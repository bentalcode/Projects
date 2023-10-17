#ifndef KEY_VALUE_NODE_H_4e3c1397_5c65_4d9f_8b82_c486864bb9e0
#define KEY_VALUE_NODE_H_4e3c1397_5c65_4d9f_8b82_c486864bb9e0

#include "IKeyValueNode.h"

namespace datastructures {
    namespace node {

        /**
         * The KeyValueNode class implements a generic key-value node.
         */
        template <typename TKey, typename TValue>
        class KeyValueNode final : public IKeyValueNode<TKey, TValue>
        {
        public:
            /**
             * Creates a new instance of a key-value node.
             */
            static IKeyValueNodeSharedPtr<TKey, TValue> Make(const TKey& key, const TValue& value);

            /**
             * The KeyValueNode constructor.
             */
            KeyValueNode(
                const TKey& key,
                const TValue& value);

            /**
             * The KeyValueNode destructor.
             */
            virtual ~KeyValueNode();

            /**
             * The Copy/move constructors.
             */
            KeyValueNode(const KeyValueNode&) = delete;
            KeyValueNode(KeyValueNode&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            KeyValueNode& operator=(const KeyValueNode&) = delete;
            KeyValueNode& operator=(KeyValueNode&&) = delete;

            /**
             * Gets a key of a node.
             */
            virtual const TKey& GetKey() const override;

            /**
             * Gets a value of a node.
             */
            virtual const TValue& GetValue() const override;

            /**
             * Sets a value of a node.
             */
            virtual void SetValue(const TValue& value) override;

        private:
            TKey m_key;
            TValue m_value;
        };

        /**
         * Creates a new instance of a key-value node.
         */
        template <typename TKey, typename TValue>
        IKeyValueNodeSharedPtr<TKey, TValue> KeyValueNode<TKey, TValue>::Make(const TKey& key, const TValue& value)
        {
            return std::make_shared<KeyValueNode<TKey, TValue>>(key, value);
        }

        /**
         * The KeyValueNode constructor.
         */
        template <typename TKey, typename TValue>
        KeyValueNode<TKey, TValue>::KeyValueNode(
            const TKey& key,
            const TValue& value) :
            m_key(key),
            m_value(value)
        {
        }

        /**
         * The KeyValueNode destructor.
         */
        template <typename TKey, typename TValue>
        KeyValueNode<TKey, TValue>::~KeyValueNode()
        {
        }

        /**
         * Gets a key of a node.
         */
        template <typename TKey, typename TValue>
        const TKey& KeyValueNode<TKey, TValue>::GetKey() const
        {
            return m_key;
        }

        /**
         * Gets a value of a node.
         */
        template <typename TKey, typename TValue>
        const TValue& KeyValueNode<TKey, TValue>::GetValue() const
        {
            return m_value;
        }

        /**
         * Sets a value of a node.
         */
        template <typename TKey, typename TValue>
        void KeyValueNode<TKey, TValue>::SetValue(const TValue& value)
        {
            m_value = value;
        }
    }
}

#endif // KEY_VALUE_NODE_H_4e3c1397_5c65_4d9f_8b82_c486864bb9e0
