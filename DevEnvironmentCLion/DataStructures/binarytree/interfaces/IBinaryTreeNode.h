#ifndef I_BINARY_TREE_NODE_H_d20c8d2a_2381_4b5b_b0eb_0bad8074f48b
#define I_BINARY_TREE_NODE_H_d20c8d2a_2381_4b5b_b0eb_0bad8074f48b

namespace datastructures {
    namespace binarytree {

        /**
         * The IBinaryTreeNode interface defines defines a node of a binary tree.
         */
        template<typename TKey, typename TValue>
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
             * The copy/move constructors.
             */
            IBinaryTreeNode(const IBinaryTreeNode&) = delete;
            IBinaryTreeNode(IBinaryTreeNode&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            IBinaryTreeNode& operator=(const IBinaryTreeNode&) = delete;
            IBinaryTreeNode& operator=(IBinaryTreeNode&&) = delete;

            /**
             * Gets the key of the node.
             */
            virtual const TKey& getKey() const = 0;

            /**
             * Sets the key of the node.
             */
            virtual void setKey(const TKey& key) = 0;

            /**
             * Gets the value of the node.
             */
            virtual const TValue& getValue() const = 0;

            /**
             * Sets the value of the node.
             */
            virtual void setValue(const TValue& value) = 0;

            /**
             * Gets the node of a left child.
             */
            virtual const IBinaryTreeNode<TKey, TValue>* getLeftChild() const = 0;

            /**
             * Sets the node of a left child.
             */
            virtual void setLeftChild(IBinaryTreeNode<TKey, TValue>* node) = 0;

            /**
             * Gets the node of a right child.
             */
            virtual const IBinaryTreeNode<TKey, TValue>* getRightChild() const = 0;

            /**
             * Sets the node of a right child.
             */
            virtual void setRightChild(IBinaryTreeNode<TKey, TValue>* node) = 0;

            /**
             * Checks whether there is a left child.
             */
            virtual bool hasLeftChild() const = 0;

            /**
             * Checks whether there is a right child.
             */
            virtual bool hasRightChild() const = 0;
        };

        template <typename TKey, typename TValue>
        using IBinaryTreeNodePtr = std::shared_ptr<IBinaryTreeNode<TKey, TValue>>;
    }
}

#endif // I_BINARY_TREE_NODE_H_d20c8d2a_2381_4b5b_b0eb_0bad8074f48b
