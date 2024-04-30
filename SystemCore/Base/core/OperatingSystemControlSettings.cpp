#include "OperatingSystemControlSettings.h"
#include "SmartPointers.h"

using namespace base::environment;

/**
 * The OperatingSystemControlSettings constructor.
 */
OperatingSystemControlSettings::OperatingSystemControlSettings(const IOperatingSystemPathSettingsSharedPtr pathSettings) :
    m_pathSettings(SmartPointers::ValidateAndReturn(pathSettings))
{
}

/**
 * The OperatingSystemControlSettings destructor.
 */
OperatingSystemControlSettings::~OperatingSystemControlSettings()
{
}

/**
 * Gets paths settings.
 */
IOperatingSystemPathSettingsSharedPtr OperatingSystemControlSettings::GetPathSettings() const
{
    return m_pathSettings;
}
