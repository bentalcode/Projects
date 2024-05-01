#ifndef I_LOG_HEADER_H_299a9673_d664_46be_ace4_2e90a2668837
#define I_LOG_HEADER_H_299a9673_d664_46be_ace4_2e90a2668837

#include "ITabularHeader.h"

namespace logging {

    /**
     * The ILogHeader interface defines a Log Header.
     */
    class ILogHeader {
    public:
        ILogHeader() = default;
        virtual ~ILogHeader() = default;

        /**
         * Gets header name of an index of a record.
         */
        virtual const std::wstring& GetIndexHeaderName() const = 0;

        /**
         * Gets header name of logging time.
         */
        virtual const std::wstring& GetLoggingTimeHeaderName() const = 0;

        /**
         * Gets header name of logging thread id.
         */
        virtual const std::wstring& GetLoggingThreadIdHeaderName() const = 0;

        /**
         * Gets header name of logging component.
         */
        virtual const std::wstring& GetLoggingComponentHeaderName() const = 0;

        /**
         * Gets header name of log level.
         */
        virtual const std::wstring& GetLogLevelHeaderName() const = 0;

        /**
         * Gets header name of logging function.
         */
        virtual const std::wstring& GetLoggingFunctionHeaderName() const = 0;

        /**
         * Gets header name of logging object.
         */
        virtual const std::wstring& GetLoggingObjectHeaderName() const = 0;

        /**
         * Gets header name of logging message.
         */
        virtual const std::wstring& GetLoggingMessageHeaderName() const = 0;

        /**
         * Gets header name of source file/line.
         */
        virtual const std::wstring& GetSourceFileLineHeaderName() const = 0;

        /**
         * Translates to a tabular header.
         */
        virtual tabular_data::ITabularHeaderSharedPtr ToHeader() const = 0;
    };

    /**
     * Defines the Shared Ptr of Log Header.
     */
    using ILogHeaderSharedPtr = std::shared_ptr<ILogHeader>;

}  // namespace logging

#endif // I_LOG_HEADER_H_299a9673_d664_46be_ace4_2e90a2668837

