package base.core;

import base.interfaces.IDestructorHandler;
import base.interfaces.IMessageWriter;
import java.io.Closeable;
import java.io.PrintWriter;

/**
 * The MessageWriter class implements a writer of messages.
 */
public final class MessageWriter implements Closeable, IMessageWriter {
    private final PrintWriter informationalWriter;
    private final PrintWriter warningWriter;
    private final PrintWriter errorWriter;
    private final IDestructorHandler destructorHandler;

    /**
     * The MessageWriter constructor.
     */
    public MessageWriter() {
        try (DestructorHandler destructorHandler = new DestructorHandler()) {
            PrintWriter informationalWriter = new PrintWriter(System.out);
            destructorHandler.register(informationalWriter);
            PrintWriter warningWriter = new PrintWriter(System.err);
            destructorHandler.register(warningWriter);
            PrintWriter errorWriter = new PrintWriter(System.err);
            destructorHandler.register(errorWriter);

            this.destructorHandler = destructorHandler.move();

            this.informationalWriter = informationalWriter;
            this.warningWriter = warningWriter;
            this.errorWriter = errorWriter;
        }
    }

    /**
     * Closes this resource.
     */
    @Override
    public void close() {
        this.destructorHandler.close();
    }

    /**
     * Writes an informational message.
     */
    @Override
    public void writeInformationalMessage(String message) {
        this.writeMessage(
            this.informationalWriter,
            ColorType.GREEN + message);
    }

    /**
     * Writes a warning message.
     */
    @Override
    public void writeWarningMessage(String message) {
        this.writeMessage(
            this.warningWriter,
            ColorType.YELLOW + message);
    }

    /**
     * Writes an error message.
     */
    @Override
    public void writeErrorMessage(String message) {
        this.writeMessage(
            this.errorWriter,
            ColorType.RED + message);
    }

    /**
     * Gets an error writer.
     */
    @Override
    public PrintWriter getErrorWriter() {
        return this.errorWriter;
    }

    /**
     * Gets a warning writer.
     */
    @Override
    public PrintWriter getWarningWriter() {
        return this.warningWriter;
    }

    /**
     * Gets an informational writer.
     */
    @Override
    public PrintWriter getInformationalWriter() {
        return this.informationalWriter;
    }

    /**
     * Writes a message to an output stream.
     */
    private void writeMessage(PrintWriter writer, String message) {
        writer.println(message);
        writer.flush();
    }
}
