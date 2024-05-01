#ifndef LOG_HEADER_H_4aa89f4e_1fd5_4f66_a38b_fb92dfa8e8ee
#define LOG_HEADER_H_4aa89f4e_1fd5_4f66_a38b_fb92dfa8e8ee

#include "ILogHeader.h"
#include "ITabularHeader.h"

namespace logging {

    /**
     * The LogHeader class implements a Log Header.
     */
    class LogHeader final : public ILogHeader {
    public:
        /**
         * Creates a Log Header.
         */
        static ILogHeaderSharedPtr Make();

        /**
         * The LogRecord constructor.
         */
        LogHeader();

        /**
         * The LogRecord destructor.
         */
        virtual ~LogHeader();

        /**
         * Gets header name of an index of a record.
         */
        virtual const std::wstring& GetIndexHeaderName() const override;

        /**
         * Gets header name of logging time.
         */
        virtual const std::wstring& GetLoggingTimeHeaderName() const override;

        /**
         * Gets header name of logging thread id.
         */
        virtual const std::wstring& GetLoggingThreadIdHeaderName() const override;

        /**
         * Gets header name of logging component.
         */
        virtual const std::wstring& GetLoggingComponentHeaderName() const override;

        /**
         * Gets header name of log level.
         */
        virtual const std::wstring& GetLogLevelHeaderName() const override;

        /**
         * Gets header name of logging function.
         */
        virtual const std::wstring& GetLoggingFunctionHeaderName() const override;

        /**
         * Gets header name of logging object.
         */
        virtual const std::wstring& GetLoggingObjectHeaderName() const override;

        /**
         * Gets header name of logging message.
         */
        virtual const std::wstring& GetLoggingMessageHeaderName() const override;

        /**
         * Gets header name of source file/line.
         */
        virtual const std::wstring& GetSourceFileLineHeaderName() const override;

        /**
         * Translates to a tabular header.
         */
        virtual tabular_data::ITabularHeaderSharedPtr ToHeader() const override;

    private:
        static const std::wstring INDEX_HEADER_NAME;
        static const std::wstring LOGGING_TIME_HEADER_NAME;
        static const std::wstring LOGGING_THREAD_ID_HEADER_NAME;
        static const std::wstring LOGGING_COMPONENT_HEADER_NAME;
        static const std::wstring LOG_LEVEL_HEADER_NAME;
        static const std::wstring LOGGING_FUNCTION_HEADER_NAME;
        static const std::wstring LOGGING_OBJECT_HEADER_NAME;
        static const std::wstring LOGGING_MESSAGE_HEADER_NAME;
        static const std::wstring LOGGING_SOURCE_FILE_LINE_HEADER_NAME;
    };

}  // namespace logging

#endif // LOG_HEADER_H_4aa89f4e_1fd5_4f66_a38b_fb92dfa8e8ee
