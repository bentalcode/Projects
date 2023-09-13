#ifndef LINKED_LIST_NODE_ITERATOR_H_f2bd7490_886d_47c2_8d37_468b50e455b4
#define LINKED_LIST_NODE_ITERATOR_H_f2bd7490_886d_47c2_8d37_468b50e455b4

#include "IIterator.h"
#include "ILinkedListNode.h"

namespace datastructures {
    namespace linkedlist {

        /**
         * The LinkedListNodeIterator class implements an iterator of nodes of a linked list.
         */
        template <typename T>
        class LinkedListNodeIterator final : public base::IIterator<ILinkedListNodeSharedPtr<T>>
        {
        public:
            /**
             * Creates a new iterator of a linked list.
             */
            static base::IIteratorSharedPtr<ILinkedListNodeSharedPtr<T>> make(ILinkedListNodeSharedPtr<T> head);

            /**
             * The LinkedListNodeIterator constructor.
             */
            explicit LinkedListNodeIterator(ILinkedListNodeSharedPtr<T> head);

            /**
             * The LinkedListNodeIterator destructor.
             */
            virtual ~LinkedListNodeIterator();

            /**
             * The copy/move constructors.
             */
            LinkedListNodeIterator(const LinkedListNodeIterator&) = delete;
            LinkedListNodeIterator(LinkedListNodeIterator&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            LinkedListNodeIterator& operator=(const LinkedListNodeIterator&) = delete;
            LinkedListNodeIterator& operator=(LinkedListNodeIterator&&) = delete;

            /**
             * Checks whether there is a next node.
             */
            bool hasNext() const;

            /**
             * Gets the next node.
             */
            ILinkedListNodeSharedPtr<T> next();

            /**
             * Resets the iterator.
             */
            void reset();

        private:
            ILinkedListNodeSharedPtr<T> m_head;
            ILinkedListNodeSharedPtr<T> m_currNode;
        };

        /**
         * Creates a new iterator of a linked list.
         */
        template <typename T>
        base::IIteratorSharedPtr<ILinkedListNodeSharedPtr<T>> LinkedListNodeIterator<T>::make(ILinkedListNodeSharedPtr<T> head)
        {
            return std::make_shared<LinkedListNodeIterator<T>>(head);
        }

        /**
         * The LinkedListNodeIterator constructor.
         */
        template <typename T>
        LinkedListNodeIterator<T>::LinkedListNodeIterator(ILinkedListNodeSharedPtr<T> head) :
            m_head(head)
        {
            reset();
        }

        /**
         * The LinkedListNodeIterator destructor.
         */
        template <typename T>
        LinkedListNodeIterator<T>::~LinkedListNodeIterator()
        {
        }

        /**
         * Checks whether there is a next node.
         */
        template <typename T>
        bool LinkedListNodeIterator<T>::hasNext() const
        {
            return m_currNode != nullptr;
        }

        /**
         * Gets the next node.
         */
        template <typename T>
        ILinkedListNodeSharedPtr<T> LinkedListNodeIterator<T>::next()
        {
            assert(hasNext());

            ILinkedListNodeSharedPtr<T> currNode = m_currNode;
            m_currNode = m_currNode->next();

            return currNode;
        }

        /**
         * Resets the iterator.
         */
        template <typename T>
        void LinkedListNodeIterator<T>::reset()
        {
            m_currNode = m_head;
        }
    }
}

#endif // LINKED_LIST_NODE_ITERATOR_H_f2bd7490_886d_47c2_8d37_468b50e455b4
