package base.interfaces;

/**
 * The Position interface defines a 2D position.
 */
public interface IPosition extends IUnaryComparator<IPosition> {
    /**
     * Gets the index of a row.
     */
    int getRow();

    /**
     * Gets the index of a column.
     */
    int getColumn();

    /**
     * Sets the index of a row.
     */
    void setRow(int row);

    /**
     * Sets the index of a column.
     */
    void setColumn(int col);

    /**
     * Moves left.
     */
    void moveLeft();

    /**
     * Moves right.
     */
    void moveRight();

    /**
     * Moves up.
     */
    void moveUp();

    /**
     * Moves down.
     */
    void moveDown();

    /**
     * Adds to a position.
     */
    IPosition add(IPosition position);

    /**
     * Subtracts from a position.
     */
    IPosition subtract(IPosition position);

    /**
     * Adds to a position.
     */
    IPosition add(int xSize, int ySize);

    /**
     * Subtracts from a position.
     */
    IPosition subtract(int xSize, int ySize);
}
