#include "MainRightWindow.h"
#include "MainRightTopWindow.h"
#include "MainRightBottomWindow.h"
#include "GuiManager.h"
#include "SplitterWindow.h"
#include "SplitterWindowConfiguration.h"
#include "SplitterSubWindowConfiguration.h"
#include "BorderWindowConfiguration.h"
#include "GuiPaths.h"
#include "StringUtils.h"

using namespace VideoRenderingVisualizer::Gui;

/**
 * Creates a Main Right Window.
 */
IGuiWindowSharedPtr MainRightWindow::Make(
    wxWindow& parent, 
    IGuiManager& guiManager)
{
    return std::make_shared<MainRightWindow>(
        parent, 
        guiManager);
}

/**
 * The MainRightWindow constructor.
 */
MainRightWindow::MainRightWindow(
    wxWindow& parent,
    IGuiManager& guiManager) : 
        AbstractGuiWindow(
            L"MainRightWindow",
            guiManager)
{
    //
    // Initialize a window...
    //
    Initialize(parent);
}

/**
 * The MainRightWindow destructor.
 */
MainRightWindow::~MainRightWindow() 
{
}

/**
 * Initializes a window.
 */
void MainRightWindow::Initialize(wxWindow& parent)
{
    //
    // Create a splitter window...
    //
    m_splitterWindow = WXWidgets::ISplitterWindowPtr::Make(
        new WXWidgets::SplitterWindow(
            GuiPaths::Read().GetMainFrameMainRightWindowSplitterWindow(), 
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
            GuiPaths::Read().GetMainFrameMainRightTopWindowLabel());

    GuiConfiguration::ILabelConfigurationSharedPtr bottomWindowLabelConfiguration =
        labelsConfiguration->GetConfiguration(
            GuiPaths::Read().GetMainFrameMainRightBottomWindowLabel());

    std::wstring topWindowLabel = Utilities::StringUtils::ToString(topWindowLabelConfiguration->GetText());
    std::wstring bottomWindowLabel = Utilities::StringUtils::ToString(bottomWindowLabelConfiguration->GetText());

    WXWidgets::ISplitterWindowConfigurationSharedPtr configuration = CreateSplitterWindowConfiguration(
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
    m_topWindow = MainRightTopWindow::Make(
        *topPanel, 
        guiManager);
    
    //
    // Create a bottom window...
    //
    m_bottomWindow = MainRightBottomWindow::Make(
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
WXWidgets::IWindow& MainRightWindow::GetWindow()
{
    return m_splitterWindow->GetWindow();
}

/**
 * Creates a configuration of a splitter window.
 */
const WXWidgets::ISplitterWindowConfigurationSharedPtr MainRightWindow::CreateSplitterWindowConfiguration(
    const wxWindow& window,
    const std::wstring& topWindowBorderLabel,
    const std::wstring& bottomWindowBorderLabel)
{
    double gravity = CalculateSplitterWindowGravity(window);
    bool initializeInBoxSizer = false;

    int topWindowProportion = 1;
    int topWindowFlag = wxEXPAND;
    WXWidgets::IBorderWindowConfigurationSharedPtr topWindowBorderConfiguration = 
        WXWidgets::BorderWindowConfiguration::Make(topWindowBorderLabel);
    bool topWindowShow = true;

    int bottomWindowProportion = 0;
    int bottomWindowFlag = wxEXPAND;
    WXWidgets::IBorderWindowConfigurationSharedPtr bottomWindowBorderConfiguration =
        WXWidgets::BorderWindowConfiguration::Make(bottomWindowBorderLabel);
    bool bottomWindowShow = true;

    WXWidgets::ISplitterSubWindowConfigurationSharedPtr leftWindowConfiguration =
        WXWidgets::SplitterSubWindowConfiguration::Make(
            topWindowProportion, 
            topWindowFlag, 
            topWindowBorderConfiguration, 
            topWindowShow);

    WXWidgets::ISplitterSubWindowConfigurationSharedPtr rightWindowConfiguration =
        WXWidgets::SplitterSubWindowConfiguration::Make(
            bottomWindowProportion, 
            bottomWindowFlag, 
            bottomWindowBorderConfiguration, 
            bottomWindowShow);

    WXWidgets::ISplitterWindowConfigurationSharedPtr configuration = WXWidgets::SplitterWindowConfiguration::Make(
        gravity, 
        initializeInBoxSizer, 
        leftWindowConfiguration, 
        rightWindowConfiguration);

    return configuration;
}

/**
 * Creates a gravity of splitter window.
 */
double MainRightWindow::CalculateSplitterWindowGravity(const wxWindow& window)
{
    return 0.75;
}
