#ifndef BINARY_TREE_UNIT_TEST_H_40f4a988_3353_4ccb_a0bd_68fbecc5070f
#define BINARY_TREE_UNIT_TEST_H_40f4a988_3353_4ccb_a0bd_68fbecc5070f

#include "UnitTestBase.h"
#include "IBinaryTree.h"

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
                void testCreation(IBinaryTreePtr<TKey, TValue> treePtr);
            };

            /**
             * Tests the creation logic of a binary tree.
             */
            template<typename TKey, typename TValue>
            void BinaryTreeUnitTest::testCreation(IBinaryTreePtr <TKey, TValue> treePtr) {
            }
        }
    }
}

#endif // BINARY_TREE_UNIT_TEST_H_40f4a988_3353_4ccb_a0bd_68fbecc5070f
