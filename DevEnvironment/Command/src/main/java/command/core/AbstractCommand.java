package command.core;

import base.core.Conditions;
import command.interfaces.ICommand;
import command.interfaces.ICommandMessageWriter;
import command.interfaces.ICommandParameters;
import command.interfaces.IParameterSet;
import command.interfaces.IProcessInformation;

/**
 * The AbstractCommand class implements an abstract command.
 */
public abstract class AbstractCommand implements ICommand {
    private IProcessInformation processInformation;
    private ICommandParameters parameters;
    private ICommandMessageWriter messageWriter;

    /**
     * The AbstractCommand constructor.
     */
    protected AbstractCommand() {
    }

    /**
     * Sets process information of a command.
     */
    @Override
    public void setProcessInformation(IProcessInformation processInformation) {
        Conditions.validateNotNull(
            processInformation,
            "The process information of the command.");

        this.processInformation = processInformation;
    }

    /**
     * Gets process information of a command.
     */
    public IProcessInformation getProcessInformation() {
        return this.processInformation;
    }

    /**
     * Sets parameters of a command.
     */
    @Override
    public void setParameters(ICommandParameters parameters) {
        Conditions.validateNotNull(
            parameters,
            "The parameters of the command.");

        this.parameters = parameters;
    }

    /**
     * Gets parameters of a command.
     */
    @Override
    public ICommandParameters getParameters() {
        return this.parameters;
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
