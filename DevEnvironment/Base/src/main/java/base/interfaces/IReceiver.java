package base.interfaces;

/**
 * The IReceiver interface defines a receiver of a dynamic type.
 */
public interface IReceiver<T> {
    /**
     * Receives an element.
     */
    void receive(T element);
}
