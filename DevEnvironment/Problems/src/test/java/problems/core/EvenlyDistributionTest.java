package problems.core;

import base.core.Pair;
import base.interfaces.IPair;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import problems.interfaces.IEventlyDistribution;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import java.util.Arrays;

/**
 * The EvenlyDistributionTest class implements tests for evenly distribution.
 */
public final class EvenlyDistributionTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The EvenlyDistributionTest constructor.
     */
    public EvenlyDistributionTest() {
    }

    /**
     * Initialize the tests.
     */
    @Before
    public void setUp() {
    }

    /**
     * Un-Initializes the tests.
     */
    @After
    public void tearDown() {
    }

    /**
     * Tests the even distribution logic.
     */
    @Test
    public void evenDistributingTest() {
        int[] values1 = {1, 2, 3, 4, 5, 6};
        int[] set1 = {1, 3, 6};
        int[] set2 = {2, 4, 5};

        this.testEvenlyDistributing(values1, Pair.of(set1, set2));
    }

    /**
     * Tests the even distribution heuristic logic.
     */
    @Test
    public void evenDistributingHeuristicTest() {
        int[] values1 = {6, 5, 4, 3, 1, 2};
        int[] setA1 = {1, 3, 5};
        int[] setB1 = {2, 4, 6};

        int[] values2 = {1, 2, 3, 4, 5, 6};
        int[] setA2 = {1, 3, 5};
        int[] setB2 = {2, 4, 6};

        this.testEvenlyDistributingHeuristic(values1, Pair.of(setA1, setB1));
        this.testEvenlyDistributingHeuristic(values2, Pair.of(setA2, setB2));
    }

    /**
     * Tests the even distribution logic.
     */
    private void testEvenlyDistributing(int[] values, IPair<int[], int[]> expectedResult) {
        IEventlyDistribution evenlyDistribution = new EvenlyDistribution();
        IPair<int[], int[]> result = evenlyDistribution.evenlyDistribute(values);

        int[] firstSet = result.first();
        Arrays.sort(firstSet);

        int[] secondSet = result.second();
        Arrays.sort(secondSet);

        this.assertion.assertEquals(
            firstSet,
            expectedResult.first(),
            "Invalid evenly distribution logic.");

        this.assertion.assertEquals(
            secondSet,
            expectedResult.second(),
            "Invalid evenly distribution logic.");
    }

    /**
     * Tests the even distribution heuristic logic.
     */
    private void testEvenlyDistributingHeuristic(int[] values, IPair<int[], int[]> expectedResult) {
        IEventlyDistribution evenlyDistribution = new EvenlyDistribution();
        IPair<int[], int[]> result = evenlyDistribution.evenlyDistributeHeuristic(values);

        int[] firstSet = result.first();
        Arrays.sort(firstSet);

        int[] secondSet = result.second();
        Arrays.sort(secondSet);

        this.assertion.assertEquals(
            firstSet,
            expectedResult.first(),
            "Invalid evenly distribution heuristic logic.");

        this.assertion.assertEquals(
            secondSet,
            expectedResult.second(),
            "Invalid evenly distribution heuristic logic.");
    }
}
