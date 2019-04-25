package base.core;

import base.interfaces.IDestructor;
import base.interfaces.IDestructorFactory;
import base.interfaces.IDestructorHandler;
import java.io.Closeable;
import java.util.ArrayList;
import java.util.List;

/**
 * The DestructorHandler class implements a destructor handler for invoking
 * destructors of the registered objects in reverse order.
 */
public final class DestructorHandler implements IDestructorHandler {
    private final IDestructorFactory destructorFactory = new DestructorFactory();
    private final List<IDestructor> destructors = new ArrayList<>();
    /**
     * The DestructorHandler constructor.
     */
    public DestructorHandler() {
    }

    /**
     * Registers an object destructor.
     */
    @Override
    public <T extends Closeable> IDestructor register(T obj) {
        Conditions.validateNotNull(
            obj,
            "The instance of an object for registering for destruction can not be null.");

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

        ReverseIterator<IDestructor> iterator = new ReverseIterator<>(this.destructors);

        while (iterator.hasNext()) {
            IDestructor currDestructor = iterator.next();

            try {
                currDestructor.destruct();
            }
            catch (Exception e) {
                String errorMessage =
                    "The Destructor Handler failed invoking a destructor of " +
                    currDestructor.getClass().getSimpleName() + " due to the following error: " + e.getMessage() +
                    "; Aborting the destruction logic with success ratio of: " +
                    numberOfDestructedObjects + "/" + numberOfObjectsToDestruct;

                throw new DestructorException(errorMessage);
            }

            ++numberOfDestructedObjects;
        }
    }
}
