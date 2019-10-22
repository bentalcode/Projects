#include "PreCompiled.h"

#include "UnitTestManager.h"
#include "UnitTestHandler.h"
#include "UnitTestingException.h"
#include "UnitTestException.h"

using namespace unit_testing;

class UnitTestPredicate //: public unary_function<IUnitTestPtr, bool>
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
    unitTest->setLogStreamWriter(m_logStreamWriter);
    m_unitTests.push_back(unitTest);
}

/**
 * Unregisters a test.
 */
void UnitTestManager::unregisterTest(IUnitTestPtr unitTest)
{
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
    for (UnitTestList::const_iterator i = m_unitTests.begin(); i != m_unitTests.end(); ++i) {
        IUnitTestPtr unitTest = *i;

        runTest(*unitTest);
    }

    m_logStreamWriter->getInformationalStream() << m_unitTestRunningResults;
}

/**
 * Runs a test.
 */
void UnitTestManager::runTest(IUnitTest& unitTest)
{
    try
    {
        UnitTestHandler unitTestHandler(unitTest, *m_logStreamWriter);
        unitTestHandler.run();

        setSuccessfulRunningResult(unitTest);
    }
    catch (UnitTestException& e)
    {
        std::stringstream errorMessageStream;
        errorMessageStream
            << "The unit test: " << unitTest.getName() << " failed due to the following error: "
            << e.getErrorMessage();

        std::string errorMessage = errorMessageStream.str();

        m_logStreamWriter->getErrorStream() << std::endl << errorMessage << std::endl;

        setFailedRunningResult(
            unitTest,
            errorMessage);
    }
    catch (std::exception& e)
    {
        std::stringstream errorMessageStream;
        errorMessageStream
            << "The unit test: " << unitTest.getName() << " failed due to an expected exception: "
            << e.what();

        std::string errorMessage = errorMessageStream.str();

        setFailedRunningResult(
            unitTest,
            errorMessage);
    }
}

/**
 * Sets a successful running result of a unit test
 */
void UnitTestManager::setSuccessfulRunningResult(IUnitTest& unitTest)
{
    m_unitTestRunningResults.setSuccessfulRunningResult(unitTest);
    m_logStreamWriter->getInformationalStream() << "Unit Test: " << unitTest.getName() << " Passed." << std::endl;
}

/**
 * Sets a failed running result of a unit test
 */
void UnitTestManager::setFailedRunningResult(IUnitTest& unitTest, const std::string& errorMessage)
{
    m_unitTestRunningResults.setFailedRunningResult(unitTest, errorMessage);
    m_logStreamWriter->getInformationalStream() << "Unit Test: " << unitTest.getName() << " Failed." << std::endl;
}

