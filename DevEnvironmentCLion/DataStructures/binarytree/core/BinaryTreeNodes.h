#ifndef BINARY_TREE_NODES_H_0444acd1_1b24_4243_ba4a_0bd34f7a64bf
#define BINARY_TREE_NODES_H_0444acd1_1b24_4243_ba4a_0bd34f7a64bf

#include "IBinaryTreeNode.h"
#include "BinaryTreeNode.h"
#include "BinaryTreeEndNode.h"

namespace datastructures {
    namespace binarytree {

        /**
         * The BinaryTreeNodes class implements a factory for creating nodes of a binary tree.
         */
        class BinaryTreeNodes final
        {
        public:
            /**
             * Creates a new binary tree node.
             */
            template<typename TKey, typename TValue>
            static IBinaryTreeNodePtr<TKey, TValue> nodePtr(TKey key, TValue value);

            /**
             * Creates a new binary tree end node.
             */
            template<typename TKey, typename TValue>
            static IBinaryTreeNodePtr<TKey, TValue> endNode();

        private:
            /**
             * Disables the default constructor, this is a static class.
             */
            BinaryTreeNodes() = delete;
            ~BinaryTreeNodes() = delete;
        };

        /**
         * Creates a new binary tree node.
         */
        template<typename TKey, typename TValue>
        IBinaryTreeNodePtr<TKey, TValue> BinaryTreeNodes::nodePtr(TKey key, TValue value) {
            return IBinaryTreeNodePtr<TKey, TValue>(new BinaryTreeNode<TKey, TValue>(key, value));
        }

        /**
         * Creates a new binary tree end node.
         */
        template<typename TKey, typename TValue>
        IBinaryTreeNodePtr<TKey, TValue> BinaryTreeNodes::endNode() {
            return IBinaryTreeNodePtr<TKey, TValue>(new BinaryTreeEndNode<TKey, TValue>());
        }
    }
}

#endif // BINARY_TREE_NODES_H_0444acd1_1b24_4243_ba4a_0bd34f7a64bf
