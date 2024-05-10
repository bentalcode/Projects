#include "MainRightTopWindow.h"
#include "MainRightTopWindowUpperSubWindow.h"
#include "MainRightTopWindowLowerSubWindow.h"
#include "GuiManager.h"
#include "GuiPaths.h"
#include "SplitterWindow.h"
#include "SplitterWindowConfiguration.h"
#include "SplitterSubWindowConfiguration.h"
#include "BorderWindowConfiguration.h"
#include "StringUtils.h"

using namespace VideoRenderingVisualizer::Gui;

/**
 * Creates a Main Right Top Window.
 */
IGuiWindowSharedPtr MainRightTopWindow::Make(
    wxWindow& parent, 
    IGuiManager& guiManager)
{
    return std::make_shared<MainRightTopWindow>(
        parent, 
        guiManager);
}

/**
 * The MainRightTopWindow constructor.
 */
MainRightTopWindow::MainRightTopWindow(
    wxWindow& parent, 
    IGuiManager& guiManager) : 
        AbstractGuiWindow(
            L"MainRightTopWindow",
            guiManager)
{
    //
    // Initialize a window...
    //
    Initialize(parent);
}

/**
 * The MainRightTopWindow destructor.
 */
MainRightTopWindow::~MainRightTopWindow() 
{
}

/**
 * Initializes a window.
 */
void MainRightTopWindow::Initialize(wxWindow& parent)
{
    //
    // Create a splitter window...
    //
    m_splitterWindow = wxwidgets::ISplitterWindowPtr::Make(
        new wxwidgets::SplitterWindow(
            GuiPaths::Read().GetMainFrameMainRightTopWindowSplitterWindow(), 
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
            GuiPaths::Read().GetMainFrameMainRightTopWindowUpperSubWindowLabel());

    GuiConfiguration::ILabelConfigurationSharedPtr bottomWindowLabelConfiguration =
        labelsConfiguration->GetConfiguration(
            GuiPaths::Read().GetMainFrameMainRightTopWindowLowerSubWindowLabel());

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
    m_topWindow = MainRightTopWindowUpperSubWindow::Make(
        *topPanel, 
        guiManager);

    //
    // Create a bottom window...
    //
    m_bottomWindow = MainRightTopWindowLowerSubWindow::Make(
        *bottomPanel, 
        guiManager);

    //
    // Initialize the top/bottom windows...
    //
    m_splitterWindow->ConnectWindows(
        m_topWindow->GetWindow().AsWindow(), 
        m_bottomWindow->GetWindow().AsWindow());
}

/**
 * Gets a window.
 */
wxwidgets::IWindow& MainRightTopWindow::GetWindow()
{
    return m_splitterWindow->GetWindow();
}

/**
 * Creates a configuration of a splitter window.
 */
const wxwidgets::ISplitterWindowConfigurationSharedPtr MainRightTopWindow::CreateSplitterWindowConfiguration(
    const wxWindow& window, 
    const std::wstring& topWindowBorderLabel,
    const std::wstring& bottomWindowBorderLabel)
{
    double gravity = CalculateSplitterWindowGravity(window);
    bool initializeInBoxSizer = false;

    int topWindowProportion = 0;
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

    wxwidgets::ISplitterWindowConfigurationSharedPtr configuration = wxwidgets::SplitterWindowConfiguration::Make(
        gravity, 
        initializeInBoxSizer, 
        leftWindowConfiguration, 
        rightWindowConfiguration);

    return configuration;
}

/**
 * Creates a gravity of splitter window.
 */
double MainRightTopWindow::CalculateSplitterWindowGravity(const wxWindow& window)
{
    return 0.92;
}
