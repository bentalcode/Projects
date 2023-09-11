package command.core;

import command.interfaces.ICommandData;
import java.nio.file.Path;
import java.util.List;

/**
 * The CommandData class implements data of a command.
 */
public final class CommandData implements ICommandData {
    private final Path manifestResourcePath;
    private final List<String> commandLineStrings;

    /**
     * The CommandData constructor.
     */
    public CommandData(
        Path manifestResourcePath,
        List<String> commandLineStrings) {

        this.manifestResourcePath = manifestResourcePath;
        this.commandLineStrings = commandLineStrings;
    }

    /**
     * Gets the path of a manifest resource.
     */
    @Override
    public Path getManifestResourcePath() {
        return this.manifestResourcePath;
    }

    /**
     * Gets the command line strings.
     */
    @Override
    public List<String> getCommandlineStrings() {
        return this.commandLineStrings;
    }
}
