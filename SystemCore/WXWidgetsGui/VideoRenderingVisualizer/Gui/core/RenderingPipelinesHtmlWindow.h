#pragma once

#include "HtmlWindow.h"
#include "DateTimeInterval.h"
#include "IRenderingPipelineInformationCollection.h"

namespace VideoRenderingVisualizer {

namespace Gui {

class IGuiManager;

/**
 * The RenderingPipelinesHtmlWindow class implements a list view of rendering pipelines.
 */
class RenderingPipelinesHtmlWindow final : public WXWidgets::HtmlWindow {
public:
    /**
     * Creates a Rendering Pipelines Html Window.
     */
    static WXWidgets::IHtmlWindowPtr Make(
        wxWindow& parent, 
        const Utilities::DateTimeIntervalSharedPtr intervalTime,
        IGuiManager& guiManager);

    /**
     * The RenderingPipelinesHtmlWindow constructor.
     */
    RenderingPipelinesHtmlWindow(
        wxWindow& parent, 
        const Utilities::DateTimeIntervalSharedPtr intervalTime,
        IGuiManager& guiManager);

    /**
     * The RenderingPipelinesHtmlWindow destructor.
     */
    virtual ~RenderingPipelinesHtmlWindow();

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

private:
    /**
     * Initializes a GUI component.
     */
    void Initialize(IGuiManager& guiManager);

    /**
     * Resets component.
     */
    void Reset();

    /**
     * Queries rendering pipelines information.
     */
    Model::IRenderingPipelineInformationCollectionSharedPtr QueryRenderingPipelinesInformation() const;

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
    // The interval time for displaying rendering pipelines...
    //
    Utilities::DateTimeIntervalSharedPtr m_intervalTime;

    //
    // The effective rendering pipelines...
    //
    Model::IRenderingPipelineInformationCollectionSharedPtr m_renderingPipelines;
};

}  // namespace Gui

}  // namespace VideoRenderingVisualizer
