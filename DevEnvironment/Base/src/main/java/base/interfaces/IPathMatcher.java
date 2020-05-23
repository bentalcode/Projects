package base.interfaces;

/**
 * The IPathMatcher interface defines matcher of a path.
 */
public interface IPathMatcher {
    /**
     * Checks whether there is a match.
     */
    boolean match(String path);
}
