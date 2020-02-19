package clientserver.interfaces;

/**
 * The IHttpRequest interface defines a http request.
 */
public interface IHttpRequest extends IHttpMessage {
    /**
     * Gets the name of a service.
     */
    String getServiceName();

    /**
     * Gets the name of an operation.
     */
    String getOperationName();

    /**
     * Gets the uri of a request.
     */
    String getUri();

    /**
     * Gets the method of a request.
     */
    HttpMethod getMethod();

    /**
     * Gets the authorization of a request.
     */
    IOAuthCredentials getAuthorization();
}
