#include "PreCompiled.h"

#include "IteratorOfIteratorCollectionUnitTest.h"
#include "UnitTestFunction.h"
#include "IteratorOfIteratorCollectionUnitTest.h"

using namespace data_structures_test;

class TestIteratorOfIteratorCollectionFunction : public unit_testing::UnitTestFunction<IteratorOfIteratorCollectionUnitTest> {
public:
    TestIteratorOfIteratorCollectionFunction(IteratorOfIteratorCollectionUnitTest &unitTest) :
        UnitTestFunction("iteratorOfIteratorCollectionTest", unitTest) {
    }

    virtual ~TestIteratorOfIteratorCollectionFunction() {
    }

    virtual void operator()() {
        getUnitTest().iteratorOfIteratorCollectionTest();
    }
};

/**
 * The IteratorOfIteratorCollectionUnitTest constructor.
 */
IteratorOfIteratorCollectionUnitTest::IteratorOfIteratorCollectionUnitTest(const std::string& name) :
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
void IteratorOfIteratorCollectionUnitTest::registerTests(unit_testing::ITestRegistration& registration)
{
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestIteratorOfIteratorCollectionFunction(*this)));
}

/**
 * Tests the iterator of a collection of iterators.
 */
void IteratorOfIteratorCollectionUnitTest::iteratorOfIteratorCollectionTest()
{
    testIteratorOfIteratorCollection();
}

/**
 * Tests the iterator of a collection of iterators.
 */
void IteratorOfIteratorCollectionUnitTest::testIteratorOfIteratorCollection()
{
}
