#include "PreCompiled.h"

#include "UnitTestRunningResult.h"

using namespace unit_testing;

/**
 * The UnitTestRunningResult constructor.
 */
UnitTestRunningResult::UnitTestRunningResult(
    const std::string& name,
    bool resultStatus,
    const std::string& errorMessage) :
    m_name(name),
    m_resultStatus(resultStatus),
    m_errorMessage(errorMessage)
{
}

/**
 * The UnitTestRunningResult destructor.
 */
UnitTestRunningResult::~UnitTestRunningResult()
{
}

/**
 * Gets the information of the running result.
 */
void UnitTestRunningResult::getRunningResultInformation(std::ostream& stream) const
{
    stream << "Name: " << m_name << ", Result Status: ";

    if (m_resultStatus)
    {
        stream << "Passed";
    }
    else
    {
        stream << "Failed" << ", ErrorMessage: " << m_errorMessage;
    }

    stream << std::endl;
}

const std::string& UnitTestRunningResult::getName() const
{
    return m_name;
}

bool UnitTestRunningResult::getResultStatus() const
{
    return m_resultStatus;
}

const std::string& UnitTestRunningResult::getErrorMessage() const
{
    return m_errorMessage;
}
