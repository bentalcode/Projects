#ifndef I_BINARY_TREE_H_80c4d24f_227c_411c_96d3_19fb108187fc
#define I_BINARY_TREE_H_80c4d24f_227c_411c_96d3_19fb108187fc

#include "IIterable.h"
#include "IReverseIterable.h"
#include "BinaryTreeLevelOrderWithEndNodesIterator.h"
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
         * Defines SharedPtr Of Binary Tree.
         */
        template <typename TKey, typename TValue>
        using IBinaryTreeSharedPtr = std::shared_ptr<IBinaryTree<TKey, TValue>>;

        /**
         * Defines operator less for binary trees.
         */
        template <typename TKey, typename TValue>
        bool operator<(const IBinaryTree<TKey, TValue>& left, const IBinaryTree<TKey, TValue>& right)
        {
            base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> lhsIterator =
                BinaryTreeLevelOrderWithEndNodesIterator<TKey, TValue>::of(left.GetRoot());

            base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> rhsIterator =
                BinaryTreeLevelOrderWithEndNodesIterator<TKey, TValue>::of(right.GetRoot());

            base::CompareToBuilder compareToBuilder;
            bool status = compareToBuilder.withDereferenceIterator(
                    *lhsIterator,
                    *rhsIterator).Build();

            return status < 0;
        }
    }
}

#endif // I_BINARY_TREE_H_80c4d24f_227c_411c_96d3_19fb108187fc
