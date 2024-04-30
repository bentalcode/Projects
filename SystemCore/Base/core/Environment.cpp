#include "Environment.h"

using namespace base::environment;

/**
 * Gets the current type of the operating system.
 */
OperatingSystemType Environment::GetOperatingSystem()
{
    return OperatingSystemType::OPERATING_SYSTEM_WINDOWS;
}
