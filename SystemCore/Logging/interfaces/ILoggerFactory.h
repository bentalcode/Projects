#ifndef I_LOGGER_FACTORY_H_08463a72_59a9_4677_a270_41bfb5d6db26
#define I_LOGGER_FACTORY_H_08463a72_59a9_4677_a270_41bfb5d6db26

#include "ILogger.h"
#include <filesystem>
#include <typeinfo>

namespace logging {

    /**
     * The ILoggerFactory interface defines a factory of loggers.
     */
    class ILoggerFactory {
    public:
        ILoggerFactory() = default;
        virtual ~ILoggerFactory() = default;

        /**
         * Initializes logger factory.
         */
        virtual void Initialize(const std::wstring& path) = 0;

        /**
         * Gets a logger.
         */
        virtual ILoggerSharedPtr GetLogger(const std::type_info& typeInfo) = 0;

        /**
         * Gets a logger.
         */
        virtual ILoggerSharedPtr GetLogger(const std::wstring& name) = 0;
    };

    /**
     * Defines the Shared Ptr of Logger Factory.
     */
    using ILoggerFactorySharedPtr = std::shared_ptr<ILoggerFactory>;

} // namespace logging

#endif // I_LOGGER_FACTORY_H_08463a72_59a9_4677_a270_41bfb5d6db26
