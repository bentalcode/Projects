package base.core;

import base.BaseException;
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
    private static final IIntegerConversion integerConversion = new IntegerConversion();
    private static final ILongConversion longConversion = new LongConversion();
    private static final IDoubleConversion doubleConversion = new DoubleConversion();
    private static final IStringConversion stringConversion = new StringConversion();
    private static final IBigIntegerConversion bigIntegerConversion = new BigIntegerConversion();

    private static final Logger LOG = LoggerFactory.getLogger(Conversion.class);

    /**
     * Casts an object to a requested type.
     */
    public static <TTo> TTo cast(Object obj) {
        try {
            return Conversion.unsafeCast(obj);
        }
        catch (ClassCastException e) {
            String errorMessage =
                "Failed to cast an instance of class type: " + ClassTypes.getName(obj) +
                " to the requested type due to the following error: " + e.getMessage();

            Conversion.LOG.error(errorMessage, e);
            throw new BaseException(errorMessage, e);
        }
    }

    /**
     * Casts an object to a requested type.
     */
    public static <TTo, TFrom> TTo cast(TFrom obj, Class<TTo> requestedType) {
        try {
            return Conversion.unsafeCast(obj);
        }
        catch (ClassCastException e) {
            String errorMessage =
                "Failed to cast an instance of class type: " + ClassTypes.getName(obj) +
                " to the requested type: " + requestedType.getName() + " due to the following error: " + e.getMessage();

            Conversion.LOG.error(errorMessage, e);
            throw new BaseException(errorMessage, e);
        }
    }

    /**
     * Gets an interface for integer conversions.
     */
    public static IIntegerConversion integerConversion() {
        return Conversion.integerConversion;
    }

    /**
     * Gets an interface for long conversions.
     */
    public static ILongConversion longConversion() {
        return Conversion.longConversion;
    }

    /**
     * Gets an interface for double conversions.
     */
    public static IDoubleConversion doubleConversion() {
        return Conversion.doubleConversion;
    }

    /**
     * Gets an interface for string conversions.
     */
    public static IStringConversion stringConversion() {
        return Conversion.stringConversion;
    }

    /**
     * Gets an interface for big integer conversions.
     */
    public static IBigIntegerConversion bigIntegerConversion() {
        return Conversion.bigIntegerConversion;
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
