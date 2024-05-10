#ifndef MAIN_LEFT_WINDOW_H_8708017f_db74_4381_80b6_9bba2110aed6
#define MAIN_LEFT_WINDOW_H_8708017f_db74_4381_80b6_9bba2110aed6

#include "AbstractGuiWindow.h"
#include "ISplitterWindow.h"
#include <vector>

namespace VideoRenderingVisualizer {

    namespace Gui {

        /**
         * The MainLeftWindow class implements a gui of Main Left Window of frame.
         */
        class MainLeftWindow final : public AbstractGuiWindow {
        public:
            /**
             * Creates a Main Left Window.
             */
            static IGuiWindowSharedPtr Make(
                wxWindow& parent,
                const std::vector<std::wstring>& topWindowItems,
                IGuiManager& guiManager);

            /**
             * The MainLeftWindow constructor.
             */
            MainLeftWindow(
                wxWindow& parent,
                const std::vector<std::wstring>& topWindowItems,
                IGuiManager& guiManager);

            /**
             * The MainLeftWindow destructor.
             */
            virtual ~MainLeftWindow();

            /**
             * Gets a window.
             */
            virtual WXWidgets::IWindow& GetWindow() override;

        private:
            /**
             * Initializes a window.
             */
            void InitializeWindow(
                wxWindow& parent,
                const std::vector<std::wstring>& topWindowItems);

            /**
             * Creates a configuration of a splitter window.
             */
            static const WXWidgets::ISplitterWindowConfigurationSharedPtr CreateSplitterWindowConfiguration(
                const wxWindow& window,
                const std::wstring& topWindowBorderLabel,
                const std::wstring& bottomWindowBorderLabel);

            /**
             * Creates a gravity of splitter window.
             */
            static double CalculateSplitterWindowGravity(const wxWindow& window);

            WXWidgets::ISplitterWindowPtr m_splitterWindow;
            IGuiWindowSharedPtr m_topWindow;
            IGuiWindowSharedPtr m_bottomWindow;
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // MAIN_LEFT_WINDOW_H_8708017f_db74_4381_80b6_9bba2110aed6
