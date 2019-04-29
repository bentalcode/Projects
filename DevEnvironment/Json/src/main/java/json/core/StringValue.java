package json.core;

import base.core.Conditions;

/**
 * The StringValue class implements a json value of type string.
 */
public final class StringValue implements IStringValue {
    private final String value;

    /**
     * The StringValue constructor.
     */
    public StringValue(String value) {
        Conditions.validateNotNull(
            value,
            "The value of a json string.");

        this.value = value;
    }
}
