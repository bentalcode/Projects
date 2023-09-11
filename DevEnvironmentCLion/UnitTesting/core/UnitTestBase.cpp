#include "PreCompiled.h"

#include "UnitTestBase.h"
#include "UnitTestingException.h"

using namespace unit_testing;

/**
 * The UnitTestBase constructor.
 */
UnitTestBase::UnitTestBase(const std::string& name) :
    m_name(name),
    m_assertion(m_messageWriter)
{
}

/**
 * The UnitTestBase destructor.
 */
UnitTestBase::~UnitTestBase()
{
}

/**
  * Gets the name of the unit test.
  */
const std::string& UnitTestBase::getName() const
{
    return m_name;
}

/**
 * Runs the logic pre-running the tests.
 */
void UnitTestBase::preRun()
{
}

/**
 * Runs the logic post running the tests.
 */
void UnitTestBase::postRun()
{
}

/**
 * Sets the message writer.
 */
void UnitTestBase::setMessageWriter(base::IMessageWriterPtr messageWriter)
{
    if (!messageWriter)
    {
        std::string errorMessage = "The Message Writer is not defined.";
        throw UnitTestingException(errorMessage);
    }

    m_messageWriter = messageWriter;
    m_assertion.setMessageWriter(messageWriter);
}

/**
 * Gets the assertion.
 */
test_base::Assertion& UnitTestBase::getAssertion()
{
    return m_assertion;
}

/**
 * Gets the message writer.
 */
base::IMessageWriter& UnitTestBase::getMessageWriter()
{
    return *m_messageWriter;
}
