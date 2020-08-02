#ifndef I_BINARY_TREE_H_80c4d24f_227c_411c_96d3_19fb108187fc
#define I_BINARY_TREE_H_80c4d24f_227c_411c_96d3_19fb108187fc

#include "IBinaryTreeNode.h"
#include "IIterator.h"

namespace datastructures {
    namespace binarytree {

        /**
         * The IBinaryTree interface defines a binary tree.
         */
        template<typename TKey, typename TValue>
        class IBinaryTree
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
            virtual IBinaryTreeNode<TKey, TValue>* getRoot() const = 0;

            /**
             * Sets a root of a tree.
             */
            virtual void setRoot(IBinaryTreeNode<TKey, TValue>* root) = 0;

            /**
             * Gets a level order iterator of a tree.
             */
            virtual base::IIteratorPtr<IBinaryTreeNode<TKey , TValue>*> getLevelOrderIterator() const = 0;

            /**
             * Gets an inorder iterator of a tree.
             */
            virtual base::IIteratorPtr<IBinaryTreeNode<TKey , TValue>*> getInorderIterator() const = 0;

            /**
             * Gets a preorder iterator of a tree.
             */
            virtual base::IIteratorPtr<IBinaryTreeNode<TKey , TValue>*> getPreorderIterator() const = 0;

            /**
             * Gets a postorder iterator of a tree.
             */
            virtual base::IIteratorPtr<IBinaryTreeNode<TKey , TValue>*> getPostorderIterator() const = 0;
        };

        template <typename TKey, typename TValue>
        using IBinaryTreePtr = std::shared_ptr<IBinaryTree<TKey, TValue>>;
    }
}

#endif // I_BINARY_TREE_H_80c4d24f_227c_411c_96d3_19fb108187fc
