#include "LogRecordIterator.h"
#include "LogRecord.h"
#include "SmartPointers.h"
#include "LoggingException.h"

using namespace logging;

const size_t LogRecordIterator::NUMBER_OF_FIELDS = 10;

/**
 * Creates a Log Record Iterator.
 */
base::IIteratorSharedPtr<ILogRecordSharedPtr> LogRecordIterator::Make(
    base::IIteratorSharedPtr<tabular_data::ITabularRecordSharedPtr> recordIterator,
    tabular_data::IValueTransformerSharedPtr<size_t> indexTransformer,
    tabular_data::IValueTransformerSharedPtr<base::DateTimeSharedPtr> dateTimeTransformer,
    tabular_data::IValueTransformerSharedPtr<unsigned long> threadIdTransformer,
    tabular_data::IValueTransformerSharedPtr<std::wstring> componentTransformer,
    tabular_data::IValueTransformerSharedPtr<LogLevel> logLevelTransformer,
    tabular_data::IValueTransformerSharedPtr<std::wstring> loggingFunctionTransformer,
    tabular_data::IValueTransformerSharedPtr<std::wstring> loggingObjectTransformer,
    tabular_data::IValueTransformerSharedPtr<std::wstring> loggingMessageTransformer,
    tabular_data::IValueTransformerSharedPtr<std::wstring> sourceFileTransformer,
    tabular_data::IValueTransformerSharedPtr<size_t> sourceLineTransformer)
{
    return std::make_shared<LogRecordIterator>(
        recordIterator, 
        indexTransformer, 
        dateTimeTransformer, 
        threadIdTransformer, 
        componentTransformer, 
        logLevelTransformer, 
        loggingFunctionTransformer, 
        loggingObjectTransformer,
        loggingMessageTransformer, 
        sourceFileTransformer, 
        sourceLineTransformer);
}

/**
 * The LogRecordIterator constructor.
 */
LogRecordIterator::LogRecordIterator(
    base::IIteratorSharedPtr<tabular_data::ITabularRecordSharedPtr> recordIterator,
    tabular_data::IValueTransformerSharedPtr<size_t> indexTransformer,
    tabular_data::IValueTransformerSharedPtr<base::DateTimeSharedPtr> dateTimeTransformer,
    tabular_data::IValueTransformerSharedPtr<unsigned long> threadIdTransformer,
    tabular_data::IValueTransformerSharedPtr<std::wstring> componentTransformer,
    tabular_data::IValueTransformerSharedPtr<LogLevel> logLevelTransformer,
    tabular_data::IValueTransformerSharedPtr<std::wstring> loggingFunctionTransformer,
    tabular_data::IValueTransformerSharedPtr<std::wstring> loggingObjectTransformer,
    tabular_data::IValueTransformerSharedPtr<std::wstring> loggingMessageTransformer,
    tabular_data::IValueTransformerSharedPtr<std::wstring> sourceFileTransformer,
    tabular_data::IValueTransformerSharedPtr<size_t> sourceLineTransformer) :
        m_currRecordIndex(0)
{
    //
    // Validate input parameters...
    //
    base::SmartPointers::Validate<base::IIterator<tabular_data::ITabularRecordSharedPtr>>(recordIterator);
    base::SmartPointers::Validate<tabular_data::IValueTransformer<size_t>>(indexTransformer);
    base::SmartPointers::Validate<tabular_data::IValueTransformer<base::DateTimeSharedPtr>>(dateTimeTransformer);
    base::SmartPointers::Validate<tabular_data::IValueTransformer<unsigned long>>(threadIdTransformer);
    base::SmartPointers::Validate<tabular_data::IValueTransformer<std::wstring>>(componentTransformer);
    base::SmartPointers::Validate<tabular_data::IValueTransformer<LogLevel>>(logLevelTransformer);
    base::SmartPointers::Validate<tabular_data::IValueTransformer<std::wstring>>(loggingFunctionTransformer);
    base::SmartPointers::Validate<tabular_data::IValueTransformer<std::wstring>>(loggingObjectTransformer);
    base::SmartPointers::Validate<tabular_data::IValueTransformer<std::wstring>>(loggingMessageTransformer);
    base::SmartPointers::Validate<tabular_data::IValueTransformer<std::wstring>>(sourceFileTransformer);
    base::SmartPointers::Validate<tabular_data::IValueTransformer<size_t>>(sourceLineTransformer);
    
    //
    // Set record iterator...
    //
    m_recordIterator = recordIterator;

    //
    // Set fields transformers...
    //
    m_indexTransformer = indexTransformer;
    m_dateTimeTransformer = dateTimeTransformer;
    m_threadIdTransformer = threadIdTransformer;
    m_componentTransformer = componentTransformer;
    m_logLevelTransformer = logLevelTransformer;
    m_loggingFunctionTransformer = loggingFunctionTransformer;
    m_loggingObjectTransformer = loggingObjectTransformer;
    m_loggingMessageTransformer = loggingMessageTransformer;
    m_sourceFileTransformer = sourceFileTransformer;
    m_sourceLineTransformer = sourceLineTransformer;
}

/**
 * The LogRecordIterator destructor.
 */
LogRecordIterator::~LogRecordIterator()
{
}

/**
 * Checks whether there is a next element.
 */
bool LogRecordIterator::HasNext() const
{
    return m_recordIterator->HasNext();
}

/**
 * Gets the next element.
 */
ILogRecordSharedPtr LogRecordIterator::Next()
{
    tabular_data::ITabularRecordSharedPtr record = m_recordIterator->Next();
    
    if (!record) {
        return nullptr;
    }

    ++m_currRecordIndex;

    if (record->GetSize() != NUMBER_OF_FIELDS) {
        long errorCode = base::ErrorCodes::INVALID_ARG;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"Invalid Logging Record at index: " << m_currRecordIndex
            << L", due to invalid number of fields."
            << L"; Found: " << record->GetSize() << L" Expected: " << NUMBER_OF_FIELDS 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();
        throw LoggingException(errorCode, errorMessage);
    }

    size_t index = m_indexTransformer->Transform(record->GetValue(0));
    base::DateTimeSharedPtr loggingTime = m_dateTimeTransformer->Transform(record->GetValue(1));
    unsigned long loggingThreadId = m_threadIdTransformer->Transform(record->GetValue(2));
    std::wstring loggingComponent = m_componentTransformer->Transform(record->GetValue(3));
    LogLevel logLevel = m_logLevelTransformer->Transform(record->GetValue(4));
    std::wstring loggingFunction = m_loggingFunctionTransformer->Transform(record->GetValue(5));
    std::wstring loggingObject = m_loggingObjectTransformer->Transform(record->GetValue(6));
    std::wstring loggingMessage = m_loggingMessageTransformer->Transform(record->GetValue(7));
    std::wstring sourceFile = m_sourceFileTransformer->Transform(record->GetValue(8));
    size_t sourceLine = m_sourceLineTransformer->Transform(record->GetValue(9));

    return LogRecord::Make(
        index, 
        loggingTime, 
        loggingThreadId, 
        loggingComponent, 
        logLevel, 
        loggingFunction,
        loggingObject,
        loggingMessage, 
        sourceFile, 
        sourceLine);
}

/**
 * Resets the iterator.
 */
void LogRecordIterator::Reset()
{
    m_currRecordIndex = 0;
    m_recordIterator->Reset();
}
