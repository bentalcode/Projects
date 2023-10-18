#ifndef I_BINARY_TREE_H_80c4d24f_227c_411c_96d3_19fb108187fc
#define I_BINARY_TREE_H_80c4d24f_227c_411c_96d3_19fb108187fc

#include "IIterable.h"
#include "IReverseIterable.h"
#include "BinaryTreeLevelOrderWithEndNodesIterator.h"
#include "EqualBuilder.h"
#include "CompareToBuilder.h"

namespace datastructures {
    namespace binarytree {

        /**
         * The IBinaryTree interface defines a binary tree.
         */
        template <typename TKey, typename TValue>
        class IBinaryTree : public
            base::IIterable<IBinaryTreeNodeSharedPtr<TKey, TValue>>,
            base::IReverseIterable<IBinaryTreeNodeSharedPtr<TKey, TValue>>
        {
        public:
            /**
             * The constructor.
             */
            IBinaryTree() = default;

            /**
             * The destructor.
             */
            virtual ~IBinaryTree() = default;

            /**
             * The Copy/move constructors.
             */
            IBinaryTree(const IBinaryTree&) = delete;
            IBinaryTree(IBinaryTree&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            IBinaryTree& operator=(const IBinaryTree&) = delete;
            IBinaryTree& operator=(IBinaryTree&&) = delete;

            /**
             * Gets a root of a tree.
             */
            virtual IBinaryTreeNodeSharedPtr<TKey, TValue> GetRoot() const = 0;

            /**
             * Sets a root of a tree.
             */
            virtual void SetRoot(IBinaryTreeNodeSharedPtr<TKey, TValue> root) = 0;

            /**
             * Gets an iterator of a tree.
             */
            virtual base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey , TValue>> GetIterator() const = 0;

            /**
             * Gets a reverse iterator of a tree.
             */
            virtual base::IReverseIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey , TValue>> GetReverseIterator() const = 0;

            /**
             * Gets a level order iterator of a tree.
             */
            virtual base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> GetLevelOrderIterator() const = 0;

            /**
             * Gets an inorder iterator of a tree.
             */
            virtual base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> GetInorderIterator() const = 0;

            /**
             * Gets a preorder iterator of a tree.
             */
            virtual base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> GetPreorderIterator() const = 0;

            /**
             * Gets a postorder iterator of a tree.
             */
            virtual base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> GetPostorderIterator() const = 0;
        };

        /**
         * Defines SharedPtr of binary tree.
         */
        template <typename TKey, typename TValue>
        using IBinaryTreeSharedPtr = std::shared_ptr<IBinaryTree<TKey, TValue>>;

        /**
         * Implements an operator equals for binary trees.
         */
        template <typename TKey, typename TValue>
        inline bool operator==(
            const IBinaryTree<TKey, TValue>& lhs,
            const IBinaryTree<TKey, TValue>& rhs)
        {
            base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> lhsIterator =
                BinaryTreeLevelOrderWithEndNodesIterator<TKey, TValue>::of(lhs.GetRoot());

            base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> rhsIterator =
                BinaryTreeLevelOrderWithEndNodesIterator<TKey, TValue>::of(rhs.GetRoot());

            base::EqualBuilder equalBuilder;
            int status = equalBuilder.WithDereferenceIterator(
                *lhsIterator,
                *rhsIterator).Build();

            return status < 0;
        }

        /**
         * Implements an operator not equals for binary trees.
         */
        template <typename TKey, typename TValue>
        inline bool operator!=(
            const IBinaryTree<TKey, TValue>& lhs,
            const IBinaryTree<TKey, TValue>& rhs)
        {
            return !(lhs == rhs);
        }

        /**
         * Implements an operator less than for binary trees.
         */
        template <typename TKey, typename TValue>
        bool operator<(
            const IBinaryTree<TKey, TValue>& lhs,
            const IBinaryTree<TKey, TValue>& rhs)
        {
            base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> lhsIterator =
                BinaryTreeLevelOrderWithEndNodesIterator<TKey, TValue>::of(lhs.GetRoot());

            base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> rhsIterator =
                BinaryTreeLevelOrderWithEndNodesIterator<TKey, TValue>::of(rhs.GetRoot());

            base::CompareToBuilder compareToBuilder;
            int status = compareToBuilder.WithDereferenceIterator(
                *lhsIterator,
                *rhsIterator).Build();

            return status < 0;
        }

        /**
         * Implements an operator less than or equal for binary trees.
         */
        template <typename TKey, typename TValue>
        bool operator<=(
            const IBinaryTree<TKey, TValue>& lhs,
            const IBinaryTree<TKey, TValue>& rhs)
        {
            return !(rhs < lhs);
        }

        /**
         * Implements an operator greater than for binary trees.
         */
        template <typename TKey, typename TValue>
        inline bool operator>(
            const IBinaryTree<TKey, TValue>& lhs,
            const IBinaryTree<TKey, TValue>& rhs)
        {
            return rhs < lhs;
        }

        /**
         * Implements an operator greater than or equal for binary trees.
         */
        template <typename TKey, typename TValue>
        bool operator>=(
            const IBinaryTree<TKey, TValue>& lhs,
            const IBinaryTree<TKey, TValue>& rhs)
        {
            return !(lhs < rhs);
        }
    }
}

#endif // I_BINARY_TREE_H_80c4d24f_227c_411c_96d3_19fb108187fc
