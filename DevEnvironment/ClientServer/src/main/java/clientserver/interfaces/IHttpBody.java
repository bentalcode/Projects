package clientserver.interfaces;

/**
 * The IHttpBody interface defines a body of a Http message.
 */
public interface IHttpBody {
    /**
     * Gets the content of a http message.
     */
    String getContent();

    /**
     * Checks whether a body of a http message has content.
     */
    boolean hasContent();
}
