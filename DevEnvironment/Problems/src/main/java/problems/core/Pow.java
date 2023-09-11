package problems.core;

import problems.interfaces.IPow;

/**
 * The Pow class implements a pow function.
 */
public final class Pow implements IPow {
    /**
     * The Pow constructor.
     */
    public Pow() {
    }

    /**
     * Comutes the pow of a number.
     */
    public double pow(double value, int pow) {
        if (pow == 0) {
            return 1.0;
        }

        if (value == 0.0 || value == 1.0 || pow == 1) {
            return value;
        }

        int signValue = sign(value);
        double absValue = Math.abs(value);

        int signPow = sign(pow);
        long absPow = Math.abs((long)pow);

        int signResult = (signValue == 1 || absPow % 2 == 0) ? 1 : 0;

        double result = effectivePow(absValue, absPow);

        if (signPow == 0) {
            result = 1 / result;
        }

        if (signResult == 0) {
            result *= -1;
        }

        return result;
    }

    private static double effectivePow(double value, long pow) {
        assert(value >= 0);
        assert(pow >= 0);

        if (pow == 0) {
            return 1.0;
        }

        if (value == 0.0 || value == 1.0 || pow == 1) {
            return value;
        }

        double result = 1;

        long currPow = pow;
        double currValue = value;

        while (currPow > 0) {
            if (currPow % 2 == 1) {
                result *= currValue;
            }

            currValue *= currValue;
            currPow >>= 1;
        }

        return result;
    }

    private static int sign(int value) {
        int mask = 1 << 31;
        return (value & mask) == 0 ? 1 : 0;
    }

    private static int sign(double value) {
        return value >= 0 ? 1: 0;
    }
}
