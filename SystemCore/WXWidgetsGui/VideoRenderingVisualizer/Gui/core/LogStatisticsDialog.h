#ifndef LOG_STATISTICS_DIALOG_H_c8fe3c7a_80b8_49f5_966f_f59b298abdec
#define LOG_STATISTICS_DIALOG_H_c8fe3c7a_80b8_49f5_966f_f59b298abdec

#include "Dialog.h"
#include "IGuiManager.h"
#include "IListView.h"

namespace VideoRenderingVisualizer {

    namespace Gui {

        /**
         * The LogStatisticsDialog class implements a dialog of Log Statistics.
         */
        class LogStatisticsDialog final : public wxwidgets::Dialog {
        public:
            /**
             * Creates a Log Statistics Dialog.
             */
            static wxwidgets::IDialogPtr Make(
                wxWindow& parent,
                IGuiManager& guiManager);

            /**
             * The LogStatisticsDialog constructor.
             */
            LogStatisticsDialog(
                wxWindow& parent,
                IGuiManager& guiManager);

            /**
             * The LogStatisticsDialog destructor.
             */
            virtual ~LogStatisticsDialog();

        private:
            /**
             * Initializes a GUI component.
             */
            void Initialize(IGuiManager& guiManager);

            //
            // The GUI Manager...
            //
            IGuiManager& m_guiManager;

            //
            // The list view of logs statistics...
            //
            wxwidgets::IListViewPtr m_logStatisticsListView;
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // LOG_STATISTICS_DIALOG_H_c8fe3c7a_80b8_49f5_966f_f59b298abdec
