package datastructures.linkedlist.core;

import base.core.ArrayLists;
import base.core.RandomGenerator;
import base.core.Triple;
import base.interfaces.IRandomGenerator;
import base.interfaces.ITriple;
import datastructures.linkedlist.interfaces.IListData;
import datastructures.linkedlist.interfaces.ILinkedListTestData;
import java.util.ArrayList;
import java.util.List;

/**
 * The LinkedListTestData class implements data of tests of a linked list.
 */
public final class LinkedListTestData implements ILinkedListTestData {
    private static int RandomCollectionsSize = 10;
    private static int RandomMinCollectionSize = 100;
    private static int RandomMaxCollectionSize = 1000;

    private final IRandomGenerator randomGenerator = new RandomGenerator();

    /**
     * The LinkedListTestData constructor.
     */
    public LinkedListTestData() {
    }

    /**
     * Gets the data of linked lists.
     */
    @Override
    public List<IListData<Integer>> getData() {
        List<IListData<Integer>> data = new ArrayList<>();

        data.add(this.getListData1());
        data.add(this.getListData2());
        data.add(this.getListData3());

        for (int i = 0; i < RandomCollectionsSize; ++i) {
            data.add(this.getRandomListData(RandomMinCollectionSize, RandomMaxCollectionSize));
        }

        return data;
    }

    /**
     * Gets the updation data of a linked list.
     */
    @Override
    public List<ITriple<String, Integer, List<Integer>>> getUpdationData() {
        List<ITriple<String, Integer, List<Integer>>> data = new ArrayList<>();

        data.add(Triple.of("addToFront", 1, ArrayLists.of(1)));
        data.add(Triple.of("addToFront", 2, ArrayLists.of(2, 1)));
        data.add(Triple.of("addToFront", 3, ArrayLists.of(3, 2, 1)));
        data.add(Triple.of("removeFromFront", null, ArrayLists.of(2, 1)));
        data.add(Triple.of("removeFromFront", null, ArrayLists.of(1)));
        data.add(Triple.of("addToBack", 2, ArrayLists.of(1, 2)));
        data.add(Triple.of("addToBack", 3, ArrayLists.of(1, 2, 3)));
        data.add(Triple.of("addToBack", 4, ArrayLists.of(1, 2, 3, 4)));
        data.add(Triple.of("addToBack", 5, ArrayLists.of(1, 2, 3, 4, 5)));
        data.add(Triple.of("removeAfter", null, ArrayLists.of(1, 3, 4, 5)));
        data.add(Triple.of("removeAfter", null, ArrayLists.of(1, 4, 5)));
        data.add(Triple.of("removeAfter", null, ArrayLists.of(1, 5)));
        data.add(Triple.of("removeAfter", null, ArrayLists.of(1)));
        data.add(Triple.of("removeFromFront", null, new ArrayList<>()));

        return data;
    }

    /**
     * Gets the data of list1.
     */
    private IListData<Integer> getListData1() {
        List<Integer> creationData = this.getData(0);
        List<Integer> data = creationData;

        return new ListData<>(creationData, data);
    }

    /**
     * Gets the data of list2.
     */
    private IListData<Integer> getListData2() {
        List<Integer> creationData = this.getData(50);
        List<Integer> data = creationData;

        return new ListData<>(creationData, data);
    }

    /**
     * Gets the data of list3.
     */
    private IListData<Integer> getListData3() {
        List<Integer> creationData = this.getData(100);
        List<Integer> data = creationData;

        return new ListData<>(creationData, data);
    }

    /**
     * Gets the data of a linked list.
     */
    private List<Integer> getData(int size) {
        List<Integer> result = new ArrayList<>();

        for (int i = 0; i < size; ++i) {
            int value = i + 1;
            result.add(value);
        }

        return result;
    }

    /**
     * Gets the random data of list.
     */
    private IListData<Integer> getRandomListData(int fromSize, int toSize) {
        int size = this.randomGenerator.nextInteger(fromSize, toSize);
        List<Integer> data = this.getData(size);

        return new ListData<>(
            data,
            data);
    }
}
