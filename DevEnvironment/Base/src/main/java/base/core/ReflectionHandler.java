package base.core;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.lang.reflect.Constructor;

/**
 * The ReflectionHandler class implements a reflection handler.
 */
public final class ReflectionHandler {
    private static final Logger Log = LoggerFactory.getLogger(ReflectionHandler.class);

    /**
     * ReflectionHandler constructor.
     */
    public ReflectionHandler() {
    }

    /**
     * Creates a new instance by invoking a default constructor.
     */
    public <Type> Type create(Class<Type> classType) {
        Conditions.validateNotNull(
            classType,
            "The type of a class to create with reflection.");

        Type instance;

        Constructor<Type> constructor = this.getDefaultConstructor(classType);

        try {
            instance = constructor.newInstance();
        }
        catch (ReflectiveOperationException e) {
            String errorMessage =
                "The Reflection Handler failed invoking a default constructor for class type: " +
                ClassTypes.getName(classType) +
                "; Error Message: " + e.getMessage();

            ReflectionHandler.Log.error(errorMessage, e);
            throw new BaseException(errorMessage, e);
        }

        return instance;
    }

    /**
     * Creates a new instance by invoking a default constructor with single parameter.
     */
    public <Type, ParamType> Type create(
        Class<Type> classType,
        ParamType param) {

        Conditions.validateNotNull(
            classType,
            "The type of a class to create with reflection.");

        Type instance;

        Constructor<Type> constructor = this.getDefaultConstructor(classType);

        try {
            instance = constructor.newInstance(param);
        }
        catch (ReflectiveOperationException e) {
            String errorMessage =
                "The Reflection Handler failed invoking a default constructor with single parameter for class type: " +
                ClassTypes.getName(classType) +
                "; Error Message: " + e.getMessage();

            ReflectionHandler.Log.error(errorMessage, e);
            throw new BaseException(errorMessage, e);
        }

        return instance;
    }

    /**
     * Creates a new instance by invoking a default constructor with two parameters.
     */
    public <Type, ParamType> Type create(
        Class<Type> classType,
        ParamType param1,
        ParamType param2) {

        Conditions.validateNotNull(
            classType,
            "The type of a class to create with reflection.");

        Type instance;

        Constructor<Type> constructor = this.getDefaultConstructor(classType);

        try {
            instance = constructor.newInstance(param1, param2);
        }
        catch (ReflectiveOperationException e) {
            String errorMessage =
                "The Reflection Handler failed invoking a default constructor with two parameters for class type: " +
                ClassTypes.getName(classType) +
                "; Error Message: " + e.getMessage();

            ReflectionHandler.Log.error(errorMessage, e);
            throw new BaseException(errorMessage, e);
        }

        return instance;
    }

    /**
     * Gets the default constructor of a class.
     */
    private <Type> Constructor<Type> getDefaultConstructor(Class<Type> classType) {
        Constructor<Type> constructor;

        try {
            constructor = classType.getDeclaredConstructor();
        }
        catch (NoSuchMethodException e) {
            String errorMessage =
                "The default constructor for class type: " + ClassTypes.getName(classType) + " was not found." +
                "; Error Message: " + e.getMessage();

            ReflectionHandler.Log.error(errorMessage, e);
            throw new BaseException(errorMessage, e);
        }

        return constructor;
    }
}
