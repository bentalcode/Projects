package base.core;

import base.interfaces.IRandomGenerator;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import org.junit.Test;

/**
 * The RandomGeneratorTest class implements tests for a random generator.
 */
public final class RandomGeneratorTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The SortingTest constructor.
     */
    public RandomGeneratorTest() {
    }

    /**
     * Tests the logic of generating random integers.
     */
    @Test
    public void randomIntegersTest() {
        testRandomInteger(0, Integer.MAX_VALUE);
        testRandomInteger(1, Integer.MAX_VALUE);
        testRandomInteger(Integer.MAX_VALUE, Integer.MAX_VALUE);
    }

    /**
     * Tests the sorting strings.
     */
    private void testRandomInteger(int from, int to) {
        IRandomGenerator randomGenerator = new RandomGenerator();
        int result = randomGenerator.nextInteger(from, to);

        this.assertion.assertTrue(
            result >= from && result <= to,
            "Invalid logic for generating a random integer.");
    }
}
