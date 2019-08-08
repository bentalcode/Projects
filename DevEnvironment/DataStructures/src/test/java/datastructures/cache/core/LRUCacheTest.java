package datastructures.cache.core;

import base.core.Iterator;
import base.interfaces.IIterator;
import base.interfaces.ITriple;
import datastructures.cache.interfaces.ILRUCache;
import datastructures.collections.interfaces.IKeyIterator;
import datastructures.collections.interfaces.IValueIterator;
import datastructures.core.TestData;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;
import datastructures.interfaces.ITestData;
import datastructures.node.interfaces.IKeyValueNode;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import java.util.List;

/**
 * The LRUCacheTest class implements tests for a least recently used cache.
 */
public final class LRUCacheTest {
    private final IAssertion assertion = new Assertion();
    private final ITestData testData = new TestData();

    /**
     * The BPlusTreeTest constructor.
     */
    public LRUCacheTest() {
    }

    /**
     * Initialize the tests.
     */
    @Before
    public void setUp() {
    }

    /**
     * Un-Initializes the tests.
     */
    @After
    public void tearDown() {
    }

    /**
     * Tests the updation logic of a cache.
     */
    @Test
    public void LRUCacheUpdationTest() {
        ILRUCache<Integer, String> cache = new LRUCache<>(new CacheProperties(3));

        List<ITriple<String, IKeyValueNode<Integer, String>, List<IKeyValueNode<Integer, String>>>> data =
            this.testData.getCacheData().getUpdationData();

        this.testUpdation(cache, data);
    }

    /**
     * Tests the iteration logic of a cache.
     */
    @Test
    public void LRUCacheIterationTest() {
        ILRUCache<Integer, String> cache = new LRUCache<>(new CacheProperties(3));

        List<ITriple<String, IKeyValueNode<Integer, String>, List<IKeyValueNode<Integer, String>>>> data =
            this.testData.getCacheData().getUpdationData();

        this.testIteration(cache, data);
    }

    /**
     * Tests the updation logic of a cache.
     */
    private <TKey extends Comparable<TKey>, TValue> void testUpdation(
        ILRUCache<TKey, TValue> cache,
        List<ITriple<String, IKeyValueNode<TKey, TValue>, List<IKeyValueNode<TKey, TValue>>>> data) {

        for (ITriple<String, IKeyValueNode<TKey, TValue>, List<IKeyValueNode<TKey, TValue>>> entry : data) {
            this.testUpdation(
                cache,
                entry.first(),
                entry.second(),
                entry.third());
        }
    }

    /**
     * Tests the iteration logic of a cache.
     */
    private <TKey extends Comparable<TKey>, TValue extends Comparable<TValue>> void testIteration(
        ILRUCache<TKey, TValue> cache,
        List<ITriple<String, IKeyValueNode<TKey, TValue>, List<IKeyValueNode<TKey, TValue>>>> data) {

        for (ITriple<String, IKeyValueNode<TKey, TValue>, List<IKeyValueNode<TKey, TValue>>> entry : data) {
            this.testIteration(
                cache,
                entry.first(),
                entry.second(),
                entry.third());
        }
    }

    /**
     * Tests the updation logic of a cache.
     */
    private <TKey extends Comparable<TKey>, TValue> void testUpdation(
        ILRUCache<TKey, TValue> cache,
        String operation,
        IKeyValueNode<TKey, TValue> item,
        List<IKeyValueNode<TKey, TValue>> expectedContent) {

        this.updateCache(cache, operation, item);

        this.assertion.assertEquals(
            cache.getIterator(),
            Iterator.of(expectedContent),
            "Invalid updation logic of a cache.");
    }

    /**
     * Tests the iteration logic of a cache.
     */
    private <TKey extends Comparable<TKey>, TValue extends Comparable<TValue>> void testIteration(
        ILRUCache<TKey, TValue> cache,
        String operation,
        IKeyValueNode<TKey, TValue> item,
        List<IKeyValueNode<TKey, TValue>> expectedContent) {

        //
        // Update the cache with the data...
        //
        this.updateCache(cache, operation, item);

        //
        // Test the default iterator of the container...
        //
        int index = 0;

        for (IKeyValueNode<TKey, TValue> node : cache) {
            this.assertion.assertEquals(
                node,
                expectedContent.get(index),
                "Invalid logic of default forward iterator over nodes.");

            ++index;
        }

        //
        // Test the forward iteration over nodes...
        //
        IIterator<IKeyValueNode<TKey, TValue>> iterator = cache.getIterator();
        index = 0;

        while (iterator.hasNext()) {
            IKeyValueNode<TKey, TValue> node = iterator.next();

            this.assertion.assertEquals(
                node,
                expectedContent.get(index),
                "Invalid logic of forward iterator over nodes.");

            ++index;
        }

        //
        // Test the forward iteration over keys...
        //
        IKeyIterator<TKey> keyIterator = cache.getKeyIterator();
        index = 0;

        while (keyIterator.hasNext()) {
            TKey key = keyIterator.next();

            this.assertion.assertEquals(
                key,
                expectedContent.get(index).getKey(),
                "Invalid logic of forward iterator over keys.");

            ++index;
        }

        //
        // Test the forward iteration over values...
        //
        IValueIterator<TValue> valueIterator = cache.getValueIterator();
        index = 0;

        while (valueIterator.hasNext()) {
            TValue value = valueIterator.next();

            this.assertion.assertEquals(
                value,
                expectedContent.get(index).getValue(),
                "Invalid logic of forward iterator over values.");

            ++index;
        }
    }

    /**
     * Updates the cache.
     */
    private <TKey extends Comparable<TKey>, TValue> void updateCache(
        ILRUCache<TKey, TValue> cache,
        String operation,
        IKeyValueNode<TKey, TValue> item) {

        if (operation.equalsIgnoreCase("set")) {
            cache.set(item.getKey(), item.getValue());
        }
        else if (operation.equalsIgnoreCase("get")) {
            cache.get(item.getKey());
        }
        else if (operation.equalsIgnoreCase("delete")) {
            cache.delete(item.getKey());
        }
    }
}
