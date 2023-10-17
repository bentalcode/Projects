#ifndef DOUBLY_LINKED_LIST_NODE_H_dd42263f_96a7_45e2_aede_78c7c67ca7e3
#define DOUBLY_LINKED_LIST_NODE_H_dd42263f_96a7_45e2_aede_78c7c67ca7e3

#include "IDoublyLinkedListNode.h"

namespace datastructures {
    namespace doublylinkedlist {

        /**
         * The DoublyLinkedListNode class implements a node of a doubly linked list.
         */
        template <typename T>
        class DoublyLinkedListNode final : public IDoublyLinkedListNode<T>
        {
        public:
            /**
             * Creates a new doubly linked list node.
             */
            static IDoublyLinkedListNodeSharedPtr<T> Make(const T& value)
            {
                return std::make_shared<DoublyLinkedListNode<T>>(value);
            }

            /**
             * Creates a new doubly linked list node.
             */
            static IDoublyLinkedListNodeSharedPtr<T> Make(
                const T& value,
                IDoublyLinkedListNodeSharedPtr<T> previous,
                IDoublyLinkedListNodeSharedPtr<T> next)
            {
                return std::make_shared<DoublyLinkedListNode<T>>(
                    value,
                    previous,
                    next);
            }

            /**
             * The DoublyLinkedListNode constructor.
             */
            DoublyLinkedListNode();

            /**
             * The DoublyLinkedListNode constructor with value.
             */
            explicit DoublyLinkedListNode(const T& value);

            /**
             * The DoublyLinkedListNode constructor with value and prev and Next nodes.
             */
            DoublyLinkedListNode(
                const T &value,
                IDoublyLinkedListNodeSharedPtr<T> prevNode,
                IDoublyLinkedListNodeSharedPtr<T> nextNode);

            /**
             * The DoublyLinkedListNode destructor.
             */
            virtual ~DoublyLinkedListNode();

            /**
             * The Copy/move constructors.
             */
            DoublyLinkedListNode(const DoublyLinkedListNode&) = delete;
            DoublyLinkedListNode(DoublyLinkedListNode&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            DoublyLinkedListNode& operator=(const DoublyLinkedListNode&) = delete;
            DoublyLinkedListNode& operator=(DoublyLinkedListNode&&) = delete;

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
            virtual IDoublyLinkedListNodeSharedPtr<T> Next() const;

            /**
             * Sets a Next node.
             */
            virtual void SetNext(IDoublyLinkedListNodeSharedPtr<T> node);

            /**
             * Checks whether there is a Next node.
             */
            virtual bool HasNext() const;

            /**
             * Gets a Previous node.
             */
            virtual IDoublyLinkedListNodeSharedPtr<T> Previous() const;

            /**
             * Sets a Previous node.
             */
            virtual void SetPrevious(IDoublyLinkedListNodeSharedPtr<T> node);

            /**
             * Checks whether there is a Previous node.
             */
            virtual bool HasPrevious() const;

            /**
             * Unlinked the node.
             */
            virtual void Unlinked();

        private:
            T m_value;
            IDoublyLinkedListNodeSharedPtr<T> m_nextNode;
            IDoublyLinkedListNodeSharedPtr<T> m_previousNode;
        };

        /**
         * The DoublyLinkedListNode constructor.
         */
        template <typename T>
        DoublyLinkedListNode<T>::DoublyLinkedListNode() :
            m_nextNode(nullptr),
            m_previousNode(nullptr)
        {
        }

        /**
         * The DoublyLinkedListNode constructor with value.
         */
        template <typename T>
        DoublyLinkedListNode<T>::DoublyLinkedListNode(const T& value) :
            m_value(value),
            m_nextNode(nullptr),
            m_previousNode(nullptr)
        {
        }

        /**
         * The DoublyLinkedListNode constructor with value and prev and Next nodes.
         */
        template <typename T>
        DoublyLinkedListNode<T>::DoublyLinkedListNode(
            const T& value,
            IDoublyLinkedListNodeSharedPtr<T> prevNode,
            IDoublyLinkedListNodeSharedPtr<T> nextNode) :
            m_value(value),
            m_nextNode(nextNode),
            m_previousNode(prevNode)
        {
        }

        /**
         * The DoublyLinkedListNode destructor.
         */
        template <typename T>
        DoublyLinkedListNode<T>::~DoublyLinkedListNode()
        {
        }

        /**
         * Gets a value of a node.
         */
        template <typename T>
        const T& DoublyLinkedListNode<T>::GetValue() const
        {
            return m_value;
        }

        /**
        * Sets a value of a node.
        */
        template <typename T>
        void DoublyLinkedListNode<T>::SetValue(const T& value)
        {
            m_value = value;
        }

        /**
         * Gets a Next node.
         */
        template <typename T>
        IDoublyLinkedListNodeSharedPtr<T> DoublyLinkedListNode<T>::Next() const
        {
            return m_nextNode;
        }

        /**
         * Sets a Next node.
         */
        template <typename T>
        void DoublyLinkedListNode<T>::SetNext(IDoublyLinkedListNodeSharedPtr<T> node)
        {
            m_nextNode = node;
        }

        /**
         * Checks whether there is a Next node.
         */
        template <typename T>
        bool DoublyLinkedListNode<T>::HasNext() const
        {
            return m_nextNode != nullptr;
        }

        /**
         * Gets a Previous node.
         */
        template <typename T>
        IDoublyLinkedListNodeSharedPtr<T> DoublyLinkedListNode<T>::Previous() const
        {
            return m_previousNode;
        }

        /**
         * Sets a Previous node.
         */
        template <typename T>
        void DoublyLinkedListNode<T>::SetPrevious(IDoublyLinkedListNodeSharedPtr<T> node)
        {
            m_previousNode = node;
        }

        /**
         * Checks whether there is a Previous node.
         */
        template <typename T>
        bool DoublyLinkedListNode<T>::HasPrevious() const
        {
            return m_previousNode != nullptr;
        }

        /**
         * Unlinked the node.
         */
        template <typename T>
        void DoublyLinkedListNode<T>::Unlinked()
        {
            m_nextNode = nullptr;
            m_previousNode = nullptr;
        }
    }
}

#endif // DOUBLY_LINKED_LIST_NODE_H_dd42263f_96a7_45e2_aede_78c7c67ca7e3
