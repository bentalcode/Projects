#include "PreCompiled.h"

#include "ConcurrentQueueUnitTest.h"
#include "UnitTestFunction.h"

using namespace concurrency_test;

class TestConcurrentQueueFunction : public unit_testing::UnitTestFunction<ConcurrentQueueUnitTest> {
public:
    TestConcurrentQueueFunction(ConcurrentQueueUnitTest &unitTest) :
        UnitTestFunction("iteratorOfIteratorCollectionTest", unitTest) {
    }

    virtual ~TestConcurrentQueueFunction() {
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
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestConcurrentQueueFunction(*this)));
}

/**
 * Tests the logic of a concurrent queue.
 */
void ConcurrentQueueUnitTest::concurrentQueueTest()
{
    std::shared_ptr<std::vector<int>> data = m_testData.createVector<>(10, 1);

    testConcurrentQueue(*data);
}
