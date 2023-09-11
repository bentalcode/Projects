package cmakebuildsystem.interfaces;

import java.util.List;

/**
 * The ICMakeWriter interface defines a CMake Writer.
 */
public interface ICMakeWriter {
    /**
     * Writes code.
     */
    void write(String code);

    /**
     * Writes a new comment.
     */
    void writeComment(String comment);

    /**
     * Writes a new comment.
     */
    void writeComment(List<String> comments);

    /**
     * Writes a new line.
     */
    void newLine();

    /**
     * Performs a left indent.
     */
    void leftIndent();

    /**
     * Performs a right indent.
     */
    void rightIndent();
}
