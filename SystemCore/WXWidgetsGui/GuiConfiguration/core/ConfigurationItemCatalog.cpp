#include "ConfigurationItemCatalog.h"
#include "Loggers.h"
#include "GuiConfigurationException.h"

using namespace GuiConfiguration;

IConfigurationItemCatalogSharedPtr ConfigurationItemCatalog::INSTANCE;
std::mutex ConfigurationItemCatalog::MUTEX;

/**
 * Gets an instance of configuration.
 */
IConfigurationItemCatalogSharedPtr ConfigurationItemCatalog::GetInstance()
{
    if (!INSTANCE) {
        std::lock_guard<std::mutex> lock(MUTEX);

        if (!INSTANCE) {
            INSTANCE = Make();
        }
    }

    return INSTANCE;
}

/**
 * Creates a configuration item catalog.
 */
IConfigurationItemCatalogSharedPtr ConfigurationItemCatalog::Make()
{ 
	return std::make_shared<ConfigurationItemCatalog>();
}

/**
 * The ConfigurationItemCatalog constructor.
 */
ConfigurationItemCatalog::ConfigurationItemCatalog() : 
    m_loggers(logging::Loggers::Make(typeid(ConfigurationItemCatalog)))
{
}

/**
 * The ConfigurationItemCatalog destructor.
 */
ConfigurationItemCatalog::~ConfigurationItemCatalog() 
{
}

/**
 * Registers configuration items.
 */
void ConfigurationItemCatalog::RegisterConfigurationItems(IConfigurationItemsSharedPtr configurationItems) 
{
    std::wstring name = configurationItems->GetName();

    std::lock_guard<std::mutex> lock(m_mutex);

    if (FindConfigurationItems(name) != nullptr) {
        long errorCode = base::ErrorCodes::RESOURCE_ALREADY_EXISTS;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"Configuration Items: " << name << L" already defined in catalog" 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);
        
        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(m_loggers->GetLogger(), errorMessage);
        throw GuiConfigurationException(errorCode, errorMessage);
    }

    m_configurationItems.insert(std::make_pair(name, configurationItems));
}

/**
 * Unregisters configuration data items.
 */
void ConfigurationItemCatalog::UnregisterConfigurationItems(const std::wstring& name)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    if (FindConfigurationItems(name) == nullptr) {
        long errorCode = base::ErrorCodes::RESOURCE_NOT_FOUND;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"Configuration Items: " << name << L" are not defined in catalog" 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(m_loggers->GetLogger(), errorMessage);
        throw GuiConfigurationException(errorCode, errorMessage);
    }

    m_configurationItems.erase(name);
}

/**
 * Checks whether configuration items have been registered.
 */
bool ConfigurationItemCatalog::HasConfigurationItems(const std::wstring& name) const
{
    std::lock_guard<std::mutex> lock(m_mutex);
    return FindConfigurationItems(name) != nullptr;
}

/**
 * Gets configuration items.
 */
const IConfigurationItems& ConfigurationItemCatalog::GetConfigurationItems(const std::wstring& name) const
{
    std::lock_guard<std::mutex> lock(m_mutex);

    IConfigurationItemsSharedPtr dataItems = FindConfigurationItems(name);

    if (dataItems == nullptr) {
        long errorCode = base::ErrorCodes::RESOURCE_NOT_FOUND;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"Configuration Items: " << name << L" are not defined in catalog" 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(m_loggers->GetLogger(), errorMessage);
        throw GuiConfigurationException(errorCode, errorMessage);
    }

    return *dataItems;
}

/**
 * Finds configuration data items by name.
 */
const IConfigurationItemsSharedPtr ConfigurationItemCatalog::FindConfigurationItems(const std::wstring& name) const
{
    ConfigurationItemsMap::const_iterator configurationItemsIterator = m_configurationItems.find(name);
    return configurationItemsIterator != m_configurationItems.end() ? configurationItemsIterator->second : nullptr;
}
