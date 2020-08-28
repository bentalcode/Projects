package clientserver.core;

import base.core.Conditions;
import base.core.ListIterator;
import base.interfaces.IIterator;
import clientserver.interfaces.IHttpHeader;
import clientserver.interfaces.IHttpHeaderEntry;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * The HttpHeader class implements a Http header.
 */
public final class HttpHeader implements IHttpHeader {
    private final List<IHttpHeaderEntry> entries = new ArrayList<>();

    /**
     * The HttpHeader constructor.
     */
    public HttpHeader() {
    }

    /**
     * Sets the authorization.
     */
    @Override
    public void setAuthorization(String value) {
        this.set(HttpHeaderConstants.authorization, value);
    }

    /**
     * Sets the content type.
     */
    @Override
    public void setContentType(String value) {
        this.set(HttpHeaderConstants.contentType, value);
    }

    /**
     * Sets the content type as application json.
     */
    @Override
    public void setContentTypeAsApplicationJson() {
        this.setContentType(HttpHeaderConstants.applicationJson);
    }

    /**
     * Sets an entry.
     */
    @Override
    public void set(String name, String value) {
        this.set(HttpHeaderEntry.make(name, value));
    }

    /**
     * Sets an entry.
     */
    @Override
    public void set(IHttpHeaderEntry entry) {
        Conditions.validateNotNull(entry, "The entry of a Http Header.");
        this.entries.add(entry);
    }

    /**
     * Gets the iterator of entries.
     */
    @Override
    public IIterator<IHttpHeaderEntry> getIterator() {
        return ListIterator.make(this.entries);
    }

    /**
     * Gets the values of the header.
     */
    @Override
    public Map<String, String> getValues() {
        Map<String, String> values = new HashMap<>();

        for (IHttpHeaderEntry entry : this.entries) {
            values.put(entry.getName(), entry.getValue());
        }

        return values;
    }

    /**
     * Creates a header from values.
     */
    public static IHttpHeader create(Map<String, String> values) {
        Conditions.validateNotNull(
            values,
            "The values of a Http Header.");

        IHttpHeader header = new HttpHeader();

        for (Map.Entry<String, String> entryValues : values.entrySet()) {
            header.set(entryValues.getKey(), entryValues.getValue());
        }

        return header;
    }
}
