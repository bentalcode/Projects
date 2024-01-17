#include "RetryHandler.h"
#include "IRetryLogic.h"
#include "RetryPolicy.h"
#include "RetryException.h"
#include "SmartPointers.h"
#include "ErrorMessages.h"
#include <sstream>

using namespace client_server;

/**
 * Creates a default retry handler.
 */
IRetryHandlerSharedPtr RetryHandler::MakeDefault()
{
    IRetryPolicySharedPtr policy = RetryPolicy::MakeDefault();
    return Make(policy, nullptr);
}

/**
 * Creates a RetryHandler.
 */
IRetryHandlerSharedPtr RetryHandler::Make(
    IRetryPolicySharedPtr policy,
    ILogicSharedPtr idleLogic)
{
    return std::make_shared<RetryHandler>(policy, idleLogic);
}

/**
 * The ConsolePipe constructor.
 */
RetryHandler::RetryHandler(
    IRetryPolicySharedPtr policy,
    ILogicSharedPtr idleLogic)
{
    base::SmartPointers::Validate(policy);
    base::SmartPointers::Validate(idleLogic);

    m_policy = policy;
    m_idleLogic = idleLogic;
}

/**
 * The RetryHandler destructor.
 */
RetryHandler::~RetryHandler()
{
}

/**
 * Retries to run a logic.
 */
void RetryHandler::Retry(IRetryLogic& logic)
{
    unsigned int attemptIndex = 0;

    std::wstring logicInformation = GetLogicInformation(logic);

    if (m_outstream != nullptr) {
        std::wstringstream informationalMessageStream;
        informationalMessageStream << L"Retry Handler started running for " << logicInformation;
        *m_outstream << informationalMessageStream.str();
    }

    unsigned int numberOfAttempts = m_policy->GetNumberOfAttempts();

    while (attemptIndex <= numberOfAttempts) {
        ++attemptIndex;

        if (m_outstream != nullptr) {
            std::wstring attemptInformation = GetRetryLogicAttemptInformation(logic, attemptIndex);
            std::wstringstream informationalMessageStream;
            informationalMessageStream << L"Running " << attemptInformation;

            *m_outstream << informationalMessageStream.str();
        }

        try {
            logic.Run();

            if (m_outstream != nullptr) {
                std::wstring attemptInformation = GetRetryLogicAttemptInformation(logic, attemptIndex);
                std::wstringstream informationalMessageStream;
                informationalMessageStream << L"Successful " << attemptInformation;

                *m_outstream << informationalMessageStream.str();
            }

            return;
        } catch (RetryException& e) {
            long errorCode = e.GetStatusCode();
            std::wstring attemptInformation = GetRetryLogicAttemptInformation(logic, attemptIndex);

            if (m_outstream != nullptr) {
                std::wstringstream warningMessageStream;
                warningMessageStream
                    << L"Failed " << attemptInformation
                    << L"; ErrorCode:" << base::ErrorMessages::GetErrorCodeMessage(errorCode)
                    << L", ErrorMessage: " << e.GetErrorMessage();

                *m_outstream << warningMessageStream.str();
            }

            if (attemptIndex < m_policy->GetNumberOfAttempts() && IsAbsorbedException(logic, e)) {
                m_idleLogic->Run();

                continue;
            }

            std::wstringstream errorMessageStream;
            errorMessageStream
                << L"Retry Handler failed running: "
                << logicInformation;

            std::wstring errorMessage = errorMessageStream.str();

            if (m_outstream != nullptr) {
                *m_outstream << errorMessage;
            }

            throw RetryException(errorCode, errorMessage);
        }
    }
}

/**
 * Gets the information of a retry logic.
 */
std::wstring RetryHandler::GetLogicInformation(const IRetryLogic& logic) const
{
    std::wstringstream stream;
    stream << L"Logic: " << logic.GetName() << ", with Retry Policy: " << m_policy;
    return stream.str();
}

/**
 * Gets the retry logic attempt information.
 */
std::wstring RetryHandler::GetRetryLogicAttemptInformation(
    const IRetryLogic& logic,
    unsigned int attemptIndex) const
{
    std::wstringstream stream;

    stream
        << L"Attempt: " << attemptIndex << "/" << m_policy->GetNumberOfAttempts()
        << L" of Logic: " << logic;

    return stream.str();
}

/**
 * Checks whether an exception is absorbed.
 */
bool RetryHandler::IsAbsorbedException(
    const IRetryLogic& logic,
    base::BaseException& exception) const
{
    const std::vector<base::IClassTypeSharedPtr>& absorbedExceptions = logic.GetAbsorbedExceptions();

    for (const base::IClassTypeSharedPtr& classType : absorbedExceptions) {

        if (base::ClassType::IsAssignableFrom(exception)) {
            return true;
        }
    }

    return false;
}