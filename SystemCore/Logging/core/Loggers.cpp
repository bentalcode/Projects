#include "Loggers.h"
#include "LoggerFactory.h"
#include "StringUtils.h"

using namespace logging;

/**
 * Creates a Loggers.
 */
ILoggersSharedPtr Loggers::Make(const std::wstring& name)
{
    return std::make_shared<Loggers>(name);
}

/**
 * Creates a Loggers.
 */
ILoggersSharedPtr Loggers::Make(const std::type_info& typeInfo)
{
    std::string name(typeInfo.name());
    std::wstring loggerName = base::StringUtils::StringToWideString(name);
    return std::make_shared<Loggers>(loggerName);
}

/**
 * The Loggers constructor.
 */
Loggers::Loggers(const std::wstring& name) : 
    m_name(name) 
{
}

/**
 * The Loggers destructor.
 */
Loggers::~Loggers()
{

}

/**
 * Gets a logger.
 */
ILoggerSharedPtr Loggers::GetLogger()
{
    if (!m_logger) {
        ILoggerFactorySharedPtr loggerFactory = LoggerFactory::Make(); 
        m_logger = loggerFactory->GetLogger(m_name);
    }

    return m_logger;
}
