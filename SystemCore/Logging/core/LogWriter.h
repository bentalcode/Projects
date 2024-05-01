#ifndef LOG_WRITER_H_b2d0f158_fc10423c_a5e3_d2a093034f73
#define LOG_WRITER_H_b2d0f158_fc10423c_a5e3_d2a093034f73

#include "ILogWriter.h"
#include "ITabularTableWriter.h"
#include "IPath.h"

namespace logging {

    /**
     * The LogWriter class implements a Log Writer.
     */
    class LogWriter final : public ILogWriter {
    public:
        /**
         * Creates a Log Writer.
         */
        static ILogWriterSharedPtr Make(
            const std::wstring& path,
            const std::wstring& separator = L"    ");

        /**
         * The LogWriter constructor.
         */
        LogWriter(
            const std::wstring& path,
            const std::wstring& separator);

        /**
         * The LogWriter destructor.
         */
        virtual ~LogWriter();

        /**
         * Writes header.
         */
        virtual void WriteHeader(const ILogHeader& header) override;

        /**
         * Writes record.
         */
        virtual void WriteRecord(const ILogRecord& record) override;

        /**
         * Writes a new line.
         */
        virtual void NewLine() override;

    private:
        /**
         * Initializes a new log.
         */
        void Initialize(
            const std::wstring& path,
            const std::wstring& separator);

        /**
         * Deletes log.
         */
        bool DeleteLog(const std::wstring& path);

        /**
         * Checks whethet logs directory exists.
         */
        bool LogsDirectoryExists(const std::wstring& path) const;

        /**
         * Create logs directory.
         */
        bool CreateLogsDirectory(const std::wstring& path);

        tabular_data::ITabularTableWriterSharedPtr m_writer;
    };

} // namespace logging

#endif // LOG_WRITER_H_b2d0f158_fc10423c_a5e3_d2a093034f73
