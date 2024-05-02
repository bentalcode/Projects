#include "BooleanDataItemValue.h"

using namespace DataContainerManagement;

/**
 * Creates a data item of type boolean.
 */
IDataItemValueSharedPtr BooleanDataItemValue::Create(bool value)
{
    return std::make_shared<BooleanDataItemValue>(value);
}

/**
 * The BooleanDataItemValue constructor.
 */
BooleanDataItemValue::BooleanDataItemValue(bool value) : 
    m_value(value) 
{
}

/**
 * The BooleanDataItemValue destructor.
 */
BooleanDataItemValue::~BooleanDataItemValue() 
{
}

/**
 * Gets a boolean value of a data item.
 */
bool BooleanDataItemValue::GetBoolean() const
{
    return m_value;
}

/**
 * Checks whether values are equals.
 */
bool BooleanDataItemValue::Equals(const IDataItemValue& other) const
{
    return m_value == other.GetBoolean();
}
