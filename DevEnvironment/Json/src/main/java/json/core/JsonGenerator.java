package json.core;

import base.core.Conditions;
import base.core.DestructorHandler;
import base.interfaces.ICloseable;
import java.io.IOException;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The JsonGenerator class implements a generator for json.
 */
public final class JsonGenerator implements IJsonGenerator, ICloseable {
    private final com.fasterxml.jackson.core.JsonGenerator generator;

    private final DestructorHandler destructorHandler = new DestructorHandler();
    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The JsonGenerator constructor.
     */
    public JsonGenerator(com.fasterxml.jackson.core.JsonGenerator generator) {
        Conditions.validateNotNull(
            generator,
            "The Jackson json generator.");

        this.generator = generator;
    }

    /**
     * Closes the generator.
     */
    @Override
    public void close() {
        this.destructorHandler.close();
    }

    /**
     * Closes the generator.
     */
    @Override
    public void flush() {
        try {
            this.generator.flush();
        }
        catch (IOException e) {
            String errorMessage =
                "The Json generator failed flushing the written content" +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage, e);
        }
    }

    /**
     * Writes a start object.
     */
    @Override
    public void writeStartObject() {
        try {
            this.generator.writeStartObject();
        }
        catch (IOException e) {
            String errorMessage =
                "The JsonGenerator failed writing a start object" +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage, e);
        }
    }

    /**
     * Writes an end object.
     */
    @Override
    public void writeEndObject() {
        try {
            this.generator.writeEndObject();
        }
        catch (IOException e) {
            String errorMessage =
                "The JsonGenerator failed writing an end object" +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage, e);
        }
    }

    /**
     * Writes a string property.
     */
    @Override
    public void writeStringProperty(String name, String value) {
        try {
            this.generator.writeStringField(name, value);
        }
        catch (IOException e) {
            String errorMessage =
                "The JsonGenerator failed writing a string property: " + name +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage, e);
        }
    }

    /**
     * Writes an integer property.
     */
    @Override
    public void writeIntegerProperty(String name, int value) {
        try {
            this.generator.writeNumberField(name, value);
        }
        catch (IOException e) {
            String errorMessage =
                "The JsonGenerator failed writing an integer property: " + name +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage, e);
        }
    }

    /**
     * Writes a long property.
     */
    @Override
    public void writeLongProperty(String name, long value) {
        try {
            this.generator.writeNumberField(name, value);
        }
        catch (IOException e) {
            String errorMessage =
                "The JsonGenerator failed writing a long property: " + name +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage, e);
        }
    }

    /**
     * Writes a float property.
     */
    @Override
    public void writeFloatProperty(String name, float value) {
        try {
            this.generator.writeNumberField(name, value);
        }
        catch (IOException e) {
            String errorMessage =
                "The JsonGenerator failed writing a float property: " + name +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage, e);
        }
    }

    /**
     * Writes a double property.
     */
    @Override
    public void writeDoubleProperty(String name, double value) {
        try {
            this.generator.writeNumberField(name, value);
        }
        catch (IOException e) {
            String errorMessage =
                "The JsonGenerator failed writing a double property: " + name +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage, e);
        }
    }
}
