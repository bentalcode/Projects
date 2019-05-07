package json.core;

import base.core.Conditions;
import base.core.DestructorHandler;
import base.interfaces.ICloseable;
import json.interfaces.IJsonObjectWriter;
import json.interfaces.IJsonSerialization;
import java.io.Writer;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The JsonWriter class implements a json writer.
 */
public final class JsonWriter implements IJsonWriter, ICloseable {
    private final IJsonFactory factory;
    private final JsonGenerator generator;

    private final DestructorHandler destructorHandler = new DestructorHandler();
    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The JsonWriter constructor.
     */
    public JsonWriter(IJsonFactory factory, Writer writer) {
        Conditions.validateNotNull(
            factory,
            "The json factory.");

        Conditions.validateNotNull(
            writer,
            "The writer to write a json into.");

        this.factory = factory;
        this.generator = this.factory.createGenerator(writer);
        this.destructorHandler.register(this.generator);
    }

    /**
     * Closes the writer.
     */
    @Override
    public void close() {
        this.destructorHandler.close();
    }

    /**
     * Flushes the writer.
     */
    @Override
    public void flush() {
        this.generator.flush();
    }

    /**
     * Writes a generic object.
     */
    @Override
    public <T extends IJsonSerialization> void writeObject(T obj) {
        Conditions.validateNotNull(
            obj,
            "The object to write to a json writer.");

        this.generator.writeStartObject();

        IJsonObjectWriter objectWriter = new JsonObjectWriter(this);
        obj.writeJson(objectWriter);

        this.generator.writeEndObject();
    }

    /**
     * Writes a string property.
     */
    @Override
    public void writeStringProperty(String name, String value) {
        this.generator.writeStringProperty(name, value);
    }

    /**
     * Writes an integer property.
     */
    @Override
    public void writeIntegerProperty(String name, int value) {
        this.generator.writeIntegerProperty(name, value);
    }

    /**
     * Writes a long property.
     */
    @Override
    public void writeLongProperty(String name, long value) {
        this.generator.writeLongProperty(name, value);
    }

    /**
     * Writes a float property.
     */
    @Override
    public void writeFloatProperty(String name, float value) {
        this.generator.writeFloatProperty(name, value);
    }

    /**
     * Writes a double property.
     */
    @Override
    public void writeDoubleProperty(String name, double value) {
        this.generator.writeDoubleProperty(name, value);
    }
}
