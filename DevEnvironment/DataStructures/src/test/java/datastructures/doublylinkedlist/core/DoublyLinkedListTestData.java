package datastructures.doublylinkedlist.core;

import base.core.ArrayLists;
import base.core.Triple;
import base.interfaces.ITriple;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListTestData;
import java.util.ArrayList;
import java.util.List;

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
     * Gets the updation data.
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
}
