#include "PreCompiled.h"

#include "Assertion.h"
#include "TestBaseException.h"

using namespace test_base;

/**
 * The Assertion constructor.
 */
Assertion::Assertion() :
    m_logStreamWriter(new base::LogStreamWriter())
{
}

/**
 * The Assertion constructor.
 */
Assertion::Assertion(base::LogStreamWriterPtr logStreamWriter) :
    m_logStreamWriter(logStreamWriter)
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
        if (m_logStreamWriter)
        {
            m_logStreamWriter->getErrorStream() << message << std::endl;
        }

        throw TestBaseException(message);
    }
}

/**
 * Sets the log stream writer.
 */
void Assertion::setLogStreamWriter(base::LogStreamWriterPtr logStreamWriter)
{
    if (!logStreamWriter)
    {
        std::string errorMessage = "The Log Stream Writer has not been set.";
        throw TestBaseException(errorMessage);
    }

    m_logStreamWriter = logStreamWriter;
}

