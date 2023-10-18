#ifndef BINARY_TREE_INORDER_REVERSE_ITERATOR_H_a488af10_de19_4c4f_be26_5d02ee75c220
#define BINARY_TREE_INORDER_REVERSE_ITERATOR_H_a488af10_de19_4c4f_be26_5d02ee75c220

#include "IReverseIterator.h"
#include "IBinaryTreeNode.h"
#include "BinaryTreeLogic.h"
#include <stack>

namespace datastructures {
    namespace binarytree {

        /**
         * The BinaryTreeInorderReverseIterator class implements an inorder reverse iterator of a binary tree.
         */
        template <typename TKey, typename TValue>
        class BinaryTreeInorderReverseIterator : public base::IReverseIterator<IBinaryTreeNodeSharedPtr<TKey, TValue>>
        {
        public:
            /**
             * Creates an inorder reverse iterator of a binary tree.
             */
            static base::IReverseIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> Make(IBinaryTreeNodeSharedPtr<TKey, TValue> root);

            /**
             * The BinaryTreeInorderReverseIterator constructor.
             */
            explicit BinaryTreeInorderReverseIterator(IBinaryTreeNodeSharedPtr<TKey, TValue> root);

            /**
             * The destructor.
             */
            virtual ~BinaryTreeInorderReverseIterator();

            /**
             * The Copy/move constructors.
             */
            BinaryTreeInorderReverseIterator(const BinaryTreeInorderReverseIterator&) = delete;
            BinaryTreeInorderReverseIterator(BinaryTreeInorderReverseIterator&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            BinaryTreeInorderReverseIterator& operator=(const BinaryTreeInorderReverseIterator&) = delete;
            BinaryTreeInorderReverseIterator& operator=(BinaryTreeInorderReverseIterator&&) = delete;

            /**
             * Checks whether there is a next element.
             */
            virtual bool HasNext() const;

            /**
             * Gets the next element.
             */
            virtual IBinaryTreeNodeSharedPtr<TKey, TValue> Next();

            /**
             * Resets the iterator.
             */
            virtual void Reset();

        private:
            IBinaryTreeNodeSharedPtr<TKey, TValue> m_root;
            std::unique_ptr<std::stack<IBinaryTreeNodeSharedPtr<TKey, TValue>>> m_stack;
            BinaryTreeLogic<TKey, TValue> m_logic;
        };

        /**
         * Creates an inorder reverse iterator of a binary tree.
         */
        template <typename TKey, typename TValue>
        base::IReverseIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> BinaryTreeInorderReverseIterator<TKey, TValue>::Make(IBinaryTreeNodeSharedPtr<TKey, TValue> root)
        {
            return std::make_shared<BinaryTreeInorderReverseIterator<TKey, TValue>>(root);
        }

        /**
         * The BinaryTreeInorderReverseIterator constructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreeInorderReverseIterator<TKey, TValue>::BinaryTreeInorderReverseIterator(IBinaryTreeNodeSharedPtr<TKey, TValue> root) :
            m_root(root)
        {
            Reset();
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
        bool BinaryTreeInorderReverseIterator<TKey, TValue>::HasNext() const
        {
            return !m_stack->empty();
        }

        /**
         * Gets the next element.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeNodeSharedPtr<TKey, TValue> BinaryTreeInorderReverseIterator<TKey, TValue>::Next()
        {
            assert(HasNext());
            IBinaryTreeNodeSharedPtr<TKey, TValue> currNode = m_stack->top();
            m_stack->pop();

            if (currNode->HasLeftChild())
            {
                m_logic.MoveMaximumNode(currNode->GetLeftChild(), *m_stack);
            }

            return currNode;
        }

        /**
         * Resets the iterator.
         */
        template <typename TKey, typename TValue>
        void BinaryTreeInorderReverseIterator<TKey, TValue>::Reset()
        {
            m_stack = std::make_unique<std::stack<IBinaryTreeNodeSharedPtr<TKey, TValue>>>();

            if (m_root.get() != nullptr)
            {
                m_logic.MoveMaximumNode(m_root, *m_stack);
            }
        }
    }
}

#endif // BINARY_TREE_INORDER_REVERSE_ITERATOR_H_a488af10_de19_4c4f_be26_5d02ee75c220
