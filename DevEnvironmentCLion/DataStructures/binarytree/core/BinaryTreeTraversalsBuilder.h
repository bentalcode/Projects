#ifndef BINARY_TREE_TRAVERSALS_BUILDER_H_d4c81e0c_2d7d_446c_a83f_01d97fccccb1
#define BINARY_TREE_TRAVERSALS_BUILDER_H_d4c81e0c_2d7d_446c_a83f_01d97fccccb1

#include "IBuilder.h"
#include "IBinaryTree.h"
#include "BinaryTreePreorderInorderTraversalBuilder.h"
#include "BinaryTreePreorderPostorderTraversalBuilder.h"

namespace datastructures {
    namespace binarytree {

        /**
         * The BinaryTreeTraversalsBuilder class implements a builder of a binary tree from various traversals.
         */
        template <typename TKey, typename TValue>
        class BinaryTreeTraversalsBuilder final
        {
        public:
            /**
             * Builds a binary tree from a preorder and an inorder traversal.
             */
            static IBinaryTreeSharedPtr<TKey, TValue> buildFromPreorderInorderTraversal(
                const std::vector<std::pair<TKey, TValue>>& preorder,
                const std::vector<std::pair<TKey, TValue>>& inorder);

            /**
             * Builds a binary tree from a preorder and a postorder traversal.
             */
            static IBinaryTreeSharedPtr<TKey, TValue> buildFromPreorderPostorderTraversal(
                const std::vector<std::pair<TKey, TValue>>& preorder,
                const std::vector<std::pair<TKey, TValue>>& postorder);

        private:
            /**
             * This is a static class - Disables the default constructor and destructor.
             */
            BinaryTreeTraversalsBuilder() = delete;
            ~BinaryTreeTraversalsBuilder() = delete;
        };

        /**
         * Builds a binary tree from a preorder and an inorder traversal.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeSharedPtr<TKey, TValue> BinaryTreeTraversalsBuilder<TKey, TValue>::buildFromPreorderInorderTraversal(
            const std::vector<std::pair<TKey, TValue>>& preorder,
            const std::vector<std::pair<TKey, TValue>>& inorder)
        {
            BinaryTreePreorderInorderTraversalBuilder<TKey, TValue> builder(preorder, inorder);
            IBinaryTreeSharedPtr<TKey, TValue> tree = builder.build();

            return tree;
        }

        /**
         * Builds a binary tree from a preorder and an inorder traversal.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeSharedPtr<TKey, TValue> BinaryTreeTraversalsBuilder<TKey, TValue>::buildFromPreorderPostorderTraversal(
            const std::vector<std::pair<TKey, TValue>>& preorder,
            const std::vector<std::pair<TKey, TValue>>& postorder)
        {
            BinaryTreePreorderPostorderTraversalBuilder<TKey, TValue> builder(preorder, postorder);
            IBinaryTreeSharedPtr<TKey, TValue> tree = builder.build();

            return tree;
        }
    }
}

#endif // BINARY_TREE_TRAVERSALS_BUILDER_H_d4c81e0c_2d7d_446c_a83f_01d97fccccb1
