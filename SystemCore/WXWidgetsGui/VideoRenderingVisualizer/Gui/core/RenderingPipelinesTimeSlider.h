#pragma once

#include "Slider.h"
#include "DateTimeInterval.h"

namespace VideoRenderingVisualizer {

namespace Gui {

class IGuiManager;

/**
 * The RenderingPipelinesTimeSlider class implements a time slider of rendering pipelines.
 */
class RenderingPipelinesTimeSlider final : public WXWidgets::Slider {
public:
    /**
     * Creates a slider.
     */
    static WXWidgets::ISliderPtr Make(
        wxWindow& parent, 
        const Utilities::DateTimeIntervalSharedPtr intervalTime,
        IGuiManager& guiManager);

    /**
     * The RenderingPipelinesTimeSlider constructor.
     */
    RenderingPipelinesTimeSlider(
        wxWindow& parent, 
        const Utilities::DateTimeIntervalSharedPtr intervalTime,
        IGuiManager& guiManager);

    /**
     * The RenderingPipelinesTimeSlider destructor.
     */
    virtual ~RenderingPipelinesTimeSlider();

    /**
     * The On Slider Updated callback.
     */
    virtual void OnSliderUpdated(int value) override;

    /**
     * Updates data container (start interval time).
     */
    static void UpdateDataContainerStartIntervalTime(
        DataContainerManagement::IDataContainer& data,
        const Utilities::DateTime& time);

    /**
     * Updates data container (end interval time).
     */
    static void UpdateDataContainerEndIntervalTime(
        DataContainerManagement::IDataContainer& data,
        const Utilities::DateTime& time);

protected:
    /**
     * Updates data from data container.
     * Returns true in case data has been updated.
     */
    virtual bool UpdateFromDataContainer(DataContainerManagement::IDataContainer& dataContainer) override;

private:
    /**
     * Resets component.
     */
    void Reset();

    /**
     * Initializes a GUI component.
     */
    void Initialize(
        const Utilities::DateTimeIntervalSharedPtr intervalTime,
        IGuiManager& guiManager);

    /**
     * Calculates the dimensions of slider.
     */
    void CalculateSliderDimensions(
        int& startIntervalDimensionValue, 
        int& endIntervalDimensionValue,
        int& dimensionValue) const;

    /**
     * Calculates the time of dimension.
     */
    Utilities::DateTimeSharedPtr CalculateDimensionTime(int dimensionValue) const;

    /**
     * Calculates the dimensions of slider.
     */
    static void CalculateSliderDimensions(
        unsigned int minNumberOfUnits, 
        unsigned int maxNumberOfUnits,
        int& startIntervalDimensionValue, 
        int& endIntervalDimensionValue,
        int& dimensionValue);

    /**
     * Calculates the time of dimension.
     */
    static Utilities::DateTimeSharedPtr CalculateDimensionTime(
        const Utilities::DateTimeInterval& intervalTime,
        int startDimensionValue, 
        int endDimensionValue,
        int dimensionValue);

    //
    // The GUI Manager...
    //
    IGuiManager& m_guiManager;
    
    //
    // The interval time of rendering pipelines...
    //
    Utilities::DateTimeIntervalSharedPtr m_intervalTime;
    unsigned int m_minNumberOfUnits;
    unsigned int m_maxNumberOfUnits;
};

}  // namespace Gui

}  // namespace VideoRenderingVisualizer
