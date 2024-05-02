#include "StringArrayArrayDataItemValue.h"
#include "CollectionComparator.h"

using namespace DataContainerManagement;

/**
 * Creates a data item of type array of string array.
 */
IDataItemValueSharedPtr StringArrayArrayDataItemValue::Create(const std::vector<std::vector<std::wstring>>& values)
{
    return std::make_shared<StringArrayArrayDataItemValue>(values);
}

/**
 * The StringArrayArrayDataItemValue constructor.
 */
StringArrayArrayDataItemValue::StringArrayArrayDataItemValue(const std::vector<std::vector<std::wstring>>& values) : 
    m_values(values) 
{
}

/**
 * The StringArrayArrayDataItemValue destructor.
 */
StringArrayArrayDataItemValue::~StringArrayArrayDataItemValue() 
{
}

/**
 * Gets an array of string array value of a data item.
 */
const std::vector<std::vector<std::wstring>>& StringArrayArrayDataItemValue::GetStringArrayArray() const
{
    return m_values;
}

/**
 * Checks whether values are equals.
 */
bool StringArrayArrayDataItemValue::Equals(const IDataItemValue& other) const
{
    base::CollectionComparatorSharedPtr<std::vector<std::vector<std::wstring>>> comparator =
        base::CollectionComparator<std::vector<std::vector<std::wstring>>>::Make();

    return comparator->AreEqual(m_values, other.GetStringArrayArray());
}
