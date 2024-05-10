#ifndef I_SLIDER_CONFIGURATION_4dd1c5e8_9ba4_4b7c_b104_9533d3db9ca3
#define I_SLIDER_CONFIGURATION_4dd1c5e8_9ba4_4b7c_b104_9533d3db9ca3

#include <memory>

namespace GuiConfiguration {

    /**
     * The ISliderConfiguration class defines an interface of configuration of a slider.
     */
    class ISliderConfiguration {
    public:
        ISliderConfiguration() = default;
        virtual ~ISliderConfiguration() = default;

        /**
         * Gets minimum number of units.
         */
        virtual unsigned int GetMinNumberOfUnits() const = 0;

        /**
         * Gets maximum number of units.
         */
        virtual unsigned int GetMaxNumberOfUnits() const = 0;
    };

    //
    // Defines the Shared Ptr of Slider Configuration.
    //
    using ISliderConfigurationSharedPtr = std::shared_ptr<ISliderConfiguration>;

} // namespace GuiConfiguration

#endif // I_SLIDER_CONFIGURATION_4dd1c5e8_9ba4_4b7c_b104_9533d3db9ca3
