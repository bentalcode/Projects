#include "AbstractListBox.h"
#include "DataCatalog.h"
#include "WXDataItems.h"
#include "DataItem.h"
#include "WXProperty.h"
#include <vector>

using namespace wxwidgets;

const size_t AbstractListBox::MIN_ITEM_SIZE = 100;
const size_t AbstractListBox::MIN_NUMBER_OF_PADS_ITEMS = 10;

namespace AbstractListBoxFunctors {

/**
 * The UpdateDataContainerItemsFunctor class implements an update functor of items.
 */
class UpdateDataContainerItemsFunctor final {
public:
    /**
     * The functor constructor.
     */
    UpdateDataContainerItemsFunctor(DataContainerManagement::IDataContainer& dataContainer) : 
        m_dataContainer(dataContainer)
    {
    }

    /**
     * The functor logic.
     */
    void operator()(const std::vector<std::wstring>& items)
    {
        AbstractListBox::UpdateDataContainerItems(m_dataContainer, items);
    }

private:
    DataContainerManagement::IDataContainer& m_dataContainer;
};

} // namespace AbstractListBoxFunctors

/**
 * The AbstractListBox constructor.
 */
AbstractListBox::AbstractListBox(
    wxWindow& parent, 
    const wxString& name, 
    wxWindowID id, 
    const wxPoint& position, 
    const wxSize& size,
    int n, 
    long style, 
    const wxValidator& validator, 
    size_t minItemSize,
    size_t minNumberOfItems) : 
        wxListBox(
            &parent, 
            id, 
            position, 
            size, 
            n, 
            NULL, 
            style, 
            validator, 
            name), 
    m_minItemSize(minItemSize),
    m_minNumberOfItems(minNumberOfItems)
{
    m_padItem = CreatePadItem(m_minItemSize);
}

/**
 * The AbstractListBox destructor.
 */
AbstractListBox::~AbstractListBox() 
{
}

/**
 * Initializes a GUI component.
 */
void AbstractListBox::Initialize(
    const IOnSelectedItemFunctorSharedPtr onSelectedItemFunctor,
    const std::vector<std::wstring>& items, 
    IGuiControllerSharedPtr guiController,
    bool showMode)
{
    //
    // Initialize window...
    //
    Window::Initialize(
        *this, 
        guiController, 
        showMode);

    //
    // Initialize functors...
    //
    m_onSelectedItemFunctor = onSelectedItemFunctor;

    //
    // Initialize data...
    //
    m_items = items;

    //
    // Reset component...
    //
    Reset();

    //
    // Bind callbacks...
    //
    Bind(wxEVT_LISTBOX, &AbstractListBox::InternalOnSelectedItem, this);

    //
    // Register data update functors...
    //
    std::wstring dataItemListBoxItems = WXDataItems::Read().GetListBoxItems();

    DataContainerManagement::IDataContainer& dataContainer = GetData();
    dataContainer.GetCatalog().RegisterDataItem(dataItemListBoxItems);

    DataContainerManagement::IDataContainerUpdateFunctors::IStringArrayFunctorSharedPtr updateFunctor =
        std::make_shared<DataContainerManagement::IDataContainerUpdateFunctors::IStringArrayFunctor>(
            AbstractListBoxFunctors::UpdateDataContainerItemsFunctor{ dataContainer });

    GetDataUpdateFunctors().RegisterUpdateFunctor(
        dataItemListBoxItems, 
        updateFunctor);
}

/**
 * Gets a window.
 */
IWindow& AbstractListBox::GetWindow()
{
    return *this;
}

/**
 * Set a selected item.
 */
bool AbstractListBox::SetSelectedItem(int index) {
    if (IsEmpty()) {
        return false;
    }

    wxListBox::SetSelection(index);

    return true;
}

/**
 * The On Selected Item callback - Default Implementation.
 */
void AbstractListBox::OnSelectedItem(const std::wstring& item) 
{
}

/**
 * Updates data container (items).
 */
void AbstractListBox::UpdateDataContainerItems(
    DataContainerManagement::IDataContainer& data, 
    const std::vector<std::wstring>& items)
{
    std::wstring dataItemName = WXDataItems::Read().GetListBoxItems();

    DataContainerManagement::IDataItemSharedPtr dataItem =
        DataContainerManagement::DataItem::Create(
            dataItemName, 
            items);

    data.SetDataItem(dataItem);
}

/**
 * Updates data from data container.
 * Returns true in case data has been updated.
 */
bool AbstractListBox::UpdateFromDataContainer(DataContainerManagement::IDataContainer& dataContainer)
{
    bool dataUpdated = Window::UpdateFromDataContainer(dataContainer);

    std::wstring dataItemName = WXDataItems::Read().GetListBoxItems();

    if (dataContainer.HasDataItem(dataItemName)) {
        const DataContainerManagement::IDataItem& dataItem = dataContainer.GetDataItem(dataItemName);
        
        const std::vector<std::wstring>& newItems = dataItem.GetValue()->GetStringArray();
        bool propertyUpdated = wxwidgets::WXProperty::UpdateValue(m_items, newItems);

        dataUpdated |= propertyUpdated;
    }

    return dataUpdated;
}

/**
 * Updates component.
 */
void AbstractListBox::Update()
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
void AbstractListBox::Reset()
{
    //
    // Set items; If no items are defined do not show the list box...
    //
    if (m_items.empty()) {
        ShowOrHide(false);
        return;
    }
    
    //
    // Set items...
    //
    SetItems(m_items);
    
    //
    // Set scroll bars to min position...
    //
    std::vector<Orient> orients = { Orient::HORIZONTAL, Orient::VERTICAL };

    for (Orient orient : orients) {
        if (ScrollbarExists(orient)) {
            SetScrollbarToMinPosition(orient);
        }
    }
}

/**
 * The internal Selected Item callback.
 */
void AbstractListBox::InternalOnSelectedItem(wxCommandEvent& event)
{
    //
    // Get selected item...
    //
    int selectedItemId = event.GetSelection();

    if (selectedItemId == wxNOT_FOUND)
    {
        long errorCode = base::ErrorCodes::UNEXPECTED;

        std::wstringstream messageStream;
        messageStream 
            << L"No item has been selected in list box: " << GuiComponent::GetName() 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = messageStream.str();
        
        LOG_ERROR(GetLogger(), errorMessage);
        throw WXWidgetsException(errorMessage);
    }

    //
    // Skip pad items...
    //
    if (selectedItemId >= m_items.size()) {
        return;
    }

    //
    // Process selected item...
    //
    std::wstring selectedItem = m_items[selectedItemId];

    if (m_onSelectedItemFunctor) {
        m_onSelectedItemFunctor->operator()(selectedItem);
    }
}

/**
 * Sets items.
 */
void AbstractListBox::SetItems(const std::vector<std::wstring>& items)
{
    Clear();
    
    size_t numberOfItems = items.size();
    size_t numberOfPadsItems = m_minNumberOfItems - numberOfItems;

    for (const std::wstring& item : items) {
        std::wstring padItem;
        PadItem(item, padItem);

        wxString entry(padItem);
        int itemIndex = Append(entry);
        EnsureVisible(itemIndex);
    }

    for (int index = 0; index < numberOfPadsItems; ++index) {
        wxString entry(m_padItem);
        int itemIndex = Append(entry);
    }
}

/**
 * Pads an item.
 * Returns true if an item has been pad.
 */
bool AbstractListBox::PadItem(const std::wstring& item, std::wstring& result)
{
    assert(result.empty());

    if (item.size() >= MIN_ITEM_SIZE) {
        return false;
    }

    size_t padSize = MIN_ITEM_SIZE - item.size(); 
    std::vector<std::wstring::value_type> buffer(item.begin(), item.end());

    for (size_t index = 0; index < padSize; ++index) {
        buffer.push_back(' ');
    }

    result.assign(buffer.begin(), buffer.end());

    return true;
}

/**
 * Creates a pad item with a specified size.
 */
std::wstring AbstractListBox::CreatePadItem(size_t size)
{
    if (size == 0) {
        return L"";
    }

    std::vector<std::wstring::value_type> buffer;
    buffer.reserve(size);

    for (size_t index = 0; index < size; ++index) {
        buffer.push_back(L' ');
    }

    return std::wstring(buffer.begin(), buffer.end());
}