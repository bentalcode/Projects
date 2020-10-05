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
        class BinaryTreeStreamBuilder final : public base::IBuilder<IBinaryTreePtr<TKey, TValue>>
        {
        public:
            /**
             * Builds a binary tree from a list of nodes.
             */
            static IBinaryTreePtr<TKey, TValue> build(const std::vector<IBinaryTreeNodePtr<TKey, TValue>>& nodes);

        private:
            /**
             * The BinaryTreeStreamBuilder constructor.
             */
            BinaryTreeStreamBuilder(IBinaryTreeNodeIterator<IBinaryTreeNodePtr<TKey, TValue>>& iterator);

        public:
            /**
             * The BinaryTreeStreamBuilder destructor.
             */
            virtual ~BinaryTreeStreamBuilder();

            /**
             * The copy/move constructors.
             */
            BinaryTreeStreamBuilder(const BinaryTreeStreamBuilder&) = delete;
            BinaryTreeStreamBuilder(BinaryTreeStreamBuilder&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            BinaryTreeStreamBuilder& operator=(const BinaryTreeStreamBuilder&) = delete;
            BinaryTreeStreamBuilder& operator=(BinaryTreeStreamBuilder&&) = delete;

            /**
             * Builds the binary tree.
             */
            IBinaryTreePtr<TKey, TValue> build();

        private:
            /**
             * Reads the tree from an input stream.
             */
            IBinaryTreeNodePtr<TKey, TValue> read(IBinaryTreeNodeIterator<IBinaryTreeNodePtr<TKey, TValue>>& iterator);

            IBinaryTreeNodeIterator<IBinaryTreeNodePtr<TKey, TValue>>& m_iterator;
        };

        /**
         * Builds a binary tree from a list of nodes.
         */
        template <typename TKey, typename TValue>
        IBinaryTreePtr<TKey, TValue> BinaryTreeStreamBuilder<TKey, TValue>::build(const std::vector<IBinaryTreeNodePtr<TKey, TValue>>& nodes)
        {
            IBinaryTreeNodeIteratorPtr<IBinaryTreeNodePtr<TKey, TValue>> iterator =
                BinaryTreeNodeListIterator<TKey, TValue>::make(nodes);

            BinaryTreeStreamBuilder builder(*iterator);
            IBinaryTreePtr<TKey, TValue> tree = builder.build();

            return tree;
        }

        /**
         * The BinaryTreeStreamBuilder constructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreeStreamBuilder<TKey, TValue>::BinaryTreeStreamBuilder(IBinaryTreeNodeIterator<IBinaryTreeNodePtr<TKey, TValue>>& iterator) :
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
        IBinaryTreePtr<TKey, TValue> BinaryTreeStreamBuilder<TKey, TValue>::build()
        {
            bool previousStatus = m_iterator.getSkipIterator()->disableSkipElements();
            IBinaryTreeNodePtr<TKey, TValue> rootNode = read(m_iterator);
            m_iterator.getSkipIterator()->setSkipElementsStatus(previousStatus);

            IBinaryTreePtr<TKey, TValue> tree(new BinaryTree<TKey, TValue>(rootNode));

            return tree;
        }

        /**
         * Reads the tree from an input stream.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeNodePtr<TKey, TValue> BinaryTreeStreamBuilder<TKey, TValue>::read(
            IBinaryTreeNodeIterator<IBinaryTreeNodePtr<TKey, TValue>>& iterator)
        {
            if (!iterator.hasNext()) {
                return nullptr;
            }

            IBinaryTreeNodePtr<TKey, TValue> rootNode = iterator.next();

            if (iterator.getSkipIterator()->isSkipElement(typeid(*rootNode))) {
                return nullptr;
            }

            if (iterator.hasNext()) {
                IBinaryTreeNodePtr<TKey, TValue> childNode = read(iterator);

                if (childNode != nullptr) {
                    rootNode->setLeftChild(childNode);
                }
            }

            if (iterator.hasNext()) {
                IBinaryTreeNodePtr<TKey, TValue> childNode = read(iterator);

                if (childNode != nullptr) {
                    rootNode->setRightChild(childNode);
                }
            }

            return rootNode;
        }
    }
}

#endif // BINARY_TREE_STREAM_BUILDER_H_d9faa47e_f0ac_4013_9fe6_bde26cd1b015
