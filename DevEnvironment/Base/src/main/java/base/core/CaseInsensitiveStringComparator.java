package base.core;

import java.util.Comparator;

/**
 * The CaseInsensitiveStringComparator class implements a comparison of a case insensitive string.
 */
public final class CaseInsensitiveStringComparator implements Comparator<String> {
    /**
     * The CaseInsensitiveStringComparator constructor.
     */
    public CaseInsensitiveStringComparator() {
    }

    /**
     * Compares the strings.
     */
    @Override
    public int compare(String left, String right) {
        if (left == null && right == null) {
            return 0;
        }

        if (left == null) {
            return -1;
        }

        if (right == null) {
            return 1;
        }

        return left.compareToIgnoreCase(right);
    }
}
