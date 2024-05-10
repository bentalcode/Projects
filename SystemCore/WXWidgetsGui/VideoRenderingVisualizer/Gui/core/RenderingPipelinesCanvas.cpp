#include "RenderingPipelinesCanvas.h"
#include "GuiManager.h"
#include "IDataQuery.h"
#include "IDataCatalog.h"
#include "GuiPaths.h"
#include "GuiDataItems.h"
#include "DataItem.h"
#include "RenderingPipelineInformation.h"
#include "WXProperty.h"
#include "wx/dcclient.h"
#include "OpenGLApi.h"
#include "video_rendering_visualizer_exception.h"

using namespace VideoRenderingVisualizer;
using namespace VideoRenderingVisualizer::Gui;

namespace RenderingPipelinesCanvasFunctors {

/**
 * The UpdateDataContainerStartIntervalTimeFunctor class implements an update functor of start interval time.
 */
class UpdateDataContainerStartIntervalTimeFunctor final {
public:
    /**
     * The functor constructor.
     */
    UpdateDataContainerStartIntervalTimeFunctor(DataContainerManagement::IDataContainer& dataContainer) : 
        m_dataContainer(dataContainer)
    {
    }

    /**
     * The functor logic.
     */
    void operator()(const Utilities::DateTime& time)
    {
        RenderingPipelinesCanvas::UpdateDataContainerStartIntervalTime(m_dataContainer, time);
    }

private:
    DataContainerManagement::IDataContainer& m_dataContainer;
};

/**
 * The UpdateDataContainerEndIntervalTimeFunctor class implements an update functor of end interval time.
 */
class UpdateDataContainerEndIntervalTimeFunctor final {
public:
    /**
     * The functor constructor.
     */
    UpdateDataContainerEndIntervalTimeFunctor(DataContainerManagement::IDataContainer& dataContainer) : 
        m_dataContainer(dataContainer)
    {
    }

    /**
     * The functor logic.
     */
    void operator()(const Utilities::DateTime& time)
    {
        RenderingPipelinesCanvas::UpdateDataContainerEndIntervalTime(m_dataContainer, time);
    }

private:
    DataContainerManagement::IDataContainer& m_dataContainer;
};

}  // namespace RenderingPipelinesCanvasFunctors

/**
 * Creates a Rendering Pipelines Canvas.
 */
WXWidgets::ICanvasPtr RenderingPipelinesCanvas::Make(
    wxWindow& parent, 
    const Utilities::DateTimeIntervalSharedPtr intervalTime,
    IGuiManager& guiManager)
{
    return WXWidgets::ICanvasPtr::Make(new RenderingPipelinesCanvas(
        parent, 
        intervalTime, 
        guiManager));
}

/**
 * The RenderingPipelinesCanvas constructor.
 */
RenderingPipelinesCanvas::RenderingPipelinesCanvas(
    wxWindow& parent, 
    const Utilities::DateTimeIntervalSharedPtr intervalTime,
    IGuiManager& guiManager) : 
        GLCanvas(
            parent, 
            GuiPaths::Read().GetMainFrameMainRightTopWindowUpperSubWindowCanvas()), 
        m_guiManager(guiManager), 
        m_intervalTime(intervalTime)
{
    //
    // Initialize a GUI component...
    //
    Initialize(guiManager);
}

/**
 * The RenderingPipelinesCanvas destructor.
 */
RenderingPipelinesCanvas::~RenderingPipelinesCanvas() 
{
}

/**
 * Initializes a GUI component.
 */
void RenderingPipelinesCanvas::Initialize(IGuiManager& guiManager)
{
    //
    // Initialize rendering pipelines...
    //
    m_renderingPipelines = QueryRenderingPipelinesInformation();

    //
    // Initialize canvas...
    //
    WXWidgets::GLCanvas::Initialize(guiManager.GetGuiController());

    //
    // Register data update functors...
    //
    DataContainerManagement::IDataContainer& dataContainer = GetData();

    std::wstring dataItemStartIntervalTime = GuiDataItems::Read().GetRenderingPipelinesStartIntervalTime();
    std::wstring dataItemEndIntervalTime = GuiDataItems::Read().GetRenderingPipelinesEndIntervalTime();

    dataContainer.GetCatalog().RegisterDataItem(dataItemStartIntervalTime);
    dataContainer.GetCatalog().RegisterDataItem(dataItemEndIntervalTime);

    DataContainerManagement::IDataContainerUpdateFunctors::IDateTimeFunctorSharedPtr startIntervalTimeFunctor =
        std::make_shared<DataContainerManagement::IDataContainerUpdateFunctors::IDateTimeFunctor>(
            RenderingPipelinesCanvasFunctors::UpdateDataContainerStartIntervalTimeFunctor{ dataContainer });

    GetDataUpdateFunctors().RegisterUpdateFunctor(
        dataItemStartIntervalTime, 
        startIntervalTimeFunctor);

    DataContainerManagement::IDataContainerUpdateFunctors::IDateTimeFunctorSharedPtr endIntervalTimeFunctor =
        std::make_shared<DataContainerManagement::IDataContainerUpdateFunctors::IDateTimeFunctor>(
            RenderingPipelinesCanvasFunctors::UpdateDataContainerEndIntervalTimeFunctor{ dataContainer });

    GetDataUpdateFunctors().RegisterUpdateFunctor(
        dataItemEndIntervalTime,
        endIntervalTimeFunctor);
}

/**
 * Initializes rendering.
 */
void RenderingPipelinesCanvas::InitializeRendering() 
{
    PreRender2();
}

/**
 * Renders painting.
 */
void RenderingPipelinesCanvas::RenderPainting() 
{
    Render2();
}

void RenderingPipelinesCanvas::PreRender1() 
{
}

void RenderingPipelinesCanvas::Render1() 
{
    wxPaintDC dc(this);

    GL_CALL(glMatrixMode(GL_PROJECTION));
    GL_CALL(glLoadIdentity());
    GL_CALL(glFrustum(-0.5f, 0.5f, -0.5f, 0.5f, 1.0f, 3.0f));
    GL_CALL(glMatrixMode(GL_MODELVIEW));

    GL_CALL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

    GL_CALL(glBegin(GL_QUADS));

    GL_CALL(glNormal3f(0.0f, 0.0f, 1.0f));
    GL_CALL(glVertex3f(0.5f, 0.5f, 0.5f));
    GL_CALL(glVertex3f(-0.5f, 0.5f, 0.5f));
    GL_CALL(glVertex3f(-0.5f, -0.5f, 0.5f));
    GL_CALL(glVertex3f(0.5f, -0.5f, 0.5f));

    GL_CALL(glNormal3f(0.0f, 0.0f, -1.0f));
    GL_CALL(glVertex3f(-0.5f, -0.5f, -0.5f));
    GL_CALL(glVertex3f(-0.5f, 0.5f, -0.5f));
    GL_CALL(glVertex3f(0.5f, 0.5f, -0.5f));
    GL_CALL(glVertex3f(0.5f, -0.5f, -0.5f));

    GL_CALL(glNormal3f(0.0f, 1.0f, 0.0f));
    GL_CALL(glVertex3f(0.5f, 0.5f, 0.5f));
    GL_CALL(glVertex3f(0.5f, 0.5f, -0.5f));
    GL_CALL(glVertex3f(-0.5f, 0.5f, -0.5f));
    GL_CALL(glVertex3f(-0.5f, 0.5f, 0.5f));

    GL_CALL(glNormal3f(0.0f, -1.0f, 0.0f));
    GL_CALL(glVertex3f(-0.5f, -0.5f, -0.5f));
    GL_CALL(glVertex3f(0.5f, -0.5f, -0.5f));
    GL_CALL(glVertex3f(0.5f, -0.5f, 0.5f));
    GL_CALL(glVertex3f(-0.5f, -0.5f, 0.5f));

    GL_CALL(glNormal3f(1.0f, 0.0f, 0.0f));
    GL_CALL(glVertex3f(0.5f, 0.5f, 0.5f));
    GL_CALL(glVertex3f(0.5f, -0.5f, 0.5f));
    GL_CALL(glVertex3f(0.5f, -0.5f, -0.5f));
    GL_CALL(glVertex3f(0.5f, 0.5f, -0.5f));

    GL_CALL(glNormal3f(-1.0f, 0.0f, 0.0f));
    GL_CALL(glVertex3f(-0.5f, -0.5f, -0.5f));
    GL_CALL(glVertex3f(-0.5f, -0.5f, 0.5f));
    GL_CALL(glVertex3f(-0.5f, 0.5f, 0.5f));
    GL_CALL(glVertex3f(-0.5f, 0.5f, -0.5f));

    GL_CALL(glEnd());
    GL_CALL(glFlush());
}

void RenderingPipelinesCanvas::PreRender2() 
{
    float points[] = { 0.0f, 0.5f, 0.5f, -0.5f, -0.5f, -0.5f };
    GL_CALL(glGenBuffers(1, &m_vbo));
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, m_vbo));
    GL_CALL(glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW));
    GL_CALL(glGenVertexArrays(1, &m_vao));
    GL_CALL(glBindVertexArray(m_vao));
    GL_CALL(glEnableVertexAttribArray(0));
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, m_vbo));
    GL_CALL(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL));
}

void RenderingPipelinesCanvas::Render2()
{
    GL_CALL(glClearColor(0.0, 0.0, 0.0, 1.0));
    GL_CALL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
    GL_CALL(glDrawArrays(GL_TRIANGLES, 0, 3));
    GL_CALL(glFlush());
}

/**
 * Updates data container (start interval time).
 */
void RenderingPipelinesCanvas::UpdateDataContainerStartIntervalTime(
    DataContainerManagement::IDataContainer& data, 
    const Utilities::DateTime& time)
{
    std::wstring dataItemName = GuiDataItems::Read().GetRenderingPipelinesStartIntervalTime();

    DataContainerManagement::IDataItemSharedPtr dataItem =
        DataContainerManagement::DataItem::Create(
            dataItemName, 
            time);

    data.SetDataItem(dataItem);
}

/**
 * Updates data container (end interval time).
 */
void RenderingPipelinesCanvas::UpdateDataContainerEndIntervalTime(
    DataContainerManagement::IDataContainer& data, 
    const Utilities::DateTime& time)
{
    std::wstring dataItemName = GuiDataItems::Read().GetRenderingPipelinesEndIntervalTime();

    DataContainerManagement::IDataItemSharedPtr dataItem = DataContainerManagement::DataItem::Create(
        dataItemName, 
        time);

    data.SetDataItem(dataItem);
}

/**
 * Updates data from data container.
 * Returns true in case data has been updated.
 */
bool RenderingPipelinesCanvas::UpdateFromDataContainer(DataContainerManagement::IDataContainer& dataContainer)
{
    bool dataUpdated = WXWidgets::GLCanvas::UpdateFromDataContainer(dataContainer);

    std::wstring dataItemStartIntervalTime = GuiDataItems::Read().GetRenderingPipelinesStartIntervalTime();

    if (dataContainer.HasDataItem(dataItemStartIntervalTime)) {
        const DataContainerManagement::IDataItem& dataItem = dataContainer.GetDataItem(dataItemStartIntervalTime);

        const Utilities::DateTime& startIntervalTime = dataItem.GetValue()->GetDateTime();

        bool propertyUpdated = WXWidgets::WXProperty::UpdateSharedValuePtr(
            m_intervalTime->GetStartTime(), 
            startIntervalTime);

        dataUpdated |= propertyUpdated;
    }

    std::wstring dataItemEndIntervalTime = GuiDataItems::Read().GetRenderingPipelinesEndIntervalTime();

    if (dataContainer.HasDataItem(dataItemEndIntervalTime)) {
        const DataContainerManagement::IDataItem& dataItem = dataContainer.GetDataItem(dataItemEndIntervalTime);

        const Utilities::DateTime& endIntervalTime = dataItem.GetValue()->GetDateTime();

        bool propertyUpdated = WXWidgets::WXProperty::UpdateSharedValuePtr(
            m_intervalTime->GetEndTime(), 
            endIntervalTime);

        dataUpdated |= propertyUpdated;
    }

    return dataUpdated;
}

/**
 * Updates component.
 */
void RenderingPipelinesCanvas::Update()
{
    //
    // Update rendering pipelines information...
    //
    m_renderingPipelines = QueryRenderingPipelinesInformation();

    //
    // Render painting...
    //
    RenderPainting();
}

/**
 * Queries rendering pipelines information.
 */
Model::IRenderingPipelineInformationCollectionSharedPtr RenderingPipelinesCanvas::QueryRenderingPipelinesInformation() const
{
    const Model::IDataRepositorySharedPtr dataRepository = m_guiManager.GetDataRepository();
    const Model::IDataQuerySharedPtr dataQuery = dataRepository->GetDataQuery();

    Model::IRenderingPipelineInformationCollectionSharedPtr renderingPipelines = dataQuery->QueryRenderingPipelines(*m_intervalTime);

    return renderingPipelines;
}

/**
 * Gets attributes of canvas.
 */
const int* RenderingPipelinesCanvas::GetAttributes() 
{
    wxGLAttributes attributes;
    attributes.PlatformDefaults().Defaults().EndList();
    return attributes.GetGLAttrs();
}
