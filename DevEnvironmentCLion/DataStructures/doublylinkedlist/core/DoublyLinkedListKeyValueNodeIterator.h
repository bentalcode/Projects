#ifndef DOUBLY_LINKED_LIST_KEY_VALUE_NODE_ITERATOR_H_faba3c70_3098_4892_8d77_eb38e4eb6636
#define DOUBLY_LINKED_LIST_KEY_VALUE_NODE_ITERATOR_H_faba3c70_3098_4892_8d77_eb38e4eb6636

#include "IIterator.h"
#include "IKeyValueNode.h"
#include "IDoublyLinkedListNode.h"
#include "DoublyLinkedListException.h"
#include "CacheException.h"

namespace datastructures {
    namespace doublylinkedlist {

        /**
         * The DoublyLinkedListKeyValueNodeIterator class implements an iterator of key-value nodes of a doubly linked list.
         */
        template <typename TKey, typename TValue>
        class DoublyLinkedListKeyValueNodeIterator final : public base::IIterator<node::IKeyValueNodePtr<TKey, TValue>>
        {
        public:
            /**
             * Creates a new doubly linked list.
             */
            static base::IIteratorPtr<node::IKeyValueNodePtr<TKey, TValue>> make(
                base::IIteratorPtr<IDoublyLinkedListNodePtr<IKeyValueNodePtr<TKey, TValue>>> iterator);

            /**
             * The DoublyLinkedListKeyValueNodeIterator constructor.
             */
            explicit DoublyLinkedListKeyValueNodeIterator(
                base::IIteratorPtr<IDoublyLinkedListNodePtr<IKeyValueNodePtr<TKey, TValue>>> iterator);

            /**
             * The DoublyLinkedListKeyValueNodeIterator destructor.
             */
            virtual ~DoublyLinkedListKeyValueNodeIterator();

            /**
             * The copy/move constructors.
             */
            DoublyLinkedListKeyValueNodeIterator(const DoublyLinkedListKeyValueNodeIterator&) = delete;
            DoublyLinkedListKeyValueNodeIterator(DoublyLinkedListKeyValueNodeIterator&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            DoublyLinkedListKeyValueNodeIterator&operator=(const DoublyLinkedListKeyValueNodeIterator&) = delete;
            DoublyLinkedListKeyValueNodeIterator&operator=(DoublyLinkedListKeyValueNodeIterator&&) = delete;

            /**
             * Checks whether there is a next node.
             */
            virtual bool hasNext() const override;

            /**
             * Gets the next node.
             */
            virtual node::IKeyValueNodePtr<TKey, TValue> next() override;

            /**
             * Resets the iterator.
             */
            virtual void reset() override;

        private:
            base::IIteratorPtr<IDoublyLinkedListNodePtr<IKeyValueNodePtr<TKey, TValue>>> m_iterator;
        };

        /**
         * Creates a new doubly linked list.
         */
        template <typename TKey, typename TValue>
        base::IIteratorPtr<node::IKeyValueNodePtr<TKey, TValue>> DoublyLinkedListKeyValueNodeIterator<TKey, TValue>::make(
            base::IIteratorPtr<IDoublyLinkedListNodePtr<IKeyValueNodePtr<TKey, TValue>>> iterator)
        {
            return std::make_shared<DoublyLinkedListKeyValueNodeIterator<TKey, TValue>>(iterator);
        }

        /**
         * The DoublyLinkedListKeyValueNodeIterator constructor.
         */
        template <typename TKey, typename TValue>
        DoublyLinkedListKeyValueNodeIterator<TKey, TValue>::DoublyLinkedListKeyValueNodeIterator(
            base::IIteratorPtr<IDoublyLinkedListNodePtr<IKeyValueNodePtr<TKey, TValue>>> iterator) :
            m_iterator(iterator)
        {
            if (!iterator)
            {
                std::string errorMessage =
                    "The iterator of a doubly linked list node of a key-value nodes is not defined.";

                throw CacheException(errorMessage);
            }

            reset();
        }

        /**
         * The DoublyLinkedListKeyValueNodeIterator destructor.
         */
        template <typename TKey, typename TValue>
        DoublyLinkedListKeyValueNodeIterator<TKey, TValue>::~DoublyLinkedListKeyValueNodeIterator()
        {
        }

        /**
         * Checks whether there is a next node.
         */
        template <typename TKey, typename TValue>
        bool DoublyLinkedListKeyValueNodeIterator<TKey, TValue>::hasNext() const
        {
            return m_iterator->hasNext();
        }

        /**
         * Gets the next node.
         */
        template <typename TKey, typename TValue>
        node::IKeyValueNodePtr<TKey, TValue> DoublyLinkedListKeyValueNodeIterator<TKey, TValue>::next()
        {
            assert(hasNext());

            IDoublyLinkedListNodePtr<IKeyValueNodePtr<TKey, TValue>> listNode = m_iterator->next();
            node::IKeyValueNodePtr<TKey, TValue> node = listNode->getValue();

            return node;
        }

        /**
         * Resets the iterator.
         */
        template <typename TKey, typename TValue>
        void DoublyLinkedListKeyValueNodeIterator<TKey, TValue>::reset()
        {
            m_iterator->reset();
        }
    }
}

#endif // DOUBLY_LINKED_LIST_KEY_VALUE_NODE_ITERATOR_H_faba3c70_3098_4892_8d77_eb38e4eb6636
