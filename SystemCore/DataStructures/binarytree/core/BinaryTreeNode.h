#ifndef BINARY_TREE_NODE_H_1e849370_ffed_42bf_a436_4d7f11030a3d
#define BINARY_TREE_NODE_H_1e849370_ffed_42bf_a436_4d7f11030a3d

#include "IBinaryTreeNode.h"

namespace datastructures {
    namespace binarytree {

        /**
         * The BinaryTreeNode class implements a node of a binary tree.
         */
        template <typename TKey, typename TValue>
        class BinaryTreeNode final : public IBinaryTreeNode<TKey, TValue> {
        public:
            /**
             * The BinaryTreeNode constructor.
             */
            BinaryTreeNode(const TKey& key, const TValue& value);

            /**
             * The BinaryTreeNode destructor.
             */
            virtual ~BinaryTreeNode();

            /**
             * The Copy/move constructors.
             */
            BinaryTreeNode(const BinaryTreeNode&) = delete;
            BinaryTreeNode(BinaryTreeNode&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            BinaryTreeNode& operator=(const BinaryTreeNode&) = delete;
            BinaryTreeNode& operator=(BinaryTreeNode&&) = delete;

            /**
             * Gets the key of the node.
             */
            virtual const TKey& GetKey() const override;

            /**
             * Sets the key of the node.
             */
            virtual void SetKey(const TKey& key) override;

            /**
             * Gets the value of the node.
             */
            virtual const TValue& GetValue() const override;

            /**
             * Sets the value of the node.
             */
            virtual void SetValue(const TValue& value) override;

            /**
             * Gets the node of a left child.
             */
            virtual IBinaryTreeNodeSharedPtr<TKey, TValue> GetLeftChild() const override;

            /**
             * Sets the node of a left child.
             */
            virtual void SetLeftChild(IBinaryTreeNodeSharedPtr<TKey, TValue> node) override;

            /**
             * Gets the node of a right child.
             */
            virtual IBinaryTreeNodeSharedPtr<TKey, TValue> GetRightChild() const override;

            /**
             * Sets the node of a right child.
             */
            virtual void SetRightChild(IBinaryTreeNodeSharedPtr<TKey, TValue> node) override;

            /**
             * Checks whether there is a left child.
             */
            virtual bool HasLeftChild() const override;

            /**
             * Checks whether there is a right child.
             */
            virtual bool HasRightChild() const override;

        private:
            TKey m_key;
            TValue m_value;
            IBinaryTreeNodeSharedPtr<TKey, TValue> m_leftChild;
            IBinaryTreeNodeSharedPtr<TKey, TValue> m_rightChild;
        };

        /**
         * The BinaryTreeNode constructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreeNode<TKey, TValue>::BinaryTreeNode(const TKey& key, const TValue& value) :
            m_key(key),
            m_value(value)
        {
        }

        /**
         * The BinaryTreeNode destructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreeNode<TKey, TValue>::~BinaryTreeNode()
        {
        }

        /**
         * Gets the key of the node.
         */
        template <typename TKey, typename TValue>
        const TKey& BinaryTreeNode<TKey, TValue>::GetKey() const
        {
            return m_key;
        }

        /**
         * Sets the key of the node.
         */
        template <typename TKey, typename TValue>
        void BinaryTreeNode<TKey, TValue>::SetKey(const TKey& key)
        {
            m_key = key;
        }

        /**
         * Gets the value of the node.
         */
        template <typename TKey, typename TValue>
        const TValue& BinaryTreeNode<TKey, TValue>::GetValue() const
        {
            return m_value;
        }

        /**
         * Sets the value of the node.
         */
        template <typename TKey, typename TValue>
        void BinaryTreeNode<TKey, TValue>::SetValue(const TValue& value)
        {
            m_value = value;
        }

        /**
         * Gets the node of a left child.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeNodeSharedPtr<TKey, TValue> BinaryTreeNode<TKey, TValue>::GetLeftChild() const
        {
            return m_leftChild;
        }

        /**
         * Sets the node of a left child.
         */
        template <typename TKey, typename TValue>
        void BinaryTreeNode<TKey, TValue>::SetLeftChild(IBinaryTreeNodeSharedPtr<TKey, TValue> child)
        {
            m_leftChild = child;
        }

        /**
         * Gets the node of a right child.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeNodeSharedPtr<TKey, TValue> BinaryTreeNode<TKey, TValue>::GetRightChild() const
        {
            return m_rightChild;
        }

        /**
         * Sets the node of a right child.
         */
        template <typename TKey, typename TValue>
        void BinaryTreeNode<TKey, TValue>::SetRightChild(IBinaryTreeNodeSharedPtr<TKey, TValue> child)
        {
            m_rightChild = child;
        }

        /**
         * Checks whether there is a left child.
         */
        template <typename TKey, typename TValue>
        bool BinaryTreeNode<TKey, TValue>::HasLeftChild() const
        {
            return m_leftChild != nullptr;
        }

        /**
         * Checks whether there is a right child.
         */
        template <typename TKey, typename TValue>
        bool BinaryTreeNode<TKey, TValue>::HasRightChild() const
        {
            return m_rightChild != nullptr;
        }
    }
}

#endif // BINARY_TREE_NODE_H_1e849370_ffed_42bf_a436_4d7f11030a3d
