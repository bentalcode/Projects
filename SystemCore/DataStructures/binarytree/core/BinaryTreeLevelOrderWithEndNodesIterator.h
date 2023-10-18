#ifndef BINARY_TREE_LEVEL_ORDER_WITH_END_NODE_ITERATOR_H_46787627_a362_4621_8bb0_853ff706e23a
#define BINARY_TREE_LEVEL_ORDER_WITH_END_NODE_ITERATOR_H_46787627_a362_4621_8bb0_853ff706e23a

#include "IIterator.h"
#include "IBinaryTreeNode.h"
#include "BinaryTreeNodes.h"
#include <queue>

namespace datastructures {
    namespace binarytree {

        /**
         * The BinaryTreeLevelOrderWithEndNodesIterator class implements a level order iterator of a binary tree.
         */
        template <typename TKey, typename TValue>
        class BinaryTreeLevelOrderWithEndNodesIterator : public base::IIterator<IBinaryTreeNodeSharedPtr<TKey, TValue>>
        {
        public:
            /**
             * Creates a level order iterator with end nodes of a binary tree.
             */
            static base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> Make(IBinaryTreeNodeSharedPtr<TKey, TValue> root);

            /**
             * The BinaryTreeLevelOrderWithEndNodesIterator constructor.
             */
            explicit BinaryTreeLevelOrderWithEndNodesIterator(IBinaryTreeNodeSharedPtr<TKey, TValue> root);

            /**
             * The destructor.
             */
            virtual ~BinaryTreeLevelOrderWithEndNodesIterator();

            /**
             * The Copy/move constructors.
             */
            BinaryTreeLevelOrderWithEndNodesIterator(const BinaryTreeLevelOrderWithEndNodesIterator&) = delete;
            BinaryTreeLevelOrderWithEndNodesIterator(BinaryTreeLevelOrderWithEndNodesIterator&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            BinaryTreeLevelOrderWithEndNodesIterator& operator=(const BinaryTreeLevelOrderWithEndNodesIterator&) = delete;
            BinaryTreeLevelOrderWithEndNodesIterator& operator=(BinaryTreeLevelOrderWithEndNodesIterator&&) = delete;

            /**
             * Checks whether there is a Next element.
             */
            virtual bool HasNext() const;

            /**
             * Gets the Next element.
             */
            virtual IBinaryTreeNodeSharedPtr<TKey, TValue> Next();

            /**
             * Resets the iterator.
             */
            virtual void Reset();

        private:
            IBinaryTreeNodeSharedPtr<TKey, TValue> m_root;
            std::unique_ptr<std::queue<IBinaryTreeNodeSharedPtr<TKey, TValue>>> m_queue;
        };

        /**
         * Creates a level order iterator with end nodes of a binary tree.
         */
        template <typename TKey, typename TValue>
        base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> BinaryTreeLevelOrderWithEndNodesIterator<TKey, TValue>::Make(
            IBinaryTreeNodeSharedPtr<TKey, TValue> root)
        {
            return std::make_shared<BinaryTreeLevelOrderWithEndNodesIterator<TKey, TValue>>(root);
        }

        /**
         * The BinaryTreeLevelOrderWithEndNodesIterator constructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreeLevelOrderWithEndNodesIterator<TKey, TValue>::BinaryTreeLevelOrderWithEndNodesIterator(
            IBinaryTreeNodeSharedPtr<TKey, TValue> root) :
            m_root(root)
        {
            Reset();
        }

        /**
         * The BinaryTreeLevelOrderWithEndNodesIterator destructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreeLevelOrderWithEndNodesIterator<TKey, TValue>::~BinaryTreeLevelOrderWithEndNodesIterator()
        {
        }

        /**
         * Checks whether there is a Next element.
         */
        template <typename TKey, typename TValue>
        bool BinaryTreeLevelOrderWithEndNodesIterator<TKey, TValue>::HasNext() const
        {
            return !m_queue->Empty();
        }

        /**
         * Gets the Next element.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeNodeSharedPtr<TKey, TValue> BinaryTreeLevelOrderWithEndNodesIterator<TKey, TValue>::Next()
        {
            assert(HasNext());
            IBinaryTreeNodeSharedPtr<TKey, TValue> currNode = m_queue->front();
            m_queue->pop();

            m_queue->push(currNode->HasLeftChild() ?
                currNode->GetLeftChild() :
                BinaryTreeNodes::EndNode<TKey, TValue>());

            m_queue->push(currNode->GetRightChild() ?
                currNode->GetRightChild() :
                BinaryTreeNodes::EndNode<TKey, TValue>());

            return currNode;
        }

        /**
         * Resets the iterator.
         */
        template <typename TKey, typename TValue>
        void BinaryTreeLevelOrderWithEndNodesIterator<TKey, TValue>::Reset()
        {
            m_queue = std::make_unique<std::queue<IBinaryTreeNodeSharedPtr<TKey, TValue>>>();

            if (m_root.get() != nullptr)
            {
                m_queue->push(m_root);
            }
        }
    }
}

#endif // BINARY_TREE_LEVEL_ORDER_WITH_END_NODE_ITERATOR_H_46787627_a362_4621_8bb0_853ff706e23a
