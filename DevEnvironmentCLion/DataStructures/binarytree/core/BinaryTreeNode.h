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
             * The copy/move constructors.
             */
            BinaryTreeNode(const BinaryTreeNode&) = delete;
            BinaryTreeNode(BinaryTreeNode&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            BinaryTreeNode& operator=(const BinaryTreeNode&) = delete;
            BinaryTreeNode& operator=(BinaryTreeNode&&) = delete;

            /**
             * Gets the key of the node.
             */
            virtual const TKey& getKey() const override;

            /**
             * Sets the key of the node.
             */
            virtual void setKey(const TKey& key) override;

            /**
             * Gets the value of the node.
             */
            virtual const TValue& getValue() const override;

            /**
             * Sets the value of the node.
             */
            virtual void setValue(const TValue& value) override;

            /**
             * Gets the node of a left child.
             */
            virtual IBinaryTreeNodePtr<TKey, TValue> getLeftChild() const override;

            /**
             * Sets the node of a left child.
             */
            virtual void setLeftChild(IBinaryTreeNodePtr<TKey, TValue> node) override;

            /**
             * Gets the node of a right child.
             */
            virtual IBinaryTreeNodePtr<TKey, TValue> getRightChild() const override;

            /**
             * Sets the node of a right child.
             */
            virtual void setRightChild(IBinaryTreeNodePtr<TKey, TValue> node) override;

            /**
             * Checks whether there is a left child.
             */
            virtual bool hasLeftChild() const override;

            /**
             * Checks whether there is a right child.
             */
            virtual bool hasRightChild() const override;

        private:
            TKey m_key;
            TValue m_value;
            IBinaryTreeNodePtr<TKey, TValue> m_leftChild;
            IBinaryTreeNodePtr<TKey, TValue> m_rightChild;
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
        const TKey& BinaryTreeNode<TKey, TValue>::getKey() const
        {
            return m_key;
        }

        /**
         * Sets the key of the node.
         */
        template <typename TKey, typename TValue>
        void BinaryTreeNode<TKey, TValue>::setKey(const TKey& key)
        {
            m_key = key;
        }

        /**
         * Gets the value of the node.
         */
        template <typename TKey, typename TValue>
        const TValue& BinaryTreeNode<TKey, TValue>::getValue() const
        {
            return m_value;
        }

        /**
         * Sets the value of the node.
         */
        template <typename TKey, typename TValue>
        void BinaryTreeNode<TKey, TValue>::setValue(const TValue& value)
        {
            m_value = value;
        }

        /**
         * Gets the node of a left child.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeNodePtr<TKey, TValue> BinaryTreeNode<TKey, TValue>::getLeftChild() const
        {
            return m_leftChild;
        }

        /**
         * Sets the node of a left child.
         */
        template <typename TKey, typename TValue>
        void BinaryTreeNode<TKey, TValue>::setLeftChild(IBinaryTreeNodePtr<TKey, TValue> child)
        {
            m_leftChild = child;
        }

        /**
         * Gets the node of a right child.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeNodePtr<TKey, TValue> BinaryTreeNode<TKey, TValue>::getRightChild() const
        {
            return m_rightChild;
        }

        /**
         * Sets the node of a right child.
         */
        template <typename TKey, typename TValue>
        void BinaryTreeNode<TKey, TValue>::setRightChild(IBinaryTreeNodePtr<TKey, TValue> child)
        {
            m_rightChild = child;
        }

        /**
         * Checks whether there is a left child.
         */
        template <typename TKey, typename TValue>
        bool BinaryTreeNode<TKey, TValue>::hasLeftChild() const
        {
            return m_leftChild != nullptr;
        }

        /**
         * Checks whether there is a right child.
         */
        template <typename TKey, typename TValue>
        bool BinaryTreeNode<TKey, TValue>::hasRightChild() const
        {
            return m_rightChild != nullptr;
        }
    }
}

#endif // BINARY_TREE_NODE_H_1e849370_ffed_42bf_a436_4d7f11030a3d
