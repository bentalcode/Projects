#include "PreCompiled.h"

#include "Assertion.h"
#include "MessageWriter.h"
#include "TestBaseException.h"

using namespace test_base;

/**
 * The Assertion constructor.
 */
Assertion::Assertion() :
    Assertion(base::MessageWriter::make())
{
}

/**
 * The Assertion constructor.
 */
Assertion::Assertion(base::IMessageWriterPtr messageWriter) :
    m_messageWriter(messageWriter)
{
}

/**
 * The Assertion destructor.
 */
Assertion::~Assertion()
{
}

/**
 * Asserts true.
 */
void Assertion::assertTrue(
    bool expression,
    const std::string& message)
{
    if (!expression)
    {
        if (m_messageWriter)
        {
            m_messageWriter->writeErrorMessage(message);
        }

        throw TestBaseException(message);
    }
}

/**
 * Sets the message writer.
 */
void Assertion::setMessageWriter(base::IMessageWriterPtr messageWriter)
{
    if (!messageWriter)
    {
        std::string errorMessage = "The Message Writer is not defined.";
        throw TestBaseException(errorMessage);
    }

    m_messageWriter = messageWriter;
}

