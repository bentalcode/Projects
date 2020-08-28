#ifndef BINARY_TREE_POSTORDER_ITERATOR_H_5c47c002_0316_4b8b_be6a_3be3eb4a0e01
#define BINARY_TREE_POSTORDER_ITERATOR_H_5c47c002_0316_4b8b_be6a_3be3eb4a0e01

#include "IIterator.h"
#include "IBinaryTreeNode.h"

namespace datastructures {
    namespace binarytree {

        /**
         * The BinaryTreePostorderIterator class implements an preorder iterator of a binary tree.
         */
        template<typename TKey, typename TValue>
        class BinaryTreePostorderIterator : public base::IIterator<IBinaryTreeNodePtr<TKey, TValue>>
        {
        public:
            /**
             * Creates a preorder iterator of a binary tree.
             */
            static base::IIteratorPtr<IBinaryTreeNodePtr<TKey, TValue>> make(IBinaryTreeNodePtr<TKey, TValue> root);

            /**
             * The BinaryTreePostorderIterator constructor.
             */
            explicit BinaryTreePostorderIterator(IBinaryTreeNodePtr<TKey, TValue> root);

            /**
             * The destructor.
             */
            virtual ~BinaryTreePostorderIterator();

            /**
             * The copy/move constructors.
             */
            BinaryTreePostorderIterator(const BinaryTreePostorderIterator&) = delete;
            BinaryTreePostorderIterator(BinaryTreePostorderIterator&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            BinaryTreePostorderIterator& operator=(const BinaryTreePostorderIterator&) = delete;
            BinaryTreePostorderIterator& operator=(BinaryTreePostorderIterator&&) = delete;

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
            /**
             * Moves to the minimum node.
             */
            void moveToMinimumNode(IBinaryTreeNodePtr<TKey, TValue> node);

            IBinaryTreeNodePtr<TKey, TValue> m_root;
            std::unique_ptr<std::stack<IBinaryTreeNodePtr<TKey, TValue>>> m_stack;
        };

        /**
         * Creates a preorder iterator of a binary tree.
         */
        template <typename TKey, typename TValue>
        base::IIteratorPtr<IBinaryTreeNodePtr<TKey, TValue>> BinaryTreePostorderIterator<TKey, TValue>::make(IBinaryTreeNodePtr<TKey, TValue> root)
        {
            return std::make_shared<BinaryTreePostorderIterator<TKey, TValue>>(root);
        }

        /**
         * The BinaryTreePostorderIterator constructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreePostorderIterator<TKey, TValue>::BinaryTreePostorderIterator(IBinaryTreeNodePtr<TKey, TValue> root) :
            m_root(root)
        {
            reset();
        }

        /**
         * The BinaryTreePostorderIterator destructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreePostorderIterator<TKey, TValue>::~BinaryTreePostorderIterator()
        {
        }

        /**
         * Checks whether there is a next element.
         */
        template <typename TKey, typename TValue>
        bool BinaryTreePostorderIterator<TKey, TValue>::hasNext() const
        {
            return !m_stack->empty();
        }

        /**
         * Gets the next element.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeNodePtr<TKey, TValue> BinaryTreePostorderIterator<TKey, TValue>::next()
        {
            assert(hasNext());

            IBinaryTreeNodePtr<TKey, TValue> currNode = nullptr;

            while (true)
            {
                currNode = m_stack->top();
                m_stack->pop();

                if (currNode->hasRightChild() &&
                    !m_stack->empty() && currNode->getRightChild() == m_stack->top())
                {
                    IBinaryTreeNodePtr<TKey, TValue> nextNode = m_stack->top();
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
        void BinaryTreePostorderIterator<TKey, TValue>::reset()
        {
            m_stack = std::make_unique<std::stack<IBinaryTreeNodePtr<TKey, TValue>>>();
            moveToMinimumNode(m_root);
        }

        /**
         * Moves to the minimum node.
         */
        template <typename TKey, typename TValue>
        void BinaryTreePostorderIterator<TKey, TValue>::moveToMinimumNode(IBinaryTreeNodePtr<TKey, TValue> node)
        {
            IBinaryTreeNodePtr<TKey, TValue> currNode = node;

            while (currNode.get() != nullptr)
            {
                if (currNode->hasRightChild())
                {
                    m_stack->push(currNode->getRightChild());
                }

                m_stack->push(currNode);

                currNode = currNode->getLeftChild();
            }
        }
    }
}

#endif // BINARY_TREE_POSTORDER_ITERATOR_H_5c47c002_0316_4b8b_be6a_3be3eb4a0e01
