#ifndef BINARY_TREE_PREORDER_INORDER_TRAVERSAL_BUILDER_H_791044d6_3edb_496e_a494_bad7c5a4e813
#define BINARY_TREE_PREORDER_INORDER_TRAVERSAL_BUILDER_H_791044d6_3edb_496e_a494_bad7c5a4e813

#include "IBuilder.h"
#include "IBinaryTree.h"
#include "Dimensions.h"
#include "BinaryTreeException.h"

namespace datastructures {
    namespace binarytree {

        /**
         * The BinaryTreePreorderInorderTraversalBuilder class implements a builder of a binary tree
         * from an inorder and preorder traversal.
         */
        template <typename TKey, typename TValue>
        class BinaryTreePreorderInorderTraversalBuilder final : public base::IBuilder<IBinaryTreePtr<TKey, TValue>>
        {
        public:
            /**
             * The BinaryTreePreorderInorderTraversalBuilder constructor.
             */
            BinaryTreePreorderInorderTraversalBuilder(
                const std::vector<std::pair<TKey, TValue>>& preorder,
                const std::vector<std::pair<TKey, TValue>>& inorder);

            /**
             * The BinaryTreeTraversalBuilder destructor.
             */
            virtual ~BinaryTreePreorderInorderTraversalBuilder();

            /**
             * The copy/move constructors.
             */
            BinaryTreePreorderInorderTraversalBuilder(const BinaryTreePreorderInorderTraversalBuilder&) = delete;
            BinaryTreePreorderInorderTraversalBuilder(BinaryTreePreorderInorderTraversalBuilder&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            BinaryTreePreorderInorderTraversalBuilder& operator=(const BinaryTreePreorderInorderTraversalBuilder&) = delete;
            BinaryTreePreorderInorderTraversalBuilder& operator=(BinaryTreePreorderInorderTraversalBuilder&&) = delete;

            /**
             * Builds the binary tree.
             */
            IBinaryTreePtr<TKey, TValue> build();

        private:
            /**
             * Builds the binary tree.
             */
            static IBinaryTreeNodePtr<TKey, TValue> build(
                const std::vector<std::pair<TKey, TValue>>& preorder,
                const std::vector<std::pair<TKey, TValue>>& inorder,
                size_t preorderStartIndex,
                size_t preorderEndIndex,
                size_t inorderStartIndex,
                size_t inorderEndIndex,
                const std::map<TKey, size_t>& inorderIndexMap);

            /**
             * Creates an index map.
             */
            static void createIndexMap(
                const std::vector<std::pair<TKey, TValue>>& data,
                std::map<TKey, size_t>& indexMap);

            /**
             * Gets an index of a node by a key.
             */
            static size_t getNodeIndex(
                const std::map<TKey, size_t>& indexMap,
                const TKey& key);

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
                std::string errorMessage = "The length of the preorder and inorder traversals do not match.";
                throw BinaryTreeException(errorMessage);
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
        IBinaryTreePtr<TKey, TValue> BinaryTreePreorderInorderTraversalBuilder<TKey, TValue>::build()
        {
            std::map<TKey, size_t> inorderIndexMap;
            createIndexMap(m_inorder, inorderIndexMap);

            if (m_preorder.empty()) {
                return BinaryTree<TKey, TValue>::make();
            }

            IBinaryTreeNodePtr<TKey, TValue> root = build(
                m_preorder,
                m_inorder,
                0,
                m_preorder.size() - 1,
                0,
                m_inorder.size() - 1,
                inorderIndexMap);

            return BinaryTree<TKey, TValue>::make(root);
        }

        /**
         * Builds the binary tree.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeNodePtr<TKey, TValue> BinaryTreePreorderInorderTraversalBuilder<TKey, TValue>::build(
            const std::vector<std::pair<TKey, TValue>>& preorder,
            const std::vector<std::pair<TKey, TValue>>& inorder,
            size_t preorderStartIndex,
            size_t preorderEndIndex,
            size_t inorderStartIndex,
            size_t inorderEndIndex,
            const std::map<TKey, size_t>& inorderIndexMap)
        {
            size_t preorderLength = base::Dimensions::length(preorderStartIndex, preorderEndIndex);
            size_t inorderLength = base::Dimensions::length(inorderStartIndex, inorderEndIndex);
            assert(preorderLength == inorderLength);

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

            size_t rootIndex = getNodeIndex(inorderIndexMap, rootData.first);
            size_t leftSize = base::Dimensions::length(inorderStartIndex, rootIndex - 1);

            size_t preorderLeftStartIndex = preorderStartIndex + 1;
            size_t preorderLeftEndIndex = preorderStartIndex + leftSize;
            size_t inorderLeftStartIndex = inorderStartIndex;
            size_t inorderLeftEndIndex = rootIndex - 1;

            size_t preorderRightStartIndex = preorderLeftEndIndex + 1;
            size_t preorderRightEndIndex = preorderEndIndex;
            size_t inorderRightStartIndex = rootIndex + 1;
            size_t inorderRightEndIndex = inorderEndIndex;

            IBinaryTreeNodePtr<TKey, TValue> leftChild = build(
                preorder,
                inorder,
                preorderLeftStartIndex,
                preorderLeftEndIndex,
                inorderLeftStartIndex,
                inorderLeftEndIndex,
                inorderIndexMap);

            IBinaryTreeNodePtr<TKey, TValue> rightChild = build(
                preorder,
                inorder,
                preorderRightStartIndex,
                preorderRightEndIndex,
                inorderRightStartIndex,
                inorderRightEndIndex,
                inorderIndexMap);

            root->setLeftChild(leftChild);
            root->setRightChild(rightChild);

            return root;
        }

        /**
         * Creates an index map.
         */
        template <typename TKey, typename TValue>
        void BinaryTreePreorderInorderTraversalBuilder<TKey, TValue>::createIndexMap(
            const std::vector<std::pair<TKey, TValue>>& data,
            std::map<TKey, size_t>& indexMap)
        {
            for (size_t i = 0; i < data.size(); ++i)
            {
                indexMap.insert(std::make_pair(data[i].first, i));
            }
        }

        /**
         * Gets an index of a node by a key.
         */
        template <typename TKey, typename TValue>
        size_t BinaryTreePreorderInorderTraversalBuilder<TKey, TValue>::getNodeIndex(
            const std::map<TKey, size_t>& indexMap,
            const TKey& key)
        {
            typename std::map<TKey, size_t>::const_iterator nodeIterator = indexMap.find(key);

            if (nodeIterator == indexMap.end())
            {
                std::string errorMessage =
                    "The index of node with key: " + std::to_string(key) +
                    " was not found in the index map.";

                throw BinaryTreeException(errorMessage);
            }

            return nodeIterator->second;
        }
    }
}

#endif // BINARY_TREE_PREORDER_INORDER_TRAVERSAL_BUILDER_H_791044d6_3edb_496e_a494_bad7c5a4e813
