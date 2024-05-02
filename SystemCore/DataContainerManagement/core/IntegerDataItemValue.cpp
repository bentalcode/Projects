#include "IntegerDataItemValue.h"

using namespace DataContainerManagement;

/**
 * Creates a data item of type integer.
 */
IDataItemValueSharedPtr IntegerDataItemValue::Create(int value)
{
    return std::make_shared<IntegerDataItemValue>(value);
}

/**
 * The IntegerDataItemValue constructor.
 */
IntegerDataItemValue::IntegerDataItemValue(int value) : 
    m_value(value) 
{
}

/**
 * The IntegerDataItemValue destructor.
 */
IntegerDataItemValue::~IntegerDataItemValue() 
{
}

/**
 * Gets an integer value of a data item.
 */
int IntegerDataItemValue::GetInteger() const
{
    return m_value;
}

/**
 * Checks whether values are equals.
 */
bool IntegerDataItemValue::Equals(const IDataItemValue& other) const
{
    return m_value == other.GetInteger();
}
