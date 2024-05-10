#ifndef MAIN_RIGHT_TOP_WINDOW_UPPER_SUB_WINDOW_H_d5f3298a_8924_4f3a_821e_bae06814fef6
#define MAIN_RIGHT_TOP_WINDOW_UPPER_SUB_WINDOW_H_d5f3298a_8924_4f3a_821e_bae06814fef6

#include "AbstractGuiWindow.h"
#include "ICanvas.h"

class wxWindow;

namespace VideoRenderingVisualizer {

    namespace Gui {

        class IGuiManager;

        /**
         * The MainRightTopWindowUpperSubWindow class implements a gui of
         * Main Right Top Window Upper Sub Window of frame.
         */
        class MainRightTopWindowUpperSubWindow final : public AbstractGuiWindow {
        public:
            /**
             * Creates a Main Right Top Window Upper Sub Window.
             */
            static IGuiWindowSharedPtr Make(
                wxWindow& parent,
                IGuiManager& guiManager);

            /**
             * The MainRightTopWindowUpperSubWindow constructor.
             */
            MainRightTopWindowUpperSubWindow(
                wxWindow& parent,
                IGuiManager& guiManager);

            /**
             * The MainRightTopWindowUpperSubWindow destructor.
             */
            virtual ~MainRightTopWindowUpperSubWindow();

            /**
             * Gets a window.
             */
            virtual WXWidgets::IWindow& GetWindow() override;

        private:

            /**
             * Initializes a window.
             */
            void Initialize(wxWindow& parent);

            WXWidgets::ICanvasPtr m_canvas;
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // MAIN_RIGHT_TOP_WINDOW_UPPER_SUB_WINDOW_H_d5f3298a_8924_4f3a_821e_bae06814fef6
