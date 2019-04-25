package datastructures.tree.core;

import base.core.Conditions;
import base.interfaces.IBuilder;
import datastructures.tree.interfaces.ITreeData;
import datastructures.tree.interfaces.ITreeDataIterator;
import datastructures.tree.interfaces.ITreeNodeData;
import java.util.ArrayList;
import java.util.List;

/**
 * The TreeData class implements a data of a tree.
 */
public final class TreeData<TKey extends Comparable<TKey>, TValue> implements ITreeData<TKey, TValue> {
    private final List<ITreeNodeData<TKey, TValue>> nodesData;

    /**
     * The TreeNode constructor.
     */
    public TreeData(List<ITreeNodeData<TKey, TValue>> nodesData) {
        Conditions.validateNotNull(
            nodesData,
            "The data of nodes of a tree can not be null.");

        this.nodesData = nodesData;
    }

    /**
     * Gets an iterator of a tree.
     */
    @Override
    public ITreeDataIterator<TKey, TValue> getIterator() {
        return new TreeDataIterator<>(this.nodesData);
    }

    /**
     * Gets the data of nodes.
     */
    @Override
    public List<ITreeNodeData<TKey, TValue>> getNodesData() {
        return this.nodesData;
    }

    /**
     * The Builder class implements a builder for creating data of a tree.
     */
    public static final class Builder<TKey extends Comparable<TKey>, TValue> implements IBuilder<ITreeData<TKey, TValue>> {
        private final List<ITreeNodeData<TKey, TValue>> nodesData = new ArrayList<>();

        /**
         * The Builder constructor.
         */
        public Builder() {
        }

        /**
         * Adds a new node data.
         */
        public Builder<TKey, TValue> addNodeData(ITreeNodeData<TKey, TValue> nodeData) {
            Conditions.validateNotNull(
                nodeData,
                "The data of a node of a tree can not be null.");

            this.nodesData.add(nodeData);

            return this;
        }

        /**
         * Adds a new node data by a key and a value.
         */
        public Builder<TKey, TValue> addNodeData(TKey key, TValue value) {
            ITreeNodeData<TKey, TValue> nodeData = new TreeNodeData<>(key, value);
            return this.addNodeData(nodeData);
        }

        /**
         * Builds the data of the tree.
         */
        @Override
        public ITreeData<TKey, TValue> build() {
            ITreeData<TKey, TValue> treeData = new TreeData<>(this.nodesData);
            return treeData;
        }
    }
}
