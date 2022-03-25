package base.core;

import base.BaseException;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The Casting class implements complementary APIs for casting.
 */
public final class Casting {
    private static final Logger LOG = LoggerFactory.getLogger(Casting.class);

    /**
     * Casts the object to the requested type.
     */
    public static <TTo, TFrom> TTo cast(TFrom obj) {
        try {
            return Casting.unsafeCast(obj);
        }
        catch (ClassCastException e) {
            String errorMessage =
                "Failed to cast an instance of class type: " + ClassTypes.getName(obj) +
                " to the requested type due to the following error: " + e.getMessage();

            LOG.error(errorMessage, e);
            throw new BaseException(errorMessage, e);
        }
    }

    /**
     * Casts the object to the requested type.
     */
    public static <TTo, TFrom> TTo cast(TFrom obj, Class<?> requestedType) {
        TTo convertedType;

        try {
            convertedType = Casting.unsafeCast(obj);
        }
        catch (ClassCastException e) {
            String errorMessage =
                "Failed to cast an instance of class type: " + ClassTypes.getName(obj) +
                " to the requested type: " + requestedType.getName() +
                " due to the following error: " + e.getMessage();

            LOG.error(errorMessage, e);
            throw new BaseException(errorMessage, e);
        }

        if (!requestedType.isAssignableFrom(convertedType.getClass())) {
            String errorMessage =
                "Failed to cast an instance of class type: " + ClassTypes.getName(obj) +
                " to the requested type: " + requestedType.getName();

            LOG.error(errorMessage);
            throw new BaseException(errorMessage);
        }

        return convertedType;
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
