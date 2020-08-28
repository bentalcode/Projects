package urireadercommand.core;

import base.core.Conditions;
import base.core.TreeSets;
import command.interfaces.ICommandParameters;
import command.interfaces.IParameter;
import urireadercommand.interfaces.IUriReaderCommandParameters;
import java.util.Set;

/**
 * The UriReaderCommandParameters class implements parameters of a uri reader command.
 */
public final class UriReaderCommandParameters implements IUriReaderCommandParameters {
    private final String uri;
    private final int numberOfMostlyUsedWords;
    private final Set<String> excludedWords;

    /**
     * The UriReaderCommandParameters constructor.
     */
    public UriReaderCommandParameters(ICommandParameters parameters) {
        Conditions.validateNotNull(
            parameters,
            "The parameters of the command.");

        IParameter uriParameter = parameters.getParameterSet().getParameter("uri");
        this.uri = uriParameter.getStringValue();

        IParameter mostlyUsedWordsParameter = parameters.getParameterSet().getParameter("mostlyUsedWords");
        this.numberOfMostlyUsedWords = mostlyUsedWordsParameter != null && mostlyUsedWordsParameter.isSet() ?
            mostlyUsedWordsParameter.getIntegerValue() : 10;

        IParameter excludedWordsParameter = parameters.getParameterSet().getParameter("excludedWords");
        this.excludedWords = TreeSets.make(excludedWordsParameter != null && excludedWordsParameter.isSet() ?
            excludedWordsParameter.getStringArrayValue() : null);
    }

    /**
     * Gets a uri to read from.
     */
    @Override
    public String getUri() {
        return this.uri;
    }

    /**
     * Gets the number of mostly-used words.
     */
    @Override
    public int getNumberOfMostlyUsedWords() {
        return this.numberOfMostlyUsedWords;
    }

    /**
     * Gets the excluded words.
     */
    public Set<String> getExcludedWords() {
        return this.excludedWords;
    }
}
