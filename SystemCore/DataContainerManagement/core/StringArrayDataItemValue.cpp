#include "StringArrayDataItemValue.h"
#include "CollectionComparator.h"

using namespace DataContainerManagement;

/**
 * Creates a data item of type string array.
 */
IDataItemValueSharedPtr StringArrayDataItemValue::Create(const std::vector<std::wstring>& values)
{
    return std::make_shared<StringArrayDataItemValue>(values);
}

/**
 * The StringArrayDataItemValue constructor.
 */
StringArrayDataItemValue::StringArrayDataItemValue(const std::vector<std::wstring>& values) : 
    m_values(values) 
{
}

/**
 * The StringArrayDataItemValue destructor.
 */
StringArrayDataItemValue::~StringArrayDataItemValue() 
{
}

/**
 * Gets a string array value of a data item.
 */
const std::vector<std::wstring>& StringArrayDataItemValue::GetStringArray() const
{
    return m_values;
}

/**
 * Checks whether values are equals.
 */
bool StringArrayDataItemValue::Equals(const IDataItemValue& other) const
{
    base::CollectionComparatorSharedPtr<std::vector<std::wstring>> comparator =
        base::CollectionComparator<std::vector<std::wstring>>::Make();

    return comparator->AreEqual(m_values, other.GetStringArray());
}
