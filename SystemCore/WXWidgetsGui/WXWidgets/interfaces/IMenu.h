#ifndef I_MENU_674b73be_8056_419f_a20f_937d2655be22
#define I_MENU_674b73be_8056_419f_a20f_937d2655be22

#include "IGuiController.h"
#include "WXObjectPtr.h"
#include "wx/defs.h"

class wxMenu;
class wxMenuItem;
class wxString;

namespace WXWidgets {

    /**
     * The IMenu interface defines a menu.
     */
    class IMenu {
    public:
        IMenu() = default;
        virtual ~IMenu() = default;

        /**
         * Initializes a GUI component.
         */
        virtual void Initialize(IGuiControllerSharedPtr guiController) = 0;

        /**
         * Gets a menu.
         */
        virtual wxMenu* GetMenu() = 0;

        /**
         * Appends an item.
         */
        virtual wxMenuItem* Append(
            int itemid,
            const wxString& text,
            const wxString& help,
            wxItemKind kind) = 0;

        /**
         * Appends a separator.
         */
        virtual wxMenuItem* AppendSeparator() = 0;
    };

    //
    // Defines the WX Object Ptr of Menu.
    //
    using IMenuPtr = WXObjectPtr<IMenu>;

}  // namespace WXWidgets

#endif // I_MENU_674b73be_8056_419f_a20f_937d2655be22
