package datastructures.hashmap.core;

import base.core.Conditions;
import base.core.IteratorOfIteratorCollection;
import base.interfaces.IIterator;
import base.interfaces.IIteratorOfIteratorCollection;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedList;
import datastructures.node.interfaces.IKeyValueNode;
import java.util.List;

/**
 * The HashMapInternalIterator class implements an internal iterator of a hash map.
 */
public final class HashMapInternalIterator<TKey extends Comparable<TKey>, TValue> implements IIterator<IKeyValueNode<TKey, TValue>> {
    private final List<IDoublyLinkedList<IKeyValueNode<TKey, TValue>>> header;
    private IIteratorOfIteratorCollection<IKeyValueNode<TKey, TValue>> iterator;

    /**
     * Creates a new internal iterator for a hash map.
     */
    public static <TKey extends Comparable<TKey>, TValue> IIterator<IKeyValueNode<TKey, TValue>> of(
        List<IDoublyLinkedList<IKeyValueNode<TKey, TValue>>> header) {

        return new HashMapInternalIterator<>(header);
    }

    /**
     * The HashMapInternalIterator constructor.
     */
    private HashMapInternalIterator(List<IDoublyLinkedList<IKeyValueNode<TKey, TValue>>> header) {
        Conditions.validateNotNull(
            header,
            "The header of a hash map.");

        this.header = header;

        this.reset();
    }

    /**
     * Checks whether there is a next element.
     */
    @Override
    public boolean hasNext() {
        return this.iterator.hasNext();
    }

    /**
     * Gets the next element.
     */
    @Override
    public IKeyValueNode<TKey, TValue> next() {
        assert(this.hasNext());

        return this.iterator.next();
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        IteratorOfIteratorCollection.Builder<IKeyValueNode<TKey, TValue>> iteratorBuilder =
            new IteratorOfIteratorCollection.Builder<>();

        for (IDoublyLinkedList<IKeyValueNode<TKey, TValue>> currList : this.header) {

            if (currList == null) {
                continue;
            }

            IIterator<IKeyValueNode<TKey, TValue>> entryIterator = currList.getValueIterator();
            iteratorBuilder.addIterator(entryIterator);
        }

        this.iterator = iteratorBuilder.build();
    }
}
