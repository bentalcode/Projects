#ifndef BINARY_TREE_NODE_LIST_REVERSE_ITERATOR_H_0b63f93d_cab8_49ad_81f1_96a82d41e6d8
#define BINARY_TREE_NODE_LIST_REVERSE_ITERATOR_H_0b63f93d_cab8_49ad_81f1_96a82d41e6d8

#include "IBinaryTreeNodeReverseIterator.h"

namespace datastructures {
    namespace binarytree {

        /**
         * The BinaryTreeNodeListReverseIterator class implements a reverse iterator of a list Of binary nodes.
         */
        template <typename TKey, typename TValue>
        class BinaryTreeNodeListReverseIterator final : public IBinaryTreeNodeReverseIterator<IBinaryTreeNodeSharedPtr<TKey, TValue>>
        {
        public:
            /**
             * Creates a new reverse iterator of a list Of binary nodes.
             */
            static IBinaryTreeNodeReverseIteratorSharedPtr<IBinaryTreeNodeSharedPtr < TKey, TValue>> make(
                const std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>>& nodes);

        private:
            /**
             * The BinaryTreeNodeListReverseIterator constructor.
             */
            BinaryTreeNodeListReverseIterator(const std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>>& nodes);

        public:
            /**
             * The BinaryTreeNodeListReverseIterator destructor.
             */
            virtual ~BinaryTreeNodeListReverseIterator();

            /**
             * The Copy/move constructors.
             */
            BinaryTreeNodeListReverseIterator(const BinaryTreeNodeListReverseIterator&) = delete;
            BinaryTreeNodeListReverseIterator(BinaryTreeNodeListReverseIterator&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            BinaryTreeNodeListReverseIterator& operator=(const BinaryTreeNodeListReverseIterator&) = delete;
            BinaryTreeNodeListReverseIterator& operator=(BinaryTreeNodeListReverseIterator&&) = delete;

            /**
             * Checks whether there is a Next element.
             */
            virtual bool hasNext() const;

            /**
             * Gets the Next element.
             */
            virtual IBinaryTreeNodeSharedPtr<TKey, TValue> next();

            /**
             * Resets the iterator.
             */
            virtual void reset();

            /**
             * Gets the skip iterator.
             */
            virtual base::ISkipIteratorSharedPtr getSkipIterator() const;

        private:
            /*
             * Gets the next position.
             */
            void nextPosition(
                size_t position,
                bool& endPosition,
                size_t& nextPosition);

            /*
             * Aligns the position.
             */
            void alignPosition(
                size_t position,
                bool& endPosition,
                size_t& alignedPosition);

            std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>> m_nodes;

            bool m_endPosition;
            size_t m_position;

            base::ISkipIteratorSharedPtr m_skipIterator;
        };

        /**
         * Creates a new reverse iterator of a list Of binary nodes.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeNodeReverseIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> BinaryTreeNodeListReverseIterator<TKey, TValue>::make(
            const std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>>& nodes) {

            return IBinaryTreeNodeReverseIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>>(
                new BinaryTreeNodeListReverseIterator<TKey, TValue>(nodes));
        }

        /**
         * The BinaryTreeNodeListReverseIterator constructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreeNodeListReverseIterator<TKey, TValue>::BinaryTreeNodeListReverseIterator(
            const std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>>& nodes) :
            m_nodes(nodes),
            m_skipIterator(std::make_shared<base::SkipIterator>())
        {
            m_skipIterator->enableSkipElements();
            m_skipIterator->registerGenericSkipElement(typeid(BinaryTreeEndNode<TKey, TValue>));

            reset();
        }

        /**
         * The BinaryTreeNodeListReverseIterator destructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreeNodeListReverseIterator<TKey, TValue>::~BinaryTreeNodeListReverseIterator()
        {
        }

        /**
         * Checks whether there is a Next element.
         */
        template <typename TKey, typename TValue>
        bool BinaryTreeNodeListReverseIterator<TKey, TValue>::hasNext() const
        {
            return !m_endPosition;
        }

        /**
         * Gets the Next element.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeNodeSharedPtr<TKey, TValue> BinaryTreeNodeListReverseIterator<TKey, TValue>::next()
        {
            assert(hasNext());

            IBinaryTreeNodeSharedPtr<TKey, TValue> currElement = m_nodes[m_position];

            bool endPositionResult = false;
            size_t nextPositionResult = 0;

            nextPosition(m_position, endPositionResult, nextPositionResult);

            m_endPosition = endPositionResult;
            m_position = nextPositionResult;

            return currElement;
        }

        /**
         * Resets the iterator.
         */
        template <typename TKey, typename TValue>
        void BinaryTreeNodeListReverseIterator<TKey, TValue>::Reset()
        {
            if (!m_nodes.Empty())
            {
                alignPosition(m_nodes.Size() - 1, m_endPosition, m_position);
            }
            else {
                m_endPosition = true;
                m_position = 0;
            }
        }

        /**
         * Gets the skip iterator.
         */
        template <typename TKey, typename TValue>
        base::ISkipIteratorSharedPtr BinaryTreeNodeListReverseIterator<TKey, TValue>::getSkipIterator() const
        {
            return m_skipIterator;
        }

        /*
         * Gets the next position.
         */
        template <typename TKey, typename TValue>
        void BinaryTreeNodeListReverseIterator<TKey, TValue>::nextPosition(
            size_t position,
            bool& endPosition,
            size_t& nextPosition)
        {
            if (position >= 1)
            {
                alignPosition(position - 1, endPosition, nextPosition);
            }
            else
            {
                endPosition = true;
                nextPosition = 0;
            }
        }

        /*
         * Aligns the position.
         */
        template <typename TKey, typename TValue>
        void BinaryTreeNodeListReverseIterator<TKey, TValue>::alignPosition(
            size_t position,
            bool& endPosition,
            size_t& alignedPosition)
        {
            size_t currPosition = position;

            if (!m_skipIterator->getSkipElementsStatus())
            {
                endPosition = false;
                alignedPosition = currPosition;

                return;
            }

            while (currPosition >= 0)
            {
                IBinaryTreeNodeSharedPtr<TKey, TValue> currNode = m_nodes[currPosition];

                if (!m_skipIterator->isSkipElement(typeid(*currNode)))
                {
                    endPosition = false;
                    alignedPosition = currPosition;

                    return;
                }

                --currPosition;
            }

            endPosition = true;
            alignedPosition = 0;
        }
    }
}

#endif // BINARY_TREE_NODE_LIST_REVERSE_ITERATOR_H_0b63f93d_cab8_49ad_81f1_96a82d41e6d8
