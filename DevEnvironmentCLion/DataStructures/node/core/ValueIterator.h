#ifndef VALUE_ITERATOR_H_514720c4_7c3f_4231_b885_cd7b562e91b9
#define VALUE_ITERATOR_H_514720c4_7c3f_4231_b885_cd7b562e91b9

#include "IIterator.h"
#include "IKeyValueNode.h"
#include "SmartPointers.h"

namespace datastructures {
    namespace node {

        /**
         * The ValueIterator class implements an iterator of values from key-value nodes.
         */
        template <typename TKey, typename TValue>
        class ValueIterator final : public base::IIterator<TValue>
        {
        public:
            /**
             * Creates a new iterator of values from key value nodes.
             */
            static base::IIteratorPtr<TValue> make(base::IIteratorPtr<IKeyValueNodePtr<TKey, TValue>> iterator);

            /**
             * The ValueIterator constructor.
             */
            explicit ValueIterator(base::IIteratorPtr<IKeyValueNodePtr<TKey, TValue>> iterator);

            /**
             * The ValueIterator destructor.
             */
            virtual ~ValueIterator();

            /**
             * The copy/move constructors.
             */
            ValueIterator(const ValueIterator&) = delete;
            ValueIterator(ValueIterator&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            ValueIterator& operator=(const ValueIterator&) = delete;
            ValueIterator& operator=(ValueIterator&&) = delete;

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
            base::IIteratorPtr<IKeyValueNodePtr<TKey, TValue>> m_iterator;
        };

        /**
         * Creates a new iterator of values from key value nodes.
         */
        template <typename TKey, typename TValue>
        base::IIteratorPtr<TValue> ValueIterator<TKey, TValue>::make(base::IIteratorPtr<IKeyValueNodePtr<TKey, TValue>> iterator)
        {
            return std::make_shared<ValueIterator<TKey, TValue>>(iterator);
        }

        /**
         * The ValueIterator constructor.
         */
        template <typename TKey, typename TValue>
        ValueIterator<TKey, TValue>::ValueIterator(base::IIteratorPtr<IKeyValueNodePtr<TKey, TValue>> iterator) :
            m_iterator(iterator)
        {
            base::SmartPointers::validate(iterator);

            reset();
        }

        /**
         * The ValueIterator destructor.
         */
        template <typename TKey, typename TValue>
        ValueIterator<TKey, TValue>::~ValueIterator()
        {
        }

        /**
         * Checks whether there is a next node.
         */
        template <typename TKey, typename TValue>
        bool ValueIterator<TKey, TValue>::hasNext() const
        {
            return m_iterator->hasNext();
        }

        /**
         * Gets the next node.
         */
        template <typename TKey, typename TValue>
        TValue ValueIterator<TKey, TValue>::next()
        {
            assert(hasNext());

            return m_iterator->next()->getValue();
        }

        /**
         * Resets the iterator.
         */
        template <typename TKey, typename TValue>
        void ValueIterator<TKey, TValue>::reset()
        {
            m_iterator->reset();
        }
    }
}

#endif // VALUE_ITERATOR_H_514720c4_7c3f_4231_b885_cd7b562e91b9
