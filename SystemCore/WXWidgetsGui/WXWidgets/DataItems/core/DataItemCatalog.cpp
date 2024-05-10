#include "DataItemCatalog.h"
#include "Loggers.h"
#include "WXWidgetsException.h"

using namespace wxwidgets;

IDataItemCatalogSharedPtr DataItemCatalog::INSTANCE;
std::mutex DataItemCatalog::MUTEX;

/**
 * Gets an instance of configuration.
 */
IDataItemCatalogSharedPtr DataItemCatalog::GetInstance()
{
    if (!INSTANCE) {
        std::lock_guard<std::mutex> lock(MUTEX);

        if (!INSTANCE) {
            INSTANCE = DataItemCatalog::Make();
        }
    }

    return INSTANCE;
}

/**
 * Creates a data item catalog
 */
IDataItemCatalogSharedPtr DataItemCatalog::Make()
{ 
	return std::make_shared<DataItemCatalog>();
}

/**
 * The DataItemCatalog constructor.
 */
DataItemCatalog::DataItemCatalog() : 
    m_loggers(logging::Loggers::Make(typeid(DataItemCatalog)))
{
}

/**
 * The DataItemCatalog destructor.
 */
DataItemCatalog::~DataItemCatalog() 
{
}

/**
 * Registers data items.
 */
void DataItemCatalog::RegisterDataItems(IDataItemsSharedPtr dataItems) 
{
    std::wstring name = dataItems->GetName();

    std::lock_guard<std::mutex> lock(m_mutex);

    if (FindDataItems(name) != nullptr) {
        long errorCode = base::ErrorCodes::RESOURCE_ALREADY_EXISTS;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"Data Items: " << name << L" already defined in catalog" 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(m_loggers->GetLogger(), errorMessage);
        throw WXWidgetsException(errorCode, errorMessage);
    }

    m_dataItems.insert(std::make_pair(name, dataItems));
}

/**
 * Unregisters data items.
 */
void DataItemCatalog::UnregisterDataItems(const std::wstring& name)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    if (FindDataItems(name) == nullptr) {
        long errorCode = base::ErrorCodes::RESOURCE_NOT_FOUND;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"Data Items: " << name << L" are not defined in catalog" 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(m_loggers->GetLogger(), errorMessage);
        throw WXWidgetsException(errorCode, errorMessage);
    }

    m_dataItems.erase(name);
}

/**
 * Checks whether data items have been registered.
 */
bool DataItemCatalog::HasDataItems(const std::wstring& name) const
{
    std::lock_guard<std::mutex> lock(m_mutex);
    return FindDataItems(name) != nullptr;
}

/**
 * Gets data items.
 */
const IDataItems& DataItemCatalog::GetDataItems(const std::wstring& name) const
{
    std::lock_guard<std::mutex> lock(m_mutex);

    IDataItemsSharedPtr dataItems = FindDataItems(name);

    if (dataItems == nullptr) {
        long errorCode = base::ErrorCodes::RESOURCE_NOT_FOUND;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"Data Items: " << name << L" are not defined in catalog" 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(m_loggers->GetLogger(), errorMessage);
        throw WXWidgetsException(errorCode, errorMessage);
    }

    return *dataItems;
}

/**
 * Finds data items by name.
 */
const IDataItemsSharedPtr DataItemCatalog::FindDataItems(const std::wstring& name) const
{
    DataItemsMap::const_iterator dataItemsIterator = m_dataItems.find(name);
    return dataItemsIterator != m_dataItems.end() ? dataItemsIterator->second : nullptr;
}
