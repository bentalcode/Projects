#ifndef DOUBLY_LINKED_LIST_KEY_VALUE_NODE_REVERSE_ITERATOR_H_4cf5ab34_86b0_4c3a_a201_d7bae0f1f108
#define DOUBLY_LINKED_LIST_KEY_VALUE_NODE_REVERSE_ITERATOR_H_4cf5ab34_86b0_4c3a_a201_d7bae0f1f108

#include "IReverseIterator.h"
#include "IKeyValueNode.h"
#include "IDoublyLinkedListNode.h"
#include "SmartPointers.h"

namespace datastructures {
    namespace doublylinkedlist {

        /**
         * The DoublyLinkedListKeyValueNodeReverseIterator class implements a reverse iterator Of
         * key-value nodes of a doubly linked list.
         */
        template <typename TKey, typename TValue>
        class DoublyLinkedListKeyValueNodeReverseIterator final : public base::IReverseIterator<node::IKeyValueNodeSharedPtr<TKey, TValue>>
        {
        public:
            /**
             * Creates a new reverse iterator of a key-value node.
             */
            static base::IReverseIteratorSharedPtr<node::IKeyValueNodeSharedPtr<TKey, TValue>> Make(
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
             * The Copy/move constructors.
             */
            DoublyLinkedListKeyValueNodeReverseIterator(const DoublyLinkedListKeyValueNodeReverseIterator&) = delete;
            DoublyLinkedListKeyValueNodeReverseIterator(DoublyLinkedListKeyValueNodeReverseIterator&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            DoublyLinkedListKeyValueNodeReverseIterator& operator=(const DoublyLinkedListKeyValueNodeReverseIterator&) = delete;
            DoublyLinkedListKeyValueNodeReverseIterator& operator=(DoublyLinkedListKeyValueNodeReverseIterator&&) = delete;

            /**
             * Checks whether there is a Next node.
             */
            virtual bool HasNext() const override;

            /**
             * Gets the Next node.
             */
            virtual node::IKeyValueNodeSharedPtr<TKey, TValue> Next() override;

            /**
             * Resets the iterator.
             */
            virtual void Reset() override;

        private:
            base::IReverseIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr < TKey, TValue>>> m_reverseIterator;
        };

        /**
         * Creates a new reverse iterator of a key-value node.
         */
        template <typename TKey, typename TValue>
        base::IReverseIteratorSharedPtr<node::IKeyValueNodeSharedPtr<TKey, TValue>> DoublyLinkedListKeyValueNodeReverseIterator<TKey, TValue>::Make(
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
            base::SmartPointers::Validate<base::IReverseIterator<IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>>>>(reverseIterator);

            Reset();
        }

        /**
         * The DoublyLinkedListKeyValueNodeReverseIterator destructor.
         */
        template <typename TKey, typename TValue>
        DoublyLinkedListKeyValueNodeReverseIterator<TKey, TValue>::~DoublyLinkedListKeyValueNodeReverseIterator()
        {
        }

        /**
         * Checks whether there is a Next node.
         */
        template <typename TKey, typename TValue>
        bool DoublyLinkedListKeyValueNodeReverseIterator<TKey, TValue>::HasNext() const
        {
            return m_reverseIterator->HasNext();
        }

        /**
         * Gets the Next node.
         */
        template <typename TKey, typename TValue>
        node::IKeyValueNodeSharedPtr<TKey, TValue> DoublyLinkedListKeyValueNodeReverseIterator<TKey, TValue>::Next()
        {
            assert(HasNext());

            IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> listNode = m_reverseIterator->Next();
            node::IKeyValueNodeSharedPtr<TKey, TValue> node = listNode->GetValue();

            return node;
        }

        /**
         * Resets the iterator.
         */
        template <typename TKey, typename TValue>
        void DoublyLinkedListKeyValueNodeReverseIterator<TKey, TValue>::Reset()
        {
            m_reverseIterator->Reset();
        }
    }
}

#endif // DOUBLY_LINKED_LIST_KEY_VALUE_NODE_REVERSE_ITERATOR_H_4cf5ab34_86b0_4c3a_a201_d7bae0f1f108
