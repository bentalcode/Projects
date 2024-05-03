#include "AbstractListView.h"
#include "DataCatalog.h"
#include "WXDataItems.h"
#include "DataItem.h"
#include "Color.h"
#include "IFont.h"
#include "WXProperty.h"
#include "WXWidgetsException.h"

using namespace WXWidgets;

namespace AbstractListViewFunctors {

/**
 * The UpdateDataContainerColumnsFunctor class implements an update functor of headers.
 */
class UpdateDataContainerHeadersFunctor final {
public:
    /**
     * The functor constructor.
     */
    UpdateDataContainerHeadersFunctor(DataContainerManagement::IDataContainer& dataContainer) : 
        m_dataContainer(dataContainer)
    {
    }

    /**
     * The functor logic.
     */
    void operator()(const std::vector<std::wstring>& headers)
    {
        AbstractListView::UpdateDataContainerHeaders(m_dataContainer, headers);
    }

private:
    DataContainerManagement::IDataContainer& m_dataContainer;
};

/**
 * The UpdateDataContainerValuesFunctor class implements an update functor of values.
 */
class UpdateDataContainerValuesFunctor final {
public:
    /**
     * The functor constructor.
     */
    UpdateDataContainerValuesFunctor(DataContainerManagement::IDataContainer& dataContainer) : 
        m_dataContainer(dataContainer)
    {
    }

    /**
     * The functor logic.
     */
    void operator()(const std::vector<std::vector<std::wstring>>& values)
    {
        AbstractListView::UpdateDataContainerValues(m_dataContainer, values);
    }

private:
    DataContainerManagement::IDataContainer& m_dataContainer;
};

}  // namespace AbstractListViewFunctors

/**
 * The AbstractListView constructor.
 */
AbstractListView::AbstractListView(
    wxWindow& parent, 
    const wxString& name,
    wxWindowID id,
    const wxPoint& position,
    const wxSize& size, 
    long style,
    const wxValidator& validator) : 
        wxListView(
            &parent, 
            id, 
            position, 
            size, 
            style, 
            validator, 
            name)
{
}

/**
 * The AbstractListView destructor.
 */
AbstractListView::~AbstractListView() 
{
}

/**
 * Initializes a GUI component.
 */
void AbstractListView::Initialize(
    const std::vector<std::wstring>& headers,
    const std::vector<std::vector<std::wstring>>& values,
    const wxListColumnFormat& headerFormat,
    size_t headerWidth,
    IGuiControllerSharedPtr guiController, 
    bool showMode)
{
    //
    // Validate input data...
    //
    ValidateHeaders(headers);
    ValidateRows(values, headers.size());

    //
    // Initialize window...
    //
    Window::Initialize(
        *this, 
        guiController, 
        showMode);

    //
    // Initialize data...
    //
    m_headers = headers;
    m_values = values;
    m_headerFormat = headerFormat;
    m_headerWidth = headerWidth;
    
    //
    // Reset component...
    //
    Reset();

    //
    // Register data update functors...
    //
    std::wstring dataItemListViewHeaders = WXDataItems::Read().GetListViewHeaders();

    DataContainerManagement::IDataContainer& dataContainer = GetData();
    dataContainer.GetCatalog().RegisterDataItem(dataItemListViewHeaders);

    DataContainerManagement::IDataContainerUpdateFunctors::IStringArrayFunctorSharedPtr headersUpdateFunctor =
        std::make_shared<DataContainerManagement::IDataContainerUpdateFunctors::IStringArrayFunctor>(
            AbstractListViewFunctors::UpdateDataContainerHeadersFunctor{ dataContainer });

    GetDataUpdateFunctors().RegisterUpdateFunctor(
        dataItemListViewHeaders, 
        headersUpdateFunctor);

    std::wstring dataItemListViewValues = WXDataItems::Read().GetListViewValues();

    dataContainer.GetCatalog().RegisterDataItem(dataItemListViewValues);

    DataContainerManagement::IDataContainerUpdateFunctors::IStringArrayArrayFunctorSharedPtr rowsUpdateFunctor =
        std::make_shared<DataContainerManagement::IDataContainerUpdateFunctors::IStringArrayArrayFunctor>(
            AbstractListViewFunctors::UpdateDataContainerValuesFunctor{ dataContainer });

    GetDataUpdateFunctors().RegisterUpdateFunctor(
        dataItemListViewValues, 
        rowsUpdateFunctor);
}

/**
 * Gets a window.
 */
IWindow& AbstractListView::GetWindow()
{
    return *this;
}

/**
 * Sets headers.
 */
void AbstractListView::SetHeaders(const std::vector<std::wstring>& headers)
{
    size_t numberOfHeaders = GetHeadersCount();

    if (numberOfHeaders > 0) {
        DeleteHeaders();
    }

    CreateHeaders(headers);
}

/**
 * Sets rows.
 */
void AbstractListView::SetRows(const std::vector<std::vector<std::wstring>>& values)
{
    //
    // Validate that headers are defined...
    //
    ValidateHeadersDefined();

    //
    // Validates rows...
    //
    size_t columnsSize = m_headers.size();
    ValidateRows(values, columnsSize);

    //
    // Clears all values...
    //
    Clear();

    //
    // Set all values...
    //
    size_t rowsSize = values.size();

    for (size_t rowIndex = 0; rowIndex < rowsSize; ++rowIndex) {
        CreateRow(rowIndex);

        for (size_t colIndex = 0; colIndex < columnsSize; ++colIndex) {
            const std::wstring& currValue = values[rowIndex][colIndex];
            SetValue(rowIndex, colIndex, currValue);
        }
    }
}

/**
 * Sets a row.
 */
void AbstractListView::SetRow(
    size_t rowIndex, 
    const std::vector<std::wstring>& values)
{
    size_t columnsSize = values.size();

    for (size_t columnIndex = 0; columnIndex < columnsSize; ++columnIndex) {
        SetValue(rowIndex, columnIndex, values[columnIndex]);
    }
}

/**
 * Sets a value.
 */
void AbstractListView::SetValue(
    size_t rowIndex, 
    size_t columnIndex, 
    const std::wstring& value)
{
    long rowIdx = GetTopItem() + rowIndex;
    bool status = SetItem(rowIdx, columnIndex, value);

    if (!status) {
        long errorCode = base::ErrorCodes::FAIL;

        std::wstringstream messageStream;
        messageStream 
            << L"The List View has failed inserting value at position: " << "[" << rowIndex << L", " << columnIndex << L"]" 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = messageStream.str();

        LOG_ERROR(GetLogger(), errorMessage);
        throw WXWidgetsException(errorMessage);
    }
}

/**
 * Gets headers.
 */
void AbstractListView::GetHeaders(std::vector<std::wstring>& headers) const
{
    assert(headers.empty());
    headers.assign(m_headers.begin(), m_headers.end());
}

/**
 * Sets headers attributes.
 */
void AbstractListView::SetHeaderAttributes(
    ColorType fontColorType, 
    ColorType backgroundColorType, 
    const IFont& font)
{
    Color fontColor(fontColorType);
    Color backgroundColor(backgroundColorType);
    wxItemAttr attibutes(fontColor.AsColor(), backgroundColor.AsColor(), font.AsFont());

    bool status = SetHeaderAttr(attibutes);

    if (!status) {
        long errorCode = base::ErrorCodes::FAIL;

        std::wstringstream messageStream;
        messageStream 
            << L"The List View has failed setting header attributes" 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = messageStream.str();

        LOG_ERROR(GetLogger(), errorMessage);
        throw WXWidgetsException(errorMessage);
    }
}

/**
 * Gets values.
 */
void AbstractListView::GetValues(std::vector<std::vector<std::wstring>>& values) const
{
    assert(values.empty());
    values.assign(m_values.begin(), m_values.end());
}

/**
 * Clears all values.
 */
void AbstractListView::Clear()
{
    bool status = DeleteAllItems(); 

    if (!status) {
        long errorCode = base::ErrorCodes::FAIL;

        std::wstringstream messageStream;
        messageStream 
            << L"Clear all items" 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = messageStream.str();

        LOG_ERROR(GetLogger(), errorMessage);
        throw WXWidgetsException(errorMessage);
    }
}

/**
 * Aligns columns widths by header.
 */
void AbstractListView::AlignColumnsWidthByHeader()
{
    size_t numOfColumns = GetHeadersCount();

    for (size_t columnIndex = 0; columnIndex < numOfColumns; ++columnIndex) {
        AlignColumnWidthByHeader(columnIndex);
    }
}

/**
 * Aligns column width by header.
 */
void AbstractListView::AlignColumnWidthByHeader(size_t columnIndex)
{
    bool status = SetColumnWidth(columnIndex, wxLIST_AUTOSIZE_USEHEADER);

    if (!status) {
        long errorCode = base::ErrorCodes::FAIL;

        std::wstringstream messageStream;
        messageStream 
            << L"The List View has failed adusting width of column: " << columnIndex << L" by header " 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = messageStream.str();

        LOG_ERROR(GetLogger(), errorMessage);
        throw WXWidgetsException(errorMessage);
    }
}

/**
 * Sets background color of a row.
 */
void AbstractListView::SetRowBackgroundColor(size_t rowIndex, ColorType colorType)
{
    Color color(colorType);
    long rowIdx = GetTopItem() + rowIndex;
    SetItemBackgroundColour(rowIdx, color.AsColor());
}

/**
 * Updates data container (headers).
 */
void AbstractListView::UpdateDataContainerHeaders(
    DataContainerManagement::IDataContainer& data, 
    const std::vector<std::wstring>& headers)
{
    std::wstring dataItemName = WXDataItems::Read().GetListViewHeaders();

    DataContainerManagement::IDataItemSharedPtr dataItem =
        DataContainerManagement::DataItem::Create(
            dataItemName, 
            headers);

    data.SetDataItem(dataItem);
}

/**
 * Updates data container (values).
 */
void AbstractListView::UpdateDataContainerValues(
    DataContainerManagement::IDataContainer& data,
    const std::vector<std::vector<std::wstring>>& values)
{
    std::wstring dataItemName = WXDataItems::Read().GetListViewValues();

    DataContainerManagement::IDataItemSharedPtr dataItem =
        DataContainerManagement::DataItem::Create(
            dataItemName, 
            values);

    data.SetDataItem(dataItem);
}

/**
 * Updates data from data container.
 * Returns true in case data has been updated.
 */
bool AbstractListView::UpdateFromDataContainer(DataContainerManagement::IDataContainer& dataContainer)
{
    bool dataUpdated = Window::UpdateFromDataContainer(dataContainer);

    std::wstring dataItemListViewHeaders = WXDataItems::Read().GetListViewHeaders();

    if (dataContainer.HasDataItem(dataItemListViewHeaders)) {
        const DataContainerManagement::IDataItem& dataItem = dataContainer.GetDataItem(dataItemListViewHeaders);
        
        const std::vector<std::wstring>& newHeaders = dataItem.GetValue()->GetStringArray();
        bool propertyUpdated = WXWidgets::WXProperty::UpdateArrayValue(m_headers, newHeaders);

        dataUpdated |= propertyUpdated;
    }

    std::wstring dataItemListViewValues = WXDataItems::Read().GetListViewValues();

    if (dataContainer.HasDataItem(dataItemListViewValues)) {
        const DataContainerManagement::IDataItem& dataItem = dataContainer.GetDataItem(dataItemListViewValues);

        const std::vector<std::vector<std::wstring>>& newValues = dataItem.GetValue()->GetStringArrayArray();
        bool propertyUpdated = WXWidgets::WXProperty::UpdateArrayArrayValue(m_values, newValues);

        dataUpdated |= propertyUpdated;
    }

    return dataUpdated;
}

/**
 * Updates component.
 */
void AbstractListView::Update()
{
    //
    // Update window...
    //
    Window::Update();

    //
    // Reset component...
    //
    Reset();
}

/**
 * Resets component.
 */
void AbstractListView::Reset()
{
    //
    // Set headers; If no headers are defined do not show the list view...
    //
    if (m_headers.empty()) {
        ShowOrHide(false);
    } else {
        SetHeaders(m_headers);
        SetRows(m_values);
    }
}

/**
 * Gets headers.
 */
void AbstractListView::GetHeaders(std::vector<wxListItem>& headers) const
{
    assert(headers.empty());

    size_t numberOfHeaders = GetHeadersCount();
    headers.reserve(numberOfHeaders);

    for (size_t index = 0; index < numberOfHeaders; ++index) {
        wxListItem item;
        GetHeaderProperties(index, item);

        headers.push_back(item);
    }
}

/**
 * Creates headers.
 */
void AbstractListView::CreateHeaders(const std::vector<std::wstring>& headers)
{
    for (const std::wstring& header : headers) {
        
        CreateHeader(
            header, 
            m_headerFormat, 
            m_headerWidth);
    }

    std::vector<wxListItem> headersProperties;
    GetHeaders(headersProperties);

    if (headersProperties.size() != headers.size()) {
        long errorCode = base::ErrorCodes::UNEXPECTED;

        std::wstringstream messageStream;
        messageStream 
            << L"The List View has failed creating headers properly: " 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = messageStream.str();

        LOG_ERROR(GetLogger(), errorMessage);
        throw WXWidgetsException(errorMessage);
    }
}

/**
 * Deletes headers.
 */
void AbstractListView::DeleteHeaders() 
{
    bool status = DeleteAllColumns();

    if (!status) {
        long errorCode = base::ErrorCodes::FAIL;

        std::wstringstream messageStream;
        messageStream 
            << L"The List View has failed deleting all columns: " 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = messageStream.str();

        LOG_ERROR(GetLogger(), errorMessage);
        throw WXWidgetsException(errorMessage);
    }
}

/**
 * Deletes values.
 */
void AbstractListView::DeleteValues() 
{
    bool status = DeleteAllItems();

    if (!status) {
        long errorCode = base::ErrorCodes::FAIL;

        std::wstringstream messageStream;
        messageStream 
            << L"The List View has failed deleting all items: " 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = messageStream.str();

        LOG_ERROR(GetLogger(), errorMessage);
        throw WXWidgetsException(errorMessage);
    }
}

/**
 * Gets number of headers.
 */
size_t AbstractListView::GetHeadersCount() const
{
    return GetColumnCount();
}

/**
 * Creates a header and returns it's index.
 */
long AbstractListView::CreateHeader(
    const std::wstring& name, 
    wxListColumnFormat format,
    int width)
{
    long idx = wxListCtrl::AppendColumn(name, format, width);

    if (idx == -1) {
        long errorCode = base::ErrorCodes::FAIL;

        std::wstringstream messageStream;
        messageStream 
            << L"The List View has failed appending column header: " << name 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = messageStream.str();
        
        LOG_ERROR(GetLogger(), errorMessage);
        throw WXWidgetsException(errorMessage);
    }

    wxListItem item;
    GetHeaderProperties(idx, item);

    return idx;
}

/**
 * Creates a header and returns it's index.
 */
long AbstractListView::CreateHeader(
    long index, 
    const std::wstring& name, 
    wxListColumnFormat format, 
    int width)
{
    long idx = wxListCtrl::InsertColumn(
        index, 
        name, 
        format, 
        width);

    wxListItem item;
    GetHeaderProperties(idx, item);

    return idx;
}

/**
 * Creates a row and returns it's index.
 */
long AbstractListView::CreateRow(size_t rowIndex)
{
    std::wstring value;
    long idx = InsertItem(rowIndex, value);

    if (idx == -1) {
        long errorCode = base::ErrorCodes::FAIL;

        std::wstringstream messageStream;
        messageStream 
            << L"The List View has failed inserting item at row: " << rowIndex 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = messageStream.str();

        LOG_ERROR(GetLogger(), errorMessage);
        throw WXWidgetsException(errorMessage);
    }

    return idx;
}

/**
 * Gets properties of a header.
 */
void AbstractListView::GetHeaderProperties(
    int index, 
    wxListItem& item) const
{
    bool status = wxListCtrl::GetColumn(index, item);

    if (!status) {
        long errorCode = base::ErrorCodes::UNEXPECTED;

        std::wstringstream messageStream;
        messageStream 
            << L"The List View has failed finding column at index: " << index
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = messageStream.str();

        LOG_ERROR(GetSLogger(), errorMessage);
        throw WXWidgetsException(errorMessage);
    }
}

/**
 * Validates headers defined.
 */
void AbstractListView::ValidateHeadersDefined() const
{
    if (m_headers.empty()) {
        long errorCode = base::ErrorCodes::ACCESS_DENIED;

        std::wstringstream messageStream;
        messageStream 
            << L"The headers of List View are not defined" 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = messageStream.str();

        LOG_ERROR(GetLogger(), errorMessage);
        throw WXWidgetsException(errorMessage);
    }
}

/**
 * Validates headers.
 */
void AbstractListView::ValidateHeaders(const std::vector<std::wstring>& headers)
{
    if (!AreHeadersValid(headers)) {
        long errorCode = base::ErrorCodes::INVALID_ARG;

        std::wstringstream messageStream;
        messageStream 
            << L"The headers of List View are invalid" 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);
        
        std::wstring errorMessage = messageStream.str();

        LOG_ERROR(GetSLogger(), errorMessage);
        throw WXWidgetsException(errorMessage);
    }
}

/**
 * Validates rows.
 */
void AbstractListView::ValidateRows(
    const std::vector<std::vector<std::wstring>>& rows, 
    size_t expectedSize)
{
    if (!AreRowsValid(rows, expectedSize)) {
        long errorCode = base::ErrorCodes::INVALID_ARG;

        std::wstringstream messageStream;
        messageStream 
            << L"The input rows of List View are invalid" 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = messageStream.str();
        
        LOG_ERROR(GetSLogger(), errorMessage);
        throw WXWidgetsException(errorMessage);
    }
}

/**
 * Validates rows.
 */
void AbstractListView::ValidateRow(
    const std::vector<std::wstring>& values, 
    size_t expectedSize)
{
    if (!IsRowValid(values, expectedSize)) {
        long errorCode = base::ErrorCodes::INVALID_ARG;

        std::wstringstream messageStream;
        messageStream 
            << L"The input row of List View is invalid" 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);
        
        std::wstring errorMessage = messageStream.str();

        LOG_ERROR(GetSLogger(), errorMessage);
        throw WXWidgetsException(errorMessage);
    }
}

/**
 * Checks whether columns are valid.
 */
bool AbstractListView::AreHeadersValid(const std::vector<std::wstring>& headers)
{
    return !headers.empty();
}

/**
 * Checks whether rows are valid.
 */
bool AbstractListView::AreRowsValid(
    const std::vector<std::vector<std::wstring>>& values, 
    size_t expectedSize) 
{
    for (const std::vector<std::wstring>& rowValues : values) {
        
        if (!IsRowValid(rowValues, expectedSize)) {
            return false;
        }
    }

    return true;
}

/**
 * Checks whether a row is valid.
 */
bool AbstractListView::IsRowValid(
    const std::vector<std::wstring>& values, 
    size_t expectedSize) 
{
    return values.size() == expectedSize;
}
