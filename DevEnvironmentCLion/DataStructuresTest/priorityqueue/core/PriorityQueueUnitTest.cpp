#include "PreCompiled.h"

#include "PriorityQueueUnitTest.h"
#include "UnitTestFunction.h"
#include "PriorityQueueData.h"

using namespace test::datastructures::priority_queue;

class TestPriorityQueueCreationFunction final : public unit_testing::UnitTestFunction<PriorityQueueUnitTest>
{
public:
    TestPriorityQueueCreationFunction(PriorityQueueUnitTest& unitTest) :
        UnitTestFunction("priorityQueueCreationTest", unitTest)
    {
    }

    virtual ~TestPriorityQueueCreationFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().priorityQueueCreationTest();
    }
};

class TestPeekAndPollFunction final : public unit_testing::UnitTestFunction<PriorityQueueUnitTest>
{
public:
    TestPeekAndPollFunction(PriorityQueueUnitTest& unitTest) :
        UnitTestFunction("peekAndPollTest", unitTest)
    {
    }

    virtual ~TestPeekAndPollFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().peekAndPollTest();
    }
};

/**
 * The PriorityQueueUnitTest constructor.
 */
PriorityQueueUnitTest::PriorityQueueUnitTest(const std::string& name) :
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
void PriorityQueueUnitTest::registerTests(unit_testing::ITestRegistration& registration)
{
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestPriorityQueueCreationFunction(*this)));
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestPeekAndPollFunction(*this)));
}

/**
 * Tests the creation logic of a priority queue.
 */
void PriorityQueueUnitTest::priorityQueueCreationTest()
{
    for (PriorityQueueDataSharedPtr<int> data : m_testData.getPriorityQueueData()->getData())
    {
        testCreation(*data);
    }
}

/**
 * Tests the peek and poll logic of a priority queue.
 */
void PriorityQueueUnitTest::peekAndPollTest()
{
    for (PriorityQueueDataSharedPtr<int> data : m_testData.getPriorityQueueData()->getData())
    {
        testPeekAndPoll(*data);
    }
}
