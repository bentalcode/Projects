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
         * Defines the SharedPtr Of Key Value Node.
         */
        template <typename TKey, typename TValue>
        using IKeyValueNodeSharedPtr = std::shared_ptr<IKeyValueNode<TKey, TValue>>;

        /**
         * Defines the equivalent operator.
         */
        template <typename TKey, typename TValue>
        inline bool operator<(const IKeyValueNode<TKey, TValue>& left, const IKeyValueNode<TKey, TValue>& right)
        {
            if (left.GetKey() < right.GetKey())
            {
                return true;
            }

            if (left.GetKey() > right.GetKey())
            {
                return false;
            }

            return left.GetValue() < right.GetValue();
        }

    }
}

#endif // I_KEY_VALUE_NODE_H_21f28c35_1930_436a_80c6_4c8f7ecad3fe
