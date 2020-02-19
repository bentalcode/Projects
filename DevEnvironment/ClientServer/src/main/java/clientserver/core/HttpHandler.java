package clientserver.core;

import base.core.Conditions;
import base.interfaces.ITriple;
import clientserver.ClientServerException;
import clientserver.interfaces.IHttpHandlerConfiguration;
import clientserver.interfaces.IHttpHandlerImpl;
import clientserver.interfaces.IHttpRequest;
import clientserver.interfaces.IHttpResponse;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.util.Map;

/**
 * The HttpHandler class implements a handler for making http requests.
 */
public final class HttpHandler extends AbstractHttpHandler {
    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The HttpHandler constructor.
     */
    public HttpHandler(
        IHttpHandlerConfiguration configuration,
        IHttpHandlerImpl implementation) {
        super(
            configuration,
            implementation);
    }

    /**
     * Makes a http request.
     */
    public IHttpResponse make(IHttpRequest request) {
        Conditions.validateNotNull(
            request,
            "The http request.");

        IHttpResponse response;

        try {
            Map<String, String> headerValues = request.getHeader().getValues();
            String body = request.getBody().getContent();

            ITriple<Integer, Map<String, String>, String> responseData =
                this.getImplementation().make(headerValues, body);

            response = HttpResponse.create(responseData);
        }
        catch (HttpException e) {
            String errorMessage = this.createErrorMessage(request, e.getMessage());

            this.log.error(errorMessage);
            throw new ClientServerException(errorMessage, e);
        }

        return response;
    }

    /**
     * Creates an error message.
     */
    private String createErrorMessage(
        IHttpRequest request,
        String errorMessage) {

        return
            "The Http Handler failed making a http request" +
            " of service: " + request.getServiceName() +
            " for operation: " + request.getOperationName() +
            " to uri: " + request.getUri() +
            ", due to the following error: " + errorMessage;
    }
}
