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
     * Disables the default constructor - This is a static class.
     */
    private HttpConstants() {
    }
}
