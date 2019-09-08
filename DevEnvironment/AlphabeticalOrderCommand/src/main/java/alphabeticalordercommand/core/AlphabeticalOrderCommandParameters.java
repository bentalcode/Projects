package alphabeticalordercommand.core;

import alphabeticalordercommand.interfaces.IAlphabeticalOrderCommandParameters;
import base.core.Conditions;

/**
 * The AlphabeticalOrderCommandParameters class implements parameters of an alphabetical order command.
 */
public final class AlphabeticalOrderCommandParameters implements IAlphabeticalOrderCommandParameters {
    private final String dataPath;

    /**
     * The AlphabeticalOrderCommandParameters constructor.
     */
    public AlphabeticalOrderCommandParameters(String dataPath) {
        Conditions.validateStringNotNullOrEmpty(
            dataPath,
            "The path of data.");

        this.dataPath = dataPath;
    }

    /**
     * Gets a path of the data.
     */
    @Override
    public String getDataPath() {
        return this.dataPath;
    }
}
