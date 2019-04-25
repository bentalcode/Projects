package base.interfaces;

import java.io.Closeable;

/**
 * The ICloseable interface defines a closeable.
 */
public interface ICloseable extends Closeable {
    /**
     * Closes this resource gracefully.
     */
    void close();
}
