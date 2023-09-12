#ifndef BINARY_TREE_INORDER_REVERSE_ITERATOR_H_a488af10_de19_4c4f_be26_5d02ee75c220
#define BINARY_TREE_INORDER_REVERSE_ITERATOR_H_a488af10_de19_4c4f_be26_5d02ee75c220

#include "IReverseIterator.h"
#include "IBinaryTreeNode.h"
#include "BinaryTreeLogic.h"

namespace datastructures {
    namespace binarytree {

        /**
         * The BinaryTreeInorderReverseIterator class implements an inorder reverse iterator of a binary tree.
         */
        template <typename TKey, typename TValue>
        class BinaryTreeInorderReverseIterator : public base::IReverseIterator<IBinaryTreeNodePtr<TKey, TValue>>
        {
        public:
            /**
             * Creates an inorder reverse iterator of a binary tree.
             */
            static base::IReverseIteratorSharedPtr<IBinaryTreeNodePtr<TKey, TValue>> make(IBinaryTreeNodePtr<TKey, TValue> root);

            /**
             * The BinaryTreeInorderReverseIterator constructor.
             */
            explicit BinaryTreeInorderReverseIterator(IBinaryTreeNodePtr<TKey, TValue> root);

            /**
             * The destructor.
             */
            virtual ~BinaryTreeInorderReverseIterator();

            /**
             * The copy/move constructors.
             */
            BinaryTreeInorderReverseIterator(const BinaryTreeInorderReverseIterator&) = delete;
            BinaryTreeInorderReverseIterator(BinaryTreeInorderReverseIterator&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            BinaryTreeInorderReverseIterator& operator=(const BinaryTreeInorderReverseIterator&) = delete;
            BinaryTreeInorderReverseIterator& operator=(BinaryTreeInorderReverseIterator&&) = delete;

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
            std::unique_ptr<std::stack<IBinaryTreeNodePtr<TKey, TValue>>> m_stack;
            BinaryTreeLogic<TKey, TValue> m_logic;
        };

        /**
         * Creates an inorder reverse iterator of a binary tree.
         */
        template <typename TKey, typename TValue>
        base::IReverseIteratorSharedPtr<IBinaryTreeNodePtr<TKey, TValue>> BinaryTreeInorderReverseIterator<TKey, TValue>::make(IBinaryTreeNodePtr<TKey, TValue> root)
        {
            return std::make_shared<BinaryTreeInorderReverseIterator<TKey, TValue>>(root);
        }

        /**
         * The BinaryTreeInorderReverseIterator constructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreeInorderReverseIterator<TKey, TValue>::BinaryTreeInorderReverseIterator(IBinaryTreeNodePtr<TKey, TValue> root) :
            m_root(root)
        {
            reset();
        }

        /**
         * The BinaryTreeInorderReverseIterator destructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreeInorderReverseIterator<TKey, TValue>::~BinaryTreeInorderReverseIterator()
        {
        }

        /**
         * Checks whether there is a next element.
         */
        template <typename TKey, typename TValue>
        bool BinaryTreeInorderReverseIterator<TKey, TValue>::hasNext() const
        {
            return !m_stack->empty();
        }

        /**
         * Gets the next element.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeNodePtr<TKey, TValue> BinaryTreeInorderReverseIterator<TKey, TValue>::next()
        {
            assert(hasNext());
            IBinaryTreeNodePtr<TKey, TValue> currNode = m_stack->top();
            m_stack->pop();

            if (currNode->hasLeftChild())
            {
                m_logic.moveMaximumNode(currNode->getLeftChild(), *m_stack);
            }

            return currNode;
        }

        /**
         * Resets the iterator.
         */
        template <typename TKey, typename TValue>
        void BinaryTreeInorderReverseIterator<TKey, TValue>::reset()
        {
            m_stack = std::make_unique<std::stack<IBinaryTreeNodePtr<TKey, TValue>>>();

            if (m_root.get() != nullptr)
            {
                m_logic.moveMaximumNode(m_root, *m_stack);
            }
        }
    }
}

#endif // BINARY_TREE_INORDER_REVERSE_ITERATOR_H_a488af10_de19_4c4f_be26_5d02ee75c220
