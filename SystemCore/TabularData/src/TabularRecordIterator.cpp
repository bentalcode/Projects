#include "TabularRecordIterator.h"
#include "TabularRecord.h"
#include "SmartPointers.h"

using namespace TabularData;

/**
 * Creates a Tabular Record Iterator.
 */
base::IIteratorSharedPtr<ITabularRecordSharedPtr> TabularRecordIterator::Make(
    base::IIteratorSharedPtr<IRecordSharedPtr> recordIterator,
    ITabularRecordParserSharedPtr recordParser)
{
    return std::make_shared<TabularRecordIterator>(
        recordIterator, 
        recordParser);
}

/**
 * The TabularRecordIterator constructor.
 */
TabularRecordIterator::TabularRecordIterator(
    base::IIteratorSharedPtr<IRecordSharedPtr> recordIterator,
    ITabularRecordParserSharedPtr recordParser) : 
    m_currRecordIndex(0)
{
    base::SmartPointers::Validate<base::IIterator<IRecordSharedPtr>>(recordIterator);
    base::SmartPointers::Validate<ITabularRecordParser>(recordParser);

    m_recordIterator = recordIterator;
    m_recordParser = recordParser;
}

/**
 * The TabularRecordIterator destructor.
 */
TabularRecordIterator::~TabularRecordIterator()
{
}

/**
 * Checks whether there is a next element.
 */
bool TabularRecordIterator::HasNext() const
{
    return m_recordIterator->HasNext();
}

/**
 * Gets the next element.
 */
ITabularRecordSharedPtr TabularRecordIterator::Next()
{
    //
    // Retrieve next record...
    //
    IRecordSharedPtr record = m_recordIterator->Next();
    std::wstring content = record->GetContent();

    if (content.empty()) {
        return nullptr;
    }

    //
    // Update record index...
    //
    ++m_currRecordIndex;

    //
    // Parse record...
    //
    ITabularRecordSharedPtr tabularRecord = m_recordParser->Parse(
        m_currRecordIndex, 
        content);

    return tabularRecord;
}

/**
 * Resets the iterator.
 */
void TabularRecordIterator::Reset()
{
    m_recordIterator->Reset();
}
