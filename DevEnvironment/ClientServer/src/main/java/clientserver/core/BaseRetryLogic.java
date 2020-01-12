package clientserver.core;

import base.core.Conditions;
import clientserver.interfaces.IRetryLogic;
import json.core.JsonStream;
import json.interfaces.IJsonObjectWriter;

import java.util.HashSet;
import java.util.Set;

/**
 * The BaseRetryLogic class implements a base retry logic.
 */
public abstract class BaseRetryLogic implements IRetryLogic {
    private static final String PropertyName = "name";
    private static final String PropertyAbsorbedExceptions = "absorbedExceptions";

    private final String name;
    private final Set<Class<?>> absorbedExceptions;

    /**
     * The BaseRetryLogic constructor.
     */
    protected BaseRetryLogic(String name) {
        this(name, new HashSet<>());
    }

    /**
     * The BaseRetryLogic constructor.
     */
    protected BaseRetryLogic(String name, Set<Class<?>> absorbedExceptions) {
        Conditions.validateStringNotNullOrEmpty(
            name,
            "The logic name");

        Conditions.validateNotNull(
            absorbedExceptions,
            "The absorbed exceptions");

        this.name = name;
        this.absorbedExceptions = absorbedExceptions;

        if (this.absorbedExceptions.isEmpty()) {
            this.absorbedExceptions.add(Exception.class);
        }
    }

    /**
     * Gets the name of the logic.
     */
    @Override
    public String name() {
        return this.name;
    }

    /**
     * Gets the set of the absorbed exception types.
     */
    @Override
    public Set<Class<?>> getAbsorbedExceptions() {
        return this.absorbedExceptions;
    }

    /**
     * Gets string representation of this instance.
     */
    public String toString() {
        return JsonStream.serialize(this);
    }

    /**
     * Writes an object to a json writer.
     */
    @Override
    public void writeJson(IJsonObjectWriter writer) {
        writer.writeStringProperty(BaseRetryLogic.PropertyName, this.name);

        writer.writeCollectionProperty(
            BaseRetryLogic.PropertyAbsorbedExceptions,
            this.absorbedExceptions,
            (Class<?> classType) -> classType.getSimpleName());
    }
}
