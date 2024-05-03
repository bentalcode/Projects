#include "AbstractSlider.h"
#include "DataItem.h"
#include "WXDataItems.h"
#include "IDataCatalog.h"
#include "WXProperty.h"
#include "ComparatorFactory.h"

using namespace WXWidgets;

const double AbstractSlider::PRECISION = 100.0;

namespace AbstractSliderFunctors {

/**
 * The UpdateDataContainerDimensionValueFunctor class implements an update functor of dimension value.
 */
class UpdateDataContainerDimensionValueFunctor final {
public:
    /**
     * The functor constructor.
     */
    UpdateDataContainerDimensionValueFunctor(DataContainerManagement::IDataContainer& dataContainer) : 
        m_dataContainer(dataContainer)
    {
    }

    /**
     * The functor logic.
     */
    void operator()(int value) 
    { 
        AbstractSlider::UpdateDataContainerDimensionValue(m_dataContainer, value); 
    }

private:
    DataContainerManagement::IDataContainer& m_dataContainer;
};

/**
 * The UpdateDataContainerDimensionMinValueFunctor class implements an update functor of dimension min value.
 */
class UpdateDataContainerDimensionMinValueFunctor final {
public:
    /**
     * The functor constructor.
     */
    UpdateDataContainerDimensionMinValueFunctor(DataContainerManagement::IDataContainer& dataContainer) : 
        m_dataContainer(dataContainer)
    {
    }

    /**
     * The functor logic.
     */
    void operator()(int value) 
    { 
        AbstractSlider::UpdateDataContainerDimensionMinValue(m_dataContainer, value); 
    }

private:
    DataContainerManagement::IDataContainer& m_dataContainer;
};

/**
 * The UpdateDataContainerDimensionMaxValueFunctor class implements an update functor of dimension max value.
 */
class UpdateDataContainerDimensionMaxValueFunctor final {
public:
    /**
     * The functor constructor.
     */
    UpdateDataContainerDimensionMaxValueFunctor(DataContainerManagement::IDataContainer& dataContainer) : 
        m_dataContainer(dataContainer)
    {
    }

    /**
     * The functor logic.
     */
    void operator()(int value) 
    { 
        AbstractSlider::UpdateDataContainerDimensionMaxValue(m_dataContainer, value); 
    }

private:
    DataContainerManagement::IDataContainer& m_dataContainer;
};

}  // namespace AbstractSliderFunctors

/**
 * The AbstractSlider constructor.
 */
AbstractSlider::AbstractSlider(
    wxWindow& parent, 
    const wxString& name, 
    int dimensionValue, 
    int dimensionMinValue,
    int dimensionMaxValue, 
    long style, 
    wxWindowID id, 
    const wxPoint& position,
    const wxSize& size, 
    const wxValidator& validator,
    double precision) : 
        wxSlider(
            &parent, 
            id, 
            dimensionValue, 
            dimensionMinValue, 
            dimensionMaxValue, 
            position, 
            size, 
            style, 
            validator, 
            name), 
        m_precision(precision), 
        m_dimensionValue(dimensionValue), 
        m_dimensionMinValue(dimensionMinValue), 
        m_dimensionMaxValue(dimensionMaxValue)
{
    //
    // Initialize the almost comparator of integer dimension values...
    //
    base::IComparatorFactorySharedPtr factory = base::ComparatorFactory::Make();
    m_dimensionValueComparator = factory->GetAlmostIntegerComparator();
}

/**
 * The AbstractSlider destructor.
 */
AbstractSlider::~AbstractSlider() 
{
}

/**
 * Initializes a GUI component.
 */
void AbstractSlider::Initialize(
    const IOnSliderUpdatedFunctorSharedPtr onSliderUpdatedFunctor, 
    IGuiControllerSharedPtr guiController)
{
    //
    // Initialize window...
    //
    Window::Initialize(
        *this, 
        guiController);

    //
    // Reset component...
    //
    Reset();

    //
    // Initialize functors...
    //
    m_onSliderUpdatedFunctor = onSliderUpdatedFunctor;
    
    //
    // Bind callbacks...
    //
    Bind(wxEVT_SCROLL_CHANGED, &AbstractSlider::InternalOnSliderUpdated, this);

    //
    // Register data items...
    //
    std::wstring dataItemSliderDimensionValue = WXDataItems::Read().GetSliderDimensionValue();
    std::wstring dataItemSliderDimensionMinValue = WXDataItems::Read().GetSliderDimensionMinValue();
    std::wstring dataItemSliderDimensionMaxValue = WXDataItems::Read().GetSliderDimensionMaxValue();

    DataContainerManagement::IDataContainer& dataContainer = GetData();
    dataContainer.GetCatalog().RegisterDataItem(dataItemSliderDimensionValue);
    dataContainer.GetCatalog().RegisterDataItem(dataItemSliderDimensionMinValue);
    dataContainer.GetCatalog().RegisterDataItem(dataItemSliderDimensionMaxValue);

    //
    // Register data update functors...
    //
    DataContainerManagement::IDataContainerUpdateFunctors::IIntegerFunctorSharedPtr updateDimensionValueFunctor =
        std::make_shared<DataContainerManagement::IDataContainerUpdateFunctors::IIntegerFunctor>(
            AbstractSliderFunctors::UpdateDataContainerDimensionValueFunctor{ dataContainer });

    GetDataUpdateFunctors().RegisterUpdateFunctor(
        dataItemSliderDimensionValue, 
        updateDimensionValueFunctor);

    DataContainerManagement::IDataContainerUpdateFunctors::IIntegerFunctorSharedPtr updateDimensionMinValueFunctor =
        std::make_shared<DataContainerManagement::IDataContainerUpdateFunctors::IIntegerFunctor>(
            AbstractSliderFunctors::UpdateDataContainerDimensionMinValueFunctor{ dataContainer });

    GetDataUpdateFunctors().RegisterUpdateFunctor(
        dataItemSliderDimensionMinValue, 
        updateDimensionMinValueFunctor);

    DataContainerManagement::IDataContainerUpdateFunctors::IIntegerFunctorSharedPtr updateDimensionMaxValueFunctor =
        std::make_shared<DataContainerManagement::IDataContainerUpdateFunctors::IIntegerFunctor>(
            AbstractSliderFunctors::UpdateDataContainerDimensionMaxValueFunctor{ dataContainer });

    GetDataUpdateFunctors().RegisterUpdateFunctor(
        dataItemSliderDimensionMaxValue,
        updateDimensionMaxValueFunctor);
}

/**
 * Gets a window.
 */
IWindow& AbstractSlider::GetWindow()
{
    return *this;
}

/**
 * Sets scroll precision.
 */
void AbstractSlider::SetScrollPrecision(double precision)
{
    ValidatePrecision(precision);
    m_precision = precision;
}

/**
 * Gets value of a dimension.
 */
int AbstractSlider::GetDimensionValue() const 
{
    return wxSlider::GetValue();
}

/**
 * Sets value of a dimension.
 */
void AbstractSlider::SetDimensionValue(int value)
{
    wxSlider::SetValue(value);
    m_dimensionValue = value;
}

/**
 * Gets value of a min dimension.
 */
int AbstractSlider::GetDimensionMinValue() const
{
    return wxSlider::GetMin();
}

/**
 * Sets min value of a dimension.
 */
void AbstractSlider::SetDimensionMinValue(int value)
{
    wxSlider::SetMin(value);
    m_dimensionMinValue = value;
}

/**
 * Gets value of a max dimension.
 */
int AbstractSlider::GetDimensionMaxValue() const
{
    return wxSlider::GetMax();
}

/**
 * Sets max value of a dimension.
 */
void AbstractSlider::SetDimensionMaxValue(int value)
{
    wxSlider::SetMax(value);
    m_dimensionMaxValue = value;
}

/**
 * The On Slider Updated callback - Default Implementation.
 */
void AbstractSlider::OnSliderUpdated(int value) 
{
    m_dimensionValue = value;
}

/**
 * Updates data container (dimension value).
 */
void AbstractSlider::UpdateDataContainerDimensionValue(
    DataContainerManagement::IDataContainer& data, 
    int value)
{
    std::wstring dataItemName = WXDataItems::Read().GetSliderDimensionValue();

    DataContainerManagement::IDataItemSharedPtr dataItem =
        DataContainerManagement::DataItem::Create(
            dataItemName, 
            value);

    data.SetDataItem(dataItem);
}

/**
 * Updates data container (dimension min value).
 */
void AbstractSlider::UpdateDataContainerDimensionMinValue(
    DataContainerManagement::IDataContainer& data, 
    int value)
{
    std::wstring dataItemName = WXDataItems::Read().GetSliderDimensionMinValue();

    DataContainerManagement::IDataItemSharedPtr dataItem =
        DataContainerManagement::DataItem::Create(
            dataItemName, 
            value);

    data.SetDataItem(dataItem);
}

/**
 * Updates data container (dimension max value).
 */
void AbstractSlider::UpdateDataContainerDimensionMaxValue(
    DataContainerManagement::IDataContainer& data, 
    int value)
{
    std::wstring dataItemName = WXDataItems::Read().GetSliderDimensionMaxValue();

    DataContainerManagement::IDataItemSharedPtr dataItem =
        DataContainerManagement::DataItem::Create(
            dataItemName, 
            value);

    data.SetDataItem(dataItem);
}

/**
 * Updates data from data container.
 * Returns true in case data has been updated.
 */
bool AbstractSlider::UpdateFromDataContainer(DataContainerManagement::IDataContainer& dataContainer)
{
    bool dataUpdated = Window::UpdateFromDataContainer(dataContainer);

    std::wstring dataItemSliderDimensionValue = WXDataItems::Read().GetSliderDimensionValue();

    if (dataContainer.HasDataItem(dataItemSliderDimensionValue)) {
        const DataContainerManagement::IDataItem& dataItem = dataContainer.GetDataItem(dataItemSliderDimensionValue);

        int dimensionValue = dataItem.GetValue()->GetInteger();
        bool propertyUpdated = WXWidgets::WXProperty::UpdateValue(m_dimensionValue, dimensionValue);

        dataUpdated |= propertyUpdated;
    }

    std::wstring dataItemSliderDimensionMinValue = WXDataItems::Read().GetSliderDimensionMinValue();

    if (dataContainer.HasDataItem(dataItemSliderDimensionMinValue)) {
        const DataContainerManagement::IDataItem& dataItem = dataContainer.GetDataItem(dataItemSliderDimensionMinValue);

        int dimensionMinValue = dataItem.GetValue()->GetInteger();
        bool propertyUpdated = WXWidgets::WXProperty::UpdateValue(m_dimensionMinValue, dimensionMinValue);

        dataUpdated |= propertyUpdated;
    }

    std::wstring dataItemSliderDimensionMaxValue = WXDataItems::Read().GetSliderDimensionMaxValue();

    if (dataContainer.HasDataItem(dataItemSliderDimensionMaxValue)) {
        const DataContainerManagement::IDataItem& dataItem = dataContainer.GetDataItem(dataItemSliderDimensionMaxValue);

        int dimensionMaxValue = dataItem.GetValue()->GetInteger();
        bool propertyUpdated = WXWidgets::WXProperty::UpdateValue(m_dimensionMaxValue, dimensionMaxValue);

        dataUpdated |= propertyUpdated;
    }

    return dataUpdated;
}

/**
 * Updates component.
 */
void AbstractSlider::Update()
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
void AbstractSlider::Reset()
{
    SetDimensionValue(m_dimensionValue);
    SetDimensionMinValue(m_dimensionMinValue);
    SetDimensionMaxValue(m_dimensionMaxValue);
}

/**
 * The internal On Slider Updated callback.
 */
void AbstractSlider::InternalOnSliderUpdated(wxScrollEvent& event)
{
    if (!m_onSliderUpdatedFunctor) {
        return;
    }

    int selectedValue = event.GetSelection();
    int compareStatus = m_dimensionValueComparator->CompareTo(m_dimensionValue, selectedValue);
    
    if (compareStatus != 0) {
        m_onSliderUpdatedFunctor->operator()(selectedValue);
    }
}

/**
 * Validates precision.
 */
void AbstractSlider::ValidatePrecision(double precision) 
{
    if (precision < 0 || precision > 100) {
        long errorCode = base::ErrorCodes::INVALID_ARG;

        std::wstringstream messageStream;
        messageStream 
            << L"The Slider precision: " << precision << L" has to be at the following range: [0-100]"
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = messageStream.str();
        LOG_ERROR(GetSLogger(), errorMessage);
    }
}
