#ifndef TLOG_PROCESSOR_H_640afa5b_b3c0_45db_a5c1_fbdd673c7f63
#define TLOG_PROCESSOR_H_640afa5b_b3c0_45db_a5c1_fbdd673c7f63

#include "ITLogProcessor.h"
#include "ITLogTree.h"
#include "ITLogNotificationHandler.h"
#include "ITLogStatistics.h"
#include "IEventTLog.h"

namespace tlogging {

    /**
     * The TLogProcessor class implements a TLog Processor.
     */
    class TLogProcessor final : public ITLogProcessor {
    public:
        /**
         * Creates a TLog Processor.
         */
        static ITLogProcessorSharedPtr Make(
            ITLogTreeSharedPtr tree,
            ITLogNotificationHandlerSharedPtr notificationHandler,
            ITLogStatisticsSharedPtr statistics,
            IEventTLogSharedPtr eventTLog);

        /**
         * The TLogProcessor constructor.
         */
        TLogProcessor(
            ITLogTreeSharedPtr tree,
            ITLogNotificationHandlerSharedPtr notificationHandler,
            ITLogStatisticsSharedPtr statistics,
            IEventTLogSharedPtr eventTLog);

        /**
         * The TLogProcessor destructor.
         */
        virtual ~TLogProcessor();

        /**
         * Processes a Call Started Record.
         */
        virtual void Process(const ICallStartedRecord& record) override;

        /**
         * Processes a Call Ended Record.
         */
        virtual void Process(const ICallEndedRecord& record) override;

        /**
         * Processes a Compositor Created Record.
         */
        virtual void Process(const ICompositorCreatedRecord& record) override;

        /**
         * Processes a Compositor Destroyed Record.
         */
        virtual void Process(const ICompositorDestroyedRecord& record) override;

        /**
         * Processes an Add View Record.
         */
        virtual void Process(const IAddViewRecord& record) override;

        /**
         * Processes a Remove View Record.
         */
        virtual void Process(const IRemoveViewRecord& record) override;

        /**
         * Processes a Set Configuration Record.
         */
        virtual void Process(const ISetConfigurationRecord& record) override;

        /**
         * Processes a Set View Properties Record.
         */
        virtual void Process(const ISetViewPropertiesRecord& record) override;

    private:
        /**
         * Processes a constructor Record.
         * Returns true if record has been processed successfully based on current known state.
         */
        bool ProcessConstructorRecord(
            const ITLogRecord& record,
            TLogRecordType recordType,
            const std::wstring& context,
            const std::wstring& key,
            const std::vector<std::wstring>& path);

        /**
         * Processes a destructor Record.
         * Returns true if record has been processed successfully based on current known state.
         */
        bool ProcessDestructorRecord(
            const ITLogRecord& record,
            TLogRecordType recordType,
            const std::wstring& context,
            const std::vector<std::wstring>& path);

        /**
         * Gets or creates a TLog Record Tree.
         */
        const ITLogTree::ITLogRecordTreeSharedPtr GetOrCreateTLogRecordTree(TLogRecordType recordType);

        /**
         * Deletes a record from a TLog Record Tree.
         */
        void DeleteTLogRecord(
            const ITLogRecord& record,
            ITLogTree::ITLogRecordTree& tree,
            const std::vector<std::wstring>& path,
            const std::wstring& context);

        /**
         * Verifies that a record exists.
         */
        bool VerifyRecordExists(
            const ITLogRecord& record,
            ITLogTree::ITLogRecordTree& tree,
            const std::vector<std::wstring>& path,
            const std::wstring& context) const;

        /**
         * Verifies that a record does not exist.
         */
        bool VerifyRecordDoesNotExist(
            const ITLogRecord& record,
            ITLogTree::ITLogRecordTree& tree,
            const std::vector<std::wstring>& path,
            const std::wstring& context) const;

        //
        // The TLog tree to update...
        //
        ITLogTreeSharedPtr m_tree;

        //
        // The Notification Handler...
        //
        ITLogNotificationHandlerSharedPtr m_notificationHandler;

        //
        // The TLog Statistics...
        //
        ITLogStatisticsSharedPtr m_statistics;

        //
        // The Event TLog...
        //
        IEventTLogSharedPtr m_eventTLog;
    };

} // namespace tlogging

#endif // TLOG_PROCESSOR_H_640afa5b_b3c0_45db_a5c1_fbdd673c7f63

