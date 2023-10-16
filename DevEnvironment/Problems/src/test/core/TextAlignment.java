package problems.core;

import base.core.Conditions;
import base.core.MutableInteger;
import problems.ProblemsException;
import problems.interfaces.ITextAlignment;
import java.util.ArrayList;
import java.util.List;

/**
 * The TextAlignment class implements a text alignment.
 */
public final class TextAlignment implements ITextAlignment {
    /**
     * The TextAlignment constructor.
     */
    public TextAlignment() {
    }

    /**
     * Aligns a text so it fits into a max-width. Each word is guaranteed to fit into max-width.
     * The words in each result's line should be separated with spaces.
     * The words in each result's line should be distributed evenly as possible, the spaces are distributed
     * evenly from left to right.
     */
    @Override
    public List<String> align(String[] words, int maxWidth) {
        Conditions.validateNotNull(
            words,
            "The input words");

        int maxWordSize = TextAlignment.getMaxStringLength(words);

        Conditions.validate(
            maxWidth >= maxWordSize,
            "Not all the input words can fit into the max width of the text.");

        List<String> result = new ArrayList<>();

        if (words.length == 0) {
            return result;
        }

        int startIndex = 0;
        int endIndex = 0;
        int currSum = words[0].length();

        for (int i = 1; i < words.length; ++i) {
            String currWord = words[i];

            //
            // Count the comma separator...
            //
            ++currSum;

            //
            // Count the current word...
            //
            currSum += currWord.length();

            if (currSum <= maxWidth) {
                //
                // The current word is included in the current record...
                //
                ++endIndex;
            }
            else {
                //
                // The current word is not included in the current record...
                //
                this.addResultRecord(
                    words,
                    maxWidth,
                    startIndex,
                    endIndex,
                    false,
                    result);

                startIndex = i;
                endIndex = i;
                currSum = currWord.length();
            }

            //
            // Break when including the last word...
            //
            if (endIndex == words.length - 1) {
                break;
            }
        }

        this.addResultRecord(
            words,
            maxWidth,
            startIndex,
            endIndex,
            true,
            result);

        return result;
    }

    /**
     * Adds a result record.
     */
    private void addResultRecord(
        String[] words,
        int maxWidth,
        int startIndex,
        int endIndex,
        boolean lastLine,
        List<String> result) {

        char[] recordBuffer = new char[maxWidth];

        int numberOfCharactersWritten;

        if (!lastLine) {
            numberOfCharactersWritten = this.writeResultRecord(
                words,
                startIndex,
                endIndex,
                recordBuffer);
        }
        else {
            numberOfCharactersWritten = this.writeLastResultRecord(
                words,
                startIndex,
                endIndex,
                recordBuffer);
        }

        if (numberOfCharactersWritten != maxWidth) {
            String errorMessage = "The current result record failed to be written.";
            throw new ProblemsException(errorMessage);
        }

        String record = new String(recordBuffer);
        result.add(record);
    }

    /**
     * Writes a result record.
     */
    private int writeResultRecord(
        String[] words,
        int startIndex,
        int endIndex,
        char[] result) {

        if (startIndex > endIndex) {
            return 0;
        }

        int numberOfWords = endIndex - startIndex + 1;
        int insertIndex = 0;

        //
        // Write the first word...
        //
        String firstWord = words[startIndex];
        int numberOfWrittenCharacters = this.writeWord(firstWord, result, insertIndex);

        if (numberOfWrittenCharacters != firstWord.length()) {
            String errorMessage =
                "TextAlignment: The first word failed to get written to the result record.";

            throw new ProblemsException(errorMessage);
        }

        insertIndex += numberOfWrittenCharacters;

        if (numberOfWords == 1) {
            return insertIndex;
        }

        int middleWordsLength = 0;
        for (int i = startIndex + 1; i < endIndex; ++i) {
            middleWordsLength += words[i].length();
        }

        String lastWord = words[endIndex];

        int middleAvailableLength = result.length - firstWord.length() - lastWord.length();
        int middlePadsAvailableLength = middleAvailableLength - middleWordsLength;
        int numberPadsInMiddle = numberOfWords - 1;
        int middlePadLength = middlePadsAvailableLength / numberPadsInMiddle;
        MutableInteger middlePadsReminderLength = new MutableInteger(middlePadsAvailableLength % numberPadsInMiddle);

        //
        // Write the first pad...
        //
        int padLength = this.calculatePadLength(middlePadLength, middlePadsReminderLength);

        numberOfWrittenCharacters = this.writePad(padLength, result, insertIndex);

        if (numberOfWrittenCharacters != padLength) {
            String errorMessage =
                "TextAlignment: The first pad failed to get written to the result record.";

            throw new ProblemsException(errorMessage);
        }

        insertIndex += numberOfWrittenCharacters;

        //
        // Write the middle words...
        //
        for (int i = startIndex + 1; i < endIndex; ++i) {
            //
            // Write the middle word...
            //
            String currWord = words[i];
            numberOfWrittenCharacters = this.writeWord(currWord, result, insertIndex);

            if (numberOfWrittenCharacters != currWord.length()) {
                String errorMessage =
                    "TextAlignment: The middle word failed to get written to the result record.";

                throw new ProblemsException(errorMessage);
            }

            insertIndex += numberOfWrittenCharacters;

            //
            // Write the corresponding pad of the middle word...
            //
            padLength = this.calculatePadLength(middlePadLength, middlePadsReminderLength);

            numberOfWrittenCharacters = this.writePad(padLength, result, insertIndex);

            if (numberOfWrittenCharacters != padLength) {
                String errorMessage =
                    "TextAlignment: The middle pad failed to get written to the result record.";

                throw new ProblemsException(errorMessage);
            }

            insertIndex += numberOfWrittenCharacters;
        }

        //
        // Write the last word...
        //
        numberOfWrittenCharacters = this.writeWord(lastWord, result, insertIndex);

        if (numberOfWrittenCharacters != lastWord.length()) {
            String errorMessage =
                "TextAlignment: The last word failed to get written to the result record.";

            throw new ProblemsException(errorMessage);
        }

        insertIndex += numberOfWrittenCharacters;

        return insertIndex;
    }

    /**
     * Writes a last result record.
     */
    private int writeLastResultRecord(
        String[] words,
        int startIndex,
        int endIndex,
        char[] result) {

        if (startIndex > endIndex) {
            return 0;
        }

        int insertIndex = 0;
        int padLength = 1;
        int numberOfWrittenCharacters;

        //
        // Write the words with a pad of size 1...
        //
        for (int i = startIndex; i <= endIndex; ++i) {
            String currWord = words[i];

            //
            // Write the corresponding pad...
            //
            if (i > startIndex) {
                numberOfWrittenCharacters = this.writePad(padLength, result, insertIndex);

                if (numberOfWrittenCharacters != padLength) {
                    String errorMessage =
                        "TextAlignment: The current pad failed to get written to the last result record.";

                    throw new ProblemsException(errorMessage);
                }

                insertIndex += numberOfWrittenCharacters;
            }

            //
            // Write the corresponding word...
            //
            numberOfWrittenCharacters = this.writeWord(currWord, result, insertIndex);

            if (numberOfWrittenCharacters != currWord.length()) {
                String errorMessage =
                    "TextAlignment: The current word failed to get written to the last result record.";

                throw new ProblemsException(errorMessage);
            }

            insertIndex += numberOfWrittenCharacters;
        }

        //
        // Write pads to the reminder of the record...
        //
        int reminderPadLength = result.length - insertIndex;

        if (reminderPadLength > 0) {
            numberOfWrittenCharacters = this.writePad(reminderPadLength, result, insertIndex);

            if (numberOfWrittenCharacters != reminderPadLength) {
                String errorMessage =
                    "TextAlignment: The remainder pads failed to get written to the last result record.";

                throw new ProblemsException(errorMessage);
            }

            insertIndex += numberOfWrittenCharacters;
        }

        return insertIndex;
    }

    /**
     * Writes a word to a result buffer at specific index.
     * Returns the number of characters written.
     */
    private int writeWord(String word, char[] result, int index) {
        int numberOfCharactersWritten = 0;

        int currIndex = 0;
        int insertIndex = index;

        while (currIndex < word.length() && insertIndex < result.length) {
            char currValue = word.charAt(currIndex);

            result[insertIndex] = currValue;
            ++numberOfCharactersWritten;

            ++currIndex;
            ++insertIndex;
        }

        return numberOfCharactersWritten;
    }

    /**
     * Writes a pad to a result buffer at specific index.
     * Returns the number of characters written.
     */
    private int writePad(int padLength, char[] result, int index) {
        int numberOfCharactersWritten = 0;

        char padValue = ' ';

        int currIndex = 0;
        int insertIndex = index;

        while (currIndex < padLength && insertIndex < result.length) {
            result[insertIndex] = padValue;
            ++numberOfCharactersWritten;

            ++currIndex;
            ++insertIndex;
        }

        return numberOfCharactersWritten;
    }

    /**
     * Calculates the pad length.
     */
    private int calculatePadLength(int initialLength, MutableInteger reminderLength) {
        int padLength = initialLength;

        if (reminderLength.get() > 0) {
            ++padLength;
            reminderLength.decrement();
        }

        return padLength;
    }

    /**
     * Gets the length of the max string.
     */
    private static int getMaxStringLength(String[] strings) {
        int maxLength = 0;

        for (String str : strings) {
            if (str.length() > maxLength) {
                maxLength = str.length();
            }
        }

        return maxLength;
    }
}
