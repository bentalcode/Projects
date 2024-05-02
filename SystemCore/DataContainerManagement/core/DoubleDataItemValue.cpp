#include "DoubleDataItemValue.h"

using namespace DataContainerManagement;

/**
 * Creates a data item of type double.
 */
IDataItemValueSharedPtr DoubleDataItemValue::Create(double value)
{
    return std::make_shared<DoubleDataItemValue>(value);
}

/**
 * The DoubleDataItemValue constructor.
 */
DoubleDataItemValue::DoubleDataItemValue(double value) : 
    m_value(value) 
{
}

/**
 * The DoubleDataItemValue destructor.
 */
DoubleDataItemValue::~DoubleDataItemValue() 
{
}

/**
 * Gets a double value of a data item.
 */
double DoubleDataItemValue::GetDouble() const
{
    return m_value;
}

/**
 * Checks whether values are equals.
 */
bool DoubleDataItemValue::Equals(const IDataItemValue& other) const
{
    return m_value == other.GetDouble();
}
