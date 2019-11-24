package problems.core;

import base.core.ArrayLists;
import base.core.CollectionIterator;
import base.core.ListIterator;
import base.core.Triple;
import base.core.Triplet;
import base.interfaces.ITriplet;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import problems.interfaces.IMatchingTriplets;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Set;

/**
 * The MatchingTripletsTest class implements tests for matching triplets.
 */
public final class MatchingTripletsTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The MatchingTripletsTest constructor.
     */
    public MatchingTripletsTest() {
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
     * Tests the logic for calculating the indexes of matching triplets.
     */
    @Test
    public void matchingTripletsIndexesTest() {
        int[] values1 = {0, 1, 1, 1, 2, 2, 2};
        int sum1 = 3;

        List<ITriplet<Integer, Integer, Integer>> result1 = ArrayLists.of(
            Triplet.of(0, 1, 4),
            Triplet.of(0, 1, 5),
            Triplet.of(0, 1, 6),
            Triplet.of(0, 2, 4),
            Triplet.of(0, 2, 5),
            Triplet.of(0, 2, 6),
            Triplet.of(0, 3, 4),
            Triplet.of(0, 3, 5),
            Triplet.of(0, 3, 6),
            Triplet.of(1, 2, 3));

        this.testMatchingTripletsIndexes(values1, sum1, result1);
    }

    /**
     * Tests the logic for calculating the values of matching triplets.
     */
    @Test
    public void matchingTripletsTest() {
        int[] values1 = {0, 1, 1, 1, 2, 2, 2};
        int sum1 = 3;

        List<ITriplet<Integer, Integer, Integer>> result1 = ArrayLists.of(
            Triplet.of(0, 1, 2),
            Triplet.of(1, 1, 1));

        this.testMatchingTriplets(values1, sum1, result1);
    }

    /**
     * Tests the logic for calculating the closest values of matching triplets.
     */
    @Test
    public void matchingClosestTripletsTest() {
        int[] values1 = {-1, 2, 1, -4};
        int sum1 = 1;

        ITriplet<Integer, Integer, Integer> result1 = Triplet.of(-1, 1, 2);

        this.testMatchingClosestTriplets(values1, sum1, result1);
    }

    /**
     * Tests the logic for calculating the indexes of matching triplets.
     */
    private void testMatchingTripletsIndexes(
        int[] values,
        int sum,
        List<ITriplet<Integer, Integer, Integer>> expectedResult) {

        IMatchingTriplets matchingTriplets = new MatchingTriplets();
        List<ITriplet<Integer, Integer, Integer>> result = matchingTriplets.getMatchingTripletsIndexes(values, sum);

        Collections.sort(result);

        this.assertion.assertEqualsWithIterators(
            ListIterator.of(result),
            CollectionIterator.of(expectedResult),
            "Invalid logic for calculating the indexes of matching triplets.");
    }

    /**
     * Tests the logic for calculating the values of matching triplets.
     */
    private void testMatchingTriplets(
        int[] values,
        int sum,
        List<ITriplet<Integer, Integer, Integer>> expectedResult) {

        IMatchingTriplets matchingTriplets = new MatchingTriplets();
        Set<ITriplet<Integer, Integer, Integer>> result = matchingTriplets.getMatchingTriplets(values, sum);

        List<ITriplet<Integer, Integer, Integer>> sortedResult = new ArrayList<>(result);
        Collections.sort(sortedResult);

        this.assertion.assertEqualsWithIterators(
            CollectionIterator.of(sortedResult),
            CollectionIterator.of(expectedResult),
            "Invalid logic for calculating the values of matching triplets.");
    }

    /**
     * Tests the logic for calculating the closest values of matching triplets.
     */
    private void testMatchingClosestTriplets(
        int[] values,
        int sum,
        ITriplet<Integer, Integer, Integer> expectedResult) {

        IMatchingTriplets matchingTriplets = new MatchingTriplets();
        ITriplet<Integer, Integer, Integer> result = matchingTriplets.getClosestMatchingTriplets(values, sum);

        this.assertion.assertEquals(
            result,
            expectedResult,
            "Invalid logic for calculating the closest values of matching triplets.");
    }
}
