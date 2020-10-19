package command.core;

import base.core.ColorType;
import base.core.Conditions;
import base.core.DestructorHandler;
import base.interfaces.IDestructorHandler;
import command.interfaces.ICommandManifest;
import command.interfaces.ICommandMessageWriter;
import java.io.Closeable;
import java.io.PrintWriter;

/**
 * The CommandMessageWriter class implements a writer of a command message.
 */
public final class CommandMessageWriter implements Closeable, ICommandMessageWriter {
    private final String usageMessage;
    private final PrintWriter informationalWriter;
    private final PrintWriter warningWriter;
    private final PrintWriter errorWriter;
    private final IDestructorHandler destructorHandler;

    /**
     * The CommandMessageWriter constructor.
     */
    public CommandMessageWriter(String usageMessage) {
        Conditions.validateNotNull(
            usageMessage,
            "The usage message of the command.");

        this.usageMessage = usageMessage;

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
     * Writes a usage message.
     */
    @Override
    public void writeUsageMessage() {
        this.writeInformationalMessage(this.usageMessage);
    }

    /**
     * Writes a usage message.
     */
    @Override
    public void writeUsageMessage(boolean status) {
        if (status) {
            this.writeInformationalMessage(this.usageMessage);
        }
        else {
            this.writeErrorMessage(this.usageMessage);
        }
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
