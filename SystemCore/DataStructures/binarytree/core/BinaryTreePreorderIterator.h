#ifndef BINARY_TREE_PREORDER_ITERATOR_H_01e217c9_6926_41eb_b00f_e1525f8050ba
#define BINARY_TREE_PREORDER_ITERATOR_H_01e217c9_6926_41eb_b00f_e1525f8050ba

#include "IIterator.h"
#include "IBinaryTreeNode.h"
#include "BinaryTreeLogic.h"

namespace datastructures {
    namespace binarytree {

        /**
         * The BinaryTreePreorderIterator class implements an preorder iterator of a binary tree.
         */
        template <typename TKey, typename TValue>
        class BinaryTreePreorderIterator : public base::IIterator<IBinaryTreeNodeSharedPtr<TKey, TValue>>
        {
        public:
            /**
             * Creates a preorder iterator of a binary tree.
             */
            static base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> Make(IBinaryTreeNodeSharedPtr<TKey, TValue> root);

            /**
             * The BinaryTreePreorderIterator constructor.
             */
            explicit BinaryTreePreorderIterator(IBinaryTreeNodeSharedPtr<TKey, TValue> root);

            /**
             * The destructor.
             */
            virtual ~BinaryTreePreorderIterator();

            /**
             * The Copy/move constructors.
             */
            BinaryTreePreorderIterator(const BinaryTreePreorderIterator&) = delete;
            BinaryTreePreorderIterator(BinaryTreePreorderIterator&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            BinaryTreePreorderIterator& operator=(const BinaryTreePreorderIterator&) = delete;
            BinaryTreePreorderIterator& operator=(BinaryTreePreorderIterator&&) = delete;

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
            std::unique_ptr<std::stack<IBinaryTreeNodeSharedPtr<TKey, TValue>>> m_stack;
            BinaryTreeLogic<TKey, TValue> m_logic;
        };

        /**
         * Creates a preorder iterator of a binary tree.
         */
        template <typename TKey, typename TValue>
        base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> BinaryTreePreorderIterator<TKey, TValue>::Make(IBinaryTreeNodeSharedPtr<TKey, TValue> root)
        {
            return std::make_shared<BinaryTreePreorderIterator<TKey, TValue>>(root);
        }

        /**
         * The BinaryTreePreorderIterator constructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreePreorderIterator<TKey, TValue>::BinaryTreePreorderIterator(IBinaryTreeNodeSharedPtr<TKey, TValue> root) :
            m_root(root)
        {
            Reset();
        }

        /**
         * The BinaryTreePreorderIterator destructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreePreorderIterator<TKey, TValue>::~BinaryTreePreorderIterator()
        {
        }

        /**
         * Checks whether there is a Next element.
         */
        template <typename TKey, typename TValue>
        bool BinaryTreePreorderIterator<TKey, TValue>::HasNext() const
        {
            return !m_stack->empty();
        }

        /**
         * Gets the Next element.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeNodeSharedPtr<TKey, TValue> BinaryTreePreorderIterator<TKey, TValue>::Next()
        {
            assert(HasNext());

            IBinaryTreeNodeSharedPtr<TKey, TValue> currNode = m_stack->top();
            m_stack->pop();

            if (currNode->HasRightChild())
            {
                m_stack->push(currNode->GetRightChild());
            }

            if (currNode->HasLeftChild())
            {
                m_stack->push(currNode->GetLeftChild());
            }

            return currNode;
        }

        /**
         * Resets the iterator.
         */
        template <typename TKey, typename TValue>
        void BinaryTreePreorderIterator<TKey, TValue>::Reset()
        {
            m_stack = std::make_unique<std::stack<IBinaryTreeNodeSharedPtr<TKey, TValue>>>();

            if (m_root.get() != nullptr)
            {
                m_stack->push(m_root);
            }
        }
    }
}

#endif // BINARY_TREE_PREORDER_ITERATOR_H_01e217c9_6926_41eb_b00f_e1525f8050ba
