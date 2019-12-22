package games.sudoku.core;

import base.interfaces.IValidator;

/**
 * The SudokuBoardValidator class implements a validator of a Sudoku board.
 */
public final class SudokuBoardValidator implements IValidator {
    private final char[][] board;
    private final int size;
    private final int subSize;

    /**
     * The SudokuBoardValidator constructor.
     */
    public SudokuBoardValidator(char[][] board, int size, int subSize) {
        this.board = board;
        this.size = size;
        this.subSize = subSize;
    }

    /**
     * Validates a Sudoku board.
     */
    @Override
    public boolean isValid() {
        if (this.board == null || this.board.length != this.size) {
            return false;
        }

        for (char[] row : this.board) {
            if (row.length != this.size) {
                return false;
            }
        }

        if (!this.rowsValid()) {
            return false;
        }

        if (!this.columnsValid()) {
            return false;
        }

        if (!this.subBoardsValid()) {
            return false;
        }

        return true;
    }

    /**
     * Validates the rows.
     */
    private boolean rowsValid() {
        for (int row = 0; row < this.size; ++row) {
            boolean[] visited = new boolean[this.size];

            for (int column = 0; column < this.size; ++column) {

                char currValue = this.board[row][column];

                if (!this.validateValue(currValue, visited)) {
                    return false;
                }
            }
        }

        return true;
    }

    /**
     * Validates the columns.
     */
    private boolean columnsValid() {
        for (int column = 0; column < this.size; ++column) {
            boolean[] visited = new boolean[this.size];

            for (int row = 0; row < this.size; ++row) {

                char currValue = this.board[row][column];

                if (!this.validateValue(currValue, visited)) {
                    return false;
                }
            }
        }

        return true;
    }

    /**
     * Validates the sub-boards.
     */
    private boolean subBoardsValid() {
        for (int subBoard = 0; subBoard < this.size; ++subBoard) {
            boolean[] visited = new boolean[this.size];

            for (int row = ((subBoard / this.subSize) * this.subSize); row < this.subSize + ((subBoard / this.subSize) * this.subSize); ++row) {
                for (int column = ((subBoard % this.subSize) * this.subSize); column < this.subSize + ((subBoard % this.subSize) * this.subSize); ++column) {

                    char currValue = this.board[row][column];

                    if (!this.validateValue(currValue, visited)) {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    /**
     * Validates a value.
     */
    private boolean validateValue(char value, boolean[] visited) {
        if (value == '.') {
            return true;
        }

        Integer digit = this.tryParseDigit(value);

        if (digit == null || digit == 0) {
            return false;
        }

        if (visited[digit - 1]) {
            return false;
        }

        visited[digit - 1] = true;

        return true;
    }

    /**
     * Tries to parse a digit.
     */
    private Integer tryParseDigit(char value) {
        if (value < '0' || value > '9') {
            return null;
        }

        return value - '0';
    }
}
