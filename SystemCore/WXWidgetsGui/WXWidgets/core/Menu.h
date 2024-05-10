#ifndef MENU_2402b53c_a098_426d_bc0c_0ae68199d56a
#define MENU_2402b53c_a098_426d_bc0c_0ae68199d56a

#include "IMenu.h"
#include "GuiComponent.h"
#include "wx/menu.h"

namespace WXWidgets {

    /**
     * The Menu class implements a menu.
     */
    class Menu final : public IMenu, public GuiComponent, public wxMenu {
    public:
        /**
         * Creates a menu.
         */
        static IMenuPtr Make(
            const std::wstring& name,
            const std::wstring& title = L"",
            long style = 0);

        /**
         * The Menu constructor.
         */
        Menu(
            const std::wstring& name,
            const std::wstring& title = L"",
            long style = 0);

        /**
         * The Menu destructor.
         */
        virtual ~Menu();

        /**
         * Initializes a GUI component.
         */
        virtual void Initialize(IGuiControllerSharedPtr guiController) override;

        /**
         * Gets a menu.
         */
        virtual wxMenu* GetMenu() override;

        /**
         * Appends an item.
         */
        virtual wxMenuItem* Append(
            int itemid,
            const wxString& text,
            const wxString& help,
            wxItemKind kind) override;

        /**
         * Appends a separator.
         */
        virtual wxMenuItem* AppendSeparator() override;

    private:
        std::wstring m_name;
    };

} // namespace WXWidgets

#endif // MENU_2402b53c_a098_426d_bc0c_0ae68199d56a
