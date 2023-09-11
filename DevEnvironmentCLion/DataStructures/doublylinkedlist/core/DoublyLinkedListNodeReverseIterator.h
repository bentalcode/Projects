#ifndef DOUBLY_LINKED_LIST_NODE_REVERSE_ITERATOR_H_004451f8_91f3_480e_9f66_cb9b07470857
#define DOUBLY_LINKED_LIST_NODE_REVERSE_ITERATOR_H_004451f8_91f3_480e_9f66_cb9b07470857

#include "IReverseIterator.h"
#include "IDoublyLinkedListNode.h"

namespace datastructures {
    namespace doublylinkedlist {

        /**
         * The DoublyLinkedListNodeReverseIterator class implements a reverse iterator of nodes of a doubly linked list.
         */
        template <typename T>
        class DoublyLinkedListNodeReverseIterator final : public base::IReverseIterator<IDoublyLinkedListNodePtr<T>>
        {
        public:
            /**
             * Creates a new iterator of a doubly linked list.
             */
            static base::IReverseIteratorPtr<IDoublyLinkedListNodePtr<T>> make(IDoublyLinkedListNodePtr<T> tail);

            /**
             * The DoublyLinkedListNodeReverseIterator constructor.
             */
            explicit DoublyLinkedListNodeReverseIterator(IDoublyLinkedListNodePtr<T> head);

            /**
             * The DoublyLinkedListNodeReverseIterator destructor.
             */
            virtual ~DoublyLinkedListNodeReverseIterator();

            /**
             * The copy/move constructors.
             */
            DoublyLinkedListNodeReverseIterator(const DoublyLinkedListNodeReverseIterator&) = delete;
            DoublyLinkedListNodeReverseIterator(DoublyLinkedListNodeReverseIterator&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            DoublyLinkedListNodeReverseIterator& operator=(const DoublyLinkedListNodeReverseIterator&) = delete;
            DoublyLinkedListNodeReverseIterator& operator=(DoublyLinkedListNodeReverseIterator&&) = delete;

            /**
             * Checks whether there is a next node.
             */
            bool hasNext() const;

            /**
             * Gets the next node.
             */
            IDoublyLinkedListNodePtr<T> next();

            /**
             * Resets the iterator.
             */
            void reset();

        private:
            IDoublyLinkedListNodePtr<T> m_tail;
            IDoublyLinkedListNodePtr<T> m_currNode;
        };

        /**
         * Creates a new reverse iterator of a doubly linked list.
         */
        template <typename T>
        base::IReverseIteratorPtr<IDoublyLinkedListNodePtr<T>> DoublyLinkedListNodeReverseIterator<T>::make(
            IDoublyLinkedListNodePtr<T> tail)
        {
            return std::make_shared<DoublyLinkedListNodeReverseIterator<T>>(tail);
        }

        /**
         * The DoublyLinkedListNodeReverseIterator constructor.
         */
        template <typename T>
        DoublyLinkedListNodeReverseIterator<T>::DoublyLinkedListNodeReverseIterator(IDoublyLinkedListNodePtr<T> tail) :
            m_tail(tail)
        {
            reset();
        }

        /**
         * The DoublyLinkedListNodeReverseIterator destructor.
         */
        template <typename T>
        DoublyLinkedListNodeReverseIterator<T>::~DoublyLinkedListNodeReverseIterator()
        {
        }

        /**
         * Checks whether there is a next node.
         */
        template <typename T>
        bool DoublyLinkedListNodeReverseIterator<T>::hasNext() const
        {
            return m_currNode != nullptr;
        }

        /**
         * Gets the next node.
         */
        template <typename T>
        IDoublyLinkedListNodePtr<T> DoublyLinkedListNodeReverseIterator<T>::next()
        {
            assert(hasNext());

            IDoublyLinkedListNodePtr<T> currNode = m_currNode;
            m_currNode = m_currNode->previous();

            return currNode;
        }

        /**
         * Resets the iterator.
         */
        template <typename T>
        void DoublyLinkedListNodeReverseIterator<T>::reset()
        {
            m_currNode = m_tail;
        }
    }
}

#endif // DOUBLY_LINKED_LIST_NODE_REVERSE_ITERATOR_H_004451f8_91f3_480e_9f66_cb9b07470857
