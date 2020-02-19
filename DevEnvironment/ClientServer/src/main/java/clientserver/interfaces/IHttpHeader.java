package clientserver.interfaces;

import base.interfaces.IIterable;

import java.util.Map;

/**
 * The IHttpHeader interface defines a Http header.
 */
public interface IHttpHeader extends IIterable<IHttpHeaderEntry> {
    /**
     * Sets the authorization.
     */
    void setAuthorization(String value);

    /**
     * Sets the content type.
     */
    void setContentType(String value);

    /**
     * Sets the content type as application json.
     */
    void setContentTypeAsApplicationJson();

    /**
     * Sets a new entry.
     */
    void set(IHttpHeaderEntry entry);

    /**
     * Sets a new entry.
     */
    void set(String name, String value);

    /**
     * Gets the values of the header.
     */
    Map<String, String> getValues();
}
