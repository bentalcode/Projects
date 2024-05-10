#ifndef I_CANVAS_036076e0_4a0d_4f02_97a2_de654e1b9d33
#define I_CANVAS_036076e0_4a0d_4f02_97a2_de654e1b9d33

#include "IGuiController.h"
#include "IWindow.h"
#include "WXObjectPtr.h"

namespace wxwidgets {

    /**
     * The ICanvas interface defines a canvas.
     */
    class ICanvas {
    public:
        ICanvas() = default;
        virtual ~ICanvas() = default;

        /**
         * Initializes a GUI component.
         */
        virtual void Initialize(IGuiControllerSharedPtr guiController) = 0;

        /**
         * Gets a window.
         */
        virtual IWindow& GetWindow() = 0;
    };

    //
    // Defines the WX Object Ptr of Canvas.
    //
    using ICanvasPtr = WXObjectPtr<ICanvas>;

} // namespace wxwidgets

#endif // I_CANVAS_036076e0_4a0d_4f02_97a2_de654e1b9d33
