package datastructures.stack.interfaces;

import java.util.List;

/**
 * The IStackTestData interface defines the data of the tests of a stack.
 */
public interface IStackTestData {
    /**
     * Gets data of the tests of a stack.
     */
    List<IStackData<Integer>> getData();
}
