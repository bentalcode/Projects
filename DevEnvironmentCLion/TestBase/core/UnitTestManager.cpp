#include "PreCompiled.h"

#include "UnitTestManager.h"
#include "UnitTestException.h"

using namespace test_base;

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
 * The UnitTestManager constructor.
 */
UnitTestManager::UnitTestManager() :
    m_errorStream(std::cout),
    m_warningStream(std::cout),
    m_informationalStream(std::cout),
    m_debugStream(std::cout)
{
}

/**
 * The UnitTestManager constructor.
 */
UnitTestManager::UnitTestManager(
    std::ostream& errorStream,
    std::ostream& warningStream,
    std::ostream& informationalStream,
    std::ostream& debugStream) :
    m_errorStream(errorStream),
    m_warningStream(warningStream),
    m_informationalStream(informationalStream),
    m_debugStream(debugStream)
{
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
    unitTest->setOutputStreams(
        m_errorStream,
        m_warningStream,
        m_informationalStream,
        m_debugStream);

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

    m_informationalStream << m_unitTestRunningResults;
}

/**
 * Runs a test.
 */
void UnitTestManager::runTest(IUnitTest& unitTest)
{
    try
    {
        unitTest.preRun();
        unitTest.run();
        unitTest.postRun();

        setSuccessfulRunningResult(unitTest);
    }
    catch (UnitTestException& e)
    {
        std::stringstream errorMessageStream;
        errorMessageStream
            << "The unit test: " << unitTest.getName() << " failed due to the following error: "
            << e.getErrorMessage();

        std::string errorMessage = errorMessageStream.str();

        m_errorStream << std::endl << errorMessage << std::endl;

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
    m_informationalStream << "Unit Test: " << unitTest.getName() << " Passed." << std::endl;
}

/**
 * Sets a failed running result of a unit test
 */
void UnitTestManager::setFailedRunningResult(IUnitTest& unitTest, const std::string& errorMessage)
{
    m_unitTestRunningResults.setFailedRunningResult(unitTest, errorMessage);
    m_informationalStream << "Unit Test: " << unitTest.getName() << " Failed." << std::endl;
}

