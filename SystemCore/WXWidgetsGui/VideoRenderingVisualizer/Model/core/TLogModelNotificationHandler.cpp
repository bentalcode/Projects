#include "TLogModelNotificationHandler.h"
#include "IDataModel.h"
#include "CallInformation.h"
#include "CompositorInformation.h"
#include "ICallStartedRecord.h"
#include "ICallEndedRecord.h"
#include "ICompositorCreatedRecord.h"
#include "ICompositorDestroyedRecord.h"
#include "EventTLog.h"
#include "ErrorCodes.h"

using namespace VideoRenderingVisualizer::Model;

/**
 * Creates a TLog Model Notification Handler.
 */
tlogging::ITLogNotificationHandlerSharedPtr TLogModelNotificationHandler::Make(
    IDataModel& model,
    tlogging::IEventTLog& eventTlog)
{
    return std::make_shared<TLogModelNotificationHandler>(
        model, 
        eventTlog);
}

/**
 * The TLogModelNotificationHandler constructor.
 */
TLogModelNotificationHandler::TLogModelNotificationHandler(
    IDataModel& model, 
    tlogging::IEventTLog& eventTlog) :
    m_model(model), 
    m_eventTLog(eventTlog)
{
}

/**
 * The TLogModelNotificationHandler destructor.
 */
TLogModelNotificationHandler::~TLogModelNotificationHandler() 
{
}

/**
 * Notifies a Call Started Record.
 */
void TLogModelNotificationHandler::Notify(
    const tlogging::ICallStartedRecord& record,
    const tlogging::ITLogTree& tree)
{
    //
    // Create a call object...
    //
    std::wstring callId = record.GetCallId();
    base::DateTimeSharedPtr startTime = record.GetLogRecord().GetLoggingTime();
    base::DateTimeSharedPtr endTime = nullptr;
    std::wstring loggingObjectMemoryAddress = record.GetLogRecord().GetLoggingObject();

    ICallInformationSharedPtr callInformation = CallInformation::Make(
        callId, 
        startTime, 
        endTime, 
        loggingObjectMemoryAddress);
    
    m_model.GetCalls()->AddItem(callInformation);
}

/**
 * Notifies a Call Ended Record.
 */
void TLogModelNotificationHandler::Notify(
    const tlogging::ICallEndedRecord& record,
    const tlogging::ITLogTree& tree)
{
    std::wstring loggingObjectMemoryAddress = record.GetLogRecord().GetLoggingObject();
    
    //
    // Find the corresponding call in model and update it's end time...
    //
    ICallInformationSharedPtr callInformation = m_model.GetCalls()->FindCallByLoggingObject(loggingObjectMemoryAddress);

    if (callInformation != nullptr) {
        base::DateTimeSharedPtr endTime = record.GetLogRecord().GetLoggingTime();
        callInformation->SetEndTime(endTime);
    } 
    else {
        long errorCode = base::ErrorCodes::RESOURCE_NOT_FOUND;

        std::wstringstream eventDescriptionStream;
        eventDescriptionStream 
            << L"TLogModelNotificationHandler failed updating end time of call"
            << L" with logging object memory address: " << record.GetLogRecord().GetLoggingObject()
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring eventName = L"TLogModelNotificationHandler";
        std::wstring eventDescription = eventDescriptionStream.str();
        
        m_eventTLog.SetWarningEvent(
            eventName, 
            eventDescription,
            record);
    }
}

/**
 * Notifies a Compositor Created Record.
 */
void TLogModelNotificationHandler::Notify(
    const tlogging::ICompositorCreatedRecord& record,
    const tlogging::ITLogTree& tree)
{
    std::wstring compositorId = record.GetCompositorId();
    std::wstring type = L"Remote Video";
    std::wstring compositionType = L"Hardware VPBIt";
    std::wstring renderer = L"Native Renderer (0x482ad34c, handle: 0x0034fed84d)";
    std::wstring compositorState = L"2172934 (Hardware | Native | VPBIt | DX11Native | MC | Partial Draw";
    unsigned long compositorFps = 30;
    bool hasFallback = false;
    base::DateTimeSharedPtr startTime = record.GetLogRecord().GetLoggingTime();
    base::DateTimeSharedPtr endTime;

    //
    // Create a compositor object...
    //
    ICompositorInformationSharedPtr compositorInformation = CompositorInformation::Make(
        compositorId,
        type, 
        compositionType,
        renderer,
        compositorState,
        compositorFps,
        hasFallback, 
        startTime,
        endTime);

    m_model.GetCompositors()->AddItem(compositorInformation);

    //
    // Add the compositor object to the corresponding call...
    //
    std::wstring loggingObjectMemoryAddress = record.GetLogRecord().GetLoggingObject();

    ICallInformationSharedPtr callInformation = m_model.GetCalls()->FindCallByLoggingObject(loggingObjectMemoryAddress);

    if (callInformation != nullptr) {
        callInformation->GetCompoistors()->AddItem(compositorInformation);
    } else {
        long errorCode = base::ErrorCodes::RESOURCE_NOT_FOUND;

        std::wstringstream eventDescriptionStream;
        eventDescriptionStream 
            << L"TLogModelNotificationHandler failed updating finding corresponding call of a compositor"
            << L" with logging object memory address: " << record.GetLogRecord().GetLoggingObject()
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring eventName = L"TLogModelNotificationHandler";
        std::wstring eventDescription = eventDescriptionStream.str();
        
        m_eventTLog.SetWarningEvent(
            eventName,
            eventDescription, 
            record);
    }
}

/**
 * Notifies a Compositor Destroyed Record.
 */
void TLogModelNotificationHandler::Notify(
    const tlogging::ICompositorDestroyedRecord& record,
    const tlogging::ITLogTree& tree)
{
    std::wstring compositorId = record.GetCompositorId();
    ICompositorInformationSharedPtr compositorInformation = m_model.GetCompositors()->GetItem(compositorId);
    
    if (compositorInformation != nullptr) {
        base::DateTimeSharedPtr endTime = record.GetLogRecord().GetLoggingTime();
        compositorInformation->SetEndTime(endTime);
    } else {
        long errorCode = base::ErrorCodes::RESOURCE_NOT_FOUND;

        std::wstringstream eventDescriptionStream;
        eventDescriptionStream 
            << L"TLogModelNotificationHandler failed updating end time of compositor" 
            << L" with id: " << compositorId
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring eventName = L"TLogModelNotificationHandler";
        std::wstring eventDescription = eventDescriptionStream.str();
        
        m_eventTLog.SetWarningEvent(
            eventName,
            eventDescription, 
            record);
    }
}

/**
 * Notifies an Add View Record.
 */
void TLogModelNotificationHandler::Notify(
    const tlogging::IAddViewRecord& record,
    const tlogging::ITLogTree& tree)
{
}

/**
 * Notifies a Remove View Record.
 */
void TLogModelNotificationHandler::Notify(
    const tlogging::IRemoveViewRecord& record,
    const tlogging::ITLogTree& tree)
{
}

/**
 * Notifies a Set Configuration Record.
 */
void TLogModelNotificationHandler::Notify(
    const tlogging::ISetConfigurationRecord& record,
    const tlogging::ITLogTree& tree)
{
}

/**
 * Notifies a Set View Properties Record.
 */
void TLogModelNotificationHandler::Notify(
    const tlogging::ISetViewPropertiesRecord& record,
    const tlogging::ITLogTree& tree)
{
}