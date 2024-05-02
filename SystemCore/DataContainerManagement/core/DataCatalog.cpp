#include "DataCatalog.h"
#include "DataContainerException.h"
#include "Loggers.h"

using namespace DataContainerManagement;

/**
 * Creates data catalog.
 */
IDataCatalogSharedPtr DataCatalog::Make()
{
    return std::make_shared<DataCatalog>();
}

/**
 * The DataCatalog constructor.
 */
DataCatalog::DataCatalog() 
{
}

/**
 * The DataCatalog destructor.
 */
DataCatalog::~DataCatalog() 
{
}

/**
 * Registers data item.
 */
void DataCatalog::RegisterDataItem(const std::wstring& name)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    if (Exists(name)) {
        long errorCode = base::ErrorCodes::RESOURCE_ALREADY_EXISTS;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"Data Catalog already contains data item with name: " << name
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(GetSLogger(), errorMessage);
        throw data_container_exception(errorCode, errorMessage);
    }

    m_dataItems.insert(name);
}

/**
 * Unregisters data item.
 */
void DataCatalog::UnregisterDataItem(const std::wstring& name)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    if (!Exists(name)) {
        long errorCode = base::ErrorCodes::RESOURCE_NOT_FOUND;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"Gui Controller does not contain data item with name: " << name 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(GetSLogger(), errorMessage);
        throw data_container_exception(errorCode, errorMessage);
    }

    m_dataItems.erase(name);
}

/**
 * Checks whether a data item exists.
 */
bool DataCatalog::HasDataItem(const std::wstring& name) const
{
    std::lock_guard<std::mutex> lock(m_mutex);
    return Exists(name);
}

/**
 * Checks whether a data item exists.
 */
bool DataCatalog::Exists(const std::wstring& name) const
{
    DataItemSet::const_iterator dataItemIterator = m_dataItems.find(name);
    return dataItemIterator != m_dataItems.end();
}

/**
 * Gets a static logger.
 */
logging::ILoggerSharedPtr DataCatalog::GetSLogger()
{
    static logging::ILoggersSharedPtr loggers = logging::Loggers::Make(typeid(DataContainerManagement::DataCatalog));
    return loggers->GetLogger();
}
