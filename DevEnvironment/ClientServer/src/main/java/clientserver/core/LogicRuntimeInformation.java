package clientserver.core;

import base.core.Conditions;
import clientserver.interfaces.IErrorInformation;
import clientserver.interfaces.ILogicRuntimeInformation;
import json.core.JsonObjectStream;
import json.interfaces.IJsonObjectReader;
import json.interfaces.IJsonObjectWriter;
import java.util.Date;

/**
 * The LogicRuntimeInformation class implements the runtime information of the logic execution.
 */
public final class LogicRuntimeInformation implements ILogicRuntimeInformation {
    private static final String PROPERTY_NAME = "name";
    private static final String PROPERTY_START_TIME = "startTime";
    private static final String PROPERTY_END_TIME = "endTime";
    private static final String PROPERTY_ERROR_INFORMATION = "errorInformation";

    private final String name;
    private final Date startTime;
    private final Date endTime;
    private final IErrorInformation errorInformation;

    /**
     * The LogicRuntimeInformation constructor.
     */
    public LogicRuntimeInformation(
        String name,
        Date startTime,
        Date endTime,
        IErrorInformation errorInformation) {

        Conditions.validateStringNotNullOrEmpty(
            name,
            "The name of the logic.");

        Conditions.validateNotNull(
            startTime,
            "start time of the logic.");

        this.name = name;
        this.startTime = startTime;
        this.endTime = endTime;
        this.errorInformation = errorInformation;
    }

    /**
     * Gets the name of the logic.
     */
    @Deprecated
    public String getName() {
        return this.name;
    }

    /**
     * Gets the status of the logic execution.
     */
    @Override
    public boolean getStatus() {
        return this.errorInformation != null;
    }

    /**
     * Gets the time in which the logic has started.
     */
    @Override
    public Date getStartTime() {
        return this.startTime;
    }

    /**
     * Gets the time in which the logic has ended.
     */
    @Override
    public Date getEndTime() {
        return this.endTime;
    }

    /**
     * Gets the information of the error.
     */
    @Override
    public IErrorInformation getErrorInformation() {
        return this.errorInformation;
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
        writer.writeStringProperty(LogicRuntimeInformation.PROPERTY_NAME, this.name);
        writer.writeDateProperty(LogicRuntimeInformation.PROPERTY_START_TIME, this.startTime);
        writer.writeDateProperty(LogicRuntimeInformation.PROPERTY_END_TIME, this.endTime);
        writer.writeObjectProperty(LogicRuntimeInformation.PROPERTY_ERROR_INFORMATION, this.errorInformation);
    }

    /**
     * Reads an object from a json reader.
     */
    public static ILogicRuntimeInformation readJson(IJsonObjectReader reader) {
        String name = reader.readStringProperty(LogicRuntimeInformation.PROPERTY_NAME);
        Date startTime = reader.readDateProperty(LogicRuntimeInformation.PROPERTY_START_TIME);
        Date endTime = reader.readDateProperty(LogicRuntimeInformation.PROPERTY_END_TIME);
        IErrorInformation errorInformation = reader.readObjectProperty(LogicRuntimeInformation.PROPERTY_ERROR_INFORMATION, ErrorInformation.class);

        return new LogicRuntimeInformation(
            name,
            startTime,
            endTime,
            errorInformation);
    }
}
