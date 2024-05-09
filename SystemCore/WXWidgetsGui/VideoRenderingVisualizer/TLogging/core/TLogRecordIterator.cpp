#include "TLogRecordIterator.h"
#include "SmartPointers.h"

using namespace tlogging;

/**
 * Creates a TLog Record Iterator.
 */
base::IIteratorSharedPtr<ITLogRecordSharedPtr> TLogRecordIterator::Make(
    base::IIteratorSharedPtr<logging::ILogRecordSharedPtr> recordIterator,
    ITLogRecordParserSharedPtr recordParser)
{
    return std::make_shared<TLogRecordIterator>(
        recordIterator, 
        recordParser);
}

/**
 * The TLogRecordIterator constructor.
 */
TLogRecordIterator::TLogRecordIterator(
    base::IIteratorSharedPtr<logging::ILogRecordSharedPtr> recordIterator,
    ITLogRecordParserSharedPtr recordParser)
{
    //
    // Set record iterator...
    //
    base::SmartPointers::Validate<base::IIterator<logging::ILogRecordSharedPtr>>(recordIterator);
    m_recordIterator = recordIterator;

    //
    // Set log record parser...
    //
    base::SmartPointers::Validate<ITLogRecordParser>(recordParser);
    m_recordParser = recordParser;
}

/**
 * The TLogRecordIterator destructor.
 */
TLogRecordIterator::~TLogRecordIterator()
{
}

/**
 * Checks whether there is a next element.
 */
bool TLogRecordIterator::HasNext() const
{
    return m_recordIterator->HasNext();
}

/**
 * Gets the next element.
 */
ITLogRecordSharedPtr TLogRecordIterator::Next()
{
    logging::ILogRecordSharedPtr logRecord = m_recordIterator->Next();

    if (logRecord == nullptr) {
        return nullptr;
    }

    ITLogRecordSharedPtr tLogRecord = m_recordParser->Parse(logRecord);
    
    return tLogRecord;
}

/**
 * Resets the iterator.
 */
void TLogRecordIterator::Reset()
{
    m_recordIterator->Reset();
}
