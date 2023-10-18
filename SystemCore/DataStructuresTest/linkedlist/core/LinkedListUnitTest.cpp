#include "LinkedListUnitTest.h"
#include "UnitTestFunction.h"

using namespace test::datastructures;
using namespace test::datastructures::linkedlist;
using namespace test::datastructures::binarytree;

class TestLinkedListCreationFunction : public unit_testing::UnitTestFunction<LinkedListUnitTest>
{
public:
    TestLinkedListCreationFunction(LinkedListUnitTest& unitTest) :
        UnitTestFunction(L"LinkedListCreationTest", unitTest)
    {
    }

    virtual ~TestLinkedListCreationFunction()
    {
    }

    virtual void operator()()
    {
        GetUnitTest().LinkedListCreationTest();
    }
};

class TestLinkedListIterationFunction : public unit_testing::UnitTestFunction<LinkedListUnitTest>
{
public:
    TestLinkedListIterationFunction(LinkedListUnitTest& unitTest) :
        UnitTestFunction(L"LinkedListIterationTest", unitTest)
    {
    }

    virtual ~TestLinkedListIterationFunction()
    {
    }

    virtual void operator()()
    {
        GetUnitTest().LinkedListIterationTest();
    }
};

class TestLinkedListUpdationFunction : public unit_testing::UnitTestFunction<LinkedListUnitTest>
{
public:
    TestLinkedListUpdationFunction(LinkedListUnitTest& unitTest) :
        UnitTestFunction(L"LinkedListUpdationTest", unitTest)
    {
    }

    virtual ~TestLinkedListUpdationFunction()
    {
    }

    virtual void operator()()
    {
        GetUnitTest().LinkedListUpdationTest();
    }
};

/**
 * The LinkedListUnitTest constructor.
 */
LinkedListUnitTest::LinkedListUnitTest(const std::wstring& name) :
    UnitTestBase(name)
{
}

/**
 * The LinkedListUnitTest destructor.
 */
LinkedListUnitTest::~LinkedListUnitTest()
{
}

/**
 * Registers tests of the unit test.
 */
void LinkedListUnitTest::RegisterTests(unit_testing::ITestRegistration& registration)
{
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new TestLinkedListCreationFunction(*this)));
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new TestLinkedListIterationFunction(*this)));
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new TestLinkedListUpdationFunction(*this)));
}

/**
 * Tests the creation logic of a linked list.
 */
void LinkedListUnitTest::LinkedListCreationTest()
{
    std::vector<LinkedListDataSharedPtr<int>> data = m_testData.GetLinkedListData()->GetData();

    for (LinkedListDataSharedPtr<int> listData : data)
    {
        TestCreation(*listData);
    }
}

/**
 * Tests the iteration logic of a linked list.
 */
void LinkedListUnitTest::LinkedListIterationTest()
{
    std::vector<LinkedListDataSharedPtr<int>> data = m_testData.GetLinkedListData()->GetData();

    for (LinkedListDataSharedPtr<int> listData : data)
    {
        TestIteration(*listData);
    }
}

/**
 * Tests the updation logic of a linked list.
 */
void LinkedListUnitTest::LinkedListUpdationTest()
{
    LinkedList<int> list;

    std::vector<std::tuple<std::wstring, int, std::vector<int>>> data =
            m_testData.GetLinkedListData()->GetUpdationData();

    TestUpdation(list, data);
}
