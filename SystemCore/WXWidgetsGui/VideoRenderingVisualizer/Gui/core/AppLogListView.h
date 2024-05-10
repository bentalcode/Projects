#ifndef APP_LOG_LIST_VIEW_H_7b0f5d31_b044_49a8_a0b3_f79d52e6712c
#define APP_LOG_LIST_VIEW_H_7b0f5d31_b044_49a8_a0b3_f79d52e6712c

#include "ListView.h"

namespace VideoRenderingVisualizer {

    namespace Gui {

        class IGuiManager;

        /**
         * The AppLogListView class implements a list view of app log.
         */
        class AppLogListView final : public wxwidgets::ListView {
        public:
            /**
             * Creates an App Log List View.
             */
            static wxwidgets::IListViewPtr Make(
                wxWindow& parent,
                const std::wstring& logPath,
                IGuiManager& guiManager);

            /**
             * The AppLogListView constructor.
             */
            AppLogListView(
                wxWindow& parent,
                const std::wstring& logPath,
                IGuiManager& guiManager);

            /**
             * The AppLogListView destructor.
             */
            virtual ~AppLogListView();

        private:
            /**
             * Initializes a GUI component.
             */
            void Initialize(IGuiManager& guiManager);

            /**
             * Gets list view information.
             */
            void GetListViewInformation(
                std::vector<std::wstring>& headers,
                std::vector<std::vector<std::wstring>>& values) const;

            /**
             * Gets list view headers.
             */
            void GetListViewHeaders(std::vector<std::wstring>& headers) const;

            /**
             * Gets list view values.
             */
            void GetListViewValues(std::vector<std::vector<std::wstring>>& values) const;

            //
            // The GUI Manager...
            //
            IGuiManager& m_guiManager;

            //
            // The path of log...
            //
            std::wstring m_logPath;
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // APP_LOG_LIST_VIEW_H_7b0f5d31_b044_49a8_a0b3_f79d52e6712c
