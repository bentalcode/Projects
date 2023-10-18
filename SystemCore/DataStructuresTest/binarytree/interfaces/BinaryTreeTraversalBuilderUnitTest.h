#ifndef BINARY_TREE_TRAVERSAL_BUILDER_UNIT_TEST_H_74399498_30ee_4a1d_a983_bd5e9cb8821c
#define BINARY_TREE_TRAVERSAL_BUILDER_UNIT_TEST_H_74399498_30ee_4a1d_a983_bd5e9cb8821c

#include "UnitTestBase.h"
#include "IBinaryTree.h"
#include "TestData.h"
#include "BinaryTreeStreamBuilder.h"
#include "IBinaryTreeNodeIterator.h"
#include "BinaryTreeNodeListIterator.h"
#include "BinaryTreeNodeListReverseIterator.h"
#include "IterableObject.h"

using namespace datastructures::binarytree;

namespace test {
    namespace datastructures {
        namespace binarytree {

            /**
             * The BinaryTreeTraversalBuilderUnitTest class implements a unit test of building a binary tree
             * from various traversals.
             */
            class BinaryTreeTraversalBuilderUnitTest final : public unit_testing::UnitTestBase {
            public:
                /**
                 * The BinaryTreeTraversalBuilderUnitTest constructor.
                 */
                explicit BinaryTreeTraversalBuilderUnitTest(const std::wstring& name);

                /**
                 * The BinaryTreeTraversalBuilderUnitTest destructor.
                 */
                virtual ~BinaryTreeTraversalBuilderUnitTest();

                /**
                 * Registers tests of the unit test.
                 */
                virtual void RegisterTests(unit_testing::ITestRegistration& registration);

                /**
                 * Tests the creation logic of a binary tree from a preorder and an inorder traversal.
                 */
                void BinaryTreePreorderInorderTraversalBuilderTest();

                /**
                 * Tests the creation logic of a binary tree from a preorder and a postorder traversal.
                 */
                void BinaryTreePreorderPostorderTraversalBuilderTest();

            private:
                /**
                 * Tests the creation logic of a binary tree from a preorder and an inorder traversal.
                 */
                template <typename TKey, typename TValue>
                void TestPreorderInorderTraversalBuilder(const BinaryTreeData<TKey, TValue>& treeData);

                /**
                 * Tests the creation logic of a binary tree from a preorder and a postorder traversal.
                 */
                template <typename TKey, typename TValue>
                void TestPreorderPostorderTraversalBuilder(const BinaryTreeData<TKey, TValue>& treeData);

                TestData m_testData;
            };

        }
    }
}

#endif // BINARY_TREE_TRAVERSAL_BUILDER_UNIT_TEST_H_74399498_30ee_4a1d_a983_bd5e9cb8821c
