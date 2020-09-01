#ifndef LINKED_LIST_NODE_H_58ebf1c5_2cb5_4887_9b6d_5bf5d5cade68
#define LINKED_LIST_NODE_H_58ebf1c5_2cb5_4887_9b6d_5bf5d5cade68

#include "ILinkedListNode.h"

namespace datastructures {
    namespace linkedlist {

        /**
         * The LinkedListNode class implements a node of a linked list.
         */
        template <typename T>
        class LinkedListNode final : public ILinkedListNode<T>
        {
        public:
            /**
             * Creates a new linked list node.
             */
            static ILinkedListNodePtr<T> make(const T& value)
            {
                return std::make_shared<LinkedListNode<T>>(value);
            }

            /**
             * Creates a new linked list node.
             */
            static ILinkedListNodePtr<T> make(
                const T& value,
                ILinkedListNodePtr<T> next)
            {
                return std::make_shared<LinkedListNode<T>>(
                    value,
                    next);
            }

            /**
             * The LinkedListNode constructor.
             */
            LinkedListNode();

            /**
             * The LinkedListNode constructor with value.
             */
            explicit LinkedListNode(const T& value);

            /**
             * The LinkedListNode constructor with value and a next node.
             */
            LinkedListNode(
                const T& value,
                ILinkedListNodePtr<T> nextNode);

            /**
             * The LinkedListNode destructor.
             */
            virtual ~LinkedListNode();

            /**
             * The copy/move constructors.
             */
            LinkedListNode(const LinkedListNode&) = delete;
            LinkedListNode(LinkedListNode&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            LinkedListNode& operator=(const LinkedListNode&) = delete;
            LinkedListNode& operator=(LinkedListNode&&) = delete;

            /**
             * Gets a value of a node.
             */
            virtual const T& getValue() const;

            /**
             * Sets a value of a node.
             */
            virtual void setValue(const T& value);

            /**
             * Gets a next node.
             */
            virtual ILinkedListNodePtr<T> next() const;

            /**
             * Sets a next node.
             */
            virtual void setNext(ILinkedListNodePtr<T> node);

            /**
             * Checks whether there is a next node.
             */
            virtual bool hasNext() const;

            /**
             * Unlinked the node.
             */
            virtual void unlinked();

        private:
            T m_value;
            ILinkedListNodePtr<T> m_nextNode;
        };

        /**
         * The LinkedListNode constructor.
         */
        template<typename T>
        LinkedListNode<T>::LinkedListNode() :
            m_nextNode(nullptr)
        {
        }

        /**
         * The LinkedListNode constructor with value.
         */
        template<typename T>
        LinkedListNode<T>::LinkedListNode(const T& value) :
            m_value(value),
            m_nextNode(nullptr)
        {
        }

        /**
         * The LinkedListNode constructor with value and prev and next nodes.
         */
        template<typename T>
        LinkedListNode<T>::LinkedListNode(
            const T& value,
            ILinkedListNodePtr<T> nextNode) :
            m_value(value),
            m_nextNode(nextNode)
        {
        }

        /**
         * The LinkedListNode destructor.
         */
        template<typename T>
        LinkedListNode<T>::~LinkedListNode()
        {
        }

        /**
         * Gets a value of a node.
         */
        template <typename T>
        const T& LinkedListNode<T>::getValue() const
        {
            return m_value;
        }

        /**
        * Sets a value of a node.
        */
        template <typename T>
        void LinkedListNode<T>::setValue(const T& value)
        {
            m_value = value;
        }

        /**
         * Gets a next node.
         */
        template <typename T>
        ILinkedListNodePtr<T> LinkedListNode<T>::next() const
        {
            return m_nextNode;
        }

        /**
         * Sets a next node.
         */
        template <typename T>
        void LinkedListNode<T>::setNext(ILinkedListNodePtr<T> node)
        {
            m_nextNode = node;
        }

        /**
         * Checks whether there is a next node.
         */
        template <typename T>
        bool LinkedListNode<T>::hasNext() const
        {
            return m_nextNode != nullptr;
        }

        /**
         * Unlinked the node.
         */
        template<typename T>
        void LinkedListNode<T>::unlinked()
        {
            m_nextNode = nullptr;
        }
    }
}

#endif // LINKED_LIST_NODE_H_58ebf1c5_2cb5_4887_9b6d_5bf5d5cade68
