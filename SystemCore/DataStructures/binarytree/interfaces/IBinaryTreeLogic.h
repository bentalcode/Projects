#ifndef I_BINARY_TREE_LOGIC_H_6bb31043_6108_4bac_b8cd_e1b7a876a852
#define I_BINARY_TREE_LOGIC_H_6bb31043_6108_4bac_b8cd_e1b7a876a852

#include "IBinaryTreeNode.h"

namespace datastructures {
    namespace binarytree {

        /**
         * The IBinaryTreeLogic interface defines logic of a binary tree.
         */
        template <typename TKey, typename TValue>
        class IBinaryTreeLogic
        {
        public:
            /**
             * The IBinaryTreeLogic constructor.
             */
            IBinaryTreeLogic() = default;

            /**
             * The IBinaryTreeLogic destructor.
             */
            virtual ~IBinaryTreeLogic() = default;

            /**
             * The Copy/move constructors.
             */
            IBinaryTreeLogic(const IBinaryTreeLogic&) = delete;
            IBinaryTreeLogic(IBinaryTreeLogic&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            IBinaryTreeLogic& operator=(const IBinaryTreeLogic&) = delete;
            IBinaryTreeLogic& operator=(IBinaryTreeLogic&&) = delete;

            /**
             * Gets the minimum node.
             */
            virtual IBinaryTreeNodeSharedPtr<TKey, TValue> GetMinimumNode(IBinaryTreeNodeSharedPtr<TKey, TValue> root) = 0;

            /**
             * Moves to the minimum node by storing the nodes in the stack.
             */
            virtual void MoveMinimumNode(
                IBinaryTreeNodeSharedPtr<TKey, TValue> root,
                std::stack<IBinaryTreeNodeSharedPtr<TKey, TValue>>& stack) = 0;

            /**
             * Gets the maximum node.
             */
            virtual IBinaryTreeNodeSharedPtr<TKey, TValue> GetMaximumNode(IBinaryTreeNodeSharedPtr<TKey, TValue> root) = 0;

            /**
             * Moves to the maximum node by storing the nodes in the stack.
             */
            virtual void MoveMaximumNode(
                IBinaryTreeNodeSharedPtr<TKey, TValue> root,
                std::stack<IBinaryTreeNodeSharedPtr<TKey, TValue>>& stack) = 0;
        };
    }
}

#endif // I_BINARY_TREE_LOGIC_H_6bb31043_6108_4bac_b8cd_e1b7a876a852
