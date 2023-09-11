#ifndef BIT32_ARRAY_ITERATOR_H_e710c65f_207c_4302_bbed_31ef389b1edc
#define BIT32_ARRAY_ITERATOR_H_e710c65f_207c_4302_bbed_31ef389b1edc

#include "IIterator.h"

namespace datastructures {
    namespace bitarray {

        class IBit32Array;

        /**
         * The Bit32ArrayIterator class implements an iterator of a bit 32 array.
         */
        class Bit32ArrayIterator final : public base::IIterator<bool>
        {
        public:
            /**
             * Creates an iterator of a bit 32 array.
             */
            static base::IIteratorPtr<bool> make(const IBit32Array& bitArray);

            /**
             * The Bit32ArrayIterator constructor.
             */
            explicit Bit32ArrayIterator(const IBit32Array& bitArray);

            /**
             * The Bit32ArrayIterator destructor.
             */
            virtual ~Bit32ArrayIterator();

            /**
             * The copy/move constructors.
             */
            Bit32ArrayIterator(const Bit32ArrayIterator&) = delete;
            Bit32ArrayIterator(Bit32ArrayIterator&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            Bit32ArrayIterator& operator=(const Bit32ArrayIterator&) = delete;
            Bit32ArrayIterator& operator=(Bit32ArrayIterator&&) = delete;

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
            const IBit32Array& m_bitArray;
            size_t m_currIndex;
        };

    }
}

#endif // BIT32_ARRAY_ITERATOR_H_e710c65f_207c_4302_bbed_31ef389b1edc
