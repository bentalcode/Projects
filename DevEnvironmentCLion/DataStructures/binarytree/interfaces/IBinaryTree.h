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
            base::IIterable<IBinaryTreeNodePtr<TKey, TValue>>,
            base::IReverseIterable<IBinaryTreeNodePtr<TKey, TValue>>
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
             * The copy/move constructors.
             */
            IBinaryTree(const IBinaryTree&) = delete;
            IBinaryTree(IBinaryTree&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            IBinaryTree& operator=(const IBinaryTree&) = delete;
            IBinaryTree& operator=(IBinaryTree&&) = delete;

            /**
             * Gets a root of a tree.
             */
            virtual IBinaryTreeNodePtr<TKey, TValue> getRoot() const = 0;

            /**
             * Sets a root of a tree.
             */
            virtual void setRoot(IBinaryTreeNodePtr<TKey, TValue> root) = 0;

            /**
             * Gets an iterator of a tree.
             */
            virtual base::IIteratorPtr<IBinaryTreeNodePtr<TKey , TValue>> getIterator() const = 0;

            /**
             * Gets a reverse iterator of a tree.
             */
            virtual base::IReverseIteratorPtr<IBinaryTreeNodePtr<TKey , TValue>> getReverseIterator() const = 0;

            /**
             * Gets a level order iterator of a tree.
             */
            virtual base::IIteratorPtr<IBinaryTreeNodePtr<TKey, TValue>> getLevelOrderIterator() const = 0;

            /**
             * Gets an inorder iterator of a tree.
             */
            virtual base::IIteratorPtr<IBinaryTreeNodePtr<TKey, TValue>> getInorderIterator() const = 0;

            /**
             * Gets a preorder iterator of a tree.
             */
            virtual base::IIteratorPtr<IBinaryTreeNodePtr<TKey, TValue>> getPreorderIterator() const = 0;

            /**
             * Gets a postorder iterator of a tree.
             */
            virtual base::IIteratorPtr<IBinaryTreeNodePtr<TKey, TValue>> getPostorderIterator() const = 0;
        };

        template <typename TKey, typename TValue>
        using IBinaryTreePtr = std::shared_ptr<IBinaryTree<TKey, TValue>>;

        template <typename TKey, typename TValue>
        bool operator<(const IBinaryTree<TKey, TValue>& left, const IBinaryTree<TKey, TValue>& right)
        {
            base::IIteratorPtr<IBinaryTreeNodePtr<TKey, TValue>> lhsIterator =
                BinaryTreeLevelOrderWithEndNodesIterator<TKey, TValue>::of(left.getRoot());

            base::IIteratorPtr<IBinaryTreeNodePtr<TKey, TValue>> rhsIterator =
                BinaryTreeLevelOrderWithEndNodesIterator<TKey, TValue>::of(right.getRoot());

            base::CompareToBuilder compareToBuilder;
            bool status = compareToBuilder.withDereferenceIterator(
                lhsIterator,
                rhsIterator).build();

            return status <= 1;
        }
    }
}

#endif // I_BINARY_TREE_H_80c4d24f_227c_411c_96d3_19fb108187fc
