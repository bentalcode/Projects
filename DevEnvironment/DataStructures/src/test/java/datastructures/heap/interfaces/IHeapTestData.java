package datastructures.heap.interfaces;

import java.util.List;

/**
 * The IHeapTestData interface defines the data of the tests of a heap.
 */
public interface IHeapTestData {
    /**
     * Gets data of the tests of a heap.
     */
    List<IHeapData<Integer>> getData();
}
