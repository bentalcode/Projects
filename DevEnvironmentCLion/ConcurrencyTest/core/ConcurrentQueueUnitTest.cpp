#include "PreCompiled.h"

#include "ConcurrentQueueUnitTest.h"
#include "UnitTestFunction.h"

using namespace test::concurrency;

class ConcurrentQueueTestFunction : public unit_testing::UnitTestFunction<ConcurrentQueueUnitTest> {
public:
    ConcurrentQueueTestFunction(ConcurrentQueueUnitTest &unitTest) :
        UnitTestFunction("concurrentQueueTest", unitTest)
    {
    }

    virtual ~ConcurrentQueueTestFunction()
    {
    }

    virtual void operator()() {
        getUnitTest().concurrentQueueTest();
    }
};

/**
 * The ConcurrentQueueUnitTest constructor.
 */
ConcurrentQueueUnitTest::ConcurrentQueueUnitTest(const std::string& name) :
    UnitTestBase(name)
{
}

/**
 * The ConcurrentQueueUnitTest destructor.
 */
ConcurrentQueueUnitTest::~ConcurrentQueueUnitTest()
{
}

/**
 * Registers tests of the unit test.
 */
void ConcurrentQueueUnitTest::registerTests(unit_testing::ITestRegistration& registration)
{
    registration.registerTest(unit_testing::ITestFunctionSharedPtr(new ConcurrentQueueTestFunction(*this)));
}

/**
 * Tests the logic of a concurrent queue.
 */
void ConcurrentQueueUnitTest::concurrentQueueTest()
{
    std::shared_ptr<std::vector<int>> data = m_testData.createVector<>(10, 1);
    testConcurrentQueue(*data);
}
