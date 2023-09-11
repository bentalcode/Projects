package base.core;

/**
 * The Exceptions class implements complementary APIs for exceptions.
 */
public final class Exceptions {
    /**
     * Gets all the error messages of an exception.
     */
    public static String getErrorMessages(Throwable exception) {

        StringBuilder result = new StringBuilder();

        Throwable currentException = exception;

        while (currentException != null) {

            if (result.length() > 0) {
                result.append("; ");
            }

            result.append(ClassTypes.getName(exception.getClass()));
            result.append(":");
            result.append(currentException.getMessage());

            currentException = currentException.getCause();
        }

        return result.toString();
    }

    /**
     * The Exceptions constructor - Disables the default constructor.
     */
    private Exceptions() {
    }
}
