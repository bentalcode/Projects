package problems.core;

import base.core.Conditions;
import base.interfaces.ICalculator;

/**
 * The MaxRectangleArea class implements a calculation of a max rectangle area.
 */
public final class MaxRectangleArea implements ICalculator<Integer> {
    private final int[][] data;
    private final int rows;
    private final int cols;

    /**
     * The MaxRectangleArea constructor.
     */
    public MaxRectangleArea(int[][] data) {
        Conditions.validateNotNull(
            data,
            "The data of a matrix.");

        validateMatrix(data);

        this.data = data;
        this.rows = data.length;
        this.cols = data[0].length;
    }

    /**
     * Given a 2D binary matrix filled with 0's and 1's,
     * find the largest rectangle containing only 1's and return its area.
     */
    @Override
    public Integer calculate() {
        int maxSize = 0;

        for (int row = 0; row < this.rows; ++row) {
            for (int col = 0; col < this.cols; ++col) {

                if (this.validRectanglePosition(row, col)) {
                    int currSize = this.calculateMaxRectangleArea(
                        row,
                        col,
                        row,
                        col);

                    if (currSize > maxSize) {
                        maxSize = currSize;
                    }
                }
            }
        }

        return maxSize;
    }

    /**
     * Calculates the maximum rectangle area.
     */
    private int calculateMaxRectangleArea(
        int leftUpperRow, int leftUpperCol,
        int rightBottomRow, int rightBottomCol) {

        int maxSize = size(
            leftUpperRow, leftUpperCol,
            rightBottomRow, rightBottomCol);

        //
        // Try moving right...
        //
        if (this.validRectanglePosition(rightBottomRow, rightBottomCol + 1) &&
            this.validRectangleColumn(leftUpperRow, rightBottomCol + 1, length(leftUpperRow, rightBottomRow))) {

            int size = this.calculateMaxRectangleArea(
                leftUpperRow, leftUpperCol,
                rightBottomRow, rightBottomCol + 1);

            if (size > maxSize) {
                maxSize = size;
            }
        }

        //
        // Try moving bottom...
        //
        if (this.validRectanglePosition(rightBottomRow + 1, rightBottomCol) &&
            this.validRectangleRow(rightBottomRow + 1, leftUpperCol, length(leftUpperCol, rightBottomCol))) {

            int size = this.calculateMaxRectangleArea(
                leftUpperRow, leftUpperCol,
                rightBottomRow + 1, rightBottomCol);

            if (size > maxSize) {
                maxSize = size;
            }
        }

        //
        // Try moving down right-bottom diagonal...
        //
        if (this.validRectanglePosition(rightBottomRow + 1, rightBottomCol + 1) &&
            this.validRectangleRow(rightBottomRow + 1, leftUpperCol, length(leftUpperCol, rightBottomCol)) &&
            this.validRectangleColumn(leftUpperRow, rightBottomCol + 1, length(leftUpperRow, rightBottomRow))) {

            int size = this.calculateMaxRectangleArea(
                leftUpperRow, leftUpperCol,
                rightBottomRow + 1, rightBottomCol + 1);

            if (size > maxSize) {
                maxSize = size;
            }
        }

        return maxSize;
    }

    /**
     * Checks whether a specific position is in bound.
     */
    private boolean inbound(int row, int col) {
        return row >= 0 && row < this.rows && col >= 0 && col < this.cols;
    }

    /**
     * Checks if a specific position is part of a rectangle.
     */
    private boolean validRectanglePosition(int row, int col) {
        return this.inbound(row, col) && this.data[row][col] == 1;
    }

    /**
     * Checks if a specific row is part of a rectangle.
     */
    private boolean validRectangleRow(int row, int col, int length) {
        int currCol = col;
        int endCol = col + length - 1;

        while (currCol <= endCol) {
            if (!this.validRectanglePosition(row, currCol)) {
                return false;
            }

            ++currCol;
        }

        return true;
    }

    /**
     * Checks if a specific column is part of a rectangle.
     */
    private boolean validRectangleColumn(int row, int col, int length) {
        int currRow = row;
        int endRow = row + length - 1;

        while (currRow <= endRow) {
            if (!this.validRectanglePosition(currRow, col)) {
                return false;
            }

            ++currRow;
        }

        return true;
    }

    /**
     * Gets the size of a rectangle.
     */
    private static int size(
        int leftUpperRow, int leftUpperCol,
        int rightBottomRow, int rightBottomCol) {

        int width = length(leftUpperCol, rightBottomCol);
        int height = length(leftUpperRow, rightBottomRow);

        return width * height;
    }

    /**
     * Gets the length of a dimension.
     */
    private static int length(int lower, int higher) {
        if (lower > higher) {
            return 0;
        }

        return higher - lower + 1;
    }

    /**
     * Validates that a matrix is valid.
     */
    private static void validateMatrix(int[][] data) {
        if (!isMatrixValid(data)) {
            throw new IllegalArgumentException("The input matrix is not valid.");
        }
    }

    /**
     * Checks whether a matrix is is valid.
     */
    private static boolean isMatrixValid(int[][] data) {
        if (data == null) {
            return false;
        }

        if (data.length == 0) {
            return false;
        }

        int rows = data.length;
        int cols = data[0].length;

        for (int row = 1; row < rows; ++row) {
            int currCols = data[row].length;

            if (currCols != cols) {
                return false;
            }
        }

        return true;
    }
}
