#include "CallEndedRecord.h"
#include "SmartPointers.h"
#include "ITLogProcessor.h"

using namespace tlogging;

/**
 * Creates a Call Ended Record.
 */
ITLogRecordSharedPtr CallEndedRecord::Make(const logging::ILogRecordSharedPtr logRecord)
{
    return std::make_shared<CallEndedRecord>(logRecord);
}

/**
 * The CallEndedRecord constructor.
 */
CallEndedRecord::CallEndedRecord(const logging::ILogRecordSharedPtr logRecord)
{
    base::SmartPointers::Validate<logging::ILogRecord>(logRecord);
    m_logRecord = logRecord;
}

/**
 * The CallEndedRecord destructor.
 */
CallEndedRecord::~CallEndedRecord() 
{
}

/**
 * Gets a log record.
 */
const logging::ILogRecord& CallEndedRecord::GetLogRecord() const
{
    return *m_logRecord;
}

/**
 * Processes a record.
 */
void CallEndedRecord::Process(ITLogProcessor& processor) const
{
    processor.Process(*this);
}
