package clientserver.core;

import java.time.Duration;

/**
 * The HttpConstants class implements constants for the http protocol.
 */
public final class HttpConstants {
    public static final Duration DEFAULT_CONNECT_TIMEOUT = Duration.ofSeconds(10);
    public static final Duration DEFAULT_WRITE_TIMEOUT = Duration.ofSeconds(10);
    public static final Duration DEFAULT_READ_TIMEOUT = Duration.ofSeconds(10);
    public static final Duration DEFAULT_SOCKET_TIMEOUT = Duration.ofSeconds(1);

    /**
     * The HttpConstants constructor - Disables the default constructor.
     */
    private HttpConstants() {
    }
}
