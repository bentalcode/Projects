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
             * The BitArray constructor.
             */
            explicit BitArray(size_t numberOfBits);

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
            virtual int get(size_t index) const override;

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
            virtual void notOperator(const IBitArray& other) override;

            /**
             * Performs a logical bit operator on this bit array with the other bit array.
             */
            virtual void operate(const BinaryBitOperator& bitOperator, const IBitArray& other) override;

            /**
             * Performs a logical bit operator on this bit array.
             */
            virtual void operate(const UnaryBitOperator& bitOperator) override;

            /**
             * Converts the bits to a native array.
             */
            virtual std::vector<unsigned int> toArray() const override;

            /**
             * Converts the bits to a 32 bit array.
             */
            virtual const std::vector<IBit32ArrayPtr>& toBit32Array() const override;

        private:
            std::vector<IBit32ArrayPtr> m_data;
            size_t m_size;
        };

        using IBitArrayPtr = std::shared_ptr<IBitArray>;
    }
}

#endif // BIT_ARRAY_H_40ad4559_dd0b_48e7_b23d_70a23d39a47b
