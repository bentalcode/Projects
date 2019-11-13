package games.sudoku.core;

import games.sudoku.interfaces.ISudokuData;

/**
 * The SudokuData class implements the data of a sudoku.
 */
public final class SudokuData implements ISudokuData {
    private final char[][] boardData;
    private final char[][] resultData;

    /**
     * The SudokuData constructor.
     */
    public SudokuData(char[][] boardData, char[][] resultData) {
        this.boardData = boardData;
        this.resultData = resultData;
    }

    /**
     * Gets the initial data of a Sudoku board.
     */
    @Override
    public char[][] getInitialBoard() {
        return this.boardData;
    }

    /**
     * Gets the result data of a Sudoku board.
     */
    @Override
    public char[][] getResultBoard() {
        return this.resultData;
    }
}
