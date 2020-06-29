package command.core;

import base.core.Conditions;
import base.core.ResourceReader;
import base.interfaces.IParser;
import command.interfaces.ICommand;
import command.interfaces.ICommandHandler;
import command.interfaces.ICommandManifest;
import command.interfaces.ICommandMessageWriter;
import command.interfaces.ICommandParameters;
import base.interfaces.IParsingResult;
import command.interfaces.IProcessInformation;
import java.nio.file.Path;

/**
 * The CommandHandler class implements a command handler for running commands.
 */
public final class CommandHandler implements ICommandHandler {
    private final ICommandManifest manifest;
    private final ICommandMessageWriter messageWriter;

    /**
     * The CommandHandler constructor.
     */
    public CommandHandler() {
        this.manifest = this.loadManifest();
        this.messageWriter = new CommandMessageWriter(this.manifest);
    }

    /**
     * Runs a command.
     *
     * Returns true if running the command successfully.
     * Returns false if failing to run the command.
     */
    @Override
    public boolean run(ICommand command, String[] arguments) {
        Conditions.validateNotNull(
            command,
            "The command to run.");

        Conditions.validateNotNull(
            arguments,
            "The arguments of a command.");

        //
        // Get the process information of the command...
        //
        IProcessInformation processInformation = ProcessInformation.current();

        //
        // Parse parameters of the command...
        //
        IParsingResult<ICommandParameters> parametersResult = this.parseParameters(arguments);

        if (parametersResult.failed()) {
            this.messageWriter.writeUsageMessage();
            return false;
        }

        //
        // Set the information of the command...
        //
        command.setInformation(new CommandInformation(
            processInformation,
            parametersResult.getResult()));

        command.setMessageWriter(this.messageWriter);

        //
        // Run the logic of the command...
        //
        command.run();

        return true;
    }

    /**
     * Parses the parameters of a command.
     */
    private IParsingResult<ICommandParameters> parseParameters(String[] arguments) {
        IParser<String[], ICommandParameters> parser = new CommandParser(this.manifest);

        IParsingResult<ICommandParameters> result = parser.parse(arguments);

        return result;
    }

    /**
     * Loads the manifest of the command.
     */
    private ICommandManifest loadManifest() {
        Path path = ICommandConstants.defaultManifestPath;
        String json = ResourceReader.loadString(path);
        return CommandManifest.fromJson(json);
    }
}
