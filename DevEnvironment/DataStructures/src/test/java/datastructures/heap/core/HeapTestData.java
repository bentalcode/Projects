package datastructures.heap.core;

import base.core.ArrayLists;
import datastructures.heap.interfaces.IHeapData;
import datastructures.heap.interfaces.IHeapTestData;
import java.util.List;

/**
 * The HeapTestData class implements data of tests for a heap.
 */
public final class HeapTestData implements IHeapTestData {
    /**
     * The HeapTestData constructor.
     */
    public HeapTestData() {
    }

    /**
     * Gets data of the tests of a heap.
     */
    @Override
    public List<IHeapData<Integer>> getData() {
        IHeapData<Integer> data1 = this.getHeapData1();
        IHeapData<Integer> data2 = this.getHeapData2();
        IHeapData<Integer> data3 = this.getHeapData3();
        IHeapData<Integer> data4 = this.getHeapData4();
        IHeapData<Integer> data5 = this.getHeapData5();

        return ArrayLists.make(
            data1,
            data2,
            data3,
            data4,
            data5);
    }

    /**
     * Gets the data of heap1.
     */
    private IHeapData<Integer> getHeapData1() {
        int capacity = 10;
        Integer[] data = {};

        return new HeapData<>(
            Integer.class,
            capacity,
            base.core.Comparator.defaultComparator(),
            data,
            data);
    }

    /**
     * Gets the data of heap2.
     */
    private IHeapData<Integer> getHeapData2() {
        int capacity = 8;
        Integer[] creationData = {14, 10, 5, 9, 6, 3, 2, 1};
        Integer[] expectedData = {1, 2, 3, 6, 9, 10, 5, 14};

        return new HeapData<>(
            Integer.class,
            capacity,
            base.core.Comparator.defaultComparator(),
            creationData,
            expectedData);
    }

    /**
     * Gets the data of heap3.
     */
    private IHeapData<Integer> getHeapData3() {
        int capacity = 10;
        Integer[] creationData = {14, 6, 5, 9, 1, 3, 2, 10};
        Integer[] expectedData = {1, 5, 2, 10, 9, 6, 3, 14};

        return new HeapData<>(
            Integer.class,
            capacity,
            base.core.Comparator.defaultComparator(),
            creationData,
            expectedData);
    }

    /**
     * Gets the data of heap4.
     */
    private IHeapData<Integer> getHeapData4() {
        int capacity = 10;
        Integer[] creationData = {2, 20, 5, 20, 19, 15, 50, 30};
        Integer[] expectedData = {50, 30, 20, 20, 19, 5, 15, 2};

        return new HeapData<>(
            Integer.class,
            capacity,
            base.core.Comparator.defaultInvertComparator(),
            creationData,
            expectedData);
    }

    /**
     * Gets the data of heap5.
     */
    private IHeapData<Integer> getHeapData5() {
        int capacity = 11;
        Integer[] creationData = {-7, 6, 0, 9, 1, 3, 4, -3, 5, -1};
        Integer[] expectedData = {9, 6, 4, 5, 1, 0, 3, -7, -3, -1};

        return new HeapData<>(
            Integer.class,
            capacity,
            base.core.Comparator.defaultInvertComparator(),
            creationData,
            expectedData);
    }
}
