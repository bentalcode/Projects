package base.interfaces;

/**
 * The IGenerator interface defines a generator of a dynamic type.
 */
public interface IGenerator<T> {
    /**
     * Generate a new object.
     */
    T generate();
}
