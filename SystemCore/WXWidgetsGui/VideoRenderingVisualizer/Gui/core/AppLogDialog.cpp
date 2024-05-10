#include "AppLogDialog.h"
#include "AppLogListView.h"
#include "IGuiConfigurationManager.h"
#include "GuiPaths.h"
#include "StringUtils.h"

using namespace VideoRenderingVisualizer;
using namespace VideoRenderingVisualizer::Gui;

/**
 * Creates an App Log Dialog.
 */
WXWidgets::IDialogPtr AppLogDialog::Make(
    wxWindow& parent, 
    IGuiManager& guiManager)
{
    return WXWidgets::IDialogPtr::Make(
        new AppLogDialog(
            parent, 
            guiManager));
}

/**
 * The AppLogDialog constructor.
 */
AppLogDialog::AppLogDialog(
    wxWindow& parent, 
    IGuiManager& guiManager) : 
        Dialog(
            parent, 
            GuiPaths::Read().GetMainFrameTopMenuBarViewMenuAppLogDialog()), 
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
        GuiPaths::Read().GetMainFrameTopMenuBarViewMenuAppLogDialog());
    
    //
    // Set title...
    //
    std::wstring title = base::StringUtils::ToString(dialogConfiguration->GetTitle());
    SetTitle(title);

    //
    // Maximize and centrelize window...
    //
    GetWindow().MaximizeAndCenteralize();
}

/**
 * The AppLogDialog destructor.
 */
AppLogDialog::~AppLogDialog() 
{
}

/**
 * Initializes a GUI component.
 */
void AppLogDialog::Initialize(IGuiManager& guiManager)
{
    //
    // Initialize dialog...
    //
    Dialog::Initialize(guiManager.GetGuiController());

    std::wstring logPath = m_guiManager.GetAppLogPath();

    m_logListView = AppLogListView::Make(
        *this, 
        logPath, 
        guiManager);
}
