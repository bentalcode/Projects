#ifndef BIT_ARRAY_ITERATOR_H_d5996173_1845_4fb4_9a9a_058604756714
#define BIT_ARRAY_ITERATOR_H_d5996173_1845_4fb4_9a9a_058604756714

#include "IIterator.h"

namespace datastructures {
    namespace bitarray {

        class IBitArray;

        /**
         * The BitArrayIterator class implements an iterator of a bit array.
         */
        class BitArrayIterator final : public base::IIterator<bool>
        {
        public:
            /**
             * Creates an iterator of a bit array.
             */
            static base::IIteratorSharedPtr<bool> Make(const IBitArray& bitArray);

            /**
             * The BitArrayIterator constructor.
             */
            explicit BitArrayIterator(const IBitArray& bitArray);

            /**
             * The BitArrayIterator destructor.
             */
            virtual ~BitArrayIterator();

            /**
             * The Copy/move constructors.
             */
            BitArrayIterator(const BitArrayIterator&) = delete;
            BitArrayIterator(BitArrayIterator&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            BitArrayIterator& operator=(const BitArrayIterator&) = delete;
            BitArrayIterator& operator=(BitArrayIterator&&) = delete;

            /**
             * Checks whether there is a next element.
             */
            virtual bool HasNext() const override;

            /**
             * Gets the next element.
             */
            virtual bool Next() override;

            /**
             * Resets the iterator.
             */
            virtual void Reset() override;

        private:
            const IBitArray& m_bitArray;
            size_t m_currIndex;
        };

    }
}

#endif // BIT_ARRAY_ITERATOR_H_d5996173_1845_4fb4_9a9a_058604756714
