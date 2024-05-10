#ifndef MAIN_RIGHT_WINDOW_H_d98ca0f3_1fe6_4ae5_9e9a_3680eaefe859
#define MAIN_RIGHT_WINDOW_H_d98ca0f3_1fe6_4ae5_9e9a_3680eaefe859

#include "AbstractGuiWindow.h"
#include "ISplitterWindow.h"

namespace VideoRenderingVisualizer {

    namespace Gui {

        class IGuiManager;

        /**
         * The MainRightWindow class implements a gui of
         * Main Right Window of frame.
         */
        class MainRightWindow final : public AbstractGuiWindow {
        public:
            /**
             * Creates a Main Right Window.
             */
            static IGuiWindowSharedPtr Make(
                wxWindow& parent,
                IGuiManager& guiManager);

            /**
             * The MainRightWindow constructor.
             */
            MainRightWindow(
                wxWindow& parent,
                IGuiManager& guiManager);

            /**
             * The MainRightWindow destructor.
             */
            virtual ~MainRightWindow();

            /**
             * Gets a window.
             */
            virtual wxwidgets::IWindow& GetWindow() override;

        private:
            /**
             * Initializes a window.
             */
            void Initialize(wxWindow& parent);

            /**
             * Creates a configuration of a splitter window.
             */
            static const wxwidgets::ISplitterWindowConfigurationSharedPtr CreateSplitterWindowConfiguration(
                const wxWindow& window,
                const std::wstring& topWindowBorderLabel,
                const std::wstring& bottomWindowBorderLabel);

            /**
             * Creates a gravity of splitter window.
             */
            static double CalculateSplitterWindowGravity(const wxWindow& window);

            wxwidgets::ISplitterWindowPtr m_splitterWindow;
            IGuiWindowSharedPtr m_topWindow;
            IGuiWindowSharedPtr m_bottomWindow;
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // MAIN_RIGHT_WINDOW_H_d98ca0f3_1fe6_4ae5_9e9a_3680eaefe859
