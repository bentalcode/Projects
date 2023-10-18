#ifndef I_LINKED_LIST_NODE_H_133f195d_56ec_4b3f_83bc_5b0bebcd3832
#define I_LINKED_LIST_NODE_H_133f195d_56ec_4b3f_83bc_5b0bebcd3832

#include <memory>

namespace datastructures {
    namespace linkedlist {

        /**
         * The ILinkedListNode interface defines a node of a linked list.
         */
        template <typename T>
        class ILinkedListNode
        {
        public:
            /**
             * The ILinkedListNode constructor.
             */
            ILinkedListNode() = default;

            /**
             * The ILinkedListNode destructor.
             */
            virtual ~ILinkedListNode() = default;

            /**
             * The Copy/move constructors.
             */
            ILinkedListNode(const ILinkedListNode&) = delete;
            ILinkedListNode(ILinkedListNode&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            ILinkedListNode& operator=(const ILinkedListNode&) = delete;
            ILinkedListNode& operator=(ILinkedListNode&&) = delete;

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
            virtual std::shared_ptr<ILinkedListNode<T>> Next() const = 0;

            /**
             * Sets a Next node.
             */
            virtual void SetNext(std::shared_ptr <ILinkedListNode<T>> node) = 0;

            /**
             * Checks whether there is a Next node.
             */
            virtual bool HasNext() const = 0;

            /**
             * Unlinked the node.
             */
            virtual void Unlinked() = 0;
        };

        /**
         * Defines the SharedPtr of Linked List Node.
         */
        template <typename T>
        using ILinkedListNodeSharedPtr = std::shared_ptr<ILinkedListNode<T>>;

        /**
         * Implements an operator equals for linked list nodes.
         */
        template <typename T>
        inline bool operator==(
            const ILinkedListNode<T>& lhs,
            const ILinkedListNode<T>& rhs)
        {
            return lhs.GetValue() == rhs.GetValue();
        }

        /**
         * Implements an operator not equals for linked list nodes.
         */
        template <typename T>
        inline bool operator!=(
            const ILinkedListNode<T>& lhs,
            const ILinkedListNode<T>& rhs)
        {
            return !(lhs == rhs);
        }

        /**
         * Implements an operator less than for linked list nodes.
         */
        template <typename T>
        bool operator<(
            const ILinkedListNode<T>& lhs,
            const ILinkedListNode<T>& rhs)
        {
            return lhs.GetValue() < rhs.GetValue();
        }

        /**
         * Implements an operator less than or equal for linked list nodes.
         */
        template <typename T>
        bool operator<=(
            const ILinkedListNode<T>& lhs,
            const ILinkedListNode<T>& rhs)
        {
            return !(rhs < lhs);
        }

        /**
         * Implements an operator greater than for linked list nodes.
         */
        template <typename T>
        inline bool operator>(
            const ILinkedListNode<T>& lhs,
            const ILinkedListNode<T>& rhs)
        {
            return rhs < lhs;
        }

        /**
         * Implements an operator greater than or equal for linked list nodes.
         */
        template <typename T>
        bool operator>=(
            const ILinkedListNode<T>& lhs,
            const ILinkedListNode<T>& rhs)
        {
            return !(lhs < rhs);
        }
    }
}

#endif // I_LINKED_LIST_NODE_H_133f195d_56ec_4b3f_83bc_5b0bebcd3832
