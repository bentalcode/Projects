#include "PreCompiled.h"
#include "LogFactory.h"

using namespace base;

/**
 * The log factory ptr.
 */
LogFactory::ILogFactoryPtr LogFactory::instance;

/**
 * The mutex for creating a singleton.
 */
std::mutex LogFactory::singletonMutex;

/**
 * The default log name.
 */
const std::string LogFactory::defaultLogName = "defaultLog";

/**
 * The LogFactory constructor.
 */
LogFactory::LogFactory(LogLevelType logLevel) :
    m_logLevel(logLevel)
{
}

/**
 * The LogFactory destructor.
 */
LogFactory::~LogFactory()
{
}

/**
 * Gets an instance of a log factory.
 */
ILogFactory& LogFactory::getInstance()
{
    if (!instance)
    {
        std::unique_lock<std::mutex> lock(singletonMutex);

        if (!instance)
        {
            instance.reset(new LogFactory);
        }
    }

    return *instance;
}

/**
 * Gets a default log.
 */
ILogPtr LogFactory::getLog()
{
    return Log::make(defaultLogName);
}

/**
 * Gets a new log by name.
 */
ILogPtr LogFactory::getLog(const std::string& name)
{
    return Log::make(name);
}

/**
 * Sets the default log level.
 */
void LogFactory::setLogLevel(LogLevelType logLevel)
{
    m_logLevel = logLevel;
}

/**
 * Gets the default log level.
 */
LogLevelType LogFactory::getLogLevel() const
{
    return m_logLevel;
}
