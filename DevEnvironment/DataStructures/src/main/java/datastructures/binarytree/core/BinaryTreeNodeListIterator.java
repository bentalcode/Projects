package datastructures.binarytree.core;

import base.core.Conditions;
import base.core.SkipIterator;
import datastructures.binarytree.interfaces.IBinaryTreeNode;
import datastructures.binarytree.interfaces.IBinaryTreeNodeIterator;
import java.util.List;

/**
 * The BinaryTreeNodeListIterator class implements an iterator of a list of binary nodes.
 */
public final class BinaryTreeNodeListIterator<TKey extends Comparable<TKey>, TValue>
    extends SkipIterator<IBinaryTreeNode<TKey, TValue>>
    implements IBinaryTreeNodeIterator<IBinaryTreeNode<TKey, TValue>> {

    private final List<IBinaryTreeNode<TKey, TValue>> nodes;
    private int position;

    /**
     * Creates a new iterator of a tree.
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
        this.registerGenericSkipElement(BinaryTreeEndNode.class);

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

        IBinaryTreeNode<TKey, TValue> currElement = this.nodes.get(this.position);
        this.position = this.nextPosition(this.position);

        return currElement;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.enableSkipElements();
        this.position = this.alignPosition(0);
    }

    /*
     * Gets the next position.
     */
    private int nextPosition(int currPosition) {
        return this.alignPosition(currPosition + 1);
    }

    /*
     * Aligns the position.
     */
    private int alignPosition(int currPosition) {
        int position = currPosition;

        if (!this.getSkipElementsStatus()) {
            return position;
        }

        while (position < this.nodes.size()) {
            IBinaryTreeNode<TKey, TValue> currNode = this.nodes.get(position);

            if (!this.isSkipElement(currNode)) {
                break;
            }

            ++position;
        }

        return position;
    }
}
