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
            static base::IIteratorSharedPtr<T> Make(base::IIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<T>> iterator);

            /**
             * The DoublyLinkedListNodeValueIterator constructor.
             */
            explicit DoublyLinkedListNodeValueIterator(base::IIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<T>> iterator);

            /**
             * The DoublyLinkedListNodeValueIterator destructor.
             */
            virtual ~DoublyLinkedListNodeValueIterator();

            /**
             * The Copy/move constructors.
             */
            DoublyLinkedListNodeValueIterator(const DoublyLinkedListNodeValueIterator&) = delete;
            DoublyLinkedListNodeValueIterator(DoublyLinkedListNodeValueIterator&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            DoublyLinkedListNodeValueIterator& operator=(const DoublyLinkedListNodeValueIterator&) = delete;
            DoublyLinkedListNodeValueIterator& operator=(DoublyLinkedListNodeValueIterator&&) = delete;

            /**
             * Checks whether there is a Next node.
             */
            virtual bool HasNext() const override;

            /**
             * Gets the Next node.
             */
            virtual T Next() override;

            /**
             * Resets the iterator.
             */
            virtual void Reset() override;

        private:
            base::IIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<T>> m_iterator;
        };

        /**
         * Creates a new iterator of values of a doubly linked list.
         */
        template <typename T>
        base::IIteratorSharedPtr<T> DoublyLinkedListNodeValueIterator<T>::Make(base::IIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<T>> iterator)
        {
            return std::make_shared<DoublyLinkedListNodeValueIterator<T>>(iterator);
        }

        /**
         * The DoublyLinkedListNodeValueIterator constructor.
         */
        template <typename T>
        DoublyLinkedListNodeValueIterator<T>::DoublyLinkedListNodeValueIterator(base::IIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<T>> iterator) :
            m_iterator(iterator)
        {
            base::SmartPointers::Validate<base::IIterator<IDoublyLinkedListNodeSharedPtr<T>>>(iterator);
            Reset();
        }

        /**
         * The DoublyLinkedListNodeValueIterator destructor.
         */
        template <typename T>
        DoublyLinkedListNodeValueIterator<T>::~DoublyLinkedListNodeValueIterator()
        {
        }

        /**
         * Checks whether there is a Next node.
         */
        template <typename T>
        bool DoublyLinkedListNodeValueIterator<T>::HasNext() const
        {
            return m_iterator->HasNext();
        }

        /**
         * Gets the Next node.
         */
        template <typename T>
        T DoublyLinkedListNodeValueIterator<T>::Next()
        {
            assert(HasNext());

            return m_iterator->Next()->GetValue();
        }

        /**
         * Resets the iterator.
         */
        template <typename T>
        void DoublyLinkedListNodeValueIterator<T>::Reset()
        {
            m_iterator->Reset();
        }
    }
}

#endif // DOUBLY_LINKED_LIST_NODE_VALUE_ITERATOR_H_911c2466_2627_493f_8375_b05ca6ccdff9
