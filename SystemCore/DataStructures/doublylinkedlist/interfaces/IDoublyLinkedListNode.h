#ifndef I_DOUBLY_LINKED_LIST_NODE_H_33e7d433_2539_49ae_81fe_d3a082c4c7d5
#define I_DOUBLY_LINKED_LIST_NODE_H_33e7d433_2539_49ae_81fe_d3a082c4c7d5

#include <memory>

namespace datastructures {
    namespace doublylinkedlist {

        /**
         * The IDoublyLinkedListNode interface defines a node of a doubly linked list.
         */
        template <typename T>
        class IDoublyLinkedListNode
        {
        public:
            /**
             * The IDoublyLinkedListNode constructor.
             */
            IDoublyLinkedListNode() = default;

            /**
             * The IDoublyLinkedListNode destructor.
             */
            virtual ~IDoublyLinkedListNode() = default;

            /**
             * The Copy/move constructors.
             */
            IDoublyLinkedListNode(const IDoublyLinkedListNode&) = delete;
            IDoublyLinkedListNode(IDoublyLinkedListNode&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            IDoublyLinkedListNode& operator=(const IDoublyLinkedListNode&) = delete;
            IDoublyLinkedListNode& operator=(IDoublyLinkedListNode&&) = delete;

            /**
             * Gets a value of a node.
             */
            virtual const T& GetValue() const = 0;

            /**
             * Sets a value of a node.
             */
            virtual void SetValue(const T& value) = 0;

            /**
             * Gets a Next node.
             */
            virtual std::shared_ptr<IDoublyLinkedListNode<T>> Next() const = 0;

            /**
             * Sets a Next node.
             */
            virtual void SetNext(std::shared_ptr<IDoublyLinkedListNode<T>> node) = 0;

            /**
             * Checks whether there is a Next node.
             */
            virtual bool HasNext() const = 0;

            /**
             * Gets a Previous node.
             */
            virtual std::shared_ptr<IDoublyLinkedListNode<T>> Previous() const = 0;

            /**
             * Sets a Previous node.
             */
            virtual void SetPrevious(std::shared_ptr<IDoublyLinkedListNode<T>> node) = 0;

            /**
             * Checks whether there is a Previous node.
             */
            virtual bool HasPrevious() const = 0;

            /**
             * Unlinked the node.
             */
            virtual void Unlinked() = 0;
        };

        /**
         * Defines the SharedPtr of Doubly Linked List Node.
         */
        template <typename T>
        using IDoublyLinkedListNodeSharedPtr = std::shared_ptr<IDoublyLinkedListNode<T>>;

        /**
         * Implements an operator equals for doubly linked list nodes.
         */
        template <typename T>
        inline bool operator==(
            const IDoublyLinkedListNode<T>& lhs,
            const IDoublyLinkedListNode<T>& rhs)
        {
            return lhs.GetValue() == rhs.GetValue();
        }

        /**
         * Implements an operator not equals for doubly linked list nodes.
         */
        template <typename T>
        inline bool operator!=(
                const IDoublyLinkedListNode<T>& lhs,
                const IDoublyLinkedListNode<T>& rhs)
        {
            return !(lhs == rhs);
        }

        /**
         * Implements an operator less than for doubly linked list nodes.
         */
        template <typename T>
        bool operator<(
                const IDoublyLinkedListNode<T>& lhs,
                const IDoublyLinkedListNode<T>& rhs)
        {
            return lhs.GetValue() < rhs.GetValue();
        }

        /**
         * Implements an operator less than or equal for doubly linked list nodes.
         */
        template <typename T>
        bool operator<=(
            const IDoublyLinkedListNode<T>& lhs,
            const IDoublyLinkedListNode<T>& rhs)
        {
            return !(rhs < lhs);
        }

        /**
         * Implements an operator greater than for doubly linked list nodes.
         */
        template <typename T>
        inline bool operator>(
            const IDoublyLinkedListNode<T>& lhs,
            const IDoublyLinkedListNode<T>& rhs)
        {
            return rhs < lhs;
        }

        /**
         * Implements an operator greater than or equal for doubly linked list nodes.
         */
        template <typename T>
        bool operator>=(
            const IDoublyLinkedListNode<T>& lhs,
            const IDoublyLinkedListNode<T>& rhs)
        {
            return !(lhs < rhs);
        }
    }
}

#endif // I_DOUBLY_LINKED_LIST_NODE_H_33e7d433_2539_49ae_81fe_d3a082c4c7d5
