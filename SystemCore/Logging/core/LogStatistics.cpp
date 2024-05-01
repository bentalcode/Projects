#include "LogStatistics.h"
#include "SmartPointers.h"

using namespace logging;

/**
 * Creates Log Statistics.
 */
ILogStatisticsSharedPtr LogStatistics::Make(const std::wstring& path)
{
    return std::make_shared<LogStatistics>(path);
}

/**
 * The Log Statistics constructor.
 */
LogStatistics::LogStatistics(const std::wstring& path) : 
    m_path(path),
    m_numberOfElementsProcessed(0), 
    m_numberOfElementsOutput(0)
{
}

/**
 * The LogStatistics destructor.
 */
LogStatistics::~LogStatistics() 
{
}

/**
 * Gets path of log.
 */
std::wstring LogStatistics::GetPath() const
{
    return m_path;
}

/**
 * Gets a number of elements processed.
 */
size_t LogStatistics::GetNumberOfElementsProcessed() const
{
    return m_numberOfElementsProcessed;
}

/**
 * Sets number of elements processed.
 */
void LogStatistics::SetNumberOfElementsProcessed(size_t numberOfElementsProcessed)
{
    m_numberOfElementsProcessed = numberOfElementsProcessed;
}

/**
 * Increments number of elements processed.
 */
void LogStatistics::IncrementNumberOfElementsProcessed()
{
    ++m_numberOfElementsProcessed;
}

/**
 * Gets a number of elements output.
 */
size_t LogStatistics::GetNumberOfElementsOutput() const
{
    return m_numberOfElementsOutput;
}

/**
 * Sets number of elements output.
 */
void LogStatistics::SetNumberOfElementsOutput(size_t numberOfElementsOutput)
{
    m_numberOfElementsOutput = numberOfElementsOutput;
}

/**
 * Increments number of elements output.
 */
void LogStatistics::IncrementNumberOfElementsOutput()
{
    ++m_numberOfElementsOutput;
}

/**
 * Gets start execution time.
 */
const base::DateTime& LogStatistics::GetStartExecutionTime() const
{
    return *m_startExecutionTime;
}

/**
 * Sets start execution time.
 */
void LogStatistics::SetStartExecutionTime(const base::DateTimeSharedPtr time)
{
    base::SmartPointers::Validate<base::DateTime>(time);
    m_startExecutionTime = time;
}

/**
 * Gets end execution time.
 */
const base::DateTime& LogStatistics::GetEndExecutionTime() const
{
    return *m_endExecutionTime;
}

/**
 * Sets end execution time.
 */
void LogStatistics::SetEndExecutionTime(const base::DateTimeSharedPtr time)
{
    base::SmartPointers::Validate<base::DateTime>(time);
    m_endExecutionTime = time;
}

/**
 * Gets execution time.
 */
const base::DurationSharedPtr LogStatistics::GetExecutionTime() const
{
    return *m_endExecutionTime - *m_startExecutionTime;
}
