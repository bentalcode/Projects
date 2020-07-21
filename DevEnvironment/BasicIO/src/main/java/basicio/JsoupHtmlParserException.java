package basicio;

/**
 * The JsoupHtmlParserException class captures errors in the jsoup html parser module.
 */
public class JsoupHtmlParserException extends BasicIOException {
    /**
     * The JsoupHtmlParserException constructor.
     */
    public JsoupHtmlParserException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The JsoupHtmlParserException constructor.
     */
    public JsoupHtmlParserException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
