#include "PreCompiled.h"

#include "UnitTestManager.h"
#include "MessageWriter.h"
#include "UnitTestHandler.h"
#include "UnitTestingException.h"

using namespace unit_testing;

class UnitTestPredicate final
{
public:
    UnitTestPredicate(const std::string& name) :
        m_name(name)
    {
    }

    bool operator()(IUnitTestSharedPtr unitTest)
    {
        return m_name == unitTest->getName();
    }

private:
    std::string m_name;
};

/**
 * The UnitTestManager default constructor.
 */
UnitTestManager::UnitTestManager() :
    UnitTestManager(base::MessageWriter::make())
{
}

/**
 * The UnitTestManager constructor.
 */
UnitTestManager::UnitTestManager(base::IMessageWriterSharedPtr messageWriter)
{
    if (!messageWriter)
    {
        std::string errorMessage = "The Message Writer is not defined.";
        throw UnitTestingException(errorMessage);
    }

    m_messageWriter = messageWriter;
}

/**
 * The UnitTestManager destructor.
 */
UnitTestManager::~UnitTestManager()
{
}

/**
 * Registers a test.
 */
void UnitTestManager::registerTest(IUnitTestSharedPtr unitTest)
{
    if (!unitTest)
    {
        std::string errorMessage = "The Unit Test is not defined.";
        throw UnitTestingException(errorMessage);
    }

    unitTest->setMessageWriter(m_messageWriter);
    m_unitTests.push_back(unitTest);
}

/**
 * Unregisters a test.
 */
void UnitTestManager::unregisterTest(IUnitTestSharedPtr unitTest)
{
    if (!unitTest)
    {
        std::string errorMessage = "The Unit Test is not defined.";
        throw UnitTestingException(errorMessage);
    }

    UnitTestPredicate unitTestPredicate(unitTest->getName());
    m_unitTests.erase(
        remove_if(m_unitTests.begin(), m_unitTests.end(), unitTestPredicate),
        m_unitTests.end());
}

/**
 * Runs the registered tests.
 */
void UnitTestManager::run()
{
    m_unitTestRunningResults.setStartTime();

    for (IUnitTestSharedPtr unitTest : m_unitTests)
    {
        runUnitTest(*unitTest);
    }

    m_unitTestRunningResults.setEndTime();

    m_unitTestRunningResults.write(*m_messageWriter);
}

/**
 * Runs a unit test.
 */
void UnitTestManager::runUnitTest(IUnitTest& unitTest)
{
    unit_testing::UnitTestHandler unitTestHandler(unitTest, *m_messageWriter);

    const ITestRunningResults& runningResults = unitTestHandler.run();

    m_unitTestRunningResults.add(runningResults);
}
