package clientserver.core;

import base.core.Collections;
import base.core.Conditions;
import base.core.Strings;
import clientserver.interfaces.IHttpHeaderEntry;

import java.util.Collection;

/**
 * The HttpHeaderEntry class implements an entry of a http header.
 */
public final class HttpHeaderEntry implements IHttpHeaderEntry {
    private static final char valueSeparator = ';';

    private final String name;
    private final String value;

    /**
     * Creates a new header entry.
     */
    public static IHttpHeaderEntry make(String name, String value) {
        return new HttpHeaderEntry(name, value);
    }

    /**
     * The HttpHeaderEntry constructor.
     */
    private HttpHeaderEntry(
        String name,
        String value) {

        Conditions.validateStringNotNullOrEmpty(
            name,
            "The name of a header entry.");

        Conditions.validateNotNull(
            value,
            "The value of a header entry.");

        this.name = name;
        this.value = value;
    }

    /**
     * Gets the name of an entry.
     */
    @Override
    public String getName() {
        return this.name;
    }

    /**
     * Gets the value of an entry.
     */
    @Override
    public String getValue() {
        return this.value;
    }

    /**
     * Creates a header entry.
     */
    public static IHttpHeaderEntry create(String name, Collection<String> values) {
        String value = Strings.create(values, HttpHeaderEntry.valueSeparator);
        return new HttpHeaderEntry(name, value);
    }
}
