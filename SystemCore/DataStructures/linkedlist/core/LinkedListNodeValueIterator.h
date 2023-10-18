#ifndef LINKED_LIST_NODE_VALUE_ITERATOR_H_6242858f_e9cc_44d6_af3a_6f43955a4019
#define LINKED_LIST_NODE_VALUE_ITERATOR_H_6242858f_e9cc_44d6_af3a_6f43955a4019

#include "IIterator.h"
#include "LinkedListNode.h"

namespace datastructures {
    namespace linkedlist {

        /**
         * The LinkedListNodeValueIterator class implements an iterator of values of a doubly linked list.
         */
        template <typename T>
        class LinkedListNodeValueIterator final : public base::IIterator<T>
        {
        public:
            /**
             * Creates a new iterator of values of a doubly linked list.
             */
            static base::IIteratorSharedPtr<T> Make(base::IIteratorSharedPtr<ILinkedListNodeSharedPtr<T>> iterator);

            /**
             * The LinkedListNodeValueIterator constructor.
             */
            explicit LinkedListNodeValueIterator(base::IIteratorSharedPtr<ILinkedListNodeSharedPtr<T>> iterator);

            /**
             * The LinkedListNodeValueIterator destructor.
             */
            virtual ~LinkedListNodeValueIterator();

            /**
             * The Copy/move constructors.
             */
            LinkedListNodeValueIterator(const LinkedListNodeValueIterator&) = delete;
            LinkedListNodeValueIterator(LinkedListNodeValueIterator&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            LinkedListNodeValueIterator& operator=(const LinkedListNodeValueIterator&) = delete;
            LinkedListNodeValueIterator& operator=(LinkedListNodeValueIterator&&) = delete;

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
            base::IIteratorSharedPtr<ILinkedListNodeSharedPtr<T>> m_iterator;
        };

        /**
         * Creates a new iterator of values of a doubly linked list.
         */
        template <typename T>
        base::IIteratorSharedPtr<T> LinkedListNodeValueIterator<T>::Make(base::IIteratorSharedPtr<ILinkedListNodeSharedPtr<T>> iterator)
        {
            return std::make_shared<LinkedListNodeValueIterator<T>>(iterator);
        }

        /**
         * The LinkedListNodeValueIterator constructor.
         */
        template <typename T>
        LinkedListNodeValueIterator<T>::LinkedListNodeValueIterator(base::IIteratorSharedPtr<ILinkedListNodeSharedPtr<T>> iterator) :
            m_iterator(iterator)
        {
            Reset();
        }

        /**
         * The LinkedListNodeValueIterator destructor.
         */
        template <typename T>
        LinkedListNodeValueIterator<T>::~LinkedListNodeValueIterator()
        {
        }

        /**
         * Checks whether there is a Next node.
         */
        template <typename T>
        bool LinkedListNodeValueIterator<T>::HasNext() const
        {
            return m_iterator->HasNext();
        }

        /**
         * Gets the Next node.
         */
        template <typename T>
        T LinkedListNodeValueIterator<T>::Next()
        {
            assert(HasNext());

            return m_iterator->Next()->GetValue();
        }

        /**
         * Resets the iterator.
         */
        template <typename T>
        void LinkedListNodeValueIterator<T>::Reset()
        {
            m_iterator->Reset();
        }
    }
}

#endif // LINKED_LIST_NODE_VALUE_ITERATOR_H_6242858f_e9cc_44d6_af3a_6f43955a4019
