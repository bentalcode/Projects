#ifndef MENU_ITEMS_CONFIGURATION_92645ce1_8cc2_4b95_90f7_5039d544e56a
#define MENU_ITEMS_CONFIGURATION_92645ce1_8cc2_4b95_90f7_5039d544e56a

#include "IMenuItemsConfiguration.h"
#include "IGuiComponentsConfiguration.h"

namespace GuiConfiguration {

    /**
     * The MenuItemsConfiguration class implements configuration of menu items.
     */
    class MenuItemsConfiguration final : public IMenuItemsConfiguration {
    public:
        /**
         * Creates a menu items configuration.
         */
        static IMenuItemsConfigurationSharedPtr Make();

        /**
         * The MenuItemsConfiguration constructor.
         */
        MenuItemsConfiguration();

        /**
         * The MenuItemsConfiguration destructor.
         */
        virtual ~MenuItemsConfiguration();

        /**
         * Adds a configuration of a component by path.
         */
        virtual void AddConfiguration(
            const std::wstring& path,
            IMenuItemConfigurationSharedPtr configuration) override;

        /**
         * Gets a configuration of a component by path.
         */
        virtual const IMenuItemConfigurationSharedPtr GetConfiguration(const std::wstring& path) const override;

        /**
         * Checks whether a configuration of a component exists.
         */
        virtual bool ConfigurationExists(const std::wstring& path) const override;

    private:
        IGuiComponentsConfigurationSharedPtr<IMenuItemConfiguration> m_impl;
    };

}  // namespace GuiConfiguration

#endif // MENU_ITEMS_CONFIGURATION_92645ce1_8cc2_4b95_90f7_5039d544e56a
