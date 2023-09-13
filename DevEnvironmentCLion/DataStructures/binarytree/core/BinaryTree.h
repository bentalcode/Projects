#ifndef BINARY_TREE_H_59e5363d_36db_4417_a926_f104f3bdffd0
#define BINARY_TREE_H_59e5363d_36db_4417_a926_f104f3bdffd0

#include "BinaryTreeNode.h"
#include "IIterator.h"
#include "BinaryTreeLevelOrderIterator.h"
#include "BinaryTreeInorderIterator.h"
#include "BinaryTreePreorderIterator.h"
#include "BinaryTreePostorderIterator.h"
#include "BinaryTreeInorderReverseIterator.h"

namespace datastructures {
    namespace binarytree {

        /**
         * The BinaryTree class implements a binary tree.
         */
        template <typename TKey, typename TValue>
        class BinaryTree final : public IBinaryTree<TKey, TValue> {
        public:

            /**
             * Creates a new binary tree.
             */
            static IBinaryTreeSharedPtr<TKey, TValue> make(IBinaryTreeNodeSharedPtr<TKey, TValue> root = nullptr);

            /**
             * The constructor.
             */
            BinaryTree(IBinaryTreeNodeSharedPtr<TKey, TValue> root = nullptr);

            /**
             * The destructor.
             */
            virtual ~BinaryTree();

            /**
             * The copy/move constructors.
             */
            BinaryTree(const BinaryTree&) = delete;
            BinaryTree(BinaryTree&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            BinaryTree& operator=(const BinaryTree&) = delete;
            BinaryTree& operator=(BinaryTree&&) = delete;

            /**
             * Gets a root of a tree.
             */
            virtual IBinaryTreeNodeSharedPtr<TKey, TValue> getRoot() const override;

            /**
             * Sets a root of a tree.
             */
            virtual void setRoot(IBinaryTreeNodeSharedPtr<TKey, TValue> root) override;

            /**
             * Gets an iterator of a tree.
             */
            virtual base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey , TValue>> getIterator() const override;

            /**
             * Gets a reverse iterator of a tree.
             */
            virtual base::IReverseIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey , TValue>> getReverseIterator() const override;

            /**
             * Gets a level order iterator of a tree.
             */
            virtual base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey , TValue>> getLevelOrderIterator() const override;

            /**
             * Gets an inorder iterator of a tree.
             */
            virtual base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey , TValue>> getInorderIterator() const override;

            /**
             * Gets a preorder iterator of a tree.
             */
            virtual base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey , TValue>> getPreorderIterator() const override;

            /**
             * Gets a postorder iterator of a tree.
             */
            virtual base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey , TValue>> getPostorderIterator() const override;

        private:
            IBinaryTreeNodeSharedPtr<TKey, TValue> m_root;
        };

        /**
         * Creates a new binary tree.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeSharedPtr<TKey, TValue> BinaryTree<TKey, TValue>::make(IBinaryTreeNodeSharedPtr<TKey, TValue> root)
        {
            return std::make_shared<BinaryTree>(root);
        }

        /**
         * The constructor.
         */
        template <typename TKey, typename TValue>
        BinaryTree<TKey, TValue>::BinaryTree(IBinaryTreeNodeSharedPtr<TKey, TValue> root) :
            m_root(root)
        {
        }

        /**
         * The destructor.
         */
        template <typename TKey, typename TValue>
        BinaryTree<TKey, TValue>::~BinaryTree()
        {
        }

        /**
         * Gets a root of a tree.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeNodeSharedPtr<TKey, TValue> BinaryTree<TKey, TValue>::getRoot() const
        {
           return m_root;
        }

        /**
         * Sets a root of a tree.
         */
        template <typename TKey, typename TValue>
        void BinaryTree<TKey, TValue>::setRoot(IBinaryTreeNodeSharedPtr<TKey, TValue> root)
        {
            m_root = root;
        }

        /**
         * Gets an iterator of a tree.
         */
        template <typename TKey, typename TValue>
        base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey , TValue>> BinaryTree<TKey, TValue>::getIterator() const
        {
            return BinaryTreeInorderIterator<TKey, TValue>::make(m_root);
        }

        /**
         * Gets a reverse iterator of a tree.
         */
        template <typename TKey, typename TValue>
        base::IReverseIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey , TValue>> BinaryTree<TKey, TValue>::getReverseIterator() const
        {
            return std::make_shared<BinaryTreeInorderReverseIterator<TKey, TValue>>(m_root);
        }

        /**
         * Gets a level order iterator of a tree.
         */
        template <typename TKey, typename TValue>
        base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> BinaryTree<TKey, TValue>::getLevelOrderIterator() const
        {
            return std::make_shared<BinaryTreeLevelOrderIterator<TKey, TValue>>(m_root);
        }

        /**
         * Gets an inorder iterator of a tree.
         */
        template <typename TKey, typename TValue>
        base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> BinaryTree<TKey, TValue>::getInorderIterator() const
        {
            return BinaryTreeInorderIterator<TKey, TValue>::make(m_root);
        }

        /**
         * Gets a preorder iterator of a tree.
         */
        template <typename TKey, typename TValue>
        base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> BinaryTree<TKey, TValue>::getPreorderIterator() const
        {
            return std::make_shared<BinaryTreePreorderIterator<TKey, TValue>>(m_root);
        }

        /**
         * Gets a postorder iterator of a tree.
         */
        template <typename TKey, typename TValue>
        base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> BinaryTree<TKey, TValue>::getPostorderIterator() const
        {
            return std::make_shared<BinaryTreePostorderIterator<TKey, TValue>>(m_root);
        }
    }
}

#endif // BINARY_TREE_H_59e5363d_36db_4417_a926_f104f3bdffd0
