#include "MainWindow.h"
#include "MainLeftWindow.h"
#include "MainRightWindow.h"
#include "GuiManager.h"
#include "SplitterWindow.h"
#include "SplitterWindowConfiguration.h"
#include "SplitterSubWindowConfiguration.h"
#include "GuiPaths.h"
#include "StringUtils.h"

using namespace VideoRenderingVisualizer::Gui;

/**
 * Creates a Main Window.
 */
IGuiWindowSharedPtr MainWindow::Make(
    wxWindow& parent, 
    const std::vector<std::wstring>& leftTopWindowItems, 
    IGuiManager& guiManager)
{
    return std::make_shared<MainWindow>(
        parent, 
        leftTopWindowItems, 
        guiManager);
}

/**
 * The MainWindow constructor.
 */
MainWindow::MainWindow(
    wxWindow& parent, 
    const std::vector<std::wstring>& leftTopWindowItems,
    IGuiManager& guiManager) : 
        AbstractGuiWindow(
            L"MainWindow",
            guiManager)
{
    //
    // Initialize window...
    //
    Initialize(
        parent, 
        leftTopWindowItems);
}

/**
 * The MainWindow destructor.
 */
MainWindow::~MainWindow() 
{
}

/**
 * Initializes window.
 */
void MainWindow::Initialize(
    wxWindow& parent, 
    const std::vector<std::wstring>& leftTopWindowItems)
{
    //
    // Create a splitter window...
    //
    m_splitterWindow = wxwidgets::ISplitterWindowPtr::Make(
        new wxwidgets::SplitterWindow(
            GuiPaths::Read().GetMainFrameMainWindowSplitterWindow(),
            parent));

    IGuiManager& guiManager = GetGuiManager();
    m_splitterWindow->Initialize(guiManager.GetGuiController());

    //
    // Create a configuration of a splitter window...
    //
    const GuiConfiguration::IGuiConfigurationManager& configurationManager = guiManager.GetConfigurationManager();
    GuiConfiguration::ILabelsConfigurationSharedPtr labelsConfiguration = configurationManager.GetLabelsConfiguration();

    GuiConfiguration::ILabelConfigurationSharedPtr leftWindowLabelConfiguration =
        labelsConfiguration->GetConfiguration(GuiPaths::Read().GetMainFrameMainLeftWindowLabel());

    GuiConfiguration::ILabelConfigurationSharedPtr rightWindowLabelConfiguration =
        labelsConfiguration->GetConfiguration(GuiPaths::Read().GetMainFrameMainRightWindowLabel());

    std::wstring leftWindowLabel = leftWindowLabelConfiguration->GetText();
    std::wstring rightWindowLabel = rightWindowLabelConfiguration->GetText();

    //
    // Create a configuration of a splitter window...
    //
    wxwidgets::ISplitterWindowConfigurationSharedPtr configuration = CreateSplitterWindowConfiguration(
        parent, 
        leftWindowLabel, 
        rightWindowLabel);

    //
    // Split a window vertically...
    //
    std::pair<wxWindow*, wxWindow*> panels = m_splitterWindow->SplitVertically(configuration);

    wxWindow* leftPanel = panels.first;
    wxWindow* rightPanel = panels.second;

    //
    // Initialize a left window...
    //
    m_leftWindow = MainLeftWindow::Make(
        *leftPanel, 
        leftTopWindowItems,
        guiManager);

    //
    // Initialize a right window...
    //
    m_rightWindow = MainRightWindow::Make(
        *rightPanel, 
        guiManager);

    //
    // Connects the left/right windows...
    //
    m_splitterWindow->ConnectWindows(
        m_leftWindow->GetWindow().AsWindow(), 
        m_rightWindow->GetWindow().AsWindow());
}

/**
 * Gets a window.
 */
wxwidgets::IWindow& MainWindow::GetWindow()
{
    return m_splitterWindow->GetWindow();
}

/**
 * Creates a configuration of a splitter window.
 */
const wxwidgets::ISplitterWindowConfigurationSharedPtr MainWindow::CreateSplitterWindowConfiguration(
    const wxWindow& window,
    const std::wstring& leftWindowBorderLabel,
    const std::wstring& rightWindowBorderLabel)
{
    double gravity = CalculateSplitterWindowGravity(window);
    bool initializeInBoxSizer = true;

    int leftWindowProportion = 1;
    int leftWindowFlag = wxEXPAND;
    wxwidgets::IBorderWindowConfigurationSharedPtr leftWindowBorderConfiguration = nullptr;
    bool leftWindowShow = true;

    int rightWindowProportion = 1;
    int rightWindowFlag = wxEXPAND;
    wxwidgets::IBorderWindowConfigurationSharedPtr rightWindowBorderConfiguration = nullptr;
    bool rightWindowShow = true;

    wxwidgets::ISplitterSubWindowConfigurationSharedPtr leftWindowConfiguration =
        wxwidgets::SplitterSubWindowConfiguration::Make(
            leftWindowProportion, 
            leftWindowFlag, 
            leftWindowBorderConfiguration, 
            leftWindowShow);

    wxwidgets::ISplitterSubWindowConfigurationSharedPtr rightWindowConfiguration =
        wxwidgets::SplitterSubWindowConfiguration::Make(
            rightWindowProportion, 
            rightWindowFlag, 
            rightWindowBorderConfiguration, 
            rightWindowShow);

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
double MainWindow::CalculateSplitterWindowGravity(const wxWindow& window)
{
    return 0.3;
}
