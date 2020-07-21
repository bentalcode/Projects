package basicio.interfaces;

/**
 * The IParagraphReader interface defines a paragraph reader.
 */
public interface IParagraphReader extends IReader<String> {
    /**
     * Gets the number of paragraph (Starting from 1).
     */
    int currentParagraphNumber();
}
