package command.core;

import base.core.Conditions;
import command.interfaces.ICommandInformation;
import command.interfaces.ICommandParameters;
import command.interfaces.IProcessInformation;

/**
 * The CommandInformation class implements information of a command.
 */
public final class CommandInformation implements ICommandInformation {
    private final IProcessInformation processInformation;
    private final ICommandParameters parameters;

    /**
     * The CommandInformation constructor
     */
    public CommandInformation(
        IProcessInformation processInformation,
        ICommandParameters parameters) {

        Conditions.validateNotNull(
            processInformation,
            "The process information of the command.");

        Conditions.validateNotNull(
            parameters,
            "The parameters of the command.");

        this.processInformation = processInformation;
        this.parameters = parameters;
    }

    /**
     * Gets the process information.
     */
    @Override
    public IProcessInformation getProcessInformation() {
        return this.processInformation;
    }

    /**
     * Gets the parameters of the command.
     */
    @Override
    public ICommandParameters getParameters() {
        return this.parameters;
    }
}
