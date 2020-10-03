#ifndef BINARY_TREE_TRAVERSAL_BUILDER_H_d4c81e0c_2d7d_446c_a83f_01d97fccccb1
#define BINARY_TREE_TRAVERSAL_BUILDER_H_d4c81e0c_2d7d_446c_a83f_01d97fccccb1

#include "IBuilder.h"
#include "IBinaryTree.h"
#include "BinaryTreePreorderInorderTraversalBuilder.h"

namespace datastructures {
    namespace binarytree {

        /**
         * The BinaryTreeTraversalBuilder class implements a builder of a binary tree from various traversals.
         */
        template <typename TKey, typename TValue>
        class BinaryTreeTraversalBuilder final
        {
        public:
            /**
             * Builds a binary tree from a preorder and an inorder traversal.
             */
            static IBinaryTreePtr<TKey, TValue> buildFromPreorderInorderTraversal(
                const std::vector<std::pair<TKey, TValue>>& preorder,
                const std::vector<std::pair<TKey, TValue>>& inorder);

        private:
            /**
             * This is a static class - Disables the default constructor and destructor.
             */
            BinaryTreeTraversalBuilder() = delete;
            ~BinaryTreeTraversalBuilder() = delete;
        };

        /**
         * Builds a binary tree from a preorder and an inorder traversal.
         */
        template <typename TKey, typename TValue>
        IBinaryTreePtr<TKey, TValue> BinaryTreeTraversalBuilder<TKey, TValue>::buildFromPreorderInorderTraversal(
            const std::vector<std::pair<TKey, TValue>>& preorder,
            const std::vector<std::pair<TKey, TValue>>& inorder)
        {
            BinaryTreePreorderInorderTraversalBuilder<TKey, TValue> builder(preorder, inorder);
            IBinaryTreePtr<TKey, TValue> tree = builder.build();

            return tree;
        }
    }
}

#endif // BINARY_TREE_TRAVERSAL_BUILDER_H_d4c81e0c_2d7d_446c_a83f_01d97fccccb1
