package base.core;

import base.interfaces.IDestructor;
import base.interfaces.IDestructorFactory;
import java.io.Closeable;

/**
 * The DestructorFactory class implements a factory for creating destructors.
 */
public final class DestructorFactory implements IDestructorFactory {
    /**
     * The DestructorFactory constructor.
     */
    public DestructorFactory() {
    }

    /**
     * Creates a closeable destructor.
     */
    @Override
    public <T extends Closeable> IDestructor create(T obj) {
        return new CloseableDestructor<>(obj);
    }

    /**
     * The CloseableDestructor destructor.
     */
    private static final class CloseableDestructor<T extends Closeable> extends AbstractDestructor<T> {

        /**
         * The CloseableDestructor constructor.
         */
        public CloseableDestructor(T obj) {
            super(obj);
        }

        /**
         * Destructs an instance of an object.
         */
        @Override
        public void destruct() {
            this.destructObject();
        }
    }
}
