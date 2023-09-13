#ifndef I_LINKED_LIST_H_d9448e2d_f4ac_45eb_9a12_369a3712932f
#define I_LINKED_LIST_H_d9448e2d_f4ac_45eb_9a12_369a3712932f

#include "ISizableCollection.h"
#include "IIterable.h"
#include "IValueIterable.h"
#include "ILinkedListNode.h"

namespace datastructures {
    namespace linkedlist {

        /**
         * The ILinkedList interface defines a linked list.
         */
        template <typename T>
        class ILinkedList :
            public base::ISizableCollection,
            public base::IIterable<ILinkedListNodeSharedPtr<T>>,
            public base::IValueIterable<T>
        {
        public:
            /**
             * The ILinkedList constructor.
             */
            ILinkedList() = default;

            /**
             * The ILinkedList destructor.
             */
            virtual ~ILinkedList() = default;

            /**
             * The copy/move constructors.
             */
            ILinkedList(const ILinkedList&) = delete;
            ILinkedList(ILinkedList&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            ILinkedList& operator=(const ILinkedList&) = delete;
            ILinkedList& operator=(ILinkedList&&) = delete;

            /**
             * Gets the head node of the list.
             */
            virtual ILinkedListNodeSharedPtr<T> getHead() const = 0;

            /**
             * Gets the tail node of the list.
             */
            virtual ILinkedListNodeSharedPtr<T> getTail() const = 0;

            /**
             * Adds a new value to the front of the list.
             */
            virtual void addToFront(const T& value) = 0;

            /**
             * Adds a new value to the back of the list.
             */
            virtual void addToBack(const T& value) = 0;

            /**
             * Adds a new value after a specific node of the list.
             */
            virtual void addAfter(
                ILinkedListNodeSharedPtr<T> currNode,
                const T& valueToAdd) = 0;

            /**
             * Adds a new node to the front of the list.
             */
            virtual void addToFront(ILinkedListNodeSharedPtr<T> node) = 0;

            /**
              * Adds a new node to the back of the list.
              */
            virtual void addToBack(ILinkedListNodeSharedPtr<T> node) = 0;

            /**
             * Adds a new node after a specific node of the list.
             */
            virtual void addAfter(
                ILinkedListNodeSharedPtr<T> currNode,
                ILinkedListNodeSharedPtr<T> nodeToAdd) = 0;

            /**
             * Removes the front node from the list.
             * Returns the removed node or null if the list is empty.
             */
            virtual ILinkedListNodeSharedPtr<T> removeFromFront() = 0;

            /**
             * Removes a node after a specific node of the list.
             */
            virtual void removeAfter(ILinkedListNodeSharedPtr<T> currNode) = 0;

            /**
             * Clears the list.
             */
            virtual void clear() = 0;

            /**
             * Gets a specific node by index. Index: [0, 1, 2, ... , size -1]
             */
            virtual ILinkedListNodeSharedPtr<T> getNode(size_t index) const = 0;
        };

        /**
         * Defines the SharedPtr of Linked List.
         */
        template <typename T>
        using ILinkedListSharedPtr = std::shared_ptr<ILinkedList<T>>;
    }
}

#endif // I_LINKED_LIST_H_d9448e2d_f4ac_45eb_9a12_369a3712932f
