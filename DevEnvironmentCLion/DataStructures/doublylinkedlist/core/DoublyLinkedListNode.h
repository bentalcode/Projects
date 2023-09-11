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
            static IDoublyLinkedListNodePtr<T> make(const T& value)
            {
                return std::make_shared<DoublyLinkedListNode<T>>(value);
            }

            /**
             * Creates a new doubly linked list node.
             */
            static IDoublyLinkedListNodePtr<T> make(
                const T& value,
                IDoublyLinkedListNodePtr<T> previous,
                IDoublyLinkedListNodePtr<T> next)
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
             * The DoublyLinkedListNode constructor with value and prev and next nodes.
             */
            DoublyLinkedListNode(
                const T &value,
                IDoublyLinkedListNodePtr<T> prevNode,
                IDoublyLinkedListNodePtr<T> nextNode);

            /**
             * The DoublyLinkedListNode destructor.
             */
            virtual ~DoublyLinkedListNode();

            /**
             * The copy/move constructors.
             */
            DoublyLinkedListNode(const DoublyLinkedListNode&) = delete;
            DoublyLinkedListNode(DoublyLinkedListNode&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            DoublyLinkedListNode& operator=(const DoublyLinkedListNode&) = delete;
            DoublyLinkedListNode& operator=(DoublyLinkedListNode&&) = delete;

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
            virtual IDoublyLinkedListNodePtr<T> next() const;

            /**
             * Sets a next node.
             */
            virtual void setNext(IDoublyLinkedListNodePtr<T> node);

            /**
             * Checks whether there is a next node.
             */
            virtual bool hasNext() const;

            /**
             * Gets a previous node.
             */
            virtual IDoublyLinkedListNodePtr<T> previous() const;

            /**
             * Sets a previous node.
             */
            virtual void setPrevious(IDoublyLinkedListNodePtr<T> node);

            /**
             * Checks whether there is a previous node.
             */
            virtual bool hasPrevious() const;

            /**
             * Unlinked the node.
             */
            virtual void unlinked();

        private:
            T m_value;
            IDoublyLinkedListNodePtr<T> m_nextNode;
            IDoublyLinkedListNodePtr<T> m_previousNode;
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
         * The DoublyLinkedListNode constructor with value and prev and next nodes.
         */
        template <typename T>
        DoublyLinkedListNode<T>::DoublyLinkedListNode(
            const T& value,
            IDoublyLinkedListNodePtr<T> prevNode,
            IDoublyLinkedListNodePtr<T> nextNode) :
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
        const T& DoublyLinkedListNode<T>::getValue() const
        {
            return m_value;
        }

        /**
        * Sets a value of a node.
        */
        template <typename T>
        void DoublyLinkedListNode<T>::setValue(const T& value)
        {
            m_value = value;
        }

        /**
         * Gets a next node.
         */
        template <typename T>
        IDoublyLinkedListNodePtr<T> DoublyLinkedListNode<T>::next() const
        {
            return m_nextNode;
        }

        /**
         * Sets a next node.
         */
        template <typename T>
        void DoublyLinkedListNode<T>::setNext(IDoublyLinkedListNodePtr<T> node)
        {
            m_nextNode = node;
        }

        /**
         * Checks whether there is a next node.
         */
        template <typename T>
        bool DoublyLinkedListNode<T>::hasNext() const
        {
            return m_nextNode != nullptr;
        }

        /**
         * Gets a previous node.
         */
        template <typename T>
        IDoublyLinkedListNodePtr<T> DoublyLinkedListNode<T>::previous() const
        {
            return m_previousNode;
        }

        /**
         * Sets a previous node.
         */
        template <typename T>
        void DoublyLinkedListNode<T>::setPrevious(IDoublyLinkedListNodePtr<T> node)
        {
            m_previousNode = node;
        }

        /**
         * Checks whether there is a previous node.
         */
        template <typename T>
        bool DoublyLinkedListNode<T>::hasPrevious() const
        {
            return m_previousNode != nullptr;
        }

        /**
         * Unlinked the node.
         */
        template <typename T>
        void DoublyLinkedListNode<T>::unlinked()
        {
            m_nextNode = nullptr;
            m_previousNode = nullptr;
        }
    }
}

#endif // DOUBLY_LINKED_LIST_NODE_H_dd42263f_96a7_45e2_aede_78c7c67ca7e3
