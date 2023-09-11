package command.core;

import base.core.Conditions;
import base.core.DestructorHandler;
import base.core.MessageWriter;
import base.interfaces.IDestructorHandler;
import base.interfaces.IMessageWriter;
import command.interfaces.ICommandMessageWriter;
import java.io.Closeable;

/**
 * The CommandMessageWriter class implements a writer of a command message.
 */
public final class CommandMessageWriter implements Closeable, ICommandMessageWriter {
    private final String usageMessage;
    private final MessageWriter messageWriter;
    private final IDestructorHandler destructorHandler = new DestructorHandler();

    /**
     * The CommandMessageWriter constructor.
     */
    public CommandMessageWriter(String usageMessage) {
        Conditions.validateNotNull(
            usageMessage,
            "The usage message of the command.");

        this.usageMessage = usageMessage;
        this.messageWriter = new MessageWriter();
        this.destructorHandler.register(this.messageWriter);
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
        this.messageWriter.writeInformationalMessage(this.usageMessage);
    }

    /**
     * Writes a usage message.
     */
    @Override
    public void writeUsageMessage(boolean status) {
        if (status) {
            this.messageWriter.writeInformationalMessage(this.usageMessage);
        }
        else {
            this.messageWriter.writeErrorMessage(this.usageMessage);
        }
    }

    /**
     * Gets the message writer.
     */
    @Override
    public IMessageWriter getMessageWriter() {
        return this.messageWriter;
    }
}
