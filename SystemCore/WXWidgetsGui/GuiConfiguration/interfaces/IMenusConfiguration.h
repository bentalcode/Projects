#ifndef I_MENUS_CONFIGURATION_100ffa25_3b59_4f64_a5e4_647023edf334
#define I_MENUS_CONFIGURATION_100ffa25_3b59_4f64_a5e4_647023edf334

#include "MenuConfiguration.h"

namespace GuiConfiguration {

    /**
     * The IMenusConfiguration class defines an interface of configuration of menus.
     */
    class IMenusConfiguration {
    public:
        IMenusConfiguration() = default;
        virtual ~IMenusConfiguration() = default;

        /**
         * Adds a menu configuration by path.
         */
        virtual void AddMenuConfiguration(
            const std::wstring& path,
            IMenuConfigurationSharedPtr configuration) = 0;

        /**
         * Gets a menu configuration by path.
         */
        virtual const IMenuConfigurationSharedPtr GetMenuConfiguration(const std::wstring& path) const = 0;

        /**
         * Checks whether a menu configuration exists.
         */
        virtual bool MenuConfigurationExists(const std::wstring& path) const = 0;
    };

    //
    // Defines the Shared Ptr of Menus Configuration.
    //
    using IMenusConfigurationSharedPtr = std::shared_ptr<IMenusConfiguration>;

} // namespace GuiConfiguration

#endif // I_MENUS_CONFIGURATION_100ffa25_3b59_4f64_a5e4_647023edf334
