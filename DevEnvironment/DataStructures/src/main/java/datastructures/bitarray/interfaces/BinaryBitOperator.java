package datastructures.bitarray.interfaces;

/**
 * The BinaryBitOperator defines the supported binary bit operators.
 */
public enum BinaryBitOperator {
    And {

        /**
         * Performs a logical bit operator on the specified values.
         */
        @Override
        public int evaluate(int lhs, int rhs) {
            return lhs & rhs;
        }
    },

    Or {

        /**
         * Performs a logical bit operator on the specified values.
         */
        @Override
        public int evaluate(int lhs, int rhs) {
            return lhs | rhs;
        }
    },

    Xor {

        /**
         * Performs a logical bit operator on the specified values.
         */
        @Override
        public int evaluate(int lhs, int rhs) {
            return lhs ^ rhs;
        }
    };

    /**
     * Performs a logical bit operator on the specified values.
     */
    public abstract int evaluate(int lhs, int rhs);
}
