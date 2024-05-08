#ifndef I_MENU_ITEMS_CONFIGURATION_e0553c48_7f37_4657_ac7f_a977d33cb023
#define I_MENU_ITEMS_CONFIGURATION_e0553c48_7f37_4657_ac7f_a977d33cb023

#include "IGuiComponentsConfiguration.h"
#include "IMenuItemConfiguration.h"

namespace GuiConfiguration {

    /**
     * The IMenuItemsConfiguration class defines an interface of configuration of menu items.
     */
    class IMenuItemsConfiguration : public IGuiComponentsConfiguration<IMenuItemConfiguration> {
    public:
        IMenuItemsConfiguration() = default;
        virtual ~IMenuItemsConfiguration() = default;
    };

    //
    // Defines the Shared Ptr of Menu Items Configuration.
    //
    using IMenuItemsConfigurationSharedPtr = std::shared_ptr<IMenuItemsConfiguration>;

}  // namespace GuiConfiguration

#endif // I_MENU_ITEMS_CONFIGURATION_e0553c48_7f37_4657_ac7f_a977d33cb023
