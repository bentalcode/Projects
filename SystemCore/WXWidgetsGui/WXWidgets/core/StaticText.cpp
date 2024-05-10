#include "StaticText.h"
#include "WXDataItems.h"
#include "DataItem.h"
#include "IDataCatalog.h"
#include "WXProperty.h"

using namespace wxwidgets;

namespace StaticTextFunctors {

/**
 * The UpdateDataContainerTextFunctor class implements an update functor of text.
 */
class UpdateDataContainerTextFunctor final {
public:
    /**
     * The functor constructor.
     */
    UpdateDataContainerTextFunctor(DataContainerManagement::IDataContainer& dataContainer) : 
        m_dataContainer(dataContainer)
    {
    }

    /**
     * The functor logic.
     */
    void operator()(const std::wstring& text)
    {
        StaticText::UpdateDataContainerText(m_dataContainer, text);
    }

private:
    DataContainerManagement::IDataContainer& m_dataContainer;
};

} // namespace StaticTextFunctors

/**
 * Creates a static text.
 */
IStaticTextPtr StaticText::Make(
    wxWindow& parent, 
    const wxString& name, 
    const wxString& label,
    wxWindowID id, 
    const wxPoint& position,
    const wxSize& size, 
    long style)
{
    return IStaticTextPtr::Make(
        new StaticText(
            parent, 
            name, 
            label,
            id, 
            position,
            size,
            style));
}

/**
 * The StaticText constructor.
 */
StaticText::StaticText(
    wxWindow& parent, 
    const wxString& name, 
    const wxString& label, 
    wxWindowID id,
    const wxPoint& position,
    const wxSize& size, 
    long style) : 
        wxStaticText(
            &parent, 
            id,
            label, 
            position,
            size,
            style, 
            name), 
            m_text(label)
{
}

/**
 * The StaticText destructor.
 */
StaticText::~StaticText() 
{
}

/**
 * Initializes a GUI component.
 */
void StaticText::Initialize(IGuiControllerSharedPtr guiController)
{
    /**
     * Initializes window...
     */
    Window::Initialize(
        *this, 
        guiController);

    //
    // Register data items...
    //
    std::wstring dataItemName = WXDataItems::Read().GetStaticTextValue();

    DataContainerManagement::IDataContainer& dataContainer = GetData();
    dataContainer.GetCatalog().RegisterDataItem(dataItemName);

    //
    // Register data update functors...
    //
    DataContainerManagement::IDataContainerUpdateFunctors::IStringFunctorSharedPtr updateFunctor =
        std::make_shared<DataContainerManagement::IDataContainerUpdateFunctors::IStringFunctor>(
            StaticTextFunctors::UpdateDataContainerTextFunctor{ dataContainer });

    GetDataUpdateFunctors().RegisterUpdateFunctor(
        dataItemName, 
        updateFunctor);
}

/**
 * Gets a window.
 */
IWindow& StaticText::GetWindow()
{
    return *this;
}

/**
 * Sets text.
 */
void StaticText::SetText(const std::wstring& text)
{
    SetLabel(text);
}

/**
 * Updates data container (text).
 */
void StaticText::UpdateDataContainerText(
    DataContainerManagement::IDataContainer& data, 
    const std::wstring& text)
{
    std::wstring dataItemStaticTextValue = WXDataItems::Read().GetStaticTextValue();

    DataContainerManagement::IDataItemSharedPtr dataItem =
        DataContainerManagement::DataItem::Create(
            dataItemStaticTextValue, 
            text);

    data.SetDataItem(dataItem);
}

/**
 * Updates data from data container.
 * Returns true in case data has been updated.
 */
bool StaticText::UpdateFromDataContainer(DataContainerManagement::IDataContainer& dataContainer)
{
    bool dataUpdated = Window::UpdateFromDataContainer(dataContainer);

    std::wstring dataItemStaticTextValue = WXDataItems::Read().GetStaticTextValue();

    if (dataContainer.HasDataItem(dataItemStaticTextValue)) {
        const DataContainerManagement::IDataItem& dataItem = dataContainer.GetDataItem(dataItemStaticTextValue);

        std::wstring text = dataItem.GetValue()->GetString();
        bool propertyUpdated = wxwidgets::WXProperty::UpdateValue(m_text, text);

        dataUpdated |= propertyUpdated;
    }

    return dataUpdated;
}

/**
 * Updates component.
 */
void StaticText::Update()
{
    Window::Update();

    //
    // Set text...
    //
    SetText(m_text);
}
