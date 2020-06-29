package base.interfaces;

/**
 * The IParsingResult interface defines a parsing result.
 */
public interface IParsingResult<T> {
    /**
     * Returns if the parsing process succeeded.
     */
    boolean succeeded();

    /**
     * Returns if the parsing process failed.
     */
    boolean failed();

    /**
     * Gets a status of the parsing process.
     */
    boolean getStatus();

    /**
     * Gets a result of the parsing process.
     */
    T getResult();

    /**
     * Gets an error message of the parsing process.
     */
    String getErrorMessage();
}
