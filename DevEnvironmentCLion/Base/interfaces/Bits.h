#ifndef BITS_H_9ad04492_f4d8_461e_bea3_76147b3f84c0
#define BITS_H_9ad04492_f4d8_461e_bea3_76147b3f84c0

namespace base
{
    /**
     * The Bits class implements complementary APIs for bits.
     */
    class Bits final
    {
    public:
        /**
         * Converts an integer to a bit value: one or zero.
         */
        static unsigned int bitValue(unsigned int bitValue);

        /**
         * Checks whether the bit is on.
         */
        static bool isOn(unsigned int bitValue);

        /**
         * Checks whether the bit is off.
         */
        static bool isOff(unsigned int bitValue);

        /**
         * Verifies that value of a bit is valid: one or zero.
         */
        static bool isBitValue(unsigned int bitValue);

        /**
         * Turns on a bit at the specified index.
         */
        static unsigned int turnOn(unsigned int value, size_t index);

        /**
         * Turns off a bit at the specified index.
         */
        static unsigned int turnOff(unsigned int value, size_t index);

        /**
         * Checks whether a bit at the specified index is on.
         */
        static bool isOn(unsigned int value, size_t index);

        /**
         * Checks whether a bit at the specified index is off.
         */
        static bool isOff(unsigned int value, size_t index);

        /**
         * Sets a value of a bit at the specified index.
         */
        static unsigned int set(unsigned int value, size_t index, unsigned int bitValue);

        /**
         * Gets a value of a bit at the specified index.
         */
        static unsigned int get(unsigned int value, size_t index);

        /**
         * Flips the value of a bit.
         */
        static unsigned int flip(unsigned int bit);

        /**
         * Sets the bit at the specified index to the complement of its current value.
         */
        static unsigned int flip(unsigned int value, size_t index);

    private:
        /**
         * Validates the index.
         */
        static void validateIndex(size_t index);

        /**
         * This is a static class - Disables the default constructor and destructor.
         */
        Bits() = delete;
        ~Bits() = delete;
    };
}

#endif // INDEXES_H_62e92087_fd0f_4d6a_8bc1_ea6b1bc449ed
