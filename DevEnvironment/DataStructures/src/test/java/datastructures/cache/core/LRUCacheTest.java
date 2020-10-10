package datastructures.cache.core;

import base.core.Iterator;
import base.core.ListIterator;
import base.core.ListReverseIterator;
import base.interfaces.IIterator;
import base.interfaces.ITriple;
import datastructures.cache.interfaces.ICache;
import datastructures.core.TestData;
import datastructures.interfaces.ITestData;
import datastructures.node.core.KeyIterator;
import datastructures.node.core.KeyReverseIterator;
import datastructures.node.core.KeyValueNodeIterator;
import datastructures.node.core.KeyValueNodeReverseIterator;
import datastructures.node.core.ValueIterator;
import datastructures.node.core.ValueReverseIterator;
import datastructures.node.interfaces.IKeyValueNode;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.core.IterationTest;
import testbase.interfaces.IAssertion;
import java.util.List;

/**
 * The LRUCacheTest class implements tests for a least recently used cache.
 */
public final class LRUCacheTest {
    private final IAssertion assertion = new Assertion();
    private final ITestData testData = new TestData();

    /**
     * The LRUCacheTest constructor.
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
     * Tests the updation logic of a least recently used cache.
     */
    @Test
    public void lruCacheUpdationTest() {
        ICache<Integer, String> cache = new LRUCache<>(new CacheProperties(3, 1));

        List<ITriple<String, IKeyValueNode<Integer, String>, List<IKeyValueNode<Integer, String>>>> data =
            this.testData.getCacheData().getLruUpdationData();

        this.testUpdation(cache, data);
    }

    /**
     * Tests the iteration logic of a least recently used cache.
     */
    @Test
    public void lruCacheIterationTest() {
        ICache<Integer, String> cache = new LRUCache<>(new CacheProperties(3, 1));

        List<ITriple<String, IKeyValueNode<Integer, String>, List<IKeyValueNode<Integer, String>>>> data =
            this.testData.getCacheData().getLruUpdationData();

        this.testIteration(cache, data);
    }

    /**
     * Tests the updation logic of a cache.
     */
    private <TKey extends Comparable<TKey>, TValue> void testUpdation(
        ICache<TKey, TValue> cache,
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
        ICache<TKey, TValue> cache,
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
        ICache<TKey, TValue> cache,
        String operation,
        IKeyValueNode<TKey, TValue> item,
        List<IKeyValueNode<TKey, TValue>> expectedContent) {

        this.updateCache(cache, operation, item);

        this.assertion.assertEqualsWithIterators(
            cache.getIterator(),
            Iterator.make(expectedContent),
            "Invalid updation logic of a cache.");
    }

    /**
     * Tests the iteration logic of a cache.
     */
    private <TKey extends Comparable<TKey>, TValue extends Comparable<TValue>> void testIteration(
        ICache<TKey, TValue> cache,
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
        IterationTest iterationTest = new IterationTest();
        iterationTest.testIteration(
            cache,
            ListIterator.make(expectedContent),
            "LRUCache");

        //
        // Test the forward iteration over nodes...
        //
        iterationTest.testForwardIteration(
            cache,
            ListIterator.make(expectedContent),
            "LRUCache");

        //
        // Test the reverse iteration over nodes...
        //
        iterationTest.testReverseIteration(
            cache,
            ListReverseIterator.make(expectedContent),
            "LRUCache");

        //
        // Test the forward iteration over keys...
        //
        iterationTest.testKeyIteration(
            cache,
            KeyIterator.make(KeyValueNodeIterator.make(expectedContent)),
            "LRUCache");

        //
        // Test the reverse iteration over keys...
        //
        iterationTest.testKeyReverseIteration(
            cache,
            KeyReverseIterator.make(KeyValueNodeReverseIterator.make(expectedContent)),
            "LRUCache");

        //
        // Test the forward iteration over values...
        //
        iterationTest.testValueIteration(
            cache,
            ValueIterator.make(KeyValueNodeIterator.make(expectedContent)),
            "LRUCache");

        //
        // Test the reverse iteration over values...
        //
        iterationTest.testValueReverseIteration(
            cache,
            ValueReverseIterator.make(KeyValueNodeReverseIterator.make(expectedContent)),
            "LRUCache");
    }

    /**
     * Updates the cache.
     */
    private <TKey extends Comparable<TKey>, TValue> void updateCache(
        ICache<TKey, TValue> cache,
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
