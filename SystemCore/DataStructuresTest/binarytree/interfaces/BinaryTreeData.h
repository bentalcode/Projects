#ifndef BINARY_TREE_DATA_H_1b17c49a_abe7_4eb4_ab03_4c8c25462e0c
#define BINARY_TREE_DATA_H_1b17c49a_abe7_4eb4_ab03_4c8c25462e0c

#include "IBinaryTreeNode.h"
#include <vector>
#include <algorithm>

using namespace datastructures::binarytree;

namespace test {
    namespace datastructures {
        namespace binarytree {

            /**
             * The BinaryTreeData class implements the data of a binary tree.
             */
            template <typename TKey, typename TValue>
            class BinaryTreeData final {
            public:
                /**
                 * The BinaryTreeData constructor.
                 */
                BinaryTreeData(
                    const std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>>& creationData,
                    const std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>>& levelOrder,
                    const std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>>& inorder,
                    const std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>>& preorder,
                    const std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>>& postorder);

                /**
                 * The BinaryTreeData destructor.
                 */
                ~BinaryTreeData();

                /**
                 * The copy/move constructors.
                 */
                BinaryTreeData(const BinaryTreeData&) = delete;
                BinaryTreeData(BinaryTreeData&&) = delete;

                /**
                 * The copy/move assignment operators.
                 */
                BinaryTreeData& operator=(const BinaryTreeData&) = delete;
                BinaryTreeData& operator=(BinaryTreeData&&) = delete;

                /**
                 * Gets the creation data.
                 */
                const std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>>& GetCreationData() const;

                /**
                 * Gets the level order nodes.
                 */
                const std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>>& GetLevelOrder() const;

                /**
                 * Gets the inorder nodes.
                 */
                const std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>>& GetInorder() const;

                /**
                 * Gets the preorder nodes.
                 */
                const std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>>& GetPreorder() const;

                /**
                 * Gets the postorder nodes.
                 */
                const std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>>& GetPostorder() const;

                /**
                 * Gets the level order data.
                 */
                std::vector<std::pair<TKey, TValue>> GetLevelOrderData() const;

                /**
                 * Gets the inorder data.
                 */
                std::vector<std::pair<TKey, TValue>> GetInorderData() const;

                /**
                 * Gets the preorder data.
                 */
                std::vector<std::pair<TKey, TValue>> GetPreorderData() const;

                /**
                 * Gets the postorder data.
                 */
                std::vector<std::pair<TKey, TValue>> GetPostorderData() const;

            private:
                /**
                 * Transforms the nodes to key values.
                 */
                static void nodesToKeyValues(
                    const std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>>& nodes,
                    std::vector<std::pair<TKey, TValue>>& keyValues);
                
                std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>> m_creationData;
                std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>> m_levelOrder;
                std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>> m_inorder;
                std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>> m_preorder;
                std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>> m_postorder;
            };

            //
            // Defines the SharedPtr of Binary Tree...
            //
            template <typename TKey, typename TValue>
            using BinaryTreeDataSharedPtr = std::shared_ptr<BinaryTreeData<TKey, TValue>>;

            /**
             * The BinaryTreeData constructor.
             */
            template <typename TKey, typename TValue>
            BinaryTreeData<TKey, TValue>::BinaryTreeData(
                const std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>>& creationData,
                const std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>>& levelOrder,
                const std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>>& inorder,
                const std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>>& preorder,
                const std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>>& postorder) :
                m_creationData (creationData),
                m_levelOrder(levelOrder),
                m_inorder(inorder),
                m_preorder(preorder),
                m_postorder(postorder) 
            {
            }

            /**
             * The BinaryTreeData destructor.
             */
            template <typename TKey, typename TValue>
            BinaryTreeData<TKey, TValue>::~BinaryTreeData() 
            {
            }

            /**
             * Gets the creation data.
             */
            template <typename TKey, typename TValue>
            const std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>>& BinaryTreeData<TKey, TValue>::GetCreationData() const
            {
                return m_creationData;
            }

            /**
             * Gets the level order nodes.
             */
            template <typename TKey, typename TValue>
            const std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>>& BinaryTreeData<TKey, TValue>::GetLevelOrder() const
            {
                return m_levelOrder;
            }

            /**
             * Gets the inorder nodes.
             */
            template <typename TKey, typename TValue>
            const std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>>& BinaryTreeData<TKey, TValue>::GetInorder() const
            {
                return m_inorder;
            }

            /**
             * Gets the preorder nodes.
             */
            template <typename TKey, typename TValue>
            const std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>>& BinaryTreeData<TKey, TValue>::GetPreorder() const
            {
                return m_preorder;
            }

            /**
             * Gets the postorder nodes.
             */
            template <typename TKey, typename TValue>
            const std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>>& BinaryTreeData<TKey, TValue>::GetPostorder() const
            {
                return m_postorder;
            }

            /**
             * Gets the level order data.
             */
            template <typename TKey, typename TValue>
            std::vector<std::pair<TKey, TValue>> BinaryTreeData<TKey, TValue>::GetLevelOrderData() const
            {
                std::vector<std::pair<TKey, TValue>> levelOrderData;
                nodesToKeyValues(m_levelOrder, levelOrderData);
                return levelOrderData;

            }

            /**
             * Gets the inorder data.
             */
            template <typename TKey, typename TValue>
            std::vector<std::pair<TKey, TValue>> BinaryTreeData<TKey, TValue>::GetInorderData() const
            {
                std::vector<std::pair<TKey, TValue>> inorderData;
                nodesToKeyValues(m_inorder, inorderData);
                return inorderData;
            }

            /**
             * Gets the preorder data.
             */
            template <typename TKey, typename TValue>
            std::vector<std::pair<TKey, TValue>> BinaryTreeData<TKey, TValue>::GetPreorderData() const
            {
                std::vector<std::pair<TKey, TValue>> preorderData;
                nodesToKeyValues(m_preorder, preorderData);
                return preorderData;
            }

            /**
             * Gets the postorder data.
             */
            template <typename TKey, typename TValue>
            std::vector<std::pair<TKey, TValue>> BinaryTreeData<TKey, TValue>::GetPostorderData() const
            {
                std::vector<std::pair<TKey, TValue>> postorderData;
                nodesToKeyValues(m_postorder, postorderData);
                return postorderData;
            }

            /**
             * Transforms the nodes to key values.
             */
            template <typename TKey, typename TValue>
            void BinaryTreeData<TKey, TValue>::nodesToKeyValues(
                const std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>>& nodes,
                std::vector<std::pair<TKey, TValue>>& keyValues)
            {
                std::transform(
                    nodes.begin(),
                    nodes.end(),
                    std::back_inserter(keyValues),
                    [](const IBinaryTreeNodeSharedPtr<TKey, TValue>& node) -> std::pair<TKey, TValue> {
                        return std::make_pair(node->GetKey(), node->GetValue());
                    }
                );
            }
        }
    }
}

#endif // BINARY_TREE_DATA_H_1b17c49a_abe7_4eb4_ab03_4c8c25462e0c
