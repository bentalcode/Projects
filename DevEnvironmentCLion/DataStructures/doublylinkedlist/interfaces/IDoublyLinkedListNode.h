#ifndef I_DOUBLY_LINKED_LIST_NODE_H_33e7d433_2539_49ae_81fe_d3a082c4c7d5
#define I_DOUBLY_LINKED_LIST_NODE_H_33e7d433_2539_49ae_81fe_d3a082c4c7d5

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
             * The copy/move constructors.
             */
            IDoublyLinkedListNode(const IDoublyLinkedListNode&) = delete;
            IDoublyLinkedListNode(IDoublyLinkedListNode&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            IDoublyLinkedListNode& operator=(const IDoublyLinkedListNode&) = delete;
            IDoublyLinkedListNode& operator=(IDoublyLinkedListNode&&) = delete;

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
            virtual std::shared_ptr<IDoublyLinkedListNode<T>> next() const = 0;

            /**
             * Sets a next node.
             */
            virtual void setNext(std::shared_ptr<IDoublyLinkedListNode<T>> node) = 0;

            /**
             * Checks whether there is a next node.
             */
            virtual bool hasNext() const = 0;

            /**
             * Gets a previous node.
             */
            virtual std::shared_ptr<IDoublyLinkedListNode<T>> previous() const = 0;

            /**
             * Sets a previous node.
             */
            virtual void setPrevious(std::shared_ptr<IDoublyLinkedListNode<T>> node) = 0;

            /**
             * Checks whether there is a previous node.
             */
            virtual bool hasPrevious() const = 0;

            /**
             * Unlinked the node.
             */
            virtual void unlinked() = 0;
        };

        template <typename T>
        using IDoublyLinkedListNodePtr = std::shared_ptr<IDoublyLinkedListNode<T>>;

        /**
         * Defines the equivalent operator.
         */
        template <typename T>
        bool operator<(const IDoublyLinkedListNode<T>& left, const IDoublyLinkedListNode<T>& right)
        {
            return left.getValue() < right.getValue();
        }
    }
}

#endif // I_DOUBLY_LINKED_LIST_NODE_H_33e7d433_2539_49ae_81fe_d3a082c4c7d5
