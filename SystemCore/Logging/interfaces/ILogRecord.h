#ifndef I_LOG_RECORD_H_dc59ec03_41d6_4503_852d_62c4d261b16d
#define I_LOG_RECORD_H_dc59ec03_41d6_4503_852d_62c4d261b16d

#include "ITabularRecord.h"
#include "DateTime.h"
#include "LogLevel.h"

namespace logging {

    /**
     * The ILogRecord interface defines a Log Record.
     */
    class ILogRecord {
    public:
        ILogRecord() = default;
        virtual ~ILogRecord() = default;

        /**
         * Gets an index of a record.
         */
        virtual size_t GetIndex() const = 0;

        /**
         * Gets logging time.
         */
        virtual base::DateTimeSharedPtr GetLoggingTime() const = 0;

        /**
         * Gets logging thread id.
         */
        virtual unsigned int GetLoggingThreadId() const = 0;

        /**
         * Gets logging component.
         */
        virtual const std::wstring& GetLoggingComponent() const = 0;

        /**
         * Gets log level.
         */
        virtual LogLevel GetLogLevel() const = 0;

        /**
         * Gets logging function.
         */
        virtual const std::wstring& GetLoggingFunction() const = 0;

        /**
         * Gets logging object.
         */
        virtual const std::wstring& GetLoggingObject() const = 0;

        /**
         * Gets logging message.
         */
        virtual const std::wstring& GetLoggingMessage() const = 0;

        /**
         * Gets source file.
         */
        virtual const std::wstring& GetSourceFile() const = 0;

        /**
         * Gets source line.
         */
        virtual size_t GetSourceLine() const = 0;

        /**
         * Translates to a tabular record.
         */
        virtual tabular_data::ITabularRecordSharedPtr ToRecord() const = 0;
    };

    /**
     * Defines the Shared Ptr of Log Record.
     */
    using ILogRecordSharedPtr = std::shared_ptr<ILogRecord>;

} // namespace logging

#endif // I_LOG_RECORD_H_dc59ec03_41d6_4503_852d_62c4d261b16d
