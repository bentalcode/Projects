package base.interfaces;

/**
 * The IPrimitiveSize interface defines a primitive size.
 */
public interface IPrimitiveSize {
    /**
     * The number of bits in byte.
     */
    int NumberOfBitsInByte = 8;

    interface InBytes {
        /**
         * The size of a byte in bytes.
         */
        int ByteSize = 1;

        /**
         * The size of a short in bytes.
         */
        int ShortSize = 2;

        /**
         * The size of an integer in bytes.
         */
        int IntegerSize = 4;

        /**
         * The size of a long in bytes.
         */
        int LongSize = 8;

        /**
         * The size of a float in bytes.
         */
        int FloatSize = 4;

        /**
         * The size of a double in bytes.
         */
        int DoubleSize = 8;

        /**
         * The size of a char in bytes.
         */
        int CharacterSize = 2;

        /**
         * The size of a reference in bytes.
         * Assuming 64-bit architecture.
         */
        int ReferenceSize = 8;
    }

    interface InBits {
        /**
         * The size of a byte in bytes.
         */
        int ByteSize = InBytes.ByteSize * NumberOfBitsInByte;

        /**
         * The size of a short in bytes.
         */
        int ShortSize = InBytes.ShortSize * NumberOfBitsInByte;

        /**
         * The size of an integer in bytes.
         */
        int IntegerSize = InBytes.IntegerSize * NumberOfBitsInByte;

        /**
         * The size of a long in bytes.
         */
        int LongSize = InBytes.LongSize * NumberOfBitsInByte;

        /**
         * The size of a float in bytes.
         */
        int FloatSize = InBytes.FloatSize * NumberOfBitsInByte;

        /**
         * The size of a double in bytes.
         */
        int DoubleSize = InBytes.DoubleSize * NumberOfBitsInByte;

        /**
         * The size of a char in bytes.
         */
        int CharacterSize = InBytes.CharacterSize * NumberOfBitsInByte;

        /**
         * The size of a reference in bytes.
         * Assuming 64-bit architecture.
         */
        int ReferenceSize = InBytes.ReferenceSize * NumberOfBitsInByte;
    }
}
