package problems.core;

import base.core.ArrayLists;
import base.core.TwoDimensionalListIterator;
import java.util.List;
import problems.interfaces.IPositionQueens;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import org.junit.Test;

/**
 * The PositionQueensTest class implements tests for the position queens problem.
 */
public final class PositionQueensTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The PositionQueensTest constructor.
     */
    public PositionQueensTest() {
    }

    /**
     * Tests the logic for position queens.
     */
    @Test
    public void combinationSumTest() {
        int size1 = 1;
        List<List<String>> result1 = ArrayLists.make();

        int size2 = 2;
        List<List<String>> result2 = ArrayLists.make();

        int size3 = 3;
        List<List<String>> result3 = ArrayLists.make();

        int size4 = 4;
        List<List<String>> result4 = ArrayLists.make(
            ArrayLists.make(
                "..Q.",
                "Q...",
                "...Q",
                ".Q.."),
            ArrayLists.make(
                ".Q..",
                "...Q",
                "Q...",
                "..Q.")
        );

        int size5 = 5;
        List<List<String>> result5 = ArrayLists.make(
            ArrayLists.make(
                "Q....",
                "...Q.",
                ".Q...",
                "....Q",
                "..Q.."),
            ArrayLists.make(
                "Q....",
                "..Q..",
                "....Q",
                ".Q...",
                "...Q."),
            ArrayLists.make(
                "..Q..",
                "Q....",
                "...Q.",
                ".Q...",
                "....Q"),
            ArrayLists.make(
                "...Q.",
                "Q....",
                "..Q..",
                "....Q",
                ".Q..."),
            ArrayLists.make(
                ".Q...",
                "...Q.",
                "Q....",
                "..Q..",
                "....Q"),
            ArrayLists.make(
                "....Q",
                "..Q..",
                "Q....",
                "...Q.",
                ".Q..."),
            ArrayLists.make(
                ".Q...",
                "....Q",
                "..Q..",
                "Q....",
                "...Q."),
            ArrayLists.make(
                "....Q",
                ".Q...",
                "...Q.",
                "Q....",
                "..Q.."),
            ArrayLists.make(
                "...Q.",
                ".Q...",
                "....Q",
                "..Q..",
                "Q...."),
            ArrayLists.make(
                "..Q..",
                "....Q",
                ".Q...",
                "...Q.",
                "Q....")
        );

        int size6 = 6;
        List<List<String>> result6 = ArrayLists.make(
            ArrayLists.make(
                "...Q..",
                "Q.....",
                "....Q.",
                ".Q....",
                ".....Q",
                "..Q..."),
            ArrayLists.make(
                "....Q.",
                "..Q...",
                "Q.....",
                ".....Q",
                "...Q..",
                ".Q...."),
            ArrayLists.make(
                ".Q....",
                "...Q..",
                ".....Q",
                "Q.....",
                "..Q...",
                "....Q."),
            ArrayLists.make(
                "..Q...",
                ".....Q",
                ".Q....",
                "....Q.",
                "Q.....",
                "...Q..")
        );

        this.testPositionQueens(size1, result1);
        this.testPositionQueens(size2, result2);
        this.testPositionQueens(size3, result3);
        this.testPositionQueens(size4, result4);
        this.testPositionQueens(size5, result5);
        this.testPositionQueens(size6, result6);
    }

    /**
     * Tests the logic for position queens.
     */
    private void testPositionQueens(
        int size,
        List<List<String>> expectedResult) {

        IPositionQueens positionQueens = new PositionQueens();
        List<List<String>> result = positionQueens.positionQueens(size);

        this.assertion.assertEqualsWithIterators(
            TwoDimensionalListIterator.make(result),
            TwoDimensionalListIterator.make(expectedResult),
            "Incorrect logic for position queens.");
    }
}
