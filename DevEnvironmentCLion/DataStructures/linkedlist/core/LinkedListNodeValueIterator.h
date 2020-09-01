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
            static base::IIteratorPtr<T> make(base::IIterator<ILinkedListNodePtr<T>>& iterator);

            /**
             * The LinkedListNodeValueIterator constructor.
             */
            explicit LinkedListNodeValueIterator(base::IIterator<ILinkedListNodePtr<T>>& iterator);

            /**
             * The LinkedListNodeValueIterator destructor.
             */
            virtual ~LinkedListNodeValueIterator();

            /**
             * The copy/move constructors.
             */
            LinkedListNodeValueIterator(const LinkedListNodeValueIterator&) = delete;
            LinkedListNodeValueIterator(LinkedListNodeValueIterator&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            LinkedListNodeValueIterator& operator=(const LinkedListNodeValueIterator&) = delete;
            LinkedListNodeValueIterator& operator=(LinkedListNodeValueIterator&&) = delete;

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
            base::IIterator<ILinkedListNodePtr<T>>& m_iterator;
        };

        /**
         * Creates a new iterator of values of a doubly linked list.
         */
        template <typename T>
        base::IIteratorPtr<T> LinkedListNodeValueIterator<T>::make(base::IIterator<ILinkedListNodePtr<T>>& iterator)
        {
            return std::make_shared<LinkedListNodeValueIterator<T>>(iterator);
        }

        /**
         * The LinkedListNodeValueIterator constructor.
         */
        template <typename T>
        LinkedListNodeValueIterator<T>::LinkedListNodeValueIterator(base::IIterator<ILinkedListNodePtr<T>>& iterator) :
            m_iterator(iterator)
        {
            reset();
        }

        /**
         * The LinkedListNodeValueIterator destructor.
         */
        template <typename T>
        LinkedListNodeValueIterator<T>::~LinkedListNodeValueIterator()
        {
        }

        /**
         * Checks whether there is a next node.
         */
        template <typename T>
        bool LinkedListNodeValueIterator<T>::hasNext() const
        {
            return m_iterator.hasNext();
        }

        /**
         * Gets the next node.
         */
        template <typename T>
        T LinkedListNodeValueIterator<T>::next()
        {
            assert(hasNext());

            return m_iterator.next()->getValue();
        }

        /**
         * Resets the iterator.
         */
        template <typename T>
        void LinkedListNodeValueIterator<T>::reset()
        {
            m_iterator.reset();
        }
    }
}

#endif // LINKED_LIST_NODE_VALUE_ITERATOR_H_6242858f_e9cc_44d6_af3a_6f43955a4019
