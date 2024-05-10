#ifndef LOG_RECORD_H_864770c5_59ec_415a_836d_5f467415af95
#define LOG_RECORD_H_864770c5_59ec_415a_836d_5f467415af95

#include "ILogRecord.h"

namespace logging {

    /**
     * The LogRecord class implements a Log Record.
     */
    class LogRecord final : public ILogRecord {
    public:
        /**
         * Creates a Log Record.
         */
        static ILogRecordSharedPtr Make(
            size_t index,
            base::DateTimeSharedPtr loggingTime,
            unsigned long loggingThreadId,
            const std::wstring& loggingComponent,
            LogLevel logLevel,
            const std::wstring& loggingFunction,
            const std::wstring& loggingObject,
            const std::wstring& loggingMessage,
            const std::wstring& sourceFile,
            size_t sourceLine);

        /**
         * The LogRecord constructor.
         */
        LogRecord(
            size_t index,
            base::DateTimeSharedPtr loggingTime,
            unsigned long loggingThreadId,
            const std::wstring& loggingComponent,
            LogLevel logLevel,
            const std::wstring& loggingFunction,
            const std::wstring& loggingObject,
            const std::wstring& loggingMessage,
            const std::wstring& sourceFile,
            size_t sourceLine);

        /**
         * The LogRecord destructor.
         */
        virtual ~LogRecord();

        /**
         * Gets an index of a record.
         */
        virtual size_t GetIndex() const override;

        /**
         * Gets logging time.
         */
        virtual base::DateTimeSharedPtr GetLoggingTime() const override;

        /**
         * Gets logging thread id.
         */
        virtual unsigned int GetLoggingThreadId() const override;

        /**
         * Gets logging component.
         */
        virtual const std::wstring& GetLoggingComponent() const override;

        /**
         * Gets log level.
         */
        virtual LogLevel GetLogLevel() const override;

        /**
         * Gets logging function.
         */
        virtual const std::wstring& GetLoggingFunction() const override;

        /**
         * Gets logging object.
         */
        virtual const std::wstring& GetLoggingObject() const override;

        /**
         * Gets logging message.
         */
        virtual const std::wstring& GetLoggingMessage() const override;

        /**
         * Gets source file.
         */
        virtual const std::wstring& GetSourceFile() const override;

        /**
         * Gets source line.
         */
        virtual size_t GetSourceLine() const override;

        /**
         * Translates to a tabular record.
         */
        virtual tabular_data::ITabularRecordSharedPtr ToRecord() const override;

    private:
        /**
         * Gets logging time as string.
         */
        std::wstring GetLoggingTimeString() const;

        /**
         * Gets source file/line.
         */
        std::wstring GetSourceFileLine() const;

        size_t m_index;
        base::DateTimeSharedPtr m_loggingTime;
        unsigned int m_loggingThreadId;
        std::wstring m_loggingComponent;
        LogLevel m_logLevel;
        std::wstring m_loggingFunction;
        std::wstring m_loggingObject;
        std::wstring m_loggingMessage;
        std::wstring m_sourceFile;
        size_t m_sourceLine;
    };

} // namespace logging

#endif // LOG_RECORD_H_864770c5_59ec_415a_836d_5f467415af95
