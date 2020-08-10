package games.BattleShip.interfaces;

import base.interfaces.IPosition;

import java.util.List;

/**
 * The IBattleShipBoard interface defines a board of bottle ships.
 */
public interface IBattleShipBoard {
    /**
     * Gets the board.
     */
    int[][] getBoard();

    /**
     * Positions a battle ship.
     */
    void positionBattleShip(List<IPosition> positions);

    /**
     * Shoots a specific position.
     */
    BattleShipShootResultType shoot(IPosition position);

    /**
     * Returns whether shooting here before.
     */
    boolean shootHereBefore(IPosition position);
}
