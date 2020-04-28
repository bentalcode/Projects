package problems.core;

import base.core.Conditions;
import base.core.Lists;
import problems.interfaces.IEditInformation;
import problems.interfaces.IStringTransformation;
import java.util.ArrayList;
import java.util.List;

/**
 * The StringTransformation class implements a string transformation.
 */
public final class StringTransformation implements IStringTransformation {

    /**
     * Counts the required edits for transforming a source string to a destination string.
     * The following edits are supported on the source string: Replace, Insert and Remove.
     */
    @Override
    public int countEdits(String src, String dest) {
        Conditions.validateNotNull(
            src,
            "The source string");

        Conditions.validateNotNull(
            dest,
            "The destination string");
        
        char[] srcCharArray = src.toCharArray();
        char[] destCharArray = dest.toCharArray();
     
        return this.countEdits(
            srcCharArray,
            destCharArray);
    }

    /**
     * Counts the required edits for transforming a source string to a destination string.
     * The following edits are supported on the source string: Replace, Insert and Remove.
     */
    public int countEditsRecursive(String src, String dest) {
        Conditions.validateNotNull(
            src,
            "The source string");

        Conditions.validateNotNull(
            dest,
            "The destination string");

        char[] srcCharArray = src.toCharArray();
        char[] destCharArray = dest.toCharArray();

        return this.countEditsRecursive(
            srcCharArray,
            srcCharArray.length,
            destCharArray,
            destCharArray.length);
    }

    /**
     * Calculates the required edits for transforming a source string to a destination string.
     * The following edits are supported on the source string: Replace, Insert and Remove.
     */
    @Override
    public List<IEditInformation<Character>> calculateEdits(String src, String dest) {
        Conditions.validateNotNull(
            src,
            "The source string");

        Conditions.validateNotNull(
            dest,
            "The destination string");

        List<IEditInformation<Character>> result = new ArrayList<>();

        char[] srcCharArray = src.toCharArray();
        char[] destCharArray = dest.toCharArray();

        if (srcCharArray.length == 0) {
            for (char destChar : destCharArray) {
                result.add(EditInformation.createInsert(null, destChar));
            }

            return result;
        }

        if (destCharArray.length == 0) {
            for (char srcChar : srcCharArray) {
                result.add(EditInformation.createRemove(srcChar));
            }
            
            return result;
        }

        int[][] lookup = this.createLookup(
            srcCharArray,
            destCharArray);

        int rows = lookup.length;
        int cols = lookup[0].length;

        int currRow = rows - 1;
        int currCol = cols - 1;

        while (currRow >= 0 && currCol >= 0) {
            if (currRow == 0 && currCol == 0) {
                break;
            }

            if (currRow == 0) {
                char currSrcCharacter = srcCharArray[currCol - 1];
                result.add(EditInformation.createRemove(currSrcCharacter));
                --currCol;
            }
            else if (currCol == 0) {
                char currDstCharacter = destCharArray[currRow - 1];
                result.add(EditInformation.createRemove(currDstCharacter));
                --currRow;
            }
            else {
                char currSrcCharacter = srcCharArray[currCol - 1];
                char currDstCharacter = destCharArray[currRow - 1];

                if (currSrcCharacter == currDstCharacter) {
                    result.add(null);
                    --currRow;
                    --currCol;
                } else {
                    int insertCount = lookup[currRow - 1][currCol];
                    int removeCount = lookup[currRow][currCol - 1];
                    int replaceCount = lookup[currRow - 1][currCol - 1];

                    if (insertCount <= removeCount && insertCount <= replaceCount) {
                        result.add(EditInformation.createInsert(currSrcCharacter, currDstCharacter));
                        --currRow;
                    } else if (removeCount <= insertCount && removeCount <= replaceCount) {
                        result.add(EditInformation.createRemove(currSrcCharacter));
                        --currCol;
                    } else {
                        result.add(EditInformation.createReplace(currSrcCharacter, currDstCharacter));
                        --currRow;
                        --currCol;
                    }
                }
            }
        }

        Lists.reverseInPlace(result);

        return result;
    }

    /**
     * Counts the required edits for transforming a source string to a destination string.
     */
    private int countEdits(
        char[] src,
        char[] dest) {

        if (src.length == 0) {
            return dest.length;
        }

        if (dest.length == 0) {
            return src.length;
        }

        int[][] lookup = this.createLookup(src, dest);
        int rows = lookup.length;
        int cols = lookup[0].length;

        return lookup[rows - 1][cols - 1];
    }

    /**
     * Counts the required edits for transforming a source string to a destination string.
     */
    private int countEditsRecursive(
        char[] src, int srcSize,
        char[] dest, int destSize) {
        
        if (srcSize == 0) {
            return destSize;
        }
        
        if (destSize == 0) {
            return srcSize;
        }
        
        if (src[srcSize - 1] == dest[destSize - 1]) {
            return this.countEditsRecursive(
                src, srcSize - 1,
                dest, destSize - 1);
        }
        else {
            int reminderInsertCount = this.countEditsRecursive(
                src, srcSize,
                dest, destSize - 1);
            
            int reminderRemoveCount = this.countEditsRecursive(
                src, srcSize - 1,
                dest, destSize);

            int reminderReplaceCount = this.countEditsRecursive(
                src, srcSize - 1,
                dest, destSize - 1);

            int reminderMinCount = Math.min(reminderInsertCount, Math.min(reminderRemoveCount, reminderReplaceCount));

            return 1 + reminderMinCount;
        }
    }

    /**
     * Creates a lookup.
     */
    private int[][] createLookup(
        char[] src,
        char[] dest) {

        int rows = dest.length + 1;
        int cols = src.length + 1;

        int[][] lookup = new int[rows][cols];
        lookup[0][0] = 0;

        for (int col = 1; col < cols; ++col) {
            lookup[0][col] = col;
        }

        for (int row = 1; row < rows; ++row) {
            lookup[row][0] = row;
        }

        for (int row = 1; row < rows; ++row) {
            for (int col = 1; col < cols; ++col) {

                char srcLastCharacter = src[col - 1];
                char destLastCharacter = dest[row - 1];

                if (srcLastCharacter == destLastCharacter) {
                    lookup[row][col] = lookup[row - 1][col - 1];
                }
                else {
                    int reminderInsertCount = lookup[row - 1][col];
                    int reminderRemoveCount = lookup[row][col - 1];
                    int reminderReplaceCount = lookup[row - 1][col - 1];
                    int reminderMinCount = Math.min(reminderInsertCount, Math.min(reminderRemoveCount, reminderReplaceCount));

                    lookup[row][col] = 1 + reminderMinCount;
                }

            }
        }

        return lookup;
    }
}
