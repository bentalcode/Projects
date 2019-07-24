package testbase.core;

import java.util.EnumSet;
import java.util.Set;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The Enums class implements complementary APIs for enums.
 */
public final class Enums {
    private static final Logger Log = LoggerFactory.getLogger(Enums.class);

    /**
     * Parses a name of an enum.
     * The Enum should implement the toString() API.
     */
    public static <TEnum extends Enum<TEnum>> TEnum parse(
        Class<TEnum> classType,
        String name) {

        Conditions.validateStringNotNullOrEmpty(
            name,
            "The name of an enum.");

        TEnum result = Enums.tryParse(classType, name);

        if (result == null) {
            String errorMessage =
                "Enums failed to parse enum of class type: " + ClassTypes.getName(classType) +
                ", for name: " + name;

            Log.error(errorMessage);
            throw new BaseException(errorMessage);
        }

        return result;
    }

    /**
     * Tries to parse a name of an enum.
     * The Enum should implement the toString() API.
     */
    public static <TEnum extends Enum<TEnum>> TEnum tryParse(
        Class<TEnum> classType,
        String name) {

        Conditions.validateNotNull(
            classType,
            "The class type of an enum.");

        if (Strings.isNullOrEmpty(name)) {
            return null;
        }

        Set<TEnum> values = EnumSet.allOf(classType);

        for (TEnum value : values) {
            if (value.toString().equals(name)) {
                return value;
            }
        }

        return null;
    }

    /**
     * Disables the default constructor - This is a static class.
     */
    private Enums() {
    }
}
