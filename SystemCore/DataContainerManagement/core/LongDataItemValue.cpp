#include "LongDataItemValue.h"

using namespace DataContainerManagement;

/**
 * Creates a data item of type long.
 */
IDataItemValueSharedPtr LongDataItemValue::Create(long value)
{
    return std::make_shared<LongDataItemValue>(value);
}

/**
 * The LongDataItemValue constructor.
 */
LongDataItemValue::LongDataItemValue(long value) : 
    m_value(value) 
{
}

/**
 * The LongDataItemValue destructor.
 */
LongDataItemValue::~LongDataItemValue() 
{
}

/**
 * Gets a long value of a data item.
 */
long LongDataItemValue::GetLong() const
{
    return m_value;
}

/**
 * Checks whether values are equals.
 */
bool LongDataItemValue::Equals(const IDataItemValue& other) const
{
    return m_value == other.GetLong();
}
