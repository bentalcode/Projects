#include "AppLogListView.h"
#include "GuiManager.h"
#include "GuiPaths.h"
#include "Font.h"
#include "Log.h"
#include "LogHeader.h"
#include "TabularRecord.h"

using namespace VideoRenderingVisualizer;
using namespace VideoRenderingVisualizer::Gui;

/**
 * Creates an App Log List View.
 */
WXWidgets::IListViewPtr AppLogListView::Make(
    wxWindow& parent, 
    const std::filesystem::path& logPath,
    IGuiManager& guiManager)
{
    return WXWidgets::IListViewPtr::Make(
        new AppLogListView(
            parent, 
            logPath,
            guiManager));
}

/**
 * The AppLogListView constructor.
 */
AppLogListView::AppLogListView(
    wxWindow& parent, 
    const std::filesystem::path& logPath,
    IGuiManager& guiManager) : 
        ListView(
            parent, 
            GuiPaths::Read().GetMainFrameTopMenuBarViewMenuAppLogDialogListView()), 
        m_guiManager(guiManager), 
        m_logPath(logPath)
{
    //
    // Initialize a GUI component...
    //
    Initialize(guiManager);
}

/**
 * The AppLogListView destructor.
 */
AppLogListView::~AppLogListView() 
{
}

/**
 * Initializes a GUI component.
 */
void AppLogListView::Initialize(IGuiManager& guiManager)
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
void AppLogListView::GetListViewInformation(
    std::vector<std::wstring>& headers,
    std::vector<std::vector<std::wstring>>& values) const
{
    GetListViewHeaders(headers);
    GetListViewValues(values);
}

/**
 * Gets list view headers.
 */
void AppLogListView::GetListViewHeaders(std::vector<std::wstring>& headers) const
{
    assert(headers.empty());
    
    Logging::ILogHeaderSharedPtr header = Logging::LogHeader::Make();
    TabularData::ITabularHeaderSharedPtr tabularHeader = header->ToHeader();
    tabularHeader->GetHeaders(headers);
}

/**
 * Gets list view values.
 */
void AppLogListView::GetListViewValues(std::vector<std::vector<std::wstring>>& values) const
{
    assert(values.empty());
    
    Logging::ILogSharedPtr log = Logging::Log::Make(m_logPath);

    Utilities::IIteratorSharedPtr<Logging::ILogRecordSharedPtr> recordIterator = log->GetIterator();

    while (recordIterator->HasNext()) {
        Logging::ILogRecordSharedPtr record = recordIterator->Next();

        if (record == nullptr) {
            continue;
        }

        TabularData::ITabularRecordSharedPtr tabularRecord = record->ToRecord();

        std::vector<std::wstring> recordValues;
        tabularRecord->GetValues(recordValues);

        values.push_back(recordValues);
    }
}
