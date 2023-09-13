#include "PreCompiled.h"

#include "BinaryTreeUnitTest.h"
#include "UnitTestFunction.h"

using namespace test::datastructures::binarytree;

class TestBinaryTreeCreationFunction : public unit_testing::UnitTestFunction<BinaryTreeUnitTest>
{
public:
    TestBinaryTreeCreationFunction(BinaryTreeUnitTest& unitTest) :
        UnitTestFunction("binaryTreeCreationTest", unitTest)
    {
    }

    virtual ~TestBinaryTreeCreationFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().binaryTreeCreationTest();
    }
};

class TestBinaryTreeIterationFunction : public unit_testing::UnitTestFunction<BinaryTreeUnitTest>
{
public:
    TestBinaryTreeIterationFunction(BinaryTreeUnitTest& unitTest) :
            UnitTestFunction("binaryTreeIterationTest", unitTest)
    {
    }

    virtual ~TestBinaryTreeIterationFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().binaryTreeIterationTest();
    }
};

/**
 * The BinaryTreeUnitTest constructor.
 */
BinaryTreeUnitTest::BinaryTreeUnitTest(const std::string& name) :
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
void BinaryTreeUnitTest::registerTests(unit_testing::ITestRegistration& registration)
{
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestBinaryTreeCreationFunction(*this)));
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestBinaryTreeIterationFunction(*this)));
}

/**
 * Tests the creation logic of a binary tree.
 */
void BinaryTreeUnitTest::binaryTreeCreationTest()
{
    std::vector<BinaryTreeDataSharedPtr<int, std::string>> data = m_testData.getBinaryTreeData()->getData();

    for (BinaryTreeDataSharedPtr<int, std::string> treeData : data)
    {
        testCreation(*treeData);
    }
}

/**
 * Tests the iteration logic of a binary tree.
 */
void BinaryTreeUnitTest::binaryTreeIterationTest()
{
    std::vector<BinaryTreeDataSharedPtr<int, std::string>> data = m_testData.getBinaryTreeData()->getData();

    for (BinaryTreeDataSharedPtr<int, std::string> treeData : data)
    {
        testIteration(*treeData);
    }
}
