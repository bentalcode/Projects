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
            public base::ISizableCollection<ILinkedListNodeSharedPtr<T>>,
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
             * The Copy/move constructors.
             */
            ILinkedList(const ILinkedList&) = delete;
            ILinkedList(ILinkedList&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            ILinkedList& operator=(const ILinkedList&) = delete;
            ILinkedList& operator=(ILinkedList&&) = delete;

            /**
             * Gets the head node of the list.
             */
            virtual ILinkedListNodeSharedPtr<T> GetHead() const = 0;

            /**
             * Gets the tail node of the list.
             */
            virtual ILinkedListNodeSharedPtr<T> GetTail() const = 0;

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
                ILinkedListNodeSharedPtr<T> currNode,
                const T& valueToAdd) = 0;

            /**
             * Adds a new node to the front of the list.
             */
            virtual void AddToFront(ILinkedListNodeSharedPtr<T> node) = 0;

            /**
              * Adds a new node to the back of the list.
              */
            virtual void AddToBack(ILinkedListNodeSharedPtr<T> node) = 0;

            /**
             * Adds a new node after a specific node of the list.
             */
            virtual void AddAfter(
                ILinkedListNodeSharedPtr<T> currNode,
                ILinkedListNodeSharedPtr<T> nodeToAdd) = 0;

            /**
             * Removes the front node from the list.
             * Returns the removed node or null if the list is Empty.
             */
            virtual ILinkedListNodeSharedPtr<T> RemoveFromFront() = 0;

            /**
             * Removes a node after a specific node of the list.
             */
            virtual void RemoveAfter(ILinkedListNodeSharedPtr<T> currNode) = 0;

            /**
             * Clears the list.
             */
            virtual void Clear() = 0;

            /**
             * Gets a specific node by index. Index: [0, 1, 2, ... , Size -1]
             */
            virtual ILinkedListNodeSharedPtr<T> GetNode(size_t index) const = 0;
        };

        /**
         * Defines the SharedPtr ofLinked List.
         */
        template <typename T>
        using ILinkedListSharedPtr = std::shared_ptr<ILinkedList<T>>;
    }
}

#endif // I_LINKED_LIST_H_d9448e2d_f4ac_45eb_9a12_369a3712932f
