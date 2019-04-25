package base.core;

/**
 * The Conditions class implements validations for various conditions.
 */
public final class Conditions {

    /**
     * Validates a conditions.
     */
    public static void validate(boolean condition, String errorMessage) {
        if (!condition) {
            String message = "Condition.validate() failed due to the following error: " + errorMessage;
            throw new BaseException(message);
        }
    }

    /**
     * Validates a not null condition.
     */
    public static <T> void validateNotNull(T obj, String objName) {
        if (obj == null) {
            String message = "The instance of object parameter: " + objName + " can not be null.";
            throw new BaseException(message);
        }
    }

    /**
     * Validates a string not null or empty condition.
     */
    public static void validateStringNotNullOrEmpty(String str, String name) {
        if (Strings.isNullOrEmpty(str)) {
            String message = "The instance of string parameter: " + name + " can not be null or empty.";
            throw new BaseException(message);
        }
    }

    /**
     * The Conditions constructor - Disables the default constructor.
     */
    private Conditions() {
    }
}
