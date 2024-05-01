#ifndef I_LOGGERS_H_8fb0491e_af7e_4449_be9f_fefc01aebf00
#define I_LOGGERS_H_8fb0491e_af7e_4449_be9f_fefc01aebf00

#include "ILogger.h"

namespace logging {

    /**
     * The ILoggers interface defines loggers.
     */
    class ILoggers {
    public:
        ILoggers() = default;
        virtual ~ILoggers() = default;

        /**
         * Gets a logger.
         */
        virtual ILoggerSharedPtr GetLogger() = 0;
    };

    /**
     * Defines the Shared Ptr of Loggers.
     */
    using ILoggersSharedPtr = std::shared_ptr<ILoggers>;

} // namespace logging

#endif // I_LOGGERS_H_8fb0491e_af7e_4449_be9f_fefc01aebf00
