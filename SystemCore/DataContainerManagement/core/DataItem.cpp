#include "DataItem.h"
#include "BooleanDataItemValue.h"
#include "DoubleDataItemValue.h"
#include "IntegerDataItemValue.h"
#include "LongDataItemValue.h"
#include "StringDataItemValue.h"
#include "DateTimeDataItemValue.h"
#include "DurationDataItemValue.h"
#include "StringArrayDataItemValue.h"
#include "StringArrayArrayDataItemValue.h"
#include "Loggers.h"
#include "DataContainerException.h"

using namespace DataContainerManagement;

/**
 * Creates a boolean data item.
 */
IDataItemSharedPtr DataItem::Create(
    const std::wstring& name, 
    bool value)
{
    IDataItemValueSharedPtr dataItemValue = BooleanDataItemValue::Create(value);
    return std::make_shared<DataItem>(name, dataItemValue);
}

/**
 * Creates an integer data item.
 */
IDataItemSharedPtr DataItem::Create(
    const std::wstring& name, 
    int value)
{
    IDataItemValueSharedPtr dataItemValue = IntegerDataItemValue::Create(value);
    return std::make_shared<DataItem>(name, dataItemValue);
}

/**
 * Creates a long data item.
 */
IDataItemSharedPtr DataItem::Create(
    const std::wstring& name, 
    long value)
{
    IDataItemValueSharedPtr dataItemValue = LongDataItemValue::Create(value);
    return std::make_shared<DataItem>(name, dataItemValue);
}

/**
 * Creates a double data item.
 */
IDataItemSharedPtr DataItem::Create(
    const std::wstring& name, 
    double value)
{
    IDataItemValueSharedPtr dataItemValue = DoubleDataItemValue::Create(value);
    return std::make_shared<DataItem>(name, dataItemValue);
}

/**
 * Creates a string data item.
 */
IDataItemSharedPtr DataItem::Create(
    const std::wstring& name, 
    const std::wstring& value)
{
    IDataItemValueSharedPtr dataItemValue = StringDataItemValue::Create(value);
    return std::make_shared<DataItem>(name, dataItemValue);
}

/**
 * Creates a date-time data item.
 */
IDataItemSharedPtr DataItem::Create(const std::wstring& name, const base::DateTime& value)
{
    IDataItemValueSharedPtr dataItemValue = DateTimeDataItemValue::Create(value);
    return std::make_shared<DataItem>(name, dataItemValue);
}

/**
 * Creates a duration data item.
 */
IDataItemSharedPtr DataItem::Create(const std::wstring& name, const base::Duration& value)
{
    IDataItemValueSharedPtr dataItemValue = DurationDataItemValue::Create(value);
    return std::make_shared<DataItem>(name, dataItemValue);
}

/**
 * Creates a string array data item.
 */
IDataItemSharedPtr DataItem::Create(
    const std::wstring& name,
    const std::vector<std::wstring>& value)
{
    IDataItemValueSharedPtr dataItemValue = StringArrayDataItemValue::Create(value);
    return std::make_shared<DataItem>(name, dataItemValue);
}

/**
 * Creates a string array array data item.
 */
IDataItemSharedPtr DataItem::Create(
    const std::wstring& name, 
    const std::vector<std::vector<std::wstring>>& value)
{
    IDataItemValueSharedPtr dataItemValue = StringArrayArrayDataItemValue::Create(value);
    return std::make_shared<DataItem>(name, dataItemValue);
}

/**
 * The DataItem constructor.
 */
DataItem::DataItem(
    const std::wstring& name, 
    IDataItemValueSharedPtr value) : 
    m_name(name), 
    m_loggers(logging::Loggers::Make(typeid(DataContainerManagement::DataItem)))
{
    if (!value) {
        long errorCode = base::ErrorCodes::INVALID_ARG;
        
        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"The value of the data item is not defined"
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(m_loggers->GetLogger(), errorMessage);
        throw data_container_exception(errorCode, errorMessage);
    }

    m_value = value;
}

/**
 * The DataItem destructor.
 */
DataItem::~DataItem() 
{
}

/**
 * Gets the name of a data item.
 */
const std::wstring& DataItem::GetName() const
{
    return m_name;
}

/**
 * Gets the value of a data item.
 */
const IDataItemValueSharedPtr DataItem::GetValue() const
{
    return m_value;
}
