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
            static base::IIteratorSharedPtr<TValue> Make(base::IIteratorSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> iterator);

            /**
             * The ValueIterator constructor.
             */
            explicit ValueIterator(base::IIteratorSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> iterator);

            /**
             * The ValueIterator destructor.
             */
            virtual ~ValueIterator();

            /**
             * The Copy/move constructors.
             */
            ValueIterator(const ValueIterator&) = delete;
            ValueIterator(ValueIterator&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            ValueIterator& operator=(const ValueIterator&) = delete;
            ValueIterator& operator=(ValueIterator&&) = delete;

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
            base::IIteratorSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> m_iterator;
        };

        /**
         * Creates a new iterator of values from key value nodes.
         */
        template <typename TKey, typename TValue>
        base::IIteratorSharedPtr<TValue> ValueIterator<TKey, TValue>::Make(base::IIteratorSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> iterator)
        {
            return std::make_shared<ValueIterator<TKey, TValue>>(iterator);
        }

        /**
         * The ValueIterator constructor.
         */
        template <typename TKey, typename TValue>
        ValueIterator<TKey, TValue>::ValueIterator(base::IIteratorSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> iterator) :
            m_iterator(iterator)
        {
            base::SmartPointers::Validate<base::IIterator<IKeyValueNodeSharedPtr<TKey, TValue>>>(iterator);

            Reset();
        }

        /**
         * The ValueIterator destructor.
         */
        template <typename TKey, typename TValue>
        ValueIterator<TKey, TValue>::~ValueIterator()
        {
        }

        /**
         * Checks whether there is a Next node.
         */
        template <typename TKey, typename TValue>
        bool ValueIterator<TKey, TValue>::HasNext() const
        {
            return m_iterator->HasNext();
        }

        /**
         * Gets the Next node.
         */
        template <typename TKey, typename TValue>
        TValue ValueIterator<TKey, TValue>::Next()
        {
            assert(HasNext());

            return m_iterator->Next()->GetValue();
        }

        /**
         * Resets the iterator.
         */
        template <typename TKey, typename TValue>
        void ValueIterator<TKey, TValue>::Reset()
        {
            m_iterator->Reset();
        }
    }
}

#endif // VALUE_ITERATOR_H_514720c4_7c3f_4231_b885_cd7b562e91b9
