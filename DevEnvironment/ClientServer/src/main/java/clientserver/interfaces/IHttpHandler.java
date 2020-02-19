package clientserver.interfaces;

/**
 * The IHttpHandler interface defines a handler for making http requests.
 */
public interface IHttpHandler {
    /**
     * Gets the configuration.
     */
    IHttpHandlerConfiguration getConfiguration();

    /**
     * Makes a http request.
     */
    IHttpResponse make(IHttpRequest request);
}
