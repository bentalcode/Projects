#ifndef MAIN_LEFT_TOP_WINDOW_UPPER_SUB_WINDOW_H_05a26d32_8256_489e_8ffb_6c804e5b9ba2
#define MAIN_LEFT_TOP_WINDOW_UPPER_SUB_WINDOW_H_05a26d32_8256_489e_8ffb_6c804e5b9ba2

#include "AbstractGuiWindow.h"
#include "IListBox.h"

class wxWindow;

namespace VideoRenderingVisualizer {

    namespace Gui {

        /**
         * The MainLeftTopWindowUpperSubWindow class implements a gui of
         * Main Left Top Window - Upper Sub Window.
         */
        class MainLeftTopWindowUpperSubWindow final : public AbstractGuiWindow {
        public:
            /**
             * Creates a Main Left Top Window - Upper Sub Window.
             */
            static IGuiWindowSharedPtr Make(
                wxWindow& parent,
                const std::vector<std::wstring>& items,
                IGuiManager& guiManager);

            /**
             * The MainLeftTopWindowUpperSubWindow constructor.
             */
            MainLeftTopWindowUpperSubWindow(
                wxWindow& parent,
                const std::vector<std::wstring>& items,
                IGuiManager& guiManager);

            /**
             * The MainLeftTopWindowUpperSubWindow destructor.
             */
            virtual ~MainLeftTopWindowUpperSubWindow();

            /**
             * Gets a window.
             */
            virtual WXWidgets::IWindow& GetWindow() override;

        private:
            /**
             * Initializes a window.
             */
            void Initialize(
                wxWindow& parent,
                const std::vector<std::wstring>& items);

            WXWidgets::IListBoxPtr m_listBox;
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // MAIN_LEFT_TOP_WINDOW_UPPER_SUB_WINDOW_H_05a26d32_8256_489e_8ffb_6c804e5b9ba2
