#ifndef VALUE_REVERSE_ITERATOR_H_af75acd1_26bd_4924_bf9c_b188f7fa99be
#define VALUE_REVERSE_ITERATOR_H_af75acd1_26bd_4924_bf9c_b188f7fa99be

#include "IReverseIterator.h"
#include "IKeyValueNode.h"
#include "NodeException.h"
#include "SmartPointers.h"

namespace datastructures {
    namespace node {

        /**
         * The ValueReverseIterator class implements a reverse iterator of values from key-value nodes.
         */
        template <typename TKey, typename TValue>
        class ValueReverseIterator final : public base::IReverseIterator<TValue>
        {
        public:
            /**
             * Creates a new reverse iterator of values from key value nodes.
             */
            static base::IReverseIteratorSharedPtr<TValue> Make(base::IReverseIteratorSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> reverseIterator);

            /**
             * The ValueReverseIterator constructor.
             */
            explicit ValueReverseIterator(base::IReverseIteratorSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> reverseIterator);

            /**
             * The ValueReverseIterator destructor.
             */
            virtual ~ValueReverseIterator();

            /**
             * The Copy/move constructors.
             */
            ValueReverseIterator(const ValueReverseIterator&) = delete;
            ValueReverseIterator(ValueReverseIterator&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            ValueReverseIterator& operator=(const ValueReverseIterator&) = delete;
            ValueReverseIterator& operator=(ValueReverseIterator&&) = delete;

            /**
             * Checks whether there is a Next node.
             */
            virtual bool HasNext() const override;

            /**
             * Gets the Next node.
             */
            virtual TValue Next() override;

            /**
             * Resets the iterator.
             */
            virtual void Reset() override;

        private:
            base::IReverseIteratorSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> m_reverseIterator;
        };

        /**
         * Creates a new reverse iterator of values from key value nodes.
         */
        template <typename TKey, typename TValue>
        base::IReverseIteratorSharedPtr<TValue> ValueReverseIterator<TKey, TValue>::Make(
            base::IReverseIteratorSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> reverseIterator)
        {
            return std::make_shared<ValueReverseIterator<TKey, TValue>>(reverseIterator);
        }

        /**
         * The ValueReverseIterator constructor.
         */
        template <typename TKey, typename TValue>
        ValueReverseIterator<TKey, TValue>::ValueReverseIterator(
            base::IReverseIteratorSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> reverseIterator) :
            m_reverseIterator(reverseIterator)
        {
            base::SmartPointers::Validate<base::IReverseIterator<IKeyValueNodeSharedPtr<TKey, TValue>>>(reverseIterator);
            Reset();
        }

        /**
         * The ValueReverseIterator destructor.
         */
        template <typename TKey, typename TValue>
        ValueReverseIterator<TKey, TValue>::~ValueReverseIterator()
        {
        }

        /**
         * Checks whether there is a Next node.
         */
        template <typename TKey, typename TValue>
        bool ValueReverseIterator<TKey, TValue>::HasNext() const
        {
            return m_reverseIterator->HasNext();
        }

        /**
         * Gets the Next node.
         */
        template <typename TKey, typename TValue>
        TValue ValueReverseIterator<TKey, TValue>::Next()
        {
            assert(HasNext());

            return m_reverseIterator->Next()->GetValue();
        }

        /**
         * Resets the iterator.
         */
        template <typename TKey, typename TValue>
        void ValueReverseIterator<TKey, TValue>::Reset()
        {
            m_reverseIterator->Reset();
        }
    }
}

#endif // VALUE_REVERSE_ITERATOR_H_af75acd1_26bd_4924_bf9c_b188f7fa99be
