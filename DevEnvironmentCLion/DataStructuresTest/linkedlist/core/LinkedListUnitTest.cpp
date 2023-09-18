#include "PreCompiled.h"

#include "LinkedListUnitTest.h"
#include "UnitTestFunction.h"

using namespace test::datastructures;
using namespace test::datastructures::linkedlist;
using namespace test::datastructures::binarytree;

class TestLinkedListCreationFunction : public unit_testing::UnitTestFunction<LinkedListUnitTest>
{
public:
    TestLinkedListCreationFunction(LinkedListUnitTest& unitTest) :
        UnitTestFunction("linkedListCreationTest", unitTest)
    {
    }

    virtual ~TestLinkedListCreationFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().linkedListCreationTest();
    }
};

class TestLinkedListIterationFunction : public unit_testing::UnitTestFunction<LinkedListUnitTest>
{
public:
    TestLinkedListIterationFunction(LinkedListUnitTest& unitTest) :
        UnitTestFunction("linkedListIterationTest", unitTest)
    {
    }

    virtual ~TestLinkedListIterationFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().linkedListIterationTest();
    }
};

class TestLinkedListUpdationFunction : public unit_testing::UnitTestFunction<LinkedListUnitTest>
{
public:
    TestLinkedListUpdationFunction(LinkedListUnitTest& unitTest) :
        UnitTestFunction("linkedListUpdationTest", unitTest)
    {
    }

    virtual ~TestLinkedListUpdationFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().linkedListUpdationTest();
    }
};

/**
 * The LinkedListUnitTest constructor.
 */
LinkedListUnitTest::LinkedListUnitTest(const std::string& name) :
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
void LinkedListUnitTest::registerTests(unit_testing::ITestRegistration& registration)
{
    registration.registerTest(unit_testing::ITestFunctionSharedPtr(new TestLinkedListCreationFunction(*this)));
    registration.registerTest(unit_testing::ITestFunctionSharedPtr(new TestLinkedListIterationFunction(*this)));
    registration.registerTest(unit_testing::ITestFunctionSharedPtr(new TestLinkedListUpdationFunction(*this)));
}

/**
 * Tests the creation logic of a linked list.
 */
void LinkedListUnitTest::linkedListCreationTest()
{
    std::vector<LinkedListDataSharedPtr<int>> data = m_testData.getLinkedListData()->getData();

    for (LinkedListDataSharedPtr<int> listData : data)
    {
        testCreation(*listData);
    }
}

/**
 * Tests the iteration logic of a linked list.
 */
void LinkedListUnitTest::linkedListIterationTest()
{
    std::vector<LinkedListDataSharedPtr<int>> data = m_testData.getLinkedListData()->getData();

    for (LinkedListDataSharedPtr<int> listData : data)
    {
        testIteration(*listData);
    }
}

/**
 * Tests the updation logic of a linked list.
 */
void LinkedListUnitTest::linkedListUpdationTest()
{
    LinkedList<int> list;

    std::vector<std::tuple<std::string, int, std::vector<int>>> data =
        m_testData.getLinkedListData()->getUpdationData();

    testUpdation(list, data);
}
