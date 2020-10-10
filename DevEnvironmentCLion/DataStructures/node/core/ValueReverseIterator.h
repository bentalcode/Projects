#ifndef VALUE_REVERSE_ITERATOR_H_af75acd1_26bd_4924_bf9c_b188f7fa99be
#define VALUE_REVERSE_ITERATOR_H_af75acd1_26bd_4924_bf9c_b188f7fa99be

#include "IReverseIterator.h"
#include "IKeyValueNode.h"
#include "NodeException.h"

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
            static base::IReverseIteratorPtr<TValue> make(base::IReverseIteratorPtr<IKeyValueNodePtr<TKey, TValue>> reverseIterator);

            /**
             * The ValueReverseIterator constructor.
             */
            explicit ValueReverseIterator(base::IReverseIteratorPtr<IKeyValueNodePtr<TKey, TValue>> reverseIterator);

            /**
             * The ValueReverseIterator destructor.
             */
            virtual ~ValueReverseIterator();

            /**
             * The copy/move constructors.
             */
            ValueReverseIterator(const ValueReverseIterator&) = delete;
            ValueReverseIterator(ValueReverseIterator&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            ValueReverseIterator& operator=(const ValueReverseIterator&) = delete;
            ValueReverseIterator& operator=(ValueReverseIterator&&) = delete;

            /**
             * Checks whether there is a next node.
             */
            virtual bool hasNext() const override;

            /**
             * Gets the next node.
             */
            virtual TValue next() override;

            /**
             * Resets the iterator.
             */
            virtual void reset() override;

        private:
            base::IReverseIteratorPtr<IKeyValueNodePtr<TKey, TValue>> m_reverseIterator;
        };

        /**
         * Creates a new reverse iterator of values from key value nodes.
         */
        template <typename TKey, typename TValue>
        base::IReverseIteratorPtr<TValue> ValueReverseIterator<TKey, TValue>::make(
            base::IReverseIteratorPtr<IKeyValueNodePtr<TKey, TValue>> reverseIterator)
        {
            return std::make_shared<ValueReverseIterator<TKey, TValue>>(reverseIterator);
        }

        /**
         * The ValueReverseIterator constructor.
         */
        template <typename TKey, typename TValue>
        ValueReverseIterator<TKey, TValue>::ValueReverseIterator(
            base::IReverseIteratorPtr<IKeyValueNodePtr<TKey, TValue>> reverseIterator) :
            m_reverseIterator(reverseIterator)
        {
            if (!reverseIterator)
            {
                std::string errorMessage = "The reverse iterator of key-value nodes is not defined.";
                throw NodeException(errorMessage);
            }

            reset();
        }

        /**
         * The ValueReverseIterator destructor.
         */
        template <typename TKey, typename TValue>
        ValueReverseIterator<TKey, TValue>::~ValueReverseIterator()
        {
        }

        /**
         * Checks whether there is a next node.
         */
        template <typename TKey, typename TValue>
        bool ValueReverseIterator<TKey, TValue>::hasNext() const
        {
            return m_reverseIterator->hasNext();
        }

        /**
         * Gets the next node.
         */
        template <typename TKey, typename TValue>
        TValue ValueReverseIterator<TKey, TValue>::next()
        {
            assert(hasNext());

            return m_reverseIterator->next()->getValue();
        }

        /**
         * Resets the iterator.
         */
        template <typename TKey, typename TValue>
        void ValueReverseIterator<TKey, TValue>::reset()
        {
            m_reverseIterator->reset();
        }
    }
}

#endif // VALUE_REVERSE_ITERATOR_H_af75acd1_26bd_4924_bf9c_b188f7fa99be
