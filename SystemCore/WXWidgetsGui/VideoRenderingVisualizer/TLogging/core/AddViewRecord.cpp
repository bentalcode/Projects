#include "AddViewRecord.h"
#include "ITLogProcessor.h"

using namespace tlogging;

/**
 * Creates an Add View Record.
 */
ITLogRecordSharedPtr AddViewRecord::Make(
    const std::wstring& viewId, 
    const base::IPositionSharedPtr<int> position,
    const IVolumeSharedPtr<size_t> volume, 
    size_t numOfViews,
    const logging::ILogRecordSharedPtr logRecord)
{
    return std::make_shared<AddViewRecord>(
        viewId, 
        position, 
        volume, 
        numOfViews, 
        logRecord);
}

/**
 * The AddViewRecord Constructor.
 */
AddViewRecord::AddViewRecord(
    const std::wstring& viewId, 
    const base::IPositionSharedPtr<int> position,
    const IVolumeSharedPtr<size_t> volume, 
    size_t numOfViews,
    const logging::ILogRecordSharedPtr logRecord) :
    m_viewId(viewId), 
    m_position(position), 
    m_volume(volume), 
    m_numOfViews(numOfViews), 
    m_logRecord(logRecord)
{
}

/**
 * The AddViewRecord Destructor.
 */
AddViewRecord::~AddViewRecord() 
{
}

/**
 * Gets an id of view.
 */
const std::wstring& AddViewRecord::GetViewId() const
{
    return m_viewId;
}

/**
 * Gets position of view.
 */
const base::IPosition<int>& AddViewRecord::GetViewPosition() const
{
    return *m_position;
}

/**
 * Gets volume of view.
 */
const IVolume<size_t>& AddViewRecord::GetViewVolume() const
{
    return *m_volume;
}

/**
 * Gets number of viewes.
 */
size_t AddViewRecord::GetNumOfViews() const 
{
    return m_numOfViews;
}

/**
 * Gets a log record.
 */
const logging::ILogRecord& AddViewRecord::GetLogRecord() const
{
    return *m_logRecord;
}

/**
 * Processes a record.
 */
void AddViewRecord::Process(ITLogProcessor& processor) const 
{
    processor.Process(*this);
}
