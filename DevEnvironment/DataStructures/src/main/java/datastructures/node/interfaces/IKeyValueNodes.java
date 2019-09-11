package datastructures.node.interfaces;

import base.interfaces.IIterable;
import java.util.List;

/**
 * The IKeyValueNodes interface defines a list of generic key-value nodes.
 */
public interface IKeyValueNodes<TKey extends Comparable<TKey>, TValue> extends IIterable<IKeyValueNode<TKey, TValue>> {
    /**
     * Gets a list of generic nodes.
     */
    List<IKeyValueNode<TKey, TValue>> getNodes();
}
