package datastructures.hashmap.interfaces;

import datastructures.node.interfaces.IKeyValueNode;
import java.util.List;

/**
 * The IMapData interface defines the data of a map.
 */
public interface IMapData<TKey extends Comparable<TKey>, TValue> {
    /**
     * Gets the creation data.
     */
    List<IKeyValueNode<TKey, TValue>> getCreationData();

    /**
     * Gets the actual data of the map.
     */
    List<IKeyValueNode<TKey, TValue>> getData();
}
