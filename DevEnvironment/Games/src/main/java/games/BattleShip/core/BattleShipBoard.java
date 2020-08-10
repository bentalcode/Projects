package games.BattleShip.core;

import base.core.ArrayLists;
import base.core.Position;
import base.interfaces.IPosition;
import games.BattleShip.interfaces.IBattleShipBoard;
import games.BattleShip.interfaces.BattleShipShootResultType;
import games.GamesException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Set;

/**
 * The BattleShipBoard class implements a board of bottle ships.
 */
public final class BattleShipBoard implements IBattleShipBoard {
    private final int[][] data;
    private final int rows;
    private final int columns;
    private final List<IPosition> directions;
    private int currShipIndex;
    private final Map<IPosition, BattleShipShootResultType> previousShoots = new HashMap<>();

    private static List<IPosition> defaultDirections = ArrayLists.of(
        Position.of(1, -1), Position.of(1, 0), Position.of(1, 1),
        Position.of(0, -1), Position.of(0, 1),
        Position.of(-1, -1), Position.of(-1, 0), Position.of(-1, 1));

    /**
     * The BattleShipBoard constructor.
     */
    public BattleShipBoard(int rows, int columns) {
        this(rows, columns, defaultDirections);
    }

    /**
     * The BattleShipBoard constructor.
     */
    public BattleShipBoard(int rows, int columns, List<IPosition> directions) {
        validateBoardDimension(rows);
        validateBoardDimension(columns);
        validateBoardDirections(directions);

        this.data = new int[rows][columns];
        this.rows = rows;
        this.columns = columns;
        this.directions = directions;
    }

    /**
     * Gets the board.
     */
    @Override
    public int[][] getBoard() {
        return this.data;
    }

    /**
     * Positions a battle ship.
     */
    @Override
    public void positionBattleShip(List<IPosition> positions) {
        this.validateShipPositions(positions);

        ++this.currShipIndex;

        for (IPosition position : positions) {
            int positionValue = this.getPositionValue(position);

            if (positionValue != 0) {
                String errorMessage = "The position: " + position + " is already used for battle ship: " + positionValue;
                throw new GamesException(errorMessage);
            }

            this.setPositionValue(position, this.currShipIndex);
        }
    }

    /**
     * Shoots a specific position.
     */
    @Override
    public BattleShipShootResultType shoot(IPosition position) {
        if (this.shootHereBefore(position)) {
            String errorMessage = "This position has already been used in this game.";
            throw new GamesException(errorMessage);
        }

        BattleShipShootResultType resultType = this.calculateShootResult(position);
        this.previousShoots.put(position, resultType);

        return resultType;
    }

    /**
     * Checks whether shooting here before.
     */
    @Override
    public boolean shootHereBefore(IPosition position) {
        this.validatePosition(position);
        return this.previousShoots.containsKey(position);
    }

    /**
     * Calculates a position of a shoot.
     */
    private BattleShipShootResultType calculateShootResult(IPosition position) {
        if (this.hit(position)) {
            int shipIndex = this.getPositionValue(position);

            return this.hitEntireShip(shipIndex, position) ? BattleShipShootResultType.Sunk : BattleShipShootResultType.Hit;
        }
        else {
            return BattleShipShootResultType.Miss;
        }
    }

    /**
     * Checks whether there is a hit.
     */
    private boolean hit(IPosition position) {
        return this.getPositionValue(position) > 0;
    }

    /**
     * Checks whether the entire ship is hit.
     */
    private boolean hitEntireShip(int shipIndex, IPosition position) {
        if (shipIndex != this.getPositionValue(position)) {
            return false;
        }

        Queue<IPosition> queue = new LinkedList<>();
        queue.offer(position);

        Set<IPosition> visited = new HashSet<>();

        while (!queue.isEmpty()) {
            IPosition currPosition = queue.poll();
            visited.add(currPosition);

            if (!currPosition.equals(position) ||
                this.previousShoots.get(currPosition) != BattleShipShootResultType.Hit) {
                return false;
            }

            for (IPosition nextPosition : this.getAdjacentPositions(currPosition)) {
                if (visited.contains(nextPosition)) {
                    continue;
                }

                if (shipIndex == this.getPositionValue(nextPosition)) {
                    queue.offer(nextPosition);
                }
            }
        }

        return true;
    }

    /**
     * Checks whether the positions of ship are connected.
     * Ignore positions which are the same.
     */
    private boolean positionsAreConnected(List<IPosition> positions) {
        if (positions.isEmpty()) {
            return true;
        }

        Set<IPosition> inputPositions = new HashSet<>(positions);

        Queue<IPosition> queue = new LinkedList<>();
        queue.offer(positions.get(0));

        Set<IPosition> visited = new HashSet<>();

        while (!queue.isEmpty()) {
            IPosition currPosition = queue.poll();
            visited.add(currPosition);

            if (!inputPositions.remove(currPosition)) {
                return false;
            }

            for (IPosition nextPosition : this.getAdjacentPositions(currPosition)) {
                if (visited.contains(nextPosition)) {
                    continue;
                }

                queue.offer(nextPosition);
            }
        }

        return inputPositions.isEmpty();
    }

    /**
     * Gets the adjacent positions in the board.
     */
    private List<IPosition> getAdjacentPositions(IPosition position) {
        List<IPosition> result = new ArrayList<>();

        for (IPosition direction : this.directions) {
            IPosition nextPosition = Position.add(position, direction);

            if (this.isPositionValid(nextPosition)) {
                result.add(nextPosition);
            }
        }

        return result;
    }

    /**
     * Gets the value of a specific position.
     */
    private int getPositionValue(IPosition position) {
        return this.data[position.getRow()][position.getColumn()];
    }

    /**
     * Sets the value of a specific position.
     */
    private void setPositionValue(IPosition position, int value) {
        this.data[position.getRow()][position.getColumn()] = value;
    }

    /**
     * Validates positions of a ship.
     */
    private void validateShipPositions(List<IPosition> positions) {
        if (positions == null || positions.isEmpty()) {
            String errorMessage = "The positions of a ship are not defined.";
            throw new GamesException(errorMessage);
        }

        for (IPosition position : positions) {
            this.validatePosition(position);
        }

        if (!this.positionsAreConnected(positions)) {
            String errorMessage = "The positions of a ship are not connected.";
            throw new GamesException(errorMessage);
        }
    }

    /**
     * Validates a position.
     */
    private void validatePosition(IPosition position) {
        if (!this.isPositionValid(position)) {
            String errorMessage = "The position is not valid.";
            throw new GamesException(errorMessage);
        }
    }

    /**
     * Checks whether a position is valid.
     */
    private boolean isPositionValid(IPosition position) {
        return
            position != null &&
            this.isRowIndexValid(position.getRow()) &&
            this.isColumnIndexValid(position.getColumn());
    }

    /**
     * Checks whether an index of a row is valid.
     */
    private boolean isRowIndexValid(int row) {
        return row >= 0 && row < this.rows;
    }

    /**
     * Checks whether an index of a column is valid.
     */
    private boolean isColumnIndexValid(int column) {
        return column >= 0 && column < this.columns;
    }

    /**
     * Validates a dimension of a board.
     */
    private static void validateBoardDimension(int dimension) {
        if (dimension <= 0) {
            String errorMessage = "The dimension of a board has to be positive.";
            throw new GamesException(errorMessage);
        }
    }

    /**
     * Validates directions in a board.
     */
    private static void validateBoardDirections(List<IPosition> directions) {
        if (directions == null || !directions.isEmpty()) {
            String errorMessage = "The supported directions in a board are not defined.";
            throw new GamesException(errorMessage);
        }
    }
}
