#ifndef FRAMES_CONFIGURATION_e1e80e33_bc62_49e4_9e85_a62c1422f6c5
#define FRAMES_CONFIGURATION_e1e80e33_bc62_49e4_9e85_a62c1422f6c5

#include "IFramesConfiguration.h"
#include "IGuiComponentsConfiguration.h"

namespace GuiConfiguration {

    /**
     * The FramesConfiguration class implements configuration of frames.
     */
    class FramesConfiguration final : public IFramesConfiguration {
    public:
        /**
         * Creates frames configuration.
         */
        static IFramesConfigurationSharedPtr Make();

        /**
         * The FramesConfiguration constructor.
         */
        FramesConfiguration();

        /**
         * The FramesConfiguration destructor.
         */
        virtual ~FramesConfiguration();

        /**
         * Adds a configuration of a component by path.
         */
        virtual void AddConfiguration(
            const std::wstring& path,
            IFrameConfigurationSharedPtr configuration) override;

        /**
         * Gets a configuration of a component by path.
         */
        virtual const IFrameConfigurationSharedPtr GetConfiguration(const std::wstring& path) const override;

        /**
         * Checks whether a configuration of a component exists.
         */
        virtual bool ConfigurationExists(const std::wstring& path) const override;

    private:
        IGuiComponentsConfigurationSharedPtr<IFrameConfiguration> m_impl;
    };

}  // namespace GuiConfiguration

#endif // FRAMES_CONFIGURATION_e1e80e33_bc62_49e4_9e85_a62c1422f6c5
