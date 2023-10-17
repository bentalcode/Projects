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
            static base::IIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<T>> Make(IDoublyLinkedListNodeSharedPtr<T> head);

            /**
             * The DoublyLinkedListNodeIterator constructor.
             */
            explicit DoublyLinkedListNodeIterator(IDoublyLinkedListNodeSharedPtr<T> head);

            /**
             * The DoublyLinkedListNodeIterator destructor.
             */
            virtual ~DoublyLinkedListNodeIterator();

            /**
             * The Copy/move constructors.
             */
            DoublyLinkedListNodeIterator(const DoublyLinkedListNodeIterator&) = delete;
            DoublyLinkedListNodeIterator(DoublyLinkedListNodeIterator&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            DoublyLinkedListNodeIterator& operator=(const DoublyLinkedListNodeIterator&) = delete;
            DoublyLinkedListNodeIterator& operator=(DoublyLinkedListNodeIterator&&) = delete;

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
            IDoublyLinkedListNodeSharedPtr<T> m_head;
            IDoublyLinkedListNodeSharedPtr<T> m_currNode;
        };

        /**
         * Creates a new iterator of a doubly linked list.
         */
        template <typename T>
        base::IIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<T>> DoublyLinkedListNodeIterator<T>::Make(IDoublyLinkedListNodeSharedPtr<T> head)
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
            Reset();
        }

        /**
         * The DoublyLinkedListNodeIterator destructor.
         */
        template <typename T>
        DoublyLinkedListNodeIterator<T>::~DoublyLinkedListNodeIterator()
        {
        }

        /**
         * Checks whether there is a Next node.
         */
        template <typename T>
        bool DoublyLinkedListNodeIterator<T>::HasNext() const
        {
            return m_currNode != nullptr;
        }

        /**
         * Gets the Next node.
         */
        template <typename T>
        IDoublyLinkedListNodeSharedPtr<T> DoublyLinkedListNodeIterator<T>::Next()
        {
            assert(HasNext());

            IDoublyLinkedListNodeSharedPtr<T> currNode = m_currNode;
            m_currNode = m_currNode->Next();

            return currNode;
        }

        /**
         * Resets the iterator.
         */
        template <typename T>
        void DoublyLinkedListNodeIterator<T>::Reset()
        {
            m_currNode = m_head;
        }
    }
}

#endif // DOUBLY_LINKED_LIST_NODE_ITERATOR_H_5a51828e_0c68_4f13_b571_ffe503c5b784
