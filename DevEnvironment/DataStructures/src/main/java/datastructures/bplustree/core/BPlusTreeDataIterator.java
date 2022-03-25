package datastructures.bplustree.core;

import base.core.Casting;
import base.core.Conditions;
import base.interfaces.IIterator;
import datastructures.bplustree.interfaces.IBPlusTreeInnerNode;
import datastructures.bplustree.interfaces.IBPlusTreeLeafNode;
import datastructures.bplustree.interfaces.IBPlusTreeNode;
import datastructures.node.core.KeyValueNode;
import datastructures.node.interfaces.IKeyValueNode;

/**
 * The BPlusTreeDataIterator class implements an iterator of data of a B+ Tree.
 */
public final class BPlusTreeDataIterator<TKey extends Comparable<TKey>, TValue> implements
    IIterator<IKeyValueNode<TKey, TValue>> {

    private IBPlusTreeLeafNode<TKey, TValue> currentNode;
    private int currentInnerNodeIndex;

    /**
     * The BPlusTreeDataIterator constructor.
     */
    public static <TKey extends Comparable<TKey>, TValue> IIterator<IKeyValueNode<TKey, TValue>> make(
        IBPlusTreeNode<TKey> root) {

        return new BPlusTreeDataIterator<>(root);
    }

    /**
     * The BPlusTreeDataIterator constructor.
     */
    private BPlusTreeDataIterator(IBPlusTreeNode<TKey> root) {
        Conditions.validateNotNull(
            root,
            "The root of a B+ tree.");

        IBPlusTreeNode<TKey> node = root;

        while (node.getNodeType() == TreeNodeType.InnerNode) {
            int firstNodeIndex = 0;
            IBPlusTreeInnerNode<TKey> innerNode = Casting.cast(node);
            node = innerNode.getChild(firstNodeIndex);
        }

        this.currentNode = Casting.cast(node);

        this.reset();
    }

    /**
     * Checks whether there is a next data.
     */
    @Override
    public boolean hasNext() {
        return
            this.currentNode != null &&
            this.currentInnerNodeIndex < this.currentNode.getKeyCount();
    }

    /**
     * Gets the next data.
     */
    @Override
    public IKeyValueNode<TKey, TValue> next() {
        assert(this.hasNext());

        TKey currKey = this.currentNode.getKey(this.currentInnerNodeIndex);
        TValue currValue = this.currentNode.getValue(this.currentInnerNodeIndex);

        ++this.currentInnerNodeIndex;

        if (this.currentInnerNodeIndex == this.currentNode.getKeyCount()) {

            if (this.currentNode.getRightSibling() != null) {
                this.currentNode = Casting.cast(this.currentNode.getRightSibling());
                this.currentInnerNodeIndex = 0;
            }
            else {
                this.currentNode = null;
                this.currentInnerNodeIndex = 0;
            }
        }

        return KeyValueNode.make(currKey, currValue);
    }

    /**
     * Reset the iterator.
     */
    @Override
    public void reset() {
        this.currentInnerNodeIndex = 0;
    }
}
