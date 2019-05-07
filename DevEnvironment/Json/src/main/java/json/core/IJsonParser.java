package json.core;

/**
 * The IJsonParser interface defines a json parser.
 */
public interface IJsonParser {
    /**
     * Parses a json into a tree.
     */
    IJsonTree parse();
}
