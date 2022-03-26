package datastructures.cache.core;

import base.core.Iterator;
import base.interfaces.IIterator;
import base.interfaces.ITriple;
import datastructures.cache.interfaces.ICache;
import datastructures.core.TestData;
import datastructures.interfaces.ITestData;
import datastructures.node.interfaces.IKeyValueNode;
import java.util.List;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;

/**
 * The CacheTest class implements tests for a cache.
 */
public final class CacheTest {
    private final IAssertion assertion = new Assertion();
    private final ITestData testData = new TestData();

    /**
     * The CacheTest constructor.
     */
    public CacheTest() {
    }

    /**
     * Tests the updation logic of a most recently used cache.
     */
    @Test
    public void mruCacheUpdationTest() {
        ICache<Integer, String> cache = new MRUCache<>(new CacheProperties(3, 1));

        List<ITriple<String, IKeyValueNode<Integer, String>, List<IKeyValueNode<Integer, String>>>> data =
            this.testData.getCacheData().getMruUpdationData();

        this.testUpdation(cache, data);
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
     * Tests the iteration logic of a most recently used cache.
     */
    @Test
    public void mruCacheIterationTest() {
        ICache<Integer, String> cache = new MRUCache<>(new CacheProperties(3, 1));

        List<ITriple<String, IKeyValueNode<Integer, String>, List<IKeyValueNode<Integer, String>>>> data =
            this.testData.getCacheData().getMruUpdationData();

        this.testIteration(cache, data);
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
        int index = 0;

        for (IKeyValueNode<TKey, TValue> node : cache) {
            this.assertion.assertEquals(
                node,
                expectedContent.get(index),
                "Incorrect logic of default forward iterator over nodes.");

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
                "Incorrect logic of forward iterator over nodes.");

            ++index;
        }

        //
        // Test the forward iteration over keys...
        //
        IIterator<TKey> keyIterator = cache.getKeyIterator();
        index = 0;

        while (keyIterator.hasNext()) {
            TKey key = keyIterator.next();

            this.assertion.assertEquals(
                key,
                expectedContent.get(index).getKey(),
                "Incorrect logic of forward iterator over keys.");

            ++index;
        }

        //
        // Test the forward iteration over values...
        //
        IIterator<TValue> valueIterator = cache.getValueIterator();
        index = 0;

        while (valueIterator.hasNext()) {
            TValue value = valueIterator.next();

            this.assertion.assertEquals(
                value,
                expectedContent.get(index).getValue(),
                "Incorrect logic of forward iterator over values.");

            ++index;
        }
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
