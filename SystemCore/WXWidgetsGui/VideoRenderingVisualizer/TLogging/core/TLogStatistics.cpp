#include "TLogStatistics.h"
#include "LogStatistics.h"

using namespace tlogging;

/**
 * Creates TLog Statistics.
 */
ITLogStatisticsSharedPtr TLogStatistics::Make(
    const std::wstring& path,
    size_t numberOfTLogRecords, 
    size_t numberOfCallStartedRecords,
    size_t numberOfCallEndedRecords,
    size_t numberOfCompositorsCreatedRecords,
    size_t numberOfCompositorsDestroyedRecords,
    size_t numberOfAddViewRecords, 
    size_t numberOfRemoveViewRecords,
    size_t numberOfSetConfigurationRecords,
    size_t numberOfSetViewPropertiesRecords)
{
    return std::make_shared<TLogStatistics>(
        path,
        numberOfTLogRecords, 
        numberOfCallStartedRecords, 
        numberOfCallEndedRecords,
        numberOfCompositorsCreatedRecords, 
        numberOfCompositorsDestroyedRecords,
        numberOfAddViewRecords, 
        numberOfRemoveViewRecords,
        numberOfSetConfigurationRecords, 
        numberOfSetViewPropertiesRecords);
}

/**
 * The TLogStatistics constructor.
 */
TLogStatistics::TLogStatistics(
    const std::wstring& path,
    size_t numberOfTLogRecords, 
    size_t numberOfCallStartedRecords,
    size_t numberOfCallEndedRecords, 
    size_t numberOfCompositorsCreatedRecords,
    size_t numberOfCompositorsDestroyedRecords, 
    size_t numberOfAddViewRecords,
    size_t numberOfRemoveViewRecords, 
    size_t numberOfSetConfigurationRecords,
    size_t numberOfSetViewPropertiesRecords) : 
    m_logStatistics(logging::LogStatistics::Make(path)),
    m_numberOfTLogRecords(numberOfTLogRecords), 
    m_numberOfCallStartedRecords(numberOfCallStartedRecords), 
    m_numberOfCallEndedRecords(numberOfCallEndedRecords), 
    m_numberOfCompositorsCreatedRecords(numberOfCompositorsCreatedRecords), 
    m_numberOfCompositorsDestroyedRecords(numberOfCompositorsDestroyedRecords), 
    m_numberOfAddViewRecords(numberOfAddViewRecords), 
    m_numberOfRemoveViewRecords(numberOfRemoveViewRecords), 
    m_numberOfSetConfigurationRecords(numberOfSetConfigurationRecords), 
    m_numberOfSetViewPropertiesRecords(numberOfSetViewPropertiesRecords)
{
}

/**
 * The TLogStatistics destructor.
 */
TLogStatistics::~TLogStatistics() 
{
}

/**
 * Gets log statistics.
 */
logging::ILogStatisticsSharedPtr TLogStatistics::GetLogStatistics() const
{
    return m_logStatistics;
}

/**
 * Gets number of TLog records.
 */
size_t TLogStatistics::GetNumberOfTLogRecords() const
{
    return m_numberOfTLogRecords;
}

/**
 * Increments number of TLog records.
 */
void TLogStatistics::IncrementNumberOfTLogRecords()
{
    ++m_numberOfTLogRecords;
}

/**
 * Gets number of calls started records.
 */
size_t TLogStatistics::GetNumberOfCallStartedRecords() const 
{
    return m_numberOfCallStartedRecords;
}

/**
 * Increments number of calls started records.
 */
void TLogStatistics::IncrementNumberOfCallStartedRecords()
{
    ++m_numberOfCallStartedRecords;
}

/**
 * Gets number of calls ended records.
 */
size_t TLogStatistics::GetNumberOfCallEndedRecords() const 
{
    return m_numberOfCallEndedRecords;
}

/**
 * Increments number of calls ended records.
 */
void TLogStatistics::IncrementNumberOfCallEndedRecords()
{
    ++m_numberOfCallEndedRecords;
}

/**
 * Gets number of compositors created records.
 */
size_t TLogStatistics::GetNumberOfCompositorsCreatedRecords() const
{
    return m_numberOfCompositorsCreatedRecords;
}

/**
 * Increments number of compositors created records.
 */
void TLogStatistics::IncrementNumberOfCompositorsCreatedRecords()
{
    ++m_numberOfCompositorsCreatedRecords;
}

/**
 * Gets number of compositors destroyed records.
 */
size_t TLogStatistics::GetNumberOfCompositorsDestroyedRecords() const
{
    return m_numberOfCompositorsDestroyedRecords;
}

/**
 * Increments number of compositors destroyed records.
 */
void TLogStatistics::IncrementNumberOfCompositorsDestroyedRecords()
{
    ++m_numberOfCompositorsDestroyedRecords;
}

/**
 * Gets number of add view records.
 */
size_t TLogStatistics::GetNumberOfAddViewRecords() const
{
    return m_numberOfAddViewRecords;
}

/**
 * Increments number of add view records.
 */
void TLogStatistics::IncrementNumberOfAddViewRecords()
{
    ++m_numberOfAddViewRecords;
}

/**
 * Gets number of remove view records.
 */
size_t TLogStatistics::GetNumberOfRemoveViewRecords() const
{
    return m_numberOfRemoveViewRecords;
}

/**
 * Increments number of remove view records.
 */
void TLogStatistics::IncrementNumberOfRemoveViewRecords()
{
    ++m_numberOfRemoveViewRecords;
}

 /**
 * Gets number of set configuration records.
 */
size_t TLogStatistics::GetNumberOfSetConfigurationRecords() const
{
    return m_numberOfSetConfigurationRecords;
}

/**
 * Increments number of set configuration records.
 */
void TLogStatistics::IncrementNumberOfSetConfigurationRecords()
{
    ++m_numberOfSetConfigurationRecords;
}

/**
 * Gets number of set view properties records.
 */
size_t TLogStatistics::GetNumberOfSetViewPropertiesRecords() const
{
    return m_numberOfSetViewPropertiesRecords;
}

/**
 * Increments number of set view properties records.
 */
void TLogStatistics::IncrementNumberOfSetViewPropertiesRecords()
{
    ++m_numberOfSetViewPropertiesRecords;
}
