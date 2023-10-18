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
             * The Copy/move constructors.
             */
            BinaryTreeLogic(const BinaryTreeLogic&) = delete;
            BinaryTreeLogic(BinaryTreeLogic&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            BinaryTreeLogic& operator=(const BinaryTreeLogic&) = delete;
            BinaryTreeLogic& operator=(BinaryTreeLogic&&) = delete;

            /**
             * Gets the minimum node.
             */
            virtual IBinaryTreeNodeSharedPtr<TKey, TValue> GetMinimumNode(IBinaryTreeNodeSharedPtr<TKey, TValue> root);

            /**
             * Moves to the minimum node by storing the nodes in the stack.
             */
            virtual void MoveMinimumNode(
                IBinaryTreeNodeSharedPtr<TKey, TValue> root,
                std::stack<IBinaryTreeNodeSharedPtr<TKey, TValue>>& stack);

            /**
             * Gets the maximum node.
             */
            virtual IBinaryTreeNodeSharedPtr<TKey, TValue> GetMaximumNode(IBinaryTreeNodeSharedPtr<TKey, TValue> root);

            /**
             * Moves to the maximum node by storing the nodes in the stack.
             */
            virtual void MoveMaximumNode(
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
        IBinaryTreeNodeSharedPtr<TKey, TValue> BinaryTreeLogic<TKey, TValue>::GetMinimumNode(
            IBinaryTreeNodeSharedPtr<TKey, TValue> root)
        {
            IBinaryTreeNodeSharedPtr<TKey, TValue> currNode = root;

            while (currNode.get() != nullptr && currNode->HasLeftChild())
            {
                currNode = currNode->GetLeftChild();
            }

            return currNode;
        }

        /**
         * Moves to the minimum node by storing the nodes in the stack.
         */
        template <typename TKey, typename TValue>
        void BinaryTreeLogic<TKey, TValue>::MoveMinimumNode(
            IBinaryTreeNodeSharedPtr<TKey, TValue> root,
            std::stack<IBinaryTreeNodeSharedPtr<TKey, TValue>>& stack)
        {
            IBinaryTreeNodeSharedPtr<TKey, TValue> currNode = root;

            while (currNode.get() != nullptr)
            {
                stack.push(currNode);
                currNode = currNode->GetLeftChild();
            }
        }

        /**
         * Gets the maximum node.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeNodeSharedPtr<TKey, TValue> BinaryTreeLogic<TKey, TValue>::GetMaximumNode(
            IBinaryTreeNodeSharedPtr<TKey, TValue> root)
        {
            IBinaryTreeNodeSharedPtr<TKey, TValue> currNode = root;

            while (currNode.get() != nullptr && currNode->HasRightChild())
            {
                currNode = currNode->GetRightChild();
            }

            return currNode;
        }

        /**
         * Moves to the maximum node by storing the nodes in the stack.
         */
        template <typename TKey, typename TValue>
        void BinaryTreeLogic<TKey, TValue>::MoveMaximumNode(
            IBinaryTreeNodeSharedPtr<TKey, TValue> root,
            std::stack<IBinaryTreeNodeSharedPtr<TKey, TValue>>& stack)
        {
            IBinaryTreeNodeSharedPtr<TKey, TValue> currNode = root;

            while (currNode.get() != nullptr)
            {
                stack.push(currNode);
                currNode = currNode->GetRightChild();
            }
        }
    }
}

#endif // BINARY_TREE_LOGIC_H_2164cf62_fb7a_456a_9a43_fca1f9e228c4
