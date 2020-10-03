#include "PreCompiled.h"

#include "BinaryTreeTraversalBuilderUnitTest.h"
#include "UnitTestFunction.h"
#include "BinaryTreeTraversalBuilder.h"

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
}

/**
 * Tests the creation logic of a binary tree from a preorder and an inorder traversal.
 */
void BinaryTreeTraversalBuilderUnitTest::binaryTreePreorderInorderTraversalBuilderTest()
{
    std::vector<BinaryTreeDataPtr<int, std::string>> data = m_testData.getBinaryTreeData()->getData();

    for (BinaryTreeDataPtr<int, std::string> treeData : data)
    {
        testPreorderInorderTraversalBuilder(*treeData);
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
    IBinaryTreePtr<TKey, TValue> tree = BinaryTreeTraversalBuilder<TKey, TValue>::buildFromPreorderInorderTraversal(
        treeData.getPreorderData(),
        treeData.getInorderData());

    //
    // Test the data of the tree...
    //
    base::IIteratorPtr<IBinaryTreeNodePtr<TKey, TValue>> levelOrderIterator =
        BinaryTreeNodeListIterator<TKey, TValue>::make(treeData.getLevelOrder());

    getAssertion().assertEqualsWithDereferenceIterators(
        *(tree->getLevelOrderIterator()),
        *levelOrderIterator,
        "Invalid creation logic of a binary tree from a preorder and an inorder traversal.");
}
