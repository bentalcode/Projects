#include "EventViewerDialog.h"
#include "EventListView.h"
#include "IGuiConfigurationManager.h"
#include "GuiPaths.h"
#include "StringUtils.h"

using namespace VideoRenderingVisualizer;
using namespace VideoRenderingVisualizer::Gui;

/**
 * Creates an Event Viewer Dialog.
 */
wxwidgets::IDialogPtr EventViewerDialog::Make(
    wxWindow& parent, 
    IGuiManager& guiManager)
{
    return wxwidgets::IDialogPtr::Make(
        new EventViewerDialog(
            parent, 
            guiManager));
}

/**
 * The EventViewerDialog constructor.
 */
EventViewerDialog::EventViewerDialog(
    wxWindow& parent, 
    IGuiManager& guiManager) : 
        wxwidgets::Dialog(
            parent, 
            GuiPaths::Read().GetMainFrameTopMenuBarViewMenuEventViewerDialog()), 
            m_guiManager(guiManager)
{
    //
    // Initialize a GUI component...
    //
    Initialize(guiManager);

    //
    // Retrieve configuration...
    //
    const GuiConfiguration::IGuiConfigurationManager& configurationManager = m_guiManager.GetConfigurationManager();
    GuiConfiguration::IDialogsConfigurationSharedPtr dialogsConfiguration = configurationManager.GetDialogsConfiguration();
    GuiConfiguration::IDialogConfigurationSharedPtr dialogConfiguration = dialogsConfiguration->GetConfiguration(
        GuiPaths::Read().GetMainFrameTopMenuBarViewMenuEventViewerDialog());
    
    //
    // Set title...
    //
    std::wstring title = dialogConfiguration->GetTitle();
    SetTitle(title);

    //
    // Maximize and centrelize window...
    //
    GetWindow().MaximizeAndCenteralize();
}

/**
 * The EventViewerDialog destructor.
 */
EventViewerDialog::~EventViewerDialog() 
{
}

/**
 * Initializes a GUI component.
 */
void EventViewerDialog::Initialize(IGuiManager& guiManager)
{
    //
    // Initialize dialog...
    //
    wxwidgets::Dialog::Initialize(guiManager.GetGuiController());

    tabular_data::IEventLogSharedPtr eventLog = guiManager.GetEventLog();
    base::DateTimeIntervalSharedPtr intervalTime = base::DateTimeInterval::Make();

    m_eventListView = EventListView::Make(
        *this, 
        eventLog, 
        intervalTime,
        guiManager);
}
