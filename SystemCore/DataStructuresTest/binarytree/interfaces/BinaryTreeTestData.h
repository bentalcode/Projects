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
                std::vector<BinaryTreeDataSharedPtr<int, std::wstring>> GetData() const;

                /**
                 * Gets the data of tree1.
                 */
                BinaryTreeDataSharedPtr<int, std::wstring> GetTreeData1() const;

                /**
                 * Gets the data of tree2.
                 */
                BinaryTreeDataSharedPtr<int, std::wstring> GetTreeData2() const;

                /**
                 * Gets the data of tree3.
                 */
                BinaryTreeDataSharedPtr<int, std::wstring> GetTreeData3() const;

                /**
                 * Gets the data of tree4.
                 */
                BinaryTreeDataSharedPtr<int, std::wstring> GetTreeData4() const;
            };

            //
            // Defines the SharedPtr of Binary Tree Test Data...
            //
            using BinaryTreeTestDataSharedPtr = std::shared_ptr<BinaryTreeTestData>;
        }
    }
}

#endif // BINARY_TREE_TEST_DATA_H_58a005d8_b649_44c4_b381_536c112940fc
