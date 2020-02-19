package clientserver.core;

import base.core.Conditions;
import base.interfaces.ITriple;
import clientserver.interfaces.IHttpBody;
import clientserver.interfaces.IHttpHeader;
import clientserver.interfaces.IHttpResponse;

import java.util.Map;

/**
 * The HttpResponse class implements a Http response.
 */
public final class HttpResponse extends HttpMessage implements IHttpResponse {
    private final int status;

    /**
     * The HttpResponse constructor.
     */
    public HttpResponse(
        int status,
        IHttpHeader header,
        IHttpBody body) {
        super(
            header,
            body);

        Conditions.validateNotNull(
            status,
            "The status of a Http response.");

        this.status = status;
    }

    /**
     * Gets the status of a response.
     */
    @Override
    public int getStatus() {
        return this.status;
    }

    /**
     * Creates a response.
     */
    public static IHttpResponse create(
        ITriple<Integer, Map<String, String>, String> data) {

        Conditions.validateNotNull(
            data,
            "The data of a response.");

        int statusCode = data.first();
        IHttpHeader header = HttpHeader.create(data.second());
        IHttpBody body = HttpBody.create(data.third());

        return new HttpResponse(
            statusCode,
            header,
            body);
    }
}
