#include "RenderingPipelinesVisualizerDialog.h"
#include "RenderingPipelinesHtmlWindow.h"
#include "IGuiConfigurationManager.h"
#include "GuiPaths.h"
#include "StringUtils.h"

using namespace VideoRenderingVisualizer;
using namespace VideoRenderingVisualizer::Gui;

/**
 * Creates a Rendering Pipelines Visualizer Dialog.
 */
WXWidgets::IDialogPtr RenderingPipelinesVisualizerDialog::Make(
    wxWindow& parent, 
    IGuiManager& guiManager)
{
    return WXWidgets::IDialogPtr::Make(
        new RenderingPipelinesVisualizerDialog(
            parent, 
            guiManager));
}

/**
 * The RenderingPipelinesVisualizerDialog constructor.
 */
RenderingPipelinesVisualizerDialog::RenderingPipelinesVisualizerDialog(
    wxWindow& parent, 
    IGuiManager& guiManager) : 
        WXWidgets::Dialog(
            parent, 
            GuiPaths::Read().GetMainFrameTopMenuBarViewMenuRenderingPipelinesVisualizerDialog()), 
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
        GuiPaths::Read().GetMainFrameTopMenuBarViewMenuRenderingPipelinesVisualizerDialog());
    
    //
    // Set title...
    //
    std::wstring title = Utilities::StringUtils::ToString(dialogConfiguration->GetTitle());
    SetTitle(title);

    //
    // Set fixed size...
    //
    wxSize dialogSize(1000, 1000);
    GetWindow().SetSize(dialogSize);
}

/**
 * The RenderingPipelinesVisualizerDialog destructor.
 */
RenderingPipelinesVisualizerDialog::~RenderingPipelinesVisualizerDialog() 
{
}

/**
 * Initializes a GUI component.
 */
void RenderingPipelinesVisualizerDialog::Initialize(IGuiManager& guiManager)
{
    //
    // Initialize dialog...
    //
    WXWidgets::Dialog::Initialize(guiManager.GetGuiController());

    TabularData::IEventLogSharedPtr eventLog = guiManager.GetEventLog();
    Utilities::DateTimeIntervalSharedPtr intervalTime = Utilities::DateTimeInterval::Make();

    m_renderingPiplinesHtmlWindow = RenderingPipelinesHtmlWindow::Make(
        *this, 
        intervalTime, 
        guiManager);
}
