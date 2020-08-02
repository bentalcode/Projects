#ifndef BINARY_TREE_H_59e5363d_36db_4417_a926_f104f3bdffd0
#define BINARY_TREE_H_59e5363d_36db_4417_a926_f104f3bdffd0

#include "BinaryTreeNode.h"
#include "IIterator.h"

namespace datastructures {
    namespace binarytree {

        /**
         * The BinaryTree class implements a binary tree.
         */
        template<typename TKey, typename TValue>
        class BinaryTree {
        public:
            /**
             * The constructor.
             */
            BinaryTree(IBinaryTreeNode<TKey, TValue>* root = nullptr);

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
            virtual IBinaryTreeNode<TKey, TValue>* getRoot() const;

            /**
             * Sets a root of a tree.
             */
            virtual void setRoot(IBinaryTreeNode<TKey, TValue>* root);

            /**
             * Gets a level order iterator of a tree.
             */
            virtual base::IIteratorPtr<IBinaryTreeNode<TKey , TValue>*> getLevelOrderIterator();

            /**
             * Gets an inorder iterator of a tree.
             */
            virtual base::IIteratorPtr<IBinaryTreeNode<TKey , TValue>*> getInorderIterator();

            /**
             * Gets a preorder iterator of a tree.
             */
            virtual base::IIteratorPtr<IBinaryTreeNode<TKey , TValue>*> getPreorderIterator();

            /**
             * Gets a postorder iterator of a tree.
             */
            virtual base::IIteratorPtr<IBinaryTreeNode<TKey , TValue>*> getPostorderIterator();

        private:
            IBinaryTreeNode<TKey, TValue>* m_root;
        };

        /**
         * The constructor.
         */
        template<typename TKey, typename TValue>
        BinaryTree<TKey, TValue>::BinaryTree(IBinaryTreeNode<TKey, TValue>* root) :
            m_root(root)
        {
        }

        /**
         * The destructor.
         */
        template<typename TKey, typename TValue>
        BinaryTree<TKey, TValue>::~BinaryTree()
        {
        }

        /**
         * Gets a root of a tree.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeNode<TKey, TValue>* BinaryTree<TKey, TValue>::getRoot() const
        {
           return m_root;
        }

        /**
         * Sets a root of a tree.
         */
        template <typename TKey, typename TValue>
        void BinaryTree<TKey, TValue>::setRoot(IBinaryTreeNode<TKey, TValue>* root)
        {
            m_root = root;
        }

        /**
         * Gets a level order iterator of a tree.
         */
        template <typename TKey, typename TValue>
        base::IIteratorPtr<IBinaryTreeNode<TKey , TValue>*> BinaryTree<TKey, TValue>::getLevelOrderIterator()
        {
            return nullptr;
        }

        /**
         * Gets an inorder iterator of a tree.
         */
        template <typename TKey, typename TValue>
        base::IIteratorPtr<IBinaryTreeNode<TKey , TValue>*> BinaryTree<TKey, TValue>::getInorderIterator()
        {
            return nullptr;
        }

        /**
         * Gets a preorder iterator of a tree.
         */
        template <typename TKey, typename TValue>
        base::IIteratorPtr<IBinaryTreeNode<TKey , TValue>*> BinaryTree<TKey, TValue>::getPreorderIterator()
        {
            return nullptr;
        }

        /**
         * Gets a postorder iterator of a tree.
         */
        template <typename TKey, typename TValue>
        base::IIteratorPtr<IBinaryTreeNode<TKey , TValue>*> BinaryTree<TKey, TValue>::getPostorderIterator()
        {
            return nullptr;
        }
    }
}

#endif // BINARY_TREE_H_59e5363d_36db_4417_a926_f104f3bdffd0
