#include "UnitTestBase.h"
#include "UnitTestingException.h"
#include "SmartPointers.h"

using namespace unit_testing;

/**
 * The UnitTestBase constructor.
 */
UnitTestBase::UnitTestBase(const std::wstring& name) :
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
const std::wstring& UnitTestBase::GetName() const
{
    return m_name;
}

/**
 * Runs the logic pre-running the tests.
 */
void UnitTestBase::PreRun()
{
}

/**
 * Runs the logic post running the tests.
 */
void UnitTestBase::PostRun()
{
}

/**
 * Sets the message writer.
 */
void UnitTestBase::SetMessageWriter(base::IMessageWriterSharedPtr messageWriter)
{
    base::SmartPointers::Validate<base::IMessageWriter>(messageWriter);

    m_messageWriter = messageWriter;
    m_assertion.setMessageWriter(messageWriter);
}

/**
 * Gets the assertion.
 */
test_base::Assertion& UnitTestBase::GetAssertion()
{
    return m_assertion;
}

/**
 * Gets the message writer.
 */
base::IMessageWriter& UnitTestBase::GetMessageWriter()
{
    return *m_messageWriter;
}
