#include "CallStartedRecord.h"
#include "SmartPointers.h"
#include "ITLogProcessor.h"

using namespace tlogging;

/**
 * Creates a Call Started Record.
 */
ITLogRecordSharedPtr CallStartedRecord::Make(
    const std::wstring& callId, 
    const std::wstring& remoteUri,
    const std::wstring& callKey, 
    const std::wstring& securityLevel,
    const std::wstring& bypassInformation,
    const logging::ILogRecordSharedPtr logRecord)
{
    return std::make_shared<CallStartedRecord>(
        callId, 
        remoteUri, 
        callKey,
        securityLevel, 
        bypassInformation,
        logRecord);
}

/**
 * The CallStartedRecord constructor.
 */
CallStartedRecord::CallStartedRecord(
    const std::wstring& callId, 
    const std::wstring& remoteUri, 
    const std::wstring& callKey,
    const std::wstring& securityLevel, 
    const std::wstring& bypassInformation,
    const logging::ILogRecordSharedPtr logRecord) :
    m_callId(callId), 
    m_remoteUri(remoteUri), 
    m_callKey(callKey), 
    m_securityLevel(securityLevel), 
    m_bypassInformation(bypassInformation)
{
    base::SmartPointers::Validate<logging::ILogRecord>(logRecord);
    m_logRecord = logRecord;
}

/**
 * The CallStartedRecord destructor.
 */
CallStartedRecord::~CallStartedRecord() 
{
}

/**
 * Gets an id of a call.
 */
const std::wstring& CallStartedRecord::GetCallId() const 
{
    return m_callId;
}

/**
 * Gets remote URI of a call.
 */
const std::wstring& CallStartedRecord::GetRemoteUri() const
{
    return m_remoteUri;
}

/**
 * Gets key of a call.
 */
const std::wstring& CallStartedRecord::GetCallKey() const
{
    return m_callKey;
}

/**
 * Gets security level.
 */
const std::wstring& CallStartedRecord::GetSecurityLevel() const 
{
    return m_securityLevel;
}

/**
 * Gets bypass information.
 */
const std::wstring& CallStartedRecord::GetBypassInformation() const 
{
    return m_bypassInformation;
}

/**
 * Gets a log record.
 */
const logging::ILogRecord& CallStartedRecord::GetLogRecord() const
{
    return *m_logRecord;
}

/**
 * Processes a record.
 */
void CallStartedRecord::Process(ITLogProcessor& processor) const
{
    processor.Process(*this);
}
