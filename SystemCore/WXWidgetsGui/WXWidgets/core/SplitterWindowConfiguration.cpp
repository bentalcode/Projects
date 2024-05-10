#include "SplitterWindowConfiguration.h"
#include "SmartPointers.h"

using namespace wxwidgets;

/**
 * Creates a configuration of a splitter window.
 */
ISplitterWindowConfigurationSharedPtr SplitterWindowConfiguration::Make(
    double gravity, 
    bool initializeInBoxSizer,
    const ISplitterSubWindowConfigurationSharedPtr firstWindowConfiguration,
    const ISplitterSubWindowConfigurationSharedPtr secondWindowConfiguration)
{
    return std::make_shared<SplitterWindowConfiguration>(
        gravity, 
        initializeInBoxSizer, 
        firstWindowConfiguration,
        secondWindowConfiguration);
}

/**
 * Copies a configuration of a splitter window.
 */
ISplitterWindowConfigurationSharedPtr SplitterWindowConfiguration::Copy(ISplitterWindowConfiguration& configuration)
{ 
    return SplitterWindowConfiguration::Make(
        configuration.GetGravity(), 
        configuration.InitializeInBoxSizer(), 
        configuration.GetFirstWindowConfiguration(),
        configuration.GetSecondWindowConfiguration());
}

/**
 * The SplitterWindowConfiguration constructor.
 */
SplitterWindowConfiguration::SplitterWindowConfiguration(
    double gravity, 
    bool initializeInBoxSizer, 
    const ISplitterSubWindowConfigurationSharedPtr firstWindowConfiguration,
    const ISplitterSubWindowConfigurationSharedPtr secondWindowConfiguration) : 
    m_gravity(gravity), 
    m_initializeInBoxSizer(initializeInBoxSizer)
{
    base::SmartPointers::Validate<ISplitterSubWindowConfiguration>(firstWindowConfiguration);
    base::SmartPointers::Validate<ISplitterSubWindowConfiguration>(secondWindowConfiguration);

    m_firstWindowConfiguration = firstWindowConfiguration;
    m_secondWindowConfiguration = secondWindowConfiguration;
}

/**
 * The SplitterWindowConfiguration destructor.
 */
SplitterWindowConfiguration::~SplitterWindowConfiguration() 
{
}

/**
 * Get the sash gravity.
 */
double SplitterWindowConfiguration::GetGravity() const
{
    return m_gravity;
}

/**
 * Inititaizes in a box sizer.
 */
bool SplitterWindowConfiguration::InitializeInBoxSizer() const
{
    return m_initializeInBoxSizer;
}

/**
 * Gets a configuration of first window.
 */
const ISplitterSubWindowConfigurationSharedPtr SplitterWindowConfiguration::GetFirstWindowConfiguration() const
{
    return m_firstWindowConfiguration;
}

/**
 * Gets a configuration of second window.
 */
const ISplitterSubWindowConfigurationSharedPtr SplitterWindowConfiguration::GetSecondWindowConfiguration() const
{
    return m_secondWindowConfiguration;
}
