package datastructures.trie.core;

import base.core.Conditions;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterator;
import datastructures.node.core.KeyValueNode;
import datastructures.node.interfaces.IKeyValueNode;
import datastructures.trie.interfaces.ITrieNode;
import java.util.Stack;

/**
 * The TrieIterator class implements an iterator of a trie.
 */
public final class TrieIterator<TKey extends Comparable<TKey>> implements IIterator<IKeyValueNode<TKey, Boolean>> {
    private final ITrieNode<TKey> root;
    private Stack<ITrieNode<TKey>> stack;

    /**
     * Creates an iterator of a trie.
     */
    public static <TKey extends Comparable<TKey>> IIterator<IKeyValueNode<TKey, Boolean>> make(ITrieNode<TKey> root) {
        return new TrieIterator<>(root);
    }

    /**
     * The TrieIterator constructor.
     */
    private TrieIterator(ITrieNode<TKey> root) {
        Conditions.validateNotNull(
            root,
            "The root of a trie.");

        this.root = root;

        this.reset();
    }

    /**
     * Checks whether there is a next node.
     */
    @Override
    public boolean hasNext() {
        return !this.stack.empty();
    }

    /**
     * Gets the next node.
     */
    @Override
    public IKeyValueNode<TKey, Boolean> next() {
        assert(this.hasNext());

        //
        // Get the current element from the peek of the stack...
        //
        ITrieNode<TKey> currElement = this.stack.pop();

        //
        // Append the children of the node in reverse order to the stack...
        //
        this.appendChildren(currElement);

        return KeyValueNode.make(currElement.getKey(), currElement.isEndNode());
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.stack = new Stack<>();

        if (this.root != null) {
            this.appendChildren(this.root);
        }
    }

    /**
     * Appends the children.
     */
    private void appendChildren(ITrieNode<TKey> node) {
        IReverseIterator<ITrieNode<TKey>> reverseIterator = node.getChildrenReverseIterator();

        while (reverseIterator.hasNext()) {
            ITrieNode<TKey> currChild = reverseIterator.next();
            this.stack.push(currChild);
        }
    }
}
