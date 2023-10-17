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
         * Defines the SharedPtr Of Linked List Node.
         */
        template <typename T>
        using ILinkedListNodeSharedPtr = std::shared_ptr<ILinkedListNode<T>>;

        /**
         * Defines the equivalent operator.
         */
        template <typename T>
        bool operator<(const ILinkedListNode<T>& left, const ILinkedListNode<T>& right)
        {
            return left.GetValue() < right.GetValue();
        }
    }
}

#endif // I_LINKED_LIST_NODE_H_133f195d_56ec_4b3f_83bc_5b0bebcd3832
