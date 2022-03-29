package datastructures.bplustree.core;

import datastructures.bplustree.interfaces.IBPlusTreeLeafNode;
import datastructures.bplustree.interfaces.IBPlusTreeLeafNodeProperties;
import datastructures.bplustree.interfaces.IBPlusTreeNode;
import base.core.Arrays;
import base.core.Casting;

/**
 * The BPlusTreeLeafNode class implements a leaf node in a B+ Tree.
 */
public final class BPlusTreeLeafNode<TKey extends Comparable<TKey>, TValue>
    extends BPlusTreeNode<TKey>
    implements IBPlusTreeLeafNode<TKey, TValue> {

    private final IBPlusTreeLeafNodeProperties<TKey, TValue> properties;
    private final TValue[] values;

    /**
     * The BPlusTreeLeafNode constructor.
     */
    public BPlusTreeLeafNode(IBPlusTreeLeafNodeProperties<TKey, TValue> properties) {
        super(properties);

        this.properties = properties;
        this.values = Arrays.newInstance(properties.getValueClassType(), properties.getDegree());
    }

    /**
     * Gets the type of node.
     */
    @Override
    public TreeNodeType getNodeType() {
        return TreeNodeType.LeafNode;
    }

    /**
     * Gets a value of the node.
     */
    @Override
    public TValue getValue(int index) {
       return this.values[index];
    }

    /**
     * Sets a value of the node.
     */
    @Override
    public void setValue(int index, TValue value) {
        this.values[index] = value;
    }

    /**
     * Finds a position of a key on current node.
     * If found the key, then return its insert position, otherwise return -1.
     * For a leaf node, returns a child node index which should contain the key for an internal node.
     */
    @Override
    public int findPosition(TKey key) {
        for (int index = 0; index < this.getKeyCount(); ++index) {
            TKey currKey = this.getKey(index);

            int compareStatus = this.getProperties().getKeyComparator().compareTo(currKey, key);

            if (compareStatus == 0) {
                return index;
            }
            else if (compareStatus > 0) {
                return -1;
            }
        }

        return -1;
    }

    /**
     * Inserts a key.
     */
    @Override
    public void insert(
        TKey key,
        TValue value) {

        int index;

        for (index = 0; index < this.getKeyCount(); ++index) {
            TKey currKey = this.getKey(index);

            if (this.properties.getKeyComparator().compareTo(currKey, key) >= 0) {
                break;
            }
        }

        this.insertAt(index, key, value);
    }

    /**
     * Deletes the key.
     */
    @Override
    public boolean delete(TKey key) {
        int index = this.findPosition(key);

        if (index == -1) {
            return false;
        }

        this.deleteAt(index);

        return true;
    }

    /**
     * Inserts a node at specific index.
     */
    @Override
    public void insertAt(
        int index,
        TKey key,
        TValue value) {

        //
        // Move space for the new key...
        //
        for (int i = this.getKeyCount() - 1; i >= index; --i) {
            this.setKey(i + 1, this.getKey(i));
            this.setValue(i + 1, this.getValue(i));
        }

        //
        // Insert new key and value...
        //
        this.setKey(index, key);
        this.setValue(index, value);

        int keyCount = this.getKeyCount() + 1;
        this.setKeyCount(keyCount);
    }

    /**
     * Deletes the node at specific index.
     */
    @Override
    public void deleteAt(int index) {

        int i;

        for (i = index; i < this.getKeyCount() - 1; ++i) {
            this.setKey(i, this.getKey(i + 1));
            this.setValue(i, this.getValue(i + 1));
        }

        this.setKey(i, null);
        this.setValue(i, null);

        int newKeyCount = this.getKeyCount() - 1;

        this.setKeyCount(newKeyCount);
    }

    /**
     * Pushes up a key.
     */
    @Override
    public IBPlusTreeNode<TKey> pushUpKey(
        TKey key,
        IBPlusTreeNode<TKey> leftChild,
        IBPlusTreeNode<TKey> rightChild) {

        throw new UnsupportedOperationException("BPlusTreeLeafNode.pushUpKey() is not supported.");
    }

    /**
     * Processes a children transfer.
     */
    @Override
    public void processChildrenTransfer(
        IBPlusTreeNode<TKey> borrower,
        IBPlusTreeNode<TKey> lender,
        int borrowIndex) {

        throw new UnsupportedOperationException("BPlusTreeLeafNode.processChildrenTransfer() is not supported.");
    }

    @Override
    public IBPlusTreeNode<TKey> processChildrenFusion(
        IBPlusTreeNode<TKey> leftChild,
        IBPlusTreeNode<TKey> rightChild) {

        throw new UnsupportedOperationException("BPlusTreeLeafNode.processChildrenFusion() is not supported.");
    }

    /**
     * Fusions with sibling.
     */
    @Override
    public void fusionWithSibling(
        TKey sinkKey,
        IBPlusTreeNode<TKey> rightSibling) {

        IBPlusTreeLeafNode<TKey, TValue> siblingLeaf = Casting.cast(rightSibling);

        int keyIndex = this.getKeyCount();

        for (int i = 0; i < siblingLeaf.getKeyCount(); ++i) {
            this.setKey(keyIndex + i, siblingLeaf.getKey(i));
            this.setValue(keyIndex + i, siblingLeaf.getValue(i));
        }

        int newKeyCount = this.getKeyCount() + siblingLeaf.getKeyCount();
        this.setKeyCount(newKeyCount);

        this.setRightSibling(siblingLeaf.getRightSibling());

        if (siblingLeaf.getRightSibling() != null) {
            siblingLeaf.getRightSibling().setLeftSibling(this);
        }
    }

    /**
     * Transfers from sibling.
     */
    @Override
    public TKey transferFromSibling(
        TKey sinkKey,
        IBPlusTreeNode<TKey> sibling,
        int borrowIndex) {

        IBPlusTreeLeafNode<TKey, TValue> siblingNode = Casting.cast(sibling);

        this.insert(siblingNode.getKey(borrowIndex), siblingNode.getValue(borrowIndex));
        siblingNode.deleteAt(borrowIndex);

        return borrowIndex == 0 ? sibling.getKey(0) : this.getKey(0);
    }

    /**
     * Gets the size of a node in bytes.
     */
    @Override
    public int getSizeInBytes() {
        int keysSize = this.getKeyCount() * this.properties.getKeySizeInBytes();
        int valuesSize = this.getKeyCount() * this.properties.getValueSizeInBytes();
        return keysSize + valuesSize;
    }

    /**
     * Splits the internal node.
     * When splitting an internal node, the middle key is moved to the parent node.
     */
    protected IBPlusTreeNode<TKey> split() {
        int midIndex = this.getKeyCount() / 2;

        IBPlusTreeLeafNode<TKey, TValue> rightNode = new BPlusTreeLeafNode<>(this.properties);

        int rightNodeCount = this.getKeyCount() - midIndex;
        int leftNodeIndex = midIndex;

        for (int rightNodeIndex = 0; rightNodeIndex < rightNodeCount; ++rightNodeIndex) {
            BPlusTreeLeafNode.swap(this, rightNode, leftNodeIndex, rightNodeIndex);

            ++leftNodeIndex;
        }

        this.setKeyCount(midIndex);
        rightNode.setKeyCount(rightNodeCount);

        return rightNode;
    }

    /**
     * Swaps the content of the nodes.
     */
    private static <TKey extends Comparable<TKey>, TValue> void swap(
        IBPlusTreeLeafNode<TKey, TValue> leftNode,
        IBPlusTreeLeafNode<TKey, TValue> rightNode,
        int leftIndex,
        int rightIndex) {

        BPlusTreeNode.swapKeys(leftNode, rightNode, leftIndex, rightIndex);
        BPlusTreeLeafNode.swapValues(leftNode, rightNode, leftIndex, rightIndex);
    }

    /**
     * Swaps the values of the nodes.
     */
    private static <TKey extends Comparable<TKey>, TValue> void swapValues(
        IBPlusTreeLeafNode<TKey, TValue> leftNode,
        IBPlusTreeLeafNode<TKey, TValue> rightNode,
        int leftIndex,
        int rightIndex) {

        TValue temp = leftNode.getValue(leftIndex);
        leftNode.setValue(leftIndex, rightNode.getValue(rightIndex));
        rightNode.setValue(rightIndex, temp);
    }
}
