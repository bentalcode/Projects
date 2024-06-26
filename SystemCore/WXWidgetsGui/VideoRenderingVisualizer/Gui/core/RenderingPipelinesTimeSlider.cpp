#include "RenderingPipelinesTimeSlider.h"
#include "IGuiManager.h"
#include "IGuiConfigurationManager.h"
#include "IDataCatalog.h"
#include "GuiDataItems.h"
#include "GuiPaths.h"
#include "DataItem.h"
#include "RefreshingTransaction.h"
#include "SmartPointers.h"
#include "WXProperty.h"

using namespace VideoRenderingVisualizer;
using namespace VideoRenderingVisualizer::Gui;

namespace RenderingPipelinesTimeSliderFunctors {

/**
 * The UpdateDataContainerStartIntervalTimeFunctor class implements an update functor of start interval time.
 */
class UpdateDataContainerStartIntervalTimeFunctor final {
public:
    /**
     * The functor constructor.
     */
    UpdateDataContainerStartIntervalTimeFunctor(DataContainerManagement::IDataContainer& dataContainer) : 
        m_dataContainer(dataContainer)
    {
    }

    /**
     * The functor logic.
     */
    void operator()(const base::DateTime& time)
    {
        RenderingPipelinesTimeSlider::UpdateDataContainerStartIntervalTime(m_dataContainer, time);
    }

private:
    DataContainerManagement::IDataContainer& m_dataContainer;
};

/**
 * The UpdateDataContainerEndIntervalTimeFunctor class implements an update functor of end interval time.
 */
class UpdateDataContainerEndIntervalTimeFunctor final {
public:
    /**
     * The functor constructor.
     */
    UpdateDataContainerEndIntervalTimeFunctor(DataContainerManagement::IDataContainer& dataContainer) : 
        m_dataContainer(dataContainer)
    {
    }

    /**
     * The functor logic.
     */
    void operator()(const base::DateTime& time)
    {
        RenderingPipelinesTimeSlider::UpdateDataContainerEndIntervalTime(m_dataContainer, time);
    }

private:
    DataContainerManagement::IDataContainer& m_dataContainer;
};

} // namespace RenderingPipelinesTimeSliderFunctors

/**
 * Creates a HTML window.
 */
wxwidgets::ISliderPtr RenderingPipelinesTimeSlider::Make(
    wxWindow& parent, 
    const base::DateTimeIntervalSharedPtr intervalTime,
    IGuiManager& guiManager)
{
    return wxwidgets::ISliderPtr::Make(
        new RenderingPipelinesTimeSlider(
            parent, 
            intervalTime, 
            guiManager));
}

/**
 * The RenderingPipelinesTimeSlider constructor.
 */
RenderingPipelinesTimeSlider::RenderingPipelinesTimeSlider(
    wxWindow& parent, 
    const base::DateTimeIntervalSharedPtr intervalTime,
    IGuiManager& guiManager) : 
        wxwidgets::Slider(
            parent, 
            GuiPaths::Read().GetMainFrameMainRightTopWindowLowerSubWindowSlider()), 
    m_guiManager(guiManager),
    m_minNumberOfUnits(0), 
    m_maxNumberOfUnits(0)
{
    //
    // Initialize a GUI component...
    //
    Initialize(
        intervalTime, 
        guiManager);
}

/**
 * The RenderingPipelinesTimeSlider destructor.
 */
RenderingPipelinesTimeSlider::~RenderingPipelinesTimeSlider() 
{
}

/**
 * Initializes a GUI component.
 */
void RenderingPipelinesTimeSlider::Initialize(
    const base::DateTimeIntervalSharedPtr intervalTime,
    IGuiManager& guiManager)
{
    base::SmartPointers::Validate<base::DateTimeInterval>(intervalTime);

    //
    // Initialize the interval time...
    //
    m_intervalTime = intervalTime;

    //
    // Initialize the min/max number of units...
    //
    GuiConfiguration::ISliderConfigurationSharedPtr sliderConfiguration =
        m_guiManager.GetConfigurationManager().GetSlidersConfiguration()->GetConfiguration(
            GuiPaths::Read().GetMainFrameMainRightTopWindowLowerSubWindowSlider());

    m_minNumberOfUnits = sliderConfiguration->GetMinNumberOfUnits();
    m_maxNumberOfUnits = sliderConfiguration->GetMaxNumberOfUnits();

    //
    // Initialize Slider...
    //
    Slider::Initialize(guiManager.GetGuiController());
    Reset(); 

    //
    // Register data update functors...
    //
    std::wstring dataItemStartIntervalTime = GuiDataItems::Read().GetRenderingPipelinesStartIntervalTime();
    std::wstring dataItemEndIntervalTime = GuiDataItems::Read().GetRenderingPipelinesEndIntervalTime();

    DataContainerManagement::IDataContainer& dataContainer = GetData();
    dataContainer.GetCatalog().RegisterDataItem(dataItemStartIntervalTime);
    dataContainer.GetCatalog().RegisterDataItem(dataItemEndIntervalTime);

    DataContainerManagement::IDataContainerUpdateFunctors::IDateTimeFunctorSharedPtr startIntervalTimeFunctor =
        std::make_shared<DataContainerManagement::IDataContainerUpdateFunctors::IDateTimeFunctor>(
            RenderingPipelinesTimeSliderFunctors::UpdateDataContainerStartIntervalTimeFunctor{ dataContainer });

    GetDataUpdateFunctors().RegisterUpdateFunctor(
        dataItemStartIntervalTime,
        startIntervalTimeFunctor);

    DataContainerManagement::IDataContainerUpdateFunctors::IDateTimeFunctorSharedPtr endIntervalTimeFunctor =
        std::make_shared<DataContainerManagement::IDataContainerUpdateFunctors::IDateTimeFunctor>(
            RenderingPipelinesTimeSliderFunctors::UpdateDataContainerEndIntervalTimeFunctor{ dataContainer });

    GetDataUpdateFunctors().RegisterUpdateFunctor(
        dataItemEndIntervalTime,
        endIntervalTimeFunctor);
}

/**
 * Updates data container (start interval time).
 */
void RenderingPipelinesTimeSlider::UpdateDataContainerStartIntervalTime(
    DataContainerManagement::IDataContainer& data,
    const base::DateTime& time)
{
    std::wstring dataItemName = GuiDataItems::Read().GetRenderingPipelinesStartIntervalTime();

    DataContainerManagement::IDataItemSharedPtr dataItem = DataContainerManagement::DataItem::Create(
        dataItemName, 
        time);

    data.SetDataItem(dataItem);
}

/**
 * Updates data container (end interval time).
 */
void RenderingPipelinesTimeSlider::UpdateDataContainerEndIntervalTime(
    DataContainerManagement::IDataContainer& data,
    const base::DateTime& time)
{
    std::wstring dataItemName = GuiDataItems::Read().GetRenderingPipelinesEndIntervalTime();

    DataContainerManagement::IDataItemSharedPtr dataItem = DataContainerManagement::DataItem::Create(
        dataItemName, 
        time);

    data.SetDataItem(dataItem);
}

/**
 * Updates data from data container.
 * Returns true in case data has been updated.
 */
bool RenderingPipelinesTimeSlider::UpdateFromDataContainer(DataContainerManagement::IDataContainer& dataContainer)
{
    bool dataUpdated = wxwidgets::Slider::UpdateFromDataContainer(dataContainer);

    std::wstring dataItemStartIntervalTime = GuiDataItems::Read().GetRenderingPipelinesStartIntervalTime();

    if (dataContainer.HasDataItem(dataItemStartIntervalTime)) {
        const DataContainerManagement::IDataItem& dataItem = dataContainer.GetDataItem(dataItemStartIntervalTime);
        const base::DateTime& startIntervalTime = dataItem.GetValue()->GetDateTime();
        base::DateTimeSharedPtr startTime = m_intervalTime->GetStartTime();

        bool propertyUpdated = wxwidgets::WXProperty::UpdateSharedValuePtr(
            startTime,
            startIntervalTime);

        dataUpdated |= propertyUpdated;
    }

    std::wstring dataItemEndIntervalTime = GuiDataItems::Read().GetRenderingPipelinesEndIntervalTime();

    if (dataContainer.HasDataItem(dataItemEndIntervalTime)) {
        const DataContainerManagement::IDataItem& dataItem = dataContainer.GetDataItem(dataItemEndIntervalTime);
        const base::DateTime& endIntervalTime = dataItem.GetValue()->GetDateTime();
        base::DateTimeSharedPtr endTime = m_intervalTime->GetEndTime();

        bool propertyUpdated = wxwidgets::WXProperty::UpdateSharedValuePtr<base::DateTime>(
            endTime,
            endIntervalTime);

        dataUpdated |= propertyUpdated;
    }

    return dataUpdated;
}

/**
 * Resets component.
 */
void RenderingPipelinesTimeSlider::Reset() 
{
    //
    // Calculate slider dimensions...
    //
    int dimensionMinValue = 0;
    int dimensionMaxValue = 0;
    int dimensionValue = 0;

    CalculateSliderDimensions(
        dimensionMinValue, 
        dimensionMaxValue, 
        dimensionValue);

    SetDimensionMinValue(dimensionMinValue);
    SetDimensionMaxValue(dimensionMaxValue);
    SetDimensionValue(dimensionValue);
}

/**
 * The On Slider Updated callback.
 */
void RenderingPipelinesTimeSlider::OnSliderUpdated(int value) 
{
    //
    // Update the slider...
    //
    Slider::OnSliderUpdated(value);

    //
    // Calculate the selected time...
    //
    base::DateTimeSharedPtr selectedTime = CalculateDimensionTime(value);

    //
    // Refresh the rendering pipelines in the list view...
    //
    wxwidgets::controller::IControllerManagerSharedPtr controllerManager = m_guiManager.GetControllerManager();
    wxwidgets::controller::IRefreshingTransactionSharedPtr transaction = wxwidgets::controller::RefreshingTransaction::Make(*controllerManager);

    std::wstring renderingPipelinesListView = 
        GuiPaths::Read().GetMainFrameMainRightBottomWindowListView();

    std::wstring dataItemStartIntervalTime = GuiDataItems::Read().GetRenderingPipelinesStartIntervalTime();
    std::wstring dataItemEndIntervalTime = GuiDataItems::Read().GetRenderingPipelinesEndIntervalTime();

    transaction->UpdateData(
        renderingPipelinesListView, 
        dataItemStartIntervalTime, 
        *m_intervalTime->GetStartTime());

    transaction->UpdateData(
        renderingPipelinesListView, 
        dataItemEndIntervalTime, 
        *selectedTime);

    //
    // Commit a refreshing transaction...
    //
    transaction->Commit();
}

/**
 * Calculates the dimensions of slider.
 */
void RenderingPipelinesTimeSlider::CalculateSliderDimensions(
    int& startIntervalDimensionValue,
    int& endIntervalDimensionValue,
    int& dimensionValue) const
{
    CalculateSliderDimensions(
        m_minNumberOfUnits, 
        m_maxNumberOfUnits, 
        startIntervalDimensionValue,
        endIntervalDimensionValue, 
        dimensionValue);
}

/**
 * Calculates the dimensions of slider.
 */
void RenderingPipelinesTimeSlider::CalculateSliderDimensions(
    unsigned int minNumberOfUnits,
    unsigned int maxNumberOfUnits,
    int& startIntervalDimensionValue,
    int& endIntervalDimensionValue, 
    int& dimensionValue)
{
    startIntervalDimensionValue = 0;
    endIntervalDimensionValue = minNumberOfUnits;
    dimensionValue = endIntervalDimensionValue;
}

/**
 * Calculates the time of dimension.
 */
base::DateTimeSharedPtr RenderingPipelinesTimeSlider::CalculateDimensionTime(int dimensionValue) const
{ 
    int startDimensionValue = GetDimensionMinValue();
    int endDimensionValue = GetDimensionMaxValue();

    return CalculateDimensionTime(
        *m_intervalTime, 
        startDimensionValue, 
        endDimensionValue, 
        dimensionValue);
}

/**
 * Calculates the time of dimension.
 */
base::DateTimeSharedPtr RenderingPipelinesTimeSlider::CalculateDimensionTime(
    const base::DateTimeInterval& intervalTime,
    int startDimensionValue,
    int endDimensionValue,
    int dimensionValue) 
{
    int sliderLengthInUnits = endDimensionValue - startDimensionValue;
    int intervalLengthInUnits = dimensionValue - startDimensionValue;
    double intervalFactor = static_cast<double>(intervalLengthInUnits) / static_cast<double>(sliderLengthInUnits);

    base::DurationSharedPtr sliderDuration = intervalTime.GetDuration();
    double sliderDurationInMilliseconds = sliderDuration->ToMilliseconds();
    double intervalDurationInMilliseconds = sliderDurationInMilliseconds * intervalFactor;

    base::DateTimeSharedPtr startTime = intervalTime.GetStartTime();
    base::DurationSharedPtr intervalDuration = base::Duration::FromMilliseconds(intervalDurationInMilliseconds);

    base::DateTimeSharedPtr dimensionTime = *startTime + *intervalDuration;
    
    return dimensionTime;
}
