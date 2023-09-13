#include "PreCompiled.h"

#include "BinaryTreeTraversalBuilderUnitTest.h"
#include "UnitTestFunction.h"
#include "BinaryTreeTraversalsBuilder.h"

using namespace test::datastructures::binarytree;

class TestBinaryTreePreorderInorderTraversalBuilderUnitTestFunction final : public unit_testing::UnitTestFunction<BinaryTreeTraversalBuilderUnitTest>
{
public:
    TestBinaryTreePreorderInorderTraversalBuilderUnitTestFunction(BinaryTreeTraversalBuilderUnitTest& unitTest) :
        UnitTestFunction("binaryTreePreorderInorderTraversalBuilderTest", unitTest)
    {
    }

    virtual ~TestBinaryTreePreorderInorderTraversalBuilderUnitTestFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().binaryTreePreorderInorderTraversalBuilderTest();
    }
};

class TestBinaryTreePreorderPostorderTraversalBuilderUnitTestFunction final : public unit_testing::UnitTestFunction<BinaryTreeTraversalBuilderUnitTest>
{
public:
    TestBinaryTreePreorderPostorderTraversalBuilderUnitTestFunction(BinaryTreeTraversalBuilderUnitTest& unitTest) :
            UnitTestFunction("binaryTreePreorderPostorderTraversalBuilderTest", unitTest)
    {
    }

    virtual ~TestBinaryTreePreorderPostorderTraversalBuilderUnitTestFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().binaryTreePreorderPostorderTraversalBuilderTest();
    }
};

/**
 * The BinaryTreeTraversalBuilderUnitTest constructor.
 */
BinaryTreeTraversalBuilderUnitTest::BinaryTreeTraversalBuilderUnitTest(const std::string& name) :
    UnitTestBase(name)
{
}

/**
 * The BinaryTreeTraversalBuilderUnitTest destructor.
 */
BinaryTreeTraversalBuilderUnitTest::~BinaryTreeTraversalBuilderUnitTest()
{
}

/**
 * Registers tests of the unit test.
 */
void BinaryTreeTraversalBuilderUnitTest::registerTests(unit_testing::ITestRegistration& registration)
{
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestBinaryTreePreorderInorderTraversalBuilderUnitTestFunction(*this)));
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestBinaryTreePreorderPostorderTraversalBuilderUnitTestFunction(*this)));
}

/**
 * Tests the creation logic of a binary tree from a preorder and an inorder traversal.
 */
void BinaryTreeTraversalBuilderUnitTest::binaryTreePreorderInorderTraversalBuilderTest()
{
    std::vector<BinaryTreeDataSharedPtr<int, std::string>> data = m_testData.getBinaryTreeData()->getData();

    for (BinaryTreeDataSharedPtr<int, std::string> treeData : data)
    {
        testPreorderInorderTraversalBuilder(*treeData);
    }
}

/**
 * Tests the creation logic of a binary tree from a preorder and an inorder traversal.
 */
void BinaryTreeTraversalBuilderUnitTest::binaryTreePreorderPostorderTraversalBuilderTest()
{
    std::vector<BinaryTreeDataSharedPtr<int, std::string>> data = m_testData.getBinaryTreeData()->getData();

    for (BinaryTreeDataSharedPtr<int, std::string> treeData : data)
    {
        testPreorderPostorderTraversalBuilder(*treeData);
    }
}

/**
 * Tests the creation logic of a binary tree from a preorder and an inorder traversal.
 */
template <typename TKey, typename TValue>
void BinaryTreeTraversalBuilderUnitTest::testPreorderInorderTraversalBuilder(const BinaryTreeData<TKey, TValue>& treeData)
{
    //
    // Create the tree...
    //
    IBinaryTreeSharedPtr<TKey, TValue> tree = BinaryTreeTraversalsBuilder<TKey, TValue>::buildFromPreorderInorderTraversal(
        treeData.getPreorderData(),
        treeData.getInorderData());

    //
    // Test the data of the tree...
    //
    base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> levelOrderIterator =
        BinaryTreeNodeListIterator<TKey, TValue>::make(treeData.getLevelOrder());

    getAssertion().assertEqualsWithDereferenceIterators(
        *(tree->getLevelOrderIterator()),
        *levelOrderIterator,
        "Invalid creation logic of a binary tree from a preorder and an inorder traversal.");
}

/**
 * Tests the creation logic of a binary tree from a preorder and a postorder traversal.
 */
template <typename TKey, typename TValue>
void BinaryTreeTraversalBuilderUnitTest::testPreorderPostorderTraversalBuilder(const BinaryTreeData<TKey, TValue>& treeData)
{
    //
    // Create the tree...
    //
    IBinaryTreeSharedPtr<TKey, TValue> tree = BinaryTreeTraversalsBuilder<TKey, TValue>::buildFromPreorderPostorderTraversal(
        treeData.getPreorderData(),
        treeData.getPostorderData());

    //
    // Test the data of the tree...
    //
    base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> levelOrderIterator =
        BinaryTreeNodeListIterator<TKey, TValue>::make(treeData.getLevelOrder());

    getAssertion().assertEqualsWithDereferenceIterators(
        *(tree->getLevelOrderIterator()),
        *levelOrderIterator,
        "Invalid creation logic of a binary tree from a preorder and a postorder traversal.");
}
