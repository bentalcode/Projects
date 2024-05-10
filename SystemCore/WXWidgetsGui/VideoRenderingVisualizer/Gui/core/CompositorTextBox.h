#ifndef COMPOSITOR_TEXT_BOX_H_78dff3d5_b6e3_47cc_96ee_cd5b8988ee80
#define COMPOSITOR_TEXT_BOX_H_78dff3d5_b6e3_47cc_96ee_cd5b8988ee80

#include "StaticText.h"
#include "ICompositorInformation.h"
#include "IGuiManager.h"

namespace VideoRenderingVisualizer {

    namespace Gui {

        /**
         * The CompositorTextBox class implements a text box of compositors.
         */
        class CompositorTextBox final : public WXWidgets::StaticText {
        public:
            /**
             * Creates a compositor static text box.
             */
            static WXWidgets::IStaticTextPtr Make(
                wxWindow& parent,
                IGuiManager& guiManager);

            /**
             * The CompositorTextBox constructor.
             */
            CompositorTextBox(
                wxWindow& parent,
                IGuiManager& guiManager);

            /**
             * The CompositorTextBox destructor.
             */
            virtual ~CompositorTextBox();

            /**
             * Updates data container (compositor id).
             */
            static void UpdateDataContainerCompositorId(
                DataContainerManagement::IDataContainer& data,
                const std::wstring& compositorId);

        protected:
            /**
             * Updates data from data container.
             * Returns true in case data has been updated.
             */
            virtual bool UpdateFromDataContainer(DataContainerManagement::IDataContainer& dataContainer) override;

        private:
            /**
             * Initializes a GUI component.
             */
            void Initialize(IGuiManager& guiManager);

            /**
             * Calculates display information of a compositor.
             */
            std::wstring QueryCompositorDisplayInformation(const std::wstring& compositorId);

            //
            // The current compositor id...
            //
            std::wstring m_compositorId;

            //
            // The GUI Manager...
            //
            IGuiManager& m_guiManager;
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // COMPOSITOR_TEXT_BOX_H_78dff3d5_b6e3_47cc_96ee_cd5b8988ee80
