#include "LogStatisticsListView.h"
#include "GuiManager.h"
#include "GuiPaths.h"
#include "Font.h"

using namespace VideoRenderingVisualizer;
using namespace VideoRenderingVisualizer::Gui;

/**
 * Creates a Log Statistics List View.
 */
WXWidgets::IListViewPtr LogStatisticsListView::Make(
    wxWindow& parent, 
    TLogging::ITLogStatisticsCollectionSharedPtr logsStatistics,
    IGuiManager& guiManager)
{
    return WXWidgets::IListViewPtr::Make(
        new LogStatisticsListView(
            parent, 
            logsStatistics,
            guiManager));
}

/**
 * The LogStatisticsListView constructor.
 */
LogStatisticsListView::LogStatisticsListView(
    wxWindow& parent, 
    TLogging::ITLogStatisticsCollectionSharedPtr logsStatistics,
    IGuiManager& guiManager) : 
        ListView(
            parent, 
            GuiPaths::Read().GetMainFrameTopMenuBarViewMenuLogStatisticsDialogListView()), 
        m_guiManager(guiManager), 
        m_logsStatistics(logsStatistics)
{
    //
    // Initialize a GUI component...
    //
    Initialize(guiManager);
}

/**
 * The LogStatisticsListView destructor.
 */
LogStatisticsListView::~LogStatisticsListView() 
{
}

/**
 * Initializes a GUI component.
 */
void LogStatisticsListView::Initialize(IGuiManager& guiManager)
{
    //
    // Initialize a list view with log statistics information...
    //
    std::vector<std::wstring> headers;
    std::vector<std::vector<std::wstring>> values;
    GetListViewInformation(headers, values);

    ListView::Initialize(
        headers, 
        values, 
        wxLIST_FORMAT_CENTER, 
        wxLIST_DEFAULT_COL_WIDTH * 2, 
        guiManager.GetGuiController());

    //
    // Set header attributes...
    //
    WXWidgets::ColorType fontColorType = WXWidgets::ColorType::BLACK;
    WXWidgets::ColorType backgroundColorType = WXWidgets::ColorType::WHITE;
    WXWidgets::Font headerFont;
    headerFont.MakeBold();
    
    SetHeaderAttributes(
        fontColorType, 
        backgroundColorType, 
        headerFont);

    //
    // Align columns widths by header...
    //
    AlignColumnsWidthByHeader();
}

/**
 * Gets list view information.
 */
void LogStatisticsListView::GetListViewInformation(
    std::vector<std::wstring>& headers,
    std::vector<std::vector<std::wstring>>& values) const
{
    GetListViewHeaders(headers);
    GetListViewValues(values);
}

/**
 * Gets list view headers.
 */
void LogStatisticsListView::GetListViewHeaders(std::vector<std::wstring>& headers) const
{
    assert(headers.empty());

    headers.push_back(L"Path");
    headers.push_back(L"Processed Elements");
    headers.push_back(L"Output Elements");
    headers.push_back(L"Execution Start Time");
    headers.push_back(L"Duration");
    headers.push_back(L"TLog Records");
    headers.push_back(L"CallStarted/CallEnded");
    headers.push_back(L"CompositorCreated/CompositorDestroyed");
    headers.push_back(L"AddView/RemoveView");
    headers.push_back(L"SetConfiguration/SetViewProperties");
}

/**
 * Gets list view values.
 */
void LogStatisticsListView::GetListViewValues(std::vector<std::vector<std::wstring>>& values) const
{
    assert(values.empty());

    Utilities::IIteratorSharedPtr<TLogging::ITLogStatisticsSharedPtr> logStatisticsIterator = m_logsStatistics->GetIterator();

    while (logStatisticsIterator->HasNext()) {
        const TLogging::ITLogStatisticsSharedPtr tlogStatistics = logStatisticsIterator->Next();
        const Logging::ILogStatisticsSharedPtr logStatistics = tlogStatistics->GetLogStatistics();

        std::vector<std::wstring> logStatisticsValues;
        logStatisticsValues.reserve(10);

        std::wstring path = logStatistics->GetPath();
        std::wstring numberOfElementsProcessed = std::to_wstring(logStatistics->GetNumberOfElementsProcessed());
        std::wstring numberOfElementsOutput = std::to_wstring(logStatistics->GetNumberOfElementsOutput());
        std::wstring exceutionStartTime = logStatistics->GetStartExecutionTime().ToString();
        std::wstring exceutionDuration = logStatistics->GetExecutionTime()->ToString();
        std::wstring numberOfTLogRecords = std::to_wstring(tlogStatistics->GetNumberOfTLogRecords());
        
        std::wstring callStartedCallEndedCounters = 
            CreateCallStartedCallEndedCountersString(*tlogStatistics);
        
        std::wstring compositorCreatedCompositorDestroyedCounters =
            CreateCompositorCreatedCompositorDestroyedCountersString(*tlogStatistics);
        
        std::wstring addViewRemoveViewCounters = 
            CreateAddViewRemoveViewCountersString(*tlogStatistics);
        
        std::wstring SetConfigurationSetViewPropertiesCounters = 
            CreateSetConfigurationSetViewPropertiesCountersString(*tlogStatistics);
        
        logStatisticsValues.push_back(path);
        logStatisticsValues.push_back(numberOfElementsProcessed);
        logStatisticsValues.push_back(numberOfElementsOutput);
        logStatisticsValues.push_back(exceutionStartTime);
        logStatisticsValues.push_back(exceutionDuration);
        logStatisticsValues.push_back(numberOfTLogRecords);
        logStatisticsValues.push_back(callStartedCallEndedCounters);
        logStatisticsValues.push_back(compositorCreatedCompositorDestroyedCounters);
        logStatisticsValues.push_back(addViewRemoveViewCounters);
        logStatisticsValues.push_back(SetConfigurationSetViewPropertiesCounters);

        values.push_back(logStatisticsValues);
    }
}

/**
 * Creates TLog records CallStarted/CallEnded counters string.
 */
std::wstring LogStatisticsListView::CreateCallStartedCallEndedCountersString(const TLogging::ITLogStatistics& logStatistics)
{
    std::wstringstream stream;
    stream 
        << std::to_wstring(logStatistics.GetNumberOfCallStartedRecords()) << L"/"
        << std::to_wstring(logStatistics.GetNumberOfCallEndedRecords());

    return stream.str();
}

/**
 * Creates TLog records CompositorCreated/CompositorDestroyed counters string.
 */
std::wstring LogStatisticsListView::CreateCompositorCreatedCompositorDestroyedCountersString(const TLogging::ITLogStatistics& logStatistics)
{
    std::wstringstream stream;
    stream 
        << std::to_wstring(logStatistics.GetNumberOfCompositorsCreatedRecords()) << L"/"
        << std::to_wstring(logStatistics.GetNumberOfCompositorsDestroyedRecords());

    return stream.str();
}

/**
 * Creates TLog records AddView/RemoveView counters string.
 */
std::wstring LogStatisticsListView::CreateAddViewRemoveViewCountersString(const TLogging::ITLogStatistics& logStatistics)
{
    std::wstringstream stream;
    stream 
        << std::to_wstring(logStatistics.GetNumberOfAddViewRecords()) << L"/"
        << std::to_wstring(logStatistics.GetNumberOfRemoveViewRecords());

    return stream.str();
}

/**
 * Creates TLog records SetConfiguration/SetViewProperties counters string.
 */
std::wstring LogStatisticsListView::CreateSetConfigurationSetViewPropertiesCountersString(const TLogging::ITLogStatistics& logStatistics)
{
    std::wstringstream stream;
    stream 
        << std::to_wstring(logStatistics.GetNumberOfSetConfigurationRecords()) << L"/"
        << std::to_wstring(logStatistics.GetNumberOfSetViewPropertiesRecords());

    return stream.str();
}
