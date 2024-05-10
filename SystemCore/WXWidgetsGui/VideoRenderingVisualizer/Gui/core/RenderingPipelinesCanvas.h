#ifndef RENDERING_PIPELINE_CANVAS_H_720ca17b_d6b4_46b3_aa8a_39e5ff347181
#define RENDERING_PIPELINE_CANVAS_H_720ca17b_d6b4_46b3_aa8a_39e5ff347181

#include "GLCanvas.h"
#include "IRenderingPipelineInformationCollection.h"
#include "DateTimeInterval.h"

namespace VideoRenderingVisualizer {

        namespace Gui {

        class IGuiManager;

        /**
         * The RenderingPipelinesCanvas class implements a canvas of rendering pipelines
         * for displaying OpenGL Graphics.
         */
        class RenderingPipelinesCanvas final : public wxwidgets::GLCanvas {
        public:
            /**
             * Creates a Rendering Pipelines Canvas.
             */
            static wxwidgets::ICanvasPtr Make(
                wxWindow& parent,
                const base::DateTimeIntervalSharedPtr intervalTime,
                IGuiManager& guiManager);

            /**
             * The RenderingPipelinesCanvas constructor.
             */
            RenderingPipelinesCanvas(
                wxWindow& parent,
                const base::DateTimeIntervalSharedPtr intervalTime,
                IGuiManager& guiManager);

            /**
             * The RenderingPipelinesCanvas destructor.
             */
            virtual ~RenderingPipelinesCanvas();

            /**
             * Updates data container (start interval time).
             */
            static void UpdateDataContainerStartIntervalTime(
                DataContainerManagement::IDataContainer& data,
                const base::DateTime& time);

            /**
             * Updates data container (end interval time).
             */
            static void UpdateDataContainerEndIntervalTime(
                DataContainerManagement::IDataContainer& data,
                const base::DateTime& time);

        protected:
            /**
             * Updates data from data container.
             * Returns true in case data has been updated.
             */
            virtual bool UpdateFromDataContainer(DataContainerManagement::IDataContainer& dataContainer) override;

            /**
             * Updates component.
             */
            virtual void Update() override;

            /**
             * Initializes rendering.
             */
            virtual void InitializeRendering() override;

            /**
             * Renders painting.
             */
            virtual void RenderPainting() override;

        private:
            void PreRender1();
            void PreRender2();
            void Render1();
            void Render2();

            /**
             * Initializes a GUI component.
             */
            void Initialize(IGuiManager& guiManager);

            /**
             * Queries rendering pipelines information.
             */
            Model::IRenderingPipelineInformationCollectionSharedPtr QueryRenderingPipelinesInformation() const;

            /**
             * Gets attributes of canvas.
             */
            static const int* GetAttributes();

            //
            // The GUI Manager...
            //
            IGuiManager& m_guiManager;

            //
            // The interval time for displaying rendering pipelines...
            //
            base::DateTimeIntervalSharedPtr m_intervalTime;

            //
            // The effective rendering pipelines...
            //
            Model::IRenderingPipelineInformationCollectionSharedPtr m_renderingPipelines;

            GLuint m_vbo; // vertex buffer pointer
            GLuint m_vao; // vertex array pointer
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // RENDERING_PIPELINE_CANVAS_H_720ca17b_d6b4_46b3_aa8a_39e5ff347181
