package basicio.core;

import base.core.Conditions;
import basicio.interfaces.IParagraphReader;
import org.jsoup.Connection;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

/**
 * The HtmlParagraphReader class implements a reader of html paragraphs.
 */
public final class HtmlParagraphReader implements IParagraphReader {
    private final String uri;
    private Elements paragraphs;
    private int paragraphIndex;

    /**
     * The HtmlParagraphReader constructor.
     */
    public HtmlParagraphReader(String uri) {
        Conditions.validateStringNotNullOrEmpty(
            uri,
            "The uri to read from.");

        this.uri = uri;

        this.reset();
    }

    /**
     * Checks whether there is a next element.
     */
    @Override
    public boolean hasNext() {
        return this.paragraphIndex < this.paragraphs.size();
    }

    /**
     * Gets the next element.
     */
    @Override
    public String next() {
        assert(this.hasNext());
        Element currParagraphElement = this.paragraphs.get(this.paragraphIndex);
        String currParagraph = currParagraphElement.wholeText();

        ++this.paragraphIndex;

        return currParagraph;
    }

    /**
     * Gets the number of paragraph (Starting from 1).
     */
    @Override
    public int currentParagraphNumber() {
        return this.paragraphIndex + 1;
    }

    /**
     * Resets the reader.
     */
    private void reset() {
        Connection connection = Jsoup.connect(this.uri);
        Document document = JsoupHtmlParserApi.getDocument(connection);

        this.paragraphs = document.select("p");
        this.paragraphIndex = 0;
    }
}
