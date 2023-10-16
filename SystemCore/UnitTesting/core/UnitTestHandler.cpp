#include "UnitTestHandler.h"
#include "UnitTestingException.h"
#include "UnitTestException.h"
#include "DateTime.h"
#include "UnitTestingConsts.h"
#include "SmartPointers.h"

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
void UnitTestHandler::RegisterTest(ITestFunctionSharedPtr testFunction)
{
    base::SmartPointers::Validate<ITestFunction>(testFunction);
    m_unitTests.push_back(testFunction);
}

/**
 * Runs the registered tests.
 */
const ITestRunningResults& UnitTestHandler::Run()
{
    //
    // Registers the tests...
    //
    m_unitTest.RegisterTests(*this);

    //
    // process the tests...
    //
    m_unitTestRunningResults.GetStartTime();

    for (ITestFunctionSharedPtr unitTestFunction : m_unitTests)
    {
        processTest(*unitTestFunction);
    }

    m_unitTestRunningResults.SetEndTime();

    return m_unitTestRunningResults;
}

/**
 * Processes a test.
 */
void UnitTestHandler::processTest(ITestFunction& unitTestFunction)
{
    base::DateTimeSharedPtr startTime = base::DateTime::Now();

    std::wstringstream testStartStream;
    testStartStream
        << UnitTestingConsts::TEST_START << std::endl
        << L"Running Unit Test: " << unitTestFunction.GetName() << std::endl;

    m_messageWriter.WriteInformationalMessage(testStartStream.str());

    std::wstring errorMessage;
    bool resultStatus = runTest(unitTestFunction, errorMessage);

    base::DateTimeSharedPtr endTime = base::DateTime::Now();

    std::wstringstream testResultStream;
    testResultStream << L"Unit Test: " << unitTestFunction.GetName();

    if (resultStatus)
    {
        m_unitTestRunningResults.SetSuccessfulRunningResult(
            unitTestFunction.GetName(),
            *startTime,
            *endTime);

        testResultStream << L", Passed.";

        m_messageWriter.WriteInformationalMessage(testResultStream.str());
    }
    else
    {
        m_unitTestRunningResults.SetFailedRunningResult(
            unitTestFunction.GetName(),
            *startTime,
            *endTime,
            errorMessage);

        testResultStream << L", Failed. ErrorMessage: " << errorMessage;

        m_messageWriter.WriteErrorMessage(testResultStream.str());
    }

    std::wstringstream testEndStream;
    testEndStream << UnitTestingConsts::TEST_END << std::endl;

    m_messageWriter.WriteInformationalMessage(testEndStream.str());
}

/**
 * Runs a test.
 */
bool UnitTestHandler::runTest(ITestFunction& unitTestFunction, std::wstring& errorMessage)
{
    bool resultStatus = false;

    try
    {
        m_unitTest.PreRun();
        unitTestFunction();
        m_unitTest.PostRun();
        resultStatus = true;
    }
    catch (UnitTestException& e)
    {
        std::wstringstream errorMessageStream;
        errorMessageStream
            << L"The unit test: " << unitTestFunction.GetName() << L" failed due to the following error: "
            << e.GetErrorMessage();

        errorMessage = errorMessageStream.str();
    }
    catch (std::exception& e)
    {
        std::wstringstream errorMessageStream;
        errorMessageStream
            << "The unit test: " << unitTestFunction.GetName() << " failed due to an expected exception: "
            << e.what();

        errorMessage = errorMessageStream.str();
    }

    return resultStatus;
}
