package games.core;

import games.sudoku.core.SudokuTestData;
import games.sudoku.interfaces.ISudokuTestData;
import games.interfaces.ITestData;

/**
 * The TestData class implements the data of the tests.
 */
public final class TestData implements ITestData {
    /**
     * The TestData constructor.
     */
    public TestData() {
    }

    /**
     * Gets the data of tests of a Sudoku.
     */
    @Override
    public ISudokuTestData getSudokuData() {
        return new SudokuTestData();
    }
}
