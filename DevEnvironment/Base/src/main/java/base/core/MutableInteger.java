package base.core;

/**
 * The MutableInteger class implements an integer which is mutable.
 */
public class MutableInteger {
    private int value;

    /**
     * The MutableInteger constructor.
     */
    public MutableInteger(int value) {
        this.value = value;
    }

    /**
     * Sets the value of an integer.
     */
    public void set(int value) {
        this.value = value;
    }

    /**
     * Gets the value of an integer.
     */
    public int get() {
        return this.value;
    }
}