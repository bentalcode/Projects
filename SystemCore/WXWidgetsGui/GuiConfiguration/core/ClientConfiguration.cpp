#include "ClientConfiguration.h"
#include "DataContainer.h"
#include "DataItem.h"

using namespace GuiConfiguration;

/**
 * Creates client configuration.
 */
IClientConfigurationSharedPtr ClientConfiguration::Make(const std::wstring& name)
{
    return std::make_shared<ClientConfiguration>(name);
}

/**
 * The ClientConfiguration constructor.
 */
ClientConfiguration::ClientConfiguration(const std::wstring& name) : 
    m_dataContainer(DataContainerManagement::DataContainer::Make(name))
{
}

/**
 * The ClientConfiguration destructor.
 */
ClientConfiguration::~ClientConfiguration() 
{
}

/**
 * Gets name of client.
 */
const std::wstring& ClientConfiguration::GetName() const
{
    return m_dataContainer->GetName();
}

/**
 * Sets a boolean property.
 */
void ClientConfiguration::SetBooleanProperty(const std::wstring& path, bool value) 
{
    SetProperty<bool>(path, value);
}

/**
 * Gets a boolean property.
 */
bool ClientConfiguration::GetBooleanProperty(const std::wstring& path) const
{
    DataContainerManagement::IDataItem& dataItem = m_dataContainer->GetDataItem(path);
    return dataItem.GetValue()->GetBoolean();
}

/**
 * Sets an integer property.
 */
void ClientConfiguration::SetIntegerProperty(const std::wstring& path, int value) 
{
    SetProperty<int>(path, value);
}

/**
 * Gets an integer property.
 */
int ClientConfiguration::GetIntegerProperty(const std::wstring& path) const
{
    DataContainerManagement::IDataItem& dataItem = m_dataContainer->GetDataItem(path);
    return dataItem.GetValue()->GetInteger();
}

/**
 * Sets a long property.
 */
void ClientConfiguration::SetLongProperty(const std::wstring& path, long value)
{
    SetProperty<long>(path, value);
}

/**
 * Gets a long property.
 */
long ClientConfiguration::GetLongProperty(const std::wstring& path) const
{
    DataContainerManagement::IDataItem& dataItem = m_dataContainer->GetDataItem(path);
    return dataItem.GetValue()->GetLong();
}

/**
 * Sets a string property.
 */
void ClientConfiguration::SetStringProperty(const std::wstring& path, const std::wstring& value)
{
    SetProperty<std::wstring>(path, value);
}

/**
 * Gets a string property.
 */
const std::wstring& ClientConfiguration::GetStringProperty(const std::wstring& path) const
{
    DataContainerManagement::IDataItem& dataItem = m_dataContainer->GetDataItem(path);
    return dataItem.GetValue()->GetString();
}

/**
 * Sets a string array property.
 */
void ClientConfiguration::SetStringArrayProperty(
    const std::wstring& path,
    const std::vector<std::wstring>& value)
{
    SetProperty<std::vector<std::wstring>>(path, value);
}

/**
 * Gets a string array property.
 */
const std::vector<std::wstring>& ClientConfiguration::GetStringArrayProperty(const std::wstring& path) const
{
    DataContainerManagement::IDataItem& dataItem = m_dataContainer->GetDataItem(path);
    return dataItem.GetValue()->GetStringArray();
}

/**
 * Sets a string array array property.
 */
void ClientConfiguration::SetStringArrayArrayProperty(const std::wstring& path, const std::vector<std::vector<std::wstring>>& value)
{
    SetProperty<std::vector<std::vector<std::wstring>>>(path, value);
}

/**
 * Gets a string array array property.
 */
const std::vector<std::vector<std::wstring>>& ClientConfiguration::GetStringArrayArrayProperty(const std::wstring& path) const
{
    DataContainerManagement::IDataItem& dataItem = m_dataContainer->GetDataItem(path);
    return dataItem.GetValue()->GetStringArrayArray();
}
