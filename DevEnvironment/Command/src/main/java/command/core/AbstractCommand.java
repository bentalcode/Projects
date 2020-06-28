package command.core;

import base.core.Conditions;
import command.interfaces.ICommand;
import command.interfaces.ICommandInformation;
import command.interfaces.ICommandMessageWriter;

/**
 * The AbstractCommand class implements an abstract command.
 */
public abstract class AbstractCommand implements ICommand {
    private ICommandInformation commandInformation;
    private ICommandMessageWriter messageWriter;

    /**
     * The AbstractCommand constructor.
     */
    protected AbstractCommand() {
    }

    /**
     * Sets information of a command.
     */
    @Override
    public void setInformation(ICommandInformation commandInformation) {
        Conditions.validateNotNull(
            commandInformation,
            "The information of a command.");

        this.commandInformation = commandInformation;
    }

    /**
     * Gets information of a command.
     */
    @Override
    public ICommandInformation getInformation() {
        return this.commandInformation;
    }

    /**
     * Sets a message writer of a command.
     */
    @Override
    public void setMessageWriter(ICommandMessageWriter messageWriter) {
        Conditions.validateNotNull(
            messageWriter,
            "The message writer of a command.");

        this.messageWriter = messageWriter;
    }

    /**
     * Gets a message writer of a command.
     */
    @Override
    public ICommandMessageWriter getMessageWriter() {
        return this.messageWriter;
    }
}
