#include "CompositorDestroyedRecord.h"
#include "SmartPointers.h"
#include "ITLogProcessor.h"

using namespace tlogging;

/**
 * Creates a Compositor Destroyed Record.
 */
ITLogRecordSharedPtr CompositorDestroyedRecord::Make(
    const std::wstring& compositorId,
    const logging::ILogRecordSharedPtr logRecord)
{
    return std::make_shared<CompositorDestroyedRecord>(
        compositorId, 
        logRecord);
}

/**
 * The CompositorDestroyedRecord constructor.
 */
CompositorDestroyedRecord::CompositorDestroyedRecord(
    const std::wstring& compositorId, 
    const logging::ILogRecordSharedPtr logRecord) :
        m_compositorId(compositorId)
{
    base::SmartPointers::Validate<logging::ILogRecord>(logRecord);
    m_logRecord = logRecord;
}

/**
 * The CompositorDestroyedRecord destructor.
 */
CompositorDestroyedRecord::~CompositorDestroyedRecord() 
{
}

/**
 * Gets an id of compositor.
 */
const std::wstring& CompositorDestroyedRecord::GetCompositorId() const
{
    return m_compositorId;
}

/**
 * Gets a log record.
 */
const logging::ILogRecord& CompositorDestroyedRecord::GetLogRecord() const
{
    return *m_logRecord;
}

/**
 * Processes a record.
 */
void CompositorDestroyedRecord::Process(ITLogProcessor& processor) const
{
    processor.Process(*this);
}
