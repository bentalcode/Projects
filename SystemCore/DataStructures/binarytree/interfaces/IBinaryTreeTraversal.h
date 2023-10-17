#ifndef I_BINARY_TREE_TRAVERSAL_H_c575ef6d_2c99_4f42_8026_32be91567d69
#define I_BINARY_TREE_TRAVERSAL_H_c575ef6d_2c99_4f42_8026_32be91567d69

#include "IBinaryTreeNode.h"
#include "IVisitor.h"

namespace datastructures {
    namespace binarytree {

        /**
         * The IBinaryTreeTraversal interface defines various traversal in a binary tree.
         */
        template <typename TKey, typename TValue>
        class IBinaryTreeTraversal {
        public:
            /**
             * The IBinaryTreeTraversal constructor.
             */
            IBinaryTreeTraversal() = default;

            /**
             * The IBinaryTreeTraversal destructor.
             */
            virtual ~IBinaryTreeTraversal() = default;

            /**
             * The Copy/move constructors.
             */
            IBinaryTreeTraversal(const IBinaryTreeTraversal&) = delete;
            IBinaryTreeTraversal(IBinaryTreeTraversal&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            IBinaryTreeTraversal& operator=(const IBinaryTreeTraversal&) = delete;
            IBinaryTreeTraversal& operator=(IBinaryTreeTraversal&&) = delete;

            /**
             * Performs a Breadth-First search.
             */
            virtual void BreadthFirstSearch(
                IBinaryTreeNodeSharedPtr<TKey, TValue> root,
                IVisitor<IBinaryTreeNodeSharedPtr<TKey, TValue>> visitor) = 0;

            /**
             * Performs a Depth-First search.
             */
            virtual void DepthFirstSearch(
                IBinaryTreeNodeSharedPtr<TKey, TValue> root,
                IVisitor<IBinaryTreeNodeSharedPtr<TKey, TValue>> visitor) = 0;

            /**
             * Performs a Pre-Order search.
             */
            virtual void PreOrder(
                IBinaryTreeNodeSharedPtr<TKey, TValue> root,
                IVisitor<IBinaryTreeNodeSharedPtr<TKey, TValue>> visitor) = 0;

            /**
             * Performs an In-Order search.
             */
            virtual void InOrder(
                IBinaryTreeNodeSharedPtr<TKey, TValue> root,
                IVisitor<IBinaryTreeNodeSharedPtr<TKey, TValue>> visitor) = 0;

            /**
             * Performs an Post-Order search.
             */
            virtual void PostOrder(
                IBinaryTreeNodeSharedPtr<TKey, TValue> root,
                IVisitor<IBinaryTreeNodeSharedPtr<TKey, TValue>> visitor) = 0;
        };
    }
}

#endif // I_BINARY_TREE_TRAVERSAL_H_c575ef6d_2c99_4f42_8026_32be91567d69
