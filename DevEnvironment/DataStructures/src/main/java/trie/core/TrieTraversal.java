package trie.core;

import base.core.Conditions;
import base.interfaces.IBinaryComparator;
import base.interfaces.IVisitor;
import java.util.Collection;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;
import trie.interfaces.ITrieNode;
import trie.interfaces.ITrieTraversal;

/**
 * The TrieTraversal class implements various traversals of a trie.
 */
public final class TrieTraversal<TKey extends Comparable<TKey>, TValue> implements ITrieTraversal<TKey, TValue> {
    private final IBinaryComparator<ITrieNode<TKey, TValue>> nodeComparator;

    /**
     * The TrieTraversal constructor.
     */
    public TrieTraversal(IBinaryComparator<ITrieNode<TKey, TValue>> nodeComparator) {
        Conditions.validateNotNull(
            nodeComparator,
            "The comparator of a node in tree.");

        this.nodeComparator = nodeComparator;
    }

    /**
     * Performs a Breadth-First search.
     */
    @Override
    public void breadthFirstSearch(
        ITrieNode<TKey, TValue> root,
        IVisitor<ITrieNode<TKey, TValue>> visitor) {

        this.validate(visitor);

        if (root == null) {
            return;
        }

        Queue<ITrieNode<TKey, TValue>> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            ITrieNode<TKey, TValue> currNode = queue.poll();

            visitor.visit(currNode);

            for (ITrieNode<TKey, TValue> child : currNode.getChildren()) {
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
        ITrieNode<TKey, TValue> root,
        IVisitor<ITrieNode<TKey, TValue>> visitor) {

        this.validate(visitor);

        if (root == null) {
            return;
        }

        Set<ITrieNode<TKey, TValue>> visited = new HashSet<>();

        visitor.visit(root);
        visited.add(root);

        Collection<ITrieNode<TKey, TValue>> children = root.getChildren();

        for (ITrieNode<TKey, TValue> child : children) {
            assert(child != null);

            if (!visited.contains(child)) {
                this.depthFirstSearch(child, visitor);
            }
        }
    }
    
    /**
     * Validates a visitor of a trie node.
     */
    private void validate(IVisitor<ITrieNode<TKey, TValue>> visitor) {
        Conditions.validateNotNull(
            visitor,
            "The visitor of a trie node.");
    }
}
