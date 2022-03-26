package command.core;

import base.BaseException;
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
    private final ICommandMessageWriter commandMessageWriter;
    private final IDestructorHandler destructorHandler = new DestructorHandler();

    /**
     * The CommandHandler constructor.
     */
    public CommandHandler() {
        this(loadManifest());
    }

    /**
     * The CommandHandler constructor.
     */
    public CommandHandler(ICommandManifest manifest) {
        Conditions.validateNotNull(
            manifest,
            "The manifest of the command");

        CommandMessageWriter commandMessageWriter = new CommandMessageWriter(manifest.getHelpMetadata().getUsageMessage());
        this.destructorHandler.register(commandMessageWriter);

        this.manifest = manifest;
        this.commandMessageWriter = commandMessageWriter;
    }

    /**
     * Closes this resource.
     */
    @Override
    public void close() {
        this.destructorHandler.close();
    }

    /**
     * Runs a command and returns the exit status.
     */
    @Override
    public int run(ICommand command, String[] arguments) {
        int exitStatus = 0;

        try {
            if(!this.runCommand(command, arguments)) {
                String errorMessage =
                    "The command: " + this.manifest.getName() +
                    " has failed to run, Exit Status: -1";

                this.commandMessageWriter.getMessageWriter().writeErrorMessage(errorMessage);

                exitStatus = -1;
            }
        }
        catch (BaseException e) {
            String errorMessage =
                "The command: " + this.manifest.getName() +
                " has failed to run due to runtime error: " + e.getMessage() +
                ", Exit Status: -1";

            this.commandMessageWriter.getMessageWriter().writeErrorMessage(errorMessage);
            exitStatus = -1;
        }
        catch (Exception e) {
            String errorMessage =
                "The command: " + this.manifest.getName() +
                " has failed to run due to an en-expected error: " + e.getMessage() +
                ", Exit Status: -1";

            this.commandMessageWriter.getMessageWriter().writeErrorMessage(errorMessage);

            exitStatus = -1;
        }

        return exitStatus;
    }

    /**
     * Runs a command.
     *
     * Returns true if running the command successfully.
     * Returns false if failing to run the command.
     */
    private boolean runCommand(ICommand command, String[] arguments) {
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

        if (parametersResult.failed() || isHelpCommand(parametersResult.getResult())) {

            if (parametersResult.failed()) {
                String errorMessage =
                    "The command: " + this.manifest.getName() +
                    " has failed to parse the parameters due to parsing error: " + parametersResult.getErrorMessage() +
                    ", Exit Status: 0";

                this.commandMessageWriter.getMessageWriter().writeErrorMessage(errorMessage);
            }

            this.commandMessageWriter.writeUsageMessage(parametersResult.getStatus());

            return parametersResult.getStatus();
        }

        //
        // Set the information of the command...
        //
        command.setProcessInformation(processInformation);
        command.setParameters(parametersResult.getResult());

        command.setMessageWriter(this.commandMessageWriter.getMessageWriter());

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
        Path path = CommandConstants.defaultManifestPath;
        String json = ResourceReader.loadString(path);
        return CommandManifest.fromJson(json);
    }

    /**
     * Checks whether this is a help command.
     */
    private static boolean isHelpCommand(ICommandParameters parameters) {
        return parameters.getParameterSet().getIndex() == CommandHelpMetadata.HELP_PARAMETER_SET_INDEX;
    }
}
