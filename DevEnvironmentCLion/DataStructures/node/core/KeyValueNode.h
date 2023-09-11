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
            static IKeyValueNodePtr<TKey, TValue> make(const TKey& key, const TValue& value);

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
             * The copy/move constructors.
             */
            KeyValueNode(const KeyValueNode&) = delete;
            KeyValueNode(KeyValueNode&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            KeyValueNode& operator=(const KeyValueNode&) = delete;
            KeyValueNode& operator=(KeyValueNode&&) = delete;

            /**
             * Gets a key of a node.
             */
            virtual const TKey& getKey() const override;

            /**
             * Gets a value of a node.
             */
            virtual const TValue& getValue() const override;

            /**
             * Sets a value of a node.
             */
            virtual void setValue(const TValue& value) override;

        private:
            TKey m_key;
            TValue m_value;
        };

        /**
         * Creates a new instance of a key-value node.
         */
        template <typename TKey, typename TValue>
        IKeyValueNodePtr<TKey, TValue> KeyValueNode<TKey, TValue>::make(const TKey& key, const TValue& value)
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
        const TKey& KeyValueNode<TKey, TValue>::getKey() const
        {
            return m_key;
        }

        /**
         * Gets a value of a node.
         */
        template <typename TKey, typename TValue>
        const TValue& KeyValueNode<TKey, TValue>::getValue() const
        {
            return m_value;
        }

        /**
         * Sets a value of a node.
         */
        template <typename TKey, typename TValue>
        void KeyValueNode<TKey, TValue>::setValue(const TValue& value)
        {
            m_value = value;
        }
    }
}

#endif // KEY_VALUE_NODE_H_4e3c1397_5c65_4d9f_8b82_c486864bb9e0
