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

        data.add(Triple.make("addToFront", 1, ArrayLists.make(1)));
        data.add(Triple.make("addToFront", 2, ArrayLists.make(2, 1)));
        data.add(Triple.make("addToFront", 3, ArrayLists.make(3, 2, 1)));
        data.add(Triple.make("removeFromFront", null, ArrayLists.make(2, 1)));
        data.add(Triple.make("removeFromFront", null, ArrayLists.make(1)));
        data.add(Triple.make("addToBack", 2, ArrayLists.make(1, 2)));
        data.add(Triple.make("addToBack", 3, ArrayLists.make(1, 2, 3)));
        data.add(Triple.make("addToBack", 4, ArrayLists.make(1, 2, 3, 4)));
        data.add(Triple.make("addToBack", 5, ArrayLists.make(1, 2, 3, 4, 5)));
        data.add(Triple.make("removeFromBack", null, ArrayLists.make(1, 2, 3, 4)));
        data.add(Triple.make("removeFromBack", null, ArrayLists.make(1, 2, 3)));

        return data;
    }

    /**
     * Gets the data of list1.
     */
    private IDoublyLinkedListData<Integer> getListData1() {
        List<Integer> values = this.createListValues(0);
        List<IDoublyLinkedListNode<Integer>> nodes = this.createListNodes(values);

        return new DoublyLinkedListData<>(
            values,
            nodes);
    }

    /**
     * Gets the data of list2.
     */
    private IDoublyLinkedListData<Integer> getListData2() {
        List<Integer> values = this.createListValues(50);
        List<IDoublyLinkedListNode<Integer>> nodes = this.createListNodes(values);

        return new DoublyLinkedListData<>(
            values,
            nodes);
    }

    /**
     * Gets the data of list3.
     */
    private IDoublyLinkedListData<Integer> getListData3() {
        List<Integer> values = this.createListValues(100);
        List<IDoublyLinkedListNode<Integer>> nodes = this.createListNodes(values);

        return new DoublyLinkedListData<>(
            values,
            nodes);
    }

    /**
     * Gets the random data of list.
     */
    private IDoublyLinkedListData<Integer> getRandomListData(int fromSize, int toSize) {
        int size = this.randomGenerator.nextInteger(fromSize, toSize);
        List<Integer> values = this.createListValues(size);
        List<IDoublyLinkedListNode<Integer>> nodes = this.createListNodes(values);

        return new DoublyLinkedListData<>(
            values,
            nodes);
    }

    /**
     * Creates values of a doubly linked list.
     */
    private List<Integer> createListValues(int size) {
        List<Integer> result = new ArrayList<>();

        for (int i = 0; i < size; ++i) {
            int value = i + 1;
            result.add(value);
        }

        return result;
    }

    /**
     * Creates nodes of a doubly linked list.
     */
    private <TValue extends Comparable<TValue>> List<IDoublyLinkedListNode<TValue>> createListNodes(List<TValue> values) {
        List<IDoublyLinkedListNode<TValue>> result = new ArrayList<>(values.size());

        for (TValue value : values) {
            result.add(DoublyLinkedListNode.make(value));
        }

        return result;
    }
}
