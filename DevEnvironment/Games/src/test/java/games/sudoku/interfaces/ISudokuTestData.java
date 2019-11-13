package games.sudoku.interfaces;

import java.util.List;

/**
 * The ISudokuTestData interface defines the data of the tests of a Sudoku.
 */
public interface ISudokuTestData {
    /**
     * Gets the data of a Sudoku.
     */
    List<ISudokuData> getData();
}
