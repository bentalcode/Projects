#ifndef BIT32_ARRAY_H_f283c94a_21ae_46de_96dc_98d49a6fa875
#define BIT32_ARRAY_H_f283c94a_21ae_46de_96dc_98d49a6fa875

#include "IBit32Array.h"

namespace datastructures {
    namespace bitarray {

        /**
         * The Bit32Array class implements a bit array ofSize 32.
         */
        class Bit32Array final : public IBit32Array
        {
        public:
            /**
             * Creates a bit 32 array.
             */
            static IBit32ArraySharedPtr Make(unsigned int bits = 0);

            /**
             * The Bit32Array constructor from an integer.
             */
            explicit Bit32Array(unsigned int bits = 0);

            /**
             * The Bit32Array destructor.
             */
            virtual ~Bit32Array();

            /**
             * The Copy/move constructors.
             */
            Bit32Array(const Bit32Array&) = default;
            Bit32Array(Bit32Array&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            Bit32Array& operator=(const Bit32Array&) = default;
            Bit32Array& operator=(Bit32Array&&) = delete;

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
            virtual unsigned int Get(size_t index) const override;

            /**
             * Sets the bit at the specified index to the complement ofits current value.
             */
            virtual void Flip(size_t index) override;

            /**
             * Returns the number ofbits Set to true.
             */
            virtual size_t Cardinality() const override;

            /**
             * Returns the number ofbits Set to true in the specified range.
             */
            virtual size_t Cardinality(size_t startIndex, size_t endIndex) const override;

            /**
             * Sets all the bits to false.
             */
            virtual void Clear() override;

            /**
             * Sets all the bits in the specified range to false.
             */
            virtual void Clear(size_t startIndex, size_t endIndex) override;

            /**
             * Sets all the bits to true.
             */
            virtual void Enable() override;

            /**
             * Sets all the bits in the specified range to true.
             */
            virtual void Enable(size_t startIndex, size_t endIndex) override;

            /**
             * Gets the size of the collection.
             */
            virtual size_t Size() const override;

            /**
             * Checks whether the collection is Empty.
             */
            virtual bool Empty() const override;

            /**
             * Performs a logical AND.
             */
            virtual void AndOperator(const IBit32Array& other) override;

            /**
             * Performs a logical OR.
             */
            virtual void OrOperator(const IBit32Array& other) override;

            /**
             * Performs a logical XOR.
             */
            virtual void XorOperator(const IBit32Array& other) override;

            /**
             * Performs a logical NOT.
             */
            virtual void NotOperator() override;

            /**
             * Performs a logical bit operator.
             */
            virtual void Operate(const base::IBinaryBitOperator& bitOperator, const IBit32Array& other) override;

            /**
             * Performs a logical bit operator.
             */
            virtual void Operate(const base::IUnaryBitOperator& bitOperator) override;

            /**
             * Performs a logical AND on the specified index.
             */
            virtual void AndOperator(size_t index, unsigned int value) override;

            /**
             * Performs a logical OR on the specified index.
             */
            virtual void OrOperator(size_t index, unsigned int value) override;

            /**
             * Performs a logical XOR on the specified index.
             */
            virtual void XorOperator(size_t index, unsigned int value) override;

            /**
             * Performs a logical NOT on the specified index.
             */
            virtual void NotOperator(size_t index) override;

            /**
             * Performs a logical bit operator on the specified index.
             */
            virtual void Operate(const base::IBinaryBitOperator& bitOperator, size_t index, unsigned int value) override;

            /**
             * Performs a logical bit operator on the specified index.
             */
            virtual void Operate(const base::IUnaryBitOperator& bitOperator, size_t index) override;

            /**
             * Converts the bits to an integer.
             */
            virtual unsigned int ToInteger() const override;

            /**
             * Gets the iterator.
             */
            virtual base::IIteratorSharedPtr<bool> GetIterator() const override;

            /**
             * Gets the reverse iterator.
             */
            virtual base::IReverseIteratorSharedPtr<bool> GetReverseIterator() const override;

        private:
            static const unsigned int allBitsMask = 0xFFFFFFFF;

            /**
             * Validates an index.
             */
            void ValidateIndex(size_t index) const;

            unsigned int m_bits;
        };

        using IBit32ArraySharedPtr = std::shared_ptr<IBit32Array>;

    }
}

#endif // BIT32_ARRAY_H_f283c94a_21ae_46de_96dc_98d49a6fa875
