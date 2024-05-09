#include "TLogNotificationHandler.h"

using namespace tlogging;

/**
 * Creates a TLog Notification Handler.
 */
ITLogNotificationHandlerSharedPtr TLogNotificationHandler::Make()
{
    return std::make_shared<TLogNotificationHandler>();
}

/**
 * The TLogNotificationHandler constructor.
 */
TLogNotificationHandler::TLogNotificationHandler()
{
}

/**
 * The TLogNotificationHandler destructor.
 */
TLogNotificationHandler::~TLogNotificationHandler() 
{
}

/**
 * Notifies a Call Started Record.
 */
void TLogNotificationHandler::Notify(
    const ICallStartedRecord& record, 
    const ITLogTree& tree)
{
}

/**
 * Notifies a Call Ended Record.
 */
void TLogNotificationHandler::Notify(
    const ICallEndedRecord& record, 
    const ITLogTree& tree)
{
}

/**
 * Notifies a Compositor Created Record.
 */
void TLogNotificationHandler::Notify(
    const ICompositorCreatedRecord& record, 
    const ITLogTree& tree)
{
}

/**
 * Notifies a Compositor Destroyed Record.
 */
void TLogNotificationHandler::Notify(
    const ICompositorDestroyedRecord& record, 
    const ITLogTree& tree)
{
}

/**
 * Notifies an Add View Record.
 */
void TLogNotificationHandler::Notify(
    const IAddViewRecord& record, 
    const ITLogTree& tree)
{
}

/**
 * Notifies a Remove View Record.
 */
void TLogNotificationHandler::Notify(
    const IRemoveViewRecord& record, 
    const ITLogTree& tree)
{
}

/**
 * Notifies a Set Configuration Record.
 */
void TLogNotificationHandler::Notify(
    const ISetConfigurationRecord& record, 
    const ITLogTree& tree)
{
}

/**
 * Notifies a Set View Properties Record.
 */
void TLogNotificationHandler::Notify(
    const ISetViewPropertiesRecord& record, 
    const ITLogTree& tree) 
{
}
