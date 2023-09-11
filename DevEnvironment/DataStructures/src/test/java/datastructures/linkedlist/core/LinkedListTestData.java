package datastructures.linkedlist.core;

import base.core.ArrayLists;
import base.core.Triple;
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

        data.add(this.getListData(0));
        data.add(this.getListData(50));
        data.add(this.getListData(100));

        return data;
    }

    /**
     * Gets the update data of a linked list.
     */
    @Override
    public List<ITriple<String, Integer, List<Integer>>> getUpdateData() {
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
     * Gets the data of list.
     */
    private ILinkedListData<Integer> getListData(int size) {
        List<Integer> values = this.createListValues(size);
        List<ILinkedListNode<Integer>> nodes = this.createListNodes(values);

        return new LinkedListData<>(
            values,
            nodes);
    }

    /**
     * Creates values of a list.
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
     * Creates nodes of a list.
     */
    private <TValue extends Comparable<TValue>> List<ILinkedListNode<TValue>> createListNodes(List<TValue> values) {
        List<ILinkedListNode<TValue>> result = new ArrayList<>(values.size());

        for (TValue value : values) {
            result.add(LinkedListNode.make(value));
        }

        return result;
    }
}
