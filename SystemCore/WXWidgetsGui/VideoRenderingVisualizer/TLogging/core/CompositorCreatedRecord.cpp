#include "CompositorCreatedRecord.h"
#include "SmartPointers.h"
#include "ITLogProcessor.h"

using namespace tlogging;

/**
 * Creates a Compositor Created Record.
 */
ITLogRecordSharedPtr CompositorCreatedRecord::Make(
    const std::wstring& compositorId,
    const logging::ILogRecordSharedPtr logRecord)
{
    return std::make_shared<CompositorCreatedRecord>(
        compositorId, 
        logRecord);
}

/**
 * The CompositorCreatedRecord constructor.
 */
CompositorCreatedRecord::CompositorCreatedRecord(
    const std::wstring& compositorId, 
    const logging::ILogRecordSharedPtr logRecord) :
    m_compositorId(compositorId)
{
    base::SmartPointers::Validate<logging::ILogRecord>(logRecord);
    m_logRecord = logRecord;
}

/**
 * The CompositorCreatedRecord destructor.
 */
CompositorCreatedRecord::~CompositorCreatedRecord() 
{
}

/**
 * Gets an id of compositor.
 */
const std::wstring& CompositorCreatedRecord::GetCompositorId() const
{
    return m_compositorId;
}

/**
 * Gets a log record.
 */
const logging::ILogRecord& CompositorCreatedRecord::GetLogRecord() const
{
    return *m_logRecord;
}

/**
 * Processes a record.
 */
void CompositorCreatedRecord::Process(ITLogProcessor& processor) const
{
    processor.Process(*this);
}
