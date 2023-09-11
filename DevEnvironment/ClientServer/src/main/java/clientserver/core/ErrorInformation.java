package clientserver.core;

import base.core.ClassTypes;
import base.core.Conditions;
import clientserver.interfaces.IErrorInformation;
import json.core.JsonObjectStream;
import json.interfaces.IJsonObjectReader;
import json.interfaces.IJsonObjectWriter;
import java.util.Date;

/**
 * The ErrorInformation class implements an error information.
 */
public final class ErrorInformation implements IErrorInformation {
    private static final String PROPERTY_EXCEPTION_TYPE = "exceptionType";
    private static final String PROPERTY_EXCEPTION_MESSAGE = "exceptionMessage";
    private static final String PROPERTY_TIME = "time";

    private final Exception exception;
    private final Date time;

    /**
     * Creates a new error information.
     */
    public static IErrorInformation create(Exception exception) {
        Date currentTime = new Date();
        return new ErrorInformation(exception, currentTime);
    }

    /**
     * The ErrorInformation constructor.
     */
    private ErrorInformation(
        Exception exception,
        Date time) {

        Conditions.validateNotNull(
            exception,
            "The exception of the error.");

        Conditions.validateNotNull(
            time,
            "The time of the error.");

        this.exception = exception;
        this.time = time;
    }

    /**
     * Gets an exception to the error.
     */
    @Override
    public Exception getException() {
        return this.exception;
    }

    /**
     * Gets the time in which the error occurs.
     */
    @Override
    public Date getTime() {
        return this.time;
    }

    /**
     * Gets string representation of this instance.
     */
    @Override
    public String toString() {
        return JsonObjectStream.serialize(this);
    }

    /**
     * Writes an object to a json writer.
     */
    @Override
    public void writeJson(IJsonObjectWriter writer) {
        writer.writeStringProperty(ErrorInformation.PROPERTY_EXCEPTION_TYPE, ClassTypes.getName(this.exception));
        writer.writeStringProperty(ErrorInformation.PROPERTY_EXCEPTION_MESSAGE, this.exception.getMessage());
        writer.writeDateProperty(ErrorInformation.PROPERTY_TIME, this.getTime());
    }

    /**
     * Reads an object from a json reader.
     */
    public static IErrorInformation readJson(IJsonObjectReader reader) {
        String exceptionMessage = reader.readStringProperty(ErrorInformation.PROPERTY_EXCEPTION_MESSAGE);
        Date date = reader.readDateProperty(ErrorInformation.PROPERTY_TIME);

        CircuitBreakerException exception = new CircuitBreakerException(exceptionMessage);
        return new ErrorInformation(
            exception,
            date);
    }
}
