package datastructures.tree.core;

import base.core.Conditions;
import base.interfaces.IBinaryComparator;
import base.interfaces.IVisitor;
import datastructures.tree.interfaces.ITreeNode;
import datastructures.tree.interfaces.ITreeTraversal;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Set;

/**
 * The TreeTraversal class implements various traversals of a tree.
 */
public final class TreeTraversal<TKey extends Comparable<TKey>, TValue> implements ITreeTraversal<TKey, TValue> {
    private final IBinaryComparator<ITreeNode<TKey, TValue>> nodeComparator;

    /**
     * The TreeTraversal constructor.
     */
    public TreeTraversal(IBinaryComparator<ITreeNode<TKey, TValue>> nodeComparator) {
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

        List<ITreeNode<TKey, TValue>> children = root.getChildren();

        for (ITreeNode<TKey, TValue> child : children) {
            assert(child != null);

            if (!visited.contains(child)) {
                this.depthFirstSearch(child, visitor);
            }
        }
    }
    
    /**
     * Performs a pre-order search.
     */
    @Override
    public void preOrder(
        ITreeNode<TKey, TValue> root,
        IVisitor<ITreeNode<TKey, TValue>> visitor) {

        this.validate(visitor);

        if (root == null) {
            return;
        }

        List<ITreeNode<TKey, TValue>> children = root.getChildren();

        int size = children.size();
        int leftSize = size / 2;

        //
        // Traverse the root...
        //
        visitor.visit(root);

        //
        // Traverse the left sub tree...
        //
        for (int i = 0; i < leftSize; ++i) {
            this.inOrder(children.get(i), visitor);
        }

        //
        // Traverse the right sub root...
        //
        for (int i = leftSize; i < size; ++i) {
            this.inOrder(children.get(i), visitor);
        }
    }

    /**
     * Performs an in-order search.
     */
    @Override
    public void inOrder(
        ITreeNode<TKey, TValue> root,
        IVisitor<ITreeNode<TKey, TValue>> visitor) {

        this.validate(visitor);

        if (root == null) {
            return;
        }

        List<ITreeNode<TKey, TValue>> children = root.getChildren();

        int size = children.size();
        int leftSize = size / 2;

        //
        // Traverse the left sub tree...
        //
        for (int i = 0; i < leftSize; ++i) {
            this.inOrder(children.get(i), visitor);
        }

        //
        // Traverse the root...
        //
        visitor.visit(root);

        //
        // Traverse the right sub root...
        //
        for (int i = leftSize; i < size; ++i) {
            this.inOrder(children.get(i), visitor);
        }
    }

    /**
     * Performs a post-order search.
     */
    @Override
    public void postOrder(
        ITreeNode<TKey, TValue> root,
        IVisitor<ITreeNode<TKey, TValue>> visitor) {

        this.validate(visitor);

        if (root == null) {
            return;
        }

        List<ITreeNode<TKey, TValue>> children = root.getChildren();

        int size = children.size();
        int leftSize = size / 2;

        //
        // Traverse the left sub tree...
        //
        for (int i = 0; i < leftSize; ++i) {
            this.inOrder(children.get(i), visitor);
        }

        //
        // Traverse the right sub root...
        //
        for (int i = leftSize; i < size; ++i) {
            this.inOrder(children.get(i), visitor);
        }

        //
        // Traverse the root...
        //
        visitor.visit(root);
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
