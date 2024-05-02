#include "DateTimeDataItemValue.h"

using namespace DataContainerManagement;

/**
 * Creates a data item of type integer.
 */
IDataItemValueSharedPtr DateTimeDataItemValue::Create(const base::DateTime& value)
{
    return std::make_shared<DateTimeDataItemValue>(value);
}

/**
 * The DateTimeDataItemValue constructor.
 */
DateTimeDataItemValue::DateTimeDataItemValue(const base::DateTime& value) :
    m_value(value) 
{
}

/**
 * The DateTimeDataItemValue destructor.
 */
DateTimeDataItemValue::~DateTimeDataItemValue() 
{
}

/**
 * Gets a date time value of a data item.
 */
const base::DateTime& DateTimeDataItemValue::GetDateTime() const
{
    return m_value;
}

/**
 * Checks whether values are equals.
 */
bool DateTimeDataItemValue::Equals(const IDataItemValue& other) const
{
    return m_value == other.GetDateTime();
}
