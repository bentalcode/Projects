package problems.core;

import java.util.*;

import base.core.Pair;
import datastructures.expressiontree.interfaces.IExpressionTree;
import org.junit.Test;

public final class GenericTest {
    /**
     * The GenericTest constructor.
     */
    public GenericTest() {

    }

    /**
     * Tests the even distribution logic.
     */
    @Test
    public void test() {
        char[][] board = new char[4][4];
        board[0][0] = 'X'; board[0][1] = 'X'; board[0][2] = 'X'; board[0][3] = 'X';
        board[1][0] = 'X'; board[1][1] = 'O'; board[1][2] = 'O'; board[1][3] = 'X';
        board[2][0] = 'X'; board[2][1] = 'X'; board[2][2] = 'O'; board[2][3] = 'X';
        board[3][0] = 'X'; board[3][1] = 'O'; board[3][2] = 'X'; board[3][3] = 'X';
        // [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

        new Solution().solve(board);
    }

    class Position {
        private final int rowIndex;
        private final int colIndex;

        public Position(int rowIndex, int colIndex) {
            this.rowIndex = rowIndex;
            this.colIndex = colIndex;
        }

        public int getRowIndex() {
            return this.rowIndex;
        }

        public int getColIndex() {
            return this.colIndex;
        }

        @Override
        public boolean equals(Object other) {
            if (other == null) {
                return false;
            }

            if (!this.getClass().isInstance(other)) {
                return false;
            }

            return isEqual((Position)other);
        }

        @Override
        public int hashCode() {
            return this.getRowIndex() ^ this.getColIndex();
        }

        private boolean isEqual(Position other) {
            if (other == null) {
                return false;
            }

            return
                this.getRowIndex() == other.getRowIndex() &&
                this.getColIndex() == other.getColIndex();
        }
    }

    class Solution {
        public void solve(char[][] board) {
            validateBoard(board);

            int rowsSize = board.length;
            int colsSize = board[0].length;

            List<List<Position>> ilands = new ArrayList<>();
            Set<Position> visited = new HashSet();

            for (int rowIndex = 0; rowIndex < rowsSize; ++rowIndex) {
                for (int colIndex = 0; colIndex < colsSize; ++colIndex) {

                    Position position = new Position(rowIndex, colIndex);

                    if (visitedPosition(visited, position) || !hasO(board, position)) {
                        continue;
                    }

                    List<Position> iland = new ArrayList<>();
                    visitIland(board, position, visited, iland);

                    ilands.add(iland);
                }
            }

            for (List<Position> iland : ilands) {
                if (isInnerIland(iland, rowsSize, colsSize)) {
                    flipIland(board, iland);
                }
            }
        }

        private void visitIland(
            char[][] board,
            Position pos,
            Set<Position> visited,
            List<Position> iland) {

            int rowsSize = board.length;
            int colsSize = board[0].length;

            if (!inbound(pos, rowsSize, colsSize) || !hasO(board, pos) || visitedPosition(visited, pos)) {
                return;
            }

            iland.add(pos);
            visited.add(pos);

            Position topPosition = new Position(pos.getRowIndex() - 1, pos.getColIndex());
            Position bottomPosition = new Position(pos.getRowIndex() + 1, pos.getColIndex());
            Position leftPosition = new Position(pos.getRowIndex(), pos.getColIndex() - 1);
            Position rightPosition = new Position(pos.getRowIndex(), pos.getColIndex() + 1);

            visitIland(board, topPosition, visited, iland);
            visitIland(board, bottomPosition, visited, iland);
            visitIland(board, leftPosition, visited, iland);
            visitIland(board, rightPosition, visited, iland);
        }

        private void flipIland(
                char[][] board,
                List<Position> iland) {

            for (Position pos : iland) {
                assert(hasO(board, pos));
                setX(board, pos);
            }
        }

        private boolean isInnerIland(List<Position> iland, int rowsSize, int colsSize) {
            for (Position pos : iland) {
                int rowIndex = pos.getRowIndex();
                int colIndex = pos.getColIndex();

                if (rowIndex <= 0 || rowIndex >= rowsSize - 1 || colIndex <= 0 || colIndex >= colsSize - 1) {
                    return false;
                }
            }

            return true;
        }

        private boolean visitedPosition(Set<Position> visited, Position pos) {
            return visited.contains(pos);
        }

        private boolean inbound(Position pos, int rowsSize, int colsSize) {
            int rowIndex = pos.getRowIndex();
            int colIndex = pos.getColIndex();

            return rowIndex >= 0 && rowIndex < rowsSize && colIndex >= 0 && colIndex < colsSize;
        }

        private boolean hasO(char[][] board, Position pos) {
            int rowIndex = pos.getRowIndex();
            int colIndex = pos.getColIndex();

            return board[rowIndex][colIndex] == 'O';
        }

        private boolean hasX(char[][] board, Position pos) {
            int rowIndex = pos.getRowIndex();
            int colIndex = pos.getColIndex();

            return board[rowIndex][colIndex] == 'X';
        }

        private void setO(char[][] board, Position pos) {
            int rowIndex = pos.getRowIndex();
            int colIndex = pos.getColIndex();

            board[rowIndex][colIndex] = 'O';
        }

        private void setX(char[][] board, Position pos) {
            int rowIndex = pos.getRowIndex();
            int colIndex = pos.getColIndex();

            board[rowIndex][colIndex] = 'X';
        }

        private void validateBoard(char[][] board) {
            if (!isRectangleMatrix(board)) {
                throw new IllegalArgumentException("The input board is not a valid rectangle matrix.");
            }
        }

        private boolean isRectangleMatrix(char[][] board) {
            if (board == null) {
                return false;
            }

            int rowsSize = board.length;

            if (rowsSize == 0) {
                return false;
            }

            int colsSize = board[0].length;

            if (colsSize == 0) {
                return false;
            }

            for (int rowIndex = 1; rowIndex < rowsSize; ++rowIndex) {
                int currColSize = board[rowIndex].length;

                if (currColSize != colsSize) {
                    return false;
                }
            }

            return true;
        }
    }
}
