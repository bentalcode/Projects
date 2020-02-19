package clientserver.interfaces;

/**
 * The IHttpMessage interface defines a http message.
 */
public interface IHttpMessage {
    /**
     * Gets the header of a request.
     */
    IHttpHeader getHeader();

    /**
     * Gets the body of a request.
     */
    IHttpBody getBody();
}
