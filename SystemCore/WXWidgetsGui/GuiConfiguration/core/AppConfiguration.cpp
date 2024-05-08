#include "AppConfiguration.h"

using namespace GuiConfiguration;

/**
 * Creates an app configuration.
 */
IAppConfigurationSharedPtr AppConfiguration::Make(
    const std::wstring& name, 
    const std::wstring& logPath)
{
    return std::make_shared<AppConfiguration>(
        name, 
        logPath);
}

/**
 * The AppConfiguration constructor.
 */
AppConfiguration::AppConfiguration(
    const std::wstring& name, 
    const std::wstring& logPath) : 
    m_name(name), 
    m_logPath(logPath) 
{
}

/**
 * The AppConfiguration destructor.
 */
AppConfiguration::~AppConfiguration() 
{
}

/**
 * Gets name of an app.
 */
const std::wstring& AppConfiguration::GetName() const
{
    return m_name;
}

/**
 * Gets log path.
 */
const std::wstring& AppConfiguration::GetLogPath() const
{
    return m_logPath;
}
