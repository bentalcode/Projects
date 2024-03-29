#ifndef BINARY_TREE_END_NODE_H_d791982e_f581_45ab_a75a_d2fe298069c9
#define BINARY_TREE_END_NODE_H_d791982e_f581_45ab_a75a_d2fe298069c9

#include "IBinaryTreeNode.h"
#include "NotImplementedException.h"

namespace datastructures {
    namespace binarytree {

        /**
         * The BinaryTreeEndNode class implements an internal end nodes of a binary tree,
         * which is used for serialization.
         */
        template <typename TKey, typename TValue>
        class BinaryTreeEndNode final : public IBinaryTreeNode<TKey, TValue> {
        public:
            /**
             * The BinaryTreeEndNode constructor.
             */
            BinaryTreeEndNode();

            /**
             * The BinaryTreeEndNode destructor.
             */
            virtual ~BinaryTreeEndNode();

            /**
             * The Copy/move constructors.
             */
            BinaryTreeEndNode(const BinaryTreeEndNode&) = delete;
            BinaryTreeEndNode(BinaryTreeEndNode&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            BinaryTreeEndNode& operator=(const BinaryTreeEndNode&) = delete;
            BinaryTreeEndNode& operator=(BinaryTreeEndNode&&) = delete;

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
        };

        /**
         * The BinaryTreeEndNode constructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreeEndNode<TKey, TValue>::BinaryTreeEndNode()
        {
        }

        /**
         * The BinaryTreeEndNode destructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreeEndNode<TKey, TValue>::~BinaryTreeEndNode()
        {
        }

        /**
         * Gets the key of the node.
         */
        template <typename TKey, typename TValue>
        const TKey& BinaryTreeEndNode<TKey, TValue>::GetKey() const
        {
            throw base::NotImplementedException(L"BinaryTreeEndNode::GetKey()");
        }

        /**
         * Sets the key of the node.
         */
        template <typename TKey, typename TValue>
        void BinaryTreeEndNode<TKey, TValue>::SetKey(const TKey& key)
        {
            throw base::NotImplementedException(L"BinaryTreeEndNode::SetKey()");
        }

        /**
         * Gets the value of the node.
         */
        template <typename TKey, typename TValue>
        const TValue& BinaryTreeEndNode<TKey, TValue>::GetValue() const
        {
            throw base::NotImplementedException(L"BinaryTreeEndNode::GetValue()");
        }

        /**
         * Sets the value of the node.
         */
        template <typename TKey, typename TValue>
        void BinaryTreeEndNode<TKey, TValue>::SetValue(const TValue& value)
        {
            throw base::NotImplementedException(L"BinaryTreeEndNode::SetValue()");
        }

        /**
         * Gets the node of a left child.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeNodeSharedPtr<TKey, TValue> BinaryTreeEndNode<TKey, TValue>::GetLeftChild() const
        {
            throw base::NotImplementedException(L"BinaryTreeEndNode::GetLeftChild()");
        }

        /**
         * Sets the node of a left child.
         */
        template <typename TKey, typename TValue>
        void BinaryTreeEndNode<TKey, TValue>::SetLeftChild(IBinaryTreeNodeSharedPtr<TKey, TValue> child)
        {
            throw base::NotImplementedException(L"BinaryTreeEndNode::GetLeftChild()");
        }

        /**
         * Gets the node of a right child.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeNodeSharedPtr<TKey, TValue> BinaryTreeEndNode<TKey, TValue>::GetRightChild() const
        {
            throw base::NotImplementedException(L"BinaryTreeEndNode::GetRightChild()");
        }

        /**
         * Sets the node of a right child.
         */
        template <typename TKey, typename TValue>
        void BinaryTreeEndNode<TKey, TValue>::SetRightChild(IBinaryTreeNodeSharedPtr<TKey, TValue> child)
        {
            throw base::NotImplementedException(L"BinaryTreeEndNode::SetRightChild()");
        }

        /**
         * Checks whether there is a left child.
         */
        template <typename TKey, typename TValue>
        bool BinaryTreeEndNode<TKey, TValue>::HasLeftChild() const
        {
            throw base::NotImplementedException(L"BinaryTreeEndNode::HasLeftChild()");
        }

        /**
         * Checks whether there is a right child.
         */
        template <typename TKey, typename TValue>
        bool BinaryTreeEndNode<TKey, TValue>::HasRightChild() const
        {
            throw base::NotImplementedException(L"BinaryTreeEndNode::HasRightChild()");
        }
    }
}

#endif // BINARY_TREE_END_NODE_H_d791982e_f581_45ab_a75a_d2fe298069c9
