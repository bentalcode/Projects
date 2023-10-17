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
            static ILinkedListSharedPtr<T> Make();

            /**
             * Creates a new linked list from a node list.
             */
            static ILinkedListNodeSharedPtr<T> Make(ILinkedListNodeSharedPtr<T> head);

            /**
             * The LinkedList constructor.
             */
            LinkedList();

            /**
             * The LinkedList constructor with a list.
             */
            LinkedList(ILinkedListNodeSharedPtr<T> head);

            /**
             * The LinkedList destructor.
             */
            virtual ~LinkedList();

            /**
             * The Copy/move constructors.
             */
            LinkedList(const LinkedList&) = delete;
            LinkedList(LinkedList&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            LinkedList& operator=(const LinkedList&) = delete;
            LinkedList& operator=(LinkedList&&) = delete;

            /**
             * Gets the head node of the list.
             */
            virtual ILinkedListNodeSharedPtr<T> GetHead() const override;

            /**
             * Gets the tail node of the list.
             */
            virtual ILinkedListNodeSharedPtr<T> GetTail() const override;

            /**
             * Gets the Size of the list.
             */
            virtual size_t Size() const override;

            /**
             * Checks whether the list is Empty.
             */
            virtual bool Empty() const override;

            /**
             * Adds a new value to the front of the list.
             */
            virtual void AddToFront(const T& value) override;

            /**
             * Adds a new value to the back of the list.
             */
            virtual void AddToBack(const T& value) override;

            /**
             * Adds a new value after a specific node of the list.
             */
            virtual void AddAfter(
                ILinkedListNodeSharedPtr<T> currNode,
                const T& valueToAdd) override;

            /**
             * Adds a new node to the front of the list.
             */
            virtual void AddToFront(ILinkedListNodeSharedPtr<T> node) override;

            /**
              * Adds a new node to the back of the list.
              */
            virtual void AddToBack(ILinkedListNodeSharedPtr<T> node) override;

            /**
             * Adds a new node after a specific node of the list.
             */
            virtual void AddAfter(
                ILinkedListNodeSharedPtr<T> currNode,
                ILinkedListNodeSharedPtr<T> nodeToAdd) override;

            /**
             * Removes the front node from the list.
             * Returns the removed node or null if the list is Empty.
             */
            virtual ILinkedListNodeSharedPtr<T> RemoveFromFront() override;

            /**
             * Removes a node after a specific node of the list.
             */
            virtual void RemoveAfter(ILinkedListNodeSharedPtr<T> currNode) override;

            /**
             * Clears the list.
             */
            virtual void Clear() override;

            /**
            * Gets an iterator of nodes.
            */
            virtual base::IIteratorSharedPtr<ILinkedListNodeSharedPtr<T>> GetIterator() const override;

            /**
             * Gets an iterator of values of a list.
             */
            virtual base::IIteratorSharedPtr<T> GetValueIterator() const override;

            /**
             * Gets a specific node by index. Index: [0, 1, 2, ... , Size -1]
             */
            virtual ILinkedListNodeSharedPtr<T> GetNode(size_t index) const override;

        private:
            /**
             * Linked nodes.
             */
            void LinkedNodes(ILinkedListNodeSharedPtr<T> left, ILinkedListNodeSharedPtr<T> right);

            /**
             * Node added.
             */
            void NodeAdded();

            /**
             * Node removed.
             */
            void NodeRemoved(ILinkedListNode<T>& node);

            ILinkedListNodeSharedPtr<T> m_head;
            ILinkedListNodeSharedPtr<T> m_tail;
            size_t m_size;
        };

        template <typename T>
        using ILinkedListSharedPtr = std::shared_ptr<ILinkedList<T>>;

        /**
         * Creates a new doubly linked list.
         */
        template <typename T>
        ILinkedListSharedPtr<T> LinkedList<T>::Make()
        {
            return std::make_shared<LinkedList<T>>();
        }

        /**
         * Creates a new doubly linked list from a node list.
         */
        template <typename T>
        ILinkedListNodeSharedPtr<T> LinkedList<T>::Make(ILinkedListNodeSharedPtr<T> head)
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
        LinkedList<T>::LinkedList(ILinkedListNodeSharedPtr<T> head) :
            m_size(0)
        {
            ILinkedListNodeSharedPtr<T> currNode = head;

            while (currNode)
            {
                ILinkedListNodeSharedPtr<T> nextNode = currNode->Next();
                AddToBack(currNode);

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
        ILinkedListNodeSharedPtr<T> LinkedList<T>::GetHead() const
        {
            return m_head;
        }

        /**
         * Gets the tail node of the list.
         */
        template <typename T>
        ILinkedListNodeSharedPtr<T> LinkedList<T>::GetTail() const
        {
            return m_tail;
        }

        /**
         * Gets the Size of the list.
         */
        template <typename T>
        size_t LinkedList<T>::Size() const
        {
            return m_size;
        }

        /**
         * Checks whether the list is Empty.
         */
        template <typename T>
        bool LinkedList<T>::Empty() const
        {
            return m_size == 0;
        }

        /**
         * Adds a new value to the front of the list.
         */
        template <typename T>
        void LinkedList<T>::AddToFront(const T& value)
        {
            AddToFront(LinkedListNode<T>::Make(value));
        }

        /**
         * Adds a new value to the back of the list.
         */
        template <typename T>
        void LinkedList<T>::AddToBack(const T& value)
        {
            AddToBack(LinkedListNode<T>::Make(value));
        }

        /**
         * Adds a new value after a specific node of the list.
         */
        template <typename T>
        void LinkedList<T>::AddAfter(
                ILinkedListNodeSharedPtr<T> currNode,
                const T& valueToAdd)
        {
            AddAfter(currNode, LinkedListNode<T>::Make(valueToAdd));
        }

        /**
         * Adds a new node to the front of the list.
         */
        template <typename T>
        void LinkedList<T>::AddToFront(ILinkedListNodeSharedPtr<T> node)
        {
            base::SmartPointers::validate(node);

            node->Unlinked();

            if (!m_head)
            {
                assert(!m_tail && Empty());
                m_head = node;
                m_tail = node;
            }
            else
            {
                LinkedNodes(node, m_head);
                m_head = node;
            }

            NodeAdded();
        }

        /**
         * Adds a new node to the back of the list.
         */
        template <typename T>
        void LinkedList<T>::AddToBack(ILinkedListNodeSharedPtr<T> node)
        {
            base::SmartPointers::validate(node);

            node->Unlinked();

            if (!m_tail)
            {
                assert(!m_head && Empty());
                m_head = node;
                m_tail = node;
            }
            else
            {
                LinkedNodes(m_tail, node);
                m_tail = node;
            }

            NodeAdded();
        }

        /**
         * Adds a new node after a specific node of the list.
         */
        template <typename T>
        void LinkedList<T>::AddAfter(
                ILinkedListNodeSharedPtr<T> currNode,
                ILinkedListNodeSharedPtr<T> nodeToAdd)
        {
            base::SmartPointers::validate(currNode);
            base::SmartPointers::validate(nodeToAdd);

            nodeToAdd->Unlinked();

            ILinkedListNodeSharedPtr<T> nextNode = currNode->Next();

            LinkedNodes(currNode, nodeToAdd);

            if (nextNode)
            {
                LinkedNodes(nodeToAdd, nextNode);
            }
            else
            {
                m_tail = nodeToAdd;
            }

            NodeAdded();
        }

        /**
         * Removes the front node from the list.
         * Returns the removed node or null if the list is Empty.
         */
        template <typename T>
        ILinkedListNodeSharedPtr<T> LinkedList<T>::RemoveFromFront()
        {
            if (!m_head)
            {
                assert(!m_tail && Empty());
                return nullptr;
            }

            ILinkedListNodeSharedPtr<T> nodeToRemove = m_head;
            ILinkedListNodeSharedPtr<T> nextNode = m_head->Next();

            m_head = nextNode;

            if (!nextNode) {
                m_tail = nullptr;
            }

            NodeRemoved(*nodeToRemove);

            return nodeToRemove;
        }

        /**
         * Removes a node after a specific node of the list.
         */
        template <typename T>
        void LinkedList<T>::RemoveAfter(ILinkedListNodeSharedPtr<T> currNode)
        {
            base::SmartPointers::validate(currNode);

            ILinkedListNodeSharedPtr<T> nodeToRemove = currNode->Next();

            if (nodeToRemove == nullptr)
            {
                return;
            }

            ILinkedListNodeSharedPtr<T> nextNode = nodeToRemove->Next();

            LinkedNodes(currNode, nextNode);

            if (!nextNode) {
                m_tail = currNode;
            }

            NodeRemoved(*nodeToRemove);
        }

        /**
         * Clears the list.
         */
        template <typename T>
        void LinkedList<T>::Clear()
        {
            m_head = nullptr;
            m_tail = nullptr;
            m_size = 0;
        }

        /**
         * Gets an iterator of nodes.
         */
        template <typename T>
        base::IIteratorSharedPtr<ILinkedListNodeSharedPtr<T>> LinkedList<T>::GetIterator() const
        {
            return LinkedListNodeIterator<T>::Make(m_head);
        }

        /**
         * Gets an iterator of values of a list.
         */
        template <typename T>
        base::IIteratorSharedPtr<T> LinkedList<T>::GetValueIterator() const
        {
            return LinkedListNodeValueIterator<T>::Make(GetIterator());
        }

        /**
         * Gets a specific node by index. Index: [0, 1, 2, ... , Size -1]
         */
        template <typename T>
        ILinkedListNodeSharedPtr<T> LinkedList<T>::GetNode(size_t index) const
        {
            if (index >= Size())
            {
                std::string errorMessage = "The index: " + std::to_string(index) + " is out Of range.";
                throw LinkedListException(errorMessage);
            }

            ILinkedListNodeSharedPtr<T> currNode = m_head;

            size_t currIndex = 0;

            while (currNode != nullptr)
            {
                assert(currIndex < Size());

                if (currIndex == index)
                {
                    return currNode;
                }

                ++currIndex;
                currNode = currNode->Next();
            }

            return nullptr;
        }

        /**
         * Linked nodes.
         */
        template <typename T>
        void LinkedList<T>::LinkedNodes(ILinkedListNodeSharedPtr<T> left, ILinkedListNodeSharedPtr<T> right)
        {
            if (left != nullptr)
            {
                left->SetNext(right);
            }
        }

        /**
         * Node added.
         */
        template <typename T>
        void LinkedList<T>::NodeAdded()
        {
            ++m_size;
        }

        /**
         * Node removed.
         */
        template <typename T>
        void LinkedList<T>::NodeRemoved(ILinkedListNode<T>& node)
        {
            node.Unlinked();
            --m_size;
        }
    }
}

#endif // I_LINKED_LIST_H_e0712efd_df12_4186_8cf2_d26117c5a513
