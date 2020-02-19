package clientserver.core;

import base.core.Conditions;
import clientserver.interfaces.IHttpBody;
import clientserver.interfaces.IHttpHeader;
import clientserver.interfaces.IHttpMessage;

/**
 * The HttpMessage abstract base class implements a http message.
 */
public abstract class HttpMessage implements IHttpMessage {
    private final IHttpHeader header;
    private final IHttpBody body;

    /**
     * The HttpMessage constructor.
     */
    protected HttpMessage(
        IHttpHeader header,
        IHttpBody body) {

        Conditions.validateNotNull(header, "The header of a http request.");
        Conditions.validateNotNull(body, "The body of a http request.");

        this.header = header;
        this.body = body;
    }

    /**
     * Gets the header of a request.
     */
    @Override
    public IHttpHeader getHeader() {
        return this.header;
    }

    /**
     * Gets the body of a request.
     */
    @Override
    public IHttpBody getBody() {
        return this.body;
    }
}
