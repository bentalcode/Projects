#ifndef DOUBLY_LINKED_LIST_H_2fb624de_8041_4c05_98cb_08b2cb97d8d4
#define DOUBLY_LINKED_LIST_H_2fb624de_8041_4c05_98cb_08b2cb97d8d4

#include "IDoublyLinkedList.h"
#include "DoublyLinkedListNode.h"
#include "DoublyLinkedListNodeIterator.h"
#include "DoublyLinkedListNodeReverseIterator.h"
#include "DoublyLinkedListNodeValueIterator.h"
#include "DoublyLinkedListNodeValueReverseIterator.h"
#include "DoublyLinkedListException.h"

namespace datastructures {
    namespace doublylinkedlist {

        /**
         * The DoublyLinkedList class implements a doubly linked list.
         */
        template<typename T>
        class DoublyLinkedList final : public IDoublyLinkedList<T>
        {
        public:
            /**
             * Creates a new doubly linked list.
             */
            static IDoublyLinkedListPtr<T> make();

            /**
             * Creates a new doubly linked list from a node list.
             */
            static IDoublyLinkedListNodePtr<T> make(IDoublyLinkedListNodePtr<T> head);

            /**
             * The DoublyLinkedList constructor.
             */
            DoublyLinkedList();

            /**
             * The DoublyLinkedList constructor with a list.
             */
            DoublyLinkedList(IDoublyLinkedListNodePtr<T> head);

            /**
             * The DoublyLinkedList destructor.
             */
            virtual ~DoublyLinkedList();

            /**
             * The copy/move constructors.
             */
            DoublyLinkedList(const DoublyLinkedList&) = delete;
            DoublyLinkedList(DoublyLinkedList&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;
            DoublyLinkedList& operator=(DoublyLinkedList&&) = delete;

            /**
             * Gets the head node of the list.
             */
            virtual IDoublyLinkedListNodePtr<T> getHead() const override;

            /**
             * Gets the tail node of the list.
             */
            virtual IDoublyLinkedListNodePtr<T> getTail() const override;

            /**
             * Gets the size of the list.
             */
            virtual size_t size() const override;

            /**
             * Checks whether the list is empty.
             */
            virtual bool empty() const override;

            /**
             * Adds a new value to the front of the list.
             */
            virtual void addToFront(const T& value) override;

            /**
             * Adds a new value to the back of the list.
             */
            virtual void addToBack(const T& value) override;

            /**
             * Adds a new value after a specific node of the list.
             */
            virtual void addAfter(
                IDoublyLinkedListNodePtr<T> currNode,
                const T& valueToAdd) override;

            /**
             * Adds a new value before a specific node of the list.
             */
            virtual void addBefore(
                IDoublyLinkedListNodePtr<T> currNode,
                const T& valueToAdd) override;

            /**
             * Adds a new node to the front of the list.
             */
            virtual void addToFront(IDoublyLinkedListNodePtr<T> node) override;

            /**
             * Adds a new node to the back of the list.
             */
            virtual void addToBack(IDoublyLinkedListNodePtr<T> node) override;

            /**
             * Adds a new node after a specific node of the list.
             */
            virtual void addAfter(
                IDoublyLinkedListNodePtr<T> currNode,
                IDoublyLinkedListNodePtr<T> nodeToAdd) override;

            /**
             * Adds a new node before a specific node of the list.
             */
            virtual void addBefore(
                IDoublyLinkedListNodePtr<T> currNode,
                IDoublyLinkedListNodePtr<T> nodeToAdd) override;

            /**
             * Removes the front node from the list.
             * Returns the removed node or null if the list is empty.
             */
            virtual IDoublyLinkedListNodePtr<T> removeFromFront() override;

            /**
             * Removes the back node from the list.
             * Returns the removed node or null if the list is empty.
             */
            virtual IDoublyLinkedListNodePtr<T> removeFromBack() override;

            /**
             * Removes the a node from the list.
             */
            virtual void remove(IDoublyLinkedListNodePtr<T> nodeToRemove) override;

            /**
             * Clears the list.
             */
            virtual void clear() override;

            /**
             * Gets an iterator of nodes.
             */
            virtual base::IIteratorPtr<IDoublyLinkedListNodePtr<T>> getIterator() const override;

            /**
             * Gets a reverse iterator of nodes.
             */
            virtual base::IReverseIteratorPtr<IDoublyLinkedListNodePtr<T>> getReverseIterator() const override;
            
            /**
             * Gets an iterator of values of a list.
             */
            virtual base::IIteratorPtr<T> getValueIterator() const override;

            /**
             * Gets a reverse iterator of values of a list.
             */
            virtual base::IReverseIteratorPtr<T> getValueReverseIterator() const override;

            /**
             * Gets a specific node by index. Index: [0, 1, 2, ... , size -1]
             */
            virtual IDoublyLinkedListNodePtr<T> getNode(size_t index) const override;

        private:
            /**
             * Validate a node.
             */
             void validateNode(IDoublyLinkedListNodePtr<T> node) const;

            /**
             * Linked nodes.
             */
            void linkedNodes(IDoublyLinkedListNodePtr<T> left, IDoublyLinkedListNodePtr<T> right);

            /**
             * Node added.
             */
            void nodeAdded();

            /**
             * Node removed.
             */
            void nodeRemoved(IDoublyLinkedListNode<T>& node);

            IDoublyLinkedListNodePtr<T> m_head;
            IDoublyLinkedListNodePtr<T> m_tail;
            size_t m_size;
        };

        template <typename T>
        using IDoublyLinkedListPtr = std::shared_ptr<IDoublyLinkedList<T>>;

        /**
         * Creates a new doubly linked list.
         */
        template<typename T>
        IDoublyLinkedListPtr<T> DoublyLinkedList<T>::make()
        {
            return std::make_shared<DoublyLinkedList<T>>();
        }

        /**
         * Creates a new doubly linked list from a node list.
         */
        template<typename T>
        IDoublyLinkedListNodePtr<T> DoublyLinkedList<T>::make(IDoublyLinkedListNodePtr<T> head)
        {
            return std::make_shared<DoublyLinkedListNode<T>>(head);
        }

        /**
         * The DoublyLinkedList constructor.
         */
        template<typename T>
        DoublyLinkedList<T>::DoublyLinkedList() :
            m_size(0)
        {
        }

        /**
         * The DoublyLinkedList constructor with a node list.
         */
        template<typename T>
        DoublyLinkedList<T>::DoublyLinkedList(IDoublyLinkedListNodePtr<T> head) :
            m_size(0)
        {
            IDoublyLinkedListNodePtr<T> currNode = head;

            while (currNode)
            {
                IDoublyLinkedListNodePtr<T> nextNode = currNode->next();
                addToBack(currNode);

                currNode = nextNode;
            }
        }

        /**
         * The DoublyLinkedList destructor.
         */
        template<typename T>
        DoublyLinkedList<T>::~DoublyLinkedList()
        {
        }

        /**
         * Gets the head node of the list.
         */
        template <typename T>
        IDoublyLinkedListNodePtr<T> DoublyLinkedList<T>::getHead() const
        {
            return m_head;
        }

        /**
         * Gets the tail node of the list.
         */
        template <typename T>
        IDoublyLinkedListNodePtr<T> DoublyLinkedList<T>::getTail() const
        {
            return m_tail;
        }

        /**
         * Gets the size of the list.
         */
        template <typename T>
        size_t DoublyLinkedList<T>::size() const
        {
            return m_size;
        }

        /**
         * Checks whether the list is empty.
         */
        template <typename T>
        bool DoublyLinkedList<T>::empty() const
        {
            return m_size == 0;
        }

        /**
         * Adds a new value to the front of the list.
         */
        template <typename T>
        void DoublyLinkedList<T>::addToFront(const T& value)
        {
            addToFront(DoublyLinkedListNode<T>::make(value));
        }

        /**
         * Adds a new value to the back of the list.
         */
        template <typename T>
        void DoublyLinkedList<T>::addToBack(const T& value)
        {
            addToBack(DoublyLinkedListNode<T>::make(value));
        }

        /**
         * Adds a new value after a specific node of the list.
         */
        template <typename T>
        void DoublyLinkedList<T>::addAfter(
            IDoublyLinkedListNodePtr<T> currNode,
            const T& valueToAdd)
        {
            addAfter(currNode, DoublyLinkedListNode<T>::make(valueToAdd));
        }

        /**
         * Adds a new value before a specific node of the list.
         */
        template <typename T>
        void DoublyLinkedList<T>::addBefore(
            IDoublyLinkedListNodePtr<T> currNode,
            const T& valueToAdd)
        {
            addBefore(currNode, DoublyLinkedListNode<T>::make(valueToAdd));
        }

        /**
         * Adds a new node to the front of the list.
         */
        template <typename T>
        void DoublyLinkedList<T>::addToFront(IDoublyLinkedListNodePtr<T> node)
        {
            validateNode(node);

            node->unlinked();

            if (!m_head)
            {
                assert(!m_tail && empty());
                m_head = node;
                m_tail = node;
            }
            else
            {
                linkedNodes(node, m_head);
                m_head = node;
            }

            nodeAdded();
        }

        /**
         * Adds a new node to the back of the list.
         */
        template <typename T>
        void DoublyLinkedList<T>::addToBack(IDoublyLinkedListNodePtr<T> node)
        {
            validateNode(node);

            if (!m_tail)
            {
                assert(!m_head && empty());
                m_head = node;
                m_tail = node;
            }
            else
            {
                linkedNodes(m_tail, node);
                m_tail = node;
            }

            nodeAdded();
        }

        /**
         * Adds a new node after a specific node of the list.
         */
        template <typename T>
        void DoublyLinkedList<T>::addAfter(
            IDoublyLinkedListNodePtr<T> currNode,
            IDoublyLinkedListNodePtr<T> nodeToAdd)
        {
            validateNode(currNode);
            validateNode(nodeToAdd);

            nodeToAdd->unlinked();

            IDoublyLinkedListNodePtr<T> nextNode = nodeToAdd->next();

            linkedNodes(currNode, nodeToAdd);

            if (nextNode)
            {
                linkedNodes(nodeToAdd, nextNode);
            }
            else
            {
                m_tail = nodeToAdd;
            }

            nodeAdded();
        }

        /**
         * Adds a new node before a specific node of the list.
         */
        template <typename T>
        void DoublyLinkedList<T>::addBefore(
            IDoublyLinkedListNodePtr<T> currNode,
            IDoublyLinkedListNodePtr<T> nodeToAdd)
        {
            validateNode(currNode);
            validateNode(nodeToAdd);

            nodeToAdd->unlinked();

            IDoublyLinkedListNodePtr<T> previousNode = currNode->previous();

            if (previousNode)
            {
                linkedNodes(previousNode, nodeToAdd);
            }
            else
            {
                m_head = nodeToAdd;
            }

            linkedNodes(nodeToAdd, currNode);

            nodeAdded();
        }

        /**
         * Removes the front node from the list.
         * Returns the removed node or null if the list is empty.
         */
        template <typename T>
        IDoublyLinkedListNodePtr<T> DoublyLinkedList<T>::removeFromFront()
        {
            if (!m_head)
            {
                assert(!m_tail && empty());
                return nullptr;
            }

            IDoublyLinkedListNodePtr<T> nodeToRemove = m_head;
            remove(nodeToRemove);

            return nodeToRemove;
        }

        /**
         * Removes the back node from the list.
         * Returns the removed node or null if the list is empty.
         */
        template <typename T>
        IDoublyLinkedListNodePtr<T> DoublyLinkedList<T>::removeFromBack()
        {
            if (!m_tail) {
                assert(!m_head && empty());
                return nullptr;
            }

            IDoublyLinkedListNodePtr<T> nodeToRemove = m_tail;

            remove(nodeToRemove);

            return nodeToRemove;
        }

        /**
         * Removes the a node from the list.
         */
        template <typename T>
        void DoublyLinkedList<T>::remove(IDoublyLinkedListNodePtr<T> nodeToRemove)
        {
            validateNode(nodeToRemove);

            IDoublyLinkedListNodePtr<T> previousNode = nodeToRemove->previous();
            IDoublyLinkedListNodePtr<T> nextNode = nodeToRemove->next();

            linkedNodes(previousNode, nextNode);

            if (!previousNode)
            {
                m_head = nextNode;
            }

            if (!nextNode)
            {
                m_tail = previousNode;
            }

            nodeRemoved(*nodeToRemove);
        }

        /**
         * Clears the list.
         */
        template <typename T>
        void DoublyLinkedList<T>::clear()
        {
            m_head = nullptr;
            m_tail = nullptr;
            m_size = 0;
        }

        /**
         * Gets an iterator of nodes.
         */
        template <typename T>
        base::IIteratorPtr<IDoublyLinkedListNodePtr<T>> DoublyLinkedList<T>::getIterator() const
        {
            return DoublyLinkedListNodeIterator<T>::make(m_head);
        }

        /**
         * Gets a reverse iterator of nodes.
         */
        template <typename T>
        base::IReverseIteratorPtr<IDoublyLinkedListNodePtr<T>> DoublyLinkedList<T>::getReverseIterator() const
        {
            return DoublyLinkedListNodeReverseIterator<T>::make(m_head);
        }

        /**
         * Gets an iterator of values of a list.
         */
        template <typename T>
        base::IIteratorPtr<T> DoublyLinkedList<T>::getValueIterator() const
        {
            return DoublyLinkedListNodeValueIterator<T>::make(*getIterator());
        }

        /**
         * Gets a reverse iterator of values of a list.
         */
        template <typename T>
        base::IReverseIteratorPtr<T> DoublyLinkedList<T>::getValueReverseIterator() const
        {
            return DoublyLinkedListNodeValueReverseIterator<T>::make(*getReverseIterator());
        }

        /**
         * Gets a specific node by index. Index: [0, 1, 2, ... , size -1]
         */
        template <typename T>
        IDoublyLinkedListNodePtr<T> DoublyLinkedList<T>::getNode(size_t index) const
        {
            if (index >= size())
            {
                std::string errorMessage = "The index: " + std::to_string(index) + " is out of range.";
                throw DoublyLinkedListException(errorMessage);
            }

            IDoublyLinkedListNodePtr<T> currNode = m_head;

            size_t currIndex = 0;

            while (currNode != nullptr)
            {
                if (currIndex == index)
                {
                    break;
                }

                ++currIndex;
                currNode = currNode->next();
            }

            return currNode;
        }

        /**
         * Validate a node.
         */
        template <typename T>
        void DoublyLinkedList<T>::validateNode(IDoublyLinkedListNodePtr<T> node) const
        {
            if (!node)
            {
                std::string errorMessage = "The node is not defined.";
                throw DoublyLinkedListException(errorMessage);
            }
        }

        /**
         * Linked nodes.
         */
        template <typename T>
        void DoublyLinkedList<T>::linkedNodes(IDoublyLinkedListNodePtr<T> left, IDoublyLinkedListNodePtr<T> right)
        {
            if (left != nullptr)
            {
                left->setNext(right);
            }

            if (right != nullptr)
            {
                right->setPrevious(left);
            }
        }

        /**
         * Node added.
         */
        template <typename T>
        void DoublyLinkedList<T>::nodeAdded()
        {
            ++m_size;
        }

        /**
         * Node removed.
         */
        template <typename T>
        void DoublyLinkedList<T>::nodeRemoved(IDoublyLinkedListNode<T>& node)
        {
            node.unlinked();
            --m_size;
        }
    }
}

#endif // I_DOUBLY_LINKED_LIST_H_920aca9a_f0e1_4a16_aa45_c65f5ef11267
