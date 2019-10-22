#include "PreCompiled.h"

#include "UnitTestHandler.h"
#include "UnitTestRunningResults.h"
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
const IUnitTestRunningResults& UnitTestHandler::run()
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
        runTest(*unitTestFunction);
    }

    return m_unitTestRunningResults;
}

/**
 * Runs a test.
 */
void UnitTestHandler::runTest(ITestFunction& unitTestFunction)
{
    try
    {
        m_unitTest.preRun();
        unitTestFunction();
        m_unitTest.postRun();

        setSuccessfulRunningResult(unitTestFunction);
    }
    catch (UnitTestException& e)
    {
        std::stringstream errorMessageStream;
        errorMessageStream
            << "The unit test: " << unitTestFunction.getName() << " failed due to the following error: "
            << e.getErrorMessage();

        std::string errorMessage = errorMessageStream.str();

        m_logStreamWriter.getErrorStream() << std::endl << errorMessage << std::endl;

        setFailedRunningResult(
            unitTestFunction,
            errorMessage);
    }
    catch (std::exception& e)
    {
        std::stringstream errorMessageStream;
        errorMessageStream
            << "The unit test: " << unitTestFunction.getName() << " failed due to an expected exception: "
            << e.what();

        std::string errorMessage = errorMessageStream.str();

        setFailedRunningResult(
            unitTestFunction,
            errorMessage);
    }
}

/**
 * Sets a successful running result of a unit test
 */
void UnitTestHandler::setSuccessfulRunningResult(ITestFunction& unitTestFunction)
{
    m_unitTestRunningResults.setSuccessfulRunningResult(unitTestFunction.getName());
    m_logStreamWriter.getInformationalStream() << "Unit Test: " << unitTestFunction.getName() << ", Passed." << std::endl;
}

/**
 * Sets a failed running result of a unit test
 */
void UnitTestHandler::setFailedRunningResult(ITestFunction& unitTestFunction, const std::string& errorMessage)
{
    m_unitTestRunningResults.setFailedRunningResult(unitTestFunction.getName(), errorMessage);
    m_logStreamWriter.getInformationalStream() << "Unit Test: " << unitTestFunction.getName() << ", Failed." << std::endl;
}

