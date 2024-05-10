#include "WXEventHandler.h"
#include "wx/event.h"
#include "SmartPointers.h"

using namespace wxwidgets;

/**
 * Creates a WXEvent Handler.
 */
IWXEventHandlerSharedPtr WXEventHandler::Create(wxEvtHandler& handler)
{
    return std::make_shared<WXEventHandler>(handler);
}

/**
 * The WXEventHandler constructor.
 */
WXEventHandler::WXEventHandler(wxEvtHandler& handler) :
    m_handler(handler)
{
}

/**
 * The WXEventHandler destructor.
 */
WXEventHandler::~WXEventHandler()
{
}

/**
 * Sends an event.
 */
void WXEventHandler::SendEvent(const IWXEventSharedPtr event)
{
    base::SmartPointers::Validate<IWXEvent>(event);
    m_handler.AddPendingEvent(event->GetEvent());
}
