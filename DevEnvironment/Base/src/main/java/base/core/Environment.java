package base.core;

import base.BaseException;
import base.interfaces.IOperatingSystemControlSettings;
import base.interfaces.IStringTransformer;
import base.interfaces.OperatingSystemType;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The Environment class implements complementary APIs for current environment.
 */
public final class Environment {
    private static final String variablePattern = "\\$\\{[A-Za-z0-9\\-\\_\\.]+\\}";
    private static final Logger log = LoggerFactory.getLogger(Enums.class);

    /**
     * Checks whether the current operating system is windows.
     */
    public static boolean isWindows() {
        return getOperatingSystem() == OperatingSystemType.Windows;
    }

    /**
     * Gets the current type of the operating system.
     */
    public static OperatingSystemType getOperatingSystem() {
        String value = System.getProperty("os.name");
        return OperatingSystemType.getOperatingSystem(value);
    }

    /**
     * Gets the current control settings of the operating system.
     */
    public static IOperatingSystemControlSettings getOperatingSystemControlSettings() {
        OperatingSystemType operatingSystemType = getOperatingSystem();
        return getOperatingSystemControlSettings(operatingSystemType);
    }

    /**
     * Gets the control settings of the operating system.
     */
    public static IOperatingSystemControlSettings getOperatingSystemControlSettings(OperatingSystemType operatingSystemType) {
        return OperatingSystemControlSettingHolder.instance().getControlSettings(operatingSystemType);
    }

    /**
     * Expends system properties.
     */
    public static String expandSystemProperties(String name) {
        IStringTransformer transformer = null;
        return expandSystemProperties(name, transformer);
    }

    /**
     * Expends system properties.
     */
    public static String expandSystemProperties(String name, IStringTransformer transformer) {
        if (Strings.isNullOrEmpty(name)) {
            return name;
        }

        Pattern pattern = Pattern.compile(variablePattern);
        Matcher matcher = pattern.matcher(name);

        StringBuilder result = new StringBuilder();

        int currIndex = 0;

        while (currIndex < name.length() && matcher.find(currIndex)) {
            String variable = matcher.group(0);
            String variableName = getVariableName(variable);

            int variableStartIndex = matcher.start(0);
            int variableEndIndex = matcher.end(0) - 1;

            int prefixStartIndex = currIndex;
            int prefixEndIndex = variableStartIndex - 1;

            int prefixLength = Dimensions.length(prefixStartIndex, prefixEndIndex);

            if (prefixLength > 0) {
                String prefix = name.substring(prefixStartIndex, prefixEndIndex + 1);
                result.append(prefix);
            }

            String variableValue = System.getProperty(variableName);

            if (transformer != null) {
                variableValue = transformer.transform(variableValue);
            }

            if (variableValue != null) {
                result.append(variableValue);
            }

            currIndex = variableEndIndex + 1;
        }

        int postfixStartIndex = currIndex;
        int postfixEndIndex = name.length() - 1;

        int postfixLength = Dimensions.length(postfixStartIndex, postfixEndIndex);

        if (postfixLength > 0) {
            String postfix = name.substring(postfixStartIndex, postfixEndIndex + 1);
            result.append(postfix);
        }

        return result.toString();
    }

    /**
     * Gets the name of a variable.
     */
    private static String getVariableName(String variable) {
        if (variable == null || variable.length() < 2) {
            String errorMessage = "Invalid length. Variable pattern: " + variablePattern;

            log.error(errorMessage);
            throw new BaseException(errorMessage);
        }

        char first = variable.charAt(0);

        if (first != '$') {
            String errorMessage = "The variable does not start with a $. Variable pattern: " + variablePattern;

            log.error(errorMessage);
            throw new BaseException(errorMessage);
        }

        int startIndex = 1;
        int endIndex = variable.length() - 1;

        if (variable.charAt(startIndex) == '{' && variable.charAt(endIndex) == '}') {
            ++startIndex;
            --endIndex;
        }

        int nameLength = Dimensions.length(startIndex, endIndex);

        if (nameLength == 0) {
            String errorMessage = "The variable is not defined. Variable pattern: " + variablePattern;

            log.error(errorMessage);
            throw new BaseException(errorMessage);
        }

        return variable.substring(startIndex, endIndex + 1);
    }

    /**
     * Gets the operating system transformer.
     */
    public static IStringTransformer operatingSystemTransformer() {
        return new OperatingSystemTypeTransformer();
    }

    /**
     * The OperatingSystemTypeTransformer class implements a transformer of an operating system type.
     */
    private static final class OperatingSystemTypeTransformer implements IStringTransformer {
        @Override
        public String transform(String value) {
            OperatingSystemType type = OperatingSystemType.getOperatingSystem(value);
            return type.name().toLowerCase();
        }
    }

    /**
     * Disables the default constructor - This is a static class.
     */
    private Environment() {
    }
}
