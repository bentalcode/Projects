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
        template<typename TKey, typename TValue>
        class BinaryTreePreorderIterator : public base::IIterator<IBinaryTreeNodePtr<TKey, TValue>>
        {
        public:
            /**
             * Creates a preorder iterator of a binary tree.
             */
            static base::IIteratorPtr<IBinaryTreeNodePtr<TKey, TValue>> of(IBinaryTreeNodePtr<TKey, TValue> root)
            {
                return std::make_shared<BinaryTreePreorderIterator<TKey, TValue>>(root);
            }

            /**
             * The BinaryTreePreorderIterator constructor.
             */
            explicit BinaryTreePreorderIterator(IBinaryTreeNodePtr<TKey, TValue> root);

            /**
             * The destructor.
             */
            virtual ~BinaryTreePreorderIterator();

            /**
             * The copy/move constructors.
             */
            BinaryTreePreorderIterator(const BinaryTreePreorderIterator&) = delete;
            BinaryTreePreorderIterator(BinaryTreePreorderIterator&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            BinaryTreePreorderIterator& operator=(const BinaryTreePreorderIterator&) = delete;
            BinaryTreePreorderIterator& operator=(BinaryTreePreorderIterator&&) = delete;

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

        template <typename TKey, typename TValue>
        using BinaryTreePreorderIteratorPtr = std::shared_ptr<BinaryTreePreorderIterator<TKey, TValue>>;

        /**
         * The BinaryTreePreorderIterator constructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreePreorderIterator<TKey, TValue>::BinaryTreePreorderIterator(IBinaryTreeNodePtr<TKey, TValue> root) :
            m_root(root)
        {
            reset();
        }

        /**
         * The BinaryTreePreorderIterator destructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreePreorderIterator<TKey, TValue>::~BinaryTreePreorderIterator()
        {
        }

        /**
         * Checks whether there is a next element.
         */
        template <typename TKey, typename TValue>
        bool BinaryTreePreorderIterator<TKey, TValue>::hasNext() const
        {
            return !m_stack->empty();
        }

        /**
         * Gets the next element.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeNodePtr<TKey, TValue> BinaryTreePreorderIterator<TKey, TValue>::next()
        {
            assert(hasNext());

            IBinaryTreeNodePtr<TKey, TValue> currNode = m_stack->top();
            m_stack->pop();

            if (currNode->hasRightChild())
            {
                m_stack->push(currNode->getRightChild());
            }

            if (currNode->hasLeftChild())
            {
                m_stack->push(currNode->getLeftChild());
            }

            return currNode;
        }

        /**
         * Resets the iterator.
         */
        template <typename TKey, typename TValue>
        void BinaryTreePreorderIterator<TKey, TValue>::reset()
        {
            m_stack = std::make_unique<std::stack<IBinaryTreeNodePtr<TKey, TValue>>>();

            if (m_root.get() != nullptr)
            {
                m_stack->push(m_root);
            }
        }
    }
}

#endif // BINARY_TREE_PREORDER_ITERATOR_H_01e217c9_6926_41eb_b00f_e1525f8050ba
