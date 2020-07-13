package hashcodecommand.core;

import base.core.Conditions;
import base.core.Paths;
import hashcodecommand.interfaces.IHashCodeParameters;
import command.interfaces.ICommandParameters;
import command.interfaces.IParameter;
import java.nio.file.Path;

/**
 * The HashCodeCommandParameters class implements parameters of a hashcode command.
 */
public final class HashCodeCommandParameters implements IHashCodeParameters {
    private final ICommandParameters parameters;
    private final Path directoryPath;
    private final Path filePath;
    private final int initialPrime;
    private final boolean recurse;

    /**
     * The HashCodeCommandParameters constructor.
     */
    public HashCodeCommandParameters(ICommandParameters parameters) {
        Conditions.validateNotNull(
            parameters,
            "The parameters of the command.");

        this.parameters = parameters;

        IParameter directoryPath = parameters.getParameterSet().getParameter("directoryPath");
        this.directoryPath = directoryPath != null && directoryPath.isSet() ?
            Paths.create(directoryPath.getStringValue()) : null;

        IParameter filePath = parameters.getParameterSet().getParameter("filePath");
        this.filePath = filePath != null && filePath.isSet() ?
            Paths.create(filePath.getStringValue()) : null;

        IParameter initialPrime = parameters.getParameterSet().getParameter("initialPrime");
        this.initialPrime = initialPrime != null && initialPrime.isSet() ?
            initialPrime.getIntegerValue() : 2;

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
     * Gets the initial prime number.
     */
    @Override
    public int getInitialPrime() {
        return this.initialPrime;
    }

    /**
     * Gets the recursive flag.
     */
    @Override
    public boolean recurse() {
        return this.recurse;
    }
}
