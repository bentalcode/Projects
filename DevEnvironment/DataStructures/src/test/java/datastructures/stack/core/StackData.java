package datastructures.stack.core;

import datastructures.stack.interfaces.IStackData;
import java.util.List;

/**
 * The StackData class implements the data of a stack.
 */
public final class StackData<T extends Comparable<T>> implements IStackData<T> {
    private final Class<T> classType;
    private final List<T> creationData;
    private final List<T> data;

    /**
     * The StackData constructor.
     */
    public StackData(
        Class<T> classType,
        List<T> creationData,
        List<T> data) {

        this.classType = classType;
        this.creationData = creationData;
        this.data = data;
    }

    /**
     * Gets the class type.
     */
    @Override
    public Class<T> getClassType() {
        return this.classType;
    }

    /**
     * Gets the creation data.
     */
    @Override
    public List<T> getCreationData() {
        return this.creationData;
    }

    /**
     * Gets the actual data of the stack.
     */
    @Override
    public List<T> getData() {
        return this.data;
    }
}
