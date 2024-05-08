#include "GuiComponentsConfiguration.h"
#include "LabelsConfiguration.h"

using namespace GuiConfiguration;

/**
 * Creates labels configuration.
 */
ILabelsConfigurationSharedPtr LabelsConfiguration::Make()
{
    return std::make_shared<LabelsConfiguration>();
}

/**
 * The LabelsConfiguration constructor.
 */
LabelsConfiguration::LabelsConfiguration() : 
    m_impl(std::make_shared<GuiComponentsConfiguration<ILabelConfiguration>>())
{
}

/**
 * The LabelsConfiguration destructor.
 */
LabelsConfiguration::~LabelsConfiguration() 
{
}

/**
 * Adds a configuration of a component by path.
 */
void LabelsConfiguration::AddConfiguration(
    const std::wstring& path, 
    ILabelConfigurationSharedPtr configuration)
{
    m_impl->AddConfiguration(path, configuration);
}

/**
 * Gets a configuration of a component by path.
 */
const ILabelConfigurationSharedPtr LabelsConfiguration::GetConfiguration(const std::wstring& path) const
{
    return m_impl->GetConfiguration(path);
}

/**
 * Checks whether a configuration of a component exists.
 */
bool LabelsConfiguration::ConfigurationExists(const std::wstring& path) const
{
    return m_impl->ConfigurationExists(path);
}
