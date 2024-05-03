#include "WXDataItems.h"
#include "DataItemCatalog.h"

using namespace WXWidgets;

const std::wstring WXDataItems::NAME = L"WXDataItems";
const std::wstring WXDataItems::COMPONENT_SHOW_MODE = L"window/showMode";
const std::wstring WXDataItems::LIST_BOX_ITEMS = L"listBox/items";
const std::wstring WXDataItems::LIST_VIEW_HEADERS = L"listView/headers";
const std::wstring WXDataItems::LIST_VIEW_VALUES = L"listView/values";
const std::wstring WXDataItems::STATIC_TEXT_VALUE = L"staticText/value";
const std::wstring WXDataItems::TEXT_CONTROL_VALUE = L"textControl/value";
const std::wstring WXDataItems::HTML_WINDOW_CONTENT = L"htmlWindow/content";
const std::wstring WXDataItems::SLIDER_DIMENSION_VALUE = L"slider/dimensionValue";
const std::wstring WXDataItems::SLIDER_DIMENSION_MIN_VALUE = L"slider/dimensionMinValue";
const std::wstring WXDataItems::SLIDER_DIMENSION_MAX_VALUE = L"slider/dimensionMaxValue";
const std::wstring WXDataItems::SPLITTER_WINDOW_FIRST_SUB_WINDOW_SHOW_MODE = L"splitterWindow/firstSubWindow/showMode";
const std::wstring WXDataItems::SPLITTER_WINDOW_SECOND_SUB_WINDOW_SHOW_MODE = L"splitterWindow/secondSubWindow/showMode";

/**
 * Reads data item from catalog.
 */
const IWXDataItems& WXDataItems::Read() 
{
    std::wstring dataItemsName = NAME;

    WXWidgets::IDataItemCatalogSharedPtr dataItemCatalog = WXWidgets::DataItemCatalog::GetInstance();

    if (!dataItemCatalog->HasDataItems(dataItemsName)) {
        WXWidgets::IDataItemsSharedPtr dataItems = WXDataItems::Make();
        dataItemCatalog->RegisterDataItems(dataItems);
    }

    return dataItemCatalog->GetDataItems<IWXDataItems>(dataItemsName);
}

/**
 * Creates data items.
 */
IDataItemsSharedPtr WXDataItems::Make()
{
    return std::make_shared<WXDataItems>();
}

/**
 * The WXDataItems constructor.
 */
WXDataItems::WXDataItems()
{
}

/**
 * The WXDataItems destructor.
 */
WXDataItems::~WXDataItems() 
{
}

/**
 * Gets category name of data items.
 */
const std::wstring& WXDataItems::GetName() const
{
    return NAME;
}

/**
 * Gets a component show mode.
 */
const std::wstring& WXDataItems::GetComponentShowMode() const
{
    return COMPONENT_SHOW_MODE;
}

/**
 * Gets a list box items.
 */
const std::wstring& WXDataItems::GetListBoxItems() const
{
    return LIST_BOX_ITEMS;
}

/**
 * Gets a list view headers.
 */
const std::wstring& WXDataItems::GetListViewHeaders() const
{
    return LIST_VIEW_HEADERS;
}

/**
 * Gets a list view values.
 */
const std::wstring& WXDataItems::GetListViewValues() const
{
    return LIST_VIEW_VALUES;
}

/**
 * Gets a text control value.
 */
const std::wstring& WXDataItems::GetTextControlValue() const
{
    return TEXT_CONTROL_VALUE;
}

/**
 * Gets a slider dimension value.
 */
const std::wstring& WXDataItems::GetSliderDimensionValue() const
{
    return SLIDER_DIMENSION_VALUE;
}

/**
 * Gets a slider dimension min value.
 */
const std::wstring& WXDataItems::GetSliderDimensionMinValue() const 
{
    return SLIDER_DIMENSION_MIN_VALUE;
}

/**
 * Gets a slider dimension max value.
 */
const std::wstring& WXDataItems::GetSliderDimensionMaxValue() const 
{
    return SLIDER_DIMENSION_MAX_VALUE;
}

/**
 * Gets a static text value.
 */
const std::wstring& WXDataItems::GetStaticTextValue() const
{
    return STATIC_TEXT_VALUE;
}

/**
 * Gets a html window content.
 */
const std::wstring& WXDataItems::GetHtmlWindowContent() const
{
    return HTML_WINDOW_CONTENT;
}

/**
 * Gets a splitter window first sub-window show node.
 */
const std::wstring& WXDataItems::GetSplitterWindowFirstSubWindowShowMode() const
{
    return SPLITTER_WINDOW_FIRST_SUB_WINDOW_SHOW_MODE;
}

/**
 * Gets a splitter window second sub-window show node.
 */
const std::wstring& WXDataItems::GetSplitterWindowSecondSubWindowShowMode() const
{
    return SPLITTER_WINDOW_SECOND_SUB_WINDOW_SHOW_MODE;
}
