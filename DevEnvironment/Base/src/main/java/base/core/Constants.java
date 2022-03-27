package base.core;

import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;

/**
 * The Constants class implements constants of the base library.
 */
public final class Constants {
    /**
     * The default encoding.
     */
    public static final Charset DEFAULT_ENCODING = StandardCharsets.UTF_8;

    /**
     * The guid regex.
     */
    public static final String GUID_REGEX = "[0-9a-fA-F]{8}[-_]{0,1}[0-9a-fA-F]{4}[-_]{0,1}[0-9a-fA-F]{4}[-_]{0,1}[0-9a-fA-F]{4}[-_]{0,1}[0-9a-fA-F]{12}";

    /**
     * Disables the default constructor - This is a static class.
     */
    private Constants() {
    }
}
