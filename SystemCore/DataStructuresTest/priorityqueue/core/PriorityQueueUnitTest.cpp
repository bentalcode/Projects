#include "PriorityQueueUnitTest.h"
#include "UnitTestFunction.h"
#include "PriorityQueueData.h"

using namespace test::datastructures::priority_queue;

class TestPriorityQueueCreationFunction final : public unit_testing::UnitTestFunction<PriorityQueueUnitTest>
{
public:
    TestPriorityQueueCreationFunction(PriorityQueueUnitTest& unitTest) :
        UnitTestFunction(L"PriorityQueueCreationTest", unitTest)
    {
    }

    virtual ~TestPriorityQueueCreationFunction()
    {
    }

    virtual void operator()()
    {
        GetUnitTest().PriorityQueueCreationTest();
    }
};

class TestPeekAndPollFunction final : public unit_testing::UnitTestFunction<PriorityQueueUnitTest>
{
public:
    TestPeekAndPollFunction(PriorityQueueUnitTest& unitTest) :
        UnitTestFunction(L"PeekAndPollTest", unitTest)
    {
    }

    virtual ~TestPeekAndPollFunction()
    {
    }

    virtual void operator()()
    {
        GetUnitTest().PeekAndPollTest();
    }
};

/**
 * The PriorityQueueUnitTest constructor.
 */
PriorityQueueUnitTest::PriorityQueueUnitTest(const std::wstring& name) :
    UnitTestBase(name)
{
}

/**
 * The PriorityQueueUnitTest destructor.
 */
PriorityQueueUnitTest::~PriorityQueueUnitTest()
{
}

/**
 * Registers tests of the unit test.
 */
void PriorityQueueUnitTest::RegisterTests(unit_testing::ITestRegistration& registration)
{
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new TestPriorityQueueCreationFunction(*this)));
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new TestPeekAndPollFunction(*this)));
}

/**
 * Tests the creation logic of a priority queue.
 */
void PriorityQueueUnitTest::PriorityQueueCreationTest()
{
    for (PriorityQueueDataSharedPtr<int> data : m_testData.GetPriorityQueueData()->GetData())
    {
        TestCreation(*data);
    }
}

/**
 * Tests the peek and poll logic of a priority queue.
 */
void PriorityQueueUnitTest::PeekAndPollTest()
{
    for (PriorityQueueDataSharedPtr<int> data : m_testData.GetPriorityQueueData()->GetData())
    {
        TestPeekAndPoll(*data);
    }
}
