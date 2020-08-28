package datastructures.linkedlist.core;

import base.core.ArrayLists;
import base.core.RandomGenerator;
import base.core.Triple;
import base.interfaces.IRandomGenerator;
import base.interfaces.ITriple;
import datastructures.linkedlist.interfaces.ILinkedListData;
import datastructures.linkedlist.interfaces.ILinkedListNode;
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
    public List<ILinkedListData<Integer>> getData() {
        List<ILinkedListData<Integer>> data = new ArrayList<>();

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

        data.add(Triple.make("addToFront", 1, ArrayLists.make(1)));
        data.add(Triple.make("addToFront", 2, ArrayLists.make(2, 1)));
        data.add(Triple.make("addToFront", 3, ArrayLists.make(3, 2, 1)));
        data.add(Triple.make("removeFromFront", null, ArrayLists.make(2, 1)));
        data.add(Triple.make("removeFromFront", null, ArrayLists.make(1)));
        data.add(Triple.make("addToBack", 2, ArrayLists.make(1, 2)));
        data.add(Triple.make("addToBack", 3, ArrayLists.make(1, 2, 3)));
        data.add(Triple.make("addToBack", 4, ArrayLists.make(1, 2, 3, 4)));
        data.add(Triple.make("addToBack", 5, ArrayLists.make(1, 2, 3, 4, 5)));
        data.add(Triple.make("removeAfter", null, ArrayLists.make(1, 3, 4, 5)));
        data.add(Triple.make("removeAfter", null, ArrayLists.make(1, 4, 5)));
        data.add(Triple.make("removeAfter", null, ArrayLists.make(1, 5)));
        data.add(Triple.make("removeAfter", null, ArrayLists.make(1)));
        data.add(Triple.make("removeFromFront", null, new ArrayList<>()));

        return data;
    }

    /**
     * Gets the data of list1.
     */
    private ILinkedListData<Integer> getListData1() {
        List<Integer> creationData = this.getData(0);
        List<ILinkedListNode<Integer>> data = this.createData(creationData);
        List<Integer> values = creationData;

        return new LinkedListData<>(
            creationData,
            data,
            values);
    }

    /**
     * Gets the data of list2.
     */
    private ILinkedListData<Integer> getListData2() {
        List<Integer> creationData = this.getData(50);
        List<ILinkedListNode<Integer>> data = this.createData(creationData);
        List<Integer> values = creationData;

        return new LinkedListData<>(
            creationData,
            data,
            values);
    }

    /**
     * Gets the data of list3.
     */
    private ILinkedListData<Integer> getListData3() {
        List<Integer> creationData = this.getData(100);
        List<ILinkedListNode<Integer>> data = this.createData(creationData);
        List<Integer> values = creationData;

        return new LinkedListData<>(
            creationData,
            data,
            values);
    }

    /**
     * Gets the random data of list.
     */
    private ILinkedListData<Integer> getRandomListData(int fromSize, int toSize) {
        int size = this.randomGenerator.nextInteger(fromSize, toSize);
        List<Integer> creationData = this.getData(size);
        List<ILinkedListNode<Integer>> data = this.createData(creationData);
        List<Integer> values = creationData;

        return new LinkedListData<>(
            creationData,
            data,
            values);
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
     * Creates the data of the list.
     */
    private <TValue extends Comparable<TValue>> List<ILinkedListNode<TValue>> createData(List<TValue> values) {
        List<ILinkedListNode<TValue>> data = new ArrayList<>();

        for (TValue value : values) {
            data.add(LinkedListNode.make(value));
        }

        return data;
    }
}
