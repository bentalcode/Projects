#pragma once

#include "ListView.h"
#include "DateTimeInterval.h"
#include "IRenderingPipelineInformationCollection.h"
#include "Color.h"
#include <map>

namespace VideoRenderingVisualizer {

namespace Gui {

class IGuiManager;

/**
 * The RenderingPipelinesListView class implements a list view of rendering pipelines.
 */
class RenderingPipelinesListView final : public WXWidgets::ListView {
public:
    /**
     * Creates a Rendering Pipelines List View.
     */
    static WXWidgets::IListViewPtr Make(
        wxWindow& parent, 
        const Utilities::DateTimeIntervalSharedPtr intervalTime,
        IGuiManager& guiManager);

    /**
     * The RenderingPipelinesListView constructor.
     */
    RenderingPipelinesListView(
        wxWindow& parent, 
        const Utilities::DateTimeIntervalSharedPtr intervalTime,
        IGuiManager& guiManager);

    /**
     * The RenderingPipelinesListView destructor.
     */
    virtual ~RenderingPipelinesListView();

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
    // Defines the mapping between a rendering status to it's color...
    //
    using RenderingStatusToColorMap = std::map<Model::RenderingStatus, WXWidgets::ColorType>;

    /**
     * Gets a color of rendering status.
     */
    WXWidgets::ColorType GetRenderingStatusColor(Model::RenderingStatus status) const;

    /**
     * Gets the Rendering Status -> Color map.
     */
    const RenderingStatusToColorMap& GetRenderingStatusToColorMap() const;

    /**
     * Initializes the Rendering Status -> Color map.
     */
    static void InitializeRenderingStatusToColorMap(RenderingStatusToColorMap& map);

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
