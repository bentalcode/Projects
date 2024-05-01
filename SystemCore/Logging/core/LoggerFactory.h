#ifndef LOGGER_FACTORY_H_7cc78f2e_1eeb_4305_88c2_423e0a5ad64f
#define LOGGER_FACTORY_H_7cc78f2e_1eeb_4305_88c2_423e0a5ad64f

#include "ILoggerFactory.h"
#include "ILogWriter.h"
#include "ILoggerImpl.h"
#include <mutex>

namespace logging {

    /**
     * The LoggerFactory class implements a logger factory.
     */
    class LoggerFactory final : public ILoggerFactory {
    public:
        /**
         * Creates a Logger factory.
         */
        static ILoggerFactorySharedPtr Make();

        /**
         * Gets an instance of a Logger factory.
         */
        static ILoggerFactorySharedPtr GetInstance();

        /**
         * The LoggerFactory constructor.
         */
        LoggerFactory();

        /**
         * The LoggerFactory destructor.
         */
        virtual ~LoggerFactory();

        /**
         * Initializes logger factory.
         */
        virtual void Initialize(const std::wstring& path) override;

        /**
         * Gets a logger.
         */
        virtual ILoggerSharedPtr GetLogger(const std::type_info& typeInfo) override;

        /**
         * Gets a logger.
         */
        virtual ILoggerSharedPtr GetLogger(const std::wstring& name) override;

    private:
        //
        // The singletone data...
        //
        static ILoggerFactorySharedPtr INSTANCE;
        static std::mutex MUTEX;

        /**
         * Create a logger.
         */
        ILoggerSharedPtr CreateLogger(const std::wstring& name);

        //
        // The log writer...
        //
        ILogWriterSharedPtr m_writer;

        //
        // The logger implementation...
        //
        ILoggerImplSharedPtr m_loggerImpl;
    };

} // namespace logging

#endif // LOGGER_FACTORY_H_7cc78f2e_1eeb_4305_88c2_423e0a5ad64f
