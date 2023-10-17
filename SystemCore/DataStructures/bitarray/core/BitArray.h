#ifndef BIT_ARRAY_H_40ad4559_dd0b_48e7_b23d_70a23d39a47b
#define BIT_ARRAY_H_40ad4559_dd0b_48e7_b23d_70a23d39a47b

#include "IBitArray.h"

namespace datastructures {
    namespace bitarray {

        /**
         * The BitArray class implements a bit array.
         */
        class BitArray final : public IBitArray
        {
        public:
            /**
             * Creates a bit array.
             */
            static IBitArraySharedPtr make(size_t numberOfBits);

            /**
             * Copies a bit array.
             */
            static IBitArraySharedPtr Copy(const IBitArray& bitArray);

            /**
             * The BitArray constructor.
             */
            explicit BitArray(size_t numberOfBits);

            /**
             * The BitArray Copy constructor.
             */
            BitArray(const IBitArray& bitArray);

            /**
             * The BitArray destructor.
             */
            virtual ~BitArray();

            /**
             * The Copy/move constructors.
             */
            BitArray(const BitArray&) = delete;
            BitArray(BitArray&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            BitArray& operator=(const BitArray&) = delete;
            BitArray& operator=(BitArray&&) = delete;

            /**
             * Turns on a bit at the specified index.
             */
            virtual void TurnOn(size_t index) override;

            /**
             * Turns off a bit at the specified index.
             */
            virtual void TurnOff(size_t index) override;

            /**
             * Checks whether a bit at the specified index is on.
             */
            virtual bool IsOn(size_t index) const override;

            /**
             * Checks whether a bit at the specified index is off.
             */
            virtual bool IsOff(size_t index) const override;

            /**
             * Sets a value of a bit at the specified index.
             */
            virtual void Set(size_t index, unsigned int value) override;

            /**
             * Gets a value of a bit at the specified index.
             */
            virtual size_t Get(size_t index) const override;

            /**
             * Sets the bits to the complement Of its current value.
             */
            virtual void Flip() override;

            /**
             * Sets the bit at the specified index to the complement Of its current value.
             */
            virtual void Flip(size_t index) override;

            /**
             * Returns the number Of bits Set to true.
             */
            virtual size_t Cardinality() const override;

            /**
             * Sets all the bits to false.
             */
            virtual void Clear() override;

            /**
             * Sets all the bits at the specified range to false.
             */
            virtual void Clear(size_t startIndex, size_t endIndex) override;

            /**
             * Sets all the bits to true.
             */
            virtual void Enable() override;

            /**
             * Sets all the bits at the specified range to true.
             */
            virtual void Enable(size_t startIndex, size_t endIndex) override;

            /**
             * Gets the Size of the collection.
             */
            virtual size_t Size() const override;

            /**
             * Checks whether the collection is Empty.
             */
            virtual bool Empty() const override;

            /**
             * Performs a logical AND on this bit array with the other bit array.
             */
            virtual void AndOperator(const IBitArray& other) override;

            /**
             * Performs a logical OR on this bit array with the other bit array.
             */
            virtual void OrOperator(const IBitArray& other) override;

            /**
             * Performs a logical XOR on this bit array with the other bit array.
             */
            virtual void XorOperator(const IBitArray& other) override;

            /**
             * Performs a logical NOT on this bit array.
             */
            virtual void NotOperator() override;

            /**
             * Performs a logical bit operator on this bit array with the other bit array.
             */
            virtual void Operate(const base::IBinaryBitOperator& bitOperator, const IBitArray& other) override;

            /**
             * Performs a logical bit operator on this bit array.
             */
            virtual void Operate(const base:: IUnaryBitOperator& bitOperator) override;

            /**
             * Converts the bits to a native array.
             */
            virtual std::vector<unsigned int> ToArray() const override;

            /**
             * Converts the bits to a bit 32 array.
             */
            virtual const std::vector<IBit32ArraySharedPtr>& ToBit32Array() const override;

            /**
             * Gets the iterator.
             */
            virtual base::IIteratorSharedPtr<bool> GetIterator() const override;

            /**
             * Gets the reverse iterator.
             */
            virtual base::IReverseIteratorSharedPtr<bool> GetReverseIterator() const override;

        private:
            static const size_t unitSizeInBits = IBit32Array::SIZE_IN_BITS;

            /**
             * Creates a bit array.
             */
            std::vector<IBit32ArraySharedPtr> CreateBitArray(size_t numberOfBits) const;

            /**
             * Gets the number Of units.
             */
            size_t GetNumberOfUnits() const;

            /**
             * Calculates the number Of units.
             */
            size_t GetNumberOfUnits(size_t numberOfBits) const;

            /**
             * Calculates the index of a unit.
             */
            size_t UnitIndexOf(size_t index) const;

            /**
             * Calculates the index of a bit in a unit.
             */
            size_t BitIndexOf(size_t index) const;

            /**
             * Validates an index.
             */
            void ValidateIndex(size_t index) const;

            std::vector<IBit32ArraySharedPtr> m_data;
            size_t m_size;
        };

        using IBitArraySharedPtr = std::shared_ptr<IBitArray>;
    }
}

#endif // BIT_ARRAY_H_40ad4559_dd0b_48e7_b23d_70a23d39a47b
