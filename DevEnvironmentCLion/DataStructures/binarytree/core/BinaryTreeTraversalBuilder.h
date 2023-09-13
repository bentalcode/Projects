#ifndef BINARY_TREE_TRAVERSAL_BUILDER_H_cd890927_be3e_4a42_bf7d_7b2a7cdfdf12
#define BINARY_TREE_TRAVERSAL_BUILDER_H_cd890927_be3e_4a42_bf7d_7b2a7cdfdf12

#include "IBuilder.h"
#include "IBinaryTree.h"
#include "BinaryTreeException.h"

namespace datastructures {
    namespace binarytree {

        /**
         * The BinaryTreeTraversalBuilder abstract base class implements a builder of a binary tree
         * from various traversals.
         */
        template <typename TKey, typename TValue>
        class BinaryTreeTraversalBuilder : public base::IBuilder<IBinaryTreeSharedPtr<TKey, TValue>>
        {
        public:
            /**
             * The BinaryTreeTraversalBuilder constructor.
             */
            BinaryTreeTraversalBuilder();

            /**
             * The BinaryTreeTraversalBuilder destructor.
             */
            virtual ~BinaryTreeTraversalBuilder();

        protected:
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
        };

        /**
         * The BinaryTreeTraversalBuilder constructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreeTraversalBuilder<TKey, TValue>::BinaryTreeTraversalBuilder()
        {
        }

        /**
         * The BinaryTreeTraversalBuilder destructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreeTraversalBuilder<TKey, TValue>::~BinaryTreeTraversalBuilder()
        {
        }

        /**
         * Creates an index map.
         */
        template <typename TKey, typename TValue>
        void BinaryTreeTraversalBuilder<TKey, TValue>::createIndexMap(
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
        size_t BinaryTreeTraversalBuilder<TKey, TValue>::getNodeIndex(
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

#endif // BINARY_TREE_TRAVERSAL_BUILDER_H_cd890927_be3e_4a42_bf7d_7b2a7cdfdf12
