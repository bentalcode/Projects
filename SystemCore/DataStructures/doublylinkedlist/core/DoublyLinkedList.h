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
            static IDoublyLinkedListSharedPtr<T> Make();

            /**
             * Creates a new doubly linked list from a node list.
             */
            static IDoublyLinkedListNodeSharedPtr<T> Make(IDoublyLinkedListNodeSharedPtr<T> head);

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
             * The Copy/move constructors.
             */
            DoublyLinkedList(const DoublyLinkedList&) = delete;
            DoublyLinkedList(DoublyLinkedList&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;
            DoublyLinkedList& operator=(DoublyLinkedList&&) = delete;

            /**
             * Gets the head node of the list.
             */
            virtual IDoublyLinkedListNodeSharedPtr<T> GetHead() const override;

            /**
             * Gets the tail node of the list.
             */
            virtual IDoublyLinkedListNodeSharedPtr<T> GetTail() const override;

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
                IDoublyLinkedListNodeSharedPtr<T> currNode,
                const T& valueToAdd) override;

            /**
             * Adds a new value before a specific node of the list.
             */
            virtual void AddBefore(
                IDoublyLinkedListNodeSharedPtr<T> currNode,
                const T& valueToAdd) override;

            /**
             * Adds a new node to the front of the list.
             */
            virtual void AddToFront(IDoublyLinkedListNodeSharedPtr<T> node) override;

            /**
             * Adds a new node to the back of the list.
             */
            virtual void AddToBack(IDoublyLinkedListNodeSharedPtr<T> node) override;

            /**
             * Adds a new node after a specific node of the list.
             */
            virtual void AddAfter(
                IDoublyLinkedListNodeSharedPtr<T> currNode,
                IDoublyLinkedListNodeSharedPtr<T> nodeToAdd) override;

            /**
             * Adds a new node before a specific node of the list.
             */
            virtual void AddBefore(
                IDoublyLinkedListNodeSharedPtr<T> currNode,
                IDoublyLinkedListNodeSharedPtr<T> nodeToAdd) override;

            /**
             * Removes the front node from the list.
             * Returns the removed node or null if the list is Empty.
             */
            virtual IDoublyLinkedListNodeSharedPtr<T> RemoveFromFront() override;

            /**
             * Removes the back node from the list.
             * Returns the removed node or null if the list is Empty.
             */
            virtual IDoublyLinkedListNodeSharedPtr<T> RemoveFromBack() override;

            /**
             * Removes the a node from the list.
             */
            virtual void Remove(IDoublyLinkedListNodeSharedPtr<T> nodeToRemove) override;

            /**
             * Clears the list.
             */
            virtual void Clear() override;

            /**
             * Gets an iterator of nodes.
             */
            virtual base::IIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<T>> GetIterator() const override;

            /**
             * Gets a reverse iterator of nodes.
             */
            virtual base::IReverseIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<T>> GetReverseIterator() const override;
            
            /**
             * Gets an iterator of values of a list.
             */
            virtual base::IIteratorSharedPtr<T> GetValueIterator() const override;

            /**
             * Gets a reverse iterator of values of a list.
             */
            virtual base::IReverseIteratorSharedPtr<T> GetValueReverseIterator() const override;

            /**
             * Gets a specific node by index. Index: [0, 1, 2, ... , Size -1]
             */
            virtual IDoublyLinkedListNodeSharedPtr<T> GetNode(size_t index) const override;

        private:
            /**
             * Linked nodes.
             */
            void linkedNodes(IDoublyLinkedListNodeSharedPtr<T> left, IDoublyLinkedListNodeSharedPtr<T> right);

            /**
             * Node added.
             */
            void NodeAdded();

            /**
             * Node removed.
             */
            void NodeRemoved(IDoublyLinkedListNode<T>& node);

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
        IDoublyLinkedListSharedPtr<T> DoublyLinkedList<T>::Make()
        {
            return std::make_shared<DoublyLinkedList<T>>();
        }

        /**
         * Creates a new doubly linked list from a node list.
         */
        template <typename T>
        IDoublyLinkedListNodeSharedPtr<T> DoublyLinkedList<T>::Make(IDoublyLinkedListNodeSharedPtr<T> head)
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
                IDoublyLinkedListNodeSharedPtr<T> nextNode = currNode->Next();
                AddToBack(currNode);

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
        IDoublyLinkedListNodeSharedPtr<T> DoublyLinkedList<T>::GetHead() const
        {
            return m_head;
        }

        /**
         * Gets the tail node of the list.
         */
        template <typename T>
        IDoublyLinkedListNodeSharedPtr<T> DoublyLinkedList<T>::GetTail() const
        {
            return m_tail;
        }

        /**
         * Gets the Size of the list.
         */
        template <typename T>
        size_t DoublyLinkedList<T>::Size() const
        {
            return m_size;
        }

        /**
         * Checks whether the list is Empty.
         */
        template <typename T>
        bool DoublyLinkedList<T>::Empty() const
        {
            return m_size == 0;
        }

        /**
         * Adds a new value to the front of the list.
         */
        template <typename T>
        void DoublyLinkedList<T>::AddToFront(const T& value)
        {
            AddToFront(DoublyLinkedListNode<T>::Make(value));
        }

        /**
         * Adds a new value to the back of the list.
         */
        template <typename T>
        void DoublyLinkedList<T>::AddToBack(const T& value)
        {
            AddToBack(DoublyLinkedListNode<T>::Make(value));
        }

        /**
         * Adds a new value after a specific node of the list.
         */
        template <typename T>
        void DoublyLinkedList<T>::AddAfter(
                IDoublyLinkedListNodeSharedPtr<T> currNode,
                const T& valueToAdd)
        {
            AddAfter(currNode, DoublyLinkedListNode<T>::Make(valueToAdd));
        }

        /**
         * Adds a new value before a specific node of the list.
         */
        template <typename T>
        void DoublyLinkedList<T>::AddBefore(
                IDoublyLinkedListNodeSharedPtr<T> currNode,
                const T& valueToAdd)
        {
            AddBefore(currNode, DoublyLinkedListNode<T>::Make(valueToAdd));
        }

        /**
         * Adds a new node to the front of the list.
         */
        template <typename T>
        void DoublyLinkedList<T>::AddToFront(IDoublyLinkedListNodeSharedPtr<T> node)
        {
            base::SmartPointers::Validate<IDoublyLinkedListNode>(node);

            node->Unlinked();

            if (!m_head)
            {
                assert(!m_tail && Empty());
                m_head = node;
                m_tail = node;
            }
            else
            {
                linkedNodes(node, m_head);
                m_head = node;
            }

            NodeAdded();
        }

        /**
         * Adds a new node to the back of the list.
         */
        template <typename T>
        void DoublyLinkedList<T>::AddToBack(IDoublyLinkedListNodeSharedPtr<T> node)
        {
            base::SmartPointers::Validate<IDoublyLinkedListNode>(node);

            node->Unlinked();

            if (!m_tail)
            {
                assert(!m_head && Empty());
                m_head = node;
                m_tail = node;
            }
            else
            {
                linkedNodes(m_tail, node);
                m_tail = node;
            }

            NodeAdded();
        }

        /**
         * Adds a new node after a specific node of the list.
         */
        template <typename T>
        void DoublyLinkedList<T>::AddAfter(
            IDoublyLinkedListNodeSharedPtr<T> currNode,
            IDoublyLinkedListNodeSharedPtr<T> nodeToAdd)
        {
            base::SmartPointers::Validate<IDoublyLinkedListNode>(currNode);
            base::SmartPointers::Validate<IDoublyLinkedListNode>(nodeToAdd);

            nodeToAdd->Unlinked();

            IDoublyLinkedListNodeSharedPtr<T> nextNode = currNode->Next();

            linkedNodes(currNode, nodeToAdd);

            if (nextNode)
            {
                linkedNodes(nodeToAdd, nextNode);
            }
            else
            {
                m_tail = nodeToAdd;
            }

            NodeAdded();
        }

        /**
         * Adds a new node before a specific node of the list.
         */
        template <typename T>
        void DoublyLinkedList<T>::AddBefore(
            IDoublyLinkedListNodeSharedPtr<T> currNode,
            IDoublyLinkedListNodeSharedPtr<T> nodeToAdd)
        {
            base::SmartPointers::Validate<IDoublyLinkedListNode>(currNode);
            base::SmartPointers::Validate<IDoublyLinkedListNode>(nodeToAdd);

            nodeToAdd->Unlinked();

            IDoublyLinkedListNodeSharedPtr<T> previousNode = currNode->Previous();

            if (previousNode)
            {
                linkedNodes(previousNode, nodeToAdd);
            }
            else
            {
                m_head = nodeToAdd;
            }

            linkedNodes(nodeToAdd, currNode);

            NodeAdded();
        }

        /**
         * Removes the front node from the list.
         * Returns the removed node or null if the list is Empty.
         */
        template <typename T>
        IDoublyLinkedListNodeSharedPtr<T> DoublyLinkedList<T>::RemoveFromFront()
        {
            if (!m_head)
            {
                assert(!m_tail && Empty());
                return nullptr;
            }

            IDoublyLinkedListNodeSharedPtr<T> nodeToRemove = m_head;
            Remove(nodeToRemove);

            return nodeToRemove;
        }

        /**
         * Removes the back node from the list.
         * Returns the removed node or null if the list is Empty.
         */
        template <typename T>
        IDoublyLinkedListNodeSharedPtr<T> DoublyLinkedList<T>::RemoveFromBack()
        {
            if (!m_tail) {
                assert(!m_head && Empty());
                return nullptr;
            }

            IDoublyLinkedListNodeSharedPtr<T> nodeToRemove = m_tail;
            Remove(nodeToRemove);

            return nodeToRemove;
        }

        /**
         * Removes the a node from the list.
         */
        template <typename T>
        void DoublyLinkedList<T>::Remove(IDoublyLinkedListNodeSharedPtr<T> nodeToRemove)
        {
            base::SmartPointers::Validate<IDoublyLinkedListNode>(nodeToRemove);

            IDoublyLinkedListNodeSharedPtr<T> previousNode = nodeToRemove->Previous();
            IDoublyLinkedListNodeSharedPtr<T> nextNode = nodeToRemove->Next();

            linkedNodes(previousNode, nextNode);

            if (!previousNode)
            {
                m_head = nextNode;
            }

            if (!nextNode)
            {
                m_tail = previousNode;
            }

            NodeRemoved(*nodeToRemove);
        }

        /**
         * Clears the list.
         */
        template <typename T>
        void DoublyLinkedList<T>::Clear()
        {
            m_head = nullptr;
            m_tail = nullptr;
            m_size = 0;
        }

        /**
         * Gets an iterator of nodes.
         */
        template <typename T>
        base::IIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<T>> DoublyLinkedList<T>::GetIterator() const
        {
            return DoublyLinkedListNodeIterator<T>::Make(m_head);
        }

        /**
         * Gets a reverse iterator of nodes.
         */
        template <typename T>
        base::IReverseIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<T>> DoublyLinkedList<T>::GetReverseIterator() const
        {
            return DoublyLinkedListNodeReverseIterator<T>::Make(m_tail);
        }

        /**
         * Gets an iterator of values of a list.
         */
        template <typename T>
        base::IIteratorSharedPtr<T> DoublyLinkedList<T>::GetValueIterator() const
        {
            return DoublyLinkedListNodeValueIterator<T>::Make(GetIterator());
        }

        /**
         * Gets a reverse iterator of values of a list.
         */
        template <typename T>
        base::IReverseIteratorSharedPtr<T> DoublyLinkedList<T>::GetValueReverseIterator() const
        {
            return DoublyLinkedListNodeValueReverseIterator<T>::Make(GetReverseIterator());
        }

        /**
         * Gets a specific node by index. Index: [0, 1, 2, ... , Size -1]
         */
        template <typename T>
        IDoublyLinkedListNodeSharedPtr<T> DoublyLinkedList<T>::GetNode(size_t index) const
        {
            if (index >= Size())
            {
                long statusCode = base::ErrorCodes::OUT_OF_RANGE;
                std::wstring errorMessage = L"The index: " + std::to_wstring(index) + L" is out Of range.";
                throw DoublyLinkedListException(statusCode, errorMessage);
            }

            IDoublyLinkedListNodeSharedPtr<T> currNode = m_head;

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
        void DoublyLinkedList<T>::linkedNodes(IDoublyLinkedListNodeSharedPtr<T> left, IDoublyLinkedListNodeSharedPtr<T> right)
        {
            if (left != nullptr)
            {
                left->SetNext(right);
            }

            if (right != nullptr)
            {
                right->SetPrevious(left);
            }
        }

        /**
         * Node added.
         */
        template <typename T>
        void DoublyLinkedList<T>::NodeAdded()
        {
            ++m_size;
        }

        /**
         * Node removed.
         */
        template <typename T>
        void DoublyLinkedList<T>::NodeRemoved(IDoublyLinkedListNode<T>& node)
        {
            node.Unlinked();
            --m_size;
        }
    }
}

#endif // I_DOUBLY_LINKED_LIST_H_920aca9a_f0e1_4a16_aa45_c65f5ef11267
