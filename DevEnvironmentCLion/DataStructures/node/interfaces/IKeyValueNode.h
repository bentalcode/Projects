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
             * The copy/move constructors.
             */
            IKeyValueNode(const IKeyValueNode&) = delete;
            IKeyValueNode(IKeyValueNode&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            IKeyValueNode& operator=(const IKeyValueNode&) = delete;
            IKeyValueNode& operator=(IKeyValueNode&&) = delete;

            /**
             * Gets a key of a node.
             */
            virtual const TKey& getKey() const = 0;

            /**
             * Gets a value of a node.
             */
            virtual const TValue& getValue() const = 0;

            /**
             * Sets a value of a node.
             */
            virtual void setValue(const TValue& value) = 0;
        };

        template <typename TKey, typename TValue>
        using IKeyValueNodePtr = std::shared_ptr<IKeyValueNode<TKey, TValue>>;

        /**
         * Defines the equivalent operator.
         */
        template <typename TKey, typename TValue>
        inline bool operator<(const IKeyValueNode<TKey, TValue>& left, const IKeyValueNode<TKey, TValue>& right)
        {
            if (left.getKey() < right.getKey())
            {
                return true;
            }

            if (left.getKey() > right.getKey())
            {
                return false;
            }

            return left.getValue() < right.getValue();
        }

    }
}

#endif // I_KEY_VALUE_NODE_H_21f28c35_1930_436a_80c6_4c8f7ecad3fe
