package clientserver.core;

import clientserver.interfaces.IHttpBody;

/**
 * The HttpBody class implements a body of a Http message.
 */
public final class HttpBody implements IHttpBody {
    private final String content;

    /**
     * Creates a body with no content.
     */
    public static IHttpBody create() {
        return new HttpBody(null);
    }

    /**
     * Creates a body with a content.
     */
    public static IHttpBody create(String content) {
        return new HttpBody(content);
    }

    /**
     * The HttpBody constructor.
     */
    private HttpBody(String content) {
        this.content = content;
    }

    /**
     * Gets the content of a http message.
     */
    @Override
    public String getContent() {
        return this.content;
    }

    /**
     * Checks whether a body of a http message has content.
     */
    @Override
    public boolean hasContent() {
        return this.content != null;
    }
}
