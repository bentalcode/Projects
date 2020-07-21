package basicio.interfaces;

/**
 * The IHtmlParagraphParser interface defines a parser of html paragraph.
 */
public interface IHtmlParagraphParser {
    /**
     * Processes a paragraph.
     */
    void processParagraph(String content);

    /**
     * Gets the html statistics.
     */
    IHtmlStatistics getHtmlStatistics();
}
