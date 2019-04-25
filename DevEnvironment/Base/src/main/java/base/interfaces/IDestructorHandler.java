package base.interfaces;

import java.io.Closeable;

/**
 * The IDestructorHandler interface defines a destructor handler for invoking
 * destructors of the registered objects in reverse order.
 */
public interface IDestructorHandler extends ICloseable {
    /**
     * Registers an object destructor.
     */
    <T extends Closeable> IDestructor register(T obj);
}
