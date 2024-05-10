#include "MainLeftTopWindow.h"
#include "MainLeftTopWindowUpperSubWindow.h"
#include "MainLeftTopWindowLowerSubWindow.h"
#include "GuiManager.h"
#include "SplitterWindow.h"
#include "SplitterWindowConfiguration.h"
#include "SplitterSubWindowConfiguration.h"
#include "BorderWindowConfiguration.h"
#include "GuiPaths.h"
#include "StringUtils.h"

using namespace VideoRenderingVisualizer::Gui;

/**
 * Creates a Main Left Top Window.
 */
IGuiWindowSharedPtr MainLeftTopWindow::Make(
    wxWindow& parent, 
    const std::vector<std::wstring>& topWindowItems, 
    IGuiManager& guiManager)
{
    return std::make_shared<MainLeftTopWindow>(
        parent, 
        topWindowItems, 
        guiManager);
}

/**
 * The MainLeftTopWindow constructor.
 */
MainLeftTopWindow::MainLeftTopWindow(
    wxWindow& parent, 
    const std::vector<std::wstring>& topWindowItems, 
    IGuiManager& guiManager) : 
        AbstractGuiWindow(
            L"MainLeftTopWindow",
            guiManager)
{
    //
    // Initialize window...
    //
    InitializeWindow(
        parent, 
        topWindowItems);
}

/**
 * The MainLeftTopWindow destructor.
 */
MainLeftTopWindow::~MainLeftTopWindow() 
{
}

/**
 * Initializes a window.
 */
void MainLeftTopWindow::InitializeWindow(
    wxWindow& parent, 
    const std::vector<std::wstring>& topListBoxItems)
{
    //
    // Create a splitter window...
    //
    m_splitterWindow = wxwidgets::ISplitterWindowPtr::Make(
        new wxwidgets::SplitterWindow(
            GuiPaths::Read().GetMainFrameMainLeftTopWindowSplitterWindow(),
            parent));

    IGuiManager& guiManager = GetGuiManager();
    m_splitterWindow->Initialize(guiManager.GetGuiController());

    //
    // Create a configuration of a splitter window...
    //
    const GuiConfiguration::IGuiConfigurationManager& configurationManager = guiManager.GetConfigurationManager();
    GuiConfiguration::ILabelsConfigurationSharedPtr labelsConfiguration = configurationManager.GetLabelsConfiguration();

    GuiConfiguration::ILabelConfigurationSharedPtr topWindowLabelConfiguration =
        labelsConfiguration->GetConfiguration(
            GuiPaths::Read().GetMainFrameMainLeftTopWindowUpperSubWindowLabel());

    GuiConfiguration::ILabelConfigurationSharedPtr bottomWindowLabelConfiguration =
        labelsConfiguration->GetConfiguration(
            GuiPaths::Read().GetMainFrameMainLeftTopWindowLowerSubWindowLabel());

    std::wstring topWindowLabel = topWindowLabelConfiguration->GetText();
    std::wstring bottomWindowLabel = bottomWindowLabelConfiguration->GetText();

    wxwidgets::ISplitterWindowConfigurationSharedPtr configuration = CreateSplitterWindowConfiguration(
        parent, 
        topWindowLabel, 
        bottomWindowLabel);

    //
    // Split a window horizontally...
    //
    std::pair<wxWindow*, wxWindow*> panels = m_splitterWindow->SplitHorizontally(configuration);

    wxWindow* topPanel = panels.first;
    wxWindow* bottomPanel = panels.second;

    //
    // Create a top window...
    //
    m_topWindow = MainLeftTopWindowUpperSubWindow::Make(
        *topPanel, 
        topListBoxItems, 
        guiManager);

    //
    // Create a bottom window...
    //
    const std::vector<std::wstring> bottomListBoxItems;
    m_bottomWindow = MainLeftTopWindowLowerSubWindow::Make(
        *bottomPanel, 
        bottomListBoxItems, 
        guiManager);

    //
    // Connect top/bottom windows...
    //
    m_splitterWindow->ConnectWindows(
        m_topWindow->GetWindow().AsWindow(), 
        m_bottomWindow->GetWindow().AsWindow());
}

/**
 * Gets a window.
 */
wxwidgets::IWindow& MainLeftTopWindow::GetWindow()
{
    return m_splitterWindow->GetWindow();
}

/**
 * Creates a configuration of a splitter window.
 */
const wxwidgets::ISplitterWindowConfigurationSharedPtr
MainLeftTopWindow::CreateSplitterWindowConfiguration(
    const wxWindow& window, 
    const std::wstring& topWindowBorderLabel, 
    const std::wstring& bottomWindowBorderLabel)
{
    double gravity = CalculateSplitterWindowGravity(window);
    bool initializeInBoxSizer = false;

    int topWindowProportion = 1;
    int topWindowFlag = wxEXPAND;
    wxwidgets::IBorderWindowConfigurationSharedPtr topWindowBorderConfiguration =
        wxwidgets::BorderWindowConfiguration::Make(topWindowBorderLabel);
    bool topWindowShow = true;

    int bottomWindowProportion = 1;
    int bottomWindowFlag = wxEXPAND;
    wxwidgets::IBorderWindowConfigurationSharedPtr bottomWindowBorderConfiguration =
        wxwidgets::BorderWindowConfiguration::Make(bottomWindowBorderLabel);
    bool bottomWindowShow = true;

    wxwidgets::ISplitterSubWindowConfigurationSharedPtr leftWindowConfiguration =
        wxwidgets::SplitterSubWindowConfiguration::Make(
            topWindowProportion, 
            topWindowFlag, 
            topWindowBorderConfiguration, 
            topWindowShow);

    wxwidgets::ISplitterSubWindowConfigurationSharedPtr rightWindowConfiguration =
        wxwidgets::SplitterSubWindowConfiguration::Make(
            bottomWindowProportion, 
            bottomWindowFlag, 
            bottomWindowBorderConfiguration, 
            bottomWindowShow);

    wxwidgets::ISplitterWindowConfigurationSharedPtr configuration =
        wxwidgets::SplitterWindowConfiguration::Make(
            gravity, 
            initializeInBoxSizer, 
            leftWindowConfiguration, 
            rightWindowConfiguration);

    return configuration;
}

/**
 * Creates a gravity of splitter window.
 */
double MainLeftTopWindow::CalculateSplitterWindowGravity(const wxWindow& window)
{
    return 0.5;
}
