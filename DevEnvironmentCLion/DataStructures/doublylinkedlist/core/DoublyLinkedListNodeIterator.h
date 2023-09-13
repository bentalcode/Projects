#ifndef DOUBLY_LINKED_LIST_NODE_ITERATOR_H_5a51828e_0c68_4f13_b571_ffe503c5b784
#define DOUBLY_LINKED_LIST_NODE_ITERATOR_H_5a51828e_0c68_4f13_b571_ffe503c5b784

#include "IIterator.h"
#include "IDoublyLinkedListNode.h"

namespace datastructures {
    namespace doublylinkedlist {

        /**
         * The DoublyLinkedListNodeIterator class implements an iterator of nodes of a doubly linked list.
         */
        template <typename T>
        class DoublyLinkedListNodeIterator final : public base::IIterator<IDoublyLinkedListNodeSharedPtr<T>>
        {
        public:
            /**
             * Creates a new iterator of a doubly linked list.
             */
            static base::IIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<T>> make(IDoublyLinkedListNodeSharedPtr<T> head);

            /**
             * The DoublyLinkedListNodeIterator constructor.
             */
            explicit DoublyLinkedListNodeIterator(IDoublyLinkedListNodeSharedPtr<T> head);

            /**
             * The DoublyLinkedListNodeIterator destructor.
             */
            virtual ~DoublyLinkedListNodeIterator();

            /**
             * The copy/move constructors.
             */
            DoublyLinkedListNodeIterator(const DoublyLinkedListNodeIterator&) = delete;
            DoublyLinkedListNodeIterator(DoublyLinkedListNodeIterator&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            DoublyLinkedListNodeIterator& operator=(const DoublyLinkedListNodeIterator&) = delete;
            DoublyLinkedListNodeIterator& operator=(DoublyLinkedListNodeIterator&&) = delete;

            /**
             * Checks whether there is a next node.
             */
            bool hasNext() const;

            /**
             * Gets the next node.
             */
            IDoublyLinkedListNodeSharedPtr<T> next();

            /**
             * Resets the iterator.
             */
            void reset();

        private:
            IDoublyLinkedListNodeSharedPtr<T> m_head;
            IDoublyLinkedListNodeSharedPtr<T> m_currNode;
        };

        /**
         * Creates a new iterator of a doubly linked list.
         */
        template <typename T>
        base::IIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<T>> DoublyLinkedListNodeIterator<T>::make(IDoublyLinkedListNodeSharedPtr<T> head)
        {
            return std::make_shared<DoublyLinkedListNodeIterator<T>>(head);
        }

        /**
         * The DoublyLinkedListNodeIterator constructor.
         */
        template <typename T>
        DoublyLinkedListNodeIterator<T>::DoublyLinkedListNodeIterator(IDoublyLinkedListNodeSharedPtr<T> head) :
            m_head(head)
        {
            reset();
        }

        /**
         * The DoublyLinkedListNodeIterator destructor.
         */
        template <typename T>
        DoublyLinkedListNodeIterator<T>::~DoublyLinkedListNodeIterator()
        {
        }

        /**
         * Checks whether there is a next node.
         */
        template <typename T>
        bool DoublyLinkedListNodeIterator<T>::hasNext() const
        {
            return m_currNode != nullptr;
        }

        /**
         * Gets the next node.
         */
        template <typename T>
        IDoublyLinkedListNodeSharedPtr<T> DoublyLinkedListNodeIterator<T>::next()
        {
            assert(hasNext());

            IDoublyLinkedListNodeSharedPtr<T> currNode = m_currNode;
            m_currNode = m_currNode->next();

            return currNode;
        }

        /**
         * Resets the iterator.
         */
        template <typename T>
        void DoublyLinkedListNodeIterator<T>::reset()
        {
            m_currNode = m_head;
        }
    }
}

#endif // DOUBLY_LINKED_LIST_NODE_ITERATOR_H_5a51828e_0c68_4f13_b571_ffe503c5b784
