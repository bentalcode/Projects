#ifndef VIDEO_RENDERING_VISUALIZER_FRAME_H_26d64231_9082_497c_ab81_de26c43b0336
#define VIDEO_RENDERING_VISUALIZER_FRAME_H_26d64231_9082_497c_ab81_de26c43b0336

#include "Frame.h"
#include "IGuiWindow.h"
#include "ICallInformation.h"
#include "Menu.h"
#include "MenuBar.h"

namespace GuiConfiguration {
    class IGuiConfigurationManager;
}

namespace VideoRenderingVisualizer {

    namespace Gui {

        class IGuiManager;

        /**
         * The VideoRenderingVisualizerFrame class implements a frame.
         */
        class VideoRenderingVisualizerFrame final : public WXWidgets::Frame {
        public:
            /**
             * Creates an app.
             */
            static WXWidgets::IFramePtr Make(
                const wxString& title,
                const wxPoint& position,
                const wxSize& size,
                IGuiManager& guiManager);

            /**
             * The VideoRenderingVisualizerFrame constructor.
             */
            VideoRenderingVisualizerFrame(
                const wxString& title,
                const wxPoint& position,
                const wxSize& size,
                IGuiManager& guiManager);

            /**
             * The VideoRenderingVisualizerFrame destructor.
             */
            virtual ~VideoRenderingVisualizerFrame();

            /**
             * The on Open Folders callback.
             */
            void OnOpen(wxCommandEvent& event);

            /**
             * The on Exit callback.
             */
            void OnExit(wxCommandEvent& event);

            /**
             * The on About callback.
             */
            void OnAbout(wxCommandEvent& event);

            /**
             * The on Rendering Pipelines Visualizer callback.
             */
            void OnRenderingPipelinesVisualizer(wxCommandEvent& event);

            /**
             * The on Event Viewer callback.
             */
            void OnEventViewer(wxCommandEvent& event);

            /**
             * The on Log Statistics callback.
             */
            void OnLogStatistics(wxCommandEvent& event);

            /**
             * The on App Log callback.
             */
            void OnAppLog(wxCommandEvent& event);

        private:
            /**
             * Initializes a GUI component.
             */
            void Initialize();

            /**
             * Initializes top menu bar.
             */
            void InitializeTopMenuBar(const GuiConfiguration::IGuiConfigurationManager& configurationManager);

            /**
             * Initializes a status bar.
             */
            void InitializeStatusBar(const GuiConfiguration::IGuiConfigurationManager& configurationManager);

            /**
             * Initializes a main window.
             */
            void InitializeMainWindow();

            /**
             * Creates a menu bar.
             */
            WXWidgets::IMenuBarPtr CreateMenuBar(
                wxMenu& fileMenu,
                wxMenu& viewMenu,
                wxMenu& helpMenu);

            /**
             * Creates a file menu.
             */
            WXWidgets::IMenuPtr CreateFileMenu(const GuiConfiguration::IGuiConfigurationManager& configurationManager);

            /**
             * Creates a view menu.
             */
            WXWidgets::IMenuPtr CreateViewMenu(const GuiConfiguration::IGuiConfigurationManager& configurationManager);

            /**
             * Creates a help menu.
             */
            WXWidgets::IMenuPtr CreateHelpMenu(const GuiConfiguration::IGuiConfigurationManager& configurationManager);

            /**
             * Retrieves calls information from data repository.
             */
            void GetCallsInformation(std::vector<Model::ICallInformationSharedPtr>& callsInformation) const;

            WXWidgets::IMenuPtr m_fileMenu;
            WXWidgets::IMenuPtr m_viewMenu;
            WXWidgets::IMenuPtr m_helpMenu;
            WXWidgets::IMenuBarPtr m_menuBar;
            IGuiWindowSharedPtr m_mainWindow;
            IGuiManager& m_guiManager;
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // VIDEO_RENDERING_VISUALIZER_FRAME_H_26d64231_9082_497c_ab81_de26c43b0336
