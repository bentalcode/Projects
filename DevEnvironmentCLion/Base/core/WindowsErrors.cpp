#include "PreCompiled.h"
#include "LocalFreeReleaser.h"

using namespace base;

/**
 * Gets the last windows errors as a string.
 */
std::string WindowsErrors::getLastErrorAsString()
{
    DWORD messageId = ::GetLastError();

    if (messageId == 0)
    {
        return "";
    }

    LPSTR messageBuffer = nullptr;
    DWORD size = FormatMessageA(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        messageId,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        reinterpret_cast<LPSTR>(&messageBuffer),
        0,
        NULL);

    LocalFreeReleaser messagePtr(messageBuffer);

    std::string message(messageBuffer, size);

    return message;
}