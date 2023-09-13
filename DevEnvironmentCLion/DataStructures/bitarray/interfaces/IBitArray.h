#ifndef I_BIT_ARRAY_H_039397dc_65db_4f96_ac8e_c71ba80a99b0
#define I_BIT_ARRAY_H_039397dc_65db_4f96_ac8e_c71ba80a99b0

#include "IBit32Array.h"

namespace base {
    class IUnaryBitOperator;
    class IBinaryBitOperator;
};

namespace datastructures {
    namespace bitarray {

        /**
         * The IBitArray interface defines a bit array, which manages a compact array of bits.
         */
        class IBitArray :
            public base::ISizableCollection,
            public base::IIterable<bool>,
            public base::IReverseIterable<bool>
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
            virtual size_t get(size_t index) const = 0;

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
            virtual void notOperator() = 0;

            /**
             * Performs a logical bit operator on this bit array with the other bit array.
             */
            virtual void operate(const base::IBinaryBitOperator& bitOperator, const IBitArray& other) = 0;

            /**
             * Performs a logical bit operator on this bit array.
             */
            virtual void operate(const base::IUnaryBitOperator& bitOperator) = 0;

            /**
             * Converts the bits to a native array.
             */
            virtual std::vector<unsigned int> toArray() const = 0;

            /**
             * Converts the bits to a bit 32 array.
             */
            virtual const std::vector<IBit32ArraySharedPtr>& toBit32Array() const = 0;
        };

        /**
         * Defines the SharedPtr of Bit Array.
         */
        using IBitArraySharedPtr = std::shared_ptr<IBitArray>;

        /**
         * Defines the equivalent operator.
         */
        inline bool operator<(const IBitArray& left, const IBitArray& right)
        {
            const std::vector<IBit32ArraySharedPtr>& leftArray = left.toBit32Array();
            const std::vector<IBit32ArraySharedPtr>& rightArray = right.toBit32Array();

            return std::lexicographical_compare(
                leftArray.begin(),
                leftArray.end(),
                rightArray.begin(),
                rightArray.end(),
                base::DereferenceLess<IBit32ArraySharedPtr>());
        }
    }
}

#endif // I_BIT_ARRAY_H_039397dc_65db_4f96_ac8e_c71ba80a99b0
