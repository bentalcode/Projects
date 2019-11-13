package games.interfaces;

import games.sudoku.interfaces.ISudokuTestData;

/**
 * The ITestData interface defines the data of the tests.
 */
public interface ITestData {
    /**
     * Gets the data of tests of a Sudoku.
     */
    ISudokuTestData getSudokuData();
}
