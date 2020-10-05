#ifndef BINARY_TREE_NODE_LIST_REVERSE_ITERATOR_H_0b63f93d_cab8_49ad_81f1_96a82d41e6d8
#define BINARY_TREE_NODE_LIST_REVERSE_ITERATOR_H_0b63f93d_cab8_49ad_81f1_96a82d41e6d8

#include "IBinaryTreeNodeReverseIterator.h"

namespace datastructures {
    namespace binarytree {

        /**
         * The BinaryTreeNodeListReverseIterator class implements a reverse iterator of a list of binary nodes.
         */
        template <typename TKey, typename TValue>
        class BinaryTreeNodeListReverseIterator final : public IBinaryTreeNodeReverseIterator<IBinaryTreeNodePtr<TKey, TValue>>
        {
        public:
            /**
             * Creates a new reverse iterator of a list of binary nodes.
             */
            static IBinaryTreeNodeReverseIteratorPtr<IBinaryTreeNodePtr<TKey, TValue>> make(
                const std::vector<IBinaryTreeNodePtr<TKey, TValue>>& nodes);

        private:
            /**
             * The BinaryTreeNodeListReverseIterator constructor.
             */
            BinaryTreeNodeListReverseIterator(const std::vector<IBinaryTreeNodePtr<TKey, TValue>>& nodes);

        public:
            /**
             * The BinaryTreeNodeListReverseIterator destructor.
             */
            virtual ~BinaryTreeNodeListReverseIterator();

            /**
             * The copy/move constructors.
             */
            BinaryTreeNodeListReverseIterator(const BinaryTreeNodeListReverseIterator&) = delete;
            BinaryTreeNodeListReverseIterator(BinaryTreeNodeListReverseIterator&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            BinaryTreeNodeListReverseIterator& operator=(const BinaryTreeNodeListReverseIterator&) = delete;
            BinaryTreeNodeListReverseIterator& operator=(BinaryTreeNodeListReverseIterator&&) = delete;

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

            std::vector<IBinaryTreeNodePtr<TKey, TValue>> m_nodes;

            bool m_endPosition;
            size_t m_position;

            base::ISkipIteratorPtr m_skipIterator;
        };

        /**
         * Creates a new reverse iterator of a list of binary nodes.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeNodeReverseIteratorPtr<IBinaryTreeNodePtr<TKey, TValue>> BinaryTreeNodeListReverseIterator<TKey, TValue>::make(
            const std::vector<IBinaryTreeNodePtr<TKey, TValue>>& nodes) {

            return IBinaryTreeNodeReverseIteratorPtr<IBinaryTreeNodePtr<TKey, TValue>>(
                new BinaryTreeNodeListReverseIterator<TKey, TValue>(nodes));
        }

        /**
         * The BinaryTreeNodeListReverseIterator constructor.
         */
        template <typename TKey, typename TValue>
        BinaryTreeNodeListReverseIterator<TKey, TValue>::BinaryTreeNodeListReverseIterator(
            const std::vector<IBinaryTreeNodePtr<TKey, TValue>>& nodes) :
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
         * Checks whether there is a next element.
         */
        template <typename TKey, typename TValue>
        bool BinaryTreeNodeListReverseIterator<TKey, TValue>::hasNext() const
        {
            return !m_endPosition;
        }

        /**
         * Gets the next element.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeNodePtr<TKey, TValue> BinaryTreeNodeListReverseIterator<TKey, TValue>::next()
        {
            assert(hasNext());

            IBinaryTreeNodePtr<TKey, TValue> currElement = m_nodes[m_position];

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
        void BinaryTreeNodeListReverseIterator<TKey, TValue>::reset()
        {
            if (!m_nodes.empty())
            {
                alignPosition(m_nodes.size() - 1, m_endPosition, m_position);
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
        base::ISkipIteratorPtr BinaryTreeNodeListReverseIterator<TKey, TValue>::getSkipIterator() const
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
                IBinaryTreeNodePtr<TKey, TValue> currNode = m_nodes[currPosition];

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
