#include "ProcessInformation.h"

using namespace Command;

/**
 * The ProcessInformation constructor.
 */
ProcessInformation::ProcessInformation(
    unsigned int processId,
    const std::wstring& user,
    const std::vector<std::wstring>& arguments,
    const std::wstring& command,
    const std::wstring& commandLine,
    const base::DateTime& startTime,
    const base::Duration& totalCpuTime) :
    m_processId(processId),
    m_user(user),
    m_arguments(arguments),
    m_command(command),
    m_commandLine(commandLine),
    m_startTime(startTime),
    m_totalCpuTime(totalCpuTime)
{
}

/**
 * The ProcessInformation destructor.
 */
ProcessInformation::~ProcessInformation()
{
}

/**
 * Gets the ProcessId.
 */
unsigned int ProcessInformation::ProcessId() const
{
    return m_processId;
}

/**
 * Gets the User of the process.
 */
const std::wstring& ProcessInformation::User() const
{
    return m_user;
}

/**
 * Gets the Arguments of the process.
 */
void ProcessInformation::Arguments(std::vector<std::wstring>& arguments) const
{
    arguments.insert(arguments.end(), m_arguments.begin(), m_arguments.end());
}

/**
 * Gets the executable pathname of the process.
 */
const std::wstring& ProcessInformation::Command() const
{
    return m_command;
}

/**
 * Gets the Command line of the process.
 */
const std::wstring& ProcessInformation::CommandLine() const
{
    return m_commandLine;
}

/**
 * Gets the start time of the process.
 */
const base::DateTime& ProcessInformation::StartTime() const
{
    return m_startTime;
}

/**
 * Gets the total cpu time of the process.
 */
const base::Duration& ProcessInformation::TotalCpuTime() const
{
    return m_totalCpuTime;
}
