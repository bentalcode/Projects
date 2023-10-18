#ifndef I_BINARY_TREE_NODE_H_d20c8d2a_2381_4b5b_b0eb_0bad8074f48b
#define I_BINARY_TREE_NODE_H_d20c8d2a_2381_4b5b_b0eb_0bad8074f48b

#include <memory>

namespace datastructures {
    namespace binarytree {

        /**
         * The IBinaryTreeNode interface defines defines a node of a binary tree.
         */
        template <typename TKey, typename TValue>
        class IBinaryTreeNode
        {
        public:
            /**
             * The constructor.
             */
            IBinaryTreeNode() = default;

            /**
             * The destructor.
             */
            virtual ~IBinaryTreeNode() = default;

            /**
             * The Copy/move constructors.
             */
            IBinaryTreeNode(const IBinaryTreeNode&) = delete;
            IBinaryTreeNode(IBinaryTreeNode&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            IBinaryTreeNode& operator=(const IBinaryTreeNode&) = delete;
            IBinaryTreeNode& operator=(IBinaryTreeNode&&) = delete;

            /**
             * Gets the key of the node.
             */
            virtual const TKey& GetKey() const = 0;

            /**
             * Sets the key of the node.
             */
            virtual void SetKey(const TKey& key) = 0;

            /**
             * Gets the value of the node.
             */
            virtual const TValue& GetValue() const = 0;

            /**
             * Sets the value of the node.
             */
            virtual void SetValue(const TValue& value) = 0;

            /**
             * Gets the node of a left child.
             */
            virtual std::shared_ptr<IBinaryTreeNode<TKey, TValue>> GetLeftChild() const = 0;

            /**
             * Sets the node of a left child.
             */
            virtual void SetLeftChild(std::shared_ptr<IBinaryTreeNode<TKey, TValue>> node) = 0;

            /**
             * Gets the node of a right child.
             */
            virtual std::shared_ptr<IBinaryTreeNode<TKey, TValue>> GetRightChild() const = 0;

            /**
             * Sets the node of a right child.
             */
            virtual void SetRightChild(std::shared_ptr<IBinaryTreeNode<TKey, TValue>> node) = 0;

            /**
             * Checks whether there is a left child.
             */
            virtual bool HasLeftChild() const = 0;

            /**
             * Checks whether there is a right child.
             */
            virtual bool HasRightChild() const = 0;
        };

        /**
         * Defines SharedPtr ofBinary Tree Node.
         */
        template <typename TKey, typename TValue>
        using IBinaryTreeNodeSharedPtr = std::shared_ptr<IBinaryTreeNode<TKey, TValue>>;

        /**
         * Implements an operator equals for binary tree nodes.
         */
        template <typename TKey, typename TValue>
        inline bool operator==(
            const IBinaryTreeNode<TKey, TValue>& lhs,
            const IBinaryTreeNode<TKey, TValue>& rhs)
        {
            return
                lhs.GetKey() == rhs.GetKey() &&
                lhs.GetValue() == rhs.GetValue();
        }

        /**
         * Implements an operator not equals for binary tree nodes.
         */
        template <typename TKey, typename TValue>
        inline bool operator!=(
            const IBinaryTreeNode<TKey, TValue>& lhs,
            const IBinaryTreeNode<TKey, TValue>& rhs)
        {
            return !(lhs == rhs);
        }

        /**
         * Implements an operator less than for binary tree nodes.
         */
        template <typename TKey, typename TValue>
        bool operator<(
            const IBinaryTreeNode<TKey, TValue>& lhs,
            const IBinaryTreeNode<TKey, TValue>& rhs)
        {
            if (lhs.GetKey() < rhs.GetKey()) {
                return true;
            }

            if (lhs.GetKey() > rhs.GetKey()) {
                return false;
            }

            return lhs.GetValue() < rhs.GetValue();
        }

        /**
         * Implements an operator less than or equal for binary tree nodes.
         */
        template <typename TKey, typename TValue>
        bool operator<=(
            const IBinaryTreeNode<TKey, TValue>& lhs,
            const IBinaryTreeNode<TKey, TValue>& rhs)
        {
            return !(rhs < lhs);
        }

        /**
         * Implements an operator greater than for binary tree nodes.
         */
        template <typename TKey, typename TValue>
        inline bool operator>(
            const IBinaryTreeNode<TKey, TValue>& lhs,
            const IBinaryTreeNode<TKey, TValue>& rhs)
        {
            return rhs < lhs;
        }

        /**
         * Implements an operator greater than or equal for binary tree nodes.
         */
        template <typename TKey, typename TValue>
        bool operator>=(
            const IBinaryTreeNode<TKey, TValue>& lhs,
            const IBinaryTreeNode<TKey, TValue>& rhs)
        {
            return !(lhs < rhs);
        }
    }
}

#endif // I_BINARY_TREE_NODE_H_d20c8d2a_2381_4b5b_b0eb_0bad8074f48b
