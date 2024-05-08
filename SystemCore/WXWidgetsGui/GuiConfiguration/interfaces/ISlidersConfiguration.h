#ifndef I_SLIDERS_CONFIGURATION_1db2a7c0_c51f_46ec_a305_8fd6e7138078
#define I_SLIDERS_CONFIGURATION_1db2a7c0_c51f_46ec_a305_8fd6e7138078

#include "IGuiComponentsConfiguration.h"
#include "ISliderConfiguration.h"

namespace GuiConfiguration {

    /**
     * The ISlidersConfiguration class defines an interface of configuration of sliders.
     */
    class ISlidersConfiguration : public IGuiComponentsConfiguration<ISliderConfiguration> {
    public:
        ISlidersConfiguration() = default;
        virtual ~ISlidersConfiguration() = default;
    };

    //
    // Defines the Shared Ptr of Sliders Configuration.
    //
    using ISlidersConfigurationSharedPtr = std::shared_ptr<ISlidersConfiguration>;

}  // namespace GuiConfiguration

#endif // I_SLIDERS_CONFIGURATION_1db2a7c0_c51f_46ec_a305_8fd6e7138078
