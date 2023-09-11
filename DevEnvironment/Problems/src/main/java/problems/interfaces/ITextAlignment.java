package problems.interfaces;

import java.util.List;

/**
 * The ITextAlignment interface defines a text alignment.
 */
public interface ITextAlignment {
    /**
     * Aligns a text so it fits into a max-width. Each word is guaranteed to fit into max-width.
     * The words in each result's line should be separated with spaces.
     * The words in each result's line should be distributed evenly as possible, the spaces are distributed
     * evenly from left to right.
     */
    List<String> align(String[] words, int maxWidth);
}
