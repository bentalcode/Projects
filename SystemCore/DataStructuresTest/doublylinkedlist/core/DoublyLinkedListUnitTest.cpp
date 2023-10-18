#include "DoublyLinkedListUnitTest.h"
#include "UnitTestFunction.h"

using namespace test::datastructures;
using namespace test::datastructures::doublylinkedlist;
using namespace test::datastructures::binarytree;

class TestDoublyLinkedListCreationFunction : public unit_testing::UnitTestFunction<DoublyLinkedListUnitTest>
{
public:
    TestDoublyLinkedListCreationFunction(DoublyLinkedListUnitTest& unitTest) :
        UnitTestFunction(L"DoublyLinkedListCreationTest", unitTest)
    {
    }

    virtual ~TestDoublyLinkedListCreationFunction()
    {
    }

    virtual void operator()()
    {
        GetUnitTest().DoublyLinkedListCreationTest();
    }
};

class TestDoublyLinkedListIterationFunction : public unit_testing::UnitTestFunction<DoublyLinkedListUnitTest>
{
public:
    TestDoublyLinkedListIterationFunction(DoublyLinkedListUnitTest& unitTest) :
        UnitTestFunction(L"DoublyLinkedListIterationTest", unitTest)
    {
    }

    virtual ~TestDoublyLinkedListIterationFunction()
    {
    }

    virtual void operator()()
    {
        GetUnitTest().DoublyLinkedListIterationTest();
    }
};

class TestDoublyLinkedListUpdationFunction : public unit_testing::UnitTestFunction<DoublyLinkedListUnitTest>
{
public:
    TestDoublyLinkedListUpdationFunction(DoublyLinkedListUnitTest& unitTest) :
        UnitTestFunction(L"DoublyLinkedListUpdationTest", unitTest)
    {
    }

    virtual ~TestDoublyLinkedListUpdationFunction()
    {
    }

    virtual void operator()()
    {
        GetUnitTest().DoublyLinkedListUpdationTest();
    }
};

/**
 * The DoublyLinkedListUnitTest constructor.
 */
DoublyLinkedListUnitTest::DoublyLinkedListUnitTest(const std::wstring& name) :
    UnitTestBase(name)
{
}

/**
 * The DoublyLinkedListUnitTest destructor.
 */
DoublyLinkedListUnitTest::~DoublyLinkedListUnitTest()
{
}

/**
 * Registers tests of the unit test.
 */
void DoublyLinkedListUnitTest::RegisterTests(unit_testing::ITestRegistration& registration)
{
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new TestDoublyLinkedListCreationFunction(*this)));
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new TestDoublyLinkedListIterationFunction(*this)));
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new TestDoublyLinkedListUpdationFunction(*this)));
}

/**
 * Tests the creation logic of a doubly linked list.
 */
void DoublyLinkedListUnitTest::DoublyLinkedListCreationTest()
{
    std::vector<DoublyLinkedListDataSharedPtr<int>> data = m_testData.GetDoublyLinkedListData()->GetData();

    for (DoublyLinkedListDataSharedPtr<int> listData : data)
    {
        TestCreation(*listData);
    }
}

/**
 * Tests the iteration logic of a doubly linked list.
 */
void DoublyLinkedListUnitTest::DoublyLinkedListIterationTest()
{
    std::vector<DoublyLinkedListDataSharedPtr<int>> data = m_testData.GetDoublyLinkedListData()->GetData();

    for (DoublyLinkedListDataSharedPtr<int> listData : data)
    {
        TestIteration(*listData);
    }
}

/**
 * Tests the updation logic of a doubly linked list.
 */
void DoublyLinkedListUnitTest::DoublyLinkedListUpdationTest()
{
    DoublyLinkedList<int> list;

    std::vector<std::tuple<std::wstring, int, std::vector<int>>> data =
            m_testData.GetDoublyLinkedListData()->GetUpdationData();

    TestUpdation(list, data);
}
