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
         * The IBit32Array interface defines a bit array Of Size 32.
         */
        class IBit32Array :
            public base::ISizableCollection<bool>,
            public base::IReverseIterable<bool>
        {
        public:
            static const size_t SIZE_IN_BITS = 32;

            /**
             * The IBit32Array constructor.
             */
            IBit32Array() = default;

            /**
             * The IBit32Array destructor.
             */
            virtual ~IBit32Array() = default;

            /**
             * The Copy/move constructors.
             */
            IBit32Array(const IBit32Array&) = delete;
            IBit32Array(IBit32Array&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            IBit32Array& operator=(const IBit32Array&) = delete;
            IBit32Array& operator=(IBit32Array&&) = delete;

            /**
             * Turns on a bit at the specified index.
             */
            virtual void TurnOn(size_t index) = 0;

            /**
             * Turns off a bit at the specified index.
             */
            virtual void TurnOff(size_t index) = 0;

            /**
             * Checks whether a bit at the specified index is on.
             */
            virtual bool IsOn(size_t index) const = 0;

            /**
             * Checks whether a bit at the specified index is off.
             */
            virtual bool IsOff(size_t index) const = 0;

            /**
             * Sets a value of a bit at the specified index.
             */
            virtual void Set(size_t index, unsigned int value) = 0;

            /**
             * Gets a value of a bit at the specified index.
             */
            virtual unsigned int Get(size_t index) const = 0;

            /**
             * Sets the bit at the specified index to the complement Of its current value.
             */
            virtual void Flip(size_t index) = 0;

            /**
             * Returns the number Of bits Set to true.
             */
            virtual size_t Cardinality() const = 0;

            /**
             * Returns the number Of bits Set to true in the specified range.
             */
            virtual size_t Cardinality(size_t startIndex, size_t endIndex) const = 0;

            /**
             * Sets all the bits to false.
             */
            virtual void Clear() = 0;

            /**
             * Sets all the bits in the specified range to false.
             */
            virtual void Clear(size_t startIndex, size_t endIndex) = 0;

            /**
             * Sets all the bits to true.
             */
            virtual void Enable() = 0;

            /**
             * Sets all the bits in the specified range to true.
             */
            virtual void Enable(size_t startIndex, size_t endIndex) = 0;

            /**
             * Performs a logical AND.
             */
            virtual void AndOperator(const IBit32Array& other) = 0;

            /**
             * Performs a logical OR.
             */
            virtual void OrOperator(const IBit32Array& other) = 0;

            /**
             * Performs a logical XOR.
             */
            virtual void XorOperator(const IBit32Array& other) = 0;

            /**
             * Performs a logical NOT.
             */
            virtual void NotOperator() = 0;

            /**
             * Performs a logical bit operator.
             */
            virtual void Operate(const base::IBinaryBitOperator& bitOperator, const IBit32Array& other) = 0;

            /**
             * Performs a logical bit operator.
             */
            virtual void Operate(const base::IUnaryBitOperator& bitOperator) = 0;

            /**
             * Performs a logical AND on the specified index.
             */
            virtual void AndOperator(size_t index, unsigned int value) = 0;

            /**
             * Performs a logical OR on the specified index.
             */
            virtual void OrOperator(size_t index, unsigned int value) = 0;

            /**
             * Performs a logical XOR on the specified index.
             */
            virtual void XorOperator(size_t index, unsigned int value) = 0;

            /**
             * Performs a logical NOT on the specified index.
             */
            virtual void NotOperator(size_t index) = 0;

            /**
             * Performs a logical bit operator on the specified index.
             */
            virtual void Operate(const base::IBinaryBitOperator& bitOperator, size_t index, unsigned int value) = 0;

            /**
             * Performs a logical bit operator on the specified index.
             */
            virtual void Operate(const base::IUnaryBitOperator& bitOperator, size_t index) = 0;

            /**
             * Converts the bits to an integer.
             */
            virtual unsigned int ToInteger() const = 0;
        };

        /**
         * Defines the SharedPtr Of Bit 32 Array.
         */
        using IBit32ArraySharedPtr = std::shared_ptr<IBit32Array>;

        /**
         * Defines the equivalent operator.
         */
        inline bool operator<(const IBit32Array& left, const IBit32Array& right)
        {
            return left.ToInteger() < right.ToInteger();
        }
    }
}

#endif // I_BIT32_ARRAY_LIST_H_0bb46183_5976_41c2_9d11_489a817c2391
