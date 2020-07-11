package base.interfaces;

/**
 * The IProvider interface defines a provider of a dynamic type.
 */
public interface IProvider<T> {
    /**
    * Gets the dynamic type.
    */
    T get();
}
