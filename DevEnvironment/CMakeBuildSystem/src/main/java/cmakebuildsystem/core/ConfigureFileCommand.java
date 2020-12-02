package cmakebuildsystem.core;

import base.core.Conditions;
import cmakebuildsystem.interfaces.ICMakeBuildCommand;
import cmakebuildsystem.interfaces.ICMakeWriter;

/**
 * The ConfigureFileCommand class implements a configure file command of a CMake build.
 */
public final class ConfigureFileCommand extends CMakeBuildCommand {
    private final String targetFilePath;

    /**
     * Creates a new configure file command.
     */
    static ICMakeBuildCommand make(String sourceFilePath, String targetFilePath) {
        return new ConfigureFileCommand(
            sourceFilePath,
            targetFilePath);
    }

    /**
     * The ConfigureFileCommand constructor.
     */
    private ConfigureFileCommand(String sourceFilePath, String targetFilePath) {
        super(
            ICMakeListsConstants.configureFileCommand,
            sourceFilePath);

        this.targetFilePath = targetFilePath;
    }

    /**
     * Compiles a CMake build command.
     */
    @Override
    public void compile(
        ICMakeWriter writer,
        ICMakeBuildContextData contextData) {

        Conditions.validateNotNull(
            writer,
            "The CMake writer.");

        Conditions.validateNotNull(
            contextData,
            "The context data.");

        this.begin(writer);

        this.addParameter(writer, this.targetFilePath);

        this.end(writer);
    }
}
