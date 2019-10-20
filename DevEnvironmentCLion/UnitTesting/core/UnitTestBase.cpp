#include "PreCompiled.h"

#include "UnitTestBase.h"
#include "UnitTestingException.h"

using namespace test_base;

/**
 * The UnitTestBase constructor.
 */
UnitTestBase::UnitTestBase(const std::string& name) :
    m_name(name)
{
}

/**
 * The UnitTestBase destructor.
 */
UnitTestBase::~UnitTestBase()
{
}

/**
  * Gets the name of the test.
  */
const std::string& UnitTestBase::getName() const
{
    return m_name;
}

/**
 * Runs the logic pre-running the test.
 */
void UnitTestBase::preRun()
{
}

/**
 * Runs the logic post running the test.
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
}

/**
 * Gets the log stream writer.
 */
base::LogStreamWriter& UnitTestBase::getLogStreamWriter()
{
    return *m_logStreamWriter;
}
