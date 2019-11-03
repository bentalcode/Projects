#include "PreCompiled.h"

#include "UnitTestBase.h"
#include "UnitTestingException.h"

using namespace unit_testing;

/**
 * The UnitTestBase constructor.
 */
UnitTestBase::UnitTestBase(const std::string& name) :
    m_name(name),
    m_assertion(m_logStreamWriter)
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
 * Sets the log stream writer.
 */
void UnitTestBase::setLogStreamWriter(base::LogStreamWriterPtr logStreamWriter)
{
    if (!logStreamWriter)
    {
        std::string errorMessage = "The Log Stream Writer has not been set.";
        throw UnitTestingException(errorMessage);
    }

    m_logStreamWriter = logStreamWriter;
    m_assertion.setLogStreamWriter(m_logStreamWriter);
}

/**
 * Gets the assertion.
 */
test_base::Assertion& UnitTestBase::getAssertion()
{
    return m_assertion;
}

/**
 * Gets the log stream writer.
 */
base::LogStreamWriter& UnitTestBase::getLogStreamWriter()
{
    return *m_logStreamWriter;
}
