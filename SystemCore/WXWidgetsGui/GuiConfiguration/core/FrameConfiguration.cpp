#include "FrameConfiguration.h"

using namespace GuiConfiguration;

/**
 * Creates frame configuration.
 */
IFrameConfigurationSharedPtr FrameConfiguration::Make(
    const std::wstring& name, 
    const std::wstring& statusText)
{
    return std::make_shared<FrameConfiguration>(name, statusText);
}

/**
 * The FrameConfiguration constructor.
 */
FrameConfiguration::FrameConfiguration(
    const std::wstring& name, 
    const std::wstring& statusText) : 
    m_name(name), 
    m_statusText(statusText)
{
}

/**
 * The FrameConfiguration destructor.
 */
FrameConfiguration::~FrameConfiguration() 
{
}

/**
 * Gets name of a frame.
 */
const std::wstring& FrameConfiguration::GetName() const
{
    return m_name;
}

/**
 * Gets status text.
 */
const std::wstring& FrameConfiguration::GetStatusText() const
{
    return m_statusText;
}
