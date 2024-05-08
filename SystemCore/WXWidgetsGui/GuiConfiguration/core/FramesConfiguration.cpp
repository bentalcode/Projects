#include "FramesConfiguration.h"
#include "GuiComponentsConfiguration.h"

using namespace GuiConfiguration;

/**
 * Creates frames configuration.
 */
IFramesConfigurationSharedPtr FramesConfiguration::Make()
{
    return std::make_shared<FramesConfiguration>();
}

/**
 * The FramesConfiguration constructor.
 */
FramesConfiguration::FramesConfiguration() : 
    m_impl(std::make_shared<GuiComponentsConfiguration<IFrameConfiguration>>())
{
}

/**
 * The FramesConfiguration destructor.
 */
FramesConfiguration::~FramesConfiguration() 
{
}

/**
 * Adds a configuration of a component by path.
 */
void FramesConfiguration::AddConfiguration(
    const std::wstring& path,
    IFrameConfigurationSharedPtr configuration)
{
    m_impl->AddConfiguration(path, configuration);
}

/**
 * Gets a configuration of a component by path.
 */
const IFrameConfigurationSharedPtr FramesConfiguration::GetConfiguration(const std::wstring& path) const
{
    return m_impl->GetConfiguration(path);
}

/**
 * Checks whether a configuration of a component exists.
 */
bool FramesConfiguration::ConfigurationExists(const std::wstring& path) const
{
    return m_impl->ConfigurationExists(path);
}
