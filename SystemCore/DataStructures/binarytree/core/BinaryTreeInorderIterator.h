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
        class BinaryTreeInorderIterator : public base::IIterator<IBinaryTreeNodeSharedPtr<TKey, TValue>>
        {
        public:
            /**
             * Creates an inorder iterator of a binary tree.
             */
            static base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> make(IBinaryTreeNodeSharedPtr<TKey, TValue> root);

            /**
             * The BinaryTreeInorderIterator constructor.
             */
            explicit BinaryTreeInorderIterator(IBinaryTreeNodeSharedPtr<TKey, TValue> root);

            /**
             * The destructor.
             */
            virtual ~BinaryTreeInorderIterator();

            /**
             * The Copy/move constructors.
             */
            BinaryTreeInorderIterator(const BinaryTreeInorderIterator&) = delete;
            BinaryTreeInorderIterator(BinaryTreeInorderIterator&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            BinaryTreeInorderIterator& operator=(const BinaryTreeInorderIterator&) = delete;
            BinaryTreeInorderIterator& operator=(BinaryTreeInorderIterator&&) = delete;

            /**
             * Checks whether there is a Next element.
             */
            virtual bool hasNext() const;

            /**
             * Gets the Next element.
             */
            virtual IBinaryTreeNodeSharedPtr<TKey, TValue> next();

            /**
             * Resets the iterator.
             */
            virtual void reset();

        private:
            IBinaryTreeNodeSharedPtr<TKey, TValue> m_root;
            std::unique_ptr<std::stack<IBinaryTreeNodeSharedPtr<TKey, TValue>>> m_stack;
            BinaryTreeLogic<TKey, TValue> m_logic;
        };

        /**
         * Creates an inorder iterator of a binary tree.
         */
        template <typename TKey, typename TValue>
        base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> BinaryTreeInorderIterator<TKey, TValue>::make(
                IBinaryTreeNodeSharedPtr<TKey, TValue> root)
        {
            return std::make_shared<BinaryTreeInorderIterator<TKey, TValue>>(root);
        }

        /**
         * The BinaryTreeInorderIterator constructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreeInorderIterator<TKey, TValue>::BinaryTreeInorderIterator(IBinaryTreeNodeSharedPtr<TKey, TValue> root) :
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
         * Checks whether there is a Next element.
         */
        template <typename TKey, typename TValue>
        bool BinaryTreeInorderIterator<TKey, TValue>::hasNext() const
        {
            return !m_stack->Empty();
        }

        /**
         * Gets the Next element.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeNodeSharedPtr<TKey, TValue> BinaryTreeInorderIterator<TKey, TValue>::next()
        {
            assert(hasNext());
            IBinaryTreeNodeSharedPtr<TKey, TValue> currNode = m_stack->top();
            m_stack->pop();

            if (currNode->HasRightChild())
            {
                m_logic.moveMinimumNode(currNode->GetRightChild(), *m_stack);
            }

            return currNode;
        }

        /**
         * Resets the iterator.
         */
        template <typename TKey, typename TValue>
        void BinaryTreeInorderIterator<TKey, TValue>::reset()
        {
            m_stack = std::make_unique<std::stack<IBinaryTreeNodeSharedPtr<TKey, TValue>>>();

            if (m_root.get() != nullptr)
            {
                m_logic.moveMinimumNode(m_root, *m_stack);
            }
        }
    }
}

#endif // BINARY_TREE_INORDER_ITERATOR_H_7f882b03_4f7c_4f81_b471_b5958705febf
