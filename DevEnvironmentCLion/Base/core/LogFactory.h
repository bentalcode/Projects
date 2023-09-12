#ifndef LOG_FACTORY_H_009fcffc_fd5a_4055_9431_c4bb4fb46b66
#define LOG_FACTORY_H_009fcffc_fd5a_4055_9431_c4bb4fb46b66

#include "ILogFactory.h"
#include <mutex>

namespace base {

    /**
     * The LogFactory class implements a log factory.
     */
    class LogFactory final : public ILogFactory
    {
    private:
        /**
         * The LogFactory Constructor.
         */
        explicit LogFactory(LogLevelType logLevel = LogLevelType::Informational);

    public:
        /**
         * The LogFactory Destructor.
         */
        virtual ~LogFactory();

        /**
         * Gets an instance of a log factory.
         */
        static ILogFactory& getInstance();

        /**
         * The copy/move constructors.
         */
        LogFactory(const LogFactory&) = delete;
        LogFactory(LogFactory&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        LogFactory& operator=(const LogFactory&) = delete;
        LogFactory& operator=(LogFactory&&) = delete;

        /**
         * Gets a default log.
         */
        virtual ILogSharedPtr getLog() override;

        /**
         * Gets a new log by name.
         */
        virtual ILogSharedPtr getLog(const std::string& name) override;

        /**
         * Sets the default log level.
         */
        virtual void setLogLevel(LogLevelType logLevel) override;

        /**
         * Gets the default log level.
         */
        virtual LogLevelType getLogLevel() const override;

    private:
        /**
         * The log factory ptr.
         */
        using ILogFactoryPtr = std::unique_ptr<ILogFactory>;
        static ILogFactoryPtr instance;

        /**
         * The mutex for creating a singleton.
         */
        static std::mutex singletonMutex;

        /**
         * The default log name.
         */
        static const std::string defaultLogName;

        LogLevelType m_logLevel;
    };
}

#endif // LOG_FACTORY_H_009fcffc_fd5a_4055_9431_c4bb4fb46b66
