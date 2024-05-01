#ifndef LOG_RECORD_ITERATOR_H_e6add5b2_53f0_4c1b_bbd1_29e6826b9146
#define LOG_RECORD_ITERATOR_H_e6add5b2_53f0_4c1b_bbd1_29e6826b9146

#include "IIterator.h"
#include "ILogRecord.h"
#include "ITabularRecord.h"
#include "IValueTransformer.h"
#include "DateTime.h"
#include "StringTransformer.h"
#include "SizeTTransformer.h"
#include "DateTimeTransformer.h"
#include "UnsignedLongTransformer.h"
#include "LogLevelTransformer.h"

namespace logging {

    /**
     * The LogRecordIterator class implements a Log Record Iterator.
     */
    class LogRecordIterator final : public base::IIterator<ILogRecordSharedPtr> {
    public:
        /**
         * Creates a Log Record Iterator.
         */
        static base::IIteratorSharedPtr<ILogRecordSharedPtr> Make(
            base::IIteratorSharedPtr<tabular_data::ITabularRecordSharedPtr> recordIterator,
            tabular_data::IValueTransformerSharedPtr<size_t> indexTransformer = SizeTTransformer::Make(),
            tabular_data::IValueTransformerSharedPtr<base::DateTimeSharedPtr> dateTimeTransformer = DateTimeTransformer::Make(),
            tabular_data::IValueTransformerSharedPtr<unsigned long> threadIdTransformer = UnsignedLongTransformer::Make(),
            tabular_data::IValueTransformerSharedPtr<std::wstring> componentTransformer = StringTransformer::Make(),
            tabular_data::IValueTransformerSharedPtr<LogLevel> logLevelTransformer = LogLevelTransformer::Make(),
            tabular_data::IValueTransformerSharedPtr<std::wstring> loggingFunctionTransformer = StringTransformer::Make(),
            tabular_data::IValueTransformerSharedPtr<std::wstring> loggingObjectTransformer = StringTransformer::Make(),
            tabular_data::IValueTransformerSharedPtr<std::wstring> loggingMessageTransformer = StringTransformer::Make(),
            tabular_data::IValueTransformerSharedPtr<std::wstring> sourceFileTransformer = StringTransformer::Make(),
            tabular_data::IValueTransformerSharedPtr<size_t> sourceLineTransformer = SizeTTransformer::Make());

        /**
         * The LogRecordIterator constructor.
         */
        LogRecordIterator(
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
            tabular_data::IValueTransformerSharedPtr<size_t> sourceLineTransformer);

        /**
         * The LogRecordIterator destructor.
         */
        virtual ~LogRecordIterator();

        /**
         * Checks whether there is a next element.
         */
        virtual bool HasNext() const override;

        /**
         * Gets the next element.
         */
        virtual ILogRecordSharedPtr Next() override;

        /**
         * Resets the iterator.
         */
        virtual void Reset() override;

    private:
        static const size_t NUMBER_OF_FIELDS;

        //
        // The iterator of tabular records...
        //
        base::IIteratorSharedPtr<tabular_data::ITabularRecordSharedPtr> m_recordIterator;

        //
        // The transformers of record properties...
        //
        tabular_data::IValueTransformerSharedPtr<size_t> m_indexTransformer;
        tabular_data::IValueTransformerSharedPtr<base::DateTimeSharedPtr> m_dateTimeTransformer;
        tabular_data::IValueTransformerSharedPtr<unsigned long> m_threadIdTransformer;
        tabular_data::IValueTransformerSharedPtr<std::wstring> m_componentTransformer;
        tabular_data::IValueTransformerSharedPtr<LogLevel> m_logLevelTransformer;
        tabular_data::IValueTransformerSharedPtr<std::wstring> m_loggingFunctionTransformer;
        tabular_data::IValueTransformerSharedPtr<std::wstring> m_loggingObjectTransformer;
        tabular_data::IValueTransformerSharedPtr<std::wstring> m_loggingMessageTransformer;
        tabular_data::IValueTransformerSharedPtr<std::wstring> m_sourceFileTransformer;
        tabular_data::IValueTransformerSharedPtr<size_t> m_sourceLineTransformer;

        //
        // The current index of record...
        //
        size_t m_currRecordIndex;
    };

} // namespace logging

#endif // LOG_RECORD_ITERATOR_H_e6add5b2_53f0_4c1b_bbd1_29e6826b9146
