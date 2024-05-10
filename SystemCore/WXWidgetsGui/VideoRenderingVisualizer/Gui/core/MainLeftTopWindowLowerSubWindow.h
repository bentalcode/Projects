#ifndef MAIN_LEFT_TOP_WINDOW_LOWER_SUB_WINDOW_H_11cce28d_8d91_4dcf_ae74_6b79b15f3908
#define MAIN_LEFT_TOP_WINDOW_LOWER_SUB_WINDOW_H_11cce28d_8d91_4dcf_ae74_6b79b15f3908

#include "AbstractGuiWindow.h"
#include "IListBox.h"

class wxWindow;

namespace VideoRenderingVisualizer {

    namespace Gui {

        /**
         * The MainLeftTopWindowLowerSubWindow class implements a gui of
         * Main Left Top Window - Lower Sub Window.
         */
        class MainLeftTopWindowLowerSubWindow final : public AbstractGuiWindow {
        public:
            /**
             * Creates a Main Left Top Window - Lower Sub Window.
             */
            static IGuiWindowSharedPtr Make(
                wxWindow& parent,
                const std::vector<std::wstring>& items,
                IGuiManager& guiManager);

            /**
             * The MainLeftTopWindowLowerSubWindow constructor.
             */
            MainLeftTopWindowLowerSubWindow(
                wxWindow& parent,
                const std::vector<std::wstring>& items,
                IGuiManager& guiManager);

            /**
             * The MainLeftTopWindowLowerSubWindow destructor.
             */
            virtual ~MainLeftTopWindowLowerSubWindow();

            /**
             * Gets a window.
             */
            virtual wxwidgets::IWindow& GetWindow() override;

        private:
            /**
             * Initializes a window.
             */
            void Initialize(
                wxWindow& parent,
                const std::vector<std::wstring>& items);

            wxwidgets::IListBoxPtr m_listBox;
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // MAIN_LEFT_TOP_WINDOW_LOWER_SUB_WINDOW_H_11cce28d_8d91_4dcf_ae74_6b79b15f3908
