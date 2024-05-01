#include "LoggerFactory.h"
#include "Logger.h"
#include "LoggerImpl.h"
#include "LogWriter.h"
#include "LogHeader.h"
#include "StringUtils.h"

using namespace logging;

ILoggerFactorySharedPtr LoggerFactory::INSTANCE;
std::mutex LoggerFactory::MUTEX;

/**
 * Creates a Logger factory.
 */
ILoggerFactorySharedPtr LoggerFactory::Make() 
{
    return GetInstance();
}

/**
 * Gets an instance of a Logger factory.
 */
ILoggerFactorySharedPtr LoggerFactory::GetInstance()
{
    if (!INSTANCE) {
        std::lock_guard<std::mutex> lock(MUTEX);

        if (!INSTANCE) {
            INSTANCE = std::make_shared<LoggerFactory>();
        }
    }

    return INSTANCE;
}

/**
 * The LoggerFactory constructor.
 */
LoggerFactory::LoggerFactory() 
{
}

/**
 * The LoggerFactory destructor.
 */
LoggerFactory::~LoggerFactory()
{
}

/**
 * Initializes logger factory.
 */
void LoggerFactory::Initialize(const std::wstring& path)
{
    //
    // Initialize logger implementation...
    //
    m_writer = LogWriter::Make(path);
    m_loggerImpl = LoggerImpl::Make(m_writer);

    //
    // Create a header for the log...
    //
    ILogHeaderSharedPtr header = LogHeader::Make();
    m_writer->WriteHeader(*header);
    m_writer->NewLine();
}

/**
 * Gets a logger.
 */
ILoggerSharedPtr LoggerFactory::GetLogger(const std::type_info& typeInfo)
{
    std::string name(typeInfo.name());
    std::wstring loggerName = base::StringUtils::StringToWideString(name);
    return CreateLogger(loggerName);
}

/**
 * Gets a logger.
 */
ILoggerSharedPtr LoggerFactory::GetLogger(const std::wstring& name)
{
    return CreateLogger(name);
}

/**
 * Create a logger.
 */
ILoggerSharedPtr LoggerFactory::CreateLogger(const std::wstring& name) 
{
    return Logger::Make(name, m_loggerImpl);
}
