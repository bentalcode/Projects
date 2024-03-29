#ifndef BINARY_TREE_STREAM_BUILDER_H_d9faa47e_f0ac_4013_9fe6_bde26cd1b015
#define BINARY_TREE_STREAM_BUILDER_H_d9faa47e_f0ac_4013_9fe6_bde26cd1b015

#include "IBuilder.h"
#include "IBinaryTree.h"
#include "BinaryTree.h"
#include "IBinaryTreeNodeIterator.h"
#include "BinaryTreeNodeListIterator.h"

namespace datastructures {
    namespace binarytree {

        /**
         * The BinaryTreeStreamBuilder class implements a builder for a binary tree from a stream.
         */
        template <typename TKey, typename TValue>
        class BinaryTreeStreamBuilder final : public base::IBuilder<IBinaryTreeSharedPtr<TKey, TValue>>
        {
        public:
            /**
             * Builds a binary tree from a list of nodes.
             */
            static IBinaryTreeSharedPtr<TKey, TValue> Build(const std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>>& nodes);

        private:
            /**
             * The BinaryTreeStreamBuilder constructor.
             */
            BinaryTreeStreamBuilder(IBinaryTreeNodeIterator<IBinaryTreeNodeSharedPtr<TKey, TValue>>& iterator);

        public:
            /**
             * The BinaryTreeStreamBuilder destructor.
             */
            virtual ~BinaryTreeStreamBuilder();

            /**
             * The Copy/move constructors.
             */
            BinaryTreeStreamBuilder(const BinaryTreeStreamBuilder&) = delete;
            BinaryTreeStreamBuilder(BinaryTreeStreamBuilder&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            BinaryTreeStreamBuilder& operator=(const BinaryTreeStreamBuilder&) = delete;
            BinaryTreeStreamBuilder& operator=(BinaryTreeStreamBuilder&&) = delete;

            /**
             * Builds the binary tree.
             */
            virtual IBinaryTreeSharedPtr<TKey, TValue> Build() override;

        private:
            /**
             * Reads the tree from an input stream.
             */
            IBinaryTreeNodeSharedPtr<TKey, TValue> read(IBinaryTreeNodeIterator<IBinaryTreeNodeSharedPtr<TKey, TValue>>& iterator);

            IBinaryTreeNodeIterator<IBinaryTreeNodeSharedPtr<TKey, TValue>>& m_iterator;
        };

        /**
         * Builds a binary tree from a list of nodes.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeSharedPtr<TKey, TValue> BinaryTreeStreamBuilder<TKey, TValue>::Build(const std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>>& nodes)
        {
            IBinaryTreeNodeIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> iterator =
                BinaryTreeNodeListIterator<TKey, TValue>::Make(nodes);

            BinaryTreeStreamBuilder builder(*iterator);
            IBinaryTreeSharedPtr<TKey, TValue> tree = builder.Build();

            return tree;
        }

        /**
         * The BinaryTreeStreamBuilder constructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreeStreamBuilder<TKey, TValue>::BinaryTreeStreamBuilder(IBinaryTreeNodeIterator<IBinaryTreeNodeSharedPtr<TKey, TValue>>& iterator) :
            m_iterator(iterator)
        {
        }

        /**
         * The BinaryTreeStreamBuilder destructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreeStreamBuilder<TKey, TValue>::~BinaryTreeStreamBuilder()
        {
        }

        /**
         * Builds the binary tree.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeSharedPtr<TKey, TValue> BinaryTreeStreamBuilder<TKey, TValue>::Build()
        {
            bool previousStatus = m_iterator.GetSkipIterator()->DisableSkipElements();
            IBinaryTreeNodeSharedPtr<TKey, TValue> rootNode = read(m_iterator);
            m_iterator.GetSkipIterator()->SetSkipElementsStatus(previousStatus);

            IBinaryTreeSharedPtr<TKey, TValue> tree(new BinaryTree<TKey, TValue>(rootNode));

            return tree;
        }

        /**
         * Reads the tree from an input stream.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeNodeSharedPtr<TKey, TValue> BinaryTreeStreamBuilder<TKey, TValue>::read(
            IBinaryTreeNodeIterator<IBinaryTreeNodeSharedPtr<TKey, TValue>>& iterator)
        {
            if (!iterator.HasNext()) {
                return nullptr;
            }

            IBinaryTreeNodeSharedPtr<TKey, TValue> rootNode = iterator.Next();

            if (iterator.GetSkipIterator()->IsSkipElement(typeid(*rootNode))) {
                return nullptr;
            }

            if (iterator.HasNext()) {
                IBinaryTreeNodeSharedPtr<TKey, TValue> childNode = read(iterator);

                if (childNode != nullptr) {
                    rootNode->SetLeftChild(childNode);
                }
            }

            if (iterator.HasNext()) {
                IBinaryTreeNodeSharedPtr<TKey, TValue> childNode = read(iterator);

                if (childNode != nullptr) {
                    rootNode->SetRightChild(childNode);
                }
            }

            return rootNode;
        }
    }
}

#endif // BINARY_TREE_STREAM_BUILDER_H_d9faa47e_f0ac_4013_9fe6_bde26cd1b015
