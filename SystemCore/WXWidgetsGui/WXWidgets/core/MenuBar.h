#ifndef MENU_BAR_62910582_4fa8_45a6_910d_0747934feb74
#define MENU_BAR_62910582_4fa8_45a6_910d_0747934feb74

#include "IMenuBar.h"
#include "GuiComponent.h"
#include "WXObjectPtr.h"
#include "wx/menu.h"

namespace wxwidgets {

    /**
     * The MenuBar class implements a menu bar.
     */
    class MenuBar final : public IMenuBar, public GuiComponent, public wxMenuBar {
    public:
        /**
         * Creates a menu bar.
         */
        static WXObjectPtr<IMenuBar> Make(
            const std::wstring& name,
            long style = 0);

        /**
         * The MenuBar constructor.
         */
        explicit MenuBar(
            const std::wstring& name,
            long style = 0);

        /**
         * The MenuBar destructor.
         */
        virtual ~MenuBar();

        /**
         * Gets a menu bar.
         */
        virtual wxMenuBar& GetMenuBar() override;

        /**
         * Appends a menu.
         */
        virtual void Append(
            wxMenu& menu,
            const wxString& title) override;

    private:
        /**
         * Initializes a GUI component.
         */
        void Initialize(IGuiControllerSharedPtr guiController);

        std::wstring m_name;
    };

} // namespace wxwidgets

#endif // MENU_BAR_62910582_4fa8_45a6_910d_0747934feb74
