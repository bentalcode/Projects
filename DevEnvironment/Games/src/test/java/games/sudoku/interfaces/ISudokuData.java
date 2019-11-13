package games.sudoku.interfaces;

/**
 * The ISudokuData interface defines the data of a Sudoku.
 */
public interface ISudokuData {
    /**
     * Gets the initial data of a Sudoku board.
     */
    char[][] getInitialBoard();

    /**
     * Gets the result data of a Sudoku board.
     */
    char[][] getResultBoard();
}
