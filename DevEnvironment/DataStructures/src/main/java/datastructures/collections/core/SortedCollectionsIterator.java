package datastructures.collections.core;

import base.core.Conditions;
import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;
import datastructures.collections.interfaces.ISortedCollectionsIterator;
import datastructures.node.core.KeyValueNode;
import datastructures.node.interfaces.IKeyValueNode;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;
import java.util.PriorityQueue;

/**
 * The SortedCollectionsIterator class implements an iterator of sorted collections.
 * The iterator returns the next element in the input collections based on the defined sorted order.
 */
public final class SortedCollectionsIterator<TKey extends Comparable<TKey>> implements ISortedCollectionsIterator<TKey> {
    private final List<Collection<TKey>> collections;
    private final IBinaryComparator<IKeyValueNode<TKey, Integer>> comparator;
    private List<IIterator<TKey>> collectionsIterators;
    private PriorityQueue<IKeyValueNode<TKey, Integer>> candidates;

    /**
     * Creates a new iterator of a sorted collections.
     */
    public static <TKey extends Comparable<TKey>> ISortedCollectionsIterator<TKey> of(
        List<Collection<TKey>> collections) {

        return new SortedCollectionsIterator<>(collections);
    }

    /**
     * Creates a new iterator of a sorted collections.
     */
    public static <TKey extends Comparable<TKey>> ISortedCollectionsIterator<TKey> of(
        List<Collection<TKey>> collections,
        IBinaryComparator<TKey> keyComparator) {

        return new SortedCollectionsIterator<>(collections, keyComparator);
    }

    /**
     * The SortedCollectionIterator constructor.
     */
    private SortedCollectionsIterator(List<Collection<TKey>> collections) {
        this(collections, base.core.Comparator.defaultComparator());
    }

    /**
     * The SortedCollectionIterator constructor.
     */
    private SortedCollectionsIterator(
        List<Collection<TKey>> collections,
        IBinaryComparator<TKey> keyComparator) {

        Conditions.validateNotNull(
            collections,
            "The collections.");

        Conditions.validateNotNull(
            keyComparator,
            "The key comparator.");

        this.collections = collections;
        this.comparator = new KeyValueNode.Comparator<>(keyComparator);

        this.reset();
    }

    /**
     * Checks whether there is a next element.
     */
    @Override
    public boolean hasNext() {
        return !this.candidates.isEmpty();
    }

    /**
     * Gets the next element.
     */
    @Override
    public TKey next() {
        assert(this.hasNext());

        IKeyValueNode<TKey, Integer> currElement = this.candidates.poll();

        int currCollectionIndex = currElement.getValue();
        IIterator<TKey> currCollectionIterator = this.collectionsIterators.get(currCollectionIndex);

        if (currCollectionIterator.hasNext()) {
            TKey nextElementKey = currCollectionIterator.next();

            IKeyValueNode<TKey, Integer> nextElement = KeyValueNode.of(
                nextElementKey,
                currCollectionIndex);

            this.candidates.offer(nextElement);
        }

        return currElement.getKey();
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.collectionsIterators = new ArrayList<>(this.collections.size());
        this.candidates = new PriorityQueue<>(this.comparator.toComparator());

        for (Collection<TKey> collection : this.collections) {
            this.collectionsIterators.add(CollectionIterator.of(collection));
        }
    }
}
