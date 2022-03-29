package datastructures.cache.core;

import datastructures.cache.interfaces.ICacheProperties;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;
import datastructures.node.interfaces.IKeyValueNode;

/**
 * The LRUCache class implements a most recently used cache.
 * Discards the least recently used items first.
 */
public final class LRUCache<TKey extends Comparable<TKey>, TValue> extends AbstractCache<TKey, TValue> {
    /**
     * The LRUCache constructor.
     */
    public LRUCache(ICacheProperties properties) {
        super(
            properties,
            AbstractCache.defaultComparator());
    }

    /**
     * Makes available space for the specified number of items.
     */
    @Override
    protected void makeAvailableSpace(CacheData<TKey, TValue> cacheData, int numberOfItems) {
        for (int i = 0; i < numberOfItems; ++i) {
            IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>> itemToRemove = cacheData.usedList().removeFromFront();
            assert itemToRemove != null;
            cacheData.dataLookup().remove(itemToRemove.getValue().getKey());
        }
    }
}
