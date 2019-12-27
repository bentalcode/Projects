package problems.core;

import problems.interfaces.IPositionQueens;
import java.util.ArrayList;
import java.util.List;

/**
 * The PositionQueens class implements the position queens problem.
 */
public final class PositionQueens implements IPositionQueens {

    /**
     * Positions queens.
     */
    @Override
    public List<List<String>> positionQueens(int size) {
        List<List<Integer>> positions = new ArrayList<>();

        if (size < 4) {
            return this.createResults(size, positions);
        }

        List<Integer> currPosition = new ArrayList<>(size);

        for (int i = 0; i < size; ++i) {
            currPosition.add(-1);
        }

        this.positionQueens(
            size,
            currPosition,
            0,
            positions);

        List<List<String>> results = this.createResults(size, positions);

        return results;
    }

    /**
     * Positions queens.
     */
    private void positionQueens(
        int size,
        List<Integer> currPosition,
        int currColumnIndex,
        List<List<Integer>> result) {

        assert(currColumnIndex >= 0 && currColumnIndex <= size);

        if (currColumnIndex > size) {
            return;
        }

        if (currColumnIndex == size) {
            List<Integer> newPosition = new ArrayList<>(currPosition);
            result.add(newPosition);
            return;
        }

        for (int currRowIndex = 0; currRowIndex < size; ++currRowIndex) {
            this.positionQueen(currPosition, currRowIndex, currColumnIndex);

            if (this.validatePosition(currPosition, size, currRowIndex, currColumnIndex)) {
                this.positionQueens(
                    size,
                    currPosition,
                    currColumnIndex + 1,
                    result);
            }

            this.unPositionQueen(currPosition, currColumnIndex);
        }
    }

    /**
     * Positions a queen.
     */
    private void positionQueen(List<Integer> position, int rowIndex, int columnIndex) {
        position.set(columnIndex, rowIndex);
    }

    /**
     * UnPositions a queen.
     */
    private void unPositionQueen(List<Integer> position, int columnIndex) {
        position.set(columnIndex, -1);
    }

    /**
     * Validates a position.
     */
    private boolean validatePosition(List<Integer> position, int size, int rowIndex, int columnIndex) {
        //
        // Validates the row...
        //
        int currRowIndex = rowIndex;
        int currColumnIndex = columnIndex - 1;

        while (currColumnIndex >= 0) {
            if (this.hasQueen(position, currRowIndex, currColumnIndex)) {
                return false;
            }

            --currColumnIndex;
        }

        //
        // Validates the LeftUpper -> RightBottom diagonal...
        //
        currRowIndex = rowIndex + 1;
        currColumnIndex = columnIndex - 1;

        while (currRowIndex < size && currColumnIndex >= 0) {
            if (this.hasQueen(position, currRowIndex, currColumnIndex)) {
                return false;
            }

            ++currRowIndex;
            --currColumnIndex;
        }

        //
        // Validates the LeftBottom -> RightUpper diagonal...
        //
        currRowIndex = rowIndex - 1;
        currColumnIndex = columnIndex - 1;

        while (currRowIndex >= 0 && currColumnIndex >= 0) {
            if (this.hasQueen(position, currRowIndex, currColumnIndex)) {
                return false;
            }

            --currRowIndex;
            --currColumnIndex;
        }

        return true;
    }

    /**
     * Checks whether the specific position includes a queen.
     */
    private boolean hasQueen(List<Integer> position, int rowIndex, int columnIndex) {
        return position.get(columnIndex) == rowIndex;
    }

    /**
     * Creates the positions.
     */
    private List<List<String>> createResults(int size, List<List<Integer>> positions) {
        List<List<String>> results = new ArrayList<>();

        for (List<Integer> position : positions) {
            List<String> result = this.createResult(size, position);
            results.add(result);
        }

        return results;
    }

    /**
     * Creates a position.
     */
    private List<String> createResult(int size, List<Integer> position) {
        List<String> result = new ArrayList<>(size);

        for (int rowIndex = 0; rowIndex < size; ++rowIndex) {
            char[] currRow = new char[size];

            for (int columnIndex = 0; columnIndex < size; ++columnIndex) {
                if (this.hasQueen(position, rowIndex, columnIndex)) {
                    currRow[columnIndex] = 'Q';
                }
                else {
                    currRow[columnIndex] = '.';
                }
            }

            String currRowString = String.valueOf(currRow);
            result.add(currRowString);
        }

        return result;
    }
}
