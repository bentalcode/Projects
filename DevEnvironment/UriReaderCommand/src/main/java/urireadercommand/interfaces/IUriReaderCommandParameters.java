package urireadercommand.interfaces;

import java.util.Set;

/**
 * The IUriReaderCommandParameters interface defines parameters of an uri-reader command.
 */
public interface IUriReaderCommandParameters {
    /**
     * Gets an uri to read from.
     */
    String getUri();

    /**
     * Gets the number of mostly-used words.
     */
    int getNumberOfMostlyUsedWords();

    /**
     * Gets the excluded words.
     */
    Set<String> getExcludedWords();
}
