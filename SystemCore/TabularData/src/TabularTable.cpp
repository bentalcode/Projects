#include "TabularTable.h"
#include "SmartPointers.h"

using namespace TabularData;

/**
 * Creates a Tabular Table.
 */
ITabularTableSharedPtr TabularTable::Make(
    const ITabularHeaderSharedPtr header,
    base::IIteratorSharedPtr<ITabularRecordSharedPtr> recordIterator)
{
    return std::make_shared<TabularTable>(header, recordIterator);
}

/**
 * The TabularTable constructor.
 */
TabularTable::TabularTable(
    const ITabularHeaderSharedPtr header,
    base::IIteratorSharedPtr<ITabularRecordSharedPtr> recordIterator)
{
    base::SmartPointers::Validate<ITabularHeader>(header);
    base::SmartPointers::Validate<base::IIterator<ITabularRecordSharedPtr>>(recordIterator);

    m_header = header;
    m_recordIterator = recordIterator;
}

/**
 * The TabularTable destructor.
 */
TabularTable::~TabularTable() 
{
}

/**
 * Gets a header of tabular table.
 */
const ITabularHeaderSharedPtr TabularTable::GetHeader() const
{
    return m_header;
}

/**
 * Gets an iterator of records of tabular table.
 */
base::IIteratorSharedPtr<ITabularRecordSharedPtr> TabularTable::GetRecordIterator() const
{
    return m_recordIterator;
}
