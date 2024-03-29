package base.core;

import base.BaseException;
import java.nio.file.Path;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The Conditions class implements validations for various conditions.
 */
public final class Conditions {
    private static final Logger LOG = LoggerFactory.getLogger(Casting.class);

    /**
     * Validates a conditions.
     */
    public static void validate(boolean condition, String errorMessage) {
        if (!condition) {
            String message = "Condition.validate() failed due to the following error: " + errorMessage;

            LOG.error(message);
            throw new BaseException(message);
        }
    }

    /**
     * Validates a not null condition.
     */
    public static <T> void validateNotNull(T obj, String name) {
        if (obj == null) {
            String message = "The instance of an object can not be null. Parameter: " + name;

            LOG.error(message);
            throw new BaseException(message);
        }
    }

    /**
     * Validates a string is not null or empty condition.
     */
    public static void validateStringNotNullOrEmpty(String str, String name) {
        if (Strings.isNullOrEmpty(str)) {
            String message = "The instance of a string can not be null or empty. Parameter: " + name;

            LOG.error(message);
            throw new BaseException(message);
        }
    }

    /**
     * Validates a path is not null or empty condition.
     */
    public static void validatePathNotNullOrEmpty(Path path, String name) {
        if (Paths.isNullOrEmpty(path)) {
            String message = "The instance of a path can not be null or empty. Parameter: " + name;

            LOG.error(message);
            throw new BaseException(message);
        }
    }

    /**
     * Validates a conditions.
     */
    public static void fail(String errorMessage) {
        String message = "Condition failed due to the following error: " + errorMessage;

        LOG.error(message);
        throw new BaseException(message);
    }

    /**
     * The Conditions constructor - Disables the default constructor.
     */
    private Conditions() {
    }
}
