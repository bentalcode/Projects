#ifndef MENUS_ITEMS_CONFIGURATION_92645ce1_8cc2_4b95_90f7_5039d544e56a
#define MENUS_ITEMS_CONFIGURATION_92645ce1_8cc2_4b95_90f7_5039d544e56a

#include "IMenusConfiguration.h"
#include "ILogger.h"
#include <map>

namespace GuiConfiguration {

    /**
     * The MenusConfiguration class implements configuration of menus.
     */
    class MenusConfiguration final : public IMenusConfiguration {
    public:
        /**
         * Creates menus configuration.
         */
        static IMenusConfigurationSharedPtr Make();

        /**
         * The MenusConfiguration constructor.
         */
        MenusConfiguration();

        /**
         * The MenusConfiguration destructor.
         */
        virtual ~MenusConfiguration();

        /**
         * Adds a menu configuration by path.
         */
        virtual void AddMenuConfiguration(
            const std::wstring& path,
            IMenuConfigurationSharedPtr configuration) override;

        /**
         * Gets a menu configuration by path.
         */
        virtual const IMenuConfigurationSharedPtr GetMenuConfiguration(const std::wstring& path) const override;

        /**
         * Checks whether a menu configuration exists.
         */
        virtual bool MenuConfigurationExists(const std::wstring& path) const override;

    private:
        /**
         * Finds a menu configuration by path.
         */
        const IMenuConfigurationSharedPtr FindMenuConfiguration(const std::wstring& path) const;

        /**
         * Gets a static logger.
         */
        static logging::ILoggerSharedPtr GetSLogger();

        using MenuConfigurationMap = std::map<std::wstring, IMenuConfigurationSharedPtr>;
        MenuConfigurationMap m_menuConfigurationMap;
    };

}  // namespace GuiConfiguration

#endif // MENUS_ITEMS_CONFIGURATION_92645ce1_8cc2_4b95_90f7_5039d544e56a
