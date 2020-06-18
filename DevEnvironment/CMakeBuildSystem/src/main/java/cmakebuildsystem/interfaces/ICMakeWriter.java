package cmakebuildsystem.interfaces;

/**
 * The ICMakeWriter interface defines a CMake Writer.
 */
public interface ICMakeWriter {
    /**
     * Writes code.
     */
    void write(String code);

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
