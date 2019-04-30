package base.core;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.lang.reflect.Constructor;
import java.lang.reflect.Method;

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
     * Invokes a method with no parameters and a return type.
     */
    public <Type, ReturnType> ReturnType invoke(Class<Type> classType, String methodName) {
        Conditions.validateNotNull(
            classType,
            "The type of a class to invoke with reflection.");

        Conditions.validateStringNotNullOrEmpty(
            methodName,
            "The method name to invoke with reflection.");

        Method method = this.getMethod(classType, methodName);

        ReturnType result;

        try {
            result = Casting.cast(method.invoke(null));
        }
        catch (ReflectiveOperationException e) {
            String errorMessage =
                "The Reflection Handler failed invoking method: " + methodName +
                " of class: " + classType +
                ", due to the following error: " + e.getMessage();

            throw new BaseException(errorMessage, e);
        }

        return result;
    }

    /**
     * Invokes a method with single parameter and a return type.
     */
    public <Type, ParamType, ReturnType> ReturnType invoke(
        Class<Type> classType,
        String methodName,
        Class<ParamType> paramType,
        ParamType param) {

        Conditions.validateNotNull(
            classType,
            "The type of a class to invoke with reflection.");

        Conditions.validateStringNotNullOrEmpty(
            methodName,
            "The method name to invoke with reflection.");

        Method method = this.getMethod(classType, methodName, paramType);

        ReturnType result;

        try {
            result = Casting.cast(method.invoke(null, param));
        }
        catch (ReflectiveOperationException e) {
            String errorMessage =
                "The Reflection Handler failed invoking method: " + methodName +
                " with param: " + paramType +
                " of class: " + classType +
                ", due to the following error: " + e.getMessage();

            throw new BaseException(errorMessage, e);
        }

        return result;
    }

    /**
     * Gets a default constructor of a class.
     */
    private <Type> Constructor<Type> getDefaultConstructor(Class<Type> classType) {
        Constructor<Type> constructor;

        try {
            constructor = classType.getDeclaredConstructor();
        }
        catch (NoSuchMethodException e) {
            String errorMessage =
                "The Reflection Handler failed to get default constructor" +
                " for class type: " + ClassTypes.getName(classType) +
                ", due to the following error: " + e.getMessage();

            ReflectionHandler.Log.error(errorMessage, e);
            throw new BaseException(errorMessage, e);
        }

        return constructor;
    }

    /**
     * Gets a method of a class.
     */
    private <Type> Method getMethod(Class<Type> classType, String methodName) {
        Method method;

        try {
            method = classType.getMethod(methodName);
        }
        catch (NoSuchMethodException e) {
            String errorMessage =
                "The Reflection Handler failed to get method: " + methodName +
                " for class type: " + ClassTypes.getName(classType) +
                ", due to the following error: " + e.getMessage();

            ReflectionHandler.Log.error(errorMessage, e);
            throw new BaseException(errorMessage, e);
        }

        return method;
    }

    /**
     * Gets a method with one parameter of a class.
     */
    private <Type, ParamType> Method getMethod(Class<Type> classType, String methodName, Class<ParamType> paramType) {
        Method method;

        try {
            method = classType.getMethod(methodName, paramType);
        }
        catch (NoSuchMethodException e) {
            String errorMessage =
                "The Reflection Handler failed to get method: " + methodName + " with param: " + paramType +
                " for class type: " + ClassTypes.getName(classType) +
                ", due to the following error: " + e.getMessage();

            ReflectionHandler.Log.error(errorMessage, e);
            throw new BaseException(errorMessage, e);
        }

        return method;
    }
}
