#ifndef BINARY_TREE_INORDER_ITERATOR_H_7f882b03_4f7c_4f81_b471_b5958705febf
#define BINARY_TREE_INORDER_ITERATOR_H_7f882b03_4f7c_4f81_b471_b5958705febf

#include "IIterator.h"
#include "IBinaryTreeNode.h"
#include "BinaryTreeLogic.h"

namespace datastructures {
    namespace binarytree {

        /**
         * The BinaryTreeInorderIterator class implements an inorder iterator of a binary tree.
         */
        template <typename TKey, typename TValue>
        class BinaryTreeInorderIterator : public base::IIterator<IBinaryTreeNodePtr<TKey, TValue>>
        {
        public:
            /**
             * Creates an inorder iterator of a binary tree.
             */
            static base::IIteratorSharedPtr<IBinaryTreeNodePtr<TKey, TValue>> make(IBinaryTreeNodePtr<TKey, TValue> root);

            /**
             * The BinaryTreeInorderIterator constructor.
             */
            explicit BinaryTreeInorderIterator(IBinaryTreeNodePtr<TKey, TValue> root);

            /**
             * The destructor.
             */
            virtual ~BinaryTreeInorderIterator();

            /**
             * The copy/move constructors.
             */
            BinaryTreeInorderIterator(const BinaryTreeInorderIterator&) = delete;
            BinaryTreeInorderIterator(BinaryTreeInorderIterator&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            BinaryTreeInorderIterator& operator=(const BinaryTreeInorderIterator&) = delete;
            BinaryTreeInorderIterator& operator=(BinaryTreeInorderIterator&&) = delete;

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
         * Creates an inorder iterator of a binary tree.
         */
        template <typename TKey, typename TValue>
        base::IIteratorSharedPtr<IBinaryTreeNodePtr<TKey, TValue>> BinaryTreeInorderIterator<TKey, TValue>::make(
            IBinaryTreeNodePtr<TKey, TValue> root)
        {
            return std::make_shared<BinaryTreeInorderIterator<TKey, TValue>>(root);
        }

        /**
         * The BinaryTreeInorderIterator constructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreeInorderIterator<TKey, TValue>::BinaryTreeInorderIterator(IBinaryTreeNodePtr<TKey, TValue> root) :
            m_root(root)
        {
            reset();
        }

        /**
         * The BinaryTreeInorderIterator destructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreeInorderIterator<TKey, TValue>::~BinaryTreeInorderIterator()
        {
        }

        /**
         * Checks whether there is a next element.
         */
        template <typename TKey, typename TValue>
        bool BinaryTreeInorderIterator<TKey, TValue>::hasNext() const
        {
            return !m_stack->empty();
        }

        /**
         * Gets the next element.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeNodePtr<TKey, TValue> BinaryTreeInorderIterator<TKey, TValue>::next()
        {
            assert(hasNext());
            IBinaryTreeNodePtr<TKey, TValue> currNode = m_stack->top();
            m_stack->pop();

            if (currNode->hasRightChild())
            {
                m_logic.moveMinimumNode(currNode->getRightChild(), *m_stack);
            }

            return currNode;
        }

        /**
         * Resets the iterator.
         */
        template <typename TKey, typename TValue>
        void BinaryTreeInorderIterator<TKey, TValue>::reset()
        {
            m_stack = std::make_unique<std::stack<IBinaryTreeNodePtr<TKey, TValue>>>();

            if (m_root.get() != nullptr)
            {
                m_logic.moveMinimumNode(m_root, *m_stack);
            }
        }
    }
}

#endif // BINARY_TREE_INORDER_ITERATOR_H_7f882b03_4f7c_4f81_b471_b5958705febf
