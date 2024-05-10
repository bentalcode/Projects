#include "VideoRenderingVisualizerFrame.h"
#include "MainWindow.h"
#include "GuiManager.h"
#include "TLogsFolderDialog.h"
#include "RenderingPipelinesVisualizerDialog.h"
#include "EventViewerDialog.h"
#include "LogStatisticsDialog.h"
#include "AppLogDialog.h"
#include "GuiPaths.h"
#include "StringUtils.h"
#include "MenuItemConfigurationItems.h"
#include "IDataModel.h"
#include "IDataQuery.h"
#include "Uuid.h"
#include "wx/msgdlg.h"
#include <assert.h>

using namespace VideoRenderingVisualizer::Gui;

/**
 * Creates an app.
 */
WXWidgets::IFramePtr VideoRenderingVisualizerFrame::Make(
    const wxString& title,
    const wxPoint& position,
    const wxSize& size,
    IGuiManager& guiManager)
{ 
    return WXWidgets::IFramePtr::Make(new VideoRenderingVisualizerFrame(
        title,
        position,
        size, 
        guiManager));
}

/**
 * The VideoRenderingVisualizerFrame constructor.
 */
VideoRenderingVisualizerFrame::VideoRenderingVisualizerFrame(
    const wxString& title, 
    const wxPoint& position, 
    const wxSize& size, 
    IGuiManager& guiManager) : 
        Frame(
            nullptr, 
            GuiPaths::Read().GetMainFrameFrame(), 
            title,
            WXWidgets::WXObjectId::NextId(), 
            position, 
            size), 
    m_guiManager(guiManager)
{
    //
    // Initialize a GUI component...
    //
    Initialize();
}

/**
 * The VideoRenderingVisualizerFrame destructor.
 */
VideoRenderingVisualizerFrame::~VideoRenderingVisualizerFrame() 
{
}

/**
 * Initializes a GUI component...
 */
void VideoRenderingVisualizerFrame::Initialize()
{
    //
    // Initialize frame...
    //
    Frame::Initialize(m_guiManager.GetGuiController());

    //
    // Initialize top menu bar...
    //
    const GuiConfiguration::IGuiConfigurationManager& configurationManager = m_guiManager.GetConfigurationManager();

    InitializeTopMenuBar(configurationManager);

    //
    // Initialize status bar...
    //
    InitializeStatusBar(configurationManager);

    //
    // Bind callbacks...
    //
    GuiConfiguration::IMenuItemsConfigurationSharedPtr menuItemsConfiguration =
        configurationManager.GetMenuItemsConfiguration();

    GuiConfiguration::IMenuItemConfigurationSharedPtr openMenuItemConfiguration =
        menuItemsConfiguration->GetConfiguration(
            GuiPaths::Read().GetMainFrameTopMenuBarFileMenuOpenMenuItem());

    GuiConfiguration::IMenuItemConfigurationSharedPtr exitMenuItemConfiguration =
        menuItemsConfiguration->GetConfiguration(
            GuiPaths::Read().GetMainFrameTopMenuBarFileMenuExitMenuItem());

    GuiConfiguration::IMenuItemConfigurationSharedPtr renderingPipelinesVisualizerMenuItemConfiguration =
        menuItemsConfiguration->GetConfiguration(
            GuiPaths::Read().GetMainFrameTopMenuBarViewMenuRenderingPipelinesVisualizerMenuItem());

    GuiConfiguration::IMenuItemConfigurationSharedPtr eventViewerMenuItemConfiguration =
        menuItemsConfiguration->GetConfiguration(
            GuiPaths::Read().GetMainFrameTopMenuBarViewMenuEventViewerMenuItem());

    GuiConfiguration::IMenuItemConfigurationSharedPtr logStatisticsMenuItemConfiguration =
        menuItemsConfiguration->GetConfiguration(
            GuiPaths::Read().GetMainFrameTopMenuBarViewMenuLogStatisticsMenuItem());

    GuiConfiguration::IMenuItemConfigurationSharedPtr appLogMenuItemConfiguration =
        menuItemsConfiguration->GetConfiguration(
            GuiPaths::Read().GetMainFrameTopMenuBarViewMenuAppLogMenuItem());


    GuiConfiguration::IMenuItemConfigurationSharedPtr aboutMenuItemConfiguration =
        menuItemsConfiguration->GetConfiguration(
            GuiPaths::Read().GetMainFrameTopMenuBarHelpMenuAboutMenuItem());

    Bind(
        wxEVT_MENU, 
        &VideoRenderingVisualizerFrame::OnOpen, 
        this, 
        openMenuItemConfiguration->GetItemId());
    
    Bind(
        wxEVT_MENU, 
        &VideoRenderingVisualizerFrame::OnExit, 
        this, 
        exitMenuItemConfiguration->GetItemId());

    Bind(
        wxEVT_MENU, 
        &VideoRenderingVisualizerFrame::OnRenderingPipelinesVisualizer, 
        this, 
        renderingPipelinesVisualizerMenuItemConfiguration->GetItemId());

    Bind(
        wxEVT_MENU, 
        &VideoRenderingVisualizerFrame::OnEventViewer, 
        this, 
        eventViewerMenuItemConfiguration->GetItemId());

    Bind(
        wxEVT_MENU, 
        &VideoRenderingVisualizerFrame::OnLogStatistics, 
        this, 
        logStatisticsMenuItemConfiguration->GetItemId());

    Bind(
        wxEVT_MENU, 
        &VideoRenderingVisualizerFrame::OnAppLog, 
        this, 
        appLogMenuItemConfiguration->GetItemId());

    Bind(
        wxEVT_MENU, 
        &VideoRenderingVisualizerFrame::OnAbout, 
        this, 
        aboutMenuItemConfiguration->GetItemId());

    //
    // Initialize gui of main window...
    //
    InitializeMainWindow();

    //
    // Maximize and centeralize...
    //
    MaximizeAndCenteralize();
}

/**
 * The on Open Folders callback.
 */
void VideoRenderingVisualizerFrame::OnOpen(wxCommandEvent& event)
{
    wxWindow& parent = *this;

    //
    // Create folder dialog for parsing TLogs...
    //
    WXWidgets::IFolderDialogPtr dialog = TLogsFolderDialog::Make(
        parent, 
        m_guiManager);

    dialog.DeleteObject(true);

    int status = dialog->ActivateModal();

    if (status == wxID_OK) {
        std::vector<std::wstring> folders;

        //
        // Retrieve the selected folders...
        //
        dialog->GetSelectedFolders(folders);

        //
        // Update data repository...
        //
        Model::IDataRepositorySharedPtr dataRepository = m_guiManager.GetDataRepository();
        // dataRepository.ReadFromResourceDirectories(folders);
    }
}

/**
 * On Exit callback.
 */
void VideoRenderingVisualizerFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

/**
 * On About callback.
 */
void VideoRenderingVisualizerFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox(
        MenuItemConfigurationItems::Read().GetMainFrameTopMenuBarHelpMenuAboutMenuItemMessage(),
        MenuItemConfigurationItems::Read().GetMainFrameTopMenuBarHelpMenuAboutMenuItemCaption(),
        MenuItemConfigurationItems::Read().GetMainFrameTopMenuBarHelpMenuAboutMenuItemStyle());
}

/**
 * The on Rendering Pipelines Visualizer callback.
 */
void VideoRenderingVisualizerFrame::OnRenderingPipelinesVisualizer(wxCommandEvent& event)
{
    wxWindow& parent = *this;

    //
    // Create the rendering pipelines visualizer dialog...
    //
    WXWidgets::IDialogPtr dialog = RenderingPipelinesVisualizerDialog::Make(
        parent, 
        m_guiManager);

    dialog.DeleteObject(true);

    int status = dialog->ActivateModal();

    if (status == wxID_OK) {
    }
}

/**
 * The on Event Viewer callback.
 */
void VideoRenderingVisualizerFrame::OnEventViewer(wxCommandEvent& event)
{
    wxWindow& parent = *this;

    //
    // Create the event view dialog...
    //
    WXWidgets::IDialogPtr dialog = EventViewerDialog::Make(parent, m_guiManager);

    dialog.DeleteObject(true);

    int status = dialog->ActivateModal();

    if (status == wxID_OK) {
    }
}

/**
 * The on Log Statistics callback.
 */
void VideoRenderingVisualizerFrame::OnLogStatistics(wxCommandEvent& event)
{
    wxWindow& parent = *this;

    //
    // Create the log statistics dialog...
    //
    WXWidgets::IDialogPtr dialog = LogStatisticsDialog::Make(
        parent, 
        m_guiManager);

    dialog.DeleteObject(true);

    int status = dialog->ActivateModal();

    if (status == wxID_OK) {
    }
}

/**
 * The on App Log callback.
 */
void VideoRenderingVisualizerFrame::OnAppLog(wxCommandEvent& event)
{
    wxWindow& parent = *this;

    //
    // Create the app log dialog...
    //
    WXWidgets::IDialogPtr dialog = AppLogDialog::Make(parent, m_guiManager);

    dialog.DeleteObject(true);

    int status = dialog->ActivateModal();

    if (status == wxID_OK) {
    }
}

/**
 * Initializes a top menu bar.
 */
void VideoRenderingVisualizerFrame::InitializeTopMenuBar(const GuiConfiguration::IGuiConfigurationManager& configurationManager)
{
    m_fileMenu = CreateFileMenu(configurationManager);
    m_viewMenu = CreateViewMenu(configurationManager);
    m_helpMenu = CreateHelpMenu(configurationManager);

    m_menuBar = CreateMenuBar(
        *m_fileMenu->GetMenu(), 
        *m_viewMenu->GetMenu(),
        *m_helpMenu->GetMenu());

    SetMenuBar(m_menuBar->GetMenuBar());
}

/**
 * Initializes a status bar.
 */
void VideoRenderingVisualizerFrame::InitializeStatusBar(const GuiConfiguration::IGuiConfigurationManager& configurationManager)
{
    wxFrame::CreateStatusBar();

    GuiConfiguration::IFramesConfigurationSharedPtr framesConfiguration = 
        configurationManager.GetFramesConfiguration();
    
    GuiConfiguration::IFrameConfigurationSharedPtr frameConfiguration =
        framesConfiguration->GetConfiguration(
            GuiPaths::Read().GetMainFrame());

    std::wstring statusText(frameConfiguration->GetStatusText());
    SetStatusText(statusText);
}

/**
 * Initializes main window.
 */
void VideoRenderingVisualizerFrame::InitializeMainWindow()
{
    //
    // Retrieve calls information from data repository...
    //
    std::vector<Model::ICallInformationSharedPtr> callsInformation;
    GetCallsInformation(callsInformation);

    //
    // Calculate the items for the call's combo box...
    //
    std::vector<std::wstring> callListBoxItems;
    callListBoxItems.reserve(callsInformation.size());

    for (Model::ICallInformationSharedPtr callInformation : callsInformation) {
        callListBoxItems.push_back(callInformation->ToDisplayString());
    }

    //
    // Create a gui of main window...
    //
    m_mainWindow = MainWindow::Make(
        *this, 
        callListBoxItems,
        m_guiManager);

    //
    // Maximize and centeralize...
    //
    MaximizeAndCenteralize();
}

/**
 * Creates a menu bar.
 */
WXWidgets::IMenuBarPtr VideoRenderingVisualizerFrame::CreateMenuBar(
    wxMenu& fileMenu,
    wxMenu& viewMenu,
    wxMenu& helpMenu)
{
    WXWidgets::IMenuBarPtr menuBar = WXWidgets::MenuBar::Make(
        GuiPaths::Read().GetMainFrameTopMenuBar());

    menuBar->Initialize(m_guiManager.GetGuiController());

    menuBar->Append(fileMenu, "&File");
    menuBar->Append(viewMenu, "&View");
    menuBar->Append(helpMenu, "&Help");

    return menuBar;
}

/**
 * Creates a file menu.
 */
WXWidgets::IMenuPtr VideoRenderingVisualizerFrame::CreateFileMenu(const GuiConfiguration::IGuiConfigurationManager& configurationManager)
{
    WXWidgets::IMenuPtr menu = WXWidgets::Menu::Make(
        GuiPaths::Read().GetMainFrameTopMenuBarFileMenu());
    
    menu->Initialize(m_guiManager.GetGuiController());

    GuiConfiguration::IMenuItemsConfigurationSharedPtr menuItemsConfiguration =
        configurationManager.GetMenuItemsConfiguration();

    GuiConfiguration::IMenuItemConfigurationSharedPtr openMenuItemConfiguration =
        menuItemsConfiguration->GetConfiguration(
            GuiPaths::Read().GetMainFrameTopMenuBarFileMenuOpenMenuItem());

    menu->Append(
        openMenuItemConfiguration->GetItemId(), 
        Utilities::StringUtils::ToString(openMenuItemConfiguration->GetText()),
        Utilities::StringUtils::ToString(openMenuItemConfiguration->GetHelp()), 
        openMenuItemConfiguration->GetKind());

    menu->AppendSeparator();

    GuiConfiguration::IMenuItemConfigurationSharedPtr exitMenuItemConfiguration =
        menuItemsConfiguration->GetConfiguration(
            GuiPaths::Read().GetMainFrameTopMenuBarFileMenuExitMenuItem());

    menu->Append(
        exitMenuItemConfiguration->GetItemId(), 
        Utilities::StringUtils::ToString(exitMenuItemConfiguration->GetText()),
        Utilities::StringUtils::ToString(exitMenuItemConfiguration->GetHelp()), 
        exitMenuItemConfiguration->GetKind());

    return menu;
}

/**
 * Creates a view menu.
 */
WXWidgets::IMenuPtr VideoRenderingVisualizerFrame::CreateViewMenu(const GuiConfiguration::IGuiConfigurationManager& configurationManager)
{
    //
    // Create view menu...
    //
    WXWidgets::IMenuPtr menu = WXWidgets::Menu::Make(
        GuiPaths::Read().GetMainFrameTopMenuBarViewMenu());

    menu->Initialize(m_guiManager.GetGuiController());

    GuiConfiguration::IMenuItemsConfigurationSharedPtr menuItemsConfiguration =
        configurationManager.GetMenuItemsConfiguration();

    //
    // Set Rendering Pipelines Visualizer menu item...
    //
    GuiConfiguration::IMenuItemConfigurationSharedPtr renderingPipelinesVisualizerMenuItemConfiguration =
        menuItemsConfiguration->GetConfiguration(
            GuiPaths::Read().GetMainFrameTopMenuBarViewMenuRenderingPipelinesVisualizerMenuItem());

    menu->Append(
        renderingPipelinesVisualizerMenuItemConfiguration->GetItemId(),
        Utilities::StringUtils::ToString(renderingPipelinesVisualizerMenuItemConfiguration->GetText()),
        Utilities::StringUtils::ToString(renderingPipelinesVisualizerMenuItemConfiguration->GetHelp()),
        renderingPipelinesVisualizerMenuItemConfiguration->GetKind());

    //
    // Set Event View menu item...
    //
    GuiConfiguration::IMenuItemConfigurationSharedPtr eventViewerMenuItemConfiguration =
        menuItemsConfiguration->GetConfiguration(GuiPaths::Read().GetMainFrameTopMenuBarViewMenuEventViewerMenuItem());

    menu->Append(
        eventViewerMenuItemConfiguration->GetItemId(),
        Utilities::StringUtils::ToString(eventViewerMenuItemConfiguration->GetText()),
        Utilities::StringUtils::ToString(eventViewerMenuItemConfiguration->GetHelp()),
        eventViewerMenuItemConfiguration->GetKind());

    //
    // Set Log Statistics menu item...
    //
    GuiConfiguration::IMenuItemConfigurationSharedPtr logStatisticsMenuItemConfiguration =
        menuItemsConfiguration->GetConfiguration(
            GuiPaths::Read().GetMainFrameTopMenuBarViewMenuLogStatisticsMenuItem());

    menu->Append(
        logStatisticsMenuItemConfiguration->GetItemId(),
        Utilities::StringUtils::ToString(logStatisticsMenuItemConfiguration->GetText()),
        Utilities::StringUtils::ToString(logStatisticsMenuItemConfiguration->GetHelp()),
        logStatisticsMenuItemConfiguration->GetKind());

    menu->AppendSeparator();

    //
    // Set App Log menu item...
    //
    GuiConfiguration::IMenuItemConfigurationSharedPtr appLogMenuItemConfiguration =
        menuItemsConfiguration->GetConfiguration(GuiPaths::Read().GetMainFrameTopMenuBarViewMenuAppLogMenuItem());

    menu->Append(
        appLogMenuItemConfiguration->GetItemId(),
        Utilities::StringUtils::ToString(appLogMenuItemConfiguration->GetText()),
        Utilities::StringUtils::ToString(appLogMenuItemConfiguration->GetHelp()),
        appLogMenuItemConfiguration->GetKind());

    menu->AppendSeparator();

    return menu;
}

/**
 * Creates a help menu.
 */
WXWidgets::IMenuPtr VideoRenderingVisualizerFrame::CreateHelpMenu(const GuiConfiguration::IGuiConfigurationManager& configurationManager)
{
    WXWidgets::IMenuPtr menu = WXWidgets::Menu::Make(GuiPaths::Read().GetMainFrameTopMenuBarHelpMenu());
    menu->Initialize(m_guiManager.GetGuiController());

    GuiConfiguration::IMenuItemsConfigurationSharedPtr menuItemsConfiguration = 
        configurationManager.GetMenuItemsConfiguration();

    GuiConfiguration::IMenuItemConfigurationSharedPtr aboutMenuItemConfiguration =
        menuItemsConfiguration->GetConfiguration(
            GuiPaths::Read().GetMainFrameTopMenuBarHelpMenuAboutMenuItem());

    menu->Append(
        aboutMenuItemConfiguration->GetItemId(), 
        Utilities::StringUtils::ToString(aboutMenuItemConfiguration->GetText()),
        Utilities::StringUtils::ToString(aboutMenuItemConfiguration->GetHelp()), 
        aboutMenuItemConfiguration->GetKind());

    return menu;
}

/**
 * Retrieves calls information from data repository.
 */
void VideoRenderingVisualizerFrame::GetCallsInformation(std::vector<Model::ICallInformationSharedPtr>& callsInformation) const
{
    assert(callsInformation.empty());

    //
    // Retrieve the data repository...
    //
    const Model::IDataRepositorySharedPtr dataRepository = m_guiManager.GetDataRepository();
    const Model::IDataQuerySharedPtr dataQuery = dataRepository->GetDataQuery();

    const Model::ICallInformationCollectionSharedPtr callInformationCollection = dataQuery->QueryCalls();
    Utilities::IIteratorSharedPtr<Model::ICallInformationSharedPtr> callInformationIterator =
        callInformationCollection->GetIterator();

    while (callInformationIterator->HasNext()) {
        Model::ICallInformationSharedPtr callInformation = callInformationIterator->Next();
        callsInformation.push_back(callInformation);
    }
}
