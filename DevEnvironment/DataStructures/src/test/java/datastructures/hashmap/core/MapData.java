package datastructures.hashmap.core;

import datastructures.hashmap.interfaces.IMapData;
import datastructures.node.interfaces.IKeyValueNode;
import java.util.List;

/**
 * The MapData class implements the data of a map.
 */
public final class MapData<TKey extends Comparable<TKey>, TValue> implements IMapData<TKey, TValue> {
    private final List<IKeyValueNode<TKey, TValue>> creationData;
    private final List<IKeyValueNode<TKey, TValue>> data;

    /**
     * The MapData constructor.
     */
    public MapData(
        List<IKeyValueNode<TKey, TValue>> creationData,
        List<IKeyValueNode<TKey, TValue>> data) {

        this.creationData = creationData;
        this.data = data;
    }

    /**
     * Gets the creation data.
     */
    @Override
    public List<IKeyValueNode<TKey, TValue>> getCreationData() {
        return this.creationData;
    }

    /**
     * Gets the actual data of the map.
     */
    @Override
    public List<IKeyValueNode<TKey, TValue>> getData() {
        return this.data;
    }
}
