#include "PreCompiled.h"
#include "MessageWriter.h"
#include "WindowsConsoleColorHandler.h"
#include "ConsoleColorSetter.h"

using namespace base;

/**
 * Creates a new message writer.
 */
IMessageWriterSharedPtr MessageWriter::make()
{
    return std::make_shared<MessageWriter>(
        std::cout,
        std::cout,
        std::cout,
        std::cout,
        createConsoleColorHandler());
}

/**
 * Creates a new message writer with no console color handler.
 */
IMessageWriterSharedPtr MessageWriter::makeLight()
{
    return std::make_shared<MessageWriter>(
        std::cout,
        std::cout,
        std::cout,
        std::cout,
        nullptr);
}

/**
 * The MessageWriter constructor.
 */
MessageWriter::MessageWriter(
    std::ostream& informationalStream,
    std::ostream& warningStream,
    std::ostream& errorStream,
    std::ostream& debugStream,
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
void MessageWriter::writeInformationalMessage(const std::string& message)
{
    base::ConsoleColorSetter consoleColorSetter(
        m_consoleColorHandler,
        base::StandardFileDescriptor::StandardOutput,
        ColorType::Green);

    writeMessage(message, m_informationalStream);
}

/**
 * Writes a warning message.
 */
void MessageWriter::writeWarningMessage(const std::string& message)
{
    base::ConsoleColorSetter consoleColorSetter(
        m_consoleColorHandler,
        base::StandardFileDescriptor::StandardError,
        ColorType::Yellow);

    writeMessage(message, m_warningStream);
}

/**
 * Writes an error message.
 */
void MessageWriter::writeErrorMessage(const std::string& message)
{
    base::ConsoleColorSetter consoleColorSetter(
        m_consoleColorHandler,
        base::StandardFileDescriptor::StandardError,
        ColorType::Green);

    writeMessage(message, m_errorStream);
}

/**
 * Writes a debug message.
 */
void MessageWriter::writeDebugMessage(const std::string& message)
{
    base::ConsoleColorSetter consoleColorSetter(
        m_consoleColorHandler,
        base::StandardFileDescriptor::StandardOutput,
        ColorType::Green);

    writeMessage(message, m_debugStream);
}

/**
 * Writes a message to an output stream.
 */
void MessageWriter::writeMessage(
    const std::string& message,
    std::ostream& ostream)
{
    ostream << message << std::endl;
}

/**
 * Creates a console color handler.
 */
base::IConsoleColorHandlerSharedPtr MessageWriter::createConsoleColorHandler()
{
    #if defined(WIN32)
        return std::make_shared<base::WindowsConsoleColorHandler>();
    # else
        return nullptr;
    #endif
}
