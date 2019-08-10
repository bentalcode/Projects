package base.core;

import base.interfaces.IBigIntegerConversion;
import base.interfaces.IDoubleConversion;
import base.interfaces.IIntegerConversion;
import base.interfaces.ILongConversion;
import base.interfaces.IStringConversion;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The Conversion class implements complementary APIs for conversions.
 */
public final class Conversion {
    private static final IIntegerConversion IntegerConversion = new IntegerConversion();
    private static final ILongConversion LongConversion = new LongConversion();
    private static final IDoubleConversion DoubleConversion = new DoubleConversion();
    private static final IStringConversion StringConversion = new StringConversion();
    private static final IBigIntegerConversion BigIntegerConversion = new BigIntegerConversion();

    private static final Logger Log = LoggerFactory.getLogger(Conversion.class);

    /**
     * Casts an object to a requested type.
     */
    public static <TTo> TTo cast(Object obj) {
        try {
            TTo convertedType = Conversion.unsafeCast(obj);
            return convertedType;
        }
        catch (ClassCastException e) {
            String errorMessage =
                "Failed to cast an instance of class type: " + ClassTypes.getName(obj) +
                " to the requested type due to the following error: " + e.getMessage();

            Conversion.Log.error(errorMessage, e);
            throw new BaseException(errorMessage, e);
        }
    }

    /**
     * Casts an object to a requested type.
     */
    public static <TTo, TFrom> TTo cast(TFrom obj, Class<TTo> requestedType) {
        try {
            TTo convertedType = Conversion.unsafeCast(obj);
            return convertedType;
        }
        catch (ClassCastException e) {
            String errorMessage =
                "Failed to cast an instance of class type: " + ClassTypes.getName(obj) +
                " to the requested type: " + requestedType.getName() + " due to the following error: " + e.getMessage();

            Conversion.Log.error(errorMessage, e);
            throw new BaseException(errorMessage, e);
        }
    }

    /**
     * Gets an interface for integer conversions.
     */
    public static IIntegerConversion integerConversion() {
        return Conversion.IntegerConversion;
    }

    /**
     * Gets an interface for long conversions.
     */
    public static ILongConversion longConversion() {
        return Conversion.LongConversion;
    }

    /**
     * Gets an interface for double conversions.
     */
    public static IDoubleConversion doubleConversion() {
        return Conversion.DoubleConversion;
    }

    /**
     * Gets an interface for string conversions.
     */
    public static IStringConversion stringConversion() {
        return Conversion.StringConversion;
    }

    /**
     * Gets an interface for big integer conversions.
     */
    public static IBigIntegerConversion bigIntegerConversion() {
        return Conversion.BigIntegerConversion;
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
     * The Conversion constructor - Disables the default constructor.
     */
    private Conversion() {
    }
}
