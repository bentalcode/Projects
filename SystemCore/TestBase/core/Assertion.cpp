#include "Assertion.h"
#include "MessageWriter.h"
#include "TestBaseException.h"
#include "SmartPointers.h"

using namespace test_base;

/**
 * The Assertion constructor.
 */
Assertion::Assertion() :
    Assertion(base::MessageWriter::Make())
{
}

/**
 * The Assertion constructor.
 */
Assertion::Assertion(base::IMessageWriterSharedPtr messageWriter) :
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
void Assertion::AssertTrue(
    bool expression,
    const std::wstring& message)
{
    if (!expression)
    {
        if (m_messageWriter)
        {
            m_messageWriter->WriteErrorMessage(message);
        }

        long statusCode = base::ErrorCodes::FAIL;
        throw TestBaseException(statusCode, message);
    }
}

/**
 * Sets the message writer.
 */
void Assertion::setMessageWriter(base::IMessageWriterSharedPtr messageWriter)
{
    base::SmartPointers::Validate<base::IMessageWriter>(messageWriter);
    m_messageWriter = messageWriter;
}

