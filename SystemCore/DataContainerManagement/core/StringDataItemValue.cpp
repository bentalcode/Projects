#include "StringDataItemValue.h"

using namespace DataContainerManagement;

/**
 * Creates a data item of type string.
 */
IDataItemValueSharedPtr StringDataItemValue::Create(const std::wstring& value)
{
    return std::make_shared<StringDataItemValue>(value);
}

/**
 * The StringDataItemValue constructor.
 */
StringDataItemValue::StringDataItemValue(const std::wstring& value) : 
    m_value(value) 
{
}

/**
 * The StringDataItemValue destructor.
 */
StringDataItemValue::~StringDataItemValue() 
{
}

/**
 * Gets a string value of a data item.
 */
const std::wstring& StringDataItemValue::GetString() const
{
    return m_value;
}

/**
 * Checks whether values are equals.
 */
bool StringDataItemValue::Equals(const IDataItemValue& other) const
{
    return m_value == other.GetString();
}
