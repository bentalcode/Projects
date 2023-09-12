#ifndef BIT_ARRAY_REVERSE_ITERATOR_H_cee0440e_7b1e_4b6c_9340_f02669ef5200
#define BIT_ARRAY_REVERSE_ITERATOR_H_cee0440e_7b1e_4b6c_9340_f02669ef5200

#include "IReverseIterator.h"

namespace datastructures {
    namespace bitarray {

        class IBitArray;

        /**
         * The BitArrayReverseIterator class implements a reverse iterator of a bit array.
         */
        class BitArrayReverseIterator final : public base::IReverseIterator<bool>
        {
        public:
            /**
             * Creates a reverse iterator of a bit array.
             */
            static base::IReverseIteratorSharedPtr<bool> make(const IBitArray& bitArray);

            /**
             * The BitArrayReverseIterator constructor.
             */
            explicit BitArrayReverseIterator(const IBitArray& bitArray);

            /**
             * The BitArrayReverseIterator destructor.
             */
            virtual ~BitArrayReverseIterator();

            /**
             * The copy/move constructors.
             */
            BitArrayReverseIterator(const BitArrayReverseIterator&) = delete;
            BitArrayReverseIterator(BitArrayReverseIterator&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            BitArrayReverseIterator& operator=(const BitArrayReverseIterator&) = delete;
            BitArrayReverseIterator& operator=(BitArrayReverseIterator&&) = delete;

            /**
             * Checks whether there is a next element.
             */
            virtual bool hasNext() const override;

            /**
             * Gets the next element.
             */
            virtual bool next() override;

            /**
             * Resets the iterator.
             */
            virtual void reset() override;

        private:
            const IBitArray& m_bitArray;
            size_t m_currIndex;
            bool m_end;
        };

    }
}

#endif // BIT_ARRAY_REVERSE_ITERATOR_H_cee0440e_7b1e_4b6c_9340_f02669ef5200
