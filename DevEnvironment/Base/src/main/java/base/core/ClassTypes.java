package base.core;

import base.BaseException;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.lang.reflect.Type;

/**
 * The ClassTypes class implements complementary APIs for class types.
 */
public final class ClassTypes {
    private static Logger Log = LoggerFactory.getLogger(ClassTypes.class);

    /**
     * Gets a name of a class of an object.
     */
    public static <T> String getName(T obj) {
        Conditions.validateNotNull(
            obj,
            "The instance of a class.");

        return obj.getClass().getSimpleName();
    }

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
     * Parses the name of a class from it's name.
     */
    public static Class<?> parse(String className) {
        Class<?> classType;

        try {
            classType = Class.forName(className);
        } catch (ClassNotFoundException e) {
            String errorMessage =
                "The ClassTypes failed loading class name: " + className +
                " due to the following error: " + e.getMessage();

            Log.error(errorMessage);
            throw new BaseException(errorMessage, e);
        }

        return classType;
    }

    /**
     * Gets the generic interfaces of a class.
     */
    public static <T> Type[] getGenericInterfaces(Class<T> classType) {
        Conditions.validateNotNull(
            classType,
            "The type of a class.");

        Type[] genericInterfaces = classType.getGenericInterfaces();

        return genericInterfaces;
    }

    /**
     * The ClassTypes constructor - Disables the default constructor.
     */
    private ClassTypes() {
    }
}
