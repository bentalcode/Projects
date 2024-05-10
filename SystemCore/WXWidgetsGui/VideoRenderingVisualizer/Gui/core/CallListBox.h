#ifndef CALL_LIST_BOX_H_be7cf40d_05f5_4dbb_9786_c25cc3fd5f74
#define CALL_LIST_BOX_H_be7cf40d_05f5_4dbb_9786_c25cc3fd5f74

#include "ListBox.h"
#include "DateTimeInterval.h"

namespace VideoRenderingVisualizer {

    namespace Model {
        class ICallInformation;
    }

    namespace Gui {

        class IGuiManager;

        /**
         * The CallListBox class implements a list box of calls.
         */
        class CallListBox final : public WXWidgets::ListBox {
        public:
            /**
             * Creates a call list box.
             */
            static WXWidgets::IListBoxPtr Make(
                wxWindow& parent,
                const std::vector<std::wstring>& items,
                IGuiManager& guiManager);

            /**
             * The CallListBox constructor.
             */
            CallListBox(
                wxWindow& parent,
                const std::vector<std::wstring>& items,
                IGuiManager& guiManager);

            /**
             * The CallListBox destructor.
             */
            virtual ~CallListBox();

            /**
             * The on selected callback.
             */
            virtual void OnSelectedItem(const std::wstring& item) override;

        private:
            /**
             * Initializes a GUI component.
             */
            void Initialize(
                const std::vector<std::wstring>& items,
                IGuiManager& guiManager);

            /**
             * Queries items of a compositor list box.
             */
            void QueryCompositorListBoxItems(
                const std::wstring& callId,
                std::vector<std::wstring>& items) const;

            /**
             * Queries rendering pipelines time interval.
             */
            base::DateTimeIntervalSharedPtr QueryRenderingPipelinesTimeInterval(const std::wstring& callId) const;

            //
            // The GUI Manager...
            //
            IGuiManager& m_guiManager;
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // CALL_LIST_BOX_H_be7cf40d_05f5_4dbb_9786_c25cc3fd5f74
