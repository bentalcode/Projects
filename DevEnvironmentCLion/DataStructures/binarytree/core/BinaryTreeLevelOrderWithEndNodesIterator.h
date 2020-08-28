#ifndef BINARY_TREE_LEVEL_ORDER_WITH_END_NODE_ITERATOR_H_46787627_a362_4621_8bb0_853ff706e23a
#define BINARY_TREE_LEVEL_ORDER_WITH_END_NODE_ITERATOR_H_46787627_a362_4621_8bb0_853ff706e23a

#include "IIterator.h"
#include "IBinaryTreeNode.h"
#include "BinaryTreeNodes.h"

namespace datastructures {
    namespace binarytree {

        /**
         * The BinaryTreeLevelOrderWithEndNodesIterator class implements a level order iterator of a binary tree.
         */
        template<typename TKey, typename TValue>
        class BinaryTreeLevelOrderWithEndNodesIterator : public base::IIterator<IBinaryTreeNodePtr<TKey, TValue>>
        {
        public:
            /**
             * Creates a level order iterator with end nodes of a binary tree.
             */
            static base::IIteratorPtr<IBinaryTreeNodePtr<TKey, TValue>> make(IBinaryTreeNodePtr<TKey, TValue> root);

            /**
             * The BinaryTreeLevelOrderWithEndNodesIterator constructor.
             */
            explicit BinaryTreeLevelOrderWithEndNodesIterator(IBinaryTreeNodePtr<TKey, TValue> root);

            /**
             * The destructor.
             */
            virtual ~BinaryTreeLevelOrderWithEndNodesIterator();

            /**
             * The copy/move constructors.
             */
            BinaryTreeLevelOrderWithEndNodesIterator(const BinaryTreeLevelOrderWithEndNodesIterator&) = delete;
            BinaryTreeLevelOrderWithEndNodesIterator(BinaryTreeLevelOrderWithEndNodesIterator&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            BinaryTreeLevelOrderWithEndNodesIterator& operator=(const BinaryTreeLevelOrderWithEndNodesIterator&) = delete;
            BinaryTreeLevelOrderWithEndNodesIterator& operator=(BinaryTreeLevelOrderWithEndNodesIterator&&) = delete;

            /**
             * Checks whether there is a next element.
             */
            virtual bool hasNext() const;

            /**
             * Gets the next element.
             */
            virtual IBinaryTreeNodePtr<TKey, TValue> next();

            /**
             * Resets the iterator.
             */
            virtual void reset();

        private:
            IBinaryTreeNodePtr<TKey, TValue> m_root;
            std::unique_ptr<std::queue<IBinaryTreeNodePtr<TKey, TValue>>> m_queue;
        };

        /**
         * Creates a level order iterator with end nodes of a binary tree.
         */
        template <typename TKey, typename TValue>
        base::IIteratorPtr<IBinaryTreeNodePtr<TKey, TValue>> BinaryTreeLevelOrderWithEndNodesIterator<TKey, TValue>::make(IBinaryTreeNodePtr<TKey, TValue> root)
        {
            return std::make_shared<BinaryTreeLevelOrderWithEndNodesIterator<TKey, TValue>>(root);
        }

        /**
         * The BinaryTreeLevelOrderWithEndNodesIterator constructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreeLevelOrderWithEndNodesIterator<TKey, TValue>::BinaryTreeLevelOrderWithEndNodesIterator(IBinaryTreeNodePtr<TKey, TValue> root) :
            m_root(root)
        {
            reset();
        }

        /**
         * The BinaryTreeLevelOrderWithEndNodesIterator destructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreeLevelOrderWithEndNodesIterator<TKey, TValue>::~BinaryTreeLevelOrderWithEndNodesIterator()
        {
        }

        /**
         * Checks whether there is a next element.
         */
        template <typename TKey, typename TValue>
        bool BinaryTreeLevelOrderWithEndNodesIterator<TKey, TValue>::hasNext() const
        {
            return !m_queue->empty();
        }

        /**
         * Gets the next element.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeNodePtr<TKey, TValue> BinaryTreeLevelOrderWithEndNodesIterator<TKey, TValue>::next()
        {
            assert(hasNext());
            IBinaryTreeNodePtr<TKey, TValue> currNode = m_queue->front();
            m_queue->pop();

            m_queue->push(currNode->hasLeftChild() ?
                currNode->getLeftChild() :
                BinaryTreeNodes::endNode<TKey, TValue>());

            m_queue->push(currNode->getRightChild() ?
                currNode->getRightChild() :
                BinaryTreeNodes::endNode<TKey, TValue>());

            return currNode;
        }

        /**
         * Resets the iterator.
         */
        template <typename TKey, typename TValue>
        void BinaryTreeLevelOrderWithEndNodesIterator<TKey, TValue>::reset()
        {
            m_queue = std::make_unique<std::queue<IBinaryTreeNodePtr<TKey, TValue>>>();

            if (m_root.get() != nullptr)
            {
                m_queue->push(m_root);
            }
        }
    }
}

#endif // BINARY_TREE_LEVEL_ORDER_WITH_END_NODE_ITERATOR_H_46787627_a362_4621_8bb0_853ff706e23a
