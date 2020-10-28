#include "PreCompiled.h"
#include "ConsoleColorSetter.h"
#include "LogFactory.h"

using namespace base;

/**
 * The WindowsConsoleColorHandler constructor.
 */
ConsoleColorSetter::ConsoleColorSetter(
    IConsoleColorHandlerPtr consoleColorHandler,
    StandardFileDescriptor fileDescriptor,
    ColorType colorType) :
    ConsoleColorSetter(
        consoleColorHandler,
        fileDescriptor,
        consoleColorHandler ? consoleColorHandler->getForegroundColorAttributes(colorType) : 0)
{
}

/**
 * The ConsoleColorSetter constructor.
 */
ConsoleColorSetter::ConsoleColorSetter(
    IConsoleColorHandlerPtr consoleColorHandler,
    StandardFileDescriptor fileDescriptor,
    unsigned short attributes) :
    m_consoleColorHandler(consoleColorHandler),
    m_fileDescriptor(fileDescriptor),
    m_newAttributes(attributes),
    m_currAttributes(0),
    m_log(LogFactory::getInstance().getLog("ConsoleColorSetter"))
{
    m_active = initialize();
}

/**
 * The ConsoleColorSetter destructor.
 */
ConsoleColorSetter::~ConsoleColorSetter()
{
    if (!m_active)
    {
        return;
    }

    bool status = m_consoleColorHandler->setColorAttributes(
        m_fileDescriptor,
        m_currAttributes);

    if (!status)
    {
        m_log->writeDebugMessage(
            "The console settings failed to get reverted to: " + std::to_string(m_currAttributes));

        return;
    }

    m_log->writeDebugMessage(
        "The console settings got reverted successfully to: " + std::to_string(m_currAttributes));
}

/**
 * Initializes the console color setter.
 */
bool ConsoleColorSetter::initialize()
{
    bool status = m_consoleColorHandler.get() != nullptr;

    if (!status)
    {
        return status;
    }

    status = m_consoleColorHandler->getColorAttributes(
        m_fileDescriptor,
        m_currAttributes);

    if (!status)
    {
        m_log->writeDebugMessage(
            "The current console settings failed to get read.");

        return status;
    }

    m_log->writeDebugMessage(
        "The current console settings are: " + std::to_string(m_currAttributes));

    status = m_consoleColorHandler->setColorAttributes(
        m_fileDescriptor,
        m_newAttributes);

    if (!status)
    {
        m_log->writeDebugMessage(
            "The console settings failed to get updated to: " + std::to_string(m_newAttributes));
    }

    m_log->writeDebugMessage(
        "The console settings got updated successfully to: " + std::to_string(m_newAttributes));

    return status;
}
