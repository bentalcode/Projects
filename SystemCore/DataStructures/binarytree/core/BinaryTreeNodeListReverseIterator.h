#ifndef BINARY_TREE_NODE_LIST_REVERSE_ITERATOR_H_0b63f93d_cab8_49ad_81f1_96a82d41e6d8
#define BINARY_TREE_NODE_LIST_REVERSE_ITERATOR_H_0b63f93d_cab8_49ad_81f1_96a82d41e6d8

#include "IBinaryTreeNodeReverseIterator.h"

namespace datastructures {
    namespace binarytree {

        /**
         * The BinaryTreeNodeListReverseIterator class implements a reverse iterator of a list of binary nodes.
         */
        template <typename TKey, typename TValue>
        class BinaryTreeNodeListReverseIterator final : public IBinaryTreeNodeReverseIterator<IBinaryTreeNodeSharedPtr<TKey, TValue>>
        {
        public:
            /**
             * Creates a new reverse iterator of a list of binary nodes.
             */
            static IBinaryTreeNodeReverseIteratorSharedPtr<IBinaryTreeNodeSharedPtr < TKey, TValue>> Make(
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
             * Checks whether there is a next element.
             */
            virtual bool HasNext() const;

            /**
             * Gets the next element.
             */
            virtual IBinaryTreeNodeSharedPtr<TKey, TValue> Next();

            /**
             * Resets the iterator.
             */
            virtual void Reset();

            /**
             * Gets the skip iterator.
             */
            virtual base::ISkipIteratorSharedPtr GetSkipIterator() const;

        private:
            /*
             * Gets the next position.
             */
            void NextPosition(
                size_t position,
                bool& endPosition,
                size_t& nextPosition);

            /*
             * Aligns the position.
             */
            void AlignPosition(
                size_t position,
                bool& endPosition,
                size_t& alignedPosition);

            std::vector<IBinaryTreeNodeSharedPtr<TKey, TValue>> m_nodes;

            bool m_endPosition;
            size_t m_position;

            base::ISkipIteratorSharedPtr m_skipIterator;
        };

        /**
         * Creates a new reverse iterator of a list of binary nodes.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeNodeReverseIteratorSharedPtr<IBinaryTreeNodeSharedPtr<TKey, TValue>> BinaryTreeNodeListReverseIterator<TKey, TValue>::Make(
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
            m_skipIterator->EnableSkipElements();
            m_skipIterator->RegisterGenericSkipElement(typeid(BinaryTreeEndNode<TKey, TValue>));

            Reset();
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
        bool BinaryTreeNodeListReverseIterator<TKey, TValue>::HasNext() const
        {
            return !m_endPosition;
        }

        /**
         * Gets the next element.
         */
        template <typename TKey, typename TValue>
        IBinaryTreeNodeSharedPtr<TKey, TValue> BinaryTreeNodeListReverseIterator<TKey, TValue>::Next()
        {
            assert(HasNext());

            IBinaryTreeNodeSharedPtr<TKey, TValue> currElement = m_nodes[m_position];

            bool endPositionResult = false;
            size_t nextPositionResult = 0;

            NextPosition(m_position, endPositionResult, nextPositionResult);

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
            if (!m_nodes.empty())
            {
                AlignPosition(m_nodes.size() - 1, m_endPosition, m_position);
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
        base::ISkipIteratorSharedPtr BinaryTreeNodeListReverseIterator<TKey, TValue>::GetSkipIterator() const
        {
            return m_skipIterator;
        }

        /*
         * Gets the next position.
         */
        template <typename TKey, typename TValue>
        void BinaryTreeNodeListReverseIterator<TKey, TValue>::NextPosition(
            size_t position,
            bool& endPosition,
            size_t& nextPosition)
        {
            if (position >= 1)
            {
                AlignPosition(position - 1, endPosition, nextPosition);
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
        void BinaryTreeNodeListReverseIterator<TKey, TValue>::AlignPosition(
            size_t position,
            bool& endPosition,
            size_t& alignedPosition)
        {
            size_t currPosition = position;

            if (!m_skipIterator->GetSkipElementsStatus())
            {
                endPosition = false;
                alignedPosition = currPosition;

                return;
            }

            while (currPosition >= 0)
            {
                IBinaryTreeNodeSharedPtr<TKey, TValue> currNode = m_nodes[currPosition];

                if (!m_skipIterator->IsSkipElement(typeid(*currNode)))
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
