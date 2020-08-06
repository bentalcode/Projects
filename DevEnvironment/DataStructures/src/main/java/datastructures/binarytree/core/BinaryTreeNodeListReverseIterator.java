package datastructures.binarytree.core;

import base.core.Conditions;
import base.core.SkipIterator;
import base.interfaces.ISkipIterator;
import datastructures.binarytree.interfaces.IBinaryTreeNode;
import datastructures.binarytree.interfaces.IBinaryTreeNodeReverseIterator;
import java.util.List;

/**
 * The BinaryTreeNodeListReverseIterator class implements a reverse iterator of a list of binary nodes.
 */
public final class BinaryTreeNodeListReverseIterator<TKey extends Comparable<TKey>, TValue>
    implements IBinaryTreeNodeReverseIterator<IBinaryTreeNode<TKey, TValue>> {

    private final List<IBinaryTreeNode<TKey, TValue>> nodes;
    private int position;
    private final ISkipIterator<IBinaryTreeNode<TKey, TValue>> skipIterator = new SkipIterator<>();

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
        this.skipIterator.registerGenericSkipElement(BinaryTreeEndNode.class);

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

        IBinaryTreeNode<TKey, TValue> currElement = this.nodes.get(this.position);
        this.position = this.nextPosition(this.position);

        return currElement;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.skipIterator.enableSkipElements();
        this.position = this.alignPosition(this.nodes.size() - 1);
    }

    /**
     * Gets the skip iterator.
     */
    @Override
    public ISkipIterator<IBinaryTreeNode<TKey, TValue>> getSkipIterator() {
        return this.skipIterator;
    }

    /*
     * Gets the next position.
     */
    private int nextPosition(int currPosition) {
        return this.alignPosition(currPosition - 1);
    }

    /*
     * Aligns the position.
     */
    private int alignPosition(int currPosition) {
        int position = currPosition;

        if (!this.skipIterator.getSkipElementsStatus()) {
            return position;
        }

        while (position >= 0) {
            IBinaryTreeNode<TKey, TValue> currNode = this.nodes.get(position);

            if (!this.skipIterator.isSkipElement(currNode)) {
                break;
            }

            --position;
        }

        return position;
    }
}
