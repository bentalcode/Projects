#ifndef BINARY_TREE_TEST_DATA_H_58a005d8_b649_44c4_b381_536c112940fc
#define BINARY_TREE_TEST_DATA_H_58a005d8_b649_44c4_b381_536c112940fc

#include "BinaryTreeNode.h"
#include "BinaryTreeData.h"

using namespace datastructures::binarytree;

namespace test {
    namespace datastructures {
        namespace binarytree {

            /**
             * The BinaryTreeTestData class implements data of tests for a binary tree.
             */
            class BinaryTreeTestData final
            {
            public:
                /**
                 * The BinaryTreeTestData constructor.
                 */
                BinaryTreeTestData();

                /**
                 * The BinaryTreeTestData destructor.
                 */
                ~BinaryTreeTestData();

                /**
                 * The copy/move constructors.
                 */
                BinaryTreeTestData(const BinaryTreeTestData&) = delete;
                BinaryTreeTestData(BinaryTreeTestData&&) = delete;

                /**
                 * The copy/move assignment operators.
                 */
                BinaryTreeTestData& operator=(const BinaryTreeTestData&) = delete;
                BinaryTreeTestData& operator=(BinaryTreeTestData&&) = delete;

                /**
                 * Gets the data of the trees.
                 */
                std::vector<BinaryTreeDataPtr<int, std::string>> getData() const;

                /**
                 * Gets the data of tree1.
                 */
                BinaryTreeDataPtr<int, std::string> getTreeData1() const;

                /**
                 * Gets the data of tree2.
                 */
                BinaryTreeDataPtr<int, std::string> getTreeData2() const;

                /**
                 * Gets the data of tree3.
                 */
                BinaryTreeDataPtr<int, std::string> getTreeData3() const;

                /**
                 * Gets the data of tree4.
                 */
                BinaryTreeDataPtr<int, std::string> getTreeData4() const;
            };

            using BinaryTreeTestDataPtr = std::shared_ptr<BinaryTreeTestData>;
        }
    }
}

#endif // BINARY_TREE_TEST_DATA_H_58a005d8_b649_44c4_b381_536c112940fc
