#ifndef I_HTML_WINDOW_3b56e748_86b0_4967_9579_fe1ebdb4cd65
#define I_HTML_WINDOW_3b56e748_86b0_4967_9579_fe1ebdb4cd65

#include "IGuiController.h"
#include "WXObjectPtr.h"

namespace WXWidgets {

    class IWindow;

    /**
     * The IHtmlWindow interface defines a HTML Window.
     */
    class IHtmlWindow {
    public:
        IHtmlWindow() = default;
        virtual ~IHtmlWindow() = default;

        /**
         * Initializes a GUI component.
         */
        virtual void Initialize(IGuiControllerSharedPtr guiController) = 0;

        /**
         * Gets a window.
         */
        virtual IWindow& GetWindow() = 0;

        /**
         * Loads file.
         */
        virtual void LoadFile(const std::wstring& path) = 0;
    };

    //
    // Defines the WX Object Ptr of HTML Window.
    //
    using IHtmlWindowPtr = WXObjectPtr<IHtmlWindow>;

}  // namespace WXWidgets

#endif // I_HTML_WINDOW_3b56e748_86b0_4967_9579_fe1ebdb4cd65
