#ifndef I_BIT_ARRAY_H_039397dc_65db_4f96_ac8e_c71ba80a99b0
#define I_BIT_ARRAY_H_039397dc_65db_4f96_ac8e_c71ba80a99b0

#include <vector>
#include "IBit32Array.h"

namespace datastructures {
    namespace bitarray {

        /**
         * The IBitArray interface defines a bit array, which manages a compact array of bits.
         */
        class IBitArray
        {
        public:
            /**
             * The IBitArray constructor.
             */
            IBitArray() = default;

            /**
             * The IBitArray destructor.
             */
            virtual ~IBitArray() = default;

            /**
             * The copy/move constructors.
             */
            IBitArray(const IBitArray&) = delete;
            IBitArray(IBitArray&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            IBitArray& operator=(const IBitArray&) = delete;
            IBitArray& operator=(IBitArray&&) = delete;

            /**
             * Turns on a bit at the specified index.
             */
            virtual void turnOn(size_t index) = 0;

            /**
             * Turns off a bit at the specified index.
             */
            virtual void turnOff(size_t index) = 0;

            /**
             * Checks whether a bit at the specified index is on.
             */
            virtual bool isOn(size_t index) const = 0;

            /**
             * Checks whether a bit at the specified index is off.
             */
            virtual bool isOff(size_t index) const = 0;

            /**
             * Sets a value of a bit at the specified index.
             */
            virtual void set(size_t index, unsigned int value) = 0;

            /**
             * Gets a value of a bit at the specified index.
             */
            virtual int get(size_t index) const = 0;

            /**
             * Sets the bits to the complement of its current value.
             */
            virtual void flip() = 0;

            /**
             * Sets the bit at the specified index to the complement of its current value.
             */
            virtual void flip(size_t index) = 0;

            /**
             * Returns the number of bits set to true.
             */
            virtual size_t cardinality() const = 0;

            /**
             * Sets all the bits to false.
             */
            virtual void clear() = 0;

            /**
             * Sets all the bits at the specified range to false.
             */
            virtual void clear(size_t startIndex, size_t endIndex) = 0;

            /**
             * Sets all the bits to true.
             */
            virtual void enable() = 0;

            /**
             * Sets all the bits at the specified range to true.
             */
            virtual void enable(size_t startIndex, size_t endIndex) = 0;

            /**
             * Performs a logical AND on this bit array with the other bit array.
             */
            virtual void andOperator(const IBitArray& other) = 0;

            /**
             * Performs a logical OR on this bit array with the other bit array.
             */
            virtual void orOperator(const IBitArray& other) = 0;

            /**
             * Performs a logical XOR on this bit array with the other bit array.
             */
            virtual void xorOperator(const IBitArray& other) = 0;

            /**
             * Performs a logical NOT on this bit array.
             */
            virtual void notOperator(const IBitArray& other) = 0;

            /**
             * Performs a logical bit operator on this bit array with the other bit array.
             */
            virtual void operate(const BinaryBitOperator& bitOperator, const IBitArray& other) = 0;

            /**
             * Performs a logical bit operator on this bit array.
             */
            virtual void operate(const UnaryBitOperator& bitOperator) = 0;

            /**
             * Converts the bits to a native array.
             */
            virtual std::vector<unsigned int> toArray() const = 0;

            /**
             * Converts the bits to a 32 bit array.
             */
            virtual const std::vector<IBit32ArrayPtr>& toBit32Array() const = 0;

        private:
        };

        using IBitArrayPtr = std::shared_ptr<IBitArray>;

        /**
         * Defines the equivalent operator.
         */
        inline bool operator<(const IBitArray& left, const IBitArray& right)
        {
            return true;
        }
    }
}

#endif // I_BIT_ARRAY_H_039397dc_65db_4f96_ac8e_c71ba80a99b0
