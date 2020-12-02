#ifndef BINARY_TREE_PREORDER_POSTORDER_TRAVERSAL_BUILDER_H_dfd5769c_0e62_4ce6_b93b_af395b18f845
#define BINARY_TREE_PREORDER_POSTORDER_TRAVERSAL_BUILDER_H_dfd5769c_0e62_4ce6_b93b_af395b18f845

#include "BinaryTreeTraversalBuilder.h"
#include "Indexes.h"

namespace datastructures {
    namespace binarytree {

        /**
         * The BinaryTreePreorderPostorderTraversalBuilder class implements a builder of a binary tree
         * from a preorder and a postorder traversal.
         */
        template <typename TKey, typename TValue>
        class BinaryTreePreorderPostorderTraversalBuilder final : public BinaryTreeTraversalBuilder<TKey, TValue>
        {
        public:
            /**
             * The BinaryTreePreorderPostorderTraversalBuilder constructor.
             */
            BinaryTreePreorderPostorderTraversalBuilder(
                const std::vector<std::pair<TKey, TValue>>& preorder,
                const std::vector<std::pair<TKey, TValue>>& postorder);

            /**
             * The BinaryTreePreorderPostorderTraversalBuilder destructor.
             */
            virtual ~BinaryTreePreorderPostorderTraversalBuilder();

            /**
             * The copy/move constructors.
             */
            BinaryTreePreorderPostorderTraversalBuilder(const BinaryTreePreorderPostorderTraversalBuilder&) = delete;
            BinaryTreePreorderPostorderTraversalBuilder(BinaryTreePreorderPostorderTraversalBuilder&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            BinaryTreePreorderPostorderTraversalBuilder& operator=(const BinaryTreePreorderPostorderTraversalBuilder&) = delete;
            BinaryTreePreorderPostorderTraversalBuilder& operator=(BinaryTreePreorderPostorderTraversalBuilder&&) = delete;

            /**
             * Builds the binary tree.
             */
            virtual IBinaryTreePtr<TKey, TValue> build() override;

        private:
            /**
             * Builds the binary tree.
             */
            static IBinaryTreeNodePtr<TKey, TValue> build(
                const std::vector<std::pair<TKey, TValue>>& preorder,
                const std::vector<std::pair<TKey, TValue>>& postorder,
                size_t preorderStartIndex,
                size_t preorderEndIndex,
                size_t postorderStartIndex,
                size_t postorderEndIndex,
                const std::map<TKey, size_t>& postorderIndexMap);

            const std::vector<std::pair<TKey, TValue>>& m_preorder;
            const std::vector<std::pair<TKey, TValue>>& m_postorder;
        };

        /**
         * The BinaryTreePreorderPostorderTraversalBuilder constructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreePreorderPostorderTraversalBuilder<TKey, TValue>::BinaryTreePreorderPostorderTraversalBuilder(
            const std::vector<std::pair<TKey, TValue>>& preorder,
            const std::vector<std::pair<TKey, TValue>>& postorder) :
                m_preorder(preorder),
                m_postorder(postorder)
        {
            if (m_preorder.size() != m_postorder.size())
            {
                std::string errorMessage = "The length of a preorder and a postorder traversals do not match.";
                throw BinaryTreeException(errorMessage);
            }
        }

        /**
         * The BinaryTreePreorderPostorderTraversalBuilder destructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreePreorderPostorderTraversalBuilder<TKey, TValue>::~BinaryTreePreorderPostorderTraversalBuilder()
        {
        }

        /**
         * Builds the binary tree.
         */
        template <typename TKey, typename TValue>
        IBinaryTreePtr<TKey, TValue> BinaryTreePreorderPostorderTraversalBuilder<TKey, TValue>::build()
        {
            std::map<TKey, size_t> postorderIndexMap;
            BinaryTreeTraversalBuilder<TKey, TValue>::createIndexMap(m_postorder, postorderIndexMap);

            if (m_preorder.empty()) {
                return BinaryTree<TKey, TValue>::make();
            }

            IBinaryTreeNodePtr<TKey, TValue> root = build(
                m_preorder,
                m_postorder,
                0,
                m_preorder.size() - 1,
                0,
                m_postorder.size() - 1,
                postorderIndexMap);

            return BinaryTree<TKey, TValue>::make(root);
        }

        /**
         * Builds the binary tree.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeNodePtr<TKey, TValue> BinaryTreePreorderPostorderTraversalBuilder<TKey, TValue>::build(
            const std::vector<std::pair<TKey, TValue>>& preorder,
            const std::vector<std::pair<TKey, TValue>>& postorder,
            size_t preorderStartIndex,
            size_t preorderEndIndex,
            size_t postorderStartIndex,
            size_t postorderEndIndex,
            const std::map<TKey, size_t>& postorderIndexMap)
        {
            size_t preorderLength = base::Indexes::size(preorderStartIndex, preorderEndIndex);
            size_t postorderLength = base::Indexes::size(postorderStartIndex, postorderEndIndex);
            assert(preorderLength == postorderLength);

            size_t length = preorderLength;

            if (length == 0)
            {
                return nullptr;
            }

            const std::pair<TKey, TValue>& rootData = preorder[preorderStartIndex];
            IBinaryTreeNodePtr<TKey, TValue> root = BinaryTreeNodes::make(rootData.first, rootData.second);

            if (length == 1)
            {
                return root;
            }

            const std::pair<TKey, TValue>& leftRootData = preorder[preorderStartIndex + 1];

            size_t leftRootIndex = BinaryTreeTraversalBuilder<TKey, TValue>::getNodeIndex(postorderIndexMap, leftRootData.first);
            size_t leftSize = base::Indexes::size(postorderStartIndex, leftRootIndex);

            size_t preorderLeftStartIndex = preorderStartIndex + 1;
            size_t preorderLeftEndIndex = preorderStartIndex + leftSize;
            size_t postorderLeftStartIndex = postorderStartIndex;
            size_t postorderLeftEndIndex = leftRootIndex;

            size_t preorderRightStartIndex = preorderLeftEndIndex + 1;
            size_t preorderRightEndIndex = preorderEndIndex;
            size_t postorderRightStartIndex = postorderLeftEndIndex + 1;
            size_t postorderRightEndIndex = postorderEndIndex - 1;

            IBinaryTreeNodePtr<TKey, TValue> leftChild = build(
                preorder,
                postorder,
                preorderLeftStartIndex,
                preorderLeftEndIndex,
                postorderLeftStartIndex,
                postorderLeftEndIndex,
                postorderIndexMap);

            IBinaryTreeNodePtr<TKey, TValue> rightChild = build(
                preorder,
                postorder,
                preorderRightStartIndex,
                preorderRightEndIndex,
                postorderRightStartIndex,
                postorderRightEndIndex,
                postorderIndexMap);

            root->setLeftChild(leftChild);
            root->setRightChild(rightChild);

            return root;
        }

    }
}

#endif // BINARY_TREE_PREORDER_POSTORDER_TRAVERSAL_BUILDER_H_dfd5769c_0e62_4ce6_b93b_af395b18f845
