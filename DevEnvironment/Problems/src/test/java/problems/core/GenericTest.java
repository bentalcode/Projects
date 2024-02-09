package problems.core;

import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

public final class GenericTest {
    /**
     * The GenericTest constructor.
     */
    public GenericTest() {
    }

    /**
     * Tests the even distribution logic.
     */
    @Test
    public void test() {
        int x = -123;
        int result = new Solution().reverse(x);
    }

    class Solution {
        public int reverse(int x) {
            if (x == 0) {
                return 0;
            }

            int signX = sign(x);
            long absX = Math.abs((long)x);

            List<Integer> digits = parseDigits(absX);

            long result = 0;

            long maxPositive = Integer.MAX_VALUE;
            long maxNegative = Math.abs((long)Integer.MIN_VALUE);

            for (int digit : digits) {
                result *= 10;
                result += digit;

                if (signX == 1 && result > maxPositive) {
                    return Integer.MAX_VALUE;
                }


                if (signX == 0 && result > maxNegative) {
                    return Integer.MIN_VALUE;
                }
            }

            if (signX == 0) {
                result *= -1;
            }

            return (int)result;
        }

        private List<Integer> parseDigits(long value) {
            List<Integer> digits = new ArrayList<>();

            long currValue = value;

            while (currValue != 0) {
                int digit = (int)(currValue % 10);
                digits.add(digit);

                currValue /= 10;
            }

            return digits;
        }

        private int sign(int value) {
            int mask = 1 << 31;
            return (value & mask) == 0 ? 1 : 0;
        }
    }
}
