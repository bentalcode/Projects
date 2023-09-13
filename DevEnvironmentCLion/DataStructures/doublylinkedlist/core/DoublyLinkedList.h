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
        template <typename T>
        class DoublyLinkedList final : public IDoublyLinkedList<T>
        {
        public:
            /**
             * Creates a new doubly linked list.
             */
            static IDoublyLinkedListSharedPtr<T> make();

            /**
             * Creates a new doubly linked list from a node list.
             */
            static IDoublyLinkedListNodeSharedPtr<T> make(IDoublyLinkedListNodeSharedPtr<T> head);

            /**
             * The DoublyLinkedList constructor.
             */
            DoublyLinkedList();

            /**
             * The DoublyLinkedList constructor with a list.
             */
            DoublyLinkedList(IDoublyLinkedListNodeSharedPtr<T> head);

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
            virtual IDoublyLinkedListNodeSharedPtr<T> getHead() const override;

            /**
             * Gets the tail node of the list.
             */
            virtual IDoublyLinkedListNodeSharedPtr<T> getTail() const override;

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
                    IDoublyLinkedListNodeSharedPtr<T> currNode,
                    const T& valueToAdd) override;

            /**
             * Adds a new value before a specific node of the list.
             */
            virtual void addBefore(
                    IDoublyLinkedListNodeSharedPtr<T> currNode,
                    const T& valueToAdd) override;

            /**
             * Adds a new node to the front of the list.
             */
            virtual void addToFront(IDoublyLinkedListNodeSharedPtr<T> node) override;

            /**
             * Adds a new node to the back of the list.
             */
            virtual void addToBack(IDoublyLinkedListNodeSharedPtr<T> node) override;

            /**
             * Adds a new node after a specific node of the list.
             */
            virtual void addAfter(
                    IDoublyLinkedListNodeSharedPtr<T> currNode,
                    IDoublyLinkedListNodeSharedPtr<T> nodeToAdd) override;

            /**
             * Adds a new node before a specific node of the list.
             */
            virtual void addBefore(
                    IDoublyLinkedListNodeSharedPtr<T> currNode,
                    IDoublyLinkedListNodeSharedPtr<T> nodeToAdd) override;

            /**
             * Removes the front node from the list.
             * Returns the removed node or null if the list is empty.
             */
            virtual IDoublyLinkedListNodeSharedPtr<T> removeFromFront() override;

            /**
             * Removes the back node from the list.
             * Returns the removed node or null if the list is empty.
             */
            virtual IDoublyLinkedListNodeSharedPtr<T> removeFromBack() override;

            /**
             * Removes the a node from the list.
             */
            virtual void remove(IDoublyLinkedListNodeSharedPtr<T> nodeToRemove) override;

            /**
             * Clears the list.
             */
            virtual void clear() override;

            /**
             * Gets an iterator of nodes.
             */
            virtual base::IIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<T>> getIterator() const override;

            /**
             * Gets a reverse iterator of nodes.
             */
            virtual base::IReverseIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<T>> getReverseIterator() const override;
            
            /**
             * Gets an iterator of values of a list.
             */
            virtual base::IIteratorSharedPtr<T> getValueIterator() const override;

            /**
             * Gets a reverse iterator of values of a list.
             */
            virtual base::IReverseIteratorSharedPtr<T> getValueReverseIterator() const override;

            /**
             * Gets a specific node by index. Index: [0, 1, 2, ... , size -1]
             */
            virtual IDoublyLinkedListNodeSharedPtr<T> getNode(size_t index) const override;

        private:
            /**
             * Linked nodes.
             */
            void linkedNodes(IDoublyLinkedListNodeSharedPtr<T> left, IDoublyLinkedListNodeSharedPtr<T> right);

            /**
             * Node added.
             */
            void nodeAdded();

            /**
             * Node removed.
             */
            void nodeRemoved(IDoublyLinkedListNode<T>& node);

            IDoublyLinkedListNodeSharedPtr<T> m_head;
            IDoublyLinkedListNodeSharedPtr<T> m_tail;
            size_t m_size;
        };

        template <typename T>
        using IDoublyLinkedListSharedPtr = std::shared_ptr<IDoublyLinkedList<T>>;

        /**
         * Creates a new doubly linked list.
         */
        template <typename T>
        IDoublyLinkedListSharedPtr<T> DoublyLinkedList<T>::make()
        {
            return std::make_shared<DoublyLinkedList<T>>();
        }

        /**
         * Creates a new doubly linked list from a node list.
         */
        template <typename T>
        IDoublyLinkedListNodeSharedPtr<T> DoublyLinkedList<T>::make(IDoublyLinkedListNodeSharedPtr<T> head)
        {
            return std::make_shared<DoublyLinkedListNode<T>>(head);
        }

        /**
         * The DoublyLinkedList constructor.
         */
        template <typename T>
        DoublyLinkedList<T>::DoublyLinkedList() :
            m_size(0)
        {
        }

        /**
         * The DoublyLinkedList constructor with a node list.
         */
        template <typename T>
        DoublyLinkedList<T>::DoublyLinkedList(IDoublyLinkedListNodeSharedPtr<T> head) :
            m_size(0)
        {
            IDoublyLinkedListNodeSharedPtr<T> currNode = head;

            while (currNode)
            {
                IDoublyLinkedListNodeSharedPtr<T> nextNode = currNode->next();
                addToBack(currNode);

                currNode = nextNode;
            }
        }

        /**
         * The DoublyLinkedList destructor.
         */
        template <typename T>
        DoublyLinkedList<T>::~DoublyLinkedList()
        {
        }

        /**
         * Gets the head node of the list.
         */
        template <typename T>
        IDoublyLinkedListNodeSharedPtr<T> DoublyLinkedList<T>::getHead() const
        {
            return m_head;
        }

        /**
         * Gets the tail node of the list.
         */
        template <typename T>
        IDoublyLinkedListNodeSharedPtr<T> DoublyLinkedList<T>::getTail() const
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
                IDoublyLinkedListNodeSharedPtr<T> currNode,
                const T& valueToAdd)
        {
            addAfter(currNode, DoublyLinkedListNode<T>::make(valueToAdd));
        }

        /**
         * Adds a new value before a specific node of the list.
         */
        template <typename T>
        void DoublyLinkedList<T>::addBefore(
                IDoublyLinkedListNodeSharedPtr<T> currNode,
                const T& valueToAdd)
        {
            addBefore(currNode, DoublyLinkedListNode<T>::make(valueToAdd));
        }

        /**
         * Adds a new node to the front of the list.
         */
        template <typename T>
        void DoublyLinkedList<T>::addToFront(IDoublyLinkedListNodeSharedPtr<T> node)
        {
            base::SmartPointers::validate(node);

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
        void DoublyLinkedList<T>::addToBack(IDoublyLinkedListNodeSharedPtr<T> node)
        {
            base::SmartPointers::validate(node);

            node->unlinked();

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
                IDoublyLinkedListNodeSharedPtr<T> currNode,
                IDoublyLinkedListNodeSharedPtr<T> nodeToAdd)
        {
            base::SmartPointers::validate(currNode);
            base::SmartPointers::validate(nodeToAdd);

            nodeToAdd->unlinked();

            IDoublyLinkedListNodeSharedPtr<T> nextNode = currNode->next();

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
                IDoublyLinkedListNodeSharedPtr<T> currNode,
                IDoublyLinkedListNodeSharedPtr<T> nodeToAdd)
        {
            base::SmartPointers::validate(currNode);
            base::SmartPointers::validate(nodeToAdd);

            nodeToAdd->unlinked();

            IDoublyLinkedListNodeSharedPtr<T> previousNode = currNode->previous();

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
        IDoublyLinkedListNodeSharedPtr<T> DoublyLinkedList<T>::removeFromFront()
        {
            if (!m_head)
            {
                assert(!m_tail && empty());
                return nullptr;
            }

            IDoublyLinkedListNodeSharedPtr<T> nodeToRemove = m_head;
            remove(nodeToRemove);

            return nodeToRemove;
        }

        /**
         * Removes the back node from the list.
         * Returns the removed node or null if the list is empty.
         */
        template <typename T>
        IDoublyLinkedListNodeSharedPtr<T> DoublyLinkedList<T>::removeFromBack()
        {
            if (!m_tail) {
                assert(!m_head && empty());
                return nullptr;
            }

            IDoublyLinkedListNodeSharedPtr<T> nodeToRemove = m_tail;
            remove(nodeToRemove);

            return nodeToRemove;
        }

        /**
         * Removes the a node from the list.
         */
        template <typename T>
        void DoublyLinkedList<T>::remove(IDoublyLinkedListNodeSharedPtr<T> nodeToRemove)
        {
            base::SmartPointers::validate(nodeToRemove);

            IDoublyLinkedListNodeSharedPtr<T> previousNode = nodeToRemove->previous();
            IDoublyLinkedListNodeSharedPtr<T> nextNode = nodeToRemove->next();

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
        base::IIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<T>> DoublyLinkedList<T>::getIterator() const
        {
            return DoublyLinkedListNodeIterator<T>::make(m_head);
        }

        /**
         * Gets a reverse iterator of nodes.
         */
        template <typename T>
        base::IReverseIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<T>> DoublyLinkedList<T>::getReverseIterator() const
        {
            return DoublyLinkedListNodeReverseIterator<T>::make(m_tail);
        }

        /**
         * Gets an iterator of values of a list.
         */
        template <typename T>
        base::IIteratorSharedPtr<T> DoublyLinkedList<T>::getValueIterator() const
        {
            return DoublyLinkedListNodeValueIterator<T>::make(getIterator());
        }

        /**
         * Gets a reverse iterator of values of a list.
         */
        template <typename T>
        base::IReverseIteratorSharedPtr<T> DoublyLinkedList<T>::getValueReverseIterator() const
        {
            return DoublyLinkedListNodeValueReverseIterator<T>::make(getReverseIterator());
        }

        /**
         * Gets a specific node by index. Index: [0, 1, 2, ... , size -1]
         */
        template <typename T>
        IDoublyLinkedListNodeSharedPtr<T> DoublyLinkedList<T>::getNode(size_t index) const
        {
            if (index >= size())
            {
                std::string errorMessage = "The index: " + std::to_string(index) + " is out of range.";
                throw DoublyLinkedListException(errorMessage);
            }

            IDoublyLinkedListNodeSharedPtr<T> currNode = m_head;

            size_t currIndex = 0;

            while (currNode != nullptr)
            {
                assert(currIndex < size());

                if (currIndex == index)
                {
                    return currNode;
                }

                ++currIndex;
                currNode = currNode->next();
            }

            return nullptr;
        }

        /**
         * Linked nodes.
         */
        template <typename T>
        void DoublyLinkedList<T>::linkedNodes(IDoublyLinkedListNodeSharedPtr<T> left, IDoublyLinkedListNodeSharedPtr<T> right)
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
