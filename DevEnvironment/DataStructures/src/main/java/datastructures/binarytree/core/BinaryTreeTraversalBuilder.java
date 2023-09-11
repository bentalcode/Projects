package datastructures.binarytree.core;

import base.interfaces.IBuilder;
import base.interfaces.IPair;
import datastructures.binarytree.BinaryTreeException;
import datastructures.binarytree.interfaces.IBinaryTree;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * The BinaryTreeTraversalBuilder abstract base class implements a builder of a binary tree
 * from various traversal.
 */
public abstract class BinaryTreeTraversalBuilder<TKey extends Comparable<TKey>, TValue> implements
    IBuilder<IBinaryTree<TKey, TValue>> {

    /**
     * The BinaryTreeTraversalBuilder constructor.
     */
    protected BinaryTreeTraversalBuilder() {
    }

    /**
     * Creates an index map.
     */
    protected static <TKey extends Comparable<TKey>, TValue> Map<TKey, Integer> createIndexMap(
        List<IPair<TKey, TValue>> data) {

        Map<TKey, Integer> result = new HashMap<>();

        for (int index = 0; index < data.size(); ++index) {
            TKey key = data.get(index).first();

            result.put(key, index);
        }

        return result;
    }

    /**
     * Gets an index of a node by a key.
     */
    protected static <TKey extends Comparable<TKey>> int getNodeIndex(
        Map<TKey, Integer> indexMap,
        TKey key)
    {
        if (!indexMap.containsKey(key)) {
            String errorMessage =
                "The index of node with key: " + key +
                " was not found in the index map.";

            throw new BinaryTreeException(errorMessage);
        }

        return indexMap.get(key);
    }
}
