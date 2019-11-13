package games.sudoku.interfaces;

/**
 * The ISudokuBoard interface defines a Sudoku board.
 */
public interface ISudokuBoard {
    /**
     * Tries solving a board.
     */
    boolean trySolve();

    /**
     * Gets the data of the board.
     */
    char[][] getData();
}
