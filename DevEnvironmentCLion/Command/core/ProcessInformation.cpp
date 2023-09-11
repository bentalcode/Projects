#include "PreCompiled.h"
#include "ProcessInformation.h"

using namespace command;

/**
 * The ProcessInformation constructor.
 */
ProcessInformation::ProcessInformation(
    unsigned int processId,
    const std::string& user,
    const std::vector<std::string>& arguments,
    const std::string& command,
    const std::string& commandLine,
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
 * Gets the processId.
 */
unsigned int ProcessInformation::processId() const
{
    return m_processId;
}

/**
 * Gets the user of the process.
 */
const std::string& ProcessInformation::user() const
{
    return m_user;
}

/**
 * Gets the arguments of the process.
 */
void ProcessInformation::arguments(std::vector<std::string>& arguments) const
{
    arguments.insert(arguments.end(), m_arguments.begin(), m_arguments.end());
}

/**
 * Gets the executable pathname of the process.
 */
const std::string& ProcessInformation::command() const
{
    return m_command;
}

/**
 * Gets the command line of the process.
 */
const std::string& ProcessInformation::commandLine() const
{
    return m_commandLine;
}

/**
 * Gets the start time of the process.
 */
const base::DateTime& ProcessInformation::startTime() const
{
    return m_startTime;
}

/**
 * Gets the total cpu time of the process.
 */
const base::Duration& ProcessInformation::totalCpuTime() const
{
    return m_totalCpuTime;
}
