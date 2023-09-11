package base.interfaces;

/**
 * The IVisitor interface defines a visitor.
 */
public interface IVisitor<T> {
    /**
     * Visits an element.
     */
    void visit(T element);
}
