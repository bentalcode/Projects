package base.interfaces;

import java.io.Closeable;

/**
 * The IDestructorFactory interface defines a factory for creating destructors.
 */
public interface IDestructorFactory {
    /**
     * Creates a destructor.
     */
    <T extends Closeable> IDestructor create(T obj);
}
