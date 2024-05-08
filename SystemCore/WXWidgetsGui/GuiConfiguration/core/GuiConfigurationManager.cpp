#include "GuiConfigurationManager.h"
#include "SmartPointers.h"

using namespace GuiConfiguration;

/**
 * Creates a GUI configuration manager.
 */
IGuiConfigurationManagerSharedPtr GuiConfigurationManager::Make()
{
    return std::make_shared<GuiConfigurationManager>();
}

/**
 * The GuiConfigurationManager constructor.
 */
GuiConfigurationManager::GuiConfigurationManager() 
{
}

/**
 * The GuiConfiguration destructor.
 */
GuiConfigurationManager::~GuiConfigurationManager() 
{
}

/**
 * Sets configuration of app.
 */
void GuiConfigurationManager::SetAppConfiguration(IAppConfigurationSharedPtr configuration)
{
    base::SmartPointers::Validate<IAppConfiguration>(configuration);
    m_appConfiguration = configuration;
}

/**
 * Sets configuration of client.
 */
void GuiConfigurationManager::SetClientConfiguration(IClientConfigurationSharedPtr configuration)
{
    base::SmartPointers::Validate<IClientConfiguration>(configuration);
    m_clientConfiguration = configuration;
}

/**
 * Sets configuration of frames.
 */
void GuiConfigurationManager::SetFramesConfiguration(IFramesConfigurationSharedPtr configuration)
{
    base::SmartPointers::Validate<IFramesConfiguration>(configuration);
    m_framesConfiguration = configuration;
}

/**
 * Sets configuration of dialogs.
 */
void GuiConfigurationManager::SetDialogsConfiguration(IDialogsConfigurationSharedPtr configuration)
{
    base::SmartPointers::Validate<IDialogsConfiguration>(configuration);
    m_dialogsConfiguration = configuration;
}

/**
 * Sets configuration of menus.
 */
void GuiConfigurationManager::SetMenusConfiguration(IMenusConfigurationSharedPtr configuration)
{
    base::SmartPointers::Validate<IMenusConfiguration>(configuration);
    m_menusConfiguration = configuration;
}

/**
 * Sets configuration of menu items.
 */
void GuiConfigurationManager::SetMenuItemsConfiguration(IMenuItemsConfigurationSharedPtr configuration)
{
    base::SmartPointers::Validate<IMenuItemsConfiguration>(configuration);
    m_menuItemsConfiguration = configuration;
}

/**
 * Sets configuration of sliders.
 */
void GuiConfigurationManager::SetSlidersConfiguration(ISlidersConfigurationSharedPtr configuration)
{
    base::SmartPointers::Validate<ISlidersConfiguration>(configuration);
    m_slidersConfiguration = configuration;
}

/**
 * Sets configuration of labels.
 */
void GuiConfigurationManager::SetLabelsConfiguration(ILabelsConfigurationSharedPtr configuration)
{
    base::SmartPointers::Validate<ILabelsConfiguration>(configuration);
    m_labelsConfiguration = configuration;
}

/**
 * Gets configuration of app.
 */
IAppConfigurationSharedPtr GuiConfigurationManager::GetAppConfiguration() const
{
    return m_appConfiguration;
}

/**
 * Gets configuration of client.
 */
IClientConfigurationSharedPtr GuiConfigurationManager::GetClientConfiguration() const
{
    return m_clientConfiguration;
}

/**
 * Gets configuration of frames.
 */
IFramesConfigurationSharedPtr GuiConfigurationManager::GetFramesConfiguration() const
{
    return m_framesConfiguration;
}

/**
 * Gets configuration of dialogs.
 */
IDialogsConfigurationSharedPtr GuiConfigurationManager::GetDialogsConfiguration() const
{
    return m_dialogsConfiguration;
}

/**
 * Gets configuration of menus.
 */
IMenusConfigurationSharedPtr GuiConfigurationManager::GetMenusConfiguration() const
{
    return m_menusConfiguration;
}

/**
 * Gets configuration of menu items.
 */
IMenuItemsConfigurationSharedPtr GuiConfigurationManager::GetMenuItemsConfiguration() const
{
    return m_menuItemsConfiguration;
}

/**
 * Gets configuration of sliders.
 */
ISlidersConfigurationSharedPtr GuiConfigurationManager::GetSlidersConfiguration() const
{
    return m_slidersConfiguration;
}

/**
 * Gets configuration of labels.
 */
ILabelsConfigurationSharedPtr GuiConfigurationManager::GetLabelsConfiguration() const
{
    return m_labelsConfiguration;
}
