#include "ListUnitTest.h"
#include "List.h"
#include "UnitTestFunction.h"
#include <assert.h>

using namespace base;
using namespace test::base;

class ListTestFunction : public unit_testing::UnitTestFunction<ListUnitTest> {
public:
    ListTestFunction(ListUnitTest &unitTest) :
        UnitTestFunction(L"ListTest", unitTest) {
    }

    virtual ~ListTestFunction() {
    }

    virtual void operator()() {
        GetUnitTest().ListTest();
    }
};

/**
 * The ListUnitTest constructor.
 */
ListUnitTest::ListUnitTest(const std::wstring& name) :
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
void ListUnitTest::RegisterTests(unit_testing::ITestRegistration& registration)
{
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new ListTestFunction(*this)));
}

/**
 * Tests the list.
 */
void ListUnitTest::ListTest()
{
    for (size_t size = 1; size <= 100; ++size)
    {
        TestList(size);
    }
}

/**
 * Tests the list.
 */
void ListUnitTest::TestList(size_t size)
{
    List<int> list;

    int value = 0;
    for (size_t i = 0; i < size; ++i)
    {
        ++value;
        list.AddBack(value);
    }

    int index = 0;

    IIteratorSharedPtr<int> iterator = list.GetIterator();
    while (iterator->HasNext())
    {
        int currentValue = iterator->Next();
        int expectedValue = list.Get(index);

        assert(currentValue == expectedValue);

        ++index;
    }
}
