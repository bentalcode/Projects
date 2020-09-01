#include "PreCompiled.h"

#include "DoublyLinkedListUnitTest.h"
#include "UnitTestFunction.h"

using namespace test::datastructures;
using namespace test::datastructures::doublylinkedlist;
using namespace test::datastructures::binarytree;

class TestDoublyLinkedListCreationFunction : public unit_testing::UnitTestFunction<DoublyLinkedListUnitTest>
{
public:
    TestDoublyLinkedListCreationFunction(DoublyLinkedListUnitTest& unitTest) :
        UnitTestFunction("doublyLinkedListCreationTest", unitTest)
    {
    }

    virtual ~TestDoublyLinkedListCreationFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().doublyLinkedListCreationTest();
    }
};

class TestDoublyLinkedListIterationFunction : public unit_testing::UnitTestFunction<DoublyLinkedListUnitTest>
{
public:
    TestDoublyLinkedListIterationFunction(DoublyLinkedListUnitTest& unitTest) :
        UnitTestFunction("doublyLinkedListIterationTest", unitTest)
    {
    }

    virtual ~TestDoublyLinkedListIterationFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().doublyLinkedListIterationTest();
    }
};

class TestDoublyLinkedListUpdationFunction : public unit_testing::UnitTestFunction<DoublyLinkedListUnitTest>
{
public:
    TestDoublyLinkedListUpdationFunction(DoublyLinkedListUnitTest& unitTest) :
        UnitTestFunction("doublyLinkedListUpdationTest", unitTest)
    {
    }

    virtual ~TestDoublyLinkedListUpdationFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().doublyLinkedListUpdationTest();
    }
};

/**
 * The DoublyLinkedListUnitTest constructor.
 */
DoublyLinkedListUnitTest::DoublyLinkedListUnitTest(const std::string& name) :
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
void DoublyLinkedListUnitTest::registerTests(unit_testing::ITestRegistration& registration)
{
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestDoublyLinkedListCreationFunction(*this)));
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestDoublyLinkedListIterationFunction(*this)));
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestDoublyLinkedListUpdationFunction(*this)));
}

/**
 * Tests the creation logic of a doubly linked list.
 */
void DoublyLinkedListUnitTest::doublyLinkedListCreationTest()
{
    std::vector<DoublyLinkedListDataPtr<int>> data = m_testData.getDoublyLinkedListData()->getData();

    for (DoublyLinkedListDataPtr<int> listData : data)
    {
        testCreation(*listData);
    }
}

/**
 * Tests the iteration logic of a doubly linked list.
 */
void DoublyLinkedListUnitTest::doublyLinkedListIterationTest()
{
    std::vector<DoublyLinkedListDataPtr<int>> data = m_testData.getDoublyLinkedListData()->getData();

    for (DoublyLinkedListDataPtr<int> listData : data)
    {
        testIteration(*listData);
    }
}

/**
 * Tests the updation logic of a doubly linked list.
 */
void DoublyLinkedListUnitTest::doublyLinkedListUpdationTest()
{
}
