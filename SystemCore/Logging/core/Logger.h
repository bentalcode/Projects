#ifndef LOGGER_H_43f1be17_4ef4_4a81_b475_d04ed02ac073
#define LOGGER_H_43f1be17_4ef4_4a81_b475_d04ed02ac073

#include "ILogger.h"
#include "ILoggerImpl.h"

namespace logging {

    /**
     * The Logger class implements a logger.
     */
    class Logger final : public ILogger {
    public:
        /**
         * Creates a Logger.
         */
        static ILoggerSharedPtr Make(
            const std::wstring& name,
            ILoggerImplSharedPtr impl);

        /**
         * The Logger constructor.
         */
        Logger(
            const std::wstring& name,
            ILoggerImplSharedPtr impl);

        /**
         * The Logger destructor.
         */
        virtual ~Logger();

        /**
         * Gets a name of a logger.
         */
        virtual const std::wstring& GetName() const override;

        /**
         * Logs a debug message.
         */
        virtual void Debug(
            const std::wstring& message,
            const std::string& file,
            size_t line) override;

        /**
         * Logs an informational message.
         */
        virtual void Info(
            const std::wstring& message,
            const std::string& file,
            size_t line) override;

        /**
         * Logs a warning message.
         */
        virtual void Warning(
            const std::wstring& message,
            const std::string& file,
            size_t line) override;

        /**
         * Logs an error message.
         */
        virtual void Error(
            const std::wstring& message,
            const std::string& file,
            size_t line) override;

    private:
        std::wstring m_name;
        ILoggerImplSharedPtr m_impl;
    };

} // namespace logging

#endif // LOGGER_H_43f1be17_4ef4_4a81_b475_d04ed02ac073
