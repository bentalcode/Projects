#include "PreCompiled.h"

#include "UnitTestBase.h"

using namespace test_base;

/**
 * The UnitTestBase constructor.
 */
UnitTestBase::UnitTestBase(const std::string& name) :
    m_name(name),
    m_errorStream(nullptr),
    m_warningStream(nullptr),
    m_informationalStream(nullptr),
    m_debugStream(nullptr)
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
 * Sets the output streams.
 */
void UnitTestBase::setOutputStreams(
    std::ostream& errorStream,
    std::ostream& warningStream,
    std::ostream& informationalStream,
    std::ostream& debugStream)
{
    m_errorStream = &errorStream;
    m_warningStream = &warningStream;
    m_informationalStream = &informationalStream;
    m_debugStream = &debugStream;
}

/**
 * Gets the error stream.
 */
std::ostream& UnitTestBase::getErrorStream() const {
    if (m_errorStream == nullptr) {
        return std::cout;
    }
    else {
        return *m_errorStream;
    }
}

/**
 * Gets the warning stream.
 */
std::ostream& UnitTestBase::getWarningStream() const {
    if (m_warningStream == nullptr) {
        return std::cout;
    }
    else {
        return *m_warningStream;
    }
}

/**
 * Gets the informational stream.
 */
std::ostream& UnitTestBase::getInformationalStream() const {
    if (m_informationalStream == nullptr) {
        return std::cout;
    }
    else {
        return *m_informationalStream;
    }
}

/**
 * Gets the debug stream.
 */
std::ostream& UnitTestBase::getDebugStream() const {
    if (m_debugStream == nullptr) {
        return std::cout;
    }
    else {
        return *m_debugStream;
    }
}
