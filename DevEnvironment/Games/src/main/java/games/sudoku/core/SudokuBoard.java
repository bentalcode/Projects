package games.sudoku.core;

import base.core.Conditions;
import base.interfaces.IValidator;
import games.sudoku.interfaces.ISudokuBoard;

/**
 * The SudokuBoard class implements a Sudoku board.
 */
public final class SudokuBoard implements ISudokuBoard {
    private static final int Size = 9;
    private static final int SubSize = 3;

    private final char[][] data;
    private final int size;
    private final int subSize;
    private final IValidator validator;

    /**
     * The SudokuBoard constructor.
     */
    public SudokuBoard(char[][] data) {
        this(
            data,
            SudokuBoard.Size,
            SudokuBoard.SubSize);
    }

    /**
     * The SudokuBoard constructor.
     */
    public SudokuBoard(char[][] data, int size, int subSize) {
        Conditions.validateNotNull(
            data,
            "The data of a Sudoku board.");

        Conditions.validateNotNull(
            size >= 1 && subSize >= 1 && size > subSize && Math.sqrt(size) == subSize,
            "Invalid dimensions of a Sudoku board.");

        IValidator validator = new SudokuBoardValidator(data, size, subSize);

        if (!validator.isValid()) {
            throw new SudokuException("The board of Sudoku is not valid.");
        }

        this.data = data;
        this.size = size;
        this.subSize = subSize;
        this.validator = validator;
    }

    /**
     * Tries solving a board.
     */
    @Override
    public boolean trySolve() {
        return this.trySolve(0, 0);
    }

    /**
     * Gets the data of the board.
     */
    @Override
    public char[][] getData() {
        return this.data;
    }

    /**
     * Tries solving a board.
     */
    private boolean trySolve(int row, int column) {
        assert(row >= 0 && row <= this.size);
        assert(column >= 0 && column < this.size);

        if (row > this.size) {
            return false;
        }

        if (row == this.size) {
            return true;
        }

        int nextRow;
        int nextColumn;

        if (column < this.size - 1) {
            nextRow = row;
            nextColumn = column + 1;
        }
        else {
            nextRow = row + 1;
            nextColumn = 0;
        }

        if (!this.isAvailable(row, column)) {
            return this.trySolve(nextRow, nextColumn);
        }
        else {
            for (int value = 1; value <= this.size; ++value) {
                this.setPositionValue(row, column, value);

                if (this.validator.isValid()) {
                    boolean status = this.trySolve(nextRow, nextColumn);

                    if (status) {
                        return true;
                    }
                    else {
                        this.setPositionAvailable(row, column);
                    }
                }
                else {
                    this.setPositionAvailable(row, column);
                }
            }
        }

        return false;
    }

    /**
     * Checks whether a specific position is available.
     */
    private boolean isAvailable(int row, int column) {
        return this.data[row][column] == '.';
    }

    /**
     * Sets a value of a specific position.
     */
    private void setPositionValue(int row, int column, int value) {
        char character = Character.forDigit(value, 10);
        this.setPositionValue(row, column, character);
    }

    /**
     * Sets a value for a specific position.
     */
    private void setPositionValue(int row, int column, char value) {
        this.data[row][column] = value;
    }

    /**
     * Sets a specific position as available.
     */
    private void setPositionAvailable(int row, int column) {
        this.data[row][column] = '.';
    }
}
