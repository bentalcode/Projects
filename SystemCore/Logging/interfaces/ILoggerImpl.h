#ifndef I_LOGGER_IMPL_H_3a0a391e_b21e_41d0_bffa_367a8d3b6457
#define I_LOGGER_IMPL_H_3a0a391e_b21e_41d0_bffa_367a8d3b6457

#include "LogLevel.h"
#include <memory>

namespace logging {

    /**
     * The ILoggerImpl interface defines a logger implementation.
     */
    class ILoggerImpl {
    public:
        ILoggerImpl() = default;
        virtual ~ILoggerImpl() = default;

        /**
         * Logs a message.
         */
        virtual void Log(
            const std::wstring& loggerName,
            LogLevel logLevel,
            const std::wstring& message,
            const std::string& file,
            size_t line) = 0;
    };

    /**
     * Defines the Shared Ptr of ILoggerImpl.
     */
    using ILoggerImplSharedPtr = std::shared_ptr<ILoggerImpl>;

} // namespace logging

#endif // I_LOGGER_IMPL_H_3a0a391e_b21e_41d0_bffa_367a8d3b6457

