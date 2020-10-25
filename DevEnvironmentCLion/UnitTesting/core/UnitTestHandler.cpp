#include "PreCompiled.h"

#include "UnitTestHandler.h"
#include "TestRunningResults.h"
#include "UnitTestingException.h"
#include "UnitTestException.h"
#include "DateTime.h"

using namespace unit_testing;

/**
 * The UnitTestHandler constructor.
 */
UnitTestHandler::UnitTestHandler(
    IUnitTest& unitTest,
    base::IMessageWriter& messageWriter) :
    m_unitTest(unitTest),
    m_messageWriter(messageWriter)
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
        std::string errorMessage = "The test function of unit test is not defined.";
        throw UnitTestingException(errorMessage);
    }

    m_unitTests.push_back(testFunction);
}

/**
 * Runs the registered tests.
 */
const ITestRunningResults& UnitTestHandler::run()
{
    //
    // Registers the tests...
    //
    m_unitTest.registerTests(*this);

    //
    // process the tests...
    //
    m_unitTestRunningResults.getStartTime();

    for (ITestFunctionPtr unitTestFunction : m_unitTests)
    {
        processTest(*unitTestFunction);
    }

    m_unitTestRunningResults.setEndTime();

    return m_unitTestRunningResults;
}

/**
 * Processes a test.
 */
void UnitTestHandler::processTest(ITestFunction& unitTestFunction)
{
    base::DateTimePtr startTime = base::DateTime::now();

    std::string errorMessage;
    bool resultStatus = runTest(unitTestFunction, errorMessage);

    base::DateTimePtr endTime = base::DateTime::now();

    if (resultStatus)
    {
        m_unitTestRunningResults.setSuccessfulRunningResult(
            unitTestFunction.getName(),
            *startTime,
            *endTime);

        std::string message = "Unit Test: " + unitTestFunction.getName() + ", Passed.";
        m_messageWriter.writeInformationalMessage(message);
    }
    else
    {
        m_unitTestRunningResults.setFailedRunningResult(
            unitTestFunction.getName(),
            *startTime,
            *endTime,
            errorMessage);

        std::string message =
            "Unit Test: " + unitTestFunction.getName() + ", Failed. ErrorMessage: " + errorMessage;

        m_messageWriter.writeInformationalMessage(message);
    }
}

/**
 * Runs a test.
 */
bool UnitTestHandler::runTest(ITestFunction& unitTestFunction, std::string& errorMessage)
{
    bool resultStatus = false;

    try
    {
        m_unitTest.preRun();
        unitTestFunction();
        m_unitTest.postRun();
        resultStatus = true;
    }
    catch (UnitTestException& e)
    {
        std::stringstream errorMessageStream;
        errorMessageStream
            << "The unit test: " << unitTestFunction.getName() << " failed due to the following error: "
            << e.getErrorMessage();

        errorMessage = errorMessageStream.str();
    }
    catch (std::exception& e)
    {
        std::stringstream errorMessageStream;
        errorMessageStream
            << "The unit test: " << unitTestFunction.getName() << " failed due to an expected exception: "
            << e.what();

        errorMessage = errorMessageStream.str();
    }

    return resultStatus;
}
