#include "PreCompiled.h"

#include "UnitTestManager.h"
#include "UnitTestHandler.h"
#include "UnitTestingException.h"

using namespace unit_testing;

class UnitTestPredicate : public std::unary_function<IUnitTestPtr, bool>
{
public:
    UnitTestPredicate(const std::string& name) :
        m_name(name)
    {
    }

    bool operator()(IUnitTestPtr unitTest) {
        return m_name == unitTest->getName();
    }

private:
    std::string m_name;
};

/**
 * The UnitTestManager default constructor.
 */
UnitTestManager::UnitTestManager() :
    m_logStreamWriter(new base::LogStreamWriter)
{
}

/**
 * The UnitTestManager constructor.
 */
UnitTestManager::UnitTestManager(base::LogStreamWriterPtr logStreamWriter)
{
    if (!logStreamWriter) {
        std::string errorMessage = "The Log Stream Writer has not been set.";
        throw UnitTestingException(errorMessage);
    }

    m_logStreamWriter = logStreamWriter;
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
void UnitTestManager::registerTest(IUnitTestPtr unitTest)
{
    if (!unitTest) {
        std::string errorMessage = "The Unit Test has not been set.";
        throw UnitTestingException(errorMessage);
    }

    unitTest->setLogStreamWriter(m_logStreamWriter);
    m_unitTests.push_back(unitTest);
}

/**
 * Unregisters a test.
 */
void UnitTestManager::unregisterTest(IUnitTestPtr unitTest)
{
    if (!unitTest) {
        std::string errorMessage = "The Unit Test has not been set.";
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

    for (UnitTestList::const_iterator i = m_unitTests.begin(); i != m_unitTests.end(); ++i) {
        IUnitTestPtr unitTest = *i;

        runUnitTest(*unitTest);
    }

    m_unitTestRunningResults.setEndTime();

    m_logStreamWriter->getInformationalStream() << m_unitTestRunningResults;
}

/**
 * Runs a unit test.
 */
void UnitTestManager::runUnitTest(IUnitTest& unitTest)
{
    UnitTestHandler unitTestHandler(unitTest, *m_logStreamWriter);
    const ITestRunningResults& runningResults = unitTestHandler.run();

    m_logStreamWriter->getInformationalStream() << runningResults;

    m_unitTestRunningResults.add(runningResults);
}
