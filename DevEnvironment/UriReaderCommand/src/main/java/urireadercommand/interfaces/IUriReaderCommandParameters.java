package urireadercommand.interfaces;

import java.util.Set;

/**
 * The IUriReaderCommandParameters interface defines parameters of a uri-reader command.
 */
public interface IUriReaderCommandParameters {
    /**
     * Gets a uri to read from.
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
