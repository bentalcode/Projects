package command.core;

import base.core.Conditions;
import base.core.DestructorHandler;
import base.core.ResourceReader;
import base.interfaces.IDestructorHandler;
import base.interfaces.IParser;
import base.interfaces.IParsingResult;
import command.interfaces.ICommand;
import command.interfaces.ICommandHandler;
import command.interfaces.ICommandManifest;
import command.interfaces.ICommandMessageWriter;
import command.interfaces.ICommandParameters;
import command.interfaces.IProcessInformation;
import java.io.Closeable;
import java.nio.file.Path;

/**
 * The CommandHandler class implements a command handler for running commands.
 */
public final class CommandHandler implements Closeable, ICommandHandler {
    private final ICommandManifest manifest;
    private final ICommandMessageWriter messageWriter;
    private final IDestructorHandler destructorHandler = new DestructorHandler();

    /**
     * The CommandHandler constructor.
     */
    public CommandHandler() {
        ICommandManifest manifest = loadManifest();

        CommandMessageWriter commandMessageWriter = new CommandMessageWriter(manifest);
        this.destructorHandler.register(commandMessageWriter);

        this.manifest = manifest;
        this.messageWriter = commandMessageWriter;
    }

    /**
     * Closes this resource.
     */
    @Override
    public void close() {
        this.destructorHandler.close();
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
    private static ICommandManifest loadManifest() {
        Path path = ICommandConstants.defaultManifestPath;
        String json = ResourceReader.loadString(path);
        return CommandManifest.fromJson(json);
    }
}
