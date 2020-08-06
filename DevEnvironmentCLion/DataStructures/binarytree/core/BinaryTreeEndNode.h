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
        template<typename TKey, typename TValue>
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
             * The copy/move constructors.
             */
            BinaryTreeEndNode(const BinaryTreeEndNode&) = delete;
            BinaryTreeEndNode(BinaryTreeEndNode&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            BinaryTreeEndNode& operator=(const BinaryTreeEndNode&) = delete;
            BinaryTreeEndNode& operator=(BinaryTreeEndNode&&) = delete;

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
        };

        /**
         * The BinaryTreeEndNode constructor.
         */
        template<typename TKey, typename TValue>
        BinaryTreeEndNode<TKey, TValue>::BinaryTreeEndNode()
        {
        }

        /**
         * The BinaryTreeEndNode destructor.
         */
        template<typename TKey, typename TValue>
        BinaryTreeEndNode<TKey, TValue>::~BinaryTreeEndNode()
        {
        }

        /**
         * Gets the key of the node.
         */
        template<typename TKey, typename TValue>
        const TKey& BinaryTreeEndNode<TKey, TValue>::getKey() const
        {
            throw NotImplementedException("BinaryTreeEndNode::getKey()");
        }

        /**
         * Sets the key of the node.
         */
        template<typename TKey, typename TValue>
        void BinaryTreeEndNode<TKey, TValue>::setKey(const TKey& key)
        {
            throw NotImplementedException("BinaryTreeEndNode::setKey()");
        }

        /**
         * Gets the value of the node.
         */
        template<typename TKey, typename TValue>
        const TValue& BinaryTreeEndNode<TKey, TValue>::getValue() const
        {
            throw NotImplementedException("BinaryTreeEndNode::getValue()");
        }

        /**
         * Sets the value of the node.
         */
        template<typename TKey, typename TValue>
        void BinaryTreeEndNode<TKey, TValue>::setValue(const TValue& value)
        {
            throw NotImplementedException("BinaryTreeEndNode::setValue()");
        }

        /**
         * Gets the node of a left child.
         */
        template<typename TKey, typename TValue>
        IBinaryTreeNodePtr<TKey, TValue> BinaryTreeEndNode<TKey, TValue>::getLeftChild() const
        {
            throw NotImplementedException("BinaryTreeEndNode::getLeftChild()");
        }

        /**
         * Sets the node of a left child.
         */
        template<typename TKey, typename TValue>
        void BinaryTreeEndNode<TKey, TValue>::setLeftChild(IBinaryTreeNodePtr<TKey, TValue> child)
        {
            throw NotImplementedException("BinaryTreeEndNode::setLeftChild()");
        }

        /**
         * Gets the node of a right child.
         */
        template<typename TKey, typename TValue>
        IBinaryTreeNodePtr<TKey, TValue> BinaryTreeEndNode<TKey, TValue>::getRightChild() const
        {
            throw NotImplementedException("BinaryTreeEndNode::getRightChild()");
        }

        /**
         * Sets the node of a right child.
         */
        template<typename TKey, typename TValue>
        void BinaryTreeEndNode<TKey, TValue>::setRightChild(IBinaryTreeNodePtr<TKey, TValue> child)
        {
            throw NotImplementedException("BinaryTreeEndNode::setRightChild()");
        }

        /**
         * Checks whether there is a left child.
         */
        template<typename TKey, typename TValue>
        bool BinaryTreeEndNode<TKey, TValue>::hasLeftChild() const
        {
            throw NotImplementedException("BinaryTreeEndNode::hasLeftChild()");
        }

        /**
         * Checks whether there is a right child.
         */
        template<typename TKey, typename TValue>
        bool BinaryTreeEndNode<TKey, TValue>::hasRightChild() const
        {
            throw NotImplementedException("BinaryTreeEndNode::hasRightChild()");
        }
    }
}

#endif // BINARY_TREE_END_NODE_H_d791982e_f581_45ab_a75a_d2fe298069c9
