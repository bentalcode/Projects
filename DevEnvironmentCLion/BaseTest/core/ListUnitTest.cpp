#include "PreCompiled.h"

#include "ListUnitTest.h"
#include "List.h"
#include "UnitTestFunction.h"

using namespace base;

class TestListFunction : public unit_testing::UnitTestFunction<ListUnitTest> {
public:
    TestListFunction(ListUnitTest &unitTest) :
        UnitTestFunction("listTest", unitTest) {
    }

    virtual ~TestListFunction() {
    }

    virtual void operator()() {
        getUnitTest().listTest();
    }
};

/**
 * The ListUnitTest constructor.
 */
ListUnitTest::ListUnitTest(const std::string& name) :
    UnitTestBase(name)
{
}

/**
 * The ListUnitTest destructor.
 */
ListUnitTest::~ListUnitTest()
{
}

/**
 * Registers tests of the unit test.
 */
void ListUnitTest::registerTests(unit_testing::ITestRegistration& registration)
{
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestListFunction(*this)));
}

/**
 * Tests the list.
 */
void ListUnitTest::listTest()
{
    for (int size = 1; size <= 100; ++size)
    {
        testList(size);
    }
}

/**
 * Tests the list.
 */
void ListUnitTest::testList(int size)
{
    List<int> list(size);

    int value = 0;
    for (int i = 0; i < size; ++i)
    {
        ++value;
        list[i] = value;

        assert(list[i] == value);
    }

    int index = 0;

    IIteratorPtr<int> iterator = list.getIterator();
    while (iterator->hasNext())
    {
        int currentValue = iterator->next();
        int expectedValue = list.get(index);

        assert(currentValue == expectedValue);

        ++index;
    }
}
