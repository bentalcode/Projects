#ifndef BINARY_TREE_DATA_H_1b17c49a_abe7_4eb4_ab03_4c8c25462e0c
#define BINARY_TREE_DATA_H_1b17c49a_abe7_4eb4_ab03_4c8c25462e0c

#include "IBinaryTreeNode.h"

using namespace datastructures::binarytree;

namespace test {
    namespace datastructures {
        namespace binarytree {

            /**
             * The BinaryTreeData class implements the data of a binary tree.
             */
            template<typename TKey, typename TValue>
            class BinaryTreeData final {
            public:
                /**
                 * The BinaryTreeData constructor.
                 */
                BinaryTreeData(
                    const std::vector<IBinaryTreeNodePtr<TKey, TValue>>& creationData,
                    const std::vector<IBinaryTreeNodePtr<TKey, TValue>>& levelOrder,
                    const std::vector<IBinaryTreeNodePtr<TKey, TValue>>& inorder,
                    const std::vector<IBinaryTreeNodePtr<TKey, TValue>>& preorder,
                    const std::vector<IBinaryTreeNodePtr<TKey, TValue>>& postorder);

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
                BinaryTreeData &operator=(const BinaryTreeData&) = delete;
                BinaryTreeData &operator=(BinaryTreeData&&) = delete;

                /**
                 * Gets the creation data.
                 */
                const std::vector<IBinaryTreeNodePtr<TKey, TValue>>& getCreationData() const;

                /**
                 * Gets the level order nodes.
                 */
                const std::vector<IBinaryTreeNodePtr<TKey, TValue>>& getLevelOrder() const;

                /**
                 * Gets the inorder nodes.
                 */
                const std::vector<IBinaryTreeNodePtr<TKey, TValue>>& getInorder() const;

                /**
                 * Gets the preorder nodes.
                 */
                const std::vector<IBinaryTreeNodePtr<TKey, TValue>>& getPreorder() const;

                /**
                 * Gets the postorder nodes.
                 */
                const std::vector<IBinaryTreeNodePtr<TKey, TValue>>& getPostorder() const;

            private:
                std::vector<IBinaryTreeNodePtr<TKey, TValue>> m_creationData;
                std::vector<IBinaryTreeNodePtr<TKey, TValue>> m_levelOrder;
                std::vector<IBinaryTreeNodePtr<TKey, TValue>> m_inorder;
                std::vector<IBinaryTreeNodePtr<TKey, TValue>> m_preorder;
                std::vector<IBinaryTreeNodePtr<TKey, TValue>> m_postorder;
            };

            template<typename TKey, typename TValue>
            using BinaryTreeDataPtr = std::shared_ptr<BinaryTreeData<TKey, TValue>>;

            /**
             * The BinaryTreeData constructor.
             */
            template<typename TKey, typename TValue>
            BinaryTreeData<TKey, TValue>::BinaryTreeData(
                const std::vector<IBinaryTreeNodePtr<TKey, TValue>>& creationData,
                const std::vector<IBinaryTreeNodePtr<TKey, TValue>>& levelOrder,
                const std::vector<IBinaryTreeNodePtr<TKey, TValue>>& inorder,
                const std::vector<IBinaryTreeNodePtr<TKey, TValue>>& preorder,
                const std::vector<IBinaryTreeNodePtr<TKey, TValue>>& postorder) :
                m_creationData (creationData),
                m_levelOrder(levelOrder),
                m_inorder(inorder),
                m_preorder(preorder),
                m_postorder(postorder) {
            }

            /**
             * The BinaryTreeData destructor.
             */
            template<typename TKey, typename TValue>
            BinaryTreeData<TKey, TValue>::~BinaryTreeData() {
            }

            /**
             * Gets the creation data.
             */
            template<typename TKey, typename TValue>
            const std::vector<IBinaryTreeNodePtr<TKey, TValue>>& BinaryTreeData<TKey, TValue>::getCreationData() const {
                return m_creationData;
            }

            /**
             * Gets the level order nodes.
             */
            template<typename TKey, typename TValue>
            const std::vector<IBinaryTreeNodePtr<TKey, TValue>>& BinaryTreeData<TKey, TValue>::getLevelOrder() const {
                return m_levelOrder;
            }

            /**
             * Gets the inorder nodes.
             */
            template<typename TKey, typename TValue>
            const std::vector<IBinaryTreeNodePtr<TKey, TValue>>& BinaryTreeData<TKey, TValue>::getInorder() const {
                return m_inorder;
            }

            /**
             * Gets the preorder nodes.
             */
            template<typename TKey, typename TValue>
            const std::vector<IBinaryTreeNodePtr<TKey, TValue>>& BinaryTreeData<TKey, TValue>::getPreorder() const {
                return m_preorder;
            }

            /**
             * Gets the postorder nodes.
             */
            template<typename TKey, typename TValue>
            const std::vector<IBinaryTreeNodePtr<TKey, TValue>>& BinaryTreeData<TKey, TValue>::getPostorder() const {
                return m_postorder;
            }
        }
    }
}

#endif // BINARY_TREE_DATA_H_1b17c49a_abe7_4eb4_ab03_4c8c25462e0c
