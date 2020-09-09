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
            static IBitArrayPtr make(size_t numberOfBits);

            /**
             * Copies a bit array.
             */
            static IBitArrayPtr copy(const IBitArray& bitArray);

            /**
             * The BitArray constructor.
             */
            explicit BitArray(size_t numberOfBits);

            /**
             * The BitArray copy constructor.
             */
            BitArray(const IBitArray& bitArray);

            /**
             * The BitArray destructor.
             */
            virtual ~BitArray();

            /**
             * The copy/move constructors.
             */
            BitArray(const BitArray&) = delete;
            BitArray(BitArray&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            BitArray& operator=(const BitArray&) = delete;
            BitArray& operator=(BitArray&&) = delete;

            /**
             * Turns on a bit at the specified index.
             */
            virtual void turnOn(size_t index) override;

            /**
             * Turns off a bit at the specified index.
             */
            virtual void turnOff(size_t index) override;

            /**
             * Checks whether a bit at the specified index is on.
             */
            virtual bool isOn(size_t index) const override;

            /**
             * Checks whether a bit at the specified index is off.
             */
            virtual bool isOff(size_t index) const override;

            /**
             * Sets a value of a bit at the specified index.
             */
            virtual void set(size_t index, unsigned int value) override;

            /**
             * Gets a value of a bit at the specified index.
             */
            virtual size_t get(size_t index) const override;

            /**
             * Sets the bits to the complement of its current value.
             */
            virtual void flip() override;

            /**
             * Sets the bit at the specified index to the complement of its current value.
             */
            virtual void flip(size_t index) override;

            /**
             * Returns the number of bits set to true.
             */
            virtual size_t cardinality() const override;

            /**
             * Sets all the bits to false.
             */
            virtual void clear() override;

            /**
             * Sets all the bits at the specified range to false.
             */
            virtual void clear(size_t startIndex, size_t endIndex) override;

            /**
             * Sets all the bits to true.
             */
            virtual void enable() override;

            /**
             * Sets all the bits at the specified range to true.
             */
            virtual void enable(size_t startIndex, size_t endIndex) override;

            /**
             * Gets the size of the collection.
             */
            virtual size_t size() const override;

            /**
             * Checks whether the collection is empty.
             */
            virtual bool empty() const override;

            /**
             * Performs a logical AND on this bit array with the other bit array.
             */
            virtual void andOperator(const IBitArray& other) override;

            /**
             * Performs a logical OR on this bit array with the other bit array.
             */
            virtual void orOperator(const IBitArray& other) override;

            /**
             * Performs a logical XOR on this bit array with the other bit array.
             */
            virtual void xorOperator(const IBitArray& other) override;

            /**
             * Performs a logical NOT on this bit array.
             */
            virtual void notOperator() override;

            /**
             * Performs a logical bit operator on this bit array with the other bit array.
             */
            virtual void operate(const base::IBinaryBitOperator& bitOperator, const IBitArray& other) override;

            /**
             * Performs a logical bit operator on this bit array.
             */
            virtual void operate(const base:: IUnaryBitOperator& bitOperator) override;

            /**
             * Converts the bits to a native array.
             */
            virtual std::vector<unsigned int> toArray() const override;

            /**
             * Converts the bits to a bit 32 array.
             */
            virtual const std::vector<IBit32ArrayPtr>& toBit32Array() const override;

            /**
             * Gets the iterator.
             */
            virtual base::IIteratorPtr<bool> getIterator() const override;

            /**
             * Gets the reverse iterator.
             */
            virtual base::IReverseIteratorPtr<bool> getReverseIterator() const override;

        private:
            static const size_t unitSizeInBits = IBit32Array::sizeInBits;

            /**
             * Creates a bit array.
             */
            std::vector<IBit32ArrayPtr> createBitArray(size_t numberOfBits) const;

            /**
             * Gets the number of units.
             */
            size_t getNumberOfUnits() const;

            /**
             * Calculates the number of units.
             */
            size_t getNumberOfUnits(size_t numberOfBits) const;

            /**
             * Calculates the index of a unit.
             */
            size_t unitIndexOf(size_t index) const;

            /**
             * Calculates the index of a bit in a unit.
             */
            size_t bitIndexOf(size_t index) const;

            /**
             * Validates an index.
             */
            void validateIndex(size_t index) const;

            std::vector<IBit32ArrayPtr> m_data;
            size_t m_size;
        };

        using IBitArrayPtr = std::shared_ptr<IBitArray>;
    }
}

#endif // BIT_ARRAY_H_40ad4559_dd0b_48e7_b23d_70a23d39a47b
