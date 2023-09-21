#include "MessageWriter.h"
#include "WindowsConsoleColorHandler.h"
#include "ConsoleColorSetter.h"
#include <iostream>

using namespace base;

/**
 * Creates a new message writer.
 */
IMessageWriterSharedPtr MessageWriter::Make()
{
    return std::make_shared<MessageWriter>(
        std::wcout,
        std::wcout,
        std::wcout,
        std::wcout,
        CreateConsoleColorHandler());
}

/**
 * Creates a new message writer with no console color handler.
 */
IMessageWriterSharedPtr MessageWriter::MakeLight()
{
    return std::make_shared<MessageWriter>(
        std::wcout,
        std::wcout,
        std::wcout,
        std::wcout,
        nullptr);
}

/**
 * The MessageWriter constructor.
 */
MessageWriter::MessageWriter(
    std::wostream& informationalStream,
    std::wostream& warningStream,
    std::wostream& errorStream,
    std::wostream& debugStream,
    base::IConsoleColorHandlerSharedPtr consoleColorHandler) :
    m_informationalStream(informationalStream),
    m_warningStream(warningStream),
    m_errorStream(errorStream),
    m_debugStream(debugStream),
    m_consoleColorHandler(consoleColorHandler)
{
}

/**
 * The MessageWriter destructor.
 */
MessageWriter::~MessageWriter()
{
}

/**
 * Writes an informational message.
 */
void MessageWriter::WriteInformationalMessage(const std::wstring& message)
{
    base::ConsoleColorSetter consoleColorSetter(
        m_consoleColorHandler,
        base::StandardFileDescriptor::StandardOutput,
        ColorType::Green);

    WriteMessage(message, m_informationalStream);
}

/**
 * Writes a warning message.
 */
void MessageWriter::WriteWarningMessage(const std::wstring& message)
{
    base::ConsoleColorSetter consoleColorSetter(
        m_consoleColorHandler,
        base::StandardFileDescriptor::StandardError,
        ColorType::Yellow);

    WriteMessage(message, m_warningStream);
}

/**
 * Writes an error message.
 */
void MessageWriter::WriteErrorMessage(const std::wstring& message)
{
    base::ConsoleColorSetter consoleColorSetter(
        m_consoleColorHandler,
        base::StandardFileDescriptor::StandardError,
        ColorType::Green);

    WriteMessage(message, m_errorStream);
}

/**
 * Writes a debug message.
 */
void MessageWriter::WriteDebugMessage(const std::wstring& message)
{
    base::ConsoleColorSetter consoleColorSetter(
        m_consoleColorHandler,
        base::StandardFileDescriptor::StandardOutput,
        ColorType::Green);

    WriteMessage(message, m_debugStream);
}

/**
 * Writes a message to an output stream.
 */
void MessageWriter::WriteMessage(
    const std::wstring& message,
    std::wostream& ostream)
{
    ostream << message << std::endl;
}

/**
 * Creates a console color handler.
 */
base::IConsoleColorHandlerSharedPtr MessageWriter::CreateConsoleColorHandler()
{
    #if defined(WINDOWS)
        return std::make_shared<WindowsConsoleColorHandler>();
    # else
        return nullptr;
    #endif
}
