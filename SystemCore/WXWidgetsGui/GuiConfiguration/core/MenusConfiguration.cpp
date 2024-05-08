#include "MenusConfiguration.h"
#include "Loggers.h"
#include "GuiConfigurationException.h"

using namespace GuiConfiguration;

/**
 * Creates menus configuration.
 */
IMenusConfigurationSharedPtr MenusConfiguration::Make()
{
    return std::make_shared<MenusConfiguration>();
}

/**
 * The MenusConfiguration constructor.
 */
MenusConfiguration::MenusConfiguration() 
{
}

/**
 * The MenusConfiguration destructor.
 */
MenusConfiguration::~MenusConfiguration() 
{
}

/**
 * Adds a menu configuration by path.
 */
void MenusConfiguration::AddMenuConfiguration(
    const std::wstring& path, 
    IMenuConfigurationSharedPtr configuration)
{
    if (MenuConfigurationExists(path)) {
        long errorCode = base::ErrorCodes::RESOURCE_ALREADY_EXISTS;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"Menu configuration with path: " << path << L" is already defined" 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(GetSLogger(), errorMessage);
        throw GuiConfigurationException(errorCode, errorMessage);
    }

    m_menuConfigurationMap.insert(std::make_pair(path, configuration));
}

/**
 * Gets a menu configuration by path.
 */
const IMenuConfigurationSharedPtr MenusConfiguration::GetMenuConfiguration(const std::wstring& path) const
{
    IMenuConfigurationSharedPtr configuration = FindMenuConfiguration(path);

    if (configuration == nullptr) {
        long errorCode = base::ErrorCodes::RESOURCE_NOT_FOUND;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"Menu configuration with path: " << path << L" has not been found" 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(GetSLogger(), errorMessage);
        throw GuiConfigurationException(errorCode, errorMessage);
    }

    return configuration;
}

/**
 * Checks whether a menu configuration exists.
 */
bool MenusConfiguration::MenuConfigurationExists(const std::wstring& path) const
{
    return m_menuConfigurationMap.find(path) != m_menuConfigurationMap.end();
}

/**
 * Finds a menu configuration by path.
 */
const IMenuConfigurationSharedPtr MenusConfiguration::FindMenuConfiguration(const std::wstring& path) const
{
    MenuConfigurationMap::const_iterator configurationIterator = m_menuConfigurationMap.find(path);

    if (configurationIterator == m_menuConfigurationMap.end()) {
        return nullptr;
    }

    return configurationIterator->second;
}

/**
 * Gets a static logger.
 */
logging::ILoggerSharedPtr MenusConfiguration::GetSLogger()
{
    static logging::ILoggersSharedPtr loggers = logging::Loggers::Make(typeid(GuiConfiguration::MenusConfiguration));
    return loggers->GetLogger();
}
