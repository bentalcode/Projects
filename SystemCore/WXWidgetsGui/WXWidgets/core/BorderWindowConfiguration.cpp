#include "BorderWindowConfiguration.h"

using namespace WXWidgets;

/**
 * Creates a configuration of a border window.
 */
IBorderWindowConfigurationSharedPtr BorderWindowConfiguration::Make(
    const std::wstring& label, 
    int proportion,
    int flag)
{
    return std::make_shared<BorderWindowConfiguration>(
        label,
        proportion, 
        flag);
}

/**
 * Copies a configuration of a border window.
 */
IBorderWindowConfigurationSharedPtr BorderWindowConfiguration::Copy(const IBorderWindowConfiguration& configuration)
{
    return BorderWindowConfiguration::Make(
        configuration.GetLabel(),
        configuration.GetProportion(), 
        configuration.GetFlag());
}

/**
 * The BorderWindowConfiguration constructor.
 */
BorderWindowConfiguration::BorderWindowConfiguration(
    const std::wstring& label,
    int proportion, 
    int flag) : 
    m_label(label), 
    m_proportion(proportion), 
    m_flag(flag)
{
}

/**
 * The BorderWindowConfiguration destructor.
 */
BorderWindowConfiguration::~BorderWindowConfiguration() 
{
}

/**
 * Gets a label of a window.
 */
const std::wstring& BorderWindowConfiguration::GetLabel() const
{
    return m_label;
}

/**
 * Gets a proportion of a window.
 */
int BorderWindowConfiguration::GetProportion() const 
{
    return m_proportion;
}

/**
 * Gets a flag of a window.
 */
int BorderWindowConfiguration::GetFlag() const
{
    return m_flag;
}
