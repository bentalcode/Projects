package base.core;

/**
 * The ArithmeticOperators class implements complementary APIs for arithmetic operators.
 */
public final class ArithmeticOperators {
    /**
     * Adds two number safely.
     */
    public static int safeAdd(int lhs, int rhs) {;
        int result = lhs + rhs;

        if (ArithmeticOperators.additionOverflow(lhs, rhs, result)) {
            String errorMessage = "ArithmeticOperators detected an overflow while adding two numbers.";
            throw new BaseException(errorMessage);
        }

        return result;
    }

    /**
     * Detects whether an addition arithmetic operator ended with an overflow.
     */
    private static boolean additionOverflow(int lhs, int rhs, int result) {
        return (lhs < 0 && rhs < 0 && result > 0) || (lhs > 0 && rhs > 0 && result < 0);
    }

    /**
     * The ArithmeticOperators - Disables the default constructor.
     */
    private ArithmeticOperators() {
    }
}
