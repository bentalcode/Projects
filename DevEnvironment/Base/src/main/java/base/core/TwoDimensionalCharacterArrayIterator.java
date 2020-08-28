package base.core;

import base.interfaces.IIterator;

/**
 * The TwoDimensionalCharacterArrayIterator class implements an iterator
 * of a two dimensional array of characters.
 */
public final class TwoDimensionalCharacterArrayIterator implements IIterator<Character> {
    private final char[][] data;
    private final int rowsSize;
    private int rowIndex;
    private int columnIndex;

    /**
     * Creates a new iterator of a two dimensional array of characters.
     */
    public static IIterator<Character> make(char[][] data) {
        return new TwoDimensionalCharacterArrayIterator(data);
    }

    /**
     * The TwoDimensionalCharacterArrayIterator constructor.
     */
    private TwoDimensionalCharacterArrayIterator(char[][] data) {
        Conditions.validateNotNull(
            data,
            "The array to iterate.");

        this.data = data;
        this.rowsSize = data.length;

        this.reset();
    }

    /**
     * Checks whether there is a next element.
     */
    @Override
    public boolean hasNext() {
        return this.rowIndex < this.rowsSize && this.columnIndex < this.columnSize(this.rowIndex);
    }

    /**
     * Gets the next element.
     */
    @Override
    public Character next() {
        assert(this.hasNext());

        char currElement = this.get(this.rowIndex, this.columnIndex);

        this.moveNext();

        return currElement;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.rowIndex = 0;
        this.columnIndex = 0;
    }

    /**
     * Moves to the next element.
     */
    private void moveNext() {
        if (this.columnIndex < this.columnSize(this.rowIndex) - 1) {
            ++this.columnIndex;
        }
        else {
            this.columnIndex = 0;
            ++this.rowIndex;
        }
    }

    /**
     * Gets the column size of a specific row.
     */
    private int columnSize(int rowIndex) {
        return this.data[rowIndex].length;
    }

    /**
     * Gets a value of a specific position.
     */
    private char get(int rowIndex, int columnIndex) {
        assert(rowIndex >= 0 && rowIndex < this.rowsSize);
        assert(columnIndex >= 0 && columnIndex < this.data[rowIndex].length);

        return this.data[rowIndex][columnIndex];
    }
}