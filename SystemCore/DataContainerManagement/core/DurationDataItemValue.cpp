#include "DurationDataItemValue.h"

using namespace DataContainerManagement;

/**
 * Creates a data item of type duration.
 */
IDataItemValueSharedPtr DurationDataItemValue::Create(const base::Duration& value)
{
    return std::make_shared<DurationDataItemValue>(value);
}

/**
 * The DurationDataItemValue constructor.
 */
DurationDataItemValue::DurationDataItemValue(const base::Duration& value) :
    m_value(value) 
{
}

/**
 * The DurationDataItemValue destructor.
 */
DurationDataItemValue::~DurationDataItemValue() 
{
}

/**
 * Gets a duration value of a data item.
 */
const base::Duration& DurationDataItemValue::GetDuration() const
{
    return m_value;
}

/**
 * Checks whether values are equals.
 */
bool DurationDataItemValue::Equals(const IDataItemValue& other) const
{
    return m_value == other.GetDuration();
}
