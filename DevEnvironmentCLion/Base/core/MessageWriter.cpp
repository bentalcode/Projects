#include "PreCompiled.h"
#include "MessageWriter.h"
#include "WindowsConsoleColorHandler.h"
#include "ConsoleColorSetter.h"

using namespace base;

/**
 * Creates a new message writer.
 */
IMessageWriterPtr MessageWriter::make()
{
    return std::make_shared<MessageWriter>();
}

/**
 * The MessageWriter constructor.
 */
MessageWriter::MessageWriter() :
    MessageWriter(
        std::cout,
        std::cout,
        std::cout,
        std::cout,
        createConsoleColorHandler())
{
}

/**
 * The MessageWriter constructor.
 */
MessageWriter::MessageWriter(
    std::ostream& informationalStream,
    std::ostream& warningStream,
    std::ostream& errorStream,
    std::ostream& debugStream,
    base::IConsoleColorHandlerPtr consoleColorHandler) :
    m_informationalStream(std::cout),
    m_warningStream(std::cout),
    m_errorStream(std::cout),
    m_debugStream(std::cout),
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
        m_consoleColorHandler->getForegroundColorAttributes(ColorType::Green));

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
        m_consoleColorHandler->getForegroundColorAttributes(ColorType::Yellow));

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
        m_consoleColorHandler->getForegroundColorAttributes(ColorType::Red));

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
        m_consoleColorHandler->getForegroundColorAttributes(ColorType::Green));

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
base::IConsoleColorHandlerPtr MessageWriter::createConsoleColorHandler()
{
    #if defined(WIN32)
        return std::make_shared<base::WindowsConsoleColorHandler>();
    # else
        return nullptr;
    #endif
}
