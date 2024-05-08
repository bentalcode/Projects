#ifndef I_MENU_ITEM_CONFIGURATION_976e3dfb_3595_4a65_b40b_4e2681ea5f5b
#define I_MENU_ITEM_CONFIGURATION_976e3dfb_3595_4a65_b40b_4e2681ea5f5b

#include "wx/defs.h"
#include <string>
#include <memory>

namespace GuiConfiguration {

    /**
     * The IMenuItemConfiguration class defines an interface of configuration of a menu item.
     */
    class IMenuItemConfiguration {
    public:
        IMenuItemConfiguration() = default;
        virtual ~IMenuItemConfiguration() = default;

        /**
         * Gets an item id.
         */
        virtual int GetItemId() const = 0;

        /**
         * Gets text.
         */
        virtual const std::wstring& GetText() const = 0;

        /**
         * Gets help.
         */
        virtual const std::wstring& GetHelp() const = 0;

        /**
         * Gets kind.
         */
        virtual wxItemKind GetKind() const = 0;
    };

    //
    // Defines the Shared Ptr of Menu Item Configuration.
    //
    using IMenuItemConfigurationSharedPtr = std::shared_ptr<IMenuItemConfiguration>;

}  // namespace GuiConfiguration

#endif // I_MENU_ITEM_CONFIGURATION_976e3dfb_3595_4a65_b40b_4e2681ea5f5b

