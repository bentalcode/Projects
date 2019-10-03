package datastructures.hashmap.interfaces;

import datastructures.node.interfaces.IKeyValueNode;
import java.util.List;

/**
 * The IMapData interface defines the data of a map.
 */
public interface IMapData<TKey extends Comparable<TKey>, TValue> {
    /**
     * Gets the creation data of the map.
     */
    List<IKeyValueNode<TKey, TValue>> getCreationData();

    /**
     * Gets the actual data of the map.
     */
    List<IKeyValueNode<TKey, TValue>> getData();

    /**
     * Gets the actual keys of the map.
     */
    List<TKey> getKeys();

    /**
     * Gets the actual values of the map.
     */
    List<TValue> getValues();
}
