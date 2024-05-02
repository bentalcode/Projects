#include "DataContainer.h"
#include "DataCatalog.h"
#include "Loggers.h"
#include "DataContainerException.h"

using namespace DataContainerManagement;

/**
 * Creates a data container.
 */
IDataContainerSharedPtr DataContainer::Make(const std::wstring& name)
{
    return std::make_shared<DataContainer>(name);
}

/**
 * The DataContainer constructor.
 */
DataContainer::DataContainer(const std::wstring& name) : 
    m_name(name), 
    m_dataCatalog(DataCatalog::Make()) 
{
}

/**
 * The DataContainer destructor.
 */
DataContainer::~DataContainer() 
{
}

/**
 * Gets name of a data container.
 */
const std::wstring& DataContainer::GetName() const
{
    return m_name;
}

/**
 * Gets a data catalog.
 */
IDataCatalog& DataContainer::GetCatalog()
{
    return *m_dataCatalog;
}

/**
 * Gets a data catalog.
 */
const IDataCatalog& DataContainer::GetCatalog() const
{
    return *m_dataCatalog;
}

/**
 * Sets a data item by name.
 */
void DataContainer::SetDataItem(IDataItemSharedPtr dataItem)
{
    std::wstring name = dataItem->GetName();
    VerifyDataItemInCatalog(name);

    {
        std::lock_guard<std::mutex> lock(m_mutex);

        m_dataItems[name] = dataItem;
    }
}

/**
 * Gets a data item by name.
 */
IDataItem& DataContainer::GetDataItem(const std::wstring& name)
{
    IDataItemSharedPtr dataItem = nullptr;

    {
        std::lock_guard<std::mutex> lock(m_mutex);

        dataItem = FindDataItem(name);
    }

    if (dataItem == nullptr) {
        long errorCode = base::ErrorCodes::RESOURCE_NOT_FOUND;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"Data Container failed finding a data item with name: " << name 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);
        
        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(GetSLogger(), errorMessage);
        throw data_container_exception(errorCode, errorMessage);
    }

    return *dataItem;
}

/**
 * Gets a data item by name.
 */
const IDataItem& DataContainer::GetDataItem(const std::wstring& name) const
{
    IDataItemSharedPtr dataItem = nullptr;

    {
        std::lock_guard<std::mutex> lock(m_mutex);

        dataItem = FindDataItem(name);
    }

    if (dataItem == nullptr) {
        long errorCode = base::ErrorCodes::RESOURCE_NOT_FOUND;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"Data Container failed finding a data item with name: " << name 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(GetSLogger(), errorMessage);
        throw data_container_exception(errorCode, errorMessage);
    }

    return *dataItem;
}

/**
 * Checks whether a data item exists.
 */
bool DataContainer::HasDataItem(const std::wstring& name) const
{
    bool status = false;

    {
        std::lock_guard<std::mutex> lock(m_mutex);

        status = m_dataItems.find(name) != m_dataItems.end();
    }

    return status;
}

/**
 * Gets a collection of data items.
 */
DataItemCollectionSharedPtr DataContainer::GetDataItems() const
{
    DataItemCollectionSharedPtr dataItems = std::make_shared<DataItemCollection>();

    {
        std::lock_guard<std::mutex> lock(m_mutex);
     
        for (const DataItemMap::value_type& entry : m_dataItems) {
            dataItems->push_back(entry.second);
        }
    }

    return dataItems;
}

/**
 * Finds a data item by name.
 */
IDataItemSharedPtr DataContainer::FindDataItem(const std::wstring& name)
{
    DataItemMap::iterator dataItemIterator = m_dataItems.find(name);
    return dataItemIterator != m_dataItems.end() ? dataItemIterator->second : nullptr;
}

/**
 * Finds a data item by name.
 */
const IDataItemSharedPtr DataContainer::FindDataItem(const std::wstring& name) const 
{
    DataItemMap::const_iterator dataItemIterator = m_dataItems.find(name);
    return dataItemIterator != m_dataItems.end() ? dataItemIterator->second : nullptr;
}

/**
 * Verifies data item in catalog.
 */
void DataContainer::VerifyDataItemInCatalog(const std::wstring& name) const 
{
    if (!m_dataCatalog->HasDataItem(name)) {
        long errorCode = base::ErrorCodes::RESOURCE_TEMPLATE_NOT_FOUND;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"Data Container failed finding a data item with name: " << name
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(GetSLogger(), errorMessage);
        throw data_container_exception(errorCode, errorMessage);
    }
}

/**
 * Gets a static logger.
 */
logging::ILoggerSharedPtr DataContainer::GetSLogger()
{
    static logging::ILoggersSharedPtr loggers = logging::Loggers::Make(typeid(DataContainerManagement::DataContainer));
    return loggers->GetLogger();
}
