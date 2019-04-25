package base.interfaces;

/**
 * The IHashCodeProvider interface defines a provider for an hash code.
 */
public interface IHashCodeProvider<T> {
    /**
     * Gets the hash code of this instance.
     */
    int getHashCode(T obj);
}
