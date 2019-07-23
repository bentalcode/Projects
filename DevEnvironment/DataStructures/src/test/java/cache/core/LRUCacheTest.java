package cache.core;

import base.core.Pair;
import datastructures.cache.core.CacheProperties;
import datastructures.cache.core.LRUCache;
import datastructures.collections.interfaces.IKeyIterator;
import datastructures.plustree.core.TestData;
import json.interfaces.ITestData;
import org.junit.After;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;
import java.util.List;
import java.util.ListIterator;

/**
 * The LRUCacheTest class implements tests for a least recently used cache.
 */
public final class LRUCacheTest {
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
     * Tests the set logic of a cache.
     */
    @Test
    public void LRUCacheTest() {
        LRUCache<Integer, String> cache = new LRUCache<>(new CacheProperties(3));

        List<Pair<Integer, List<Integer>>> data = this.testData.getLRUSetData();
        this.testLRUCache(cache, data);
    }

    /**
     * Tests the least recently used cache.
     */
    private <TKey extends Comparable<TKey>, TValue> void testLRUCache(
        LRUCache<TKey, TValue> cache,
        List<Pair<TKey, List<TKey>>> data) {

        for (Pair<TKey, List<TKey>> entry : data) {
            this.testSet(cache, entry.first(), entry.second());
        }
    }

    /**
     * Tests the insertion logic of a LRU cache.
     */
    private <TKey extends Comparable<TKey>, TValue> void testSet(
        LRUCache<TKey, TValue> cache,
        TKey itemToAdd,
        List<TKey> expectedContent) {

        cache.set(itemToAdd, null);

        this.validateContent(cache, expectedContent);
    }


    private <TKey extends Comparable<TKey>, TValue> void validateContent(
        LRUCache<TKey, TValue> cache,
        List<TKey> expectedContent) {

        IKeyIterator<TKey> actualKeyIterator = cache.getKeyIterator();
        ListIterator<TKey> expectedKeyIterator = expectedContent.listIterator();

        while (actualKeyIterator.hasNext() && expectedKeyIterator.hasNext()) {
            TKey actualKey = actualKeyIterator.next();
            TKey expectedKey = expectedKeyIterator.next();

            Assert.assertEquals(actualKey, expectedKey);
        }

        Assert.assertTrue(
            "Invalid content in LRU Cache after set.",
            !actualKeyIterator.hasNext() && !expectedKeyIterator.hasNext());
    }
}
