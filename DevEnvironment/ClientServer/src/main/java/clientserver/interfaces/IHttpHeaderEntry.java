package clientserver.interfaces;

/**
 * The IHttpHeaderEntry interface defines an entry of a http header.
 */
public interface IHttpHeaderEntry {
    /**
     * Gets the name of an entry.
     */
    String getName();

    /**
     * Gets the value of an entry.
     */
    String getValue();
}
