package games.sudoku.core;

import games.GamesException;

/**
 * The SudokuException class implements an exception for capturing errors in the Sudoku module.
 */
public class SudokuException extends GamesException {
    /**
     * The SudokuException constructor.
     */
    public SudokuException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The SudokuException constructor.
     */
    public SudokuException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
