#include "PreCompiled.h"

#include "UnitTestBase.h"

using namespace test_base;

/**
 * The UnitTestBase constructor.
 */
UnitTestBase::UnitTestBase(const std::string& name) :
    m_name(name),
    m_stream(nullptr)
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
 * Sets the output stream.
 */
void UnitTestBase::setOutputStream(std::ostream& stream)
{
    m_stream = &stream;
}

/**
 * Gets the informational stream.
 */
std::ostream& UnitTestBase::getInformationalStream() const {
    if (m_stream == nullptr) {
        return std::cout;
    }
    else {
        return *m_stream;
    }
}

/**
 * Gets the warning stream.
 */
std::ostream& UnitTestBase::getWarningStream() const {
    if (m_stream == nullptr) {
        return std::cout;
    }
    else {
        return *m_stream;
    }
}

/**
 * Gets the error stream.
 */
std::ostream& UnitTestBase::getErrorStream() const {
    if (m_stream == nullptr) {
        return std::cout;
    }
    else {
        return *m_stream;
    }
}
