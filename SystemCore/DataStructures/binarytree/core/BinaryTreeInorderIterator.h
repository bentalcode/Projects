#ifndef BINARY_TREE_INORDER_ITERATOR_H_7f882b03_4f7c_4f81_b471_b5958705febf
#define BINARY_TREE_INORDER_ITERATOR_H_7f882b03_4f7c_4f81_b471_b5958705febf

#include "IIterator.h"
#include "IBinaryTreeNode.h"
#include "BinaryTreeLogic.h"
#include <stack>

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
            static base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> Make(IBinaryTreeNodeSharedPtr<TKey, TValue> root);

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
         * Creates an inorder iterator of a binary tree.
         */
        template <typename TKey, typename TValue>
        base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> BinaryTreeInorderIterator<TKey, TValue>::Make(
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
            Reset();
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
        bool BinaryTreeInorderIterator<TKey, TValue>::HasNext() const
        {
            return !m_stack->empty();
        }

        /**
         * Gets the next element.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeNodeSharedPtr<TKey, TValue> BinaryTreeInorderIterator<TKey, TValue>::Next()
        {
            assert(HasNext());
            IBinaryTreeNodeSharedPtr<TKey, TValue> currNode = m_stack->top();
            m_stack->pop();

            if (currNode->HasRightChild())
            {
                m_logic.MoveMinimumNode(currNode->GetRightChild(), *m_stack);
            }

            return currNode;
        }

        /**
         * Resets the iterator.
         */
        template <typename TKey, typename TValue>
        void BinaryTreeInorderIterator<TKey, TValue>::Reset()
        {
            m_stack = std::make_unique<std::stack<IBinaryTreeNodeSharedPtr<TKey, TValue>>>();

            if (m_root.get() != nullptr)
            {
                m_logic.MoveMinimumNode(m_root, *m_stack);
            }
        }
    }
}

#endif // BINARY_TREE_INORDER_ITERATOR_H_7f882b03_4f7c_4f81_b471_b5958705febf
