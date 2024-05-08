#include "SlidersConfiguration.h"
#include "GuiComponentsConfiguration.h"

using namespace GuiConfiguration;

/**
 * Creates sliders configuration.
 */
ISlidersConfigurationSharedPtr SlidersConfiguration::Make()
{
    return std::make_shared<SlidersConfiguration>();
}

/**
 * The SlidersConfiguration constructor.
 */
SlidersConfiguration::SlidersConfiguration() : 
    m_impl(std::make_shared<GuiComponentsConfiguration<ISliderConfiguration>>())
{
}

/**
 * The SlidersConfiguration destructor.
 */
SlidersConfiguration::~SlidersConfiguration() 
{
}

/**
 * Adds a configuration of a component by path.
 */
void SlidersConfiguration::AddConfiguration(const std::wstring& path, ISliderConfigurationSharedPtr configuration)
{
    m_impl->AddConfiguration(path, configuration);
}

/**
 * Gets a configuration of a component by path.
 */
const ISliderConfigurationSharedPtr SlidersConfiguration::GetConfiguration(const std::wstring& path) const
{
    return m_impl->GetConfiguration(path);
}

/**
 * Checks whether a configuration of a component exists.
 */
bool SlidersConfiguration::ConfigurationExists(const std::wstring& path) const
{
    return m_impl->ConfigurationExists(path);
}
