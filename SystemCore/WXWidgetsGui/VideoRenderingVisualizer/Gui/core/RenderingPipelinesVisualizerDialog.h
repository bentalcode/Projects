#ifndef RENDERING_PIPELINES_VISUALIZER_DIALOG_H_b79ace62_016a_4447_bf59_52803398280d
#define RENDERING_PIPELINES_VISUALIZER_DIALOG_H_b79ace62_016a_4447_bf59_52803398280d

#include "Dialog.h"
#include "IGuiManager.h"
#include "RenderingPipelinesHtmlWindow.h"

namespace VideoRenderingVisualizer {

    namespace Gui {

        /**
         * The RenderingPipelinesVisualizerDialog class implements
         * a dialog of Rendering Pipelines Visualizer.
         */
        class RenderingPipelinesVisualizerDialog final : public wxwidgets::Dialog {
        public:
            /**
             * Creates a Rendering Pipelines Visualizer Dialog.
             */
            static wxwidgets::IDialogPtr Make(
                wxWindow& parent,
                IGuiManager& guiManager);

            /**
             * The RenderingPipelinesVisualizerDialog constructor.
             */
            RenderingPipelinesVisualizerDialog(
                wxWindow& parent,
                IGuiManager& guiManager);

            /**
             * The RenderingPipelinesVisualizerDialog destructor.
             */
            virtual ~RenderingPipelinesVisualizerDialog();

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
            // The HTML Document of Rendering Pipelines...
            //
            wxwidgets::IHtmlWindowPtr m_renderingPiplinesHtmlWindow;
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // RENDERING_PIPELINES_VISUALIZER_DIALOG_H_b79ace62_016a_4447_bf59_52803398280d
