#ifndef DOUBLY_LINKED_LIST_KEY_VALUE_NODE_ITERATOR_H_faba3c70_3098_4892_8d77_eb38e4eb6636
#define DOUBLY_LINKED_LIST_KEY_VALUE_NODE_ITERATOR_H_faba3c70_3098_4892_8d77_eb38e4eb6636

#include "IIterator.h"
#include "IKeyValueNode.h"
#include "IDoublyLinkedListNode.h"
#include "SmartPointers.h"

namespace datastructures {
    namespace doublylinkedlist {

        /**
         * The DoublyLinkedListKeyValueNodeIterator class implements an iterator of key-value nodes of a doubly linked list.
         */
        template <typename TKey, typename TValue>
        class DoublyLinkedListKeyValueNodeIterator final : public base::IIterator<node::IKeyValueNodeSharedPtr<TKey, TValue>>
        {
        public:
            /**
             * Creates a new doubly linked list.
             */
            static base::IIteratorSharedPtr<node::IKeyValueNodeSharedPtr<TKey, TValue>> Make(
                base::IIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr < TKey, TValue>>> iterator);

            /**
             * The DoublyLinkedListKeyValueNodeIterator constructor.
             */
            explicit DoublyLinkedListKeyValueNodeIterator(
                base::IIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr < TKey, TValue>>> iterator);

            /**
             * The DoublyLinkedListKeyValueNodeIterator destructor.
             */
            virtual ~DoublyLinkedListKeyValueNodeIterator();

            /**
             * The Copy/move constructors.
             */
            DoublyLinkedListKeyValueNodeIterator(const DoublyLinkedListKeyValueNodeIterator&) = delete;
            DoublyLinkedListKeyValueNodeIterator(DoublyLinkedListKeyValueNodeIterator&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            DoublyLinkedListKeyValueNodeIterator&operator=(const DoublyLinkedListKeyValueNodeIterator&) = delete;
            DoublyLinkedListKeyValueNodeIterator&operator=(DoublyLinkedListKeyValueNodeIterator&&) = delete;

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
            base::IIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr < TKey, TValue>>> m_iterator;
        };

        /**
         * Creates a new doubly linked list.
         */
        template <typename TKey, typename TValue>
        base::IIteratorSharedPtr<node::IKeyValueNodeSharedPtr<TKey, TValue>> DoublyLinkedListKeyValueNodeIterator<TKey, TValue>::Make(
            base::IIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr < TKey, TValue>>> iterator)
        {
            return std::make_shared<DoublyLinkedListKeyValueNodeIterator<TKey, TValue>>(iterator);
        }

        /**
         * The DoublyLinkedListKeyValueNodeIterator constructor.
         */
        template <typename TKey, typename TValue>
        DoublyLinkedListKeyValueNodeIterator<TKey, TValue>::DoublyLinkedListKeyValueNodeIterator(
            base::IIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>>> iterator) :
            m_iterator(iterator)
        {
            base::SmartPointers::validate<base::IIterator<IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>>>>(iterator);

            Reset();
        }

        /**
         * The DoublyLinkedListKeyValueNodeIterator destructor.
         */
        template <typename TKey, typename TValue>
        DoublyLinkedListKeyValueNodeIterator<TKey, TValue>::~DoublyLinkedListKeyValueNodeIterator()
        {
        }

        /**
         * Checks whether there is a Next node.
         */
        template <typename TKey, typename TValue>
        bool DoublyLinkedListKeyValueNodeIterator<TKey, TValue>::HasNext() const
        {
            return m_iterator->HasNext();
        }

        /**
         * Gets the Next node.
         */
        template <typename TKey, typename TValue>
        node::IKeyValueNodeSharedPtr<TKey, TValue> DoublyLinkedListKeyValueNodeIterator<TKey, TValue>::Next()
        {
            assert(HasNext());

            IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> listNode = m_iterator->Next();
            node::IKeyValueNodeSharedPtr<TKey, TValue> node = listNode->GetValue();

            return node;
        }

        /**
         * Resets the iterator.
         */
        template <typename TKey, typename TValue>
        void DoublyLinkedListKeyValueNodeIterator<TKey, TValue>::Reset()
        {
            m_iterator->Reset();
        }
    }
}

#endif // DOUBLY_LINKED_LIST_KEY_VALUE_NODE_ITERATOR_H_faba3c70_3098_4892_8d77_eb38e4eb6636
