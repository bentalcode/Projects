#include "SplitterSubWindowConfiguration.h"

using namespace WXWidgets;

/**
 * Creates a configuration of a splitter sub window.
 */
ISplitterSubWindowConfigurationSharedPtr SplitterSubWindowConfiguration::Make(
    int proportion,
    int flag, 
    const IBorderWindowConfigurationSharedPtr borderWindowConfiguration, 
    bool showMode)
{
    return std::make_shared<SplitterSubWindowConfiguration>(
        proportion, 
        flag, 
        borderWindowConfiguration, 
        showMode);
}

/**
 * Copies a configuration of a splitter sub window.
 */
ISplitterSubWindowConfigurationSharedPtr SplitterSubWindowConfiguration::Copy(const ISplitterSubWindowConfiguration& configuration)
{
    return SplitterSubWindowConfiguration::Make(
        configuration.GetProportion(), 
        configuration.GetFlag(),
        configuration.GetBorderWindowConfiguration(), 
        configuration.GetShowMode());
}

/**
 * The SplitterSubWindowConfiguration constructor.
 */
SplitterSubWindowConfiguration::SplitterSubWindowConfiguration(
    int proportion, 
    int flag, 
    const IBorderWindowConfigurationSharedPtr borderWindowConfiguration, 
    bool showMode) : 
    m_proportion(proportion), 
    m_flag(flag), 
    m_borderWindowConfiguration(borderWindowConfiguration),
    m_showMode(showMode)
{
}

/**
 * The SplitterSubWindowConfiguration destructor.
 */
SplitterSubWindowConfiguration::~SplitterSubWindowConfiguration() 
{
}

/**
 * Gets a proportion of window.
 */
int SplitterSubWindowConfiguration::GetProportion() const 
{
    return m_proportion;
}

/**
 * Gets a flag of window.
 */
int SplitterSubWindowConfiguration::GetFlag() const
{
    return m_flag;
}

/**
 * Gets optional configuration of a border window.
 */
const IBorderWindowConfigurationSharedPtr SplitterSubWindowConfiguration::GetBorderWindowConfiguration() const 
{
    return m_borderWindowConfiguration;
}

/**
 * Gets show mode of window.
 */
bool SplitterSubWindowConfiguration::GetShowMode() const
{
    return m_showMode;
}

/**
 * Sets show mode of window.
 */
void SplitterSubWindowConfiguration::SetShowMode(bool mode)
{
    m_showMode = mode;
}
