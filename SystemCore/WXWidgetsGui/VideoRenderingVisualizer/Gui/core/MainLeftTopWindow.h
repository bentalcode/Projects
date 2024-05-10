#ifndef MAIN_LEFT_TOP_WINDOW_H_ff6f5eaa_1519_41ac_ad2d_512dc91eff9c
#define MAIN_LEFT_TOP_WINDOW_H_ff6f5eaa_1519_41ac_ad2d_512dc91eff9c

#include "AbstractGuiWindow.h"
#include "ISplitterWindow.h"
#include <vector>

namespace VideoRenderingVisualizer {

    namespace Gui {

        /**
         * The MainLeftTopWindow class implements a gui of Main Left Top Window of frame.
         */
        class MainLeftTopWindow final : public AbstractGuiWindow {
        public:
            /**
             * Creates a Main Left Top Window.
             */
            static IGuiWindowSharedPtr Make(
                wxWindow& parent,
                const std::vector<std::wstring>& topWindowItems,
                IGuiManager& guiManager);

            /**
             * The MainLeftTopWindow constructor.
             */
            MainLeftTopWindow(
                wxWindow& parent,
                const std::vector<std::wstring>& topWindowItems,
                IGuiManager& guiManager);

            /**
             * The MainLeftTopWindow destructor.
             */
            virtual ~MainLeftTopWindow();

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

#endif // MAIN_LEFT_TOP_WINDOW_H_ff6f5eaa_1519_41ac_ad2d_512dc91eff9c
