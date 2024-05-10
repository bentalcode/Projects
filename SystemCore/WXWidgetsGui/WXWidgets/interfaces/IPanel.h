#ifndef I_PANEL_9954a8c6_1707_44b4_b6a2_3993055f0fff
#define I_PANEL_9954a8c6_1707_44b4_b6a2_3993055f0fff

#include "IGuiController.h"
#include "WXObjectPtr.h"

class wxSizer;

namespace WXWidgets {

    /**
     * The IPanel interface defines a panel.
     */
    class IPanel {
    public:
        IPanel() = default;
        virtual ~IPanel() = default;

        /**
         * Initializes a GUI component.
         */
        virtual void Initialize(IGuiControllerSharedPtr guiController) = 0;

        /**
         * Sets a sizer.
         */
        virtual void SetSizer(wxSizer& sizer) = 0;
    };

    //
    // Defines the WX Object Ptr of Panel.
    //
    using IPanelPtr = WXObjectPtr<IPanel>;

} // namespace WXWidgets

#endif // I_PANEL_9954a8c6_1707_44b4_b6a2_3993055f0fff
