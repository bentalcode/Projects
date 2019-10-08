package datastructures.bitarray.interfaces;

/**
 * The BinaryBitOperator defines the supported unary bit operators.
 */
public enum UnaryBitOperator {
    Not {

        /**
         * Performs a logical bit operator on the specified value.
         */
        @Override
        public int evaluate(int value) {
            return ~value;
        }

        /**
         * Performs a logical bit operator on the specified bit.
         */
        @Override
        public int evaluateBit(int bitValue) {
            return (bitValue == 0) ? 1 : 0;
        }
    };

    /**
     * Performs a logical bit operator on the specified value.
     */
    public abstract int evaluate(int value);

    /**
     * Performs a logical bit operator on the specified bit.
     */
    public abstract int evaluateBit(int bitValue);
}
