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
        class LinkedListNodeIterator final : public base::IIterator<ILinkedListNodePtr<T>>
        {
        public:
            /**
             * Creates a new iterator of a linked list.
             */
            static base::IIteratorPtr<ILinkedListNodePtr<T>> make(ILinkedListNodePtr<T> head);

            /**
             * The LinkedListNodeIterator constructor.
             */
            explicit LinkedListNodeIterator(ILinkedListNodePtr<T> head);

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
            ILinkedListNodePtr<T> next();

            /**
             * Resets the iterator.
             */
            void reset();

        private:
            ILinkedListNodePtr<T> m_head;
            ILinkedListNodePtr<T> m_currNode;
        };

        /**
         * Creates a new iterator of a linked list.
         */
        template <typename T>
        base::IIteratorPtr<ILinkedListNodePtr<T>> LinkedListNodeIterator<T>::make(ILinkedListNodePtr<T> head)
        {
            return std::make_shared<LinkedListNodeIterator<T>>(head);
        }

        /**
         * The LinkedListNodeIterator constructor.
         */
        template <typename T>
        LinkedListNodeIterator<T>::LinkedListNodeIterator(ILinkedListNodePtr<T> head) :
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
        ILinkedListNodePtr<T> LinkedListNodeIterator<T>::next()
        {
            assert(hasNext());

            ILinkedListNodePtr<T> currNode = m_currNode;
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
