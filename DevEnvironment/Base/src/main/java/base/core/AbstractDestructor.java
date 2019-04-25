package base.core;

import base.interfaces.IDestructor;
import java.io.Closeable;
import java.io.IOException;

/**
 * The AbstractDestructor base class implements an abstract destructor.
 */
public abstract class AbstractDestructor<T extends Closeable> implements IDestructor {
    private final T obj;
    private boolean toDestruct = true;

    /**
     * The CloseableDestructor constructor.
     */
    public AbstractDestructor(T obj) {
        Conditions.validateNotNull(
            obj,
            "The instance of an object for closing can not be null.");

        this.obj = obj;
    }

    /**
     * Destructs an instance of an object.
     */
    protected void destructObject() {
        if (!this.toDestruct) {
            return;
        }

        try {
            this.obj.close();
        }
        catch (IOException e) {
            String errorMessage =
                "The object: " + this.obj.getClass().getSimpleName() + " failed to get closed " +
                " due to the following error: " + e.getMessage();

            throw new BaseException(errorMessage);
        }
    }

    /**
     * Detaches the destructor logic.
     */
    public void detach() {
        this.toDestruct = false;
    }
}
