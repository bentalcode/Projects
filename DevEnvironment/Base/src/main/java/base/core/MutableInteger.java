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
     * Increments the value of an integer.
     */
    public int increment() {
        ++this.value;
        return this.value;
    }

    /**
     * Decrements the value of an integer.
     */
    public int decrement() {
        --this.value;
        return this.value;
    }

    /**
     * Gets the value of an integer.
     */
    public int get() {
        return this.value;
    }

    /**
     * Gets the string representation of this instance.
     */
    public String toString() {
        return String.valueOf(this.value);
    }
}