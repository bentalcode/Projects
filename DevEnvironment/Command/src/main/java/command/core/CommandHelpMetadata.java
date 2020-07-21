package command.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.core.Strings;
import base.interfaces.IBinaryComparator;
import command.interfaces.ICommandHelpMetadata;
import json.core.JsonObjectStream;
import json.interfaces.IJsonObjectReader;
import json.interfaces.IJsonObjectWriter;

/**
 * The CommandHelpMetadata class implements meta-data of help of a command.
 */
public final class CommandHelpMetadata implements ICommandHelpMetadata {
    public static final int helpParameterSetIndex = -1;

    private static final String propertyShortName = "shortName";
    private static final String propertyLongName = "longName";
    private static final String propertyUsageMessage = "usageMessage";

    private static final String defaultShortName = ICommandConstants.helpShortName;
    private static final String defaultLongName = ICommandConstants.helpLongName;

    private final String shortName;
    private final String longName;
    private final String usageMessage;

    private final IBinaryComparator<ICommandHelpMetadata> comparator = defaultComparator();
    private final int hashCode;

    /**
     * The CommandHelpMetadata constructor.
     */
    public CommandHelpMetadata(
        String shortName,
        String longName,
        String usageMessage) {

        Conditions.validate(
            !Strings.isNullOrEmpty(shortName) || !Strings.isNullOrEmpty(longName),
            "Either the short name or the long name of a metadata of a help parameter has to be defined.");

        Conditions.validateStringNotNullOrEmpty(
            usageMessage,
            "The usage message of a command.");

        this.shortName = shortName;
        this.longName = longName;
        this.usageMessage = usageMessage;

        this.hashCode = this.comparator.hashCode();
    }

    /**
     * Gets a short name of the parameter.
     */
    @Override
    public String getShortName() {
        return this.shortName;
    }

    /**
     * Gets a long name of the parameter.
     */
    @Override
    public String getLongName() {
        return this.longName;
    }

    /**
     * Gets a usage message of a command.
     */
    @Override
    public String getUsageMessage() {
        return this.usageMessage;
    }

    /**
     * Gets the string representation of this instance.
     */
    @Override
    public String toString() {
        return JsonObjectStream.serialize(this);
    }

    /**
     * Serializes an object from a json.
     */
    public static ICommandHelpMetadata fromJson(String json) {
        return JsonObjectStream.deserialize(json, CommandHelpMetadata.class);
    }

    /**
     * Writes an object to a json writer.
     */
    @Override
    public void writeJson(IJsonObjectWriter writer) {
        if (this.shortName != null) {
            writer.writeStringProperty(propertyShortName, this.shortName);
        }

        if (this.longName != null) {
            writer.writeStringProperty(propertyLongName, this.longName);
        }

        writer.writeStringProperty(propertyUsageMessage, this.usageMessage);
    }

    /**
     * Reads a json.
     */
    public static ICommandHelpMetadata readJson(IJsonObjectReader reader) {
        String shortName = reader.hasProperty(propertyShortName) ?
            reader.readStringProperty(propertyShortName) :
            defaultShortName;

        String longName = reader.hasProperty(propertyLongName) ?
            reader.readStringProperty(propertyLongName) :
            defaultLongName;

        String usageMessage = reader.readStringProperty(propertyUsageMessage);

        return new CommandHelpMetadata(
            shortName,
            longName,
            usageMessage);
    }

    /**
     * Gets the hash code.
     */
    @Override
    public int hashCode() {
        return this.hashCode;
    }

    /**
     * Checks whether the instances are equals.
     */
    @Override
    public boolean equals(Object other) {
        if (other == null) {
            return false;
        }

        if (this == other) {
            return true;
        }

        if (!this.getClass().isInstance(other)) {
            return false;
        }

        return this.isEqual(Casting.cast(other));
    }

    /**
     * Checks whether the instances are equals.
     */
    @Override
    public boolean isEqual(ICommandHelpMetadata other) {
        return this.comparator.isEqual(this, other);
    }

    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    @Override
    public int compareTo(ICommandHelpMetadata other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<ICommandHelpMetadata> defaultComparator() {
        return new Comparator();
    }

    /**
     * The Comparator class implements a comparator of a meta-data of help of a command.
     */
    public static final class Comparator extends AbstractBinaryComparator<ICommandHelpMetadata> {
        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(ICommandHelpMetadata obj) {
            return new HashCodeBuilder(193, 197)
                .withString(obj.getShortName())
                .withString(obj.getLongName())
                .withString(obj.getUsageMessage())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(ICommandHelpMetadata lhs, ICommandHelpMetadata rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withString(lhs.getShortName(), rhs.getShortName())
                .withString(lhs.getLongName(), rhs.getLongName())
                .withString(lhs.getUsageMessage(), rhs.getUsageMessage())
                .build();
        }

        /**
         * Determines the relative order of two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        @Override
        public int compareTo(ICommandHelpMetadata lhs, ICommandHelpMetadata rhs) {
            if (lhs == null && rhs == null) {
                return 0;
            }

            if (lhs == null) {
                return -1;
            }

            if (rhs == null) {
                return 1;
            }

            return new CompareToBuilder()
                .withString(lhs.getShortName(), rhs.getShortName())
                .withString(lhs.getLongName(), rhs.getLongName())
                .withString(lhs.getUsageMessage(), rhs.getUsageMessage())
                .build();
        }
    }
}

