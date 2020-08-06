#ifndef BINARY_TREE_LOGIC_H_2164cf62_fb7a_456a_9a43_fca1f9e228c4
#define BINARY_TREE_LOGIC_H_2164cf62_fb7a_456a_9a43_fca1f9e228c4

#include "IBinaryTreeLogic.h"

namespace datastructures {
    namespace binarytree {

        /**
         * The BinaryTreeLogic class implements logic of a binary tree.
         */
        template<typename TKey, typename TValue>
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
            virtual IBinaryTreeNodePtr<TKey, TValue> getMinimumNode(IBinaryTreeNodePtr<TKey, TValue> root);

            /**
             * Moves to the minimum node by storing the nodes in the stack.
             */
            virtual void moveMinimumNode(
                IBinaryTreeNodePtr<TKey, TValue> root,
                std::stack<IBinaryTreeNodePtr<TKey, TValue>>& stack);

            /**
             * Gets the maximum node.
             */
            virtual IBinaryTreeNodePtr<TKey, TValue> getMaximumNode(IBinaryTreeNodePtr<TKey, TValue> root);

            /**
             * Moves to the maximum node by storing the nodes in the stack.
             */
            virtual void moveMaximumNode(
                IBinaryTreeNodePtr<TKey, TValue> root,
                std::stack<IBinaryTreeNodePtr<TKey, TValue>>& stack);
        };

        /**
         * The BinaryTreeLogic constructor.
         */
        template<typename TKey, typename TValue>
        BinaryTreeLogic<TKey, TValue>::BinaryTreeLogic()
        {
        }

        /**
         * The BinaryTreeLogic destructor.
         */
        template<typename TKey, typename TValue>
        BinaryTreeLogic<TKey, TValue>::~BinaryTreeLogic()
        {
        }

        /**
         * Gets the minimum node.
         */
        template<typename TKey, typename TValue>
        IBinaryTreeNodePtr<TKey, TValue> BinaryTreeLogic<TKey, TValue>::getMinimumNode(
            IBinaryTreeNodePtr<TKey, TValue> root)
        {
            IBinaryTreeNodePtr<TKey, TValue> currNode = root;

            while (currNode.get() != nullptr && currNode->hasLeftChild())
            {
                currNode = currNode->getLeftChild();
            }

            return currNode;
        }

        /**
         * Moves to the minimum node by storing the nodes in the stack.
         */
        template<typename TKey, typename TValue>
        void BinaryTreeLogic<TKey, TValue>::moveMinimumNode(
            IBinaryTreeNodePtr<TKey, TValue> root,
            std::stack<IBinaryTreeNodePtr<TKey, TValue>>& stack)
        {
            IBinaryTreeNodePtr<TKey, TValue> currNode = root;

            while (currNode.get() != nullptr)
            {
                stack.push(currNode);
                currNode = currNode->getLeftChild();
            }
        }

        /**
         * Gets the maximum node.
         */
        template<typename TKey, typename TValue>
        IBinaryTreeNodePtr<TKey, TValue> BinaryTreeLogic<TKey, TValue>::getMaximumNode(
            IBinaryTreeNodePtr<TKey, TValue> root)
        {
            IBinaryTreeNodePtr<TKey, TValue> currNode = root;

            while (currNode.get() != nullptr && currNode->hasRightChild())
            {
                currNode = currNode->getRightChild();
            }

            return currNode;
        }

        /**
         * Moves to the maximum node by storing the nodes in the stack.
         */
        template<typename TKey, typename TValue>
        void BinaryTreeLogic<TKey, TValue>::moveMaximumNode(
            IBinaryTreeNodePtr<TKey, TValue> root,
            std::stack<IBinaryTreeNodePtr<TKey, TValue>>& stack)
        {
            IBinaryTreeNodePtr<TKey, TValue> currNode = root;

            while (currNode.get() != nullptr)
            {
                stack.push(currNode);
                currNode = currNode->getRightChild();
            }
        }
    }
}

#endif // BINARY_TREE_LOGIC_H_2164cf62_fb7a_456a_9a43_fca1f9e228c4
