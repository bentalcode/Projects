#ifndef BINARY_TREE_POSTORDER_ITERATOR_H_5c47c002_0316_4b8b_be6a_3be3eb4a0e01
#define BINARY_TREE_POSTORDER_ITERATOR_H_5c47c002_0316_4b8b_be6a_3be3eb4a0e01

#include "IIterator.h"
#include "IBinaryTreeNode.h"

namespace datastructures {
    namespace binarytree {

        /**
         * The BinaryTreePostorderIterator class implements an preorder iterator of a binary tree.
         */
        template <typename TKey, typename TValue>
        class BinaryTreePostorderIterator : public base::IIterator<IBinaryTreeNodeSharedPtr<TKey, TValue>>
        {
        public:
            /**
             * Creates a preorder iterator of a binary tree.
             */
            static base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> Make(IBinaryTreeNodeSharedPtr<TKey, TValue> root);

            /**
             * The BinaryTreePostorderIterator constructor.
             */
            explicit BinaryTreePostorderIterator(IBinaryTreeNodeSharedPtr<TKey, TValue> root);

            /**
             * The destructor.
             */
            virtual ~BinaryTreePostorderIterator();

            /**
             * The Copy/move constructors.
             */
            BinaryTreePostorderIterator(const BinaryTreePostorderIterator&) = delete;
            BinaryTreePostorderIterator(BinaryTreePostorderIterator&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            BinaryTreePostorderIterator& operator=(const BinaryTreePostorderIterator&) = delete;
            BinaryTreePostorderIterator& operator=(BinaryTreePostorderIterator&&) = delete;

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
            /**
             * Moves to the minimum node.
             */
            void moveToMinimumNode(IBinaryTreeNodeSharedPtr<TKey, TValue> node);

            IBinaryTreeNodeSharedPtr<TKey, TValue> m_root;
            std::unique_ptr<std::stack<IBinaryTreeNodeSharedPtr<TKey, TValue>>> m_stack;
        };

        /**
         * Creates a preorder iterator of a binary tree.
         */
        template <typename TKey, typename TValue>
        base::IIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> BinaryTreePostorderIterator<TKey, TValue>::Make(IBinaryTreeNodeSharedPtr<TKey, TValue> root)
        {
            return std::make_shared<BinaryTreePostorderIterator<TKey, TValue>>(root);
        }

        /**
         * The BinaryTreePostorderIterator constructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreePostorderIterator<TKey, TValue>::BinaryTreePostorderIterator(IBinaryTreeNodeSharedPtr<TKey, TValue> root) :
            m_root(root)
        {
            Reset();
        }

        /**
         * The BinaryTreePostorderIterator destructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreePostorderIterator<TKey, TValue>::~BinaryTreePostorderIterator()
        {
        }

        /**
         * Checks whether there is a Next element.
         */
        template <typename TKey, typename TValue>
        bool BinaryTreePostorderIterator<TKey, TValue>::HasNext() const
        {
            return !m_stack->empty();
        }

        /**
         * Gets the Next element.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeNodeSharedPtr<TKey, TValue> BinaryTreePostorderIterator<TKey, TValue>::Next()
        {
            assert(HasNext());

            IBinaryTreeNodeSharedPtr<TKey, TValue> currNode = nullptr;

            while (true)
            {
                currNode = m_stack->top();
                m_stack->pop();

                if (currNode->HasRightChild() &&
                    !m_stack->empty() && currNode->GetRightChild() == m_stack->top())
                {
                    IBinaryTreeNodeSharedPtr<TKey, TValue> nextNode = m_stack->top();
                    m_stack->pop();

                    m_stack->push(currNode);
                    moveToMinimumNode(nextNode);
                }
                else
                {
                    break;
                }
            }

            return currNode;
        }

        /**
         * Resets the iterator.
         */
        template <typename TKey, typename TValue>
        void BinaryTreePostorderIterator<TKey, TValue>::Reset()
        {
            m_stack = std::make_unique<std::stack<IBinaryTreeNodeSharedPtr<TKey, TValue>>>();
            moveToMinimumNode(m_root);
        }

        /**
         * Moves to the minimum node.
         */
        template <typename TKey, typename TValue>
        void BinaryTreePostorderIterator<TKey, TValue>::moveToMinimumNode(IBinaryTreeNodeSharedPtr<TKey, TValue> node)
        {
            IBinaryTreeNodeSharedPtr<TKey, TValue> currNode = node;

            while (currNode.get() != nullptr)
            {
                if (currNode->HasRightChild())
                {
                    m_stack->push(currNode->GetRightChild());
                }

                m_stack->push(currNode);

                currNode = currNode->GetLeftChild();
            }
        }
    }
}

#endif // BINARY_TREE_POSTORDER_ITERATOR_H_5c47c002_0316_4b8b_be6a_3be3eb4a0e01
