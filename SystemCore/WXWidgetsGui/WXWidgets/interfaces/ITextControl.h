#ifndef I_TEXT_CONTROL_2c50ff34_6e81_4cd9_a914_72733b4135a0
#define I_TEXT_CONTROL_2c50ff34_6e81_4cd9_a914_72733b4135a0

#include "IGuiController.h"
#include "WXObjectPtr.h"

class wxString;

namespace WXWidgets {

    class IWindow;

    /**
     * The ITextControl interface defines a text control.
     */
    class ITextControl {
    public:
        ITextControl() = default;
        virtual ~ITextControl() = default;

        /**
         * Initializes a GUI component.
         */
        virtual void Initialize(IGuiControllerSharedPtr guiController) = 0;

        /**
         * Gets a window.
         */
        virtual IWindow& GetWindow() = 0;

        /**
         * Sets a value.
         */
        virtual void SetValue(const wxString& value) = 0;
    };

    //
    // Defines the WX Object Ptr of Text Control.
    //
    using ITextControlPtr = WXObjectPtr<ITextControl>;

}  // namespace WXWidgets

#endif // I_TEXT_CONTROL_2c50ff34_6e81_4cd9_a914_72733b4135a0
