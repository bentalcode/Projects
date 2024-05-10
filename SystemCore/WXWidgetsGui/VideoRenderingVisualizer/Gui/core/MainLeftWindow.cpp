#include "MainLeftWindow.h"
#include "MainLeftTopWindow.h"
#include "MainLeftBottomWindow.h"
#include "GuiManager.h"
#include "SplitterWindow.h"
#include "SplitterWindowConfiguration.h"
#include "SplitterSubWindowConfiguration.h"
#include "BorderWindowConfiguration.h"
#include "GuiPaths.h"
#include "StringUtils.h"

using namespace VideoRenderingVisualizer::Gui;

/**
 * Creates a Main Left Window.
 */
IGuiWindowSharedPtr MainLeftWindow::Make(
    wxWindow& parent, 
    const std::vector<std::wstring>& topWindowItems, 
    IGuiManager& guiManager)
{
    return std::make_shared<MainLeftWindow>(
        parent, 
        topWindowItems, 
        guiManager);
}

/**
 * The MainLeftWindow constructor.
 */
MainLeftWindow::MainLeftWindow(
    wxWindow& parent, 
    const std::vector<std::wstring>& topWindowItems, 
    IGuiManager& guiManager) : 
        AbstractGuiWindow(
            L"MainLeftWindow",
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
 * The MainLeftWindow destructor.
 */
MainLeftWindow::~MainLeftWindow() 
{
}

/**
 * Initializes a window.
 */
void MainLeftWindow::InitializeWindow(
    wxWindow& parent, 
    const std::vector<std::wstring>& topListBoxItems)
{
    //
    // Create a splitter window...
    //
    m_splitterWindow = WXWidgets::ISplitterWindowPtr::Make(
        new WXWidgets::SplitterWindow(
            GuiPaths::Read().GetMainFrameMainLeftWindowSplitterWindow(),
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
            GuiPaths::Read().GetMainFrameMainLeftTopWindowLabel());

    GuiConfiguration::ILabelConfigurationSharedPtr bottomWindowLabelConfiguration =
        labelsConfiguration->GetConfiguration(
            GuiPaths::Read().GetMainFrameMainLeftBottomWindowLabel());

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
    m_topWindow = MainLeftTopWindow::Make(
        *topPanel, 
        topListBoxItems,
        guiManager);

    //
    // Create a bottom window...
    //
    m_bottomWindow = MainLeftBottomWindow::Make(
        *bottomPanel, 
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
WXWidgets::IWindow& MainLeftWindow::GetWindow()
{
    return m_splitterWindow->GetWindow();
}

/**
 * Creates a configuration of a splitter window.
 */
const WXWidgets::ISplitterWindowConfigurationSharedPtr 
MainLeftWindow::CreateSplitterWindowConfiguration(
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

    int bottomWindowProportion = 1;
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

    WXWidgets::ISplitterWindowConfigurationSharedPtr configuration = 
        WXWidgets::SplitterWindowConfiguration::Make(
            gravity, 
            initializeInBoxSizer, 
            leftWindowConfiguration, 
            rightWindowConfiguration);

    return configuration;
}

/**
 * Creates a gravity of splitter window.
 */
double MainLeftWindow::CalculateSplitterWindowGravity(const wxWindow& window)
{
    return 0.75;
}
