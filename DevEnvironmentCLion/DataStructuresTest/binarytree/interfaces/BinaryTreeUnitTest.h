#ifndef BINARY_TREE_UNIT_TEST_H_40f4a988_3353_4ccb_a0bd_68fbecc5070f
#define BINARY_TREE_UNIT_TEST_H_40f4a988_3353_4ccb_a0bd_68fbecc5070f

#include "UnitTestBase.h"
#include "IBinaryTree.h"
#include "TestData.h"
#include "BinaryTreeStreamBuilder.h"
#include "IBinaryTreeNodeIterator.h"
#include "BinaryTreeNodeListIterator.h"

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
                explicit BinaryTreeUnitTest(const std::string &name);

                /**
                 * The BinaryTreeUnitTest destructor.
                 */
                virtual ~BinaryTreeUnitTest();

                /**
                 * Registers tests of the unit test.
                 */
                virtual void registerTests(unit_testing::ITestRegistration &registration);

                /**
                 * Tests the creation logic of a binary tree.
                 */
                void binaryTreeCreationTest();

            private:
                /**
                 * Tests the creation logic of a binary tree.
                 */
                template<typename TKey, typename TValue>
                void testCreation(const BinaryTreeData<TKey, TValue>& treeData);

                TestData m_testData;
            };

            /**
             * Tests the creation logic of a binary tree.
             */
            template<typename TKey, typename TValue>
            void BinaryTreeUnitTest::testCreation(const BinaryTreeData<TKey, TValue>& treeData)
            {
                //
                // Create the tree...
                //
                IBinaryTreePtr<TKey, TValue> tree = BinaryTreeStreamBuilder<TKey, TValue>::build(treeData.getCreationData());

                //
                // Test the data of the tree...
                //
                base::IIteratorPtr<IBinaryTreeNodePtr<TKey, TValue>> levelOrderIterator =
                    BinaryTreeNodeListIterator<TKey, TValue>::of(treeData.getLevelOrder());

                getAssertion().assertEqualsWithDereferenceIterators(
                    *(tree->getLevelOrderIterator()),
                    *levelOrderIterator,
                    "Invalid creation logic of a binary tree.");
            }
        }
    }
}

#endif // BINARY_TREE_UNIT_TEST_H_40f4a988_3353_4ccb_a0bd_68fbecc5070f
