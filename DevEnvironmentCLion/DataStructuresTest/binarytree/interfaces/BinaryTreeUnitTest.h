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
                explicit BinaryTreeUnitTest(const std::string& name);

                /**
                 * The BinaryTreeUnitTest destructor.
                 */
                virtual ~BinaryTreeUnitTest();

                /**
                 * Registers tests of the unit test.
                 */
                virtual void registerTests(unit_testing::ITestRegistration& registration);

                /**
                 * Tests the creation logic of a binary tree.
                 */
                void binaryTreeCreationTest();

                /**
                 * Tests the iteration logic of a binary tree.
                 */
                void binaryTreeIterationTest();

            private:
                /**
                 * Tests the creation logic of a binary tree.
                 */
                template <typename TKey, typename TValue>
                void testCreation(const BinaryTreeData<TKey, TValue>& treeData);

                /**
                 * Tests the iteration logic of a binary tree.
                 */
                template <typename TKey, typename TValue>
                void testIteration(const BinaryTreeData<TKey, TValue>& treeData);

                /**
                 * Tests the logic of default iteration of a binary tree.
                 */
                template <typename TKey, typename TValue>
                void testDefaultIteration(
                    const IBinaryTree<TKey, TValue>& tree,
                    base::IIterator<IBinaryTreeNodePtr<TKey, TValue>>& dataIterator);

                /**
                 * Tests the logic of iteration of a binary tree.
                 */
                template <typename TKey, typename TValue>
                void testIteration(
                    base::IIterator<IBinaryTreeNodePtr<TKey, TValue>>& treeIterator,
                    base::IIterator<IBinaryTreeNodePtr<TKey, TValue>>& dataIterator,
                    const std::string& iteratorName);

                TestData m_testData;
            };

            /**
             * Tests the creation logic of a binary tree.
             */
            template <typename TKey, typename TValue>
            void BinaryTreeUnitTest::testCreation(const BinaryTreeData<TKey, TValue>& treeData)
            {
                //
                // Create the tree...
                //
                IBinaryTreePtr<TKey, TValue> tree = BinaryTreeStreamBuilder<TKey, TValue>::build(treeData.getCreationData());

                //
                // Test the data of the tree...
                //
                base::IIteratorSharedPtr<IBinaryTreeNodePtr<TKey, TValue>> levelOrderIterator =
                    BinaryTreeNodeListIterator<TKey, TValue>::make(treeData.getLevelOrder());

                getAssertion().assertEqualsWithDereferenceIterators(
                    *(tree->getLevelOrderIterator()),
                    *levelOrderIterator,
                    "Invalid creation logic of a binary tree.");
            }

            /**
             * Tests the iteration logic of a binary tree.
             */
            template <typename TKey, typename TValue>
            void BinaryTreeUnitTest::testIteration(const BinaryTreeData<TKey, TValue>& treeData)
            {
                //
                // Create the tree...
                //
                IBinaryTreePtr<TKey, TValue> tree = BinaryTreeStreamBuilder<TKey, TValue>::build(treeData.getCreationData());

                //
                // Test the logic of a default iteration...
                //
                base::IIteratorSharedPtr<IBinaryTreeNodePtr<TKey, TValue>> dataIterator = BinaryTreeNodeListIterator<TKey, TValue>::make(treeData.getInorder());
                testDefaultIteration(*tree, *dataIterator);

                //
                // Test the logic of a reverse iteration...
                //
                base::IReverseIteratorSharedPtr<IBinaryTreeNodePtr<TKey, TValue>> reverseIterator = tree->getReverseIterator();
                base::IIteratorSharedPtr<IBinaryTreeNodePtr<TKey, TValue>> reverseDataIterator = BinaryTreeNodeListReverseIterator<TKey, TValue>::make(treeData.getInorder());
                testIteration(*reverseIterator, *reverseDataIterator, "Reverse Iterator");

                //
                // Test the logic of a level order iteration...
                //
                base::IIteratorSharedPtr<IBinaryTreeNodePtr<TKey, TValue>> levelOrderIterator = tree->getLevelOrderIterator();
                base::IIteratorSharedPtr<IBinaryTreeNodePtr<TKey, TValue>> levelOrderDataIterator = BinaryTreeNodeListIterator<TKey, TValue>::make(treeData.getLevelOrder());
                testIteration(*levelOrderIterator, *levelOrderDataIterator, "Level Order Iterator");

                //
                // Test the logic of an inorder iteration...
                //
                base::IIteratorSharedPtr<IBinaryTreeNodePtr<TKey, TValue>> inorderIterator = tree->getInorderIterator();
                base::IIteratorSharedPtr<IBinaryTreeNodePtr<TKey, TValue>> inorderDataIterator = BinaryTreeNodeListIterator<TKey, TValue>::make(treeData.getInorder());
                testIteration(*inorderIterator, *inorderDataIterator, "Inorder Iterator");

                //
                // Test the logic of a preorder iteration...
                //
                base::IIteratorSharedPtr<IBinaryTreeNodePtr<TKey, TValue>> preorderIterator = tree->getPreorderIterator();
                base::IIteratorSharedPtr<IBinaryTreeNodePtr<TKey, TValue>> preorderDataIterator = BinaryTreeNodeListIterator<TKey, TValue>::make(treeData.getPreorder());
                testIteration(*preorderIterator, *preorderDataIterator, "Preorder Iterator");

                //
                // Test the logic of a postorder iteration...
                //
                base::IIteratorSharedPtr<IBinaryTreeNodePtr<TKey, TValue>> postorderIterator = tree->getPostorderIterator();
                base::IIteratorSharedPtr<IBinaryTreeNodePtr<TKey, TValue>> postorderDataIterator = BinaryTreeNodeListIterator<TKey, TValue>::make(treeData.getPostorder());
                testIteration(*postorderIterator, *postorderDataIterator, "Postorder Iterator");
            }

            /**
             * Tests the logic of default iteration of a binary tree.
             */
            template <typename TKey, typename TValue>
            void BinaryTreeUnitTest::testDefaultIteration(
                const IBinaryTree<TKey, TValue>& tree,
                base::IIterator<IBinaryTreeNodePtr<TKey, TValue>>& dataIterator)
            {
                base::IterableObject<IBinaryTreeNodePtr<TKey, TValue>> iterableObject(tree.getIterator());

                for (IBinaryTreeNodePtr<TKey, TValue> currNode : iterableObject)
                {
                    IBinaryTreeNodePtr<TKey, TValue> dataNode = dataIterator.next();

                    getAssertion().assertEqualsWithDereference(
                        currNode,
                        dataNode,
                        "Incorrect logic of default iteration.");
                }
            }

            /**
             * Tests the logic of iteration of a binary tree.
             */
            template <typename TKey, typename TValue>
            void BinaryTreeUnitTest::testIteration(
                base::IIterator<IBinaryTreeNodePtr<TKey, TValue>>& treeIterator,
                base::IIterator<IBinaryTreeNodePtr<TKey, TValue>>& dataIterator,
                const std::string& iteratorName)
            {
                getAssertion().assertEqualsWithDereferenceIterators(
                    treeIterator,
                    dataIterator,
                    "Incorrect logic of iteration of: " + iteratorName);
            }
        }
    }
}

#endif // BINARY_TREE_UNIT_TEST_H_40f4a988_3353_4ccb_a0bd_68fbecc5070f
