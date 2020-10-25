#include "PreCompiled.h"
#include "ConsoleColorSetter.h"

using namespace base;

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
    m_currAttributes(0)
{
    m_status = m_consoleColorHandler.get() != nullptr;

    if (!m_status)
    {
        return;
    }

    m_status = m_consoleColorHandler->getColorAttributes(
        m_fileDescriptor,
        m_currAttributes);

    if (!m_status)
    {
        return;
    }

    m_consoleColorHandler->setColorAttributes(
        m_fileDescriptor,
        m_newAttributes);
}

/**
 * The ConsoleColorSetter destructor.
 */
ConsoleColorSetter::~ConsoleColorSetter()
{
    if (m_status)
    {
        m_consoleColorHandler->setColorAttributes(
            m_fileDescriptor,
            m_currAttributes);
    }
}
