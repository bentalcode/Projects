#ifndef SLIDERS_CONFIGURATION_c94a7d66_c33e_4b4a_a5da_1275fdbdd184
#define SLIDERS_CONFIGURATION_c94a7d66_c33e_4b4a_a5da_1275fdbdd184

#include "ISlidersConfiguration.h"
#include "IGuiComponentsConfiguration.h"

namespace GuiConfiguration {

    /**
     * The SlidersConfiguration class implements configuration of sliders.
     */
    class SlidersConfiguration final : public ISlidersConfiguration {
    public:
        /**
         * Creates a sliders configuration.
         */
        static ISlidersConfigurationSharedPtr Make();

        /**
         * The SlidersConfiguration constructor.
         */
        SlidersConfiguration();

        /**
         * The SlidersConfiguration destructor.
         */
        virtual ~SlidersConfiguration();

        /**
         * Adds a configuration of a component by path.
         */
        virtual void AddConfiguration(
            const std::wstring& path,
            ISliderConfigurationSharedPtr configuration) override;

        /**
         * Gets a configuration of a component by path.
         */
        virtual const ISliderConfigurationSharedPtr GetConfiguration(const std::wstring& path) const override;

        /**
         * Checks whether a configuration of a component exists.
         */
        virtual bool ConfigurationExists(const std::wstring& path) const override;

    private:
        IGuiComponentsConfigurationSharedPtr<ISliderConfiguration> m_impl;
    };

} // namespace GuiConfiguration

#endif // SLIDERS_CONFIGURATION_c94a7d66_c33e_4b4a_a5da_1275fdbdd184
