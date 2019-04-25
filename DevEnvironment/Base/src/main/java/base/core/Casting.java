package base.core;

/**
 * The Casting class implements complementary APIs for casting.
 */
public final class Casting {

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

            throw new BaseException(errorMessage);
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

            throw new BaseException(errorMessage);
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
