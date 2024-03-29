package base.core;

import java.util.Base64;

/**
 * The Bytes class implements complementary APIs for bytes.
 */
public final class Bytes {
    /**
     * Parses a bytes from a string.
     */
    public static byte[] fromString(String value) {
        if (Strings.isNullOrEmpty(value)) {
            return null;
        }

        return Base64.getDecoder().decode(value);
    }

    /**
     * Converts bytes to a string.
     */
    public static String toString(byte[] value) {
        if (value == null) {
            return null;
        }

        return Base64.getEncoder().encodeToString(value);
    }

    /**
     * The Bytes constructor - Disables the default constructor.
     */
    private Bytes() {
    }
}
