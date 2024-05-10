#include "GuiDataItems.h"
#include "DataItemCatalog.h"
#include "AppConfigurationItems.h"

using namespace VideoRenderingVisualizer::Gui;

const std::wstring GuiDataItems::COMPOSITOR_ID = 
    L"compositors/compositorId";

const std::wstring GuiDataItems::EVENTS_START_INTERVAL_TIME = 
    L"events/startIntervalTime";

const std::wstring GuiDataItems::EVENTS_END_INTERVAL_TIME = 
    L"events/endIntervalTime";

const std::wstring GuiDataItems::RENDERING_PIPELINES_START_INTERVAL_TIME =
    L"renderingPipelines/startIntervalTime";

const std::wstring GuiDataItems::RENDERING_PIPELINES_END_INTERVAL_TIME =
    L"renderingPipelines/endIntervalTime";

/**
 * Reads GUI data items from data item catalog.
 */
const IGuiDataItems& GuiDataItems::Read() 
{ 
    std::wstring dataItemsName = AppConfigurationItems::Read().GetAppName();

    WXWidgets::IDataItemCatalogSharedPtr dataItemCatalog = WXWidgets::DataItemCatalog::GetInstance();

    if (!dataItemCatalog->HasDataItems(dataItemsName)) {
        WXWidgets::IDataItemsSharedPtr dataItems = GuiDataItems::Make();
        dataItemCatalog->RegisterDataItems(dataItems);
    }

    return dataItemCatalog->GetDataItems<IGuiDataItems>(dataItemsName);
}

/**
 * Creates GUI data items.
 */
WXWidgets::IDataItemsSharedPtr GuiDataItems::Make()
{
    return std::make_shared<GuiDataItems>();
}

/**
 * The GuiDataItems constructor.
 */
GuiDataItems::GuiDataItems()
{
}

/**
 * The GuiDataItems destructor.
 */
GuiDataItems::~GuiDataItems() 
{
}

/**
 * Gets category name of data items.
 */
const std::wstring& GuiDataItems::GetName() const 
{
    return AppConfigurationItems::Read().GetAppName();
}

/**
 * Gets a compositor id.
 */
const std::wstring& GuiDataItems::GetCompositorId() const 
{
    return COMPOSITOR_ID;
}

/**
 * Gets events start interval time.
 */
const std::wstring& GuiDataItems::GetEventsStartIntervalTime() const
{
    return EVENTS_START_INTERVAL_TIME;
}

/**
 * Gets events end interval time.
 */
const std::wstring& GuiDataItems::GetEventsEndIntervalTime() const
{
    return EVENTS_END_INTERVAL_TIME;
}

/**
 * Gets rendering pipelines start interval time.
 */
const std::wstring& GuiDataItems::GetRenderingPipelinesStartIntervalTime() const
{
    return RENDERING_PIPELINES_START_INTERVAL_TIME;
}

/**
 * Gets rendering pipelines end interval time.
 */
const std::wstring& GuiDataItems::GetRenderingPipelinesEndIntervalTime() const
{
    return RENDERING_PIPELINES_END_INTERVAL_TIME;
}
