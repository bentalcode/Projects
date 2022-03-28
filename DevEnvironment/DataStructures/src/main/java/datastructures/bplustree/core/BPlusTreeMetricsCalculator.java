package datastructures.bplustree.core;

import base.core.Casting;
import base.core.Conditions;
import base.interfaces.ICalculator;
import base.interfaces.IPrimitiveSize;
import datastructures.bplustree.interfaces.IBPlusTreeInnerNode;
import datastructures.bplustree.interfaces.IBPlusTreeMetrics;
import datastructures.bplustree.interfaces.IBPlusTreeNode;
import datastructures.bplustree.interfaces.IBPlusTreeProperties;

import java.math.BigInteger;
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
            "The properties of a B+ tree.");

        Conditions.validateNotNull(
            root,
            "The root of a B+ tree.");

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

        int height = -1;
        int numberOfInnerNodes = 0;
        int numberOfLeafNodes = 0;

        BigInteger sizeInBytes = BigInteger.ZERO;

        Queue<IBPlusTreeNode<TKey>> queue = new LinkedList<>();
        queue.offer(Casting.cast(root));

        while (!queue.isEmpty()) {
            ++height;

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

                BigInteger currNodeSizeInBytes = BigInteger.valueOf(currNode.getSizeInBytes());
                sizeInBytes = sizeInBytes.add(currNodeSizeInBytes);
            }
        }

        int numberOfNodes = numberOfInnerNodes + numberOfLeafNodes;

        BigInteger innerNodeCapacity = BigInteger.valueOf((long) this.calculateInnerNodeCapacity(properties) * numberOfInnerNodes);
        BigInteger leafNodeCapacity = BigInteger.valueOf((long) this.calculateLeafNodeCapacity(properties) * numberOfLeafNodes);

        BigInteger capacityInBytes = innerNodeCapacity.add(leafNodeCapacity);

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
        return keysCapacity + childrenCapacity;
    }

    /**
     * Calculates a capacity of a leaf node.
     */
    private int calculateLeafNodeCapacity(IBPlusTreeProperties<TKey, TValue> properties) {
        int keysCapacity = properties.getDegree() * properties.getInnerNodeProperties().getKeySizeInBytes();
        int valueCapacity = (properties.getDegree()) * properties.getLeafNodeProperties().getValueSizeInBytes();
        return keysCapacity + valueCapacity;
    }
}
