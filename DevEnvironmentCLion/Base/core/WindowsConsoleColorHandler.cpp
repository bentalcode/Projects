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

/**
 * Gets the attributes of a foreground color.
 */
unsigned short WindowsConsoleColorHandler::getForegroundColorAttributes(ColorType colorType) const
{
    static std::unique_ptr<ForegroundColorMap> colorMap(createForegroundColorMap());

    ForegroundColorMap::const_iterator colorIterator = colorMap->find(colorType);

    if (colorIterator == colorMap->end())
    {
        std::string errorMessage = "The color type for the specific foreground color is not defined.";
        throw BaseException(errorMessage);
    }

    return colorIterator->second;
}

/**
 * Creates the foreground color map.
 */
WindowsConsoleColorHandler::ForegroundColorMap* WindowsConsoleColorHandler::createForegroundColorMap()
{
    std::unique_ptr<ForegroundColorMap> colorMap = std::make_unique<ForegroundColorMap>();

    colorMap->insert(std::make_pair(ColorType::Black, 0));
    colorMap->insert(std::make_pair(ColorType::DarkBlue, FOREGROUND_BLUE));
    colorMap->insert(std::make_pair(ColorType::DarkGreen, FOREGROUND_GREEN));
    colorMap->insert(std::make_pair(ColorType::DarkCyan, FOREGROUND_GREEN | FOREGROUND_BLUE));
    colorMap->insert(std::make_pair(ColorType::DarkRed, FOREGROUND_RED));
    colorMap->insert(std::make_pair(ColorType::DarkMagenta, FOREGROUND_RED | FOREGROUND_BLUE));
    colorMap->insert(std::make_pair(ColorType::DarkYellow, FOREGROUND_RED | FOREGROUND_GREEN));
    colorMap->insert(std::make_pair(ColorType::DarkGray, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE));
    colorMap->insert(std::make_pair(ColorType::Gray, FOREGROUND_INTENSITY));
    colorMap->insert(std::make_pair(ColorType::Blue, FOREGROUND_INTENSITY | FOREGROUND_BLUE));
    colorMap->insert(std::make_pair(ColorType::Green, FOREGROUND_INTENSITY | FOREGROUND_GREEN));
    colorMap->insert(std::make_pair(ColorType::Cyan, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE));
    colorMap->insert(std::make_pair(ColorType::Red, FOREGROUND_INTENSITY | FOREGROUND_RED));
    colorMap->insert(std::make_pair(ColorType::Magenta, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE));
    colorMap->insert(std::make_pair(ColorType::Yellow, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN));
    colorMap->insert(std::make_pair(ColorType::White, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE));

    return colorMap.release();
}
