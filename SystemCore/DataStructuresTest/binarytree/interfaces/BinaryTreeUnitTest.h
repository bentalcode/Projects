#ifndef BINARY_TREE_UNIT_TEST_H_40f4a988_3353_4ccb_a0bd_68fbecc5070f
#define BINARY_TREE_UNIT_TEST_H_40f4a988_3353_4ccb_a0bd_68fbecc5070f

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
             * The BinaryTreeUnitTest class implements a unit test of a binary tree.
             */
            class BinaryTreeUnitTest final : public unit_testing::UnitTestBase {
            public:
                /**
                 * The BinaryTreeUnitTest constructor.
                 */
                explicit BinaryTreeUnitTest(const std::wstring& name);

                /**
                 * The BinaryTreeUnitTest destructor.
                 */
                virtual ~BinaryTreeUnitTest();

                /**
                 * Registers tests of the unit test.
                 */
                virtual void RegisterTests(unit_testing::ITestRegistration& registration);

                /**
                 * Tests the creation logic of a binary tree.
                 */
                void BinaryTreeCreationTest();

                /**
                 * Tests the iteration logic of a binary tree.
                 */
                void BinaryTreeIterationTest();

            private:
                /**
                 * Tests the creation logic of a binary tree.
                 */
                template <typename TKey, typename TValue>
                void TestCreation(const BinaryTreeData<TKey, TValue>& treeData);

                /**
                 * Tests the iteration logic of a binary tree.
                 */
                template <typename TKey, typename TValue>
                void TestIteration(const BinaryTreeData<TKey, TValue>& treeData);

                /**
                 * Tests the logic of default iteration of a binary tree.
                 */
                template <typename TKey, typename TValue>
                void TestDefaultIteration(
                    const IBinaryTree<TKey, TValue>& tree,
                    base::IIterator<IBinaryTreeNodeSharedPtr<TKey, TValue>>& dataIterator);

                /**
                 * Tests the logic of iteration of a binary tree.
                 */
                template <typename TKey, typename TValue>
                void TestIteration(
                    base::IIterator<IBinaryTreeNodeSharedPtr<TKey, TValue>>& treeIterator,
                    base::IIterator<IBinaryTreeNodeSharedPtr<TKey, TValue>>& dataIterator,
                    const std::wstring& iteratorName);

                TestData m_testData;
            };

            /**
             * Tests the creation logic of a binary tree.
             */
            template <typename TKey, typename TValue>
            void BinaryTreeUnitTest::TestCreation(const BinaryTreeData<TKey, TValue>& treeData)
            {
                //
                // Create the tree...
                //
                IBinaryTreeSharedPtr<TKey, TValue> tree = BinaryTreeStreamBuilder<TKey, TValue>::Build(
                    treeData.GetCreationData());

                //
                // Test the data of the tree...
                //
                base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> levelOrderIterator =
                    BinaryTreeNodeListIterator<TKey, TValue>::Make(treeData.GetLevelOrder());

                GetAssertion().AssertEqualsWithDereferenceIterators(
                    *(tree->GetLevelOrderIterator()),
                    *levelOrderIterator,
                    L"Invalid creation logic of a binary tree.");
            }

            /**
             * Tests the iteration logic of a binary tree.
             */
            template <typename TKey, typename TValue>
            void BinaryTreeUnitTest::TestIteration(const BinaryTreeData<TKey, TValue>& treeData)
            {
                //
                // Create the tree...
                //
                IBinaryTreeSharedPtr<TKey, TValue> tree = BinaryTreeStreamBuilder<TKey, TValue>::Build(
                    treeData.GetCreationData());

                //
                // Test the logic of a default iteration...
                //
                base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> dataIterator = BinaryTreeNodeListIterator<TKey, TValue>::Make(
                        treeData.GetInorder());
                TestDefaultIteration(*tree, *dataIterator);

                //
                // Test the logic of a reverse iteration...
                //
                base::IReverseIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> reverseIterator = tree->GetReverseIterator();
                base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> reverseDataIterator = BinaryTreeNodeListReverseIterator<TKey, TValue>::Make(
                    treeData.GetInorder());

                TestIteration(*reverseIterator, *reverseDataIterator, L"Reverse Iterator");

                //
                // Test the logic of a level order iteration...
                //
                base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> levelOrderIterator = tree->GetLevelOrderIterator();
                base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> levelOrderDataIterator = BinaryTreeNodeListIterator<TKey, TValue>::Make(
                        treeData.GetLevelOrder());
                TestIteration(*levelOrderIterator, *levelOrderDataIterator, L"Level Order Iterator");

                //
                // Test the logic of an inorder iteration...
                //
                base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> inorderIterator = tree->GetInorderIterator();
                base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> inorderDataIterator = BinaryTreeNodeListIterator<TKey, TValue>::Make(
                        treeData.GetInorder());
                TestIteration(*inorderIterator, *inorderDataIterator, L"Inorder Iterator");

                //
                // Test the logic of a preorder iteration...
                //
                base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> preorderIterator = tree->GetPreorderIterator();
                base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> preorderDataIterator = BinaryTreeNodeListIterator<TKey, TValue>::Make(
                        treeData.GetPreorder());
                TestIteration(*preorderIterator, *preorderDataIterator, L"Preorder Iterator");

                //
                // Test the logic of a postorder iteration...
                //
                base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> postorderIterator = tree->GetPostorderIterator();
                base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> postorderDataIterator = BinaryTreeNodeListIterator<TKey, TValue>::Make(
                        treeData.GetPostorder());
                TestIteration(*postorderIterator, *postorderDataIterator, L"Postorder Iterator");
            }

            /**
             * Tests the logic of default iteration of a binary tree.
             */
            template <typename TKey, typename TValue>
            void BinaryTreeUnitTest::TestDefaultIteration(
                const IBinaryTree<TKey, TValue>& tree,
                base::IIterator<IBinaryTreeNodeSharedPtr<TKey, TValue>>& dataIterator)
            {
                base::IterableObject<IBinaryTreeNodeSharedPtr<TKey, TValue>> iterableObject(tree.GetIterator());

                for (IBinaryTreeNodeSharedPtr<TKey, TValue> currNode : iterableObject)
                {
                    IBinaryTreeNodeSharedPtr<TKey, TValue> dataNode = dataIterator.Next();

                    GetAssertion().AssertEqualsWithDereference(
                        currNode,
                        dataNode,
                        L"Incorrect logic of default iteration.");
                }
            }

            /**
             * Tests the logic of iteration of a binary tree.
             */
            template <typename TKey, typename TValue>
            void BinaryTreeUnitTest::TestIteration(
                base::IIterator<IBinaryTreeNodeSharedPtr<TKey, TValue>>& treeIterator,
                base::IIterator<IBinaryTreeNodeSharedPtr<TKey, TValue>>& dataIterator,
                const std::wstring& iteratorName)
            {
                GetAssertion().AssertEqualsWithDereferenceIterators(
                    treeIterator,
                    dataIterator,
                    L"Incorrect logic of iteration of: " + iteratorName);
            }
        }
    }
}

#endif // BINARY_TREE_UNIT_TEST_H_40f4a988_3353_4ccb_a0bd_68fbecc5070f
