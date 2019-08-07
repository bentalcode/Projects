package datastructures.binarytree.core;

import base.core.Conditions;
import datastructures.binarytree.interfaces.IBinaryTreeNode;
import datastructures.binarytree.interfaces.IBinaryTreeNodeReverseIterator;
import java.util.List;

/**
 * The BinaryTreeNodeListReverseIterator class implements a reverse iterator of a list of binary nodes.
 */
public class BinaryTreeNodeListReverseIterator<TKey extends Comparable<TKey>, TValue>
    implements IBinaryTreeNodeReverseIterator<IBinaryTreeNode<TKey, TValue>> {

    private final List<IBinaryTreeNode<TKey, TValue>> nodes;
    private int position;
    private boolean skipEndNodes;

    /**
     * Creates a new reverse iterator of a list.
     */
    public static <TKey extends Comparable<TKey>, TValue> IBinaryTreeNodeReverseIterator<IBinaryTreeNode<TKey, TValue>> of(
        List<IBinaryTreeNode<TKey, TValue>> nodes) {

        return new BinaryTreeNodeListReverseIterator<>(nodes);
    }

    /**
     * The BinaryTreeNodeListIterator constructor.
     */
    private BinaryTreeNodeListReverseIterator(List<IBinaryTreeNode<TKey, TValue>> nodes) {
        Conditions.validateNotNull(
            nodes,
            "The nodes to iterate.");

        this.nodes = nodes;

        this.reset();
    }

    /**
     * Checks whether there is a next element.
     */
    @Override
    public boolean hasNext() {
        return this.position >= 0;
    }

    /**
     * Gets the next element.
     */
    @Override
    public IBinaryTreeNode<TKey, TValue> next() {
        assert(this.hasNext());

        IBinaryTreeNode<TKey, TValue> currElement = null;

        while (this.hasNext()) {
            currElement = this.nodes.get(this.position);
            --this.position;

            if (this.skipEndNodes && currElement.getClass().isInstance(BinaryTreeEndNode.class)) {
                continue;
            }
        }

        return currElement;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.position = this.nodes.size() - 1;
        this.skipEndNodes();
    }

    /*
     * Skips over end nodes.
     * Returns the previous set status.
     */
    @Override
    public boolean skipEndNodes() {
        return this.setSkipEndNodesStatus(true);
    }

    /*
     * Includes end nodes.
     */
    @Override
    public boolean includeEndNodes() {
        return this.setSkipEndNodesStatus(false);
    }

    /*
     * Sets the status of skip end nodes.
     * Returns the previous configured status.
     */
    @Override
    public boolean setSkipEndNodesStatus(boolean status) {
        boolean previousStatus = status;
        this.skipEndNodes = status;
        return previousStatus;
    }
}
