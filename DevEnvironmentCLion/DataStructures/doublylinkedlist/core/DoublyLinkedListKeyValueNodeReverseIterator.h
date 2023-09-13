#ifndef DOUBLY_LINKED_LIST_KEY_VALUE_NODE_REVERSE_ITERATOR_H_4cf5ab34_86b0_4c3a_a201_d7bae0f1f108
#define DOUBLY_LINKED_LIST_KEY_VALUE_NODE_REVERSE_ITERATOR_H_4cf5ab34_86b0_4c3a_a201_d7bae0f1f108

#include "IReverseIterator.h"
#include "IKeyValueNode.h"
#include "IDoublyLinkedListNode.h"
#include "SmartPointers.h"

namespace datastructures {
    namespace doublylinkedlist {

        /**
         * The DoublyLinkedListKeyValueNodeReverseIterator class implements a reverse iterator of
         * key-value nodes of a doubly linked list.
         */
        template <typename TKey, typename TValue>
        class DoublyLinkedListKeyValueNodeReverseIterator final : public base::IReverseIterator<node::IKeyValueNodeSharedPtr<TKey, TValue>>
        {
        public:
            /**
             * Creates a new reverse iterator of a key-value node.
             */
            static base::IReverseIteratorSharedPtr<node::IKeyValueNodeSharedPtr<TKey, TValue>> make(
                base::IReverseIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr < TKey, TValue>>> reverseIterator);

            /**
             * The DoublyLinkedListKeyValueNodeReverseIterator constructor.
             */
            explicit DoublyLinkedListKeyValueNodeReverseIterator(
                base::IReverseIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr < TKey, TValue>>> reverseIterator);

            /**
             * The DoublyLinkedListKeyValueNodeReverseIterator destructor.
             */
            virtual ~DoublyLinkedListKeyValueNodeReverseIterator();

            /**
             * The copy/move constructors.
             */
            DoublyLinkedListKeyValueNodeReverseIterator(const DoublyLinkedListKeyValueNodeReverseIterator&) = delete;
            DoublyLinkedListKeyValueNodeReverseIterator(DoublyLinkedListKeyValueNodeReverseIterator&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            DoublyLinkedListKeyValueNodeReverseIterator& operator=(const DoublyLinkedListKeyValueNodeReverseIterator&) = delete;
            DoublyLinkedListKeyValueNodeReverseIterator& operator=(DoublyLinkedListKeyValueNodeReverseIterator&&) = delete;

            /**
             * Checks whether there is a next node.
             */
            virtual bool hasNext() const override;

            /**
             * Gets the next node.
             */
            virtual node::IKeyValueNodeSharedPtr<TKey, TValue> next() override;

            /**
             * Resets the iterator.
             */
            virtual void reset() override;

        private:
            base::IReverseIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr < TKey, TValue>>> m_reverseIterator;
        };

        /**
         * Creates a new reverse iterator of a key-value node.
         */
        template <typename TKey, typename TValue>
        base::IReverseIteratorSharedPtr<node::IKeyValueNodeSharedPtr<TKey, TValue>> DoublyLinkedListKeyValueNodeReverseIterator<TKey, TValue>::make(
            base::IReverseIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr < TKey, TValue>>> reverseIterator)
        {
            return std::make_shared<DoublyLinkedListKeyValueNodeReverseIterator<TKey, TValue>>(reverseIterator);
        }

        /**
         * The DoublyLinkedListKeyValueNodeReverseIterator constructor.
         */
        template <typename TKey, typename TValue>
        DoublyLinkedListKeyValueNodeReverseIterator<TKey, TValue>::DoublyLinkedListKeyValueNodeReverseIterator(
            base::IReverseIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>>> reverseIterator) :
            m_reverseIterator(reverseIterator)
        {
            base::SmartPointers::validate(reverseIterator);

            reset();
        }

        /**
         * The DoublyLinkedListKeyValueNodeReverseIterator destructor.
         */
        template <typename TKey, typename TValue>
        DoublyLinkedListKeyValueNodeReverseIterator<TKey, TValue>::~DoublyLinkedListKeyValueNodeReverseIterator()
        {
        }

        /**
         * Checks whether there is a next node.
         */
        template <typename TKey, typename TValue>
        bool DoublyLinkedListKeyValueNodeReverseIterator<TKey, TValue>::hasNext() const
        {
            return m_reverseIterator->hasNext();
        }

        /**
         * Gets the next node.
         */
        template <typename TKey, typename TValue>
        node::IKeyValueNodeSharedPtr<TKey, TValue> DoublyLinkedListKeyValueNodeReverseIterator<TKey, TValue>::next()
        {
            assert(hasNext());

            IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> listNode = m_reverseIterator->next();
            node::IKeyValueNodeSharedPtr<TKey, TValue> node = listNode->getValue();

            return node;
        }

        /**
         * Resets the iterator.
         */
        template <typename TKey, typename TValue>
        void DoublyLinkedListKeyValueNodeReverseIterator<TKey, TValue>::reset()
        {
            m_reverseIterator->reset();
        }
    }
}

#endif // DOUBLY_LINKED_LIST_KEY_VALUE_NODE_REVERSE_ITERATOR_H_4cf5ab34_86b0_4c3a_a201_d7bae0f1f108
