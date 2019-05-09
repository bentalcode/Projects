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
    public static <TTo, TFrom> TTo cast(TFrom obj) {
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
    public static <TTo, TFrom> TTo cast(TFrom obj, Class<?> requestedType) {
        try {
            TTo convertedType = Casting.unsafeCast(obj);

            if (!requestedType.isAssignableFrom(convertedType.getClass())) {
                String errorMessage =
                    "Failed to cast an instance of class type: " + obj.getClass().getName() +
                    " to the requested type: " + requestedType.getName();

                Casting.Log.error(errorMessage);
                throw new BaseException(errorMessage);
            }

            return convertedType;
        }
        catch (ClassCastException e) {
            String errorMessage =
                "Failed to cast an instance of class type: " + obj.getClass().getName() +
                " to the requested type: " + requestedType.getName() + " due to the following error: " + e.getMessage();

            Casting.Log.error(errorMessage, e);
            throw new BaseException(errorMessage, e);
        }
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
