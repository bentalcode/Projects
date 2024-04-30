#include "WindowsOperatingSystemType.h"
#include "NotImplementedException.h"

using namespace base;

/**
 * Checks whether this is an operating system based on the system value.
 */
bool WindowsOperatingSystemType::IsOperatingSystem(const std::wstring& value) const {
    throw NotImplementedException(L"WindowsOperatingSystemType::IsOperatingSystem");
}
