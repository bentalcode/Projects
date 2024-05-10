#ifndef I_MENU_BAR_0ed937ff_fcc5_4b57_bd1f_8c55d41b71dc
#define I_MENU_BAR_0ed937ff_fcc5_4b57_bd1f_8c55d41b71dc

#include "IGuiController.h"
#include "WXObjectPtr.h"

class wxMenuBar;
class wxMenu;
class wxString;

namespace WXWidgets {

    /**
     * The IMenuBar interface defines a menu bar.
     */
    class IMenuBar {
    public:
        IMenuBar() = default;
        virtual ~IMenuBar() = default;

        /**
         * Initializes a GUI component.
         */
        virtual void Initialize(IGuiControllerSharedPtr guiController) = 0;

        /**
         * Gets a menu bar.
         */
        virtual wxMenuBar& GetMenuBar() = 0;

        /**
         * Appends a menu.
         */
        virtual void Append(wxMenu& menu, const wxString& title) = 0;
    };

    //
    // Defines the WX Object Ptr of Panel.
    //
    using IMenuBarPtr = WXObjectPtr<IMenuBar>;

} // namespace WXWidgets

#endif // I_MENU_BAR_0ed937ff_fcc5_4b57_bd1f_8c55d41b71dc
