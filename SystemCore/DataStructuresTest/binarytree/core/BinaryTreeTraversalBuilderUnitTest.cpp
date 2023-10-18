#include "BinaryTreeTraversalBuilderUnitTest.h"
#include "UnitTestFunction.h"
#include "BinaryTreeTraversalsBuilder.h"

using namespace test::datastructures::binarytree;

class TestBinaryTreePreorderInorderTraversalBuilderUnitTestFunction final : public unit_testing::UnitTestFunction<BinaryTreeTraversalBuilderUnitTest>
{
public:
    TestBinaryTreePreorderInorderTraversalBuilderUnitTestFunction(BinaryTreeTraversalBuilderUnitTest& unitTest) :
        UnitTestFunction(L"BinaryTreePreorderInorderTraversalBuilderTest", unitTest)
    {
    }

    virtual ~TestBinaryTreePreorderInorderTraversalBuilderUnitTestFunction()
    {
    }

    virtual void operator()()
    {
        GetUnitTest().BinaryTreePreorderInorderTraversalBuilderTest();
    }
};

class TestBinaryTreePreorderPostorderTraversalBuilderUnitTestFunction final : public unit_testing::UnitTestFunction<BinaryTreeTraversalBuilderUnitTest>
{
public:
    TestBinaryTreePreorderPostorderTraversalBuilderUnitTestFunction(BinaryTreeTraversalBuilderUnitTest& unitTest) :
            UnitTestFunction(L"BinaryTreePreorderPostorderTraversalBuilderTest", unitTest)
    {
    }

    virtual ~TestBinaryTreePreorderPostorderTraversalBuilderUnitTestFunction()
    {
    }

    virtual void operator()()
    {
        GetUnitTest().BinaryTreePreorderPostorderTraversalBuilderTest();
    }
};

/**
 * The BinaryTreeTraversalBuilderUnitTest constructor.
 */
BinaryTreeTraversalBuilderUnitTest::BinaryTreeTraversalBuilderUnitTest(const std::wstring& name) :
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
void BinaryTreeTraversalBuilderUnitTest::RegisterTests(unit_testing::ITestRegistration& registration)
{
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new TestBinaryTreePreorderInorderTraversalBuilderUnitTestFunction(*this)));
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new TestBinaryTreePreorderPostorderTraversalBuilderUnitTestFunction(*this)));
}

/**
 * Tests the creation logic of a binary tree from a preorder and an inorder traversal.
 */
void BinaryTreeTraversalBuilderUnitTest::BinaryTreePreorderInorderTraversalBuilderTest()
{
    std::vector<BinaryTreeDataSharedPtr<int, std::wstring>> data = m_testData.GetBinaryTreeData()->GetData();

    for (BinaryTreeDataSharedPtr<int, std::wstring> treeData : data)
    {
        TestPreorderInorderTraversalBuilder(*treeData);
    }
}

/**
 * Tests the creation logic of a binary tree from a preorder and an inorder traversal.
 */
void BinaryTreeTraversalBuilderUnitTest::BinaryTreePreorderPostorderTraversalBuilderTest()
{
    std::vector<BinaryTreeDataSharedPtr<int, std::wstring>> data = m_testData.GetBinaryTreeData()->GetData();

    for (BinaryTreeDataSharedPtr<int, std::wstring> treeData : data)
    {
        TestPreorderPostorderTraversalBuilder(*treeData);
    }
}

/**
 * Tests the creation logic of a binary tree from a preorder and an inorder traversal.
 */
template <typename TKey, typename TValue>
void BinaryTreeTraversalBuilderUnitTest::TestPreorderInorderTraversalBuilder(const BinaryTreeData<TKey, TValue>& treeData)
{
    //
    // Create the tree...
    //
    IBinaryTreeSharedPtr<TKey, TValue> tree = BinaryTreeTraversalsBuilder<TKey, TValue>::BuildFromPreorderInorderTraversal(
            treeData.GetPreorderData(),
        treeData.GetInorderData());

    //
    // Test the data of the tree...
    //
    base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> levelOrderIterator =
        BinaryTreeNodeListIterator<TKey, TValue>::Make(treeData.GetLevelOrder());

    GetAssertion().AssertEqualsWithDereferenceIterators(
        *(tree->GetLevelOrderIterator()),
        *levelOrderIterator,
        L"Invalid creation logic of a binary tree from a preorder and an inorder traversal.");
}

/**
 * Tests the creation logic of a binary tree from a preorder and a postorder traversal.
 */
template <typename TKey, typename TValue>
void BinaryTreeTraversalBuilderUnitTest::TestPreorderPostorderTraversalBuilder(const BinaryTreeData<TKey, TValue>& treeData)
{
    //
    // Create the tree...
    //
    IBinaryTreeSharedPtr<TKey, TValue> tree = BinaryTreeTraversalsBuilder<TKey, TValue>::BuildFromPreorderPostorderTraversal(
            treeData.GetPreorderData(),
            treeData.GetPostorderData());

    //
    // Test the data of the tree...
    //
    base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> levelOrderIterator =
        BinaryTreeNodeListIterator<TKey, TValue>::Make(treeData.GetLevelOrder());

    GetAssertion().AssertEqualsWithDereferenceIterators(
        *(tree->GetLevelOrderIterator()),
        *levelOrderIterator,
        L"Invalid creation logic of a binary tree from a preorder and a postorder traversal.");
}
