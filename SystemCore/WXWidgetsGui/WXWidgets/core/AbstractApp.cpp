#include "AbstractApp.h"
#include "GuiController.h"
#include "GuiTransaction.h"
#include "PreRefreshEvent.h"
#include "RefreshEvent.h"
#include "PostRefreshEvent.h"
#include "TriggerEndRefreshingEvent.h"
#include "wx/xrc/xmlres.h"

using namespace wxwidgets;

/**
 * The AbstractApp constructor.
 */
AbstractApp::AbstractApp() : 
    GuiComponent()
{
}

/**
 * The AbstractApp destructor.
 */
AbstractApp::~AbstractApp() 
{
}

/**
 * Initializes a GUI component.
 */
void AbstractApp::Initialize(
    const std::wstring& name, 
    IGuiControllerSharedPtr guiController)
{
    //
    // Initialize GUI component...
    //
    GuiComponent::Initialize(
        name, 
        *this,
        guiController);

    //
    // Initialize all handlers of XML resources...
    //
    wxXmlResource::Get()->InitAllHandlers();
}

/**
 * The on app exit logic - Default Implemention.
 */
void AbstractApp::OnAppExit() 
{
}

/**
 * The internal on init callback.
 */
bool AbstractApp::OnInit()
{
    OnAppInitialization();
    return true;
}

/**
 * The internal on exit callback.
 */
int AbstractApp::OnExit()
{
    OnAppExit();
    return wxApp::OnExit();
}

/**
 * Gets an app console.
 */
wxAppConsole& AbstractApp::GetAppConsole() 
{
    return *this;
}

/**
 * The On Trigger Start Refreshing callback.
 */
void AbstractApp::OnTriggerStartRefreshing()
{
    wxwidgets::IGuiComponentList components;
    GetGuiController()->GetComponents(components);

    std::wstring componentListString = GuiController::GetComponentListString(components);

    //
    // Perform a Refresh Transaction...
    //
    IGuiTransactionSharedPtr guiTransaction = GuiTransaction::Make();
    IWXEventSharedPtr triggerEndRefreshingEvent = TriggerEndRefreshingEvent::Create();
    guiTransaction->SetOnCompletionEvent(GetEventHandler(), triggerEndRefreshingEvent);

    for (wxwidgets::IGuiComponent* component : components) {
        std::wstring componentName = component->GetName();

        if (componentName != GetName()) {
            guiTransaction->RegisterComponent(*component);

            IWXEventSharedPtr preRefreshEvent = PreRefreshEvent::Create(guiTransaction);
            IWXEventSharedPtr refreshEvent = RefreshEvent::Create(guiTransaction);
            IWXEventSharedPtr postRefreshEvent = PostRefreshEvent::Create(guiTransaction);

            component->GetEventHandler().SendEvent(preRefreshEvent);
            component->GetEventHandler().SendEvent(refreshEvent);
            component->GetEventHandler().SendEvent(postRefreshEvent);
        }
    }
}
