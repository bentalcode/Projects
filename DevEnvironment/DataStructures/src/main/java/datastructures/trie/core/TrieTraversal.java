package datastructures.trie.core;

import base.core.Conditions;
import base.interfaces.IVisitor;
import java.util.Collection;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;
import datastructures.trie.interfaces.ITrieNode;
import datastructures.trie.interfaces.ITrieTraversal;

/**
 * The TrieTraversal class implements various traversals of a trie.
 */
public final class TrieTraversal<TKey extends Comparable<TKey>> implements ITrieTraversal<TKey> {
    /**
     * The TrieTraversal constructor.
     */
    public TrieTraversal() {
    }

    /**
     * Performs a Breadth-First search.
     */
    @Override
    public void breadthFirstSearch(
        ITrieNode<TKey> root,
        IVisitor<ITrieNode<TKey>> visitor) {

        this.validate(visitor);

        if (root == null) {
            return;
        }

        Queue<ITrieNode<TKey>> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            ITrieNode<TKey> currNode = queue.poll();

            visitor.visit(currNode);

            for (ITrieNode<TKey> child : currNode.getChildren()) {
                assert(child != null);

                queue.offer(child);
            }
        }
    }

    /**
     * Performs a Depth-First search.
     */
    @Override
    public void depthFirstSearch(
        ITrieNode<TKey> root,
        IVisitor<ITrieNode<TKey>> visitor) {

        this.validate(visitor);

        if (root == null) {
            return;
        }

        Set<ITrieNode<TKey>> visited = new HashSet<>();

        visitor.visit(root);
        visited.add(root);

        Collection<ITrieNode<TKey>> children = root.getChildren();

        for (ITrieNode<TKey> child : children) {
            assert(child != null);

            if (!visited.contains(child)) {
                this.depthFirstSearch(child, visitor);
            }
        }
    }
    
    /**
     * Validates a visitor of a trie node.
     */
    private void validate(IVisitor<ITrieNode<TKey>> visitor) {
        Conditions.validateNotNull(
            visitor,
            "The visitor of a trie node.");
    }
}
