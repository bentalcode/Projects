package base.core;

import base.interfaces.IComparableComparator;
import java.io.BufferedReader;
import java.nio.file.Path;

/**
 * The FileComparator class implements a comparator for files.
 */
public final class FileComparator implements IComparableComparator<Path> {
    private final IComparableComparator<String> comparator = Comparator.make();

    /**
     * The FileComparator constructor.
     */
    public FileComparator() {
    }

    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    @Override
    public int compareTo(Path lhs, Path rhs) {
        if (lhs == null && rhs == null) {
            return 0;
        }

        if (lhs == null) {
            return -1;
        }

        if (rhs == null) {
            return 1;
        }

        BufferedReader lhsReader = Readers.createBufferedReader(lhs);
        BufferedReader rhsReader = Readers.createBufferedReader(rhs);

        while (true) {
            String lhsLine = Readers.readLine(lhsReader);
            String rhsLine = Readers.readLine(rhsReader);

            int compareStatus = this.comparator.compareTo(lhsLine, rhsLine);

            if (compareStatus != 0) {
                return compareStatus;
            }

            if (lhsLine == null || rhs == null) {
                assert(lhsLine == null && rhsLine == null);
                break;
            }
        }

        return 0;
    }
}
