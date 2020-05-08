package datastructures.priorityqueue.core;

import base.core.ArrayLists;
import datastructures.priorityqueue.interfaces.IPriorityQueueData;
import datastructures.priorityqueue.interfaces.IPriorityQueueTestData;
import java.util.ArrayList;
import java.util.List;

/**
 * The PriorityQueueTestData class implements data of tests for a priority queue.
 */
public final class PriorityQueueTestData implements IPriorityQueueTestData {
    /**
     * The PriorityQueueTestData constructor.
     */
    public PriorityQueueTestData() {
    }

    /**
     * Gets data of the tests of a priority queue.
     */
    @Override
    public List<IPriorityQueueData<Integer>> getData() {
        IPriorityQueueData<Integer> data1 = this.getPriorityQueueData1();
        IPriorityQueueData<Integer> data2 = this.getPriorityQueueData2();
        IPriorityQueueData<Integer> data3 = this.getPriorityQueueData3();
        IPriorityQueueData<Integer> data4 = this.getPriorityQueueData4();
        IPriorityQueueData<Integer> data5 = this.getPriorityQueueData5();

        return ArrayLists.of(
            data1,
            data2,
            data3,
            data4,
            data5);
    }

    /**
     * Gets the data of priority queue1.
     */
    private IPriorityQueueData<Integer> getPriorityQueueData1() {
        List<Integer> data = new ArrayList<>();

        return new PriorityQueueData<>(
            Integer.class,
            base.core.Comparator.defaultComparator(),
            data,
            data);
    }

    /**
     * Gets the data of priority queue2.
     */
    private IPriorityQueueData<Integer> getPriorityQueueData2() {
        List<Integer> creationData = ArrayLists.of(14, 10, 5, 9, 6, 3, 2, 1);
        List<Integer> expectedData = ArrayLists.of(1, 2, 3, 6, 9, 10, 5, 14);

        return new PriorityQueueData<>(
            Integer.class,
            base.core.Comparator.defaultComparator(),
            creationData,
            expectedData);
    }

    /**
     * Gets the data of priority queue3.
     */
    private IPriorityQueueData<Integer> getPriorityQueueData3() {
        List<Integer> creationData = ArrayLists.of(14, 6, 5, 9, 1, 3, 2, 10);
        List<Integer> expectedData = ArrayLists.of(1, 5, 2, 10, 9, 6, 3, 14);

        return new PriorityQueueData<>(
            Integer.class,
            base.core.Comparator.defaultComparator(),
            creationData,
            expectedData);
    }

    /**
     * Gets the data of priority queue4.
     */
    private IPriorityQueueData<Integer> getPriorityQueueData4() {
        List<Integer> creationData = ArrayLists.of(2, 20, 5, 20, 19, 15, 50, 30);
        List<Integer> expectedData = ArrayLists.of(50, 30, 20, 20, 19, 5, 15, 2);

        return new PriorityQueueData<>(
            Integer.class,
            base.core.Comparator.defaultInvertComparator(),
            creationData,
            expectedData);
    }

    /**
     * Gets the data of priority queue5.
     */
    private IPriorityQueueData<Integer> getPriorityQueueData5() {
        List<Integer> creationData = ArrayLists.of(-7, 6, 0, 9, 1, 3, 4, -3, 5, -1);
        List<Integer> expectedData = ArrayLists.of(9, 6, 4, 5, 1, 0, 3, -7, -3, -1);

        return new PriorityQueueData<>(
            Integer.class,
            base.core.Comparator.defaultInvertComparator(),
            creationData,
            expectedData);
    }
}
