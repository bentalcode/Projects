package command.core;

import command.interfaces.IParsingResult;

/**
 * The ParsingResult class implements a parsing result.
 */
public final class ParsingResult<T> implements IParsingResult<T> {
    private final boolean status;
    private final T result;
    private final String errorMessage;

    /**
     * Creates a successful result.
     */
    public static <T> IParsingResult<T> successfulResult(T result) {
        return new ParsingResult<>(true, result, null);
    }

    /**
     * Creates a failure result.
     */
    public static <T> IParsingResult<T> failureResult(String errorMessage) {
        return new ParsingResult<>(false, null, errorMessage);
    }

    /**
     * Creates a failure result from a previous one.
     */
    public static <T1, T2> IParsingResult<T2> failureResult(IParsingResult<T1> result) {
        return new ParsingResult<>(false, null, result.getErrorMessage());
    }

    /**
     * The ParsingResult constructor.
     */
    private ParsingResult(
        boolean status,
        T result,
        String errorMessage) {

        this.status = status;
        this.result = result;
        this.errorMessage = errorMessage;
    }

    /**
     * Returns if the parsing process succeeded.
     */
    @Override
    public boolean succeeded() {
        return this.status;
    }

    /**
     * Returns if the parsing process failed.
     */
    @Override
    public boolean failed() {
        return !this.status;
    }

    /**
     * Gets a status of the parsing process.
     */
    @Override
    public boolean getStatus() {
        return this.status;
    }

    /**
     * Gets a result of the parsing process.
     */
    @Override
    public T getResult() {
        return this.result;
    }

    /**
     * Gets an error message of the parsing process.
     */
    @Override
    public String getErrorMessage() {
        return this.errorMessage;
    }
}
