#ifndef I_KEY_VALUE_NODE_H_21f28c35_1930_436a_80c6_4c8f7ecad3fe
#define I_KEY_VALUE_NODE_H_21f28c35_1930_436a_80c6_4c8f7ecad3fe

namespace datastructures {
    namespace node {

        /**
         * The IKeyValueNode interface defines a generic key-value node.
         */
        template <typename TKey, typename TValue>
        class IKeyValueNode
        {
        public:
            /**
             * The IKeyValueNode constructor.
             */
            IKeyValueNode() = default;

            /**
             * The IKeyValueNode destructor.
             */
            virtual ~IKeyValueNode() = default;

            /**
             * The Copy/move constructors.
             */
            IKeyValueNode(const IKeyValueNode&) = delete;
            IKeyValueNode(IKeyValueNode&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            IKeyValueNode& operator=(const IKeyValueNode&) = delete;
            IKeyValueNode& operator=(IKeyValueNode&&) = delete;

            /**
             * Gets a key of a node.
             */
            virtual const TKey& GetKey() const = 0;

            /**
             * Gets a value of a node.
             */
            virtual const TValue& GetValue() const = 0;

            /**
             * Sets a value of a node.
             */
            virtual void SetValue(const TValue& value) = 0;
        };

        /**
         * Defines the SharedPtr ofKey Value Node.
         */
        template <typename TKey, typename TValue>
        using IKeyValueNodeSharedPtr = std::shared_ptr<IKeyValueNode<TKey, TValue>>;

        /**
         * Implements an operator equals for key value nodes.
         */
        template <typename TKey, typename TValue>
        inline bool operator==(
            const IKeyValueNode<TKey, TValue>& lhs,
            const IKeyValueNode<TKey, TValue>& rhs)
        {
            return
                lhs.GetValue() == rhs.GetValue() &&
                lhs.GetValue() == rhs.GetValue();
        }

        /**
         * Implements an operator not equals for key value nodes.
         */
        template <typename TKey, typename TValue>
        inline bool operator!=(
            const IKeyValueNode<TKey, TValue>& lhs,
            const IKeyValueNode<TKey, TValue>& rhs)
        {
            return !(lhs == rhs);
        }

        /**
         * Implements an operator less than for key value nodes.
         */
        template <typename TKey, typename TValue>
        bool operator<(
            const IKeyValueNode<TKey, TValue>& lhs,
            const IKeyValueNode<TKey, TValue>& rhs)
        {
            if (lhs.GetKey() < rhs.GetKey())
            {
                return true;
            }

            if (lhs.GetKey() > rhs.GetKey())
            {
                return false;
            }

            return lhs.GetValue() < rhs.GetValue();
        }

        /**
         * Implements an operator less than or equal for key value nodes.
         */
        template <typename TKey, typename TValue>
        bool operator<=(
            const IKeyValueNode<TKey, TValue>& lhs,
            const IKeyValueNode<TKey, TValue>& rhs)
        {
            return !(rhs < lhs);
        }

        /**
         * Implements an operator greater than for key value nodes.
         */
        template <typename TKey, typename TValue>
        inline bool operator>(
            const IKeyValueNode<TKey, TValue>& lhs,
            const IKeyValueNode<TKey, TValue>& rhs)
        {
            return rhs < lhs;
        }

        /**
         * Implements an operator greater than or equal for key value nodes.
         */
        template <typename TKey, typename TValue>
        bool operator>=(
            const IKeyValueNode<TKey, TValue>& lhs,
            const IKeyValueNode<TKey, TValue>& rhs)
        {
            return !(lhs < rhs);
        }
    }
}

#endif // I_KEY_VALUE_NODE_H_21f28c35_1930_436a_80c6_4c8f7ecad3fe
