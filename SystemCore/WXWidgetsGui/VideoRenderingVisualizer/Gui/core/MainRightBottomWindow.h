#ifndef MAIN_RIGHT_BOTTOM_WINDOW_H_28d45fb8_5c90_441d_8a9e_829b91a0bac8
#define MAIN_RIGHT_BOTTOM_WINDOW_H_28d45fb8_5c90_441d_8a9e_829b91a0bac8

#include "AbstractGuiWindow.h"
#include "IListView.h"

namespace VideoRenderingVisualizer {

    namespace Gui {

        /**
         * The MainRightBottomWindow class implements a gui of
         * Main Right Bottom Window.
         */
        class MainRightBottomWindow final : public AbstractGuiWindow {
        public:
            /**
             * Creates a Main Right Bottom Window.
             */
            static IGuiWindowSharedPtr Make(
                wxWindow& parent,
                IGuiManager& guiManager);

            /**
             * The MainRightBottomWindow constructor.
             */
            MainRightBottomWindow(
                wxWindow& parent,
                IGuiManager& guiManager);

            /**
             * The MainRightBottomWindow destructor.
             */
            virtual ~MainRightBottomWindow();

            /**
             * Gets a window.
             */
            virtual wxwidgets::IWindow& GetWindow() override;

        private:
            /**
             * Initializes a window.
             */
            void Initialize(wxWindow& parent);

            //
            // The list view of rendering pipelines...
            //
            wxwidgets::IListViewPtr m_listView;
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // MAIN_RIGHT_BOTTOM_WINDOW_H_28d45fb8_5c90_441d_8a9e_829b91a0bac8
