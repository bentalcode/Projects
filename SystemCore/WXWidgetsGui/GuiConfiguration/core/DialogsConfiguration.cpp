#include "DialogsConfiguration.h"
#include "GuiComponentsConfiguration.h"

using namespace GuiConfiguration;

/**
 * Creates dialogs configuration.
 */
IDialogsConfigurationSharedPtr DialogsConfiguration::Make()
{
    return std::make_shared<DialogsConfiguration>();
}

/**
 * The DialogsConfiguration constructor.
 */
DialogsConfiguration::DialogsConfiguration() : 
    m_impl(std::make_shared<GuiComponentsConfiguration<IDialogConfiguration>>())
{
}

/**
 * The DialogsConfiguration destructor.
 */
DialogsConfiguration::~DialogsConfiguration() 
{
}

/**
 * Adds a configuration of a component by path.
 */
void DialogsConfiguration::AddConfiguration(
    const std::wstring& path,
    IDialogConfigurationSharedPtr configuration)
{
    m_impl->AddConfiguration(path, configuration);
}

/**
 * Gets a configuration of a component by path.
 */
const IDialogConfigurationSharedPtr DialogsConfiguration::GetConfiguration(const std::wstring& path) const
{
    return m_impl->GetConfiguration(path);
}

/**
 * Checks whether a configuration of a component exists.
 */
bool DialogsConfiguration::ConfigurationExists(const std::wstring& path) const
{
    return m_impl->ConfigurationExists(path);
}
