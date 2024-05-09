#include "TLogProcessor.h"
#include "ICallStartedRecord.h"
#include "ICallEndedRecord.h"
#include "ICompositorCreatedRecord.h"
#include "ICompositorDestroyedRecord.h"
#include "IAddViewRecord.h"
#include "IRemoveViewRecord.h"
#include "StringUtils.h"
#include "SmartPointers.h"
#include "TloggingException.h"

using namespace tlogging;

/**
 * Creates a TLogProcessor.
 */
ITLogProcessorSharedPtr TLogProcessor::Make(
    ITLogTreeSharedPtr tree, 
    ITLogNotificationHandlerSharedPtr notificationHandler,
    ITLogStatisticsSharedPtr statistics,
    IEventTLogSharedPtr eventTLog)
{
    return std::make_shared<TLogProcessor>(
        tree, 
        notificationHandler, 
        statistics,
        eventTLog);
}

/**
 * The TLogProcessor constructor.
 */
TLogProcessor::TLogProcessor(
    ITLogTreeSharedPtr tree, 
    ITLogNotificationHandlerSharedPtr notificationHandler,
    ITLogStatisticsSharedPtr statistics,
    tlogging::IEventTLogSharedPtr eventTLog)
{
    base::SmartPointers::Validate<ITLogTree>(tree);
    base::SmartPointers::Validate<ITLogNotificationHandler>(notificationHandler);
    base::SmartPointers::Validate<ITLogStatistics>(statistics);
    base::SmartPointers::Validate<IEventTLog>(eventTLog);

    m_tree = tree;
    m_notificationHandler = notificationHandler;
    m_statistics = statistics;
    m_eventTLog = eventTLog;
}

/**
 * The TLogProcessor destructor.
 */
TLogProcessor::~TLogProcessor() 
{
}

/**
 * Processes a Call Started Record.
 */
void TLogProcessor::Process(const ICallStartedRecord& record)
{
    //
    // Process a constructor record...
    //
    std::wstring context = L"TLogProcessor::Process(Call Started)";
    TLogRecordType recordType = TLogRecordType::CALL_STARTED;

    std::wstring loggingObject = record.GetLogRecord().GetLoggingObject();
    std::wstring callId = record.GetCallId();

    std::wstring key = callId;
    std::vector<std::wstring> path = { loggingObject };

    bool status = ProcessConstructorRecord(
        record, 
        recordType,
        context, 
        key,
        path);

    //
    // Notify that a new object has been processed...
    //
    if (status) {
        m_notificationHandler->Notify(record, *m_tree);
    }

    //
    // Update statistics...
    //
    m_statistics->IncrementNumberOfCallStartedRecords();
    m_statistics->IncrementNumberOfTLogRecords();
}

/**
 * Processes a Call Ended Record.
 */
void TLogProcessor::Process(const ICallEndedRecord& record)
{
    //
    // Process a destructor record...
    //
    std::wstring context = L"TLogProcessor::Process(Call Ended)";
    TLogRecordType recordType = TLogRecordType::CALL_STARTED;

    std::wstring loggingObject = record.GetLogRecord().GetLoggingObject();
    std::vector<std::wstring> path = { loggingObject };

    bool status = ProcessDestructorRecord(
        record, 
        recordType,
        context, 
        path);

    //
    // Notify that a new object has been processed successfully...
    //
    if (status) {
        m_notificationHandler->Notify(record, *m_tree);
    }

    //
    // Update statistics...
    //
    m_statistics->IncrementNumberOfCallEndedRecords();
    m_statistics->IncrementNumberOfTLogRecords();
}

/**
 * Processes a Compositor Created Record.
 */
void TLogProcessor::Process(const ICompositorCreatedRecord& record)
{
    //
    // Process a constructor record...
    //
    std::wstring context = L"TLogProcessor::Process(Compositor Created)";
    TLogRecordType recordType = TLogRecordType::COMPOSITOR_CREATED;
    
    std::wstring loggingObject = record.GetLogRecord().GetLoggingObject();
    std::wstring compositorId = record.GetCompositorId();

    std::wstring key = compositorId;
    std::vector<std::wstring> path = { loggingObject, compositorId };

    bool status = ProcessConstructorRecord(
        record, 
        recordType, 
        context, 
        key, 
        path);

    //
    // Notify that a new object has been processed...
    //
    if (status) {
        m_notificationHandler->Notify(record, *m_tree);
    }

    //
    // Update statistics...
    //
    m_statistics->IncrementNumberOfCompositorsCreatedRecords();
    m_statistics->IncrementNumberOfTLogRecords();
}

/**
 * Processes a Compositor Destroyed Record.
 */
void TLogProcessor::Process(const ICompositorDestroyedRecord& record)
{
    //
    // Process a destructor record...
    //
    std::wstring context = L"TLogProcessor::Process(Compositor Destroyed)";
    TLogRecordType recordType = TLogRecordType::COMPOSITOR_CREATED;

    std::wstring loggingObject = record.GetLogRecord().GetLoggingObject();
    std::wstring compositorId = record.GetCompositorId();

    std::vector<std::wstring> path = { loggingObject, compositorId };

    bool status = ProcessDestructorRecord(
        record, 
        recordType, 
        context, 
        path);

    //
    // Notify that a new object has been processed...
    //
    if (status) {
        m_notificationHandler->Notify(record, *m_tree);
    }

    //
    // Update statistics...
    //
    m_statistics->IncrementNumberOfCompositorsDestroyedRecords();
    m_statistics->IncrementNumberOfTLogRecords();
}

/**
 * Processes an Add View Record.
 */
void TLogProcessor::Process(const IAddViewRecord& record)
{
    //
    // Process a constructor record...
    //
    std::wstring context = L"TLogProcessor::Process(Add View)";
    TLogRecordType recordType = TLogRecordType::ADD_VIEW;

    std::wstring loggingObject = record.GetLogRecord().GetLoggingObject();
    std::wstring viewId = record.GetViewId();

    std::wstring key = viewId;
    std::vector<std::wstring> path = { loggingObject, viewId };

    bool status = ProcessConstructorRecord(
        record, 
        recordType, 
        context, 
        key, 
        path);

    //
    // Notify that a new object has been processed...
    //
    if (status) {
        m_notificationHandler->Notify(record, *m_tree);
    }

    //
    // Update statistics...
    //
    m_statistics->IncrementNumberOfAddViewRecords();
    m_statistics->IncrementNumberOfTLogRecords();
}

/**
 * Processes a Remove View Record.
 */
void TLogProcessor::Process(const IRemoveViewRecord& record)
{
    //
    // Notify that a new object has been processed...
    //
    m_notificationHandler->Notify(record, *m_tree);

    //
    // Process a destructor record...
    //
    std::wstring context = L"TLogProcessor::Process(Remove View)";
    TLogRecordType recordType = TLogRecordType::ADD_VIEW;

    std::wstring loggingObject = record.GetLogRecord().GetLoggingObject();
    std::wstring viewId = record.GetViewId();

    std::vector<std::wstring> path = { loggingObject, viewId };

    bool status = ProcessDestructorRecord(
        record, 
        recordType, 
        context, 
        path);

    //
    // Notify that a new object has been processed...
    //
    if (status) {
        m_notificationHandler->Notify(record, *m_tree);
    }

    //
    // Update statistics...
    //
    m_statistics->IncrementNumberOfRemoveViewRecords();
    m_statistics->IncrementNumberOfTLogRecords();
}

/**
 * Processes a Set Configuration Record.
 */
void TLogProcessor::Process(const ISetConfigurationRecord& record) 
{
    //
    // Notify that a new object has been processed...
    //
    m_notificationHandler->Notify(record, *m_tree);

    //
    // Update statistics...
    //
    m_statistics->IncrementNumberOfSetConfigurationRecords();
    m_statistics->IncrementNumberOfTLogRecords();
}

/**
 * Processes a Set View Properties Record.
 */
void TLogProcessor::Process(const ISetViewPropertiesRecord& record) 
{
    //
    // Notify that a new object has been processed...
    //
    m_notificationHandler->Notify(record, *m_tree);

    //
    // Update statistics...
    //
    m_statistics->IncrementNumberOfSetViewPropertiesRecords();
    m_statistics->IncrementNumberOfTLogRecords();
}

/**
 * Processes a constructor Record.
 * Returns true if record has been processed successfully based on current known state.
 */
bool TLogProcessor::ProcessConstructorRecord(
    const ITLogRecord& record, 
    TLogRecordType recordType,
    const std::wstring& context, 
    const std::wstring& key,
    const std::vector<std::wstring>& path)
{
    //
    // Retrieve TLog Record Tree...
    //
    ITLogTree::ITLogRecordTreeSharedPtr logRecordTree = GetOrCreateTLogRecordTree(recordType);

    //
    // Verify that the record has not been attached before...
    //
    bool status = VerifyRecordDoesNotExist(
        record,
        *logRecordTree, 
        path, 
        context);

    if (!status) {
        return false;
    }

    //
    // Add keys to path...
    //
    ITLogTree::ITLogRecordTreeNodeSharedPtr currNode = logRecordTree->GetRoot(); 

    for (std::wstring currKey : path) {
        
        if (!currNode->HasChild(currKey)) {
            const ITLogRecord* currRecord = nullptr;
            ITLogTree::ITLogRecordTreeNodeSharedPtr newNode = ITLogTree::TLogRecordTreeNode::Make(currKey, currRecord);
            currNode->AddChild(newNode);
            currNode = newNode;
        } 
        else {
            currNode = currNode->GetChild(currKey);
        }
    }

    //
    // Set the record as a leaf of path with specified key...
    //
    const ITLogRecord* recordPtr = &record;
    ITLogTree::ITLogRecordTreeNodeSharedPtr newNode = ITLogTree::TLogRecordTreeNode::Make(
        key, 
        recordPtr);

    currNode->AddChild(newNode);

    return true;
}

/**
 * Processes a destructor Record.
 * Returns true if record has been processed successfully based on current known state.
 */
bool TLogProcessor::ProcessDestructorRecord(
    const ITLogRecord& record, 
    TLogRecordType recordType,
    const std::wstring& context, 
    const std::vector<std::wstring>& path)
{
    //
    // Retrieve TLog Record Tree...
    //
    ITLogTree::ITLogRecordTreeSharedPtr logRecordTree = GetOrCreateTLogRecordTree(recordType);

    //
    // Verify that the record already exists...
    //
    bool status = VerifyRecordExists(
        record,
        *logRecordTree, 
        path, 
        context);

    if (!status) {
        return status;
    }

    DeleteTLogRecord(
        record,
        *logRecordTree, 
        path, 
        context);

    return true;
}

/**
 * Gets or creates a TLog Record Tree.
 */
const ITLogTree::ITLogRecordTreeSharedPtr TLogProcessor::GetOrCreateTLogRecordTree(TLogRecordType recordType)
{
    ITLogTree::ITLogRecordTreeSharedPtr tlogRecordTree;

    if (m_tree->HasTLogRecordTree(recordType)) {
        tlogRecordTree = m_tree->GetTLogRecordTree(recordType);
    } else {
        tlogRecordTree = m_tree->CreateTLogRecordTree(recordType);
    }

    return tlogRecordTree;
}

/**
 * Deletes a record from a TLog Record Tree.
 */
void TLogProcessor::DeleteTLogRecord(
    const ITLogRecord& record,
    ITLogTree::ITLogRecordTree& tree, 
    const std::vector<std::wstring>& path,
    const std::wstring& context)
{
    bool status = tree.DeleteNode(path);

    if (!status) {
        long errorCode = base::ErrorCodes::RESOURCE_NOT_FOUND;
        std::wstringstream eventDescriptionStream;
        eventDescriptionStream 
            << L"In Context: " << context 
            << L"; TLogRecordTree does not contain record at path: " << base::StringUtils::ToString(path, L"\\")
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring eventName = L"TLogProcessor";
        std::wstring eventDescription = eventDescriptionStream.str();
        
        m_eventTLog->SetWarningEvent(
            eventName, 
            eventDescription, 
            record);
    }
}

/**
 * Verifies that a record exists.
 */
bool TLogProcessor::VerifyRecordExists(
    const ITLogRecord& record,
    ITLogTree::ITLogRecordTree& tree, 
    const std::vector<std::wstring>& path,
    const std::wstring& context) const
{
    if (tree.FindNode(path)) {
        return true;
    }

    long errorCode = base::ErrorCodes::RESOURCE_NOT_FOUND;
    std::wstringstream eventDescriptionStream;
    eventDescriptionStream
        << L"In Context: " << context << L"; TLogRecordTree does not contain record at path: "
        << base::StringUtils::ToString(path, L"\\")
        << base::ErrorMessages::GetErrorCodeMessage(errorCode);

    std::wstring eventName = L"TLogProcessor";
    std::wstring eventDescription = eventDescriptionStream.str();

    m_eventTLog->SetWarningEvent(
        eventName, 
        eventDescription, 
        record);

    return false;
}

/**
 * Verifies that a record does not exist.
 */
bool TLogProcessor::VerifyRecordDoesNotExist(
    const ITLogRecord& record,
    ITLogTree::ITLogRecordTree& tree, 
    const std::vector<std::wstring>& path,
    const std::wstring& context) const
{
    if (!tree.FindNode(path)) {
        return true;
    }

    long errorCode = base::ErrorCodes::RESOURCE_ALREADY_EXISTS;
    std::wstringstream eventDescriptionStream;
    eventDescriptionStream 
        << L"In Context: " << context << L"; TLogRecordTree already contains record at path: "
        << base::StringUtils::ToString(path, L"\\")
        << base::ErrorMessages::GetErrorCodeMessage(errorCode);

    std::wstring eventName = L"TLogProcessor";
    std::wstring eventDescription = eventDescriptionStream.str();
        
    m_eventTLog->SetWarningEvent(
        eventName, 
        eventDescription, 
        record);

    return false;
}
