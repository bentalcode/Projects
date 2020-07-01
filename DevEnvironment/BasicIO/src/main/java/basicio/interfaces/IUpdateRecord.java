package basicio.interfaces;

/**
 * The IUpdateRecord interface defines an update record.
 */
public interface IUpdateRecord {
    /**
     * Gets the matching regex.
     */
    String getMatchingRegex();

    /**
     * Gets the new content.
     */
    String getNewContent();
}
