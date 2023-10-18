#include "BinaryTreeUnitTest.h"
#include "UnitTestFunction.h"

using namespace test::datastructures::binarytree;

class TestBinaryTreeCreationFunction : public unit_testing::UnitTestFunction<BinaryTreeUnitTest>
{
public:
    TestBinaryTreeCreationFunction(BinaryTreeUnitTest& unitTest) :
        UnitTestFunction(L"BinaryTreeCreationTest", unitTest)
    {
    }

    virtual ~TestBinaryTreeCreationFunction()
    {
    }

    virtual void operator()()
    {
        GetUnitTest().BinaryTreeCreationTest();
    }
};

class TestBinaryTreeIterationFunction : public unit_testing::UnitTestFunction<BinaryTreeUnitTest>
{
public:
    TestBinaryTreeIterationFunction(BinaryTreeUnitTest& unitTest) :
            UnitTestFunction(L"BinaryTreeIterationTest", unitTest)
    {
    }

    virtual ~TestBinaryTreeIterationFunction()
    {
    }

    virtual void operator()()
    {
        GetUnitTest().BinaryTreeIterationTest();
    }
};

/**
 * The BinaryTreeUnitTest constructor.
 */
BinaryTreeUnitTest::BinaryTreeUnitTest(const std::wstring& name) :
    UnitTestBase(name)
{
}

/**
 * The BinaryTreeUnitTest destructor.
 */
BinaryTreeUnitTest::~BinaryTreeUnitTest()
{
}

/**
 * Registers tests of the unit test.
 */
void BinaryTreeUnitTest::RegisterTests(unit_testing::ITestRegistration& registration)
{
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new TestBinaryTreeCreationFunction(*this)));
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new TestBinaryTreeIterationFunction(*this)));
}

/**
 * Tests the creation logic of a binary tree.
 */
void BinaryTreeUnitTest::BinaryTreeCreationTest()
{
    std::vector<BinaryTreeDataSharedPtr<int, std::wstring>> data = m_testData.GetBinaryTreeData()->GetData();

    for (BinaryTreeDataSharedPtr<int, std::wstring> treeData : data)
    {
        TestCreation(*treeData);
    }
}

/**
 * Tests the iteration logic of a binary tree.
 */
void BinaryTreeUnitTest::BinaryTreeIterationTest()
{
    std::vector<BinaryTreeDataSharedPtr<int, std::wstring>> data = m_testData.GetBinaryTreeData()->GetData();

    for (BinaryTreeDataSharedPtr<int, std::wstring> treeData : data)
    {
        TestIteration(*treeData);
    }
}
