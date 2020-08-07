#ifndef BINARY_TREE_NODE_LIST_ITERATOR_H_940cfba4_f361_46de_8154_95a713fe8fd6
#define BINARY_TREE_NODE_LIST_ITERATOR_H_940cfba4_f361_46de_8154_95a713fe8fd6

#include "IBinaryTreeNodeIterator.h"
#include "IBinaryTreeNode.h"
#include "SkipIterator.h"
#include "BinaryTreeEndNode.h"

namespace datastructures {
    namespace binarytree {

        /**
         * The BinaryTreeNodeListIterator class implements an iterator of a list of binary nodes.
         */
        template<typename TKey, typename TValue>
        class BinaryTreeNodeListIterator final : public IBinaryTreeNodeIterator<IBinaryTreeNodePtr<TKey, TValue>>
        {
        public:
            /**
             * Creates a new iterator of a list of binary nodes.
             */
            static IBinaryTreeNodeIteratorPtr<IBinaryTreeNodePtr<TKey, TValue>> of(
                const std::vector<IBinaryTreeNodePtr<TKey, TValue>>& nodes);

        private:
            /**
             * The BinaryTreeNodeListIterator constructor.
             */
            BinaryTreeNodeListIterator(const std::vector<IBinaryTreeNodePtr<TKey, TValue>>& nodes);

        public:
            /**
             * The BinaryTreeNodeListIterator destructor.
             */
            virtual ~BinaryTreeNodeListIterator();

            /**
             * The copy/move constructors.
             */
            BinaryTreeNodeListIterator(const BinaryTreeNodeListIterator&) = delete;
            BinaryTreeNodeListIterator(BinaryTreeNodeListIterator&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            BinaryTreeNodeListIterator& operator=(const BinaryTreeNodeListIterator&) = delete;
            BinaryTreeNodeListIterator& operator=(BinaryTreeNodeListIterator&&) = delete;

            /**
             * Checks whether there is a next element.
             */
            virtual bool hasNext() const;

            /**
             * Gets the next element.
             */
            virtual IBinaryTreeNodePtr<TKey, TValue> next();

            /**
             * Resets the iterator.
             */
            virtual void reset();

            /**
             * Gets the skip iterator.
             */
            virtual base::ISkipIteratorPtr getSkipIterator() const;

        private:
            /*
             * Gets the next position.
             */
            size_t nextPosition(size_t position);

            /*
             * Aligns the position.
             */
            size_t alignPosition(size_t position);

            std::vector<IBinaryTreeNodePtr<TKey, TValue>> m_nodes;
            size_t m_position;

            base::ISkipIteratorPtr m_skipIterator;
        };

        /**
         * Creates a new iterator of a list of binary nodes.
         */
        template<typename TKey, typename TValue>
        IBinaryTreeNodeIteratorPtr<IBinaryTreeNodePtr<TKey, TValue>> BinaryTreeNodeListIterator<TKey, TValue>::of(
            const std::vector<IBinaryTreeNodePtr<TKey, TValue>>& nodes) {

            return IBinaryTreeNodeIteratorPtr<IBinaryTreeNodePtr<TKey, TValue>>(
                new BinaryTreeNodeListIterator<TKey, TValue>(nodes));
        }

        /**
         * The BinaryTreeNodeListIterator constructor.
         */
        template<typename TKey, typename TValue>
        BinaryTreeNodeListIterator<TKey, TValue>::BinaryTreeNodeListIterator(
            const std::vector<IBinaryTreeNodePtr<TKey, TValue>>& nodes) :
            m_nodes(nodes),
            m_skipIterator(std::make_shared<base::SkipIterator>())
        {
            m_skipIterator->enableSkipElements();
            m_skipIterator->registerGenericSkipElement(typeid(BinaryTreeEndNode<TKey, TValue>));

            reset();
        }

        /**
         * The BinaryTreeNodeListIterator destructor.
         */
        template<typename TKey, typename TValue>
        BinaryTreeNodeListIterator<TKey, TValue>::~BinaryTreeNodeListIterator()
        {
        }

        /**
         * Checks whether there is a next element.
         */
        template<typename TKey, typename TValue>
        bool BinaryTreeNodeListIterator<TKey, TValue>::hasNext() const
        {
            return m_position < m_nodes.size();
        }

        /**
         * Gets the next element.
         */
        template<typename TKey, typename TValue>
        IBinaryTreeNodePtr<TKey, TValue> BinaryTreeNodeListIterator<TKey, TValue>::next()
        {
            assert(hasNext());

            IBinaryTreeNodePtr<TKey, TValue> currElement = m_nodes[m_position];
            m_position = nextPosition(m_position);

            return currElement;
        }

        /**
         * Resets the iterator.
         */
        template<typename TKey, typename TValue>
        void BinaryTreeNodeListIterator<TKey, TValue>::reset()
        {
            m_position = alignPosition(0);
        }

        /**
         * Gets the skip iterator.
         */
        template<typename TKey, typename TValue>
        base::ISkipIteratorPtr BinaryTreeNodeListIterator<TKey, TValue>::getSkipIterator() const
        {
            return m_skipIterator;
        }

        /*
         * Gets the next position.
         */
        template<typename TKey, typename TValue>
        size_t BinaryTreeNodeListIterator<TKey, TValue>::nextPosition(size_t position)
        {
            return alignPosition(position + 1);
        }

        /*
         * Aligns the position.
         */
        template<typename TKey, typename TValue>
        size_t BinaryTreeNodeListIterator<TKey, TValue>::alignPosition(size_t position)
        {
            size_t currPosition = position;

            if (!m_skipIterator->getSkipElementsStatus())
            {
                return currPosition;
            }

            while (currPosition < m_nodes.size())
            {
                IBinaryTreeNodePtr<TKey, TValue> currNode = m_nodes[currPosition];

                if (!m_skipIterator->isSkipElement(typeid(*currNode)))
                {
                    break;
                }

                ++currPosition;
            }

            return currPosition;
        }
    }
}

#endif // BINARY_TREE_NODE_LIST_ITERATOR_H_940cfba4_f361_46de_8154_95a713fe8fd6
