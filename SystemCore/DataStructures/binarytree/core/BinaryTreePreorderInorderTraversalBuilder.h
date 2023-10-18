#ifndef BINARY_TREE_PREORDER_INORDER_TRAVERSAL_BUILDER_H_791044d6_3edb_496e_a494_bad7c5a4e813
#define BINARY_TREE_PREORDER_INORDER_TRAVERSAL_BUILDER_H_791044d6_3edb_496e_a494_bad7c5a4e813

#include "BinaryTreeTraversalBuilder.h"
#include "Indexes.h"
#include <assert.h>

namespace datastructures {
    namespace binarytree {

        /**
         * The BinaryTreePreorderInorderTraversalBuilder class implements a builder of a binary tree
         * from a preorder and a inorder traversal.
         */
        template <typename TKey, typename TValue>
        class BinaryTreePreorderInorderTraversalBuilder final : public BinaryTreeTraversalBuilder<TKey, TValue>
        {
        public:
            /**
             * The BinaryTreePreorderInorderTraversalBuilder constructor.
             */
            BinaryTreePreorderInorderTraversalBuilder(
                const std::vector<std::pair<TKey, TValue>>& preorder,
                const std::vector<std::pair<TKey, TValue>>& inorder);

            /**
             * The BinaryTreePreorderInorderTraversalBuilder destructor.
             */
            virtual ~BinaryTreePreorderInorderTraversalBuilder();

            /**
             * The Copy/move constructors.
             */
            BinaryTreePreorderInorderTraversalBuilder(const BinaryTreePreorderInorderTraversalBuilder&) = delete;
            BinaryTreePreorderInorderTraversalBuilder(BinaryTreePreorderInorderTraversalBuilder&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            BinaryTreePreorderInorderTraversalBuilder& operator=(const BinaryTreePreorderInorderTraversalBuilder&) = delete;
            BinaryTreePreorderInorderTraversalBuilder& operator=(BinaryTreePreorderInorderTraversalBuilder&&) = delete;

            /**
             * Builds the binary tree.
             */
            virtual IBinaryTreeSharedPtr<TKey, TValue> Build() override;

        private:
            /**
             * Builds the binary tree.
             */
            static IBinaryTreeNodeSharedPtr<TKey, TValue> Build(
                const std::vector<std::pair<TKey, TValue>>& preorder,
                const std::vector<std::pair<TKey, TValue>>& inorder,
                size_t preorderStartIndex,
                size_t preorderEndIndex,
                size_t inorderStartIndex,
                size_t inorderEndIndex,
                const std::map<TKey, size_t>& inorderIndexMap);

            const std::vector<std::pair<TKey, TValue>>& m_preorder;
            const std::vector<std::pair<TKey, TValue>>& m_inorder;
        };

        /**
         * The BinaryTreePreorderInorderTraversalBuilder constructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreePreorderInorderTraversalBuilder<TKey, TValue>::BinaryTreePreorderInorderTraversalBuilder(
            const std::vector<std::pair<TKey, TValue>>& preorder,
            const std::vector<std::pair<TKey, TValue>>& inorder) :
                m_preorder(preorder),
                m_inorder(inorder)
        {
            if (m_preorder.size() != m_inorder.size())
            {
                long statusCode = base::ErrorCodes::INVALID_ARG;
                std::wstring errorMessage = L"The length of a preorder and an inorder traversals does not match.";

                throw BinaryTreeException(statusCode, errorMessage);
            }
        }

        /**
         * The BinaryTreePreorderInorderTraversalBuilder destructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreePreorderInorderTraversalBuilder<TKey, TValue>::~BinaryTreePreorderInorderTraversalBuilder()
        {
        }

        /**
         * Builds the binary tree.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeSharedPtr<TKey, TValue> BinaryTreePreorderInorderTraversalBuilder<TKey, TValue>::Build()
        {
            std::map<TKey, size_t> inorderIndexMap;
            BinaryTreeTraversalBuilder<TKey, TValue>::CreateIndexMap(m_inorder, inorderIndexMap);

            if (m_preorder.empty()) {
                return BinaryTree<TKey, TValue>::Make();
            }

            IBinaryTreeNodeSharedPtr<TKey, TValue> root = Build(
                m_preorder,
                m_inorder,
                0,
                m_preorder.size() - 1,
                0,
                m_inorder.size() - 1,
                inorderIndexMap);

            return BinaryTree<TKey, TValue>::Make(root);
        }

        /**
         * Builds the binary tree.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeNodeSharedPtr<TKey, TValue> BinaryTreePreorderInorderTraversalBuilder<TKey, TValue>::Build(
            const std::vector<std::pair<TKey, TValue>>& preorder,
            const std::vector<std::pair<TKey, TValue>>& inorder,
            size_t preorderStartIndex,
            size_t preorderEndIndex,
            size_t inorderStartIndex,
            size_t inorderEndIndex,
            const std::map<TKey, size_t>& inorderIndexMap)
        {
            size_t preorderLength = base::Indexes::Size(preorderStartIndex, preorderEndIndex);
            size_t inorderLength = base::Indexes::Size(inorderStartIndex, inorderEndIndex);
            assert(preorderLength == inorderLength);

            size_t length = preorderLength;

            if (length == 0)
            {
                return nullptr;
            }

            const std::pair<TKey, TValue>& rootData = preorder[preorderStartIndex];
            IBinaryTreeNodeSharedPtr<TKey, TValue> root = BinaryTreeNodes::Make(rootData.first, rootData.second);

            if (length == 1)
            {
                return root;
            }

            size_t rootIndex = BinaryTreeTraversalBuilder<TKey, TValue>::GetNodeIndex(inorderIndexMap, rootData.first);
            size_t leftSize = base::Indexes::Size(inorderStartIndex, rootIndex - 1);

            size_t preorderLeftStartIndex = preorderStartIndex + 1;
            size_t preorderLeftEndIndex = preorderStartIndex + leftSize;
            size_t inorderLeftStartIndex = inorderStartIndex;
            size_t inorderLeftEndIndex = rootIndex - 1;

            size_t preorderRightStartIndex = preorderLeftEndIndex + 1;
            size_t preorderRightEndIndex = preorderEndIndex;
            size_t inorderRightStartIndex = rootIndex + 1;
            size_t inorderRightEndIndex = inorderEndIndex;

            IBinaryTreeNodeSharedPtr<TKey, TValue> leftChild = Build(
                preorder,
                inorder,
                preorderLeftStartIndex,
                preorderLeftEndIndex,
                inorderLeftStartIndex,
                inorderLeftEndIndex,
                inorderIndexMap);

            IBinaryTreeNodeSharedPtr<TKey, TValue> rightChild = Build(
                preorder,
                inorder,
                preorderRightStartIndex,
                preorderRightEndIndex,
                inorderRightStartIndex,
                inorderRightEndIndex,
                inorderIndexMap);

            root->SetLeftChild(leftChild);
            root->SetRightChild(rightChild);

            return root;
        }

    }
}

#endif // BINARY_TREE_PREORDER_INORDER_TRAVERSAL_BUILDER_H_791044d6_3edb_496e_a494_bad7c5a4e813
