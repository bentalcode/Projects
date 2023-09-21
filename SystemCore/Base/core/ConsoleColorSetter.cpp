#include "ConsoleColorSetter.h"
#include <assert.h>

using namespace base;

/**
 * The WindowsConsoleColorHandler constructor.
 */
ConsoleColorSetter::ConsoleColorSetter(
    IConsoleColorHandlerSharedPtr consoleColorHandler,
    StandardFileDescriptor fileDescriptor,
    ColorType colorType) :
    ConsoleColorSetter(
        consoleColorHandler,
        fileDescriptor,
        consoleColorHandler ? consoleColorHandler->GetForegroundColorAttributes(colorType) : 0)
{
}

/**
 * The ConsoleColorSetter constructor.
 */
ConsoleColorSetter::ConsoleColorSetter(
    IConsoleColorHandlerSharedPtr consoleColorHandler,
    StandardFileDescriptor fileDescriptor,
    unsigned short attributes) :
    m_consoleColorHandler(consoleColorHandler),
    m_fileDescriptor(fileDescriptor),
    m_newAttributes(attributes),
    m_currAttributes(0)
{
    m_active = Initialize();
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

    bool status = m_consoleColorHandler->SetColorAttributes(
        m_fileDescriptor,
        m_currAttributes);

    assert(status);
}

/**
 * Initializes the console color setter.
 */
bool ConsoleColorSetter::Initialize()
{
    bool status = m_consoleColorHandler.get() != nullptr;

    if (!status)
    {
        return status;
    }

    status = m_consoleColorHandler->GetColorAttributes(
        m_fileDescriptor,
        m_currAttributes);

    if (!status)
    {
        return status;
    }

    status = m_consoleColorHandler->SetColorAttributes(
        m_fileDescriptor,
        m_newAttributes);

    return status;
}
