package base.interfaces;

/**
 * The IComparable interface defines a comparable for a generic class,
 * for determining comparable order between this instance and an other.
 */
public interface IComparable<Type> extends Comparable<Type>{
    /**
     * Gets the hash code.
     */
    int hashCode();
}
