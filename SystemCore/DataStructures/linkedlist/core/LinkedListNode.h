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
            static ILinkedListNodeSharedPtr<T> Make(const T& value)
            {
                return std::make_shared<LinkedListNode<T>>(value);
            }

            /**
             * Creates a new linked list node.
             */
            static ILinkedListNodeSharedPtr<T> Make(
                    const T& value,
                    ILinkedListNodeSharedPtr<T> next)
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
             * The LinkedListNode constructor with value and a Next node.
             */
            LinkedListNode(
                const T& value,
                ILinkedListNodeSharedPtr<T> nextNode);

            /**
             * The LinkedListNode destructor.
             */
            virtual ~LinkedListNode();

            /**
             * The Copy/move constructors.
             */
            LinkedListNode(const LinkedListNode&) = delete;
            LinkedListNode(LinkedListNode&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            LinkedListNode& operator=(const LinkedListNode&) = delete;
            LinkedListNode& operator=(LinkedListNode&&) = delete;

            /**
             * Gets a value of a node.
             */
            virtual const T& GetValue() const;

            /**
             * Sets a value of a node.
             */
            virtual void SetValue(const T& value);

            /**
             * Gets a Next node.
             */
            virtual ILinkedListNodeSharedPtr<T> Next() const;

            /**
             * Sets a Next node.
             */
            virtual void SetNext(ILinkedListNodeSharedPtr<T> node);

            /**
             * Checks whether there is a Next node.
             */
            virtual bool HasNext() const;

            /**
             * Unlinked the node.
             */
            virtual void Unlinked();

        private:
            T m_value;
            ILinkedListNodeSharedPtr<T> m_nextNode;
        };

        /**
         * The LinkedListNode constructor.
         */
        template <typename T>
        LinkedListNode<T>::LinkedListNode() :
            m_nextNode(nullptr)
        {
        }

        /**
         * The LinkedListNode constructor with value.
         */
        template <typename T>
        LinkedListNode<T>::LinkedListNode(const T& value) :
            m_value(value),
            m_nextNode(nullptr)
        {
        }

        /**
         * The LinkedListNode constructor with value and prev and Next nodes.
         */
        template <typename T>
        LinkedListNode<T>::LinkedListNode(
            const T& value,
            ILinkedListNodeSharedPtr<T> nextNode) :
            m_value(value),
            m_nextNode(nextNode)
        {
        }

        /**
         * The LinkedListNode destructor.
         */
        template <typename T>
        LinkedListNode<T>::~LinkedListNode()
        {
        }

        /**
         * Gets a value of a node.
         */
        template <typename T>
        const T& LinkedListNode<T>::GetValue() const
        {
            return m_value;
        }

        /**
        * Sets a value of a node.
        */
        template <typename T>
        void LinkedListNode<T>::SetValue(const T& value)
        {
            m_value = value;
        }

        /**
         * Gets a Next node.
         */
        template <typename T>
        ILinkedListNodeSharedPtr<T> LinkedListNode<T>::Next() const
        {
            return m_nextNode;
        }

        /**
         * Sets a Next node.
         */
        template <typename T>
        void LinkedListNode<T>::SetNext(ILinkedListNodeSharedPtr<T> node)
        {
            m_nextNode = node;
        }

        /**
         * Checks whether there is a Next node.
         */
        template <typename T>
        bool LinkedListNode<T>::HasNext() const
        {
            return m_nextNode != nullptr;
        }

        /**
         * Unlinked the node.
         */
        template <typename T>
        void LinkedListNode<T>::Unlinked()
        {
            m_nextNode = nullptr;
        }
    }
}

#endif // LINKED_LIST_NODE_H_58ebf1c5_2cb5_4887_9b6d_5bf5d5cade68
