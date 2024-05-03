#ifndef PANEL_919366a8_6dae_4388_8479_9eac23bdf7df
#define PANEL_919366a8_6dae_4388_8479_9eac23bdf7df

#include "IPanel.h"
#include "Window.h"
#include "WXObjectId.h"
#include "wx/panel.h"

namespace WXWidgets {

    /**
     * The Panel class implements a panel.
     */
    class Panel final : public IPanel, public Window, public wxPanel {
    public:
        /**
         * Creates a panel.
         */
        static WXObjectPtr<IPanel> Make(
            wxWindow& parent,
            const wxString& name,
            wxWindowID id = WXObjectId::NextId(),
            const wxPoint& position = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxTE_READONLY);

        /**
         * The Panel constructor.
         */
        Panel(
            wxWindow& parent,
            const wxString& name,
            wxWindowID id,
            const wxPoint& position,
            const wxSize& size,
            long style);

        /**
         * The Panel destructor.
         */
        virtual ~Panel();

        /**
         * Initializes a GUI component.
         */
        virtual void Initialize(IGuiControllerSharedPtr guiController) override;

        /**
         * Sets a sizer.
         */
        virtual void SetSizer(wxSizer& sizer) override;
    };

}  // namespace WXWidgets

#endif // PANEL_919366a8_6dae_4388_8479_9eac23bdf7df
