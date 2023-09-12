#ifndef DOUBLY_LINKED_LIST_NODE_VALUE_ITERATOR_H_911c2466_2627_493f_8375_b05ca6ccdff9
#define DOUBLY_LINKED_LIST_NODE_VALUE_ITERATOR_H_911c2466_2627_493f_8375_b05ca6ccdff9

#include "IIterator.h"
#include "DoublyLinkedListNode.h"
#include "DoublyLinkedListException.h"
#include "SmartPointers.h"

namespace datastructures {
    namespace doublylinkedlist {

        /**
         * The DoublyLinkedListNodeValueIterator class implements an iterator of values of a doubly linked list.
         */
        template <typename T>
        class DoublyLinkedListNodeValueIterator final : public base::IIterator<T>
        {
        public:
            /**
             * Creates a new iterator of values of a doubly linked list.
             */
            static base::IIteratorSharedPtr<T> make(base::IIteratorSharedPtr<IDoublyLinkedListNodePtr<T>> iterator);

            /**
             * The DoublyLinkedListNodeValueIterator constructor.
             */
            explicit DoublyLinkedListNodeValueIterator(base::IIteratorSharedPtr<IDoublyLinkedListNodePtr<T>> iterator);

            /**
             * The DoublyLinkedListNodeValueIterator destructor.
             */
            virtual ~DoublyLinkedListNodeValueIterator();

            /**
             * The copy/move constructors.
             */
            DoublyLinkedListNodeValueIterator(const DoublyLinkedListNodeValueIterator&) = delete;
            DoublyLinkedListNodeValueIterator(DoublyLinkedListNodeValueIterator&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            DoublyLinkedListNodeValueIterator& operator=(const DoublyLinkedListNodeValueIterator&) = delete;
            DoublyLinkedListNodeValueIterator& operator=(DoublyLinkedListNodeValueIterator&&) = delete;

            /**
             * Checks whether there is a next node.
             */
            virtual bool hasNext() const override;

            /**
             * Gets the next node.
             */
            virtual T next() override;

            /**
             * Resets the iterator.
             */
            virtual void reset() override;

        private:
            base::IIteratorSharedPtr<IDoublyLinkedListNodePtr<T>> m_iterator;
        };

        /**
         * Creates a new iterator of values of a doubly linked list.
         */
        template <typename T>
        base::IIteratorSharedPtr<T> DoublyLinkedListNodeValueIterator<T>::make(base::IIteratorSharedPtr<IDoublyLinkedListNodePtr<T>> iterator)
        {
            return std::make_shared<DoublyLinkedListNodeValueIterator<T>>(iterator);
        }

        /**
         * The DoublyLinkedListNodeValueIterator constructor.
         */
        template <typename T>
        DoublyLinkedListNodeValueIterator<T>::DoublyLinkedListNodeValueIterator(base::IIteratorSharedPtr<IDoublyLinkedListNodePtr<T>> iterator) :
            m_iterator(iterator)
        {
            base::SmartPointers::validate(iterator);
            reset();
        }

        /**
         * The DoublyLinkedListNodeValueIterator destructor.
         */
        template <typename T>
        DoublyLinkedListNodeValueIterator<T>::~DoublyLinkedListNodeValueIterator()
        {
        }

        /**
         * Checks whether there is a next node.
         */
        template <typename T>
        bool DoublyLinkedListNodeValueIterator<T>::hasNext() const
        {
            return m_iterator->hasNext();
        }

        /**
         * Gets the next node.
         */
        template <typename T>
        T DoublyLinkedListNodeValueIterator<T>::next()
        {
            assert(hasNext());

            return m_iterator->next()->getValue();
        }

        /**
         * Resets the iterator.
         */
        template <typename T>
        void DoublyLinkedListNodeValueIterator<T>::reset()
        {
            m_iterator->reset();
        }
    }
}

#endif // DOUBLY_LINKED_LIST_NODE_VALUE_ITERATOR_H_911c2466_2627_493f_8375_b05ca6ccdff9
