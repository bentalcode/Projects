package datastructures.bplustree.core;

import base.core.Casting;
import base.core.Conditions;
import datastructures.bplustree.interfaces.IBPlusTreeLeafNode;
import datastructures.bplustree.interfaces.IBPlusTreeNode;
import datastructures.tree.core.TreeNodeData;
import datastructures.tree.interfaces.ITreeDataIterator;
import datastructures.tree.interfaces.ITreeNodeData;
import java.util.Iterator;

/**
 * The BPlusTreeDataIterator class implements an iterator of data of a B+ Tree.
 */
public final class BPlusTreeDataIterator<TKey extends Comparable<TKey>, TValue>
    implements ITreeDataIterator<TKey, TValue> {

    private IBPlusTreeLeafNode<TKey, TValue> currentNode;
    private int currentInnerNodeIndex;

    /**
     * The BPlusTreeDataIterator constructor.
     */
    public BPlusTreeDataIterator(IBPlusTreeNode<TKey> root) {
        Conditions.validateNotNull(
            root,
            "The root of a B+ tree.");

        IBPlusTreeNode<TKey> node = root;

        while (node.getNodeType() == TreeNodeType.InnerNode) {
            int firstNodeIndex = 0;
            node = ((BPlusTreeInnerNode<TKey>)node).getChild(firstNodeIndex);
        }

        this.currentNode = Casting.cast(node);
        this.currentInnerNodeIndex = 0;
    }

    /**
     * Gets an iterator for iterating over data.
     */
    @Override
    public Iterator<ITreeNodeData<TKey, TValue>> iterator() {
        this.currentInnerNodeIndex = 0;
        return this;
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
    public ITreeNodeData<TKey, TValue> next() {
        Conditions.validate(
            this.hasNext(),
            "The iterator has already reached the end of data of a B+ tree.");

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

        ITreeNodeData<TKey, TValue> currNode = new TreeNodeData<>(currKey, currValue);

        return currNode;
    }

    /**
     * Removes the current data.
     */
    @Override
    public void remove() {
        throw new UnsupportedOperationException("Removing data from a B+ tree is not supported.");
    }
}
