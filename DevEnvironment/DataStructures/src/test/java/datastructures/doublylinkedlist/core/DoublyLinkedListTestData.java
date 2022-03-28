package datastructures.doublylinkedlist.core;

import base.core.ArrayLists;
import base.core.Triple;
import base.interfaces.ITriple;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListTestData;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListData;
import java.util.ArrayList;
import java.util.List;
import testbase.core.CollectionValues;

/**
 * The DoublyLinkedListTestData class implements data of tests of a doubly linked list.
 */
public final class DoublyLinkedListTestData implements IDoublyLinkedListTestData {
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

        data.add(this.getListData(0));
        data.add(this.getListData(50));
        data.add(this.getListData(100));

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
     * Gets the data of list.
     */
    private IDoublyLinkedListData<Integer> getListData(int size) {
        List<Integer> values = CollectionValues.createListValues(size);
        List<IDoublyLinkedListNode<Integer>> nodes = createListNodes(values);

        return new DoublyLinkedListData<>(
            values,
            nodes);
    }

    /**
     * Creates nodes of a doubly linked list.
     */
    private static <TValue extends Comparable<TValue>> List<IDoublyLinkedListNode<TValue>> createListNodes(List<TValue> values) {
        List<IDoublyLinkedListNode<TValue>> result = new ArrayList<>(values.size());

        for (TValue value : values) {
            result.add(DoublyLinkedListNode.make(value));
        }

        return result;
    }
}
