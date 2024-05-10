#ifndef EVENT_VIEWER_DIALOG_H_8521afb1_e2c2_435f_8800_e85d650d2151
#define EVENT_VIEWER_DIALOG_H_8521afb1_e2c2_435f_8800_e85d650d2151

#include "Dialog.h"
#include "IGuiManager.h"
#include "IListView.h"

namespace VideoRenderingVisualizer {

    namespace Gui {

        /**
         * The EventViewerDialog class implements a dialog of Event Viewer.
         */
        class EventViewerDialog final : public WXWidgets::Dialog {
        public:
            /**
             * Creates an Event Viewer Dialog.
             */
            static WXWidgets::IDialogPtr Make(
                wxWindow& parent,
                IGuiManager& guiManager);

            /**
             * The EventViewerDialog constructor.
             */
            EventViewerDialog(
                wxWindow& parent,
                IGuiManager& guiManager);

            /**
             * The EventViewerDialog destructor.
             */
            virtual ~EventViewerDialog();

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
            // The list view of events...
            //
            WXWidgets::IListViewPtr m_eventListView;
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // EVENT_VIEWER_DIALOG_H_8521afb1_e2c2_435f_8800_e85d650d2151
