#ifndef I_SPLITTER_WINDOW_cdec9d79_9f08_47a1_a8ce_c5aa4b43b59f
#define I_SPLITTER_WINDOW_cdec9d79_9f08_47a1_a8ce_c5aa4b43b59f

#include "IGuiController.h"
#include "ISplitterWindowConfiguration.h"
#include "WXObjectPtrs.h"

class wxWindow;

namespace WXWidgets {

    class IWindow;

    /**
     * The ISplitterWindow interface defines a splitter window.
     */
    class ISplitterWindow {
    public:
        ISplitterWindow() = default;
        virtual ~ISplitterWindow() = default;

        /**
         * Initializes a GUI component.
         */
        virtual void Initialize(IGuiControllerSharedPtr guiController) = 0;

        /**
         * Gets a window.
         */
        virtual IWindow& GetWindow() = 0;

        /**
         * Splits a window vertically.
         */
        virtual std::pair<wxWindow*, wxWindow*> SplitVertically(
            const ISplitterWindowConfigurationSharedPtr configuration) = 0;

        /**
         * Splits a window horizontally.
         */
        virtual std::pair<wxWindow*, wxWindow*> SplitHorizontally(
            const ISplitterWindowConfigurationSharedPtr configuration) = 0;

        /**
         * Connects windows (left/right or upper/bottom).
         */
        virtual void ConnectWindows(
            wxWindow& firstWindow,
            wxWindow& secondWindow) = 0;
    };

    //
    // Defines the WX Object Ptr of Splitter Window.
    //
    using ISplitterWindowPtr = WXObjectPtr<ISplitterWindow>;

}  // namespace WXWidgets

#endif // I_SPLITTER_WINDOW_cdec9d79_9f08_47a1_a8ce_c5aa4b43b59f
