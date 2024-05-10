#ifndef WINDOW_9bc360cd_662b_485b_9699_69bf8ca9cd22
#define WINDOW_9bc360cd_662b_485b_9699_69bf8ca9cd22

#include "AbstractWindow.h"

namespace wxwidgets {

    /**
     * The Window class implements a window.
     */
    class Window : public AbstractWindow {
    public:
        /**
         * The Window constructor.
         */
        Window();

        /**
         * The Window destructor.
         */
        virtual ~Window();

        /**
         * Initializes a GUI component.
         */
        void Initialize(
            wxWindow& window,
            IGuiControllerSharedPtr guiController,
            bool showMode = true);
    };

} // namespace wxwidgets

#endif // WINDOW_9bc360cd_662b_485b_9699_69bf8ca9cd22
