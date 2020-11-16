#ifndef I_LINKED_LIST_H_e0712efd_df12_4186_8cf2_d26117c5a513
#define I_LINKED_LIST_H_e0712efd_df12_4186_8cf2_d26117c5a513

#include "ILinkedList.h"
#include "LinkedListNode.h"
#include "LinkedListNodeIterator.h"
#include "LinkedListNodeValueIterator.h"
#include "SmartPointers.h"
#include "LinkedListException.h"

namespace datastructures {
    namespace linkedlist {

        /**
         * The LinkedList class implements a linked list.
         */
        template <typename T>
        class LinkedList final : public ILinkedList<T>
        {
        public:
            /**
             * Creates a new linked list.
             */
            static ILinkedListPtr<T> make();

            /**
             * Creates a new linked list from a node list.
             */
            static ILinkedListNodePtr<T> make(ILinkedListNodePtr<T> head);

            /**
             * The LinkedList constructor.
             */
            LinkedList();

            /**
             * The LinkedList constructor with a list.
             */
            LinkedList(ILinkedListNodePtr<T> head);

            /**
             * The LinkedList destructor.
             */
            virtual ~LinkedList();

            /**
             * The copy/move constructors.
             */
            LinkedList(const LinkedList&) = delete;
            LinkedList(LinkedList&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            LinkedList& operator=(const LinkedList&) = delete;
            LinkedList& operator=(LinkedList&&) = delete;

            /**
             * Gets the head node of the list.
             */
            virtual ILinkedListNodePtr<T> getHead() const override;

            /**
             * Gets the tail node of the list.
             */
            virtual ILinkedListNodePtr<T> getTail() const override;

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
                ILinkedListNodePtr<T> currNode,
                const T& valueToAdd) override;

            /**
             * Adds a new node to the front of the list.
             */
            virtual void addToFront(ILinkedListNodePtr<T> node) override;

            /**
              * Adds a new node to the back of the list.
              */
            virtual void addToBack(ILinkedListNodePtr<T> node) override;

            /**
             * Adds a new node after a specific node of the list.
             */
            virtual void addAfter(
                ILinkedListNodePtr<T> currNode,
                ILinkedListNodePtr<T> nodeToAdd) override;

            /**
             * Removes the front node from the list.
             * Returns the removed node or null if the list is empty.
             */
            virtual ILinkedListNodePtr<T> removeFromFront() override;

            /**
             * Removes a node after a specific node of the list.
             */
            virtual void removeAfter(ILinkedListNodePtr<T> currNode) override;

            /**
             * Clears the list.
             */
            virtual void clear() override;

            /**
            * Gets an iterator of nodes.
            */
            virtual base::IIteratorPtr<ILinkedListNodePtr<T>> getIterator() const override;

            /**
             * Gets an iterator of values of a list.
             */
            virtual base::IIteratorPtr<T> getValueIterator() const override;

            /**
             * Gets a specific node by index. Index: [0, 1, 2, ... , size -1]
             */
            virtual ILinkedListNodePtr<T> getNode(size_t index) const override;

        private:
            /**
             * Linked nodes.
             */
            void linkedNodes(ILinkedListNodePtr<T> left, ILinkedListNodePtr<T> right);

            /**
             * Node added.
             */
            void nodeAdded();

            /**
             * Node removed.
             */
            void nodeRemoved(ILinkedListNode<T>& node);

            ILinkedListNodePtr<T> m_head;
            ILinkedListNodePtr<T> m_tail;
            size_t m_size;
        };

        template <typename T>
        using ILinkedListPtr = std::shared_ptr<ILinkedList<T>>;

        /**
         * Creates a new doubly linked list.
         */
        template <typename T>
        ILinkedListPtr<T> LinkedList<T>::make()
        {
            return std::make_shared<LinkedList<T>>();
        }

        /**
         * Creates a new doubly linked list from a node list.
         */
        template <typename T>
        ILinkedListNodePtr<T> LinkedList<T>::make(ILinkedListNodePtr<T> head)
        {
            return std::make_shared<LinkedListNode<T>>(head);
        }

        /**
         * The LinkedList constructor.
         */
        template <typename T>
        LinkedList<T>::LinkedList() :
            m_size(0)
        {
        }

        /**
         * The LinkedList constructor with a node list.
         */
        template <typename T>
        LinkedList<T>::LinkedList(ILinkedListNodePtr<T> head) :
            m_size(0)
        {
            ILinkedListNodePtr<T> currNode = head;

            while (currNode)
            {
                ILinkedListNodePtr<T> nextNode = currNode->next();
                addToBack(currNode);

                currNode = nextNode;
            }
        }

        /**
         * The LinkedList destructor.
         */
        template <typename T>
        LinkedList<T>::~LinkedList()
        {
        }

        /**
         * Gets the head node of the list.
         */
        template <typename T>
        ILinkedListNodePtr<T> LinkedList<T>::getHead() const
        {
            return m_head;
        }

        /**
         * Gets the tail node of the list.
         */
        template <typename T>
        ILinkedListNodePtr<T> LinkedList<T>::getTail() const
        {
            return m_tail;
        }

        /**
         * Gets the size of the list.
         */
        template <typename T>
        size_t LinkedList<T>::size() const
        {
            return m_size;
        }

        /**
         * Checks whether the list is empty.
         */
        template <typename T>
        bool LinkedList<T>::empty() const
        {
            return m_size == 0;
        }

        /**
         * Adds a new value to the front of the list.
         */
        template <typename T>
        void LinkedList<T>::addToFront(const T& value)
        {
            addToFront(LinkedListNode<T>::make(value));
        }

        /**
         * Adds a new value to the back of the list.
         */
        template <typename T>
        void LinkedList<T>::addToBack(const T& value)
        {
            addToBack(LinkedListNode<T>::make(value));
        }

        /**
         * Adds a new value after a specific node of the list.
         */
        template <typename T>
        void LinkedList<T>::addAfter(
            ILinkedListNodePtr<T> currNode,
            const T& valueToAdd)
        {
            addAfter(currNode, LinkedListNode<T>::make(valueToAdd));
        }

        /**
         * Adds a new node to the front of the list.
         */
        template <typename T>
        void LinkedList<T>::addToFront(ILinkedListNodePtr<T> node)
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
        void LinkedList<T>::addToBack(ILinkedListNodePtr<T> node)
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
        void LinkedList<T>::addAfter(
            ILinkedListNodePtr<T> currNode,
            ILinkedListNodePtr<T> nodeToAdd)
        {
            base::SmartPointers::validate(currNode);
            base::SmartPointers::validate(nodeToAdd);

            nodeToAdd->unlinked();

            ILinkedListNodePtr<T> nextNode = currNode->next();

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
         * Removes the front node from the list.
         * Returns the removed node or null if the list is empty.
         */
        template <typename T>
        ILinkedListNodePtr<T> LinkedList<T>::removeFromFront()
        {
            if (!m_head)
            {
                assert(!m_tail && empty());
                return nullptr;
            }

            ILinkedListNodePtr<T> nodeToRemove = m_head;
            ILinkedListNodePtr<T> nextNode = m_head->next();

            m_head = nextNode;

            if (!nextNode) {
                m_tail = nullptr;
            }

            nodeRemoved(*nodeToRemove);

            return nodeToRemove;
        }

        /**
         * Removes a node after a specific node of the list.
         */
        template <typename T>
        void LinkedList<T>::removeAfter(ILinkedListNodePtr<T> currNode)
        {
            base::SmartPointers::validate(currNode);

            ILinkedListNodePtr<T> nodeToRemove = currNode->next();

            if (nodeToRemove == nullptr)
            {
                return;
            }

            ILinkedListNodePtr<T> nextNode = nodeToRemove->next();

            linkedNodes(currNode, nextNode);

            if (!nextNode) {
                m_tail = currNode;
            }

            nodeRemoved(*nodeToRemove);
        }

        /**
         * Clears the list.
         */
        template <typename T>
        void LinkedList<T>::clear()
        {
            m_head = nullptr;
            m_tail = nullptr;
            m_size = 0;
        }

        /**
         * Gets an iterator of nodes.
         */
        template <typename T>
        base::IIteratorPtr<ILinkedListNodePtr<T>> LinkedList<T>::getIterator() const
        {
            return LinkedListNodeIterator<T>::make(m_head);
        }

        /**
         * Gets an iterator of values of a list.
         */
        template <typename T>
        base::IIteratorPtr<T> LinkedList<T>::getValueIterator() const
        {
            return LinkedListNodeValueIterator<T>::make(getIterator());
        }

        /**
         * Gets a specific node by index. Index: [0, 1, 2, ... , size -1]
         */
        template <typename T>
        ILinkedListNodePtr<T> LinkedList<T>::getNode(size_t index) const
        {
            if (index >= size())
            {
                std::string errorMessage = "The index: " + std::to_string(index) + " is out of range.";
                throw LinkedListException(errorMessage);
            }

            ILinkedListNodePtr<T> currNode = m_head;

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
        void LinkedList<T>::linkedNodes(ILinkedListNodePtr<T> left, ILinkedListNodePtr<T> right)
        {
            if (left != nullptr)
            {
                left->setNext(right);
            }
        }

        /**
         * Node added.
         */
        template <typename T>
        void LinkedList<T>::nodeAdded()
        {
            ++m_size;
        }

        /**
         * Node removed.
         */
        template <typename T>
        void LinkedList<T>::nodeRemoved(ILinkedListNode<T>& node)
        {
            node.unlinked();
            --m_size;
        }
    }
}

#endif // I_LINKED_LIST_H_e0712efd_df12_4186_8cf2_d26117c5a513
