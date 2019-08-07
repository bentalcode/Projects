package datastructures.binarytree.core;

import base.core.Conditions;
import datastructures.binarytree.interfaces.IBinaryTreeNode;
import datastructures.binarytree.interfaces.IBinaryTreeNodeIterator;
import java.util.List;

/**
 * The BinaryTreeNodeListIterator class implements an iterator of a list of binary nodes.
 */
public class BinaryTreeNodeListIterator<TKey extends Comparable<TKey>, TValue>
    implements IBinaryTreeNodeIterator<IBinaryTreeNode<TKey, TValue>> {

    private final List<IBinaryTreeNode<TKey, TValue>> nodes;
    private int position;
    private boolean skipEndNodes;

    /**
     * Creates a new list iterator.
     */
    public static <TKey extends Comparable<TKey>, TValue> IBinaryTreeNodeIterator<IBinaryTreeNode<TKey, TValue>> of(List<IBinaryTreeNode<TKey, TValue>> nodes) {
        return new BinaryTreeNodeListIterator<>(nodes);
    }

    /**
     * The BinaryTreeNodeListIterator constructor.
     */
    private BinaryTreeNodeListIterator(List<IBinaryTreeNode<TKey, TValue>> nodes) {
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
        return this.position < this.nodes.size();
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
            ++this.position;

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
        this.position = 0;
        this.skipEndNodes();
    }

    /*
     * Skips over end nodes.
     */
    @Override
    public void skipEndNodes() {
        this.skipEndNodes = true;
    }

    /*
     * Includes end nodes.
     */
    @Override
    public void includeEndNodes() {
        this.skipEndNodes = false;
    }
}