package base.core;

import base.BaseException;
import base.interfaces.IDestructor;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.io.Closeable;
import java.io.IOException;

/**
 * The AbstractDestructor base class implements an abstract destructor.
 */
public abstract class AbstractDestructor<T extends Closeable> implements IDestructor {
    private final T obj;
    private boolean toDestruct = true;

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The CloseableDestructor constructor.
     */
    public AbstractDestructor(T obj) {
        Conditions.validateNotNull(
            obj,
            "The instance of an object for closing.");

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
                "The object: " + ClassTypes.getName(this.obj) + " failed to get closed " +
                " due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
            throw new BaseException(errorMessage, e);
        }
    }

    /**
     * Detaches the destructor logic.
     */
    public void detach() {
        this.toDestruct = false;
    }
}
