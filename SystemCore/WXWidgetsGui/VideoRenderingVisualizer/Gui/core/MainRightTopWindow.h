#ifndef MAIN_RIGHT_TOP_WINDOW_H_268bdfb2_2235_4eec_a241_c447de72c8a7
#define MAIN_RIGHT_TOP_WINDOW_H_268bdfb2_2235_4eec_a241_c447de72c8a7

#include "AbstractGuiWindow.h"
#include "ISplitterWindow.h"

namespace VideoRenderingVisualizer {

    namespace Gui {

        /**
         * The MainRightTopWindow class implements a gui of
         * Main Right Top Window of frame.
         */
        class MainRightTopWindow final : public AbstractGuiWindow {
        public:
            /**
             * Creates a Main Right Top Window.
             */
            static IGuiWindowSharedPtr Make(
                wxWindow& parent,
                IGuiManager& guiManager);

            /**
             * The MainRightTopWindow constructor.
             */
            MainRightTopWindow(
                wxWindow& parent,
                IGuiManager& guiManager);

            /**
             * The MainRightTopWindow destructor.
             */
            virtual ~MainRightTopWindow();

            /**
             * Gets a window.
             */
            virtual WXWidgets::IWindow& GetWindow() override;

        private:
            /**
             * Initializes a window.
             */
            void Initialize(wxWindow& parent);

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

#endif // MAIN_RIGHT_TOP_WINDOW_H_268bdfb2_2235_4eec_a241_c447de72c8a7
