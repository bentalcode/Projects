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
        class DoublyLinkedListNodeReverseIterator final : public base::IReverseIterator<IDoublyLinkedListNodeSharedPtr<T>>
        {
        public:
            /**
             * Creates a new iterator of a doubly linked list.
             */
            static base::IReverseIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<T>> Make(IDoublyLinkedListNodeSharedPtr<T> tail);

            /**
             * The DoublyLinkedListNodeReverseIterator constructor.
             */
            explicit DoublyLinkedListNodeReverseIterator(IDoublyLinkedListNodeSharedPtr<T> head);

            /**
             * The DoublyLinkedListNodeReverseIterator destructor.
             */
            virtual ~DoublyLinkedListNodeReverseIterator();

            /**
             * The Copy/move constructors.
             */
            DoublyLinkedListNodeReverseIterator(const DoublyLinkedListNodeReverseIterator&) = delete;
            DoublyLinkedListNodeReverseIterator(DoublyLinkedListNodeReverseIterator&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            DoublyLinkedListNodeReverseIterator& operator=(const DoublyLinkedListNodeReverseIterator&) = delete;
            DoublyLinkedListNodeReverseIterator& operator=(DoublyLinkedListNodeReverseIterator&&) = delete;

            /**
             * Checks whether there is a Next node.
             */
            bool HasNext() const;

            /**
             * Gets the Next node.
             */
            IDoublyLinkedListNodeSharedPtr<T> Next();

            /**
             * Resets the iterator.
             */
            void Reset();

        private:
            IDoublyLinkedListNodeSharedPtr<T> m_tail;
            IDoublyLinkedListNodeSharedPtr<T> m_currNode;
        };

        /**
         * Creates a new reverse iterator of a doubly linked list.
         */
        template <typename T>
        base::IReverseIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<T>> DoublyLinkedListNodeReverseIterator<T>::Make(
            IDoublyLinkedListNodeSharedPtr<T> tail)
        {
            return std::make_shared<DoublyLinkedListNodeReverseIterator<T>>(tail);
        }

        /**
         * The DoublyLinkedListNodeReverseIterator constructor.
         */
        template <typename T>
        DoublyLinkedListNodeReverseIterator<T>::DoublyLinkedListNodeReverseIterator(IDoublyLinkedListNodeSharedPtr<T> tail) :
            m_tail(tail)
        {
            Reset();
        }

        /**
         * The DoublyLinkedListNodeReverseIterator destructor.
         */
        template <typename T>
        DoublyLinkedListNodeReverseIterator<T>::~DoublyLinkedListNodeReverseIterator()
        {
        }

        /**
         * Checks whether there is a Next node.
         */
        template <typename T>
        bool DoublyLinkedListNodeReverseIterator<T>::HasNext() const
        {
            return m_currNode != nullptr;
        }

        /**
         * Gets the Next node.
         */
        template <typename T>
        IDoublyLinkedListNodeSharedPtr<T> DoublyLinkedListNodeReverseIterator<T>::Next()
        {
            assert(HasNext());

            IDoublyLinkedListNodeSharedPtr<T> currNode = m_currNode;
            m_currNode = m_currNode->Previous();

            return currNode;
        }

        /**
         * Resets the iterator.
         */
        template <typename T>
        void DoublyLinkedListNodeReverseIterator<T>::Reset()
        {
            m_currNode = m_tail;
        }
    }
}

#endif // DOUBLY_LINKED_LIST_NODE_REVERSE_ITERATOR_H_004451f8_91f3_480e_9f66_cb9b07470857
