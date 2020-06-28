package command.core;

import base.core.Conditions;
import command.interfaces.ICommandManifest;
import command.interfaces.ICommandMessageWriter;
import java.io.PrintStream;

/**
 * The CommandMessageWriter class implements a writer of a command message.
 */
public final class CommandMessageWriter implements ICommandMessageWriter {
    private final ICommandManifest manifest;

    /**
     * The CommandMessageWriter constructor.
     */
    public CommandMessageWriter(ICommandManifest manifest) {
        Conditions.validateNotNull(
            manifest,
            "The manifest of a command.");

        this.manifest = manifest;
    }

    /**
     * Writes a usage message.
     */
    @Override
    public void writeUsageMessage() {
        String usageMessage = this.manifest.getHelpMessage();
        this.writeInformationalMessage(usageMessage);
    }

    /**
     * Writes an informational message.
     */
    @Override
    public void writeInformationalMessage(String message) {
        PrintStream outputStream = System.out;
        writeMessage(message, outputStream);
    }

    /**
     * Writes a warning message.
     */
    @Override
    public void writeWarningMessage(String message) {
        PrintStream outputStream = System.err;
        writeMessage(message, outputStream);
    }

    /**
     * Writes an error message.
     */
    @Override
    public void writeErrorMessage(String message) {
        PrintStream outputStream = System.err;
        writeMessage(message, outputStream);
    }

    /**
     * Writes a message to an output stream.
     */
    private void writeMessage(String message, PrintStream outputStream) {
        outputStream.println(message);
        outputStream.flush();
    }
}
