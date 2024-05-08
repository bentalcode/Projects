#ifndef LABELES_CONFIGURATION_521f58d4_497b_422c_9946_7e084e31a46d
#define LABELES_CONFIGURATION_521f58d4_497b_422c_9946_7e084e31a46d

#include "ILabelsConfiguration.h"
#include "IGuiComponentsConfiguration.h"

namespace GuiConfiguration {

    /**
     * The LabelsConfiguration class implements configuration of labels.
     */
    class LabelsConfiguration final : public ILabelsConfiguration {
    public:
        /**
         * Creates labels configuration.
         */
        static ILabelsConfigurationSharedPtr Make();

        /**
         * The LabelsConfiguration constructor.
         */
        LabelsConfiguration();

        /**
         * The LabelsConfiguration destructor.
         */
        virtual ~LabelsConfiguration();

        /**
         * Adds a configuration of a component by path.
         */
        virtual void AddConfiguration(
            const std::wstring& path,
            ILabelConfigurationSharedPtr configuration) override;

        /**
         * Gets a configuration of a component by path.
         */
        virtual const ILabelConfigurationSharedPtr GetConfiguration(const std::wstring& path) const override;

        /**
         * Checks whether a configuration of a component exists.
         */
        virtual bool ConfigurationExists(const std::wstring& path) const override;

    private:
        IGuiComponentsConfigurationSharedPtr<ILabelConfiguration> m_impl;
    };

}  // namespace GuiConfiguration

#endif // LABELES_CONFIGURATION_521f58d4_497b_422c_9946_7e084e31a46d
