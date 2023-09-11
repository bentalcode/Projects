package problems.interfaces;

import java.util.List;

/**
 * The IStringTransformation interface defines a string transformation.
 */
public interface IStringTransformation {
    /**
     * Counts the required edits for transforming a source string to a destination string.
     * The following edits are supported on the source string: Replace, Insert and Remove.
     */
    int countEdits(String src, String dest);

    /**
     * Calculates the required edits for transforming a source string to a destination string.
     * The following edits are supported on the source string: Replace, Insert and Remove.
     */
    List<IEditInformation<Character>> calculateEdits(String src, String dest);
}
