package json.core;

/**
 * The IJsonTokenizer interface defines a tokenizer for json.
 */
public interface IJsonTokenizer {
    /**
     * Gets the next token.
     * Returns null if no token is available
     */
    JsonToken next();

    /**
     * Gets the identifier of the current token.
     */
    int currentTokenId();

    /**
     * Gets the current name.
     */
    String currentName();

    /**
     * Gets the current string value.
     */
    String currentStringValue();

    /**
     * Gets the current long value.
     */
    long currentLongValue();

    /**
     * Gets the current double value.
     */
    double currentDoubleValue();
}
