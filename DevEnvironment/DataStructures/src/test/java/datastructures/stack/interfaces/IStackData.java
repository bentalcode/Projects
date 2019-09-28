package datastructures.stack.interfaces;

import java.util.List;

/**
 * The IStackData interface defines the data of a stack.
 */
public interface IStackData<T extends Comparable<T>> {
    /**
     * Gets the class type.
     */
    Class<T> getClassType();

    /**
     * Gets the creation data.
     */
    List<T> getCreationData();

    /**
     * Gets the actual data of the stack.
     */
    List<T> getData();
}
