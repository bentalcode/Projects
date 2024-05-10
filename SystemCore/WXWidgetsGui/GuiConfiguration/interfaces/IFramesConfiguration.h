#ifndef I_FRAMES_CONFIGURATION_aa5d84c7_89ca_4614_8142_893125ca48ff
#define I_FRAMES_CONFIGURATION_aa5d84c7_89ca_4614_8142_893125ca48ff

#include "IGuiComponentsConfiguration.h"
#include "IFrameConfiguration.h"

namespace GuiConfiguration {

    /**
     * The IFramesConfiguration class defines an interface of configuration of frames.
     */
    class IFramesConfiguration : public IGuiComponentsConfiguration<IFrameConfiguration> {
    public:
        IFramesConfiguration() = default;
        virtual ~IFramesConfiguration() = default;
    };

    //
    // Defines the Shared Ptr of Frames Configuration.
    //
    using IFramesConfigurationSharedPtr = std::shared_ptr<IFramesConfiguration>;

} // namespace GuiConfiguration

#endif // I_FRAMES_CONFIGURATION_aa5d84c7_89ca_4614_8142_893125ca48ff
