#ifndef I_GUI_MANAGER_H_649c2b2d_a280_4df8_912f_ca01bed46ad7
#define I_GUI_MANAGER_H_649c2b2d_a280_4df8_912f_ca01bed46ad7

#include "IControllerManager.h"
#include "IGuiController.h"
#include "IEventLog.h"
#include "IDataRepository.h"

namespace GuiConfiguration {
    class IGuiConfigurationManager;
}

namespace VideoRenderingVisualizer {

    namespace Gui {

        /**
         * The IGuiManager interface defines a GUI Manager of Video Rendering Visualizer.
         */
        class IGuiManager {
        public:
            IGuiManager() = default;
            virtual ~IGuiManager() = default;

            /**
             * Gets a GUI Configuration Manager.
             */
            virtual const GuiConfiguration::IGuiConfigurationManager& GetConfigurationManager() const = 0;

            /**
             * Gets a Controller Manager.
             */
            virtual wxwidgets::controller::IControllerManagerSharedPtr GetControllerManager() = 0;

            /**
             * Gets a GUI Controller.
             */
            virtual wxwidgets::IGuiControllerSharedPtr GetGuiController() = 0;

            /**
             * Gets an Event Log.
             */
            virtual tabular_data::IEventLogSharedPtr GetEventLog() = 0;
            virtual const tabular_data::IEventLogSharedPtr GetEventLog() const = 0;

            /**
             * Gets a Data Repository.
             */
            virtual Model::IDataRepositorySharedPtr GetDataRepository() = 0;
            virtual const Model::IDataRepositorySharedPtr GetDataRepository() const = 0;

            /**
             * Gets path of rendering pipelines visualizer html.
             */
            virtual const std::wstring& GetRenderingPipelinesVisualizerHtmlPath() const = 0;

            /**
             * Gets path of app log.
             */
            virtual const std::wstring& GetAppLogPath() const = 0;
        };

        /**
         * Defines the Shared Ptr of GUI Manager.
         */
        using IGuiManagerSharedPtr = std::shared_ptr<IGuiManager>;

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // I_GUI_MANAGER_H_649c2b2d_a280_4df8_912f_ca01bed46ad7
