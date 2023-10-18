#ifndef I_DOUBLY_LINKED_LIST_H_920aca9a_f0e1_4a16_aa45_c65f5ef11267
#define I_DOUBLY_LINKED_LIST_H_920aca9a_f0e1_4a16_aa45_c65f5ef11267

#include "ISizableCollection.h"
#include "IIterable.h"
#include "IReverseIterable.h"
#include "IValueIterable.h"
#include "IValueReverseIterable.h"
#include "IDoublyLinkedListNode.h"

namespace datastructures {
    namespace doublylinkedlist {

        /**
         * The IDoublyLinkedList interface defines a doubly linked list.
         */
        template <typename T>
        class IDoublyLinkedList :
            public base::ISizableCollection<IDoublyLinkedListNodeSharedPtr<T>>,
            public base::IReverseIterable<IDoublyLinkedListNodeSharedPtr<T>>,
            public base::IValueIterable<T>,
            public base::IValueReverseIterable<T>
        {
        public:
            /**
             * The IDoublyLinkedList constructor.
             */
            IDoublyLinkedList() = default;

            /**
             * The IDoublyLinkedList destructor.
             */
            virtual ~IDoublyLinkedList() = default;

            /**
             * The Copy/move constructors.
             */
            IDoublyLinkedList(const IDoublyLinkedList&) = delete;
            IDoublyLinkedList(IDoublyLinkedList&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            IDoublyLinkedList& operator=(const IDoublyLinkedList&) = delete;
            IDoublyLinkedList& operator=(IDoublyLinkedList&&) = delete;

            /**
             * Gets the head node of the list.
             */
            virtual IDoublyLinkedListNodeSharedPtr<T> GetHead() const = 0;

            /**
             * Gets the tail node of the list.
             */
            virtual IDoublyLinkedListNodeSharedPtr<T> GetTail() const = 0;

            /**
             * Adds a new value to the front of the list.
             */
            virtual void AddToFront(const T& value) = 0;

            /**
             * Adds a new value to the back of the list.
             */
            virtual void AddToBack(const T& value) = 0;

            /**
             * Adds a new value after a specific node of the list.
             */
            virtual void AddAfter(
                IDoublyLinkedListNodeSharedPtr<T> currNode,
                const T& valueToAdd) = 0;

            /**
             * Adds a new value before a specific node of the list.
             */
            virtual void AddBefore(
                IDoublyLinkedListNodeSharedPtr<T> currNode,
                const T& valueToAdd) = 0;

            /**
             * Adds a new node to the front of the list.
             */
            virtual void AddToFront(IDoublyLinkedListNodeSharedPtr<T> node) = 0;

            /**
             * Adds a new node to the back of the list.
             */
            virtual void AddToBack(IDoublyLinkedListNodeSharedPtr<T> node) = 0;

            /**
             * Adds a new node after a specific node of the list.
             */
            virtual void AddAfter(
                IDoublyLinkedListNodeSharedPtr<T> currNode,
                IDoublyLinkedListNodeSharedPtr<T> nodeToAdd) = 0;

            /**
             * Adds a new node before a specific node of the list.
             */
            virtual void AddBefore(
                IDoublyLinkedListNodeSharedPtr<T> currNode,
                IDoublyLinkedListNodeSharedPtr<T> nodeToAdd) = 0;

            /**
             * Removes the front node from the list.
             * Returns the removed node or null if the list is Empty.
             */
            virtual IDoublyLinkedListNodeSharedPtr<T> RemoveFromFront() = 0;

            /**
             * Removes the back node from the list.
             * Returns the removed node or null if the list is Empty.
             */
            virtual IDoublyLinkedListNodeSharedPtr<T> RemoveFromBack() = 0;

            /**
             * Removes the a node from the list.
             */
            virtual void Remove(IDoublyLinkedListNodeSharedPtr<T> nodeToRemove) = 0;

            /**
             * Clears the list.
             */
            virtual void Clear() = 0;

            /**
             * Gets a specific node by index. Index: [0, 1, 2, ... , Size -1]
             */
            virtual IDoublyLinkedListNodeSharedPtr<T> GetNode(size_t index) const = 0;
        };

        /**
         * Defines the SharedPtr ofDoubly Linked List.
         */
        template <typename T>
        using IDoublyLinkedListSharedPtr = std::shared_ptr<IDoublyLinkedList<T>>;
    }
}

#endif // I_DOUBLY_LINKED_LIST_H_920aca9a_f0e1_4a16_aa45_c65f5ef11267
