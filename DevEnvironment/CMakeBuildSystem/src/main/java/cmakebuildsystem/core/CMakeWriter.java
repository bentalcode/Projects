package cmakebuildsystem.core;

import base.core.ArrayLists;
import base.core.Conditions;
import base.core.Writers;
import cmakebuildsystem.interfaces.ICMakeWriter;
import cmakebuildsystem.interfaces.IEditorSettings;
import java.io.Writer;
import java.util.List;

/**
 * The CMakeWriter class implements a writer of a CMake build.
 */
public final class CMakeWriter implements ICMakeWriter {
    private final Writer writer;
    private final IEditorSettings editorSettings;
    private int indentationSize;

    /**
     * The CMakeWriter constructor.
     */
    public CMakeWriter(
        Writer writer,
        IEditorSettings editorSettings) {

        Conditions.validateNotNull(
            writer,
            "The writer.");

        Conditions.validateNotNull(
            editorSettings,
            "The editor settings.");

        this.writer = writer;
        this.editorSettings = editorSettings;
    }

    /**
     * Writes code.
     */
    @Override
    public void write(String code) {
        String indentation = this.createIndentation();
        String section = indentation + code;

        Writers.write(this.writer, section);
        Writers.write(this.writer, "\n");
    }

    /**
     * Writes a new comment.
     */
    @Override
    public void writeComment(String comment) {
        this.writeComment(ArrayLists.make(comment));
    }

    /**
     * Writes a new comment.
     */
    @Override
    public void writeComment(List<String> comments) {
        Conditions.validateNotNull(
            comments,
            "The comments.");

        StringBuilder commentBuilder = new StringBuilder();
        commentBuilder.append("#").append("\n");

        for (String comment : comments) {
            commentBuilder.append("#").append(" ").append(comment).append("\n");
        }

        commentBuilder.append("#").append("\n");

        Writers.write(this.writer, commentBuilder.toString());
    }

    /**
     * Writes a new line.
     */
    @Override
    public void newLine() {
        Writers.write(this.writer, "\n");
    }

    /**
     * Performs a left indent.
     */
    @Override
    public void leftIndent() {
        this.indentationSize -= this.editorSettings.getTabSize();
        assert(this.indentationSize >= 0);
    }

    /**
     * Performs a right indent.
     */
    @Override
    public void rightIndent() {
        this.indentationSize += this.editorSettings.getTabSize();
    }

    /**
     * Creates an indentation string.
     */
    private String createIndentation() {
        if (this.indentationSize == 0) {
            return "";
        }

        char[] buffer = new char[this.indentationSize];
        for (int i = 0; i < this.indentationSize; ++i) {
            buffer[i] = ' ';
        }

        return new String(buffer);
    }
}
