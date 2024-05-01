#ifndef LOG_H_ea533151_2122_40a4_b2cb_6149cd347fe1
#define LOG_H_ea533151_2122_40a4_b2cb_6149cd347fe1

#include "ILog.h"
#include "ParsingPolicyType.h"
#include "EventLog.h"
#include "ITabularFile.h"

namespace logging {

    /**
     * The Log class implements an abstract log.
     */
    class Log final : public ILog {
    public:
        /**
         * Creates a Log.
         */
        static ILogSharedPtr Make(
            const std::wstring& path,
            tabular_data::ParsingPolicyType parsingPolicyType = tabular_data::ParsingPolicyType::FAIL_ON_FIRST_ERROR,
            tabular_data::IEventLogSharedPtr eventLog = tabular_data::EventLog::Make());

        /**
         * The Log constructor.
         */
        Log(const std::wstring& path,
            tabular_data::ParsingPolicyType parsingPolicyType,
            tabular_data::IEventLogSharedPtr eventLog);

        /**
         * The Log destructor.
         */
        virtual ~Log();

        /**
         * Gets a tabular file.
         */
        virtual const tabular_data::ITabularFile& GetTabularFile() const override;

        /**
         * Gets an iterator of records of log.
         */
        virtual base::IIteratorSharedPtr<ILogRecordSharedPtr> GetIterator() const override;

    private:
        tabular_data::ITabularFileSharedPtr m_tabularFile;
    };

} // namespace logging

#endif // namespace LOG_H_ea533151_2122_40a4_b2cb_6149cd347fe1
