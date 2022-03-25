package base.core;

import base.interfaces.IAlmostComparatorFactory;
import base.interfaces.IBinaryComparator;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

/**
 * The AlmostComparatorTest class implements tests for almost comparator.
 */
public final class AlmostComparatorTest {
    private final IAlmostComparatorFactory almostComparatorFactory = new AlmostComparatorFactory();
    private final IAssertion assertion = new Assertion();

    /**
     * The AlmostComparatorTest constructor.
     */
    public AlmostComparatorTest() {
    }

    /**
     * Tests the double almost comparator.
     */
    @Test
    public void doubleAlmostComparatorTest() {
        IBinaryComparator<Double> comparator = this.almostComparatorFactory.createDoubleComparator();

        this.testDoubleAlmostComparator(comparator, 0.0, 0.0, 0);
        this.testDoubleAlmostComparator(comparator, 0.0, 1.0, -1);
        this.testDoubleAlmostComparator(comparator, 1.0, 0.0, 1);
        this.testDoubleAlmostComparator(comparator, 0.0, 0.0001, 0);
        this.testDoubleAlmostComparator(comparator, 0.0, 0.001, 0);
        this.testDoubleAlmostComparator(comparator, 0.0, 0.0011, -1);
        this.testDoubleAlmostComparator(comparator, 0.0, 0.00099, 0);
        this.testDoubleAlmostComparator(comparator, 0.0, 0.00009999999999, 0);
        this.testDoubleAlmostComparator(comparator, 0.00009999999999, 0.0, 0);
        this.testDoubleAlmostComparator(comparator, 0.0, 0.00010000000001, 0);
        this.testDoubleAlmostComparator(comparator, 0.0010000000001, 0.0, 1);
    }

    /**
     * Tests the double almost comparator..
     */
    private void testDoubleAlmostComparator(
        IBinaryComparator<Double> comparator,
        double lhs,
        double rhs,
        int expectedResult) {

        int result = comparator.compareTo(lhs, rhs);

        this.assertion.assertEquals(
            result,
            expectedResult,
            "The logic of the double almost comparator is invalid.");
    }
}
