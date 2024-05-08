#include "SliderConfiguration.h"

using namespace GuiConfiguration;

/**
 * Creates slider configuration.
 */
ISliderConfigurationSharedPtr SliderConfiguration::Make(
    unsigned int minNumberOfUnits, 
    unsigned int maxNumberOfUnits)
{
    return std::make_shared<SliderConfiguration>(
        minNumberOfUnits, 
        maxNumberOfUnits);
}

/**
 * The SliderConfiguration constructor.
 */
SliderConfiguration::SliderConfiguration(
    unsigned int minNumberOfUnits, 
    unsigned int maxNumberOfUnits) : 
    m_minNumberOfUnits(minNumberOfUnits), 
    m_maxNumberOfUnits(maxNumberOfUnits)
{
}

/**
 * The SliderConfiguration destructor.
 */
SliderConfiguration::~SliderConfiguration() 
{
}

/**
 * Gets minimum number of units.
 */
unsigned int SliderConfiguration::GetMinNumberOfUnits() const 
{
    return m_minNumberOfUnits;
}

/**
 * Gets maximum number of units.
 */
unsigned int SliderConfiguration::GetMaxNumberOfUnits() const
{
    return m_maxNumberOfUnits;
}
