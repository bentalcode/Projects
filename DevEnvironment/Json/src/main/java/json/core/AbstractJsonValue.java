package json.core;

import testbase.core.ClassTypes;

/**
 * The AbstractJsonValue class implements an abstract json value.
 */
public abstract class AbstractJsonValue implements IJsonValue {
    /**
     * The AbstractJsonValue constructor.
     */
    protected AbstractJsonValue() {
    }

    /**
     * Gets a boolean value.
     */
    @Override
    public boolean getBooleanValue() {
        String errorMessage =
            "The Json Value class: " + ClassTypes.getName(this.getClass()) + " does not support a boolean.";

        throw new JsonException(errorMessage);
    }

    /**
     * Gets a long value.
     */
    @Override
    public long getLongValue() {
        String errorMessage =
            "The Json Value class: " + ClassTypes.getName(this.getClass()) + " does not support a long.";

        throw new JsonException(errorMessage);
    }

    /**
     * Gets a double value.
     */
    @Override
    public double getDoubleValue() {
        String errorMessage =
            "The Json Value class: " + ClassTypes.getName(this.getClass()) + " does not support a double.";

        throw new JsonException(errorMessage);
    }

    /**
     * Gets a string value.
     */
    @Override
    public String getStringValue() {
        String errorMessage =
            "The Json Value class: " + ClassTypes.getName(this.getClass()) + " does not support a string.";

        throw new JsonException(errorMessage);
    }

    /**
     * Gets an object.
     */
    @Override
    public IJsonObject getObject() {
        String errorMessage =
            "The Json Value class: " + ClassTypes.getName(this.getClass()) + " does not support an object.";

        throw new JsonException(errorMessage);
    }

    /**
     * Gets an array.
     */
    @Override
    public IJsonArray getArray() {
        String errorMessage =
            "The Json Value class: " + ClassTypes.getName(this.getClass()) + " does not support an array.";

        throw new JsonException(errorMessage);
    }
}
