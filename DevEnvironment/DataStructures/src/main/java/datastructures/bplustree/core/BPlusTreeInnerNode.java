package datastructures.bplustree.core;

import base.interfaces.IPrimitiveSize;
import datastructures.bplustree.interfaces.IBPlusTreeInnerNode;
import datastructures.bplustree.interfaces.IBPlusTreeNode;
import base.core.Arrays;
import base.core.Casting;
import datastructures.bplustree.interfaces.IBPlusTreeNodeProperties;
import java.util.ArrayList;
import java.util.List;

/**
 * The BPlusTreeInnerNode class implements an inner node in a B+ Tree.
 */
public final class BPlusTreeInnerNode<TKey extends Comparable<TKey>> extends BPlusTreeNode<TKey> implements IBPlusTreeInnerNode<TKey> {
    private final IBPlusTreeNode<TKey>[] children;

    /**
     * The BPlusTreeInnerNode constructor.
     */
    public BPlusTreeInnerNode(IBPlusTreeNodeProperties<TKey> properties) {
        super(properties);

        this.children = Arrays.newInstance(
            IBPlusTreeNode.class,
            properties.getDegree() + 1);
    }

    /**
     * Gets the type of a node.
     */
    @Override
    public TreeNodeType getNodeType() {
        return TreeNodeType.InnerNode;
    }

    /**
     * Gets a child by index.
     */
    @Override
    public IBPlusTreeNode<TKey> getChild(int index) {
        return this.children[index];
    }

    /**
     * Gets the children.
     */
    @Override
    public List<IBPlusTreeNode<TKey>> getChildren() {
        List<IBPlusTreeNode<TKey>> children = new ArrayList<>();

        for (int i = 0; i < this.getChildrenCount(); ++i) {
            children.add(this.getChild(i));
        }

        return children;
    }

    /**
     * Gets the children count of a node.
     */
    @Override
    public int getChildrenCount() {
        return this.getKeyCount() + 1;
    }

    /**
     * Sets a child by index.
     */
    @Override
    public void setChild(int index, IBPlusTreeNode<TKey> child) {
        this.children[index] = child;

        if (child != null) {
            child.setParent(this);
        }
    }

    /**
     * Finds a position of a key on current node.
     * If found the key, then return its insert position, otherwise return -1.
     * For a leaf node, returns a child node index which should contain the key for an internal node.
     */
    @Override
    public int findPosition(TKey key) {
        int index = 0;

        for (index = 0; index < this.getKeyCount(); ++index) {
            TKey currKey = this.getKey(index);

            int compareStatus = this.getProperties().getKeyComparator().compareTo(currKey, key);

            if (compareStatus == 0) {
                return index + 1;
            }
            else if (compareStatus > 0) {
                return index;
            }
        }

        return index;
    }

    /**
     * Pushes up a key.
     */
     public IBPlusTreeNode<TKey> pushUpKey(
        TKey key,
        IBPlusTreeNode<TKey> leftChild,
        IBPlusTreeNode<TKey> rightChild) {

        //
        // Find the target position of the new key...
        //
        int index = this.findPosition(key);

        //
        // Insert the new key...
        //
        this.insertAt(index, key, leftChild, rightChild);

        //
        // Check whether the current node is needed to be splitted...
        //
        IBPlusTreeNode<TKey> result = null;

        if (this.isOverflow()) {
            result = this.processOverflow();
        }
        else if (this.getParent() == null) {
            result = this;
        }

        return result;
    }

    /**
     * Processes a children transfer.
     */
    @Override
    public void processChildrenTransfer(
        IBPlusTreeNode<TKey> borrower,
        IBPlusTreeNode<TKey> lender,
        int borrowIndex) {

        int borrowerChildIndex = 0;

        while (borrowerChildIndex < this.getChildrenCount() && this.getChild(borrowerChildIndex) != borrower) {
            ++borrowerChildIndex;
        }

        if (borrowIndex == 0) {
            //
            // Borrow a key from the right sibling...
            //
            TKey upKey = borrower.transferFromSibling(this.getKey(borrowerChildIndex), lender, borrowIndex);
            this.setKey(borrowerChildIndex, upKey);
        }
        else {
            //
            // Borrow a key from the left sibling...
            //
            TKey upKey = borrower.transferFromSibling(this.getKey(borrowerChildIndex - 1), lender, borrowIndex);
            this.setKey(borrowerChildIndex - 1, upKey);
        }
    }

    /**
     * Processes a children fusion.
     */
    @Override
    public IBPlusTreeNode<TKey> processChildrenFusion(
        IBPlusTreeNode<TKey> leftChild,
        IBPlusTreeNode<TKey> rightChild) {

        int index = 0;
        while (index < this.getKeyCount() && this.getChild(index) != leftChild) {
            ++index;
        }

        TKey sinkKey = this.getKey(index);

        //
        // Merge two children and the sink key into the left child node...
        //
        leftChild.fusionWithSibling(sinkKey, rightChild);

        //
        // Remove the sink key, keep the left child and abandon the right child...
        //
        this.deleteAt(index);

        //
        // Check whether needed to propagate borrow or fusion to parent...
        //
        IBPlusTreeNode<TKey> result = null;

        if (this.isUnderflow()) {
            if (this.getParent() == null) {
                //
                // Current node is root, only remove keys or delete the whole root node...
                //
                if (this.getKeyCount() == 0) {
                    leftChild.setParent(null);
                    result = leftChild;
                }
            }
            else {
                result = this.processUnderflow();
            }
        }

        return result;
    }

    /**
     * Fusions with sibling.
     */
    @Override
    public void fusionWithSibling(
        TKey sinkKey,
        IBPlusTreeNode<TKey> rightSibling) {

        IBPlusTreeInnerNode<TKey> rightSiblingNode = Casting.cast(rightSibling);

        int keyIndex = this.getKeyCount();
        this.setKey(keyIndex, sinkKey);
        ++keyIndex;

        for (int i = 0; i < rightSiblingNode.getKeyCount(); ++i) {
            TKey currKey = rightSiblingNode.getKey(i);
            this.setKey(keyIndex + i, currKey);
        }

        for (int i = 0; i < rightSiblingNode.getChildrenCount(); ++i) {
            IBPlusTreeNode<TKey> currChild = rightSiblingNode.getChild(i);
            this.setChild(keyIndex + i, currChild);
        }

        int newKeyCount = 1 + rightSiblingNode.getKeyCount();
        this.setKeyCount(newKeyCount);

        this.setRightSibling(rightSiblingNode.getRightSibling());

        if (rightSiblingNode.getRightSibling() != null) {
            rightSiblingNode.getRightSibling().setLeftSibling(this);
        }
    }

    /**
     * Transfers from sibling.
     */
    public TKey transferFromSibling(
        TKey sinkKey,
        IBPlusTreeNode<TKey> sibling,
        int borrowIndex) {

        IBPlusTreeInnerNode<TKey> siblingNode = Casting.cast(sibling);

        TKey upKey;

        if (borrowIndex == 0) {
            //
            // Borrow the first key from the right sibling, append it to tail...
            //
            int index = this.getKeyCount();
            this.setKey(index, sinkKey);
            this.setChild(index + 1, siblingNode.getChild(borrowIndex));

            int newKeyCount = this.getKeyCount() + 1;
            this.setKeyCount(newKeyCount);

            upKey = siblingNode.getKey(0);
        }
        else {
            //
            // Borrow the last key from left sibling, insert it to the head...
            //
            this.insertAt(0, sinkKey, siblingNode.getChild(borrowIndex + 1), this.getChild(0));
            upKey = siblingNode.getKey(borrowIndex);
        }

        siblingNode.deleteAt(borrowIndex);

        return upKey;
    }

    /**
     * Inserts a node at specific index.
     */
    @Override
    public void insertAt(
        int index,
        TKey key,
        IBPlusTreeNode<TKey> leftChild,
        IBPlusTreeNode<TKey> rightChild) {

        //
        // Make an available space for the new key for inserting...
        //
        this.shiftKeysToRight(index);
        this.setKey(index, key);

        //
        // Make an available space for the new children for inserting...
        //
        this.shiftChildrenToRight(index);
        this.setChild(index, leftChild);
        this.setChild(index + 1, rightChild);

        //
        // Increment the key count...
        //
        this.incrementKeyCount();
    }

    /**
     * Deletes at a specific index.
     */
    @Override
    public void deleteAt(int index) {
        int i = 0;

        for (i = index; i < this.getKeyCount() - 1; ++i) {
            this.setKey(i, this.getKey(i + 1));
            this.setChild(i + 1, this.getChild(i + 2));
        }

        this.setKey(i, null);
        this.setChild(i + 1, null);

        this.decrementKeyCount();
    }

    /**
     * Gets the size of a node in bytes.
     */
    @Override
    public int getSizeInBytes() {
        int keysSize = this.getKeyCount() * this.getProperties().getKeySizeInBytes();
        int valuesSize = this.getChildrenCount() * IPrimitiveSize.InBytes.ReferenceSize;

        return keysSize + valuesSize;
    }

    /**
     * Splits the leaf node.
     * When splitting an inner node, the middle key is kept on new node and be pushed to parent node.
     */
    protected IBPlusTreeNode<TKey> split() {
        int midIndex = this.getKeyCount() / 2;

        IBPlusTreeInnerNode<TKey> rightNode = new BPlusTreeInnerNode<>(this.getProperties());

        //
        // Swaps the keys...
        //
        int rightNodeCount = this.getKeyCount() - midIndex - 1;

        int leftNodeIndex = midIndex + 1;

        for (int rightNodeIndex = 0; rightNodeIndex < rightNodeCount; ++rightNodeIndex) {
            BPlusTreeNode.swapKeys(this, rightNode, leftNodeIndex, rightNodeIndex);

            ++leftNodeIndex;
        }

        // When splitting a leaf node, the middle key is kept on new node and be pushed to parent node.
        this.setKey(midIndex, null);
        this.setKeyCount(midIndex);
        rightNode.setKeyCount(rightNodeCount);

        //
        // Swaps the children...
        //
        leftNodeIndex = midIndex + 1;
        for (int rightNodeIndex = 0; rightNodeIndex < rightNodeCount + 1; ++rightNodeIndex) {
            BPlusTreeInnerNode.swapChildren(this, rightNode, leftNodeIndex, rightNodeIndex);
            ++leftNodeIndex;
        }

        return rightNode;
    }

    /**
     * Shifts the children to the right.
     */
    private void shiftChildrenToRight(int index) {
        for (int i = this.getChildrenCount(); i > index; --i) {
            this.setChild(i, this.getChild(i - 1));
        }
    }

    /**
     * Swaps the children of the nodes.
     */
    private static <TKey extends Comparable<TKey>> void swapChildren(
        IBPlusTreeInnerNode<TKey> leftNode,
        IBPlusTreeInnerNode<TKey> rightNode,
        int leftIndex,
        int rightIndex) {

        IBPlusTreeNode<TKey> temp = leftNode.getChild(leftIndex);
        leftNode.setChild(leftIndex, rightNode.getChild(rightIndex));
        rightNode.setChild(rightIndex, temp);

        if (leftNode.getChild(leftIndex) != null) {
            leftNode.getChild(leftIndex).setParent(leftNode);
        }

        if (rightNode.getChild(rightIndex) != null) {
            rightNode.getChild(rightIndex).setParent(rightNode);
        }
    }
}
