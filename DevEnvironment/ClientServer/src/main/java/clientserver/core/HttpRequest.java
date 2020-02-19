package clientserver.core;

import base.core.Conditions;
import clientserver.interfaces.HttpMethod;
import clientserver.interfaces.IHttpBody;
import clientserver.interfaces.IHttpHeader;
import clientserver.interfaces.IHttpRequest;
import clientserver.interfaces.IOAuthCredentials;

/**
 * The HttpRequest class implements a http request.
 */
public final class HttpRequest extends HttpMessage implements IHttpRequest {
    private final String serviceName;
    private final String operationName;
    private final String uri;
    private final HttpMethod method;
    private final IOAuthCredentials oAuthCredentials;

    /**
     * The HttpRequest constructor.
     */
    public HttpRequest(
        String serviceName,
        String operationName,
        String uri,
        HttpMethod method,
        IHttpHeader header,
        IOAuthCredentials oAuthCredentials) {
        this(
            serviceName,
            operationName,
            uri,
            method,
            header,
            HttpBody.create(),
            oAuthCredentials);
    }

    /**
     * The HttpRequest constructor.
     */
    public HttpRequest(
        String serviceName,
        String operationName,
        String uri,
        HttpMethod method,
        IHttpHeader header,
        IHttpBody body,
        IOAuthCredentials oAuthCredentials) {
        super(
            header,
            body);

        Conditions.validateStringNotNullOrEmpty(
            serviceName,
            "The name of a service.");

        Conditions.validateStringNotNullOrEmpty(
            operationName,
            "The name of an operation.");

        Conditions.validateStringNotNullOrEmpty(
            uri,
            "The uri of a http request.");

        Conditions.validateNotNull(
            method,
            "The method of a http request.");

        this.serviceName = serviceName;
        this.operationName = operationName;
        this.uri = uri;
        this.method = method;
        this.oAuthCredentials = oAuthCredentials;
    }

    /**
     * Gets the name of a service.
     */
    public String getServiceName() {
        return this.serviceName;
    }

    /**
     * Gets the name of an operation.
     */
    @Override
    public String getOperationName() {
        return this.operationName;
    }

    /**
     * Gets the uri of the request.
     */
    @Override
    public String getUri() {
        return this.uri;
    }

    /**
     * Gets the method of a request.
     */
    @Override
    public HttpMethod getMethod() {
        return this.method;
    }

    /**
     * Gets the authorization of a request.
     */
    @Override
    public IOAuthCredentials getAuthorization() {
        return this.oAuthCredentials;
    }
}
