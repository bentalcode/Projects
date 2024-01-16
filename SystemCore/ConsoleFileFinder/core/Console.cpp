#include "Console.h"
#include <iostream>

using namespace consolefilefinder;

/**
 * Creates a console.
 */
IConsoleSharedPtr Console::Make(std::wostream& stream)
{
    return std::make_shared<Console>(stream);
}

/**
 * The Console constructor.
 */
Console::Console(std::wostream& stream) :
    m_stream(stream)
{
}

/**
 * The Console destructor.
 */
Console::~Console()
{
}

/**
 * Writes a line to console.
 */
void Console::WriteLine(const std::wstring& content)
{
    m_stream << content << std::endl;
}
