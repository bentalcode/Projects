package problems.core;

import problems.interfaces.IPositionQueens;
import java.util.ArrayList;
import java.util.List;

/**
 * The PositionQueens class implements the position queens problem.
 */
public final class PositionQueens implements IPositionQueens {

    /**
     * Positions queens and returns the boards.
     */
    @Override
    public List<List<String>> positionQueens(int size) {
        List<List<Integer>> boards = new ArrayList<>();

        if (size < 4) {
            return this.createBoardsAsString(boards, size);
        }

        List<Integer> board = createBoard(size);

        this.positionQueens(
            board,
            size,
            0,
            boards);

        return this.createBoardsAsString(boards, size);
    }

    /**
     * Positions queens.
     */
    private boolean positionQueens(
        List<Integer> board,
        int size,
        int columnIndex,
        List<List<Integer>> boards) {

        assert(columnIndex >= 0 && columnIndex <= size);

        if (size < 4) {
            return false;
        }

        if (columnIndex == size) {
            List<Integer> newBoard = new ArrayList<>(board);
            boards.add(newBoard);
            return true;
        }

        boolean status = false;

        for (int rowIndex = 0; rowIndex < size; ++rowIndex) {
            this.positionQueen(board, rowIndex, columnIndex);

            if (this.validateBoard(board, size, rowIndex, columnIndex)) {
                boolean currStatus = this.positionQueens(
                    board,
                    size,
                    columnIndex + 1,
                    boards);

                if (currStatus) {
                    status = true;
                }
            }

            this.unPositionQueen(board, columnIndex);
        }

        return status;
    }

    /**
     * Positions a queen.
     */
    private void positionQueen(
        List<Integer> board,
        int rowIndex,
        int columnIndex) {

        board.set(columnIndex, rowIndex);
    }

    /**
     * UnPositions a queen.
     */
    private void unPositionQueen(
        List<Integer> board,
        int columnIndex) {

        board.set(columnIndex, -1);
    }

    /**
     * Validates a board.
     */
    private boolean validateBoard(
        List<Integer> board,
        int size,
        int rowIndex,
        int columnIndex) {

        //
        // Validates the left row...
        //
        int currRowIndex = rowIndex;
        int currColumnIndex = columnIndex - 1;

        while (currColumnIndex >= 0) {
            if (this.hasQueen(board, currRowIndex, currColumnIndex)) {
                return false;
            }

            --currColumnIndex;
        }

        //
        // Validates the upper column...
        //
        currRowIndex = rowIndex + 1;
        currColumnIndex = columnIndex;

        while (currRowIndex < size) {
            if (this.hasQueen(board, currRowIndex, currColumnIndex)) {
                return false;
            }

            ++currRowIndex;
        }

        //
        // Validates the lower column...
        //
        currRowIndex = rowIndex - 1;

        while (currRowIndex >= 0) {
            if (this.hasQueen(board, currRowIndex, currColumnIndex)) {
                return false;
            }

            --currRowIndex;
        }

        //
        // Validates the LeftUpper -> RightBottom diagonal...
        //
        currRowIndex = rowIndex + 1;
        currColumnIndex = columnIndex - 1;

        while (currRowIndex < size && currColumnIndex >= 0) {
            if (this.hasQueen(board, currRowIndex, currColumnIndex)) {
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
            if (this.hasQueen(board, currRowIndex, currColumnIndex)) {
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
    private boolean hasQueen(
        List<Integer> board,
        int rowIndex,
        int columnIndex) {

        return board.get(columnIndex) == rowIndex;
    }

    /**
     * Create a board of queens.
     */
    private List<Integer> createBoard(int size) {
        List<Integer> board = new ArrayList<>(size);

        for (int i = 0; i < size; ++i) {
            board.add(-1);
        }

        return board;
    }

    /**
     * Creates boards as string.
     */
    private List<List<String>> createBoardsAsString(
        List<List<Integer>> boards,
        int size) {

        List<List<String>> results = new ArrayList<>();

        for (List<Integer> board : boards) {
            List<String> result = this.createBoardAsString(board, size);
            results.add(result);
        }

        return results;
    }

    /**
     * Creates a board as string.
     */
    private List<String> createBoardAsString(
        List<Integer> board,
        int size) {

        List<String> result = new ArrayList<>(size);

        for (int rowIndex = 0; rowIndex < size; ++rowIndex) {
            char[] currRow = new char[size];

            for (int columnIndex = 0; columnIndex < size; ++columnIndex) {
                if (this.hasQueen(board, rowIndex, columnIndex)) {
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
