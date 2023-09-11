package problems.core;

import base.core.ArrayLists;
import base.core.CollectionIterator;
import base.core.ListIterator;
import base.core.Triplet;
import base.interfaces.ITriplet;
import java.util.Collections;
import java.util.List;
import problems.interfaces.IMatchingTriplets;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import org.junit.Test;

/**
 * The MatchingTripletsTest class implements tests for the matching triplets' problem.
 */
public final class MatchingTripletsTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The MatchingTripletsTest constructor.
     */
    public MatchingTripletsTest() {
    }

    /**
     * Tests the logic for finding the indexes of matching triplets.
     */
    @Test
    public void matchingTripletsIndexesTest() {
        int[] values1 = {0, 1, 1, 1, 2, 2, 2};
        int sum1 = 3;

        List<ITriplet<Integer, Integer, Integer>> result1 = ArrayLists.make(
            Triplet.make(0, 1, 4),
            Triplet.make(0, 1, 5),
            Triplet.make(0, 1, 6),
            Triplet.make(0, 2, 4),
            Triplet.make(0, 2, 5),
            Triplet.make(0, 2, 6),
            Triplet.make(0, 3, 4),
            Triplet.make(0, 3, 5),
            Triplet.make(0, 3, 6),
            Triplet.make(1, 2, 3));

        this.testMatchingTripletsIndexes(values1, sum1, result1);
    }

    /**
     * Tests the logic for finding the values of matching triplets.
     */
    @Test
    public void matchingTripletsTest() {
        int[] values1 = {0, 1, 1, 1, 2, 2, 2};
        int sum1 = 3;

        List<ITriplet<Integer, Integer, Integer>> result1 = ArrayLists.make(
            Triplet.make(0, 1, 2),
            Triplet.make(1, 1, 1));

        this.testMatchingTriplets(values1, sum1, result1);
    }

    /**
     * Tests the logic for finding the closest values of matching triplets.
     */
    @Test
    public void matchingClosestTripletsTest() {
        int[] values1 = {-1, 2, 1, -4};
        int sum1 = 1;
        ITriplet<Integer, Integer, Integer> result1 = Triplet.make(-1, 1, 2);

        int[] values2 = {0, 1, 1, 1, 2, 2, 2};
        int sum2 = 7;
        ITriplet<Integer, Integer, Integer> result2 = Triplet.make(2, 2, 2);

        int[] values3 = {6, 1, -1, 1, 2, 8, 2};
        int sum3 = 1;
        ITriplet<Integer, Integer, Integer> result3 = Triplet.make(-1, 1, 1);

        this.testMatchingClosestTriplet(values1, sum1, result1);
        this.testMatchingClosestTriplet(values2, sum2, result2);
        this.testMatchingClosestTriplet(values3, sum3, result3);
    }

    /**
     * Tests the logic for finding triplets such that sum of two equals to third element.
     */
    @Test
    public void findTripletsTest() {
        int[] values1 = {0, 1, 1, 1, 2, 2, 2};

        List<ITriplet<Integer, Integer, Integer>> result1 = ArrayLists.make(
            Triplet.make(0, 1, 1),
            Triplet.make(0, 2, 2),
            Triplet.make(1, 1, 2));

        this.testFindingTriplets(values1, result1);
    }

    /**
     * Tests the logic for finding the indexes of matching triplets.
     */
    private void testMatchingTripletsIndexes(
        int[] values,
        int sum,
        List<ITriplet<Integer, Integer, Integer>> expectedResult) {

        IMatchingTriplets matchingTriplets = new MatchingTriplets();
        List<ITriplet<Integer, Integer, Integer>> result = matchingTriplets.findMatchingTripletsIndexes(values, sum);

        Collections.sort(result);

        this.assertion.assertEqualsWithIterators(
            ListIterator.make(result),
            CollectionIterator.make(expectedResult),
            "Incorrect logic for finding the indexes of matching triplets.");
    }

    /**
     * Tests the logic for finding the values of matching triplets.
     */
    private void testMatchingTriplets(
        int[] values,
        int sum,
        List<ITriplet<Integer, Integer, Integer>> expectedResult) {

        IMatchingTriplets matchingTriplets = new MatchingTriplets();
        List<ITriplet<Integer, Integer, Integer>> result = matchingTriplets.findMatchingTriplets(values, sum);
        Collections.sort(result);

        this.assertion.assertEqualsWithIterators(
            CollectionIterator.make(result),
            CollectionIterator.make(expectedResult),
            "Incorrect logic for finding the values of matching triplets.");
    }

    /**
     * Tests the logic for finding the closest values of matching triplets.
     */
    private void testMatchingClosestTriplet(
        int[] values,
        int sum,
        ITriplet<Integer, Integer, Integer> expectedResult) {

        IMatchingTriplets matchingTriplets = new MatchingTriplets();
        ITriplet<Integer, Integer, Integer> result = matchingTriplets.findClosestMatchingTriplet(values, sum);

        this.assertion.assertEquals(
            result,
            expectedResult,
            "Incorrect logic for finding the closest values of matching triplet.");
    }

    /**
     * Tests the logic for finding triplets such that sum of two equals to third element.
     */
    private void testFindingTriplets(
        int[] values,
        List<ITriplet<Integer, Integer, Integer>> expectedResult) {

        IMatchingTriplets matchingTriplets = new MatchingTriplets();
        List<ITriplet<Integer, Integer, Integer>> result = matchingTriplets.findTriplets(values);
        Collections.sort(result);

        this.assertion.assertEqualsWithIterators(
            ListIterator.make(result),
            ListIterator.make(expectedResult),
            "Incorrect logic for finding triplets such that sum of two equals to third element.");
    }
}
