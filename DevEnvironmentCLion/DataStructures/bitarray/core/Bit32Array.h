#ifndef BIT32_ARRAY_H_f283c94a_21ae_46de_96dc_98d49a6fa875
#define BIT32_ARRAY_H_f283c94a_21ae_46de_96dc_98d49a6fa875

#include "IBit32Array.h"

namespace datastructures {
    namespace bitarray {

        /**
         * The Bit32Array class implements a bit array of size 32.
         */
        class Bit32Array final : public IBit32Array
        {
        public:
            /**
             * Creates a bit 32 array.
             */
            static IBit32ArrayPtr make(unsigned int bits = 0);

            /**
             * The Bit32Array constructor from an integer.
             */
            explicit Bit32Array(unsigned int bits = 0);

            /**
             * The Bit32Array destructor.
             */
            virtual ~Bit32Array();

            /**
             * The copy/move constructors.
             */
            Bit32Array(const Bit32Array&) = default;
            Bit32Array(Bit32Array&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            Bit32Array& operator=(const Bit32Array&) = default;
            Bit32Array& operator=(Bit32Array&&) = delete;

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
            virtual unsigned int get(size_t index) const override;

            /**
             * Sets the bit at the specified index to the complement of its current value.
             */
            virtual void flip(size_t index) override;

            /**
             * Returns the number of bits set to true.
             */
            virtual size_t cardinality() const override;

            /**
             * Returns the number of bits set to true in the specified range.
             */
            virtual size_t cardinality(size_t startIndex, size_t endIndex) const override;

            /**
             * Sets all the bits to false.
             */
            virtual void clear() override;

            /**
             * Sets all the bits in the specified range to false.
             */
            virtual void clear(size_t startIndex, size_t endIndex) override;

            /**
             * Sets all the bits to true.
             */
            virtual void enable() override;

            /**
             * Sets all the bits in the specified range to true.
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
             * Performs a logical AND.
             */
            virtual void andOperator(const IBit32Array& other) override;

            /**
             * Performs a logical OR.
             */
            virtual void orOperator(const IBit32Array& other) override;

            /**
             * Performs a logical XOR.
             */
            virtual void xorOperator(const IBit32Array& other) override;

            /**
             * Performs a logical NOT.
             */
            virtual void notOperator() override;

            /**
             * Performs a logical bit operator.
             */
            virtual void operate(const base::IBinaryBitOperator& bitOperator, const IBit32Array& other) override;

            /**
             * Performs a logical bit operator.
             */
            virtual void operate(const base::IUnaryBitOperator& bitOperator) override;

            /**
             * Performs a logical AND on the specified index.
             */
            virtual void andOperator(size_t index, unsigned int value) override;

            /**
             * Performs a logical OR on the specified index.
             */
            virtual void orOperator(size_t index, unsigned int value) override;

            /**
             * Performs a logical XOR on the specified index.
             */
            virtual void xorOperator(size_t index, unsigned int value) override;

            /**
             * Performs a logical NOT on the specified index.
             */
            virtual void notOperator(size_t index) override;

            /**
             * Performs a logical bit operator on the specified index.
             */
            virtual void operate(const base::IBinaryBitOperator& bitOperator, size_t index, unsigned int value) override;

            /**
             * Performs a logical bit operator on the specified index.
             */
            virtual void operate(const base::IUnaryBitOperator& bitOperator, size_t index) override;

            /**
             * Converts the bits to an integer.
             */
            virtual unsigned int toInteger() const override;

            /**
             * Gets the iterator.
             */
            virtual base::IIteratorPtr<bool> getIterator() const override;

            /**
             * Gets the reverse iterator.
             */
            virtual base::IReverseIteratorPtr<bool> getReverseIterator() const override;

        private:
            static const unsigned int allBitsMask = 0xFFFFFFFF;

            /**
             * Validates an index.
             */
            void validateIndex(size_t index) const;

            unsigned int m_bits;
        };

        using IBit32ArrayPtr = std::shared_ptr<IBit32Array>;

    }
}

#endif // BIT32_ARRAY_H_f283c94a_21ae_46de_96dc_98d49a6fa875
