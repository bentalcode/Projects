package clientserver.interfaces;

/**
 * The IHttpResponse interface defines a http response.
 */
public interface IHttpResponse extends IHttpMessage {
    /**
     * Gets the status of a response.
     */
    int getStatus();
}
