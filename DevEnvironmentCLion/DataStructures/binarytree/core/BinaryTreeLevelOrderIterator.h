#ifndef BINARY_TREE_LEVEL_ORDER_ITERATOR_H_ea6cd5a6_b24c_495d_89cd_5d4a0b637401
#define BINARY_TREE_LEVEL_ORDER_ITERATOR_H_ea6cd5a6_b24c_495d_89cd_5d4a0b637401

#include "IIterator.h"
#include "IBinaryTreeNode.h"

namespace datastructures {
    namespace binarytree {

        /**
         * The BinaryTreeLevelOrderIterator class implements a level order iterator of a binary tree.
         */
        template <typename TKey, typename TValue>
        class BinaryTreeLevelOrderIterator : public base::IIterator<IBinaryTreeNodeSharedPtr<TKey, TValue>>
        {
        public:
            /**
             * Creates a level order iterator of a binary tree.
             */
            static base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> make(IBinaryTreeNodeSharedPtr<TKey, TValue> root);

            /**
             * The BinaryTreeLevelOrderIterator constructor.
             */
            explicit BinaryTreeLevelOrderIterator(IBinaryTreeNodeSharedPtr<TKey, TValue> root);

            /**
             * The destructor.
             */
            virtual ~BinaryTreeLevelOrderIterator();

            /**
             * The copy/move constructors.
             */
            BinaryTreeLevelOrderIterator(const BinaryTreeLevelOrderIterator&) = delete;
            BinaryTreeLevelOrderIterator(BinaryTreeLevelOrderIterator&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            BinaryTreeLevelOrderIterator& operator=(const BinaryTreeLevelOrderIterator&) = delete;
            BinaryTreeLevelOrderIterator& operator=(BinaryTreeLevelOrderIterator&&) = delete;

            /**
             * Checks whether there is a next element.
             */
            virtual bool hasNext() const;

            /**
             * Gets the next element.
             */
            virtual IBinaryTreeNodeSharedPtr<TKey, TValue> next();

            /**
             * Resets the iterator.
             */
            virtual void reset();

        private:
            IBinaryTreeNodeSharedPtr<TKey, TValue> m_root;
            std::unique_ptr<std::queue<IBinaryTreeNodeSharedPtr<TKey, TValue>>> m_queue;
        };

        /**
         * Creates a level order iterator of a binary tree.
         */
        template <typename TKey, typename TValue>
        base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> BinaryTreeLevelOrderIterator<TKey, TValue>::make(IBinaryTreeNodeSharedPtr<TKey, TValue> root)
        {
            return std::make_shared<BinaryTreeLevelOrderIterator<TKey, TValue>>(root);
        }
        
        /**
         * The BinaryTreeLevelOrderIterator constructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreeLevelOrderIterator<TKey, TValue>::BinaryTreeLevelOrderIterator(IBinaryTreeNodeSharedPtr<TKey, TValue> root) :
            m_root(root)
        {
            reset();
        }

        /**
         * The BinaryTreeLevelOrderIterator destructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreeLevelOrderIterator<TKey, TValue>::~BinaryTreeLevelOrderIterator()
        {
        }

        /**
         * Checks whether there is a next element.
         */
        template <typename TKey, typename TValue>
        bool BinaryTreeLevelOrderIterator<TKey, TValue>::hasNext() const
        {
            return !m_queue->empty();
        }

        /**
         * Gets the next element.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeNodeSharedPtr<TKey, TValue> BinaryTreeLevelOrderIterator<TKey, TValue>::next()
        {
            assert(hasNext());
            IBinaryTreeNodeSharedPtr<TKey, TValue> currNode = m_queue->front();
            m_queue->pop();

            if (currNode->hasLeftChild())
            {
                m_queue->push(currNode->getLeftChild());
            }

            if (currNode->hasRightChild())
            {
                m_queue->push(currNode->getRightChild());
            }

            return currNode;
        }

        /**
         * Resets the iterator.
         */
        template <typename TKey, typename TValue>
        void BinaryTreeLevelOrderIterator<TKey, TValue>::reset()
        {
            m_queue = std::make_unique<std::queue<IBinaryTreeNodeSharedPtr<TKey, TValue>>>();

            if (m_root.get() != nullptr)
            {
                m_queue->push(m_root);
            }
        }
    }
}

#endif // BINARY_TREE_LEVEL_ORDER_ITERATOR_H_ea6cd5a6_b24c_495d_89cd_5d4a0b637401
