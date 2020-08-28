package datastructures.hashmap.core;

import base.core.Conditions;
import base.interfaces.IReverseIterator;
import datastructures.collections.core.ReverseIteratorOfReverseIteratorCollection;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedList;
import datastructures.node.interfaces.IKeyValueNode;
import java.util.List;

/**
 * The HashMapInternalReverseIterator class implements an internal reverse iterator of a hash map.
 */
public final class HashMapInternalReverseIterator<TKey extends Comparable<TKey>, TValue> implements
    IReverseIterator<IKeyValueNode<TKey, TValue>> {

    private final List<IDoublyLinkedList<IKeyValueNode<TKey, TValue>>> header;
    private IReverseIterator<IKeyValueNode<TKey, TValue>> reverseIterator;

    /**
     * Creates a new reverse iterator for a hash map.
     */
    public static <TKey extends Comparable<TKey>, TValue> IReverseIterator<IKeyValueNode<TKey, TValue>> make(
        List<IDoublyLinkedList<IKeyValueNode<TKey, TValue>>> header) {

        return new HashMapInternalReverseIterator<>(header);
    }

    /**
     * The HashMapInternalReverseIterator constructor.
     */
    private HashMapInternalReverseIterator(List<IDoublyLinkedList<IKeyValueNode<TKey, TValue>>> header) {
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
        return this.reverseIterator.hasNext();
    }

    /**
     * Gets the next element.
     */
    @Override
    public IKeyValueNode<TKey, TValue> next() {
        assert(this.hasNext());

        return this.reverseIterator.next();
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        ReverseIteratorOfReverseIteratorCollection.Builder<IKeyValueNode<TKey, TValue>> reverseIteratorBuilder =
            new ReverseIteratorOfReverseIteratorCollection.Builder<>();

        for (int i = this.header.size() - 1; i >= 0; --i) {
            IDoublyLinkedList<IKeyValueNode<TKey, TValue>> currList = this.header.get(i);

            if (currList == null) {
                continue;
            }

            IReverseIterator<IKeyValueNode<TKey, TValue>> entryReverseIterator = currList.getValueReverseIterator();
            reverseIteratorBuilder.addReverseIterator(entryReverseIterator);
        }

        this.reverseIterator = reverseIteratorBuilder.build();
    }
}
