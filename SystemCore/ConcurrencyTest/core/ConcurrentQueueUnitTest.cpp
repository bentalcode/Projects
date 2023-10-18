#include "ConcurrentQueueUnitTest.h"
#include "UnitTestFunction.h"

using namespace test::concurrency;

class ConcurrentQueueTestFunction : public unit_testing::UnitTestFunction<ConcurrentQueueUnitTest> {
public:
    ConcurrentQueueTestFunction(ConcurrentQueueUnitTest &unitTest) :
        UnitTestFunction(L"ConcurrentQueueTest", unitTest)
    {
    }

    virtual ~ConcurrentQueueTestFunction()
    {
    }

    virtual void operator()() {
        GetUnitTest().ConcurrentQueueTest();
    }
};

/**
 * The ConcurrentQueueUnitTest constructor.
 */
ConcurrentQueueUnitTest::ConcurrentQueueUnitTest(const std::wstring& name) :
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
void ConcurrentQueueUnitTest::RegisterTests(unit_testing::ITestRegistration& registration)
{
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new ConcurrentQueueTestFunction(*this)));
}

/**
 * Tests the logic of a concurrent queue.
 */
void ConcurrentQueueUnitTest::ConcurrentQueueTest()
{
    std::shared_ptr<std::vector<int>> data = m_testData.CreateVector<>(10, 1);
    TestConcurrentQueue(*data);
}
