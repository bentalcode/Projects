package base.core;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The Casting class implements complementary APIs for casting.
 */
public final class Casting {
    private static Logger Log = LoggerFactory.getLogger(Casting.class);

    /**
     * Casts the object to the requested type.
     */
    public static <TTo> TTo cast(Object obj) {
        try {
            TTo convertedType = Casting.unsafeCast(obj);
            return convertedType;
        }
        catch (ClassCastException e) {
            String errorMessage =
                "Failed to cast an instance of class type: " + obj.getClass().getName() +
                " to the requested type due to the following error: " + e.getMessage();

            Casting.Log.error(errorMessage, e);
            throw new BaseException(errorMessage, e);
        }
    }

    /**
     * Casts the object to the requested type.
     */
    public static <TTo, TFrom> TTo cast(TFrom obj, Class<TTo> requestedType) {
        try {
            TTo convertedType = Casting.unsafeCast(obj);
            return convertedType;
        }
        catch (ClassCastException e) {
            String errorMessage =
                "Failed to cast an instance of class type: " + obj.getClass().getName() +
                " to the requested typ: " + requestedType.getName() + " due to the following error: " + e.getMessage();

            Casting.Log.error(errorMessage, e);
            throw new BaseException(errorMessage, e);
        }
    }

    /**
     * Casts an integer to a long.
     */
    public static int toInteger(long value) {
        if (value < Integer.MIN_VALUE || value > Integer.MAX_VALUE) {
            String errorMessage = "Failed to cast a long: " + value + " to an integer.";
            throw new BaseException(errorMessage);
        }

        return (int)value;
    }

    /**
     * Performs an unsafe cast.
     */
    private static <TTo> TTo unsafeCast(Object obj) {
        @SuppressWarnings("unchecked")
        TTo convertedType = (TTo)obj;
        return convertedType;
    }

    /**
     * The Casting constructor - Disables the default constructor.
     */
    private Casting() {
    }
}
