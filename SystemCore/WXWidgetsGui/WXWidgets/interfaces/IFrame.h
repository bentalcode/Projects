#ifndef I_FRAME_e927ad3c_7035_44f0_927b_4d668cd10c63
#define I_FRAME_e927ad3c_7035_44f0_927b_4d668cd10c63

#include "IGuiController.h"
#include "WXObjectPtr.h"

class wxMenuBar;
class wxString;

namespace WXWidgets {

    class IWindow;

    /**
     * The IFrame interface defines a frame.
     */
    class IFrame {
    public:
        IFrame() = default;
        virtual ~IFrame() = default;

        /**
         * Initializes a GUI component.
         */
        virtual void Initialize(IGuiControllerSharedPtr guiController) = 0;

        /**
         * Gets a window.
         */
        virtual IWindow& GetWindow() = 0;

        /**
         * Sets menu bar.
         */
        virtual void SetMenuBar(wxMenuBar& menuBar) = 0;

        /**
         * Sets status text.
         */
        virtual void SetStatusText(const wxString& text) = 0;

        /**
         * Maximizes frame.
         */
        virtual void Maximize() = 0;

        /**
         * Maximizes and centeralizes frame.
         */
        virtual void MaximizeAndCenteralize() = 0;
    };

    //
    // Defines the WX Object Ptr of Frame.
    //
    using IFramePtr = WXObjectPtr<IFrame>;

}  // namespace WXWidgets

#endif // I_FRAME_e927ad3c_7035_44f0_927b_4d668cd10c63
