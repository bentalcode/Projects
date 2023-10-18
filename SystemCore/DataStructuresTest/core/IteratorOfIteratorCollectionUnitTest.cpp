#include "IteratorOfIteratorCollectionUnitTest.h"
#include "UnitTestFunction.h"

using namespace test::datastructures;

class TestIteratorOfIteratorCollectionFunction : public unit_testing::UnitTestFunction<IteratorOfIteratorCollectionUnitTest> {
public:
    TestIteratorOfIteratorCollectionFunction(IteratorOfIteratorCollectionUnitTest &unitTest) :
        UnitTestFunction(L"IteratorOfIteratorCollectionTest", unitTest) {
    }

    virtual ~TestIteratorOfIteratorCollectionFunction() {
    }

    virtual void operator()() {
        GetUnitTest().IteratorOfIteratorCollectionTest();
    }
};

/**
 * The IteratorOfIteratorCollectionUnitTest constructor.
 */
IteratorOfIteratorCollectionUnitTest::IteratorOfIteratorCollectionUnitTest(const std::wstring& name) :
    UnitTestBase(name)
{
}

/**
 * The IteratorOfIteratorCollectionUnitTest destructor.
 */
IteratorOfIteratorCollectionUnitTest::~IteratorOfIteratorCollectionUnitTest()
{
}

/**
 * Registers tests of the unit test.
 */
void IteratorOfIteratorCollectionUnitTest::RegisterTests(unit_testing::ITestRegistration& registration)
{
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new TestIteratorOfIteratorCollectionFunction(*this)));
}

/**
 * Tests the iterator of a collection of iterators.
 */
void IteratorOfIteratorCollectionUnitTest::IteratorOfIteratorCollectionTest()
{
    std::shared_ptr<std::vector<int>> oneDimensionalArray = m_testData.CreateVector<>(10, 1);
    std::shared_ptr<std::vector<std::vector<int>>> twoDimensionalArray = m_testData.CreateTwoDimensionalVector(
        10, 20, 11);

    TestIteratorOfIteratorCollection(
        *oneDimensionalArray,
        *twoDimensionalArray);
}
