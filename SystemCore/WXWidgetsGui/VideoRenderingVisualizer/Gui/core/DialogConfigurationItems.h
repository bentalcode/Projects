#ifndef DIALOG_CONFIGURATION_ITEMS_H_d377315f_a8c0_4f2a_a7aa_74c76d3e1b26
#define DIALOG_CONFIGURATION_ITEMS_H_d377315f_a8c0_4f2a_a7aa_74c76d3e1b26

#include "IDialogConfigurationItems.h"
#include <string>

namespace VideoRenderingVisualizer {

    namespace Gui {

        /**
         * The DialogConfigurationItems class implements configuration items of dialogs.
         */
        class DialogConfigurationItems final : public IDialogConfigurationItems {
        public:
            /**
             * Reads dialog configuration items from configuration catalog.
             */
            static const IDialogConfigurationItems& Read();

            /**
             * Creates dialog configuration items.
             */
            static GuiConfiguration::IConfigurationItemsSharedPtr Make();

            /**
             * The DialogConfigurationItems constructor.
             */
            DialogConfigurationItems();

            /**
             * The DialogConfigurationItems destructor.
             */
            virtual ~DialogConfigurationItems();

            /**
             * Gets category name of data items.
             */
            virtual const std::wstring& GetName() const override;

            /**
             * Gets title of rendering pipelines visualizer dialog.
             */
            virtual const std::wstring& GetRenderingPipelinesVisualizerDialogTitle() const override;

            /**
             * Gets title of event viewer dialog.
             */
            virtual const std::wstring& GetEventViewerDialogTitle() const override;

            /**
             * Gets title of log statistics dialog.
             */
            virtual const std::wstring& GetLogStatisticsDialogTitle() const override;

            /**
             * Gets title of app log dialog.
             */
            virtual const std::wstring& GetAppLogDialogTitle() const override;

        private:
            static const std::wstring NAME;
            static const std::wstring RENDERING_PIPELINES_VISUALIZER_TITLE;
            static const std::wstring EVENT_VIEWER_TITLE;
            static const std::wstring LOG_STATISTICS_TITLE;
            static const std::wstring APP_LOG_TITLE;
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // DIALOG_CONFIGURATION_ITEMS_H_d377315f_a8c0_4f2a_a7aa_74c76d3e1b26
