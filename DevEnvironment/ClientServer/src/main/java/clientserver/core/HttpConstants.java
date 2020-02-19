package clientserver.core;

import java.time.Duration;

/**
 * The HttpConstants class implements constants for the http protocol.
 */
public final class HttpConstants {
    public static final Duration defaultConnectTimeout = Duration.ofSeconds(10);
    public static final Duration defaultWriteTimeout = Duration.ofSeconds(10);
    public static final Duration defaultReadTimeout = Duration.ofSeconds(10);
    public static final Duration defaultSocketTimeout = Duration.ofSeconds(1);

    /**
     * The HttpConstants constructor - Disables the default constructor.
     */
    private HttpConstants() {
    }
}
