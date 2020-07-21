package cheadercommand.core;

import base.core.Conditions;
import base.core.Paths;
import cheadercommand.interfaces.ICHeaderCommandParameters;
import command.interfaces.ICommandParameters;
import command.interfaces.IParameter;
import java.nio.file.Path;

/**
 * The CHeaderCommandParameters class implements parameters of a c-header command.
 */
public final class CHeaderCommandParameters implements ICHeaderCommandParameters {
    private final Path directoryPath;
    private final Path filePath;
    private final boolean recurse;

    /**
     * The CHeaderCommandParameters constructor.
     */
    public CHeaderCommandParameters(ICommandParameters parameters) {
        Conditions.validateNotNull(
            parameters,
            "The parameters of the command.");

        IParameter directoryPath = parameters.getParameterSet().getParameter("directoryPath");
        this.directoryPath = directoryPath != null && directoryPath.isSet() ?
            Paths.create(directoryPath.getStringValue()) : null;

        IParameter filePath = parameters.getParameterSet().getParameter("filePath");
        this.filePath = filePath != null && filePath.isSet() ?
            Paths.create(filePath.getStringValue()) : null;

        IParameter recurse = parameters.getParameterSet().getParameter("recurse");
        this.recurse = recurse != null && recurse.isSet() ?
            recurse.getBooleanValue() : false;
    }

    /**
     * Gets the path of a directory.
     */
    @Override
    public Path getDirectoryPath() {
        return this.directoryPath;
    }

    /**
     * Gets the path of a file.
     */
    @Override
    public Path getFilePath() {
        return this.filePath;
    }

    /**
     * Gets the recursive flag.
     */
    @Override
    public boolean recurse() {
        return this.recurse;
    }
}
