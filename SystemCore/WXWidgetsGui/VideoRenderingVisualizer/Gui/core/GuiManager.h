#ifndef GUI_MANAGER_H_4d12ab6e_9212_4d78_8ab0_a83e2464c2c5
#define GUI_MANAGER_H_4d12ab6e_9212_4d78_8ab0_a83e2464c2c5

#include "IGuiManager.h"
#include "IGuiConfigurationManager.h"

namespace VideoRenderingVisualizer {

    namespace Gui {

        /**
         * The GuiManager class implements a GUI Manager of Video Rendering Visualizer.
         */
        class GuiManager final : public IGuiManager {
        public:
            /**
             * Creates a GUI Manager.
             */
            static IGuiManagerSharedPtr Make();

            /**
             * The GuiManager constructor.
             */
            GuiManager();

            /**
             * The GuiManager destructor.
             */
            virtual ~GuiManager();

            /**
             * Gets a GUI Configuration Manager.
             */
            virtual const GuiConfiguration::IGuiConfigurationManager& GetConfigurationManager() const override;

            /**
             * Gets a Controller Manager.
             */
            virtual WXWidgets::controller::IControllerManagerSharedPtr GetControllerManager() override;

            /**
             * Gets a GUI Controller.
             */
            virtual WXWidgets::IGuiControllerSharedPtr GetGuiController() override;

            /**
             * Gets an Event Log.
             */
            virtual tabular_data::IEventLogSharedPtr GetEventLog() override;
            virtual const tabular_data::IEventLogSharedPtr GetEventLog() const override;

            /**
             * Gets a Data Repository.
             */
            virtual Model::IDataRepositorySharedPtr GetDataRepository() override;
            virtual const Model::IDataRepositorySharedPtr GetDataRepository() const override;

            /**
             * Gets path of rendering pipelines visualizer html.
             */
            virtual const std::wstring& GetRenderingPipelinesVisualizerHtmlPath() const override;

            /**
             * Gets path of app log.
             */
            virtual const std::wstring& GetAppLogPath() const override;

        private:
            //
            // The path of repository resources...
            //
            static const std::wstring REPOSITORY_RESOURCES_PATH;

            //
            // The path of rendering pipelines visualizer HTML...
            //
            static const std::wstring RENDERING_PIPELINES_VISUALIZER_HTML_PATH;

            //
            // The path of app log...
            //
            static const std::wstring APP_LOG_PATH;

            GuiConfiguration::IGuiConfigurationManagerSharedPtr m_configurationManager;
            WXWidgets::IGuiControllerSharedPtr m_guiController;
            tabular_data::IEventLogSharedPtr m_eventLog;
            Model::IDataRepositorySharedPtr m_dataRepository;
            std::wstring m_renderingPipelinesVisualizerHtmlPath;
            std::wstring m_logPath;
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // GUI_MANAGER_H_4d12ab6e_9212_4d78_8ab0_a83e2464c2c5
