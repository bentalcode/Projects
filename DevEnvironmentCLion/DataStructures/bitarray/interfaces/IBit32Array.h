#ifndef I_BIT32_ARRAY_LIST_H_0bb46183_5976_41c2_9d11_489a817c2391
#define I_BIT32_ARRAY_LIST_H_0bb46183_5976_41c2_9d11_489a817c2391

#include "ISizableCollection.h"
#include "IIterable.h"
#include "IReverseIterable.h"

namespace base {
    class IUnaryBitOperator;
    class IBinaryBitOperator;
};

namespace datastructures {
    namespace bitarray {

        class BinaryBitOperator;
        class UnaryBitOperator;

        /**
         * The IBit32Array interface defines a bit array of size 32.
         */
        class IBit32Array :
            public base::ISizableCollection,
            public base::IIterable<bool>,
            public base::IReverseIterable<bool>
        {
        public:
            static const size_t sizeInBits = 32;

            /**
             * The IBit32Array constructor.
             */
            IBit32Array() = default;

            /**
             * The IBit32Array destructor.
             */
            virtual ~IBit32Array() = default;

            /**
             * The copy/move constructors.
             */
            IBit32Array(const IBit32Array&) = delete;
            IBit32Array(IBit32Array&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            IBit32Array& operator=(const IBit32Array&) = delete;
            IBit32Array& operator=(IBit32Array&&) = delete;

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
            virtual unsigned int get(size_t index) const = 0;

            /**
             * Sets the bit at the specified index to the complement of its current value.
             */
            virtual void flip(size_t index) = 0;

            /**
             * Returns the number of bits set to true.
             */
            virtual size_t cardinality() const = 0;

            /**
             * Returns the number of bits set to true in the specified range.
             */
            virtual size_t cardinality(size_t startIndex, size_t endIndex) const = 0;

            /**
             * Sets all the bits to false.
             */
            virtual void clear() = 0;

            /**
             * Sets all the bits in the specified range to false.
             */
            virtual void clear(size_t startIndex, size_t endIndex) = 0;

            /**
             * Sets all the bits to true.
             */
            virtual void enable() = 0;

            /**
             * Sets all the bits in the specified range to true.
             */
            virtual void enable(size_t startIndex, size_t endIndex) = 0;

            /**
             * Performs a logical AND.
             */
            virtual void andOperator(const IBit32Array& other) = 0;

            /**
             * Performs a logical OR.
             */
            virtual void orOperator(const IBit32Array& other) = 0;

            /**
             * Performs a logical XOR.
             */
            virtual void xorOperator(const IBit32Array& other) = 0;

            /**
             * Performs a logical NOT.
             */
            virtual void notOperator() = 0;

            /**
             * Performs a logical bit operator.
             */
            virtual void operate(const base::IBinaryBitOperator& bitOperator, const IBit32Array& other) = 0;

            /**
             * Performs a logical bit operator.
             */
            virtual void operate(const base::IUnaryBitOperator& bitOperator) = 0;

            /**
             * Performs a logical AND on the specified index.
             */
            virtual void andOperator(size_t index, unsigned int value) = 0;

            /**
             * Performs a logical OR on the specified index.
             */
            virtual void orOperator(size_t index, unsigned int value) = 0;

            /**
             * Performs a logical XOR on the specified index.
             */
            virtual void xorOperator(size_t index, unsigned int value) = 0;

            /**
             * Performs a logical NOT on the specified index.
             */
            virtual void notOperator(size_t index) = 0;

            /**
             * Performs a logical bit operator on the specified index.
             */
            virtual void operate(const base::IBinaryBitOperator& bitOperator, size_t index, unsigned int value) = 0;

            /**
             * Performs a logical bit operator on the specified index.
             */
            virtual void operate(const base::IUnaryBitOperator& bitOperator, size_t index) = 0;

            /**
             * Converts the bits to an integer.
             */
            virtual unsigned int toInteger() const = 0;
        };

        using IBit32ArrayPtr = std::shared_ptr<IBit32Array>;

        /**
         * Defines the equivalent operator.
         */
        inline bool operator<(const IBit32Array& left, const IBit32Array& right)
        {
            return true;
        }
    }
}

#endif // I_BIT32_ARRAY_LIST_H_0bb46183_5976_41c2_9d11_489a817c2391
