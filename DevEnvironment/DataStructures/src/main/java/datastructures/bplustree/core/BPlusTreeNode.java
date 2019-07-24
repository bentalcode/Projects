package datastructures.bplustree.core;

import testbase.core.Arrays;
import testbase.core.Casting;
import testbase.core.CompareToBuilder;
import testbase.core.Conditions;
import testbase.core.EqualBuilder;
import testbase.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import datastructures.bplustree.interfaces.IBPlusTreeNode;
import datastructures.bplustree.interfaces.IBPlusTreeNodeProperties;
import java.util.ArrayList;
import java.util.List;

/**
 * The BPlusTreeNode class implements an abstract node in a B+ Tree.
 */
public abstract class BPlusTreeNode<TKey extends Comparable<TKey>> implements IBPlusTreeNode<TKey> {

    private final IBPlusTreeNodeProperties<TKey> properties;
    private TKey[] keys;
    private int keyCount;
    private IBPlusTreeNode<TKey> parentNode;
    private IBPlusTreeNode<TKey> leftSibling;
    private IBPlusTreeNode<TKey> rightSibling;

    /**
     * The BPlusTreeNode constructor.
     */
    protected BPlusTreeNode(IBPlusTreeNodeProperties<TKey> properties) {
        Conditions.validateNotNull(
            properties,
            "The properties of a node of a B+ tree.");

        this.properties = properties;
        this.keys = Arrays.newInstance(properties.getKeyClassType(), properties.getDegree());
    }

    /**
     * Gets the type of a node.
     */
    @Override
    public abstract TreeNodeType getNodeType();

    /**
     * Gets the properties of a node.
     */
    @Override
    public IBPlusTreeNodeProperties<TKey> getProperties() {
        return this.properties;
    }

    /**
     * Gets a key of a node by index.
     */
    @Override
    public TKey getKey(int index) {
        return this.keys[index];
    }

    /**
     * Sets a key of a node by index.
     */
    @Override
    public void setKey(int index, TKey key) {
        this.keys[index] = key;
    }

    /**
     * Gets the key count of a node.
     */
    @Override
    public int getKeyCount() {
        return this.keyCount;
    }

    /**
     * Gets the keys of a node.
     */
    @Override
    public List<TKey> getKeys() {
        List<TKey> keys = new ArrayList<>();

        for (int i = 0; i < this.getKeyCount(); ++i) {
            TKey currKey = this.keys[i];
            keys.add(currKey);
        }

        return keys;
    }

    /**
     * Sets the key count of a node.
     */
    @Override
    public void setKeyCount(int keyCount) {
        this.keyCount = keyCount;
    }

    /**
     * Gets the parent of a node.
     */
    @Override
    public IBPlusTreeNode<TKey> getParent() {
        return this.parentNode;
    }

    /**
     * Sets the parent of a node.
     */
    @Override
    public void setParent(IBPlusTreeNode<TKey> parent) {
        this.parentNode = parent;
    }

    /**
     * Gets the left sibling.
     */
    @Override
    public IBPlusTreeNode<TKey> getLeftSibling() {
        return this.leftSibling;
	}

    /**
     * Sets the left sibling.
     */
    @Override
	public void setLeftSibling(IBPlusTreeNode<TKey> sibling) {
		this.leftSibling = sibling;
	}

    /**
     * Gets the right sibling.
     */
    @Override
	public IBPlusTreeNode<TKey> getRightSibling() {
        return this.rightSibling;
	}

    /**
     * Sets the right sibling.
     */
    @Override
    public void setRightSibling(IBPlusTreeNode<TKey> sibling) {
		this.rightSibling = sibling;
    }

    /**
     * Finds a position of a key.
     * If found the key, then return it's position, otherwise return -1.
     * For a leaf node, returns a child node index which should contain the key for an internal node.
     */
    @Override
    public abstract int findPosition(TKey key);

    /**
     * Checks whether an overflow condition is set.
     */
    @Override
    public boolean isOverflow() {
        Conditions.validate(
            this.getKeyCount() <= this.keys.length,
            "The keys of a B+ tree node are out of range.");

        return this.getKeyCount() == this.keys.length;
    }

    /**
     * Checks whether there is underflow condition.
     */
    @Override
    public boolean isUnderflow() {
        Conditions.validate(
            this.getKeyCount() <= this.keys.length,
            "The keys of a B+ tree node are out of range.");

        return this.getKeyCount() < (this.keys.length / 2);
    }

    /**
     * Checks whether a key can be lent.
     */
    @Override
    public boolean canLendAKey() {
        Conditions.validate(
            this.getKeyCount() <= this.keys.length,
            "The keys of a B+ tree node are out of range.");

        return this.getKeyCount() > (this.keys.length / 2);
    }

    /**
     * Pushes up a key.
     */
    @Override
    public abstract IBPlusTreeNode<TKey> pushUpKey(
        TKey key,
        IBPlusTreeNode<TKey> leftChild,
        IBPlusTreeNode<TKey> rightChild);

    /**
     * Processes an overflow.
     */
    @Override
    public IBPlusTreeNode<TKey> processOverflow() {
        //
        // Retrieve the parent key...
        //
        int midIndex = this.getKeyCount() / 2;
        TKey upKey = this.getKey(midIndex);

        //
        // Splits the node into two, distributing the keys evenly between the two nodes...
        //
        IBPlusTreeNode<TKey> parent = this.getParent();
        IBPlusTreeNode<TKey> leftNode = this;
        IBPlusTreeNode<TKey> rightNode = this.split();

        //
        // Set the new parent of the nodes...
        //
        if (parent == null) {
            parent = new BPlusTreeInnerNode<>(this.properties);
            leftNode.setParent(parent);
        }

        rightNode.setParent(parent);

        //
        // Maintain links of sibling nodes...
        //
        rightNode.setLeftSibling(leftNode);
        rightNode.setRightSibling(leftNode.getRightSibling());

        leftNode.setRightSibling(rightNode);

        //
        // Push up a key to a parent internal node...
        //
        IBPlusTreeNode<TKey> result = parent.pushUpKey(upKey, leftNode, rightNode);

        return result;
    }

    /**
     * Processes underflow.
     */
    @Override
    public IBPlusTreeNode<TKey> processUnderflow() {

        if (this.getParent() == null) {
            return null;
        }

        //
        // Try to borrow a key from sibling...
        //
        IBPlusTreeNode<TKey> leftSibling = this.getLeftSibling();

        if (leftSibling != null && leftSibling.canLendAKey()) {
            this.getParent().processChildrenTransfer(this, leftSibling, leftSibling.getKeyCount() - 1);
            return null;
        }

        IBPlusTreeNode<TKey> rightSibling = this.getRightSibling();

        if (rightSibling != null && rightSibling.canLendAKey()) {
            this.getParent().processChildrenTransfer(this, rightSibling, 0);
            return null;
        }

        //
        // Can not borrow a key from any sibling, then do fusion with sibling...
        //
        if (leftSibling != null) {
            return this.getParent().processChildrenFusion(leftSibling, this);
        }
        else {
            return this.getParent().processChildrenFusion(this, rightSibling);
        }

    }

    /**
     * Processes children transfer.
     */
    @Override
    public abstract void processChildrenTransfer(
        IBPlusTreeNode<TKey> borrower,
        IBPlusTreeNode<TKey> lender,
        int borrowIndex);

    /**
     * Processes children fusion.
     */
    @Override
    public abstract IBPlusTreeNode<TKey> processChildrenFusion(
        IBPlusTreeNode<TKey> leftChild,
        IBPlusTreeNode<TKey> rightChild);

    /**
     * Fusions with sibling.
     */
    @Override
    public abstract void fusionWithSibling(
        TKey sinkKey,
        IBPlusTreeNode<TKey> rightSibling);

    /**
     * Transfers from sibling.
     */
    @Override
    public abstract TKey transferFromSibling(
        TKey sinkKey,
        IBPlusTreeNode<TKey> sibling,
        int borrowIndex);

    /**
     * Gets the hash code of a node of a B+ tree.
     */
    @Override
    public int hashCode() {
        return this.properties.getNodeComparator().getHashCode(this);
    }

    /**
     * Gets the hash code of a node of a B+ tree.
     */
    @Override
    public boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }

        if (!this.getClass().isInstance(obj)) {
            return false;
        }

        return this.isEqual(Casting.cast(obj));
    }

    /**
     * Checks whether the instances are equals.
     */
    @Override
    public boolean isEqual(IBPlusTreeNode<TKey> other) {
        return this.properties.getNodeComparator().isEqual(this, other);
    }

    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    @Override
    public int compareTo(IBPlusTreeNode<TKey> other) {
        return this.properties.getNodeComparator().compareTo(this, other);
    }

    /**
     * Splits the node.
     */
    protected abstract IBPlusTreeNode<TKey> split();

    /**
     * Shifts the keys to the right.
     */
    protected void shiftKeysToRight(int index) {
        for (int i = this.getKeyCount(); i > index; --i) {
            this.setKey(i, this.getKey(i - 1));
        }
    }

    /**
     * Swaps the keys of the nodes.
     */
    protected static <TKey extends Comparable<TKey>> void swapKeys(
        IBPlusTreeNode<TKey> leftNode,
        IBPlusTreeNode<TKey> rightNode,
        int leftIndex,
        int rightIndex) {

        TKey temp = leftNode.getKey(leftIndex);
        leftNode.setKey(leftIndex, rightNode.getKey(rightIndex));
        rightNode.setKey(rightIndex, temp);
    }

    /**
     * Increments the key count.
     */
    protected void incrementKeyCount() {
        ++this.keyCount;
    }

    /**
     * Decrements the key count.
     */
    protected void decrementKeyCount() {
        --this.keyCount;
    }

    /**
     * Gets the default comparator of a node of a tree.
     */
    public static <TKey extends Comparable<TKey>> IBinaryComparator<IBPlusTreeNode<TKey>> DefaultComparator(
        IBinaryComparator<TKey> keyComparator) {

        return new BPlusTreeNode.Comparator<>(keyComparator);
    }

    /**
     * The Comparator class implements a binary comparator for a node of a B+ tree.
     */
    private static final class Comparator<TKey extends Comparable<TKey>> implements IBinaryComparator<IBPlusTreeNode<TKey>> {
        private final IBinaryComparator<TKey> keyComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<TKey> keyComparator) {
            Conditions.validateNotNull(
                keyComparator,
                "The key comparator.");

            this.keyComparator = keyComparator;
        }

        /**
         * Gets the hash code of this instance.
         */
        @Override
        public int getHashCode(IBPlusTreeNode<TKey> node) {
            return new HashCodeBuilder(3, 5)
                .withCollection(node.getKeys(), this.keyComparator)
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IBPlusTreeNode<TKey> lhs, IBPlusTreeNode<TKey> rhs) {
            return new EqualBuilder()
                .withCollection(lhs.getKeys(), rhs.getKeys(), this.keyComparator)
                .build();
        }

        /**
         * Determines the relative order of two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        public int compareTo(IBPlusTreeNode<TKey> lhs, IBPlusTreeNode<TKey> rhs) {
            return new CompareToBuilder()
                .withCollection(lhs.getKeys(), rhs.getKeys(), this.keyComparator)
                .build();
        }
    }
}
