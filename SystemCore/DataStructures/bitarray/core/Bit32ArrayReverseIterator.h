#ifndef BIT32_ARRAY_REVERSE_ITERATOR_H_fda3565c_d63e_4991_9695_ed2780e7a76e
#define BIT32_ARRAY_REVERSE_ITERATOR_H_fda3565c_d63e_4991_9695_ed2780e7a76e

#include "IReverseIterator.h"

namespace datastructures {
    namespace bitarray {

        class IBit32Array;

        /**
         * The Bit32ArrayReverseIterator class implements a reverse iterator of a bit 32 array.
         */
        class Bit32ArrayReverseIterator final : public base::IReverseIterator<bool>
        {
        public:
            /**
             * Creates a reverse iterator of a bit 32 array.
             */
            static base::IReverseIteratorSharedPtr<bool> Make(const IBit32Array& bitArray);

            /**
             * The Bit32ArrayReverseIterator constructor.
             */
            explicit Bit32ArrayReverseIterator(const IBit32Array& bitArray);

            /**
             * The Bit32ArrayReverseIterator destructor.
             */
            virtual ~Bit32ArrayReverseIterator();

            /**
             * The Copy/move constructors.
             */
            Bit32ArrayReverseIterator(const Bit32ArrayReverseIterator&) = delete;
            Bit32ArrayReverseIterator(Bit32ArrayReverseIterator&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            Bit32ArrayReverseIterator& operator=(const Bit32ArrayReverseIterator&) = delete;
            Bit32ArrayReverseIterator& operator=(Bit32ArrayReverseIterator&&) = delete;

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
            const IBit32Array& m_bitArray;
            size_t m_currIndex;
            bool m_end;
        };

    }
}

#endif // BIT32_ARRAY_REVERSE_ITERATOR_H_fda3565c_d63e_4991_9695_ed2780e7a76e
