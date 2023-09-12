#include "PreCompiled.h"

#include "ListUnitTest.h"
#include "List.h"
#include "UnitTestFunction.h"

using namespace base;
using namespace test::base;

class ListTestFunction : public unit_testing::UnitTestFunction<ListUnitTest> {
public:
    ListTestFunction(ListUnitTest &unitTest) :
        UnitTestFunction("listTest", unitTest) {
    }

    virtual ~ListTestFunction() {
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
    registration.registerTest(unit_testing::ITestFunctionPtr(new ListTestFunction(*this)));
}

/**
 * Tests the list.
 */
void ListUnitTest::listTest()
{
    for (size_t size = 1; size <= 100; ++size)
    {
        testList(size);
    }
}

/**
 * Tests the list.
 */
void ListUnitTest::testList(size_t size)
{
    List<int> list;

    int value = 0;
    for (size_t i = 0; i < size; ++i)
    {
        ++value;
        list.addBack(value);
    }

    int index = 0;

    IIteratorSharedPtr<int> iterator = list.getIterator();
    while (iterator->hasNext())
    {
        int currentValue = iterator->next();
        int expectedValue = list.get(index);

        assert(currentValue == expectedValue);

        ++index;
    }
}
