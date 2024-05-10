#ifndef MAIN_RIGHT_TOP_WINDOW_LOWER_SUB_WINDOW_H_bcf277f4_3d5e_4b78_9412_88de3f6431e5
#define MAIN_RIGHT_TOP_WINDOW_LOWER_SUB_WINDOW_H_bcf277f4_3d5e_4b78_9412_88de3f6431e5

#include "AbstractGuiWindow.h"
#include "ISlider.h"

class wxWindow;

namespace VideoRenderingVisualizer {

    namespace Gui {

        /**
         * The MainRightTopWindowLowerSubWindow class implements a gui of
         * Main Right Top Window - Lower Sub Window.
         */
        class MainRightTopWindowLowerSubWindow final : public AbstractGuiWindow {
        public:
            /**
             * Creates a Main Right Top Window - Lower Sub Window.
             */
            static IGuiWindowSharedPtr Make(
                wxWindow& parent,
                IGuiManager& guiManager);

            /**
             * The MainRightTopWindowLowerSubWindow constructor.
             */
            MainRightTopWindowLowerSubWindow(
                wxWindow& parent,
                IGuiManager& guiManager);

            /**
             * The MainRightTopWindowLowerSubWindow destructor.
             */
            virtual ~MainRightTopWindowLowerSubWindow();

            /**
             * Gets a window.
             */
            virtual WXWidgets::IWindow& GetWindow() override;

        private:
            /**
             * Initializes a window.
             */
            void Initialize(wxWindow& parent);

            WXWidgets::ISliderPtr m_slider;
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // MAIN_RIGHT_TOP_WINDOW_LOWER_SUB_WINDOW_H_bcf277f4_3d5e_4b78_9412_88de3f6431e5
