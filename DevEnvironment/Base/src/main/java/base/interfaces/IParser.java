package base.interfaces;

/**
 * The IParser interface defines a generic parser.
 */
public interface IParser<T, TResult> {
    /**
     * Parses an object.
     */
    IParsingResult<TResult> parse(T obj);
}
