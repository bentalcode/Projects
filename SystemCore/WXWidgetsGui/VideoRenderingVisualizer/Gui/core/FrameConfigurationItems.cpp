#include "FrameConfigurationItems.h"
#include "ConfigurationItemCatalog.h"

using namespace VideoRenderingVisualizer::Gui;

const std::wstring FrameConfigurationItems::NAME = 
    L"FrameConfigurationItems";

const std::wstring FrameConfigurationItems::MAIN_FRAME_NAME = 
    L"Video Rendering Visualizer";

const std::wstring FrameConfigurationItems::MAIN_FRAME_STATUS_TEXT =
    L"Welcome to Video Rendering Visualizer with wxWidgets!";

/**
 * Reads frame configuration items from configuration catalog.
 */
const IFrameConfigurationItems& FrameConfigurationItems::Read()
{
    std::wstring configurationItemsName = NAME;

    GuiConfiguration::IConfigurationItemCatalogSharedPtr configurationItemCatalog =
        GuiConfiguration::ConfigurationItemCatalog::GetInstance();

    if (!configurationItemCatalog->HasConfigurationItems(configurationItemsName)) {
        GuiConfiguration::IConfigurationItemsSharedPtr configurationItems = FrameConfigurationItems::Make();
        configurationItemCatalog->RegisterConfigurationItems(configurationItems);
    }

    return configurationItemCatalog->GetConfigurationItems<IFrameConfigurationItems>(configurationItemsName);
}

/**
 * Creates frame configuration items.
 */
GuiConfiguration::IConfigurationItemsSharedPtr FrameConfigurationItems::Make()
{
    return std::make_shared<FrameConfigurationItems>();
}

/**
 * The FrameConfigurationItems constructor.
 */
FrameConfigurationItems::FrameConfigurationItems() 
{
}

/**
 * The FrameConfigurationItems destructor.
 */
FrameConfigurationItems::~FrameConfigurationItems() 
{
}

/**
 * Gets category name of data items.
 */
const std::wstring& FrameConfigurationItems::GetName() const
{
    return NAME;
}

/**
 * Gets name of main frame.
 */
const std::wstring& FrameConfigurationItems::GetMainFrameName() const
{
    return MAIN_FRAME_NAME;
}

/**
 * Gets status text of main frame.
 */
const std::wstring& FrameConfigurationItems::GetMainFrameStatusText() const
{
    return MAIN_FRAME_STATUS_TEXT;
}
