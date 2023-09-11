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
    public List<IMapData<Integer, String>> getHashMapData() {
        List<IMapData<Integer, String>> data = new ArrayList<>();

        data.add(this.getHashMapData1());
        data.add(this.getHashMapData2());

        return data;
    }

    /**
     * Gets the data of linked hash maps.
     */
    @Override
    public List<IMapData<Integer, String>> getLinkedHashMapData() {
        List<IMapData<Integer, String>> data = new ArrayList<>();

        data.add(this.getLinkedHashMapData1());
        data.add(this.getLinkedHashMapData2());

        return data;
    }

    /**
     * Gets the data of hash map1.
     */
    private IMapData<Integer, String> getHashMapData1() {
        List<IKeyValueNode<Integer, String>> creationData = new ArrayList<>();
        List<IKeyValueNode<Integer, String>> data = new ArrayList<>();
        List<Integer> keys = this.createKeys(data);
        List<String> values = this.createValues(data);

        return new MapData<>(
            creationData,
            data,
            keys,
            values);
    }

    /**
     * Gets the data of hash map2.
     */
    private IMapData<Integer, String> getHashMapData2() {
        List<IKeyValueNode<Integer, String>> creationData = ArrayLists.make(
            KeyValueNode.make(1, "a"),
            KeyValueNode.make(1, "a"),
            KeyValueNode.make(2, "b"),
            KeyValueNode.make(2, "c"),
            KeyValueNode.make(2, "b"),
            KeyValueNode.make(3, "a"),
            KeyValueNode.make(3, "b"),
            KeyValueNode.make(3, "c"));

        List<IKeyValueNode<Integer, String>> data = ArrayLists.make(
            KeyValueNode.make(1, "a"),
            KeyValueNode.make(2, "b"),
            KeyValueNode.make(3, "c"));

        List<Integer> keys = this.createKeys(data);
        List<String> values = this.createValues(data);

        return new MapData<>(
            creationData,
            data,
            keys,
            values);
    }

    /**
     * Gets the data of linked hash map1.
     */
    private IMapData<Integer, String> getLinkedHashMapData1() {
        List<IKeyValueNode<Integer, String>> creationData = new ArrayList<>();
        List<IKeyValueNode<Integer, String>> data = new ArrayList<>();
        List<Integer> keys = this.createKeys(data);
        List<String> values = this.createValues(data);

        return new MapData<>(
            creationData,
            data,
            keys,
            values);
    }

    /**
     * Gets the data of linked hash map2.
     */
    private IMapData<Integer, String> getLinkedHashMapData2() {
        List<IKeyValueNode<Integer, String>> creationData = ArrayLists.make(
            KeyValueNode.make(3, "c"),
            KeyValueNode.make(3, "c"),
            KeyValueNode.make(2, "b"),
            KeyValueNode.make(2, "a"),
            KeyValueNode.make(2, "b"),
            KeyValueNode.make(1, "c"),
            KeyValueNode.make(1, "b"),
            KeyValueNode.make(1, "a"));

        List<IKeyValueNode<Integer, String>> data = ArrayLists.make(
            KeyValueNode.make(3, "c"),
            KeyValueNode.make(2, "b"),
            KeyValueNode.make(1, "a"));

        List<Integer> keys = this.createKeys(data);
        List<String> values = this.createValues(data);

        return new MapData<>(
            creationData,
            data,
            keys,
            values);
    }

    /**
     * Creates the keys of the map.
     */
    private <TKey extends Comparable<TKey>, TValue> List<TKey> createKeys(List<IKeyValueNode<TKey, TValue>> data) {
        List<TKey> keys = new ArrayList<>();

        for (IKeyValueNode<TKey, TValue> node : data) {
            keys.add(node.getKey());
        }

        return keys;
    }

    /**
     * Creates the values of the map.
     */
    private <TKey extends Comparable<TKey>, TValue> List<TValue> createValues(List<IKeyValueNode<TKey, TValue>> data) {
        List<TValue> values = new ArrayList<>();

        for (IKeyValueNode<TKey, TValue> node : data) {
            values.add(node.getValue());
        }

        return values;
    }
}
