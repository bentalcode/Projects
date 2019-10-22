#include "PreCompiled.h"

#include "UnitTestHandler.h"
#include "UnitTestingException.h"
#include "UnitTestException.h"

using namespace unit_testing;

/**
 * The UnitTestHandler constructor.
 */
UnitTestHandler::UnitTestHandler(
    IUnitTest& unitTest,
    base::LogStreamWriter& logStreamWriter) :
    m_unitTest(unitTest),
    m_logStreamWriter(logStreamWriter)
{
}

/**
 * The UnitTestHandler destructor.
 */
UnitTestHandler::~UnitTestHandler()
{
}

/**
 * Registers a test.
 */
void UnitTestHandler::registerTest(ITestFunctionPtr testFunction)
{
    if (!testFunction)
    {
        std::string errorMessage = "The test function of a unit test has not been defined.";
        throw UnitTestingException(errorMessage);
    }

    m_unitTests.push_back(testFunction);
}

/**
 * Runs the registered tests.
 */
void UnitTestHandler::run()
{
    //
    // Registers the tests...
    //
    m_unitTest.registerTests(*this);

    //
    // Run each test...
    //
    for (TestList::const_iterator i = m_unitTests.begin(); i != m_unitTests.end(); ++i)
    {
        ITestFunctionPtr unitTestFunction = *i;
        runTest(m_unitTest, *unitTestFunction);
    }

    //
    // Log the results of the unit test...
    //
    m_logStreamWriter.getInformationalStream() << m_unitTestRunningResults;
}

/**
 * Runs a test.
 */
void UnitTestHandler::runTest(IUnitTest& unitTest, ITestFunction& unitTestFunction)
{
    try
    {
        unitTest.preRun();
        unitTestFunction();
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

        m_logStreamWriter.getErrorStream() << std::endl << errorMessage << std::endl;

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
void UnitTestHandler::setSuccessfulRunningResult(IUnitTest& unitTest)
{
    m_unitTestRunningResults.setSuccessfulRunningResult(unitTest);
    m_logStreamWriter.getInformationalStream() << "Unit Test: " << unitTest.getName() << " Passed." << std::endl;
}

/**
 * Sets a failed running result of a unit test
 */
void UnitTestHandler::setFailedRunningResult(IUnitTest& unitTest, const std::string& errorMessage)
{
    m_unitTestRunningResults.setFailedRunningResult(unitTest, errorMessage);
    m_logStreamWriter.getInformationalStream() << "Unit Test: " << unitTest.getName() << " Failed." << std::endl;
}

