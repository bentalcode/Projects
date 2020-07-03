package basicio.interfaces;

/**
 * The ILineReader interface defines a line reader.
 */
public interface ILineReader extends IReader<String> {
    /**
     * Gets the number of current line.
     */
    long currentLineNumber();

    /**
     * Gets the start position of current line.
     */
    long currentLineStartPosition();

    /**
     * Gets the end position of current line.
     */
    long currentLineEndPosition();
}
