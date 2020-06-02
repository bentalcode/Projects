package datastructures.doublylinkedlist.core;

import base.core.ArrayLists;
import base.core.RandomGenerator;
import base.core.Triple;
import base.interfaces.IRandomGenerator;
import base.interfaces.ITriple;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListTestData;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListData;
import java.util.ArrayList;
import java.util.List;

/**
 * The DoublyLinkedListTestData class implements data of tests of a doubly linked list.
 */
public final class DoublyLinkedListTestData implements IDoublyLinkedListTestData {
    private static int randomCollectionsSize = 10;
    private static int randomMinCollectionSize = 100;
    private static int randomMaxCollectionSize = 1000;

    private final IRandomGenerator randomGenerator = new RandomGenerator();

    /**
     * The DoublyLinkedListTestData constructor.
     */
    public DoublyLinkedListTestData() {
    }

    /**
     * Gets the data of doubly linked lists.
     */
    @Override
    public List<IDoublyLinkedListData<Integer>> getData() {
        List<IDoublyLinkedListData<Integer>> data = new ArrayList<>();

        data.add(this.getListData1());
        data.add(this.getListData2());
        data.add(this.getListData3());

        for (int i = 0; i < randomCollectionsSize; ++i) {
            data.add(this.getRandomListData(randomMinCollectionSize, randomMaxCollectionSize));
        }

        return data;
    }

    /**
     * Gets the updation data of a doubly linked list.
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
        data.add(Triple.of("removeFromBack", null, ArrayLists.of(1, 2, 3, 4)));
        data.add(Triple.of("removeFromBack", null, ArrayLists.of(1, 2, 3)));

        return data;
    }

    /**
     * Gets the data of list1.
     */
    private IDoublyLinkedListData<Integer> getListData1() {
        List<Integer> creationData = this.getData(0);
        List<IDoublyLinkedListNode<Integer>> data = this.createData(creationData);
        List<Integer> values = creationData;

        return new DoublyLinkedListData<>(
            creationData,
            data,
            values);
    }

    /**
     * Gets the data of list2.
     */
    private IDoublyLinkedListData<Integer> getListData2() {
        List<Integer> creationData = this.getData(50);
        List<IDoublyLinkedListNode<Integer>> data = this.createData(creationData);
        List<Integer> values = creationData;

        return new DoublyLinkedListData<>(
            creationData,
            data,
            values);
    }

    /**
     * Gets the data of list3.
     */
    private IDoublyLinkedListData<Integer> getListData3() {
        List<Integer> creationData = this.getData(100);
        List<IDoublyLinkedListNode<Integer>> data = this.createData(creationData);
        List<Integer> values = creationData;

        return new DoublyLinkedListData<>(
            creationData,
            data,
            values);
    }

    /**
     * Gets the random data of list.
     */
    private IDoublyLinkedListData<Integer> getRandomListData(int fromSize, int toSize) {
        int size = this.randomGenerator.nextInteger(fromSize, toSize);
        List<Integer> creationData = this.getData(size);
        List<IDoublyLinkedListNode<Integer>> data = this.createData(creationData);
        List<Integer> values = creationData;

        return new DoublyLinkedListData<>(
            creationData,
            data,
            values);
    }

    /**
     * Gets the data of a doubly linked list.
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
    private <TValue extends Comparable<TValue>> List<IDoublyLinkedListNode<TValue>> createData(List<TValue> values) {
        List<IDoublyLinkedListNode<TValue>> data = new ArrayList<>();

        for (TValue value : values) {
            data.add(DoublyLinkedListNode.of(value));
        }

        return data;
    }
}
