#ifndef I_LINKED_LIST_NODE_H_133f195d_56ec_4b3f_83bc_5b0bebcd3832
#define I_LINKED_LIST_NODE_H_133f195d_56ec_4b3f_83bc_5b0bebcd3832

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
             * The copy/move constructors.
             */
            ILinkedListNode(const ILinkedListNode&) = delete;
            ILinkedListNode(ILinkedListNode&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            ILinkedListNode& operator=(const ILinkedListNode&) = delete;
            ILinkedListNode& operator=(ILinkedListNode&&) = delete;

            /**
             * Gets a value of a node.
             */
            virtual const T& getValue() const = 0;

            /**
             * Sets a value of a node.
             */
            virtual void setValue(const T& value) = 0;

            /**
             * Gets a next node.
             */
            virtual std::shared_ptr<ILinkedListNode<T>> next() const = 0;

            /**
             * Sets a next node.
             */
            virtual void setNext(std::shared_ptr<ILinkedListNode<T>> node) = 0;

            /**
             * Checks whether there is a next node.
             */
            virtual bool hasNext() const = 0;

            /**
             * Unlinked the node.
             */
            virtual void unlinked() = 0;
        };

        /**
         * Defines the SharedPtr of Linked List Node.
         */
        template <typename T>
        using ILinkedListNodeSharedPtr = std::shared_ptr<ILinkedListNode<T>>;

        /**
         * Defines the equivalent operator.
         */
        template <typename T>
        bool operator<(const ILinkedListNode<T>& left, const ILinkedListNode<T>& right)
        {
            return left.getValue() < right.getValue();
        }
    }
}

#endif // I_LINKED_LIST_NODE_H_133f195d_56ec_4b3f_83bc_5b0bebcd3832
