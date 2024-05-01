#ifndef I_LOGGER_H_3b53653b_0ab2_4968_86f8_ec35f157c646
#define I_LOGGER_H_3b53653b_0ab2_4968_86f8_ec35f157c646

#include <string>
#include <memory>

namespace logging {

    /**
     * The ILogger interface defines a logger.
     */
    class ILogger {
    public:
        ILogger() = default;
        virtual ~ILogger() = default;

        /**
         * Gets a name of a logger.
         */
        virtual const std::wstring& GetName() const = 0;

        /**
         * Logs a debug message.
         */
        virtual void Debug(
            const std::wstring& message,
            const std::string& file,
            size_t line) = 0;

        /**
         * Logs an informational message.
         */
        virtual void Info(
            const std::wstring& message,
            const std::string& file,
            size_t line) = 0;

        /**
         * Logs a warning message.
         */
        virtual void Warning(
            const std::wstring& message,
            const std::string& file,
            size_t line) = 0;

        /**
         * Logs an error message.
         */
        virtual void Error(
            const std::wstring& message,
            const std::string& file,
            size_t line) = 0;
    };

    /**
     * Defines the Shared Ptr of Logger.
     */
    using ILoggerSharedPtr = std::shared_ptr<ILogger>;


    //
    // Logging Macors...
    //
    #define LOG_DEBUG(logger, message) logger->Debug(message, __FILE__, __LINE__);
    #define LOG_INFO(logger, message) logger->Info(message, __FILE__, __LINE__);
    #define LOG_WARNING(logger, message) logger->Warning(message, __FILE__, __LINE__);
    #define LOG_ERROR(logger, message) logger->Error(message, __FILE__, __LINE__);

} // namespace logging

#endif // I_LOGGER_H_3b53653b_0ab2_4968_86f8_ec35f157c646
