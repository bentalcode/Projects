#ifndef I_LOG_FACTORY_H_a6e84864_6b95_4ce1_99b6_80d297e43b00
#define I_LOG_FACTORY_H_a6e84864_6b95_4ce1_99b6_80d297e43b00

#include "Log.h"

namespace base {

    /**
     * The ILogFactory interface defines a log factory.
     */
    class ILogFactory
    {
    public:
        /**
         * The constructor.
         */
        ILogFactory() = default;

        /**
         * The destructor.
         */
        virtual ~ILogFactory() = default;

        /**
         * The copy/move constructors.
         */
        ILogFactory(const ILogFactory&) = delete;
        ILogFactory(ILogFactory&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ILogFactory& operator=(const ILogFactory&) = delete;
        ILogFactory& operator=(ILogFactory&&) = delete;

        /**
         * Gets a default log.
         */
        virtual ILogPtr getLog() = 0;

        /**
         * Gets a new log by name.
         */
        virtual ILogPtr getLog(const std::string& name) = 0;

        /**
         * Sets the default log level.
         */
        virtual void setLogLevel(LogLevelType logLevel) = 0;

        /**
         * Gets the default log level.
         */
        virtual LogLevelType getLogLevel() const = 0;
    };
}

#endif // I_LOG_FACTORY_H_a6e84864_6b95_4ce1_99b6_80d297e43b00
