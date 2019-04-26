package datastructures.bplustree.core;

import base.core.Casting;
import base.core.Conditions;
import base.interfaces.ICalculator;
import base.interfaces.IPrimitiveSize;
import datastructures.bplustree.interfaces.IBPlusTreeInnerNode;
import datastructures.bplustree.interfaces.IBPlusTreeMetrics;
import datastructures.bplustree.interfaces.IBPlusTreeNode;
import datastructures.bplustree.interfaces.IBPlusTreeProperties;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/**
 * The BPlusTreeMetricsCalculator class implements a calculator of metrics of a tree.
 */
public final class BPlusTreeMetricsCalculator<TKey extends Comparable<TKey>, TValue> implements ICalculator<IBPlusTreeMetrics> {
    private final IBPlusTreeProperties<TKey, TValue> properties;
    private final IBPlusTreeNode<TKey> root;

    /**
     * The BPlusTreeMetricsCalculator constructor.
     */
    public BPlusTreeMetricsCalculator(
        IBPlusTreeProperties<TKey, TValue> properties,
        IBPlusTreeNode<TKey> root) {

        Conditions.validateNotNull(
            properties,
            "The properties of a B+ tree can not be null.");

        Conditions.validateNotNull(
            root,
            "The root of a B+ tree can not be null.");

        this.properties = properties;
        this.root = root;
    }

    /**
     * Gets the height of a tree.
     */
    @Override
    public IBPlusTreeMetrics calculate() {
        return this.calculateMetrics(this.properties, this.root);
    }

    /**
     * Calculates metrics of a B+ tree.
     */
    private IBPlusTreeMetrics calculateMetrics(
        IBPlusTreeProperties<TKey, TValue> properties,
        IBPlusTreeNode<TKey> root) {

        int height = 0;
        int numberOfInnerNodes = 0;
        int numberOfLeafNodes = 0;
        int sizeInBytes = 0;

        Queue<IBPlusTreeNode<TKey>> queue = new LinkedList<>();
        queue.offer(Casting.cast(root));

        while (!queue.isEmpty()) {

            int levelSize = queue.size();

            for (int i = 0; i < levelSize; ++i) {
                IBPlusTreeNode<TKey> currNode = queue.poll();

                if (currNode.getNodeType() == TreeNodeType.InnerNode) {

                    IBPlusTreeInnerNode<TKey> currInnerNode = Casting.cast(currNode);
                    List<IBPlusTreeNode<TKey>> nextNodes = currInnerNode.getChildren();

                    for (IBPlusTreeNode<TKey> nextNode : nextNodes) {
                        queue.offer(nextNode);
                    }

                    ++numberOfInnerNodes;
                }
                else {
                    ++numberOfLeafNodes;
                }

                ++height;
                sizeInBytes += currNode.getSizeInBytes();
            }
        }

        int numberOfNodes = numberOfInnerNodes + numberOfLeafNodes;

        int innerNodeCapacity = this.calculateInnerNodeCapacity(properties) * numberOfInnerNodes;
        int leafNodeCapacity = this.calculateLeafNodeCapacity(properties) * numberOfLeafNodes;

        int capacityInBytes = innerNodeCapacity + leafNodeCapacity;

        return new BPlusTreeMetrics(
            height,
            numberOfNodes,
            numberOfInnerNodes,
            numberOfLeafNodes,
            sizeInBytes,
            capacityInBytes);
    }

    /**
     * Calculates a capacity of an inner node.
     */
    private int calculateInnerNodeCapacity(IBPlusTreeProperties<TKey, TValue> properties) {
        int keysCapacity = properties.getDegree() * properties.getInnerNodeProperties().getKeySizeInBytes();
        int childrenCapacity = (properties.getDegree() + 1) * IPrimitiveSize.InBytes.ReferenceSize;

        int capacity = keysCapacity + childrenCapacity;

        return capacity;
    }

    /**
     * Calculates a capacity of a leaf node.
     */
    private int calculateLeafNodeCapacity(IBPlusTreeProperties<TKey, TValue> properties) {
        int keysCapacity = properties.getDegree() * properties.getInnerNodeProperties().getKeySizeInBytes();
        int valueCapacity = (properties.getDegree()) * properties.getLeafNodeProperties().getValueSizeInBytes();

        int capacity = keysCapacity + valueCapacity;

        return capacity;
    }
}
