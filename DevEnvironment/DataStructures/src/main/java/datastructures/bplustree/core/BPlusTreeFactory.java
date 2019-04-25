package datastructures.bplustree.core;

import base.core.Conditions;
import datastructures.bplustree.interfaces.IBPlusTree;
import datastructures.bplustree.interfaces.IBPlusTreeFactory;
import datastructures.bplustree.interfaces.IBPlusTreeProperties;
import datastructures.tree.interfaces.ITreeData;
import datastructures.tree.interfaces.ITreeNodeData;

/**
 * The BPlusTreeFactory class implements a factory for creating B+ trees.
 */
public final class BPlusTreeFactory<TKey extends Comparable<TKey>, TValue> implements IBPlusTreeFactory<TKey, TValue> {
    private IBPlusTreeProperties<TKey, TValue> properties;

    /**
     * The BPlusTree constructor.
     */
    public BPlusTreeFactory(IBPlusTreeProperties<TKey, TValue> properties) {
        Conditions.validateNotNull(
            properties,
            "The properties of a B+ tree can not be null.");

        this.properties = properties;
    }

    /**
     * Creates a new B+ tree.
     */
    @Override
    public IBPlusTree<TKey, TValue> create(ITreeData<TKey, TValue> treeData) {
        return this.create(this.properties, treeData);
    }

    /**
     * Creates a new B+ tree.
     */
    @Override
    public IBPlusTree<TKey, TValue> create(
        IBPlusTreeProperties<TKey, TValue> properties,
        ITreeData<TKey, TValue> treeData) {

        Conditions.validateNotNull(
            properties,
            "The properties of a B+ tree can not be null.");

        Conditions.validateNotNull(
            treeData,
            "The data of a B+ tree can not be null.");

        IBPlusTree<TKey, TValue> tree = new BPlusTree<>(this.properties);

        for (ITreeNodeData<TKey, TValue> nodeData : treeData.getNodesData()) {
            tree.insert(nodeData.getKey(), nodeData.getValue());
        }

        return tree;
    }
}
