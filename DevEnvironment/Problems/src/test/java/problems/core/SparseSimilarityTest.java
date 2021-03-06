package problems.core;

import base.core.ArrayLists;
import base.interfaces.ICalculator;
import base.interfaces.IIterator;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import problems.interfaces.IAdding;
import problems.interfaces.ISparseSimilarityResult;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.ListIterator;

/**
 * The SparseSimilarityTest class implements tests for a sparse similarity problem.
 */
public final class SparseSimilarityTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The SparseSimilarityTest constructor.
     */
    public SparseSimilarityTest() {
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
     * Tests the logic of sparse similarity.
     */
    @Test
    public void sparseSimilarityTest() {
        List<List<String>> collections1 = ArrayLists.make(
            ArrayLists.make("c", "c", "b", "a", "d", "c"),
            ArrayLists.make("a", "b", "c", "d", "d", "d", "e")
        );

        List<ISparseSimilarityResult> result1 = ArrayLists.make(
            new SparseSimilarityResult(0, 1, 4, 5, 0.8)
        );

        List<List<String>> collections2 = ArrayLists.make(
            ArrayLists.make("a", "b", "c"),
            ArrayLists.make("a", "b", "c", "d"),
            ArrayLists.make("b", "c")
        );

        List<ISparseSimilarityResult> result2 = ArrayLists.make(
            new SparseSimilarityResult(0, 1, 3, 4, 0.75),
            new SparseSimilarityResult(0, 2, 2, 3, 0.666),
            new SparseSimilarityResult(1, 2, 2, 4, 0.5)
        );

        List<List<String>> collections3 = ArrayLists.make(
            ArrayLists.make("c", "b", "d", "e"),
            ArrayLists.make("a", "c", "e", "h", "f"),
            ArrayLists.make("b", "c", "c")
        );

        List<ISparseSimilarityResult> result3 = ArrayLists.make(
            new SparseSimilarityResult(0, 1, 2, 7, 0.285),
            new SparseSimilarityResult(0, 2, 2, 4, 0.5),
            new SparseSimilarityResult(1, 2, 1, 6, 0.166)
        );

        this.testSparseSimilarity(collections1, result1);
        this.testSparseSimilarity(collections2, result2);
        this.testSparseSimilarity(collections3, result3);
    }

    /**
     * Tests the logic of sparse similarity.
     */
    private <T extends Comparable<T>> void testSparseSimilarity(
        List<List<T>> collections,
        List<ISparseSimilarityResult> expectedResult) {

        ICalculator<List<ISparseSimilarityResult>> sparseSimilarity = new SparseSimilarity<>(collections);
        List<ISparseSimilarityResult> result = sparseSimilarity.calculate();

        sortResult(result);
        sortResult(expectedResult);

        this.assertion.assertEqualsWithIterators(
            base.core.ListIterator.make(result),
            base.core.ListIterator.make(expectedResult),
            "Incorrect logic sparse similarity.");
    }

    /**
     * Sorts the result.
     */
    private void sortResult(List<ISparseSimilarityResult> result) {
        Collections.sort(result, new Comparator<ISparseSimilarityResult>() {
            @Override
            public int compare(ISparseSimilarityResult left, ISparseSimilarityResult right) {
                if (left == null && right == null) {
                    return 0;
                }

                if (left == null) {
                    return -1;
                }

                if (right == null) {
                    return 1;
                }

                if (left.getCollectionId1() < right.getCollectionId1()) {
                    return -1;
                }

                if (left.getCollectionId1() > right.getCollectionId1()) {
                    return 1;
                }

                if (left.getCollectionId2() < right.getCollectionId2()) {
                    return -1;
                }

                if (left.getCollectionId2() > right.getCollectionId2()) {
                    return 1;
                }

                return 0;
            }
        });
    }
}
