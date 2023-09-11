package datastructures.tree.core;

import base.core.Conditions;
import base.interfaces.IVisitor;
import datastructures.tree.interfaces.ITreeNode;
import datastructures.tree.interfaces.ITreeTraversal;
import java.util.Collection;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;

/**
 * The TreeTraversal class implements various traversals of a tree.
 */
public final class TreeTraversal<TKey extends Comparable<TKey>, TValue> implements ITreeTraversal<TKey, TValue> {
    /**
     * The TreeTraversal constructor.
     */
    public TreeTraversal() {
    }

    /**
     * Performs a Breadth-First search.
     */
    @Override
    public void breadthFirstSearch(
        ITreeNode<TKey, TValue> root,
        IVisitor<ITreeNode<TKey, TValue>> visitor) {

        this.validate(visitor);

        if (root == null) {
            return;
        }

        Queue<ITreeNode<TKey, TValue>> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            ITreeNode<TKey, TValue> currNode = queue.poll();

            visitor.visit(currNode);

            for (ITreeNode<TKey, TValue> child : currNode.getChildren()) {
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
        ITreeNode<TKey, TValue> root,
        IVisitor<ITreeNode<TKey, TValue>> visitor) {

        this.validate(visitor);

        if (root == null) {
            return;
        }

        Set<ITreeNode<TKey, TValue>> visited = new HashSet<>();

        visitor.visit(root);
        visited.add(root);

        Collection<ITreeNode<TKey, TValue>> children = root.getChildren();

        for (ITreeNode<TKey, TValue> child : children) {
            assert(child != null);

            if (!visited.contains(child)) {
                this.depthFirstSearch(child, visitor);
            }
        }
    }
    
    /**
     * Validates a visitor of a tree node.
     */
    private void validate(IVisitor<ITreeNode<TKey, TValue>> visitor) {
        Conditions.validateNotNull(
            visitor,
            "The visitor of a tree node.");
    }
}
