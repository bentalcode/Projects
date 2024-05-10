#include "LogStatisticsDialog.h"
#include "LogStatisticsListView.h"
#include "IGuiConfigurationManager.h"
#include "GuiPaths.h"
#include "StringUtils.h"

using namespace VideoRenderingVisualizer;
using namespace VideoRenderingVisualizer::Gui;

/**
 * Creates Log Statistics Dialog.
 */
WXWidgets::IDialogPtr LogStatisticsDialog::Make(
    wxWindow& parent, 
    IGuiManager& guiManager)
{
    return WXWidgets::IDialogPtr::Make(
        new LogStatisticsDialog(
            parent, 
            guiManager));
}

/**
 * The LogStatisticsDialog constructor.
 */
LogStatisticsDialog::LogStatisticsDialog(
    wxWindow& parent, 
    IGuiManager& guiManager) : 
        WXWidgets::Dialog(
            parent, 
            GuiPaths::Read().GetMainFrameTopMenuBarViewMenuLogStatisticsDialog()), 
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
        GuiPaths::Read().GetMainFrameTopMenuBarViewMenuLogStatisticsDialog());
    
    //
    // Set title...
    //
    std::wstring title = Utilities::StringUtils::ToString(dialogConfiguration->GetTitle());
    SetTitle(title);

    //
    // Maximize and centrelize window...
    //
    GetWindow().MaximizeAndCenteralize();
}

/**
 * The LogStatisticsDialog destructor.
 */
LogStatisticsDialog::~LogStatisticsDialog() 
{
}

/**
 * Initializes a GUI component.
 */
void LogStatisticsDialog::Initialize(IGuiManager& guiManager)
{
    //
    // Initialize dialog...
    //
    WXWidgets::Dialog::Initialize(guiManager.GetGuiController());

    Model::IDataRepositorySharedPtr dataRepository = guiManager.GetDataRepository();
    TLogging::ITLogStatisticsCollectionSharedPtr logsStatistics = dataRepository->GetTLogStatisticsCollection();

    m_logStatisticsListView = LogStatisticsListView::Make(
        *this, 
        logsStatistics, 
        guiManager);
}
