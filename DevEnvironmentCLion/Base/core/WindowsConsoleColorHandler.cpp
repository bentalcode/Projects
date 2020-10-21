#include "PreCompiled.h"
#include "WindowsConsoleColorHandler.h"

using namespace base;

/**
 * The WindowsConsoleColorHandler constructor.
 */
WindowsConsoleColorHandler::WindowsConsoleColorHandler()
{
}

/**
 * The WindowsConsoleColorHandler destructor.
 */
WindowsConsoleColorHandler::~WindowsConsoleColorHandler()
{
}

/**
 * Gets the current color attributes.
 * Returns true if the functions succeeds, otherwise false.
 */
bool WindowsConsoleColorHandler::getColorAttributes(
    StandardFileDescriptor fileDescriptor,
    unsigned short& result) const
{
    HANDLE handle = getFileDescriptorHandle(fileDescriptor);

    CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
    ::SecureZeroMemory(&screenBufferInfo, sizeof(CONSOLE_SCREEN_BUFFER_INFO));

    if (!GetConsoleScreenBufferInfo(handle, &screenBufferInfo))
    {
        return false;
    }

    WORD oldColorAttributes = screenBufferInfo.wAttributes;
    result = oldColorAttributes;

    return true;
}

/**
 * Sets the current color attributes.
 * Returns true if the functions succeeds, otherwise false.
 */
bool WindowsConsoleColorHandler::setColorAttributes(
    StandardFileDescriptor fileDescriptor,
    unsigned short attributes)
{
    HANDLE handle = getFileDescriptorHandle(fileDescriptor);
    WORD colorAttributes = attributes;

    return SetConsoleTextAttribute(handle, colorAttributes);
}

/**
 * Gets the handle of the file descriptor.
 */
HANDLE WindowsConsoleColorHandler::getFileDescriptorHandle(StandardFileDescriptor fileDescriptor)
{
    if (fileDescriptor == StandardFileDescriptor::StandardInput)
    {
        return GetStdHandle(STD_INPUT_HANDLE);
    }
    else if (fileDescriptor == StandardFileDescriptor::StandardOutput)
    {
        return GetStdHandle(STD_OUTPUT_HANDLE);
    }
    else if (fileDescriptor == StandardFileDescriptor::StandardError)
    {
        return GetStdHandle(STD_ERROR_HANDLE);
    }
    else
    {
        assert(false);
        std::string errorMessage = "The standard file descriptor is not supported.";
        throw BaseException(errorMessage);
    }
}
