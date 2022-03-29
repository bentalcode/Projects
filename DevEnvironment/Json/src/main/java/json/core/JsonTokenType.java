package json.core;

/**
 * The JsonTokenType enum defines the various types of a json token.
 */
public enum JsonTokenType {
    /**
     * NOT_AVAILABLE can be returned if JsonParser
     * implementation can not currently return the requested
     * token (usually next one), or even if any will be
     * available, but that may be able to determine this in the future.
     * This is the case with non-blocking parsers --
     * they can not block to wait for more data to parse and
     * must return something.
     */
    NOT_AVAILABLE,

    /**
     * START_OBJECT is returned when encountering "{"
     * which signals starting of an Object value.
     */
    START_OBJECT,

    /**
     * END_OBJECT is returned when encountering "}"
     * which signals ending of an Object value
     */
    END_OBJECT,

    /**
     * START_ARRAY is returned when encountering '['
     * which signals starting of an Array value
     */
    START_ARRAY,

    /**
     * END_ARRAY is returned when encountering ']'
     * which signals ending of an Array value
     */
    END_ARRAY,

    /**
     * FIELD_NAME is returned when a String token is encountered
     * as a field name (same lexical value, different function)
     */
    FIELD_NAME,

    /**
     * VALUE_STRING is returned when a String token is encountered
     * in value context (array element, field value, or root-level
     * stand-alone value)
     */
    VALUE_STRING,

    /**
     * Placeholder token returned when the input source has a concept
     * of embedded Object that are not accessible as usual structure
     * (of starting with {@link #START_OBJECT}, having values, ending with
     * {@link #END_OBJECT}), but as "raw" objects.
     * <p>
     * Note: this token is never returned by regular JSON readers, but
     * only by readers that expose other kinds of source (like
     * <code>JsonNode</code>-based JSON trees, Maps, Lists and such).
     */
    VALUE_EMBEDDED_OBJECT,

    /**
     * VALUE_NUMBER_INTEGER is returned when an integer numeric token is
     * encountered in value context: that is, a number that does
     * not have floating point or exponent marker in it (consists
     * only of an optional sign, followed by one or more digits;
     * or, for binary formats, is indicated as integral number
     * by internal representation).
     */
    VALUE_NUMBER_INTEGER,

    /**
     * VALUE_NUMBER_FLOAT is returned when a numeric token other
     * than integer is encountered: that is, a number that does
     * have floating point or exponent marker in it, in addition
     * to one or more digits (or, for non-textual formats,
     * has internal floating-point representation).
     */
    VALUE_NUMBER_DOUBLE,

    /**
     * VALUE_TRUE is returned when encountering literal "true" in
     * value context
     */
    VALUE_TRUE,

    /**
     * VALUE_NULL is returned when encountering literal "null" in
     * value context
     */
    VALUE_FALSE,

    /**
     * VALUE_NULL is returned when encountering literal "null" in
     * value context
     */
    VALUE_NULL
}
