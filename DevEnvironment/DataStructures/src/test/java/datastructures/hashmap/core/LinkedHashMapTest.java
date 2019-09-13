package datastructures.hashmap.core;

import base.core.ListIterator;
import base.core.Lists;
import datastructures.collections.core.CollectionEquatableComparator;
import datastructures.collections.interfaces.ICollectionEquatableComparator;
import datastructures.core.TestData;
import datastructures.hashmap.interfaces.ILinkedHashMap;
import datastructures.hashmap.interfaces.ILinkedHashMapBuilder;
import datastructures.hashmap.interfaces.IMapData;
import datastructures.interfaces.ITestData;
import datastructures.node.interfaces.IKeyValueNode;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import java.util.List;

/**
 * The LinkedHashMapTest class implements tests for a linked hash map.
 */
public final class LinkedHashMapTest {
    private final ITestData testData = new TestData();
    private final ICollectionEquatableComparator comparator = new CollectionEquatableComparator();
    private final IAssertion assertion = new Assertion();

    /**
     * The LinkedHashMapTest constructor.
     */
    public LinkedHashMapTest() {
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
     * Tests the creation logic of a linked hash map.
     */
    @Test
    public void LinkedHashMapCreationTest() {
        for (IMapData<Integer, String> mapData : this.testData.getHashMapData().getLinkedHashMapData()) {
            this.testCreation(
                mapData.getCreationData(),
                mapData.getData());
        }
    }

    /**
     * Tests the creation logic of a linked hash map.
     */
    @Test
    public void LinkedHashMapCreationWithDeletionTest() {
        for (IMapData<Integer, String> mapData : this.testData.getHashMapData().getLinkedHashMapData()) {
            this.testCreationWithDeletion(
                mapData.getCreationData(),
                mapData.getData());
        }
    }

    /**
     * Tests the creation logic of a linked hash.
     */
    private <TKey extends Comparable<TKey>, TValue extends Comparable<TValue>> void testCreation(
        List<IKeyValueNode<TKey, TValue>> creationData,
        List<IKeyValueNode<TKey, TValue>> data) {

        ILinkedHashMapBuilder<TKey, TValue> mapBuilder = new LinkedHashMapBuilder<>();
        mapBuilder.set(ListIterator.of(creationData));
        ILinkedHashMap<TKey, TValue> map = mapBuilder.build();

        this.assertion.assertTrue(
            this.comparator.isEqual(map, data),
            "Invalid creation logic of a linked hash map.");
    }

    /**
     * Tests the creation with deletion logic of a hash-map.
     */
    private <TKey extends Comparable<TKey>, TValue extends Comparable<TValue>> void testCreationWithDeletion(
        List<IKeyValueNode<TKey, TValue>> creationData,
        List<IKeyValueNode<TKey, TValue>> data) {

        ILinkedHashMapBuilder<TKey, TValue> mapBuilder = new LinkedHashMapBuilder<>();
        mapBuilder.set(ListIterator.of(creationData));
        ILinkedHashMap<TKey, TValue> map = mapBuilder.build();

        this.assertion.assertTrue(
            this.comparator.isEqual(map, data),
            "Invalid creation logic of a linked hash map.");

        List<IKeyValueNode<TKey, TValue>> keyValueNodes = Lists.fromIterator(map.getIterator());
        int currSize = map.size();

        for (IKeyValueNode<TKey, TValue> nodeToRemove : keyValueNodes) {
            IKeyValueNode<TKey, TValue> removedNode = map.remove(nodeToRemove.getKey());
            --currSize;

            this.assertion.assertTrue(
                !map.containsKey(nodeToRemove.getKey()),
                "Invalid remove logic of linked hash map: key was not removed.");

            this.assertion.assertEquals(
                removedNode,
                nodeToRemove,
                "Invalid remove logic of linked hash map: invalid removed key-value node.");

            this.assertion.assertTrue(
                map.size() == currSize,
                "Invalid remove logic of linked hash map: invalid size.");
        }
    }
}
