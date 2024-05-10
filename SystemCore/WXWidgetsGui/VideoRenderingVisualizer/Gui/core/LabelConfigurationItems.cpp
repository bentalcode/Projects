#include "LabelConfigurationItems.h"
#include "ConfigurationItemCatalog.h"

using namespace VideoRenderingVisualizer::Gui;

const std::wstring LabelConfigurationItems::NAME = L"LabelConfigurationItems";

const std::wstring LabelConfigurationItems::MAIN_LEFT_WINDOW_LABEL = L"";
const std::wstring LabelConfigurationItems::MAIN_RIGHT_WINDOW_LABEL = L"";

const std::wstring LabelConfigurationItems::MAIN_LEFT_TOP_WINDOW_LABEL = L"";
const std::wstring LabelConfigurationItems::MAIN_LEFT_BOTTOM_WINDOW_LABEL = L"Compositor";

const std::wstring LabelConfigurationItems::MAIN_LEFT_TOP_WINDOW_UPPER_SUB_WINDOW_LABEL = L"Calls";
const std::wstring LabelConfigurationItems::MAIN_LEFT_TOP_WINDOW_LOWER_SUB_WINDOW_LABEL = L"Compositors";

const std::wstring LabelConfigurationItems::MAIN_RIGHT_TOP_WINDOW_LABEL = L"Visualizer";
const std::wstring LabelConfigurationItems::MAIN_RIGHT_BOTTOM_WINDOW_LABEL = L"Rendering Pipelines";

const std::wstring LabelConfigurationItems::MAIN_RIGHT_TOP_WINDOW_UPPER_SUB_WINDOW_LABEL = L"";
const std::wstring LabelConfigurationItems::MAIN_RIGHT_TOP_WINDOW_LOWER_SUB_WINDOW_LABEL = L"";

/**
 * Reads label configuration items from configuration.
 */
const ILabelConfigurationItems& LabelConfigurationItems::Read()
{
    std::wstring configurationItemsName = NAME;

    GuiConfiguration::IConfigurationItemCatalogSharedPtr configurationItemCatalog =
        GuiConfiguration::ConfigurationItemCatalog::GetInstance();

    if (!configurationItemCatalog->HasConfigurationItems(configurationItemsName)) {
        GuiConfiguration::IConfigurationItemsSharedPtr configurationItems = LabelConfigurationItems::Make();
        configurationItemCatalog->RegisterConfigurationItems(configurationItems);
    }

    return configurationItemCatalog->GetConfigurationItems<ILabelConfigurationItems>(configurationItemsName);
}

/**
 * Creates label configuration items.
 */
GuiConfiguration::IConfigurationItemsSharedPtr LabelConfigurationItems::Make()
{
    return std::make_shared<LabelConfigurationItems>();
}

/**
 * The LabelConfigurationItems constructor.
 */
LabelConfigurationItems::LabelConfigurationItems() 
{
}

/**
 * The LabelConfigurationItems destructor.
 */
LabelConfigurationItems::~LabelConfigurationItems() 
{
}

/**
 * Gets category name of data items.
 */
const std::wstring& LabelConfigurationItems::GetName() const
{
    return NAME;
}

/**
 * Gets label of main left window.
 */
const std::wstring& LabelConfigurationItems::GetMainLeftWindowLabel() const
{
    return MAIN_LEFT_WINDOW_LABEL;
}

/**
 * Gets label of main right bottom window.
 */
const std::wstring& LabelConfigurationItems::GetMainRightWindowLabel() const
{
    return MAIN_RIGHT_WINDOW_LABEL;
}

/**
 * Gets label of main left top window.
 */
const std::wstring& LabelConfigurationItems::GetMainLeftTopWindowLabel() const
{
    return MAIN_LEFT_TOP_WINDOW_LABEL;
}

/**
 * Gets label of main left bottom window.
 */
const std::wstring& LabelConfigurationItems::GetMainLeftBottomWindowLabel() const
{
    return MAIN_LEFT_BOTTOM_WINDOW_LABEL;
}

/**
 * Gets label of main left top window - upper sub window.
 */
const std::wstring& LabelConfigurationItems::GetMainLeftTopWindowUpperSubWindowLabel() const
{
    return MAIN_LEFT_TOP_WINDOW_UPPER_SUB_WINDOW_LABEL;
}

/**
 * Gets label of main left top window - lower sub window.
 */
const std::wstring& LabelConfigurationItems::GetMainLeftTopWindowLowerSubWindowLabel() const
{
    return MAIN_LEFT_TOP_WINDOW_LOWER_SUB_WINDOW_LABEL;
}

/**
 * Gets label of main right top window.
 */
const std::wstring& LabelConfigurationItems::GetMainRightTopWindowLabel() const 
{
    return MAIN_RIGHT_TOP_WINDOW_LABEL;
}

/**
 * Gets label of main right bottom window.
 */
const std::wstring& LabelConfigurationItems::GetMainRightBottomWindowLabel() const 
{
    return MAIN_RIGHT_BOTTOM_WINDOW_LABEL;
}

/**
 * Gets label of main right top window - upper sub window.
 */
const std::wstring& LabelConfigurationItems::GetMainRightTopWindowUpperSubWindowLabel() const 
{
    return MAIN_RIGHT_TOP_WINDOW_UPPER_SUB_WINDOW_LABEL;
}

/**
 * Gets label of main right top window - lower sub window.
 */
const std::wstring& LabelConfigurationItems::GetMainRightTopWindowLowerSubWindowLabel() const 
{
    return MAIN_RIGHT_TOP_WINDOW_LOWER_SUB_WINDOW_LABEL;
}
