#ifndef I_BIT_ARRAY_H_039397dc_65db_4f96_ac8e_c71ba80a99b0
#define I_BIT_ARRAY_H_039397dc_65db_4f96_ac8e_c71ba80a99b0

#include "IBit32Array.h"
#include "BaseLogic.h"
#include <vector>

namespace base {
    class IUnaryBitOperator;
    class IBinaryBitOperator;
};

namespace datastructures {
    namespace bitarray {

        /**
         * The IBitArray interface defines a bit array, which manages a compact array Of bits.
         */
        class IBitArray :
            public base::ISizableCollection<bool>,
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
             * The Copy/move constructors.
             */
            IBitArray(const IBitArray&) = delete;
            IBitArray(IBitArray&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            IBitArray& operator=(const IBitArray&) = delete;
            IBitArray& operator=(IBitArray&&) = delete;

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
            virtual size_t Get(size_t index) const = 0;

            /**
             * Sets the bits to the complement Of its current value.
             */
            virtual void Flip() = 0;

            /**
             * Sets the bit at the specified index to the complement Of its current value.
             */
            virtual void Flip(size_t index) = 0;

            /**
             * Returns the number Of bits Set to true.
             */
            virtual size_t Cardinality() const = 0;

            /**
             * Sets all the bits to false.
             */
            virtual void Clear() = 0;

            /**
             * Sets all the bits at the specified range to false.
             */
            virtual void Clear(size_t startIndex, size_t endIndex) = 0;

            /**
             * Sets all the bits to true.
             */
            virtual void Enable() = 0;

            /**
             * Sets all the bits at the specified range to true.
             */
            virtual void Enable(size_t startIndex, size_t endIndex) = 0;

            /**
             * Performs a logical AND on this bit array with the other bit array.
             */
            virtual void AndOperator(const IBitArray& other) = 0;

            /**
             * Performs a logical OR on this bit array with the other bit array.
             */
            virtual void OrOperator(const IBitArray& other) = 0;

            /**
             * Performs a logical XOR on this bit array with the other bit array.
             */
            virtual void XorOperator(const IBitArray& other) = 0;

            /**
             * Performs a logical NOT on this bit array.
             */
            virtual void NotOperator() = 0;

            /**
             * Performs a logical bit operator on this bit array with the other bit array.
             */
            virtual void Operate(const base::IBinaryBitOperator& bitOperator, const IBitArray& other) = 0;

            /**
             * Performs a logical bit operator on this bit array.
             */
            virtual void Operate(const base::IUnaryBitOperator& bitOperator) = 0;

            /**
             * Converts the bits to a native array.
             */
            virtual std::vector<unsigned int> ToArray() const = 0;

            /**
             * Converts the bits to a bit 32 array.
             */
            virtual const std::vector<IBit32ArraySharedPtr>& ToBit32Array() const = 0;
        };

        /**
         * Defines the SharedPtr Of Bit Array.
         */
        using IBitArraySharedPtr = std::shared_ptr<IBitArray>;

        /**
         * Defines the equivalent operator.
         */
        inline bool operator<(const IBitArray& left, const IBitArray& right)
        {
            const std::vector<IBit32ArraySharedPtr>& leftArray = left.ToBit32Array();
            const std::vector<IBit32ArraySharedPtr>& rightArray = right.ToBit32Array();

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
