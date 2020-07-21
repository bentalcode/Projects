package basicio.core;

import base.core.Conditions;
import basicio.JsoupHtmlParserException;
import java.io.IOException;
import org.jsoup.Connection;
import org.jsoup.nodes.Document;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The JsoupHtmlParserApi class implements complementary APIs for jsop html parser module.
 */
public final class JsoupHtmlParserApi {
    private static final Logger log = LoggerFactory.getLogger(JsoupHtmlParserApi.class);

    /**
     * Creates a new Connection to a URL
     */
    public static Document getDocument(Connection connection) {
        Conditions.validateNotNull(
            connection,
            "The connection.");

        Document document;

        try {
            document = connection.get();
        }
        catch (IOException e) {
            String errorMessage =
                "Failed to get document of connection: " + connection +
                " due to the following error: " + e.getMessage();

            log.error(errorMessage, e);
            throw new JsoupHtmlParserException(errorMessage, e);
        }

        return document;
    }

    /**
     * Disables the default constructor - This is a static class.
     */
    private JsoupHtmlParserApi() {
    }
}
