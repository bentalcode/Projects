#include "PreCompiled.h"

#include "UnitTestRunningResult.h"

using namespace test_base;

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

/**
 * Gets the information of the running result.
 */
std::ostream& test_base::operator<<(std::ostream& stream, const UnitTestRunningResult& runningResult)
{
    runningResult.getRunningResultInformation(stream);
    return stream;
}
