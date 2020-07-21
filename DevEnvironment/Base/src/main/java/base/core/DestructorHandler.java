package base.core;

import base.interfaces.IDestructor;
import base.interfaces.IDestructorFactory;
import base.interfaces.IDestructorHandler;
import java.io.Closeable;
import java.util.ArrayList;
import java.util.List;
import base.interfaces.IIterator;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The DestructorHandler class implements a destructor handler for invoking
 * destructors of the registered objects in reverse order.
 */
public final class DestructorHandler implements IDestructorHandler {
    private final IDestructorFactory destructorFactory = new DestructorFactory();
    private final List<IDestructor> destructors;

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The DestructorHandler constructor.
     */
    public DestructorHandler() {
        this(ArrayLists.newList());
    }

    /**
     * The DestructorHandler constructor.
     */
    private DestructorHandler(List<IDestructor> destructors) {
        Conditions.validateNotNull(
            destructors,
            "The list of destructors.");

        this.destructors = destructors;
    }

    /**
     * Moves the destructors to a new destructor.
     */
    public IDestructorHandler move() {
        List<IDestructor> destructors = new ArrayList<>(this.destructors);
        IDestructorHandler destructorHandler = new DestructorHandler(destructors);
        this.destructors.clear();
        return destructorHandler;
    }

    /**
     * Registers an object destructor.
     */
    @Override
    public <T extends Closeable> IDestructor register(T obj) {
        Conditions.validateNotNull(
            obj,
            "The instance of an object for registering for destruction.");

        IDestructor destructor = this.destructorFactory.create(obj);
        this.destructors.add(destructor);

        return destructor;
    }

    /**
     * Closes this resource.
     */
    @Override
    public void close() {
        int numberOfObjectsToDestruct = this.destructors.size();
        int numberOfDestructedObjects = 0;

        IIterator<IDestructor> iterator = new ReverseIterator<>(this.destructors);

        while (iterator.hasNext()) {
            IDestructor currDestructor = iterator.next();

            try {
                currDestructor.destruct();
            }
            catch (Exception e) {
                String errorMessage =
                    "The Destructor Handler failed invoking a destructor of " +
                    ClassTypes.getName(currDestructor) + " due to the following error: " + e.getMessage() +
                    "; Aborting the destruction logic with success ratio of: " +
                    numberOfDestructedObjects + "/" + numberOfObjectsToDestruct;

                this.log.error(errorMessage);
                throw new DestructorException(errorMessage, e);
            }

            ++numberOfDestructedObjects;
        }
    }
}
