#ifndef I_STATIC_TEXT_3476f4ac_72d7_438a_9638_c69bbaa94071
#define I_STATIC_TEXT_3476f4ac_72d7_438a_9638_c69bbaa94071

#include "IGuiController.h"
#include "WXObjectPtr.h"
#include <string>

namespace WXWidgets {

    class IWindow;

    /**
     * The IStaticText interface defines a static text.
     */
    class IStaticText {
    public:
        IStaticText() = default;
        virtual ~IStaticText() = default;

        /**
         * Initializes a GUI component.
         */
        virtual void Initialize(IGuiControllerSharedPtr guiController) = 0;

        /**
         * Gets a window.
         */
        virtual IWindow& GetWindow() = 0;

        /**
         * Sets text.
         */
        virtual void SetText(const std::wstring& text) = 0;
    };

    //
    // Defines the WX Object Ptr of Static Text.
    //
    using IStaticTextPtr = WXObjectPtr<IStaticText>;

}  // namespace WXWidgets

#endif // I_STATIC_TEXT_3476f4ac_72d7_438a_9638_c69bbaa94071
