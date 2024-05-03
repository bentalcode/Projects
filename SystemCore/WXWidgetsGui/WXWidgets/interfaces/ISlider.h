#ifndef I_SLIDER_58fbd89e_3482_4b72_9045_d96a254766ec
#define I_SLIDER_58fbd89e_3482_4b72_9045_d96a254766ec

#include "IGuiController.h"
#include "WXObjectPtr.h"

namespace WXWidgets {

    class IWindow;

    /**
     * The ISlider interface defines a slider.
     */
    class ISlider {
    public:
        ISlider() = default;
        virtual ~ISlider() = default;

        /**
         * Initializes a GUI component.
         */
        virtual void Initialize(
            IGuiControllerSharedPtr guiController) = 0;

        /**
         * Gets a window.
         */
        virtual IWindow& GetWindow() = 0;

        /**
         * Sets scroll precision.
         */
        virtual void SetScrollPrecision(double precision) = 0;

        /**
         * Gets value of a dimension.
         */
        virtual int GetDimensionValue() const = 0;

        /**
         * Sets value of a dimension.
         */
        virtual void SetDimensionValue(int value) = 0;

        /**
         * Gets min value of a dimension.
         */
        virtual int GetDimensionMinValue() const = 0;

        /**
         * Sets min value of a dimension.
         */
        virtual void SetDimensionMinValue(int value) = 0;

        /**
         * Gets max value of a dimension.
         */
        virtual int GetDimensionMaxValue() const = 0;

        /**
         * Sets max value of a dimension.
         */
        virtual void SetDimensionMaxValue(int value) = 0;

        /**
         * The On Slider Updated callback.
         */
        virtual void OnSliderUpdated(int value) = 0;
    };

    //
    // Defines the WX Object Ptr of Slider.
    //
    using ISliderPtr = WXObjectPtr<ISlider>;

}  // namespace WXWidgets

#endif // I_SLIDER_58fbd89e_3482_4b72_9045_d96a254766ec

