#ifndef TLOG_RECORD_ITERATOR_H_6bdf078c_8090_461b_bb0e_19c9123e5bf1
#define TLOG_RECORD_ITERATOR_H_6bdf078c_8090_461b_bb0e_19c9123e5bf1

#include "IIterator.h"
#include "ITLogRecord.h"
#include "ILogRecord.h"
#include "TLogRecordParser.h"

namespace tlogging {

    /**
     * The TLogRecordIterator class implements a TLog Record Iterator.
     */
    class TLogRecordIterator final : public base::IIterator<ITLogRecordSharedPtr> {
    public:
        /**
         * Creates a TLog Record Iterator.
         */
        static base::IIteratorSharedPtr<ITLogRecordSharedPtr> Make(
            base::IIteratorSharedPtr<logging::ILogRecordSharedPtr> recordIterator,
             ITLogRecordParserSharedPtr recordParser = TLogRecordParser::Make());

        /**
         * The TLogRecordIterator constructor.
         */
        TLogRecordIterator(
            base::IIteratorSharedPtr<logging::ILogRecordSharedPtr> recordIterator,
            ITLogRecordParserSharedPtr recordParser);

        /**
         * The TLogRecordIterator destructor.
         */
        virtual ~TLogRecordIterator();

        /**
         * Checks whether there is a next element.
         */
        virtual bool HasNext() const override;

        /**
         * Gets the next element.
         */
        virtual ITLogRecordSharedPtr Next() override;

        /**
         * Resets the iterator.
         */
        virtual void Reset() override;

    private:
        //
        // The iterator of log records...
        //
        base::IIteratorSharedPtr<logging::ILogRecordSharedPtr> m_recordIterator;

        //
        // The record parser...
        //
        ITLogRecordParserSharedPtr m_recordParser;
    };

} // namespace tlogging

#endif // TLOG_RECORD_ITERATOR_H_6bdf078c_8090_461b_bb0e_19c9123e5bf1
