#ifndef BINARY_TREE_LOGIC_H_2164cf62_fb7a_456a_9a43_fca1f9e228c4
#define BINARY_TREE_LOGIC_H_2164cf62_fb7a_456a_9a43_fca1f9e228c4

#include "IBinaryTreeLogic.h"

namespace datastructures {
    namespace binarytree {

        /**
         * The BinaryTreeLogic class implements logic of a binary tree.
         */
        template <typename TKey, typename TValue>
        class BinaryTreeLogic : public IBinaryTreeLogic<TKey, TValue>
        {
        public:
            /**
             * The BinaryTreeLogic constructor.
             */
            BinaryTreeLogic();

            /**
             * The BinaryTreeLogic destructor.
             */
            virtual ~BinaryTreeLogic();

            /**
             * The copy/move constructors.
             */
            BinaryTreeLogic(const BinaryTreeLogic&) = delete;
            BinaryTreeLogic(BinaryTreeLogic&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            BinaryTreeLogic& operator=(const BinaryTreeLogic&) = delete;
            BinaryTreeLogic& operator=(BinaryTreeLogic&&) = delete;

            /**
             * Gets the minimum node.
             */
            virtual IBinaryTreeNodeSharedPtr<TKey, TValue> getMinimumNode(IBinaryTreeNodeSharedPtr<TKey, TValue> root);

            /**
             * Moves to the minimum node by storing the nodes in the stack.
             */
            virtual void moveMinimumNode(
                IBinaryTreeNodeSharedPtr<TKey, TValue> root,
                std::stack<IBinaryTreeNodeSharedPtr<TKey, TValue>>& stack);

            /**
             * Gets the maximum node.
             */
            virtual IBinaryTreeNodeSharedPtr<TKey, TValue> getMaximumNode(IBinaryTreeNodeSharedPtr<TKey, TValue> root);

            /**
             * Moves to the maximum node by storing the nodes in the stack.
             */
            virtual void moveMaximumNode(
                IBinaryTreeNodeSharedPtr<TKey, TValue> root,
                std::stack<IBinaryTreeNodeSharedPtr<TKey, TValue>>& stack);
        };

        /**
         * The BinaryTreeLogic constructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreeLogic<TKey, TValue>::BinaryTreeLogic()
        {
        }

        /**
         * The BinaryTreeLogic destructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreeLogic<TKey, TValue>::~BinaryTreeLogic()
        {
        }

        /**
         * Gets the minimum node.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeNodeSharedPtr<TKey, TValue> BinaryTreeLogic<TKey, TValue>::getMinimumNode(
            IBinaryTreeNodeSharedPtr<TKey, TValue> root)
        {
            IBinaryTreeNodeSharedPtr<TKey, TValue> currNode = root;

            while (currNode.get() != nullptr && currNode->hasLeftChild())
            {
                currNode = currNode->getLeftChild();
            }

            return currNode;
        }

        /**
         * Moves to the minimum node by storing the nodes in the stack.
         */
        template <typename TKey, typename TValue>
        void BinaryTreeLogic<TKey, TValue>::moveMinimumNode(
            IBinaryTreeNodeSharedPtr<TKey, TValue> root,
            std::stack<IBinaryTreeNodeSharedPtr<TKey, TValue>>& stack)
        {
            IBinaryTreeNodeSharedPtr<TKey, TValue> currNode = root;

            while (currNode.get() != nullptr)
            {
                stack.push(currNode);
                currNode = currNode->getLeftChild();
            }
        }

        /**
         * Gets the maximum node.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeNodeSharedPtr<TKey, TValue> BinaryTreeLogic<TKey, TValue>::getMaximumNode(
            IBinaryTreeNodeSharedPtr<TKey, TValue> root)
        {
            IBinaryTreeNodeSharedPtr<TKey, TValue> currNode = root;

            while (currNode.get() != nullptr && currNode->hasRightChild())
            {
                currNode = currNode->getRightChild();
            }

            return currNode;
        }

        /**
         * Moves to the maximum node by storing the nodes in the stack.
         */
        template <typename TKey, typename TValue>
        void BinaryTreeLogic<TKey, TValue>::moveMaximumNode(
            IBinaryTreeNodeSharedPtr<TKey, TValue> root,
            std::stack<IBinaryTreeNodeSharedPtr<TKey, TValue>>& stack)
        {
            IBinaryTreeNodeSharedPtr<TKey, TValue> currNode = root;

            while (currNode.get() != nullptr)
            {
                stack.push(currNode);
                currNode = currNode->getRightChild();
            }
        }
    }
}

#endif // BINARY_TREE_LOGIC_H_2164cf62_fb7a_456a_9a43_fca1f9e228c4
