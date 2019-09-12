package datastructures.hashmap.core;

import base.core.ArrayLists;
import datastructures.hashmap.interfaces.IHashMapTestData;
import datastructures.hashmap.interfaces.IMapData;
import datastructures.node.core.KeyValueNode;
import datastructures.node.interfaces.IKeyValueNode;
import java.util.ArrayList;
import java.util.List;

/**
 * The HashMapTestData class implements data of tests for a hash map.
 */
public final class HashMapTestData implements IHashMapTestData {
    /**
     * The HashMapTestData constructor.
     */
    public HashMapTestData() {
    }

    /**
     * Gets the data of hash maps.
     */
    @Override
    public List<IMapData<Integer, String>> getData() {
        List<IMapData<Integer, String>> data = new ArrayList<>();

        data.add(this.getData1());
        data.add(this.getData2());

        return data;
    }

    /**
     * Gets the data of hash map1.
     */
    private IMapData<Integer, String> getData1() {
        List<IKeyValueNode<Integer, String>> creationData = new ArrayList<>();
        List<IKeyValueNode<Integer, String>> data = new ArrayList<>();

        return new MapData<>(creationData, data);
    }

    /**
     * Gets the data of hash map1.
     */
    private IMapData<Integer, String> getData2() {
        List<IKeyValueNode<Integer, String>> creationData = ArrayLists.of(
            KeyValueNode.of(1, "a"),
            KeyValueNode.of(1, "a"),
            KeyValueNode.of(2, "b"),
            KeyValueNode.of(2, "c"),
            KeyValueNode.of(2, "b"),
            KeyValueNode.of(3, "a"),
            KeyValueNode.of(3, "b"),
            KeyValueNode.of(3, "c"));

        List<IKeyValueNode<Integer, String>> data = ArrayLists.of(
            KeyValueNode.of(1, "a"),
            KeyValueNode.of(2, "b"),
            KeyValueNode.of(3, "c"));

        return new MapData<>(creationData, data);
    }
}
