package base.interfaces;

/**
 * The IBuilder interface defines a builder.
 */
public interface IBuilder<T> {
    /**
     * Builds a new object of type T.
     */
    T build();
}
