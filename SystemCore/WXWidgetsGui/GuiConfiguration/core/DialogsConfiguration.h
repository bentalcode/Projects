#ifndef DIALOGS_CONFIGURATION_a2351deb_505f_4df6_a455_2b7276f34167
#define DIALOGS_CONFIGURATION_a2351deb_505f_4df6_a455_2b7276f34167

#include "IDialogsConfiguration.h"
#include "IGuiComponentsConfiguration.h"

namespace GuiConfiguration {

    /**
     * The DialogsConfiguration class implements configuration of dialogs.
     */
    class DialogsConfiguration final : public IDialogsConfiguration {
    public:
        /**
         * Creates dialogs configuration.
         */
        static IDialogsConfigurationSharedPtr Make();

        /**
         * The DialogsConfiguration constructor.
         */
        DialogsConfiguration();

        /**
         * The DialogsConfiguration destructor.
         */
        virtual ~DialogsConfiguration();

        /**
         * Adds a configuration of a component by path.
         */
        virtual void AddConfiguration(
            const std::wstring& path,
            IDialogConfigurationSharedPtr configuration) override;

        /**
         * Gets a configuration of a component by path.
         */
        virtual const IDialogConfigurationSharedPtr GetConfiguration(const std::wstring& path) const override;

        /**
         * Checks whether a configuration of a component exists.
         */
        virtual bool ConfigurationExists(const std::wstring& path) const override;

    private:
        IGuiComponentsConfigurationSharedPtr<IDialogConfiguration> m_impl;
    };

}  // namespace GuiConfiguration

#endif // DIALOGS_CONFIGURATION_a2351deb_505f_4df6_a455_2b7276f34167
