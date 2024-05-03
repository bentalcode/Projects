#include "TextControl.h"
#include "WXProperty.h"
#include "WXDataItems.h"
#include "DataItem.h"
#include "IDataCatalog.h"

using namespace WXWidgets;

namespace TextControlFunctors {

/**
 * The UpdateDataContainerTextFunctor class implements an update functor of text.
 */
class UpdateDataContainerTextFunctor final {
public:
    /**
     * The functor constructor.
     */
    UpdateDataContainerTextFunctor(DataContainerManagement::IDataContainer& dataContainer)
        : m_dataContainer(dataContainer)
    {
    }

    /**
     * The functor logic.
     */
    void operator()(const std::wstring& value)
    {
        TextControl::UpdateDataContainerValue(m_dataContainer, value);
    }

private:
    DataContainerManagement::IDataContainer& m_dataContainer;
};

}  // namespace TextControlFunctors

/**
 * Creates a text control.
 */
ITextControlPtr TextControl::Make(
    wxWindow& parent, 
    const wxString& name, 
    const wxString& value, 
    wxWindowID id,
    const wxPoint& position,
    const wxSize& size,
    long style,
    const wxValidator& validator)
{
    return ITextControlPtr::Make(
        new TextControl(
            parent, 
            name, 
            value,
            id, 
            position,
            size,
            style,
            validator));
}

/**
 * The TextControl constructor.
 */
TextControl::TextControl(
    wxWindow& parent, 
    const wxString& name, 
    const wxString& value,
    wxWindowID id, 
    const wxPoint& position, 
    const wxSize& size, 
    long style,
    const wxValidator& validator) : 
        wxTextCtrl(
            &parent, 
            id,
            value, 
            position,
            size,
            style,
            validator,
            name)
{
}

/**
 * The TextControl destructor.
 */
TextControl::~TextControl() 
{
}

/**
 * Initializes a GUI component.
 */
void TextControl::Initialize(IGuiControllerSharedPtr guiController)
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
    std::wstring dataItemTextControlValue = WXDataItems::Read().GetTextControlValue();
    DataContainerManagement::IDataContainer& dataContainer = GetData();
    dataContainer.GetCatalog().RegisterDataItem(dataItemTextControlValue);

    //
    // Register data update functors...
    //
    DataContainerManagement::IDataContainerUpdateFunctors::IStringFunctorSharedPtr updateFunctor =
        std::make_shared<DataContainerManagement::IDataContainerUpdateFunctors::IStringFunctor>(
            TextControlFunctors::UpdateDataContainerTextFunctor{ dataContainer });

    GetDataUpdateFunctors().RegisterUpdateFunctor(
        dataItemTextControlValue, 
        updateFunctor);
}

/**
 * Gets a window.
 */
IWindow& TextControl::GetWindow() 
{
    return *this;
}

/**
 * Sets a value.
 */
void TextControl::SetValue(const wxString& value)
{
    wxTextCtrl::SetValue(value);
}

/**
 * Updates data container (value).
 */
void TextControl::UpdateDataContainerValue(
    DataContainerManagement::IDataContainer& data, 
    const std::wstring& value)
{
    std::wstring dataItemTextControlValue = WXDataItems::Read().GetTextControlValue();

    DataContainerManagement::IDataItemSharedPtr dataItem =
        DataContainerManagement::DataItem::Create(
            dataItemTextControlValue, 
            value);

    data.SetDataItem(dataItem);
}

/**
 * Updates data from data container.
 * Returns true in case data has been updated.
 */
bool TextControl::UpdateFromDataContainer(DataContainerManagement::IDataContainer& dataContainer)
{
    bool dataUpdated = Window::UpdateFromDataContainer(dataContainer);

    std::wstring dataItemTextControlValue = WXDataItems::Read().GetTextControlValue();

    if (dataContainer.HasDataItem(dataItemTextControlValue)) {
        const DataContainerManagement::IDataItem& dataItem = dataContainer.GetDataItem(dataItemTextControlValue);

        std::wstring value = dataItem.GetValue()->GetString();
        bool propertyUpdated = WXWidgets::WXProperty::UpdateValue(m_value, value);

        dataUpdated |= propertyUpdated;
    }

    return dataUpdated;
}

/**
 * Updates component.
 */
void TextControl::Update()
{
    Window::Update();

    //
    // Set text...
    //
    TextControl::SetValue(wxString(m_value));
}
