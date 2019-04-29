package base.core;

/**
 * The ClassTypes class implements complementary APIs for class types.
 */
public final class ClassTypes {

    /**
     * Gets a name of a class.
     */
    public static <T> String getName(Class<T> classType) {

        Conditions.validateNotNull(
            classType,
            "The type of a class.");

        return classType.getSimpleName();
    }

    /**
     * The ClassTypes constructor - Disables the default constructor.
     */
    private ClassTypes() {
    }
}
