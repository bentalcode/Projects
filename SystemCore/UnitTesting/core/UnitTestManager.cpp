#include "UnitTestManager.h"
#include "MessageWriter.h"
#include "UnitTestHandler.h"
#include "UnitTestingException.h"
#include "SmartPointers.h"
#include <algorithm>

using namespace unit_testing;

class UnitTestPredicate final
{
public:
    UnitTestPredicate(const std::wstring& name) :
        m_name(name)
    {
    }

    bool operator()(IUnitTestSharedPtr unitTest)
    {
        return m_name == unitTest->GetName();
    }

private:
    std::wstring m_name;
};

/**
 * The UnitTestManager default constructor.
 */
UnitTestManager::UnitTestManager() :
    UnitTestManager(base::MessageWriter::Make())
{
}

/**
 * The UnitTestManager constructor.
 */
UnitTestManager::UnitTestManager(base::IMessageWriterSharedPtr messageWriter)
{
    base::SmartPointers::Validate<base::IMessageWriter>(messageWriter);
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
void UnitTestManager::RegisterTest(IUnitTestSharedPtr unitTest)
{
    base::SmartPointers::Validate<IUnitTest>(unitTest);

    unitTest->SetMessageWriter(m_messageWriter);
    m_unitTests.push_back(unitTest);
}

/**
 * Unregisters a test.
 */
void UnitTestManager::UnregisterTest(IUnitTestSharedPtr unitTest)
{
    base::SmartPointers::Validate<IUnitTest>(unitTest);

    UnitTestPredicate unitTestPredicate(unitTest->GetName());
    m_unitTests.erase(
        std::remove_if(m_unitTests.begin(), m_unitTests.end(), unitTestPredicate),
        m_unitTests.end());
}

/**
 * Runs the registered tests.
 */
void UnitTestManager::Run()
{
    m_unitTestRunningResults.SetStartTime();

    for (IUnitTestSharedPtr unitTest : m_unitTests)
    {
        runUnitTest(*unitTest);
    }

    m_unitTestRunningResults.SetEndTime();

    m_unitTestRunningResults.Write(*m_messageWriter);
}

/**
 * Runs a unit test.
 */
void UnitTestManager::runUnitTest(IUnitTest& unitTest)
{
    unit_testing::UnitTestHandler unitTestHandler(unitTest, *m_messageWriter);

    const ITestRunningResults& runningResults = unitTestHandler.Run();

    m_unitTestRunningResults.Add(runningResults);
}
