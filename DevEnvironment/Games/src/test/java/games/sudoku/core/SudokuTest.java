package games.sudoku.core;

import base.core.TwoDimensionalCharacterArrayIterator;
import base.interfaces.IIterator;
import games.core.TestData;
import games.interfaces.ITestData;
import games.sudoku.interfaces.ISudokuBoard;
import games.sudoku.interfaces.ISudokuData;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;

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
            "Invalid logic for solving Sudoku.");

        IIterator<Character> resultIterator = TwoDimensionalCharacterArrayIterator.of(board.getData());
        IIterator<Character> expectedResultIterator = TwoDimensionalCharacterArrayIterator.of(data.getResultBoard());

        this.assertion.assertEqualsWithIterators(
            resultIterator,
            expectedResultIterator,
            "Invalid logic for solving Sudoku.");
    }
}
