#pragma once

#include "GLCanvas.h"
#include "DateTimeInterval.h"
#include "IRenderingPipelineInformationCollection.h"

namespace VideoRenderingVisualizer {

namespace Gui {

class IGuiManager;

/**
 * The RenderingPipelinesCanvas class implements a canvas of rendering pipelines 
 * for displaying OpenGL Graphics. 
 */
class RenderingPipelinesCanvas final : public WXWidgets::GLCanvas {
public:
    /**
     * Creates a Rendering Pipelines Canvas.
     */
    static WXWidgets::ICanvasPtr Make(
        wxWindow& parent, 
        const Utilities::DateTimeIntervalSharedPtr intervalTime,
        IGuiManager& guiManager);

    /**
     * The RenderingPipelinesCanvas constructor.
     */
    RenderingPipelinesCanvas(
        wxWindow& parent, 
        const Utilities::DateTimeIntervalSharedPtr intervalTime,
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
        const Utilities::DateTime& time);

    /**
     * Updates data container (end interval time).
     */
    static void UpdateDataContainerEndIntervalTime(
        DataContainerManagement::IDataContainer& data, 
        const Utilities::DateTime& time);

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
    Utilities::DateTimeIntervalSharedPtr m_intervalTime;

    //
    // The effective rendering pipelines...
    //
    Model::IRenderingPipelineInformationCollectionSharedPtr m_renderingPipelines;

    GLuint m_vbo;  // vertex buffer pointer
    GLuint m_vao;  // vertex array pointer
};

}  // namespace Gui

}  // namespace VideoRenderingVisualizer
