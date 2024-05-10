#include "RemoveViewRecord.h"
#include "ITLogProcessor.h"

using namespace tlogging;

/**
 * Creates a Remove View Record.
 */
ITLogRecordSharedPtr RemoveViewRecord::Make(
    const std::wstring& viewId, 
    size_t numOfViews,
    const logging::ILogRecordSharedPtr logRecord)
{
    return std::make_shared<RemoveViewRecord>(
        viewId, 
        numOfViews, 
        logRecord);
}

/**
 * The RemoveViewRecord Constructor.
 */
RemoveViewRecord::RemoveViewRecord(
    const std::wstring& viewId, 
    size_t numOfViews, 
    const logging::ILogRecordSharedPtr logRecord) :
    m_viewId(viewId), 
    m_numOfViews(numOfViews), 
    m_logRecord(logRecord)
{
}

/**
 * The RemoveViewRecord Destructor.
 */
RemoveViewRecord::~RemoveViewRecord() 
{
}

/**
 * Gets an id of view.
 */
const std::wstring& RemoveViewRecord::GetViewId() const
{
    return m_viewId;
}

/**
 * Gets number of viewes.
 */
size_t RemoveViewRecord::GetNumOfViews() const 
{
    return m_numOfViews;
}

/**
 * Gets a log record.
 */
const logging::ILogRecord& RemoveViewRecord::GetLogRecord() const
{
    return *m_logRecord;
}

/**
 * Processes a record.
 */
void RemoveViewRecord::Process(ITLogProcessor& processor) const
{
    processor.Process(*this);
}
