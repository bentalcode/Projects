#ifndef DOUBLY_LINKED_LIST_NODE_VALUE_REVERSE_ITERATOR_H_45a8082d_f024_4bf3_b034_3e93c501de0e
#define DOUBLY_LINKED_LIST_NODE_VALUE_REVERSE_ITERATOR_H_45a8082d_f024_4bf3_b034_3e93c501de0e

#include "IReverseIterator.h"
#include "DoublyLinkedListNode.h"

namespace datastructures {
    namespace doublylinkedlist {

        /**
         * The DoublyLinkedListNodeValueReverseIterator class implements a reverse iterator
         * of values of a doubly linked list.
         */
        template <typename T>
        class DoublyLinkedListNodeValueReverseIterator final : public base::IReverseIterator<T>
        {
        public:
            /**
             * Creates a new reverse iterator of values of a doubly linked list.
             */
            static base::IReverseIteratorSharedPtr<T> Make(base::IReverseIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<T>> reverseIterator);

            /**
             * The DoublyLinkedListNodeValueReverseIterator constructor.
             */
            explicit DoublyLinkedListNodeValueReverseIterator(base::IReverseIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<T>> reverseIterator);

            /**
             * The DoublyLinkedListNodeValueReverseIterator destructor.
             */
            virtual ~DoublyLinkedListNodeValueReverseIterator();

            /**
             * The Copy/move constructors.
             */
            DoublyLinkedListNodeValueReverseIterator(const DoublyLinkedListNodeValueReverseIterator&) = delete;
            DoublyLinkedListNodeValueReverseIterator(DoublyLinkedListNodeValueReverseIterator&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            DoublyLinkedListNodeValueReverseIterator& operator=(const DoublyLinkedListNodeValueReverseIterator&) = delete;
            DoublyLinkedListNodeValueReverseIterator& operator=(DoublyLinkedListNodeValueReverseIterator&&) = delete;

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
            base::IReverseIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<T>> m_reverseIterator;
        };

        /**
         * Creates a new reverse iterator of values of a doubly linked list.
         */
        template <typename T>
        base::IReverseIteratorSharedPtr<T> DoublyLinkedListNodeValueReverseIterator<T>::Make(
            base::IReverseIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<T>> reverseIterator)
        {
            return std::make_shared<DoublyLinkedListNodeValueReverseIterator<T>>(reverseIterator);
        }

        /**
         * The DoublyLinkedListNodeValueReverseIterator constructor.
         */
        template <typename T>
        DoublyLinkedListNodeValueReverseIterator<T>::DoublyLinkedListNodeValueReverseIterator(
            base::IReverseIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<T>> reverseIterator) :
            m_reverseIterator(reverseIterator)
        {
            base::SmartPointers::Validate<base::IReverseIterator<IDoublyLinkedListNodeSharedPtr<T>>>(reverseIterator);

            Reset();
        }

        /**
         * The DoublyLinkedListNodeValueReverseIterator destructor.
         */
        template <typename T>
        DoublyLinkedListNodeValueReverseIterator<T>::~DoublyLinkedListNodeValueReverseIterator()
        {
        }

        /**
         * Checks whether there is a Next node.
         */
        template <typename T>
        bool DoublyLinkedListNodeValueReverseIterator<T>::HasNext() const
        {
            return m_reverseIterator->HasNext();
        }

        /**
         * Gets the Next node.
         */
        template <typename T>
        T DoublyLinkedListNodeValueReverseIterator<T>::Next()
        {
            assert(HasNext());

            return m_reverseIterator->Next()->GetValue();
        }

        /**
         * Resets the iterator.
         */
        template <typename T>
        void DoublyLinkedListNodeValueReverseIterator<T>::Reset()
        {
            m_reverseIterator->Reset();
        }
    }
}

#endif // DOUBLY_LINKED_LIST_NODE_VALUE_REVERSE_ITERATOR_H_45a8082d_f024_4bf3_b034_3e93c501de0e
