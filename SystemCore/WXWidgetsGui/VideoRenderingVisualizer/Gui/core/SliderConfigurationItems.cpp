#include "SliderConfigurationItems.h"
#include "ConfigurationItemCatalog.h"

using namespace VideoRenderingVisualizer::Gui;

const std::wstring SliderConfigurationItems::NAME = L"SliderConfigurationItems";
const unsigned int SliderConfigurationItems::MAIN_RIGHT_TOP_WINDOW_LOWER_SUB_WINDOW_SLIDER_MIN_NUMBER_OF_UNITS = 100;
const unsigned int SliderConfigurationItems::MAIN_RIGHT_TOP_WINDOW_LOWER_SUB_WINDOW_SLIDER_MAX_NUMBER_OF_UNITS = 1000;


/**
 * Reads slider configuration items from configuration.
 */
const ISliderConfigurationItems& SliderConfigurationItems::Read()
{
    std::wstring configurationItemsName = NAME;

    GuiConfiguration::IConfigurationItemCatalogSharedPtr configurationItemCatalog =
        GuiConfiguration::ConfigurationItemCatalog::GetInstance();

    if (!configurationItemCatalog->HasConfigurationItems(configurationItemsName)) {
        GuiConfiguration::IConfigurationItemsSharedPtr configurationItems = SliderConfigurationItems::Make();
        configurationItemCatalog->RegisterConfigurationItems(configurationItems);
    }

    return configurationItemCatalog->GetConfigurationItems<ISliderConfigurationItems>(configurationItemsName);
}

/**
 * Creates slider configuration items.
 */
GuiConfiguration::IConfigurationItemsSharedPtr SliderConfigurationItems::Make()
{
    return std::make_shared<SliderConfigurationItems>();
}

/**
 * The SliderConfigurationItems constructor.
 */
SliderConfigurationItems::SliderConfigurationItems() 
{
}

/**
 * The SliderConfigurationItems destructor.
 */
SliderConfigurationItems::~SliderConfigurationItems() 
{
}

/**
 * Gets category name of data items.
 */
const std::wstring& SliderConfigurationItems::GetName() const
{
    return NAME;
}

/**
 * Gets name of main right top window lower sub window - slider min number of units.
 */
const unsigned int SliderConfigurationItems::GetMainRightTopWindowLowerSubWindowSliderMinNumberOfUnits() const
{
    return MAIN_RIGHT_TOP_WINDOW_LOWER_SUB_WINDOW_SLIDER_MIN_NUMBER_OF_UNITS;
}

/**
 * Gets name of main right top window lower sub window - slider max number of units.
 */
const unsigned int SliderConfigurationItems::GetMainRightTopWindowLowerSubWindowSliderMaxNumberOfUnits() const
{
    return MAIN_RIGHT_TOP_WINDOW_LOWER_SUB_WINDOW_SLIDER_MAX_NUMBER_OF_UNITS;
}
