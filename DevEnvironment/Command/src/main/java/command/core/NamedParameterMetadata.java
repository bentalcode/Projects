package command.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.core.Strings;
import base.interfaces.IBinaryComparator;
import command.interfaces.INamedParameterMetadata;
import json.core.JsonObjectStream;
import json.interfaces.IJsonObjectReader;
import json.interfaces.IJsonObjectWriter;

/**
 * The NamedParameterMetadata class implements meta-data of a named parameter.
 */
public final class NamedParameterMetadata extends ParameterMetadata implements INamedParameterMetadata {
    private static final String PROPERTY_SHORT_NAME = "shortName";
    private static final String PROPERTY_LONG_NAME = "longName";
    private static final String PROPERTY_OPTIONAL = "optional";
    private static final String PROPERTY_DEFAULT_VALUE = "defaultValue";
    private static final boolean DEFAULT_OPTIONAL_VALUE = false;

    private final String shortName;
    private final String longName;
    private final String shortNameKey;
    private final String longNameKey;
    private final boolean optional;
    private final String defaultValue;

    private final IBinaryComparator<INamedParameterMetadata> comparator = defaultComparator();
    private final int hashCode;

    /**
     * Creates a parameter meta-data.
     */
    public static INamedParameterMetadata make(
        String name,
        String shortName,
        String longName,
        String description) {

        return new NamedParameterMetadata(
            name,
            shortName,
            longName,
            description,
            false,
            null);
    }

    /**
     * Creates an optional parameter meta-data.
     */
    public static INamedParameterMetadata makeOptional(
        String name,
        String shortName,
        String longName,
        String description,
        String defaultValue) {

        return new NamedParameterMetadata(
            name,
            shortName,
            longName,
            description,
            true,
            defaultValue);
    }

    /**
     * The NamedParameterMetadata constructor.
     */
    public NamedParameterMetadata(
        String name,
        String shortName,
        String longName,
        String description,
        boolean optional,
        String defaultValue) {

        super(
            name,
            description);

        Conditions.validate(
            !Strings.isNullOrEmpty(shortName) || !Strings.isNullOrEmpty(longName),
            "Either the short name or the long name of a metadata of a named parameter has to be defined.");

        this.shortName = shortName;
        this.longName = longName;
        this.shortNameKey = ICommandConstants.shortNamedParameterPrefix + shortName;
        this.longNameKey = ICommandConstants.longNamedParameterPrefix + longName;
        this.optional = optional;
        this.defaultValue = defaultValue;

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
     * Gets a short name key of the parameter.
     */
    @Override
    public String getShortNameKey() {
        return this.shortNameKey;
    }

    /**
     * Gets a long name key of the parameter.
     */
    @Override
    public String getLongNameKey() {
        return this.longNameKey;
    }

    /**
     * Returns whether a parameter is optional.
     */
    @Override
    public boolean optional() {
        return this.optional;
    }

    /**
     * Gets the default value.
     */
    @Override
    public String getDefaultValue() {
        return this.defaultValue;
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
    public static INamedParameterMetadata fromJson(String json) {
        return JsonObjectStream.deserialize(json, NamedParameterMetadata.class);
    }

    /**
     * Writes an object to a json writer.
     */
    @Override
    public void writeJson(IJsonObjectWriter writer) {
        super.writeJson(writer);

        if (this.shortName != null) {
            writer.writeStringProperty(PROPERTY_SHORT_NAME, this.shortName);
        }

        if (this.longName != null) {
            writer.writeStringProperty(PROPERTY_LONG_NAME, this.longName);
        }

        writer.writeBooleanProperty(PROPERTY_OPTIONAL, this.optional);

        if (this.defaultValue != null) {
            writer.writeStringProperty(PROPERTY_DEFAULT_VALUE, this.defaultValue);
        }
    }

    /**
     * Reads a json.
     */
    public static INamedParameterMetadata readJson(IJsonObjectReader reader) {
        String name = reader.readStringProperty(PROPERTY_NAME);

        String shortName = reader.hasProperty(PROPERTY_SHORT_NAME) ?
            reader.readStringProperty(PROPERTY_SHORT_NAME) :
            null;

        String longName = reader.hasProperty(PROPERTY_LONG_NAME) ?
            reader.readStringProperty(PROPERTY_LONG_NAME) :
            null;

        String description = reader.readStringProperty(PROPERTY_DESCRIPTION);

        boolean optional = reader.hasProperty(PROPERTY_OPTIONAL) ?
            reader.readBooleanProperty(PROPERTY_OPTIONAL) : DEFAULT_OPTIONAL_VALUE;

        String defaultValue = reader.hasProperty(PROPERTY_DEFAULT_VALUE) ?
            reader.readStringProperty(PROPERTY_DEFAULT_VALUE) :
            null;

        return new NamedParameterMetadata(
            name,
            shortName,
            longName,
            description,
            optional,
            defaultValue);
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
    public boolean isEqual(INamedParameterMetadata other) {
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
    public int compareTo(INamedParameterMetadata other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<INamedParameterMetadata> defaultComparator() {
        return new Comparator();
    }

    /**
     * The Comparator class implements a comparator of a meta-data of a parameter of a command.
     */
    public static final class Comparator extends AbstractBinaryComparator<INamedParameterMetadata> {
        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(INamedParameterMetadata obj) {
            return new HashCodeBuilder(229, 233)
                .withString(obj.getName())
                .withString(obj.getShortName())
                .withString(obj.getLongName())
                .withString(obj.getDescription())
                .withBoolean(obj.optional())
                .withString(obj.getDefaultValue())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(INamedParameterMetadata lhs, INamedParameterMetadata rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withString(lhs.getName(), rhs.getName())
                .withString(lhs.getShortName(), rhs.getShortName())
                .withString(lhs.getLongName(), rhs.getLongName())
                .withString(lhs.getDescription(), rhs.getDescription())
                .withBoolean(lhs.optional(), rhs.optional())
                .withString(lhs.getDefaultValue(), rhs.getDefaultValue())
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
        public int compareTo(INamedParameterMetadata lhs, INamedParameterMetadata rhs) {
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
                .withString(lhs.getName(), rhs.getName())
                .withString(lhs.getShortName(), rhs.getShortName())
                .withString(lhs.getLongName(), rhs.getLongName())
                .withString(lhs.getDescription(), rhs.getDescription())
                .withBoolean(lhs.optional(), rhs.optional())
                .withString(lhs.getDefaultValue(), rhs.getDefaultValue())
                .build();
        }
    }
}

