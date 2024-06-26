#ifndef APP_LOG_DIALOG_H_d410587b_5db6_444b_a180_06d8d168e194
#define APP_LOG_DIALOG_H_d410587b_5db6_444b_a180_06d8d168e194

#include "Dialog.h"
#include "IGuiManager.h"
#include "IListView.h"

namespace VideoRenderingVisualizer {

    namespace Gui {

        /**
         * The AppLogDialog class implements a dialog of App Log.
         */
        class AppLogDialog final : public wxwidgets::Dialog {
        public:
            /**
             * Creates an App Log Dialog.
             */
            static wxwidgets::IDialogPtr Make(
                wxWindow& parent,
                IGuiManager& guiManager);

            /**
             * The AppLogDialog constructor.
             */
            AppLogDialog(
                wxWindow& parent,
                IGuiManager& guiManager);

            /**
             * The AppLogDialog destructor.
             */
            virtual ~AppLogDialog();

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
            // The list view of log...
            //
            wxwidgets::IListViewPtr m_logListView;
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // APP_LOG_DIALOG_H_d410587b_5db6_444b_a180_06d8d168e194
