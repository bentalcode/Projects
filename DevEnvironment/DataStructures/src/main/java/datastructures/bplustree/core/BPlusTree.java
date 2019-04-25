package datastructures.bplustree.core;

import base.core.Casting;
import base.core.Conditions;
import base.interfaces.ICalculator;
import base.interfaces.INullable;
import datastructures.blocktree.core.BlockTreeLevel;
import datastructures.blocktree.core.BlockTreeLevels;
import datastructures.blocktree.interfaces.IBlockTreeLevel;
import datastructures.blocktree.interfaces.IBlockTreeLevels;
import datastructures.bplustree.interfaces.IBPlusTree;
import datastructures.bplustree.interfaces.IBPlusTreeInnerNode;
import datastructures.bplustree.interfaces.IBPlusTreeLeafNode;
import datastructures.bplustree.interfaces.IBPlusTreeMetrics;
import datastructures.bplustree.interfaces.IBPlusTreeNode;
import datastructures.bplustree.interfaces.IBPlusTreeProperties;
import datastructures.tree.core.KeyIterator;
import datastructures.tree.core.ValueIterator;
import datastructures.tree.interfaces.IKeyIterator;
import datastructures.tree.interfaces.ITreeDataIterator;
import datastructures.tree.interfaces.ITreeMetrics;
import datastructures.tree.interfaces.IValueIterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/**
 * The BPlusTree class implements a B+ tree.
 *
 * There are two classes for each type of node: BPlusTreeInnerNode, BPlusTreeLeafNode,
 * since the structures and behaviours between internal node and external node is different.
 */
public final class BPlusTree<TKey extends Comparable<TKey>, TValue> implements IBPlusTree<TKey, TValue> {
    private final IBPlusTreeProperties<TKey, TValue> properties;
    private IBPlusTreeNode<TKey> root;

    /**
     * The BPlusTree constructor.
     */
    public BPlusTree(IBPlusTreeProperties<TKey, TValue> properties) {
        Conditions.validateNotNull(
            properties,
            "The properties of a B+ tree can not be null.");

        this.properties = properties;
        this.root = new BPlusTreeLeafNode<>(properties.getLeafNodeProperties());
    }

    /**
     * Gets the properties of the B+ tree.
     */
    @Override
    public IBPlusTreeProperties<TKey, TValue> getProperties() {
        return this.properties;
    }

    /**
     * Inserts a new key and it's associated value into a B+ tree.
     */
    @Override
    public void insert(TKey key, TValue value) {
        IBPlusTreeLeafNode<TKey, TValue> leaf = this.findLeafNodeShouldContainKey(key);
        leaf.insert(key, value);

        if (leaf.isOverflow()) {
            IBPlusTreeNode<TKey> node = leaf.processOverflow();

            if (node != null) {
                this.root = node;
            }
        }
    }

    /**
     * Deletes a key and it's associated value from the tree.
     */
    @Override
    public void delete(TKey key) {
        IBPlusTreeLeafNode<TKey, TValue> leaf = this.findLeafNodeShouldContainKey(key);

        if (leaf.delete(key) && leaf.isUnderflow()) {
            IBPlusTreeNode<TKey> node = leaf.processUnderflow();

            if (node != null) {
                this.root = node;
            }
        }
    }

    /**
     * Searches a key value on the tree and return it's associated value.
     */
    @Override
    public TValue search(TKey key) {
        IBPlusTreeLeafNode<TKey, TValue> leaf = this.findLeafNodeShouldContainKey(key);

        int index = leaf.findPosition(key);

        if (index == -1) {
            return null;
        }

        TValue value = leaf.getValue(index);

        return value;
    }

    /**
     * Gets an iterator of keys of a tree.
     */
    public IKeyIterator<TKey> getKeyIterator() {
        return new KeyIterator<>(this.getDataIterator());
    }

    /**
     * Gets an iterator of values of a tree.
     */
    @Override
    public IValueIterator<TValue> getValueIterator() {
        return new ValueIterator<>(this.getDataIterator());
    }

    /**
     * Gets an iterator of data of a tree.
     */
    @Override
    public ITreeDataIterator<TKey, TValue> getDataIterator() {
        return new BPlusTreeDataIterator<>(this.root);
    }

    /**
     * Gets levels of a tree.
     */
    @Override
    public IBlockTreeLevels<TKey, INullable> getTreeLevels() {
        BlockTreeLevels.Builder<TKey, INullable> levelsBuilder = new BlockTreeLevels.Builder<>();

        Queue<IBPlusTreeNode<TKey>> queue = new LinkedList<>();
        queue.offer(Casting.cast(this.root));

        while (!queue.isEmpty()) {

            BlockTreeLevel.Builder<TKey, INullable> currLevelBuilder = new BlockTreeLevel.Builder<>();

            int currLevelSize = queue.size();
            for (int i = 0; i < currLevelSize; ++i) {

                IBPlusTreeNode<TKey> currNode = queue.poll();
                currLevelBuilder.addNode(currNode.getKeys());

                if (currNode.getNodeType() == TreeNodeType.InnerNode) {

                    IBPlusTreeInnerNode<TKey> currInnerNode = Casting.cast(currNode);
                    List<IBPlusTreeNode<TKey>> nextNodes = currInnerNode.getChildren();

                    for (IBPlusTreeNode<TKey> nextNode : nextNodes) {
                        queue.offer(nextNode);
                    }
                }
            }

            IBlockTreeLevel<TKey, INullable> currLevel = currLevelBuilder.build();
            levelsBuilder.addLevel(currLevel);
        }

        return levelsBuilder.build();
    }

    /**
     * Gets metrics of a tree.
     */
    public IBPlusTreeMetrics getMetrics() {
        ICalculator<IBPlusTreeMetrics> metricsCalculator = new BPlusTreeMetricsCalculator<>(
            this.properties,
            this.root);

        return metricsCalculator.calculate();
    }

    /**
     * Searches a leaf node which contains the specified key.
     */
    private IBPlusTreeLeafNode<TKey, TValue> findLeafNodeShouldContainKey(TKey key) {
        IBPlusTreeNode<TKey> node = this.root;

        while (node.getNodeType() == TreeNodeType.InnerNode) {
            int nodeIndex = node.findPosition(key);
            node = ((BPlusTreeInnerNode<TKey>)node).getChild(nodeIndex);
        }

        return Casting.cast(node);
    }
}
