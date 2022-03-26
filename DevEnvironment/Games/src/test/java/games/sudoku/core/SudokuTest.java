package games.sudoku.core;

import base.core.TwoDimensionalCharacterArrayIterator;
import base.interfaces.IIterator;
import games.core.TestData;
import games.interfaces.ITestData;
import games.sudoku.interfaces.ISudokuBoard;
import games.sudoku.interfaces.ISudokuData;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import org.junit.Test;

/**
 * The SudokuTest class implements tests for a Sudoku game.
 */
public final class SudokuTest {
    private final ITestData testData = new TestData();
    private final IAssertion assertion = new Assertion();

    /**
     * The SudokuTest constructor.
     */
    public SudokuTest() {
    }

    /**
     * Tests the logic for solving a Sudoku.
     */
    @Test
    public void solveSudokuTest() {
        for (ISudokuData data : this.testData.getSudokuData().getData()) {
            this.testSolvingSudoku(data);
        }
    }

    /**
     * Tests the logic for solving a Sudoku.
     */
    private void testSolvingSudoku(ISudokuData data) {
        ISudokuBoard board = new SudokuBoard(data.getInitialBoard());
        boolean status = board.trySolve();

        this.assertion.assertTrue(
            status,
            "Incorrect logic for solving Sudoku.");

        IIterator<Character> resultIterator = TwoDimensionalCharacterArrayIterator.make(board.getData());
        IIterator<Character> expectedResultIterator = TwoDimensionalCharacterArrayIterator.make(data.getResultBoard());

        this.assertion.assertEqualsWithIterators(
            resultIterator,
            expectedResultIterator,
            "Incorrect logic for solving Sudoku.");
    }
}
