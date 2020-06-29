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
    private static final String propertyShortName = "shortName";
    private static final String propertyLongName = "longName";
    private static final String propertyOptional = "optional";

    private static final boolean defaultOptionalValue = false;

    private final String shortName;
    private final String longName;
    private final boolean optional;

    private final IBinaryComparator<INamedParameterMetadata> comparator = defaultComparator();
    private final int hashCode;

    /**
     * The NamedParameterMetadata constructor.
     */
    public NamedParameterMetadata(
        String name,
        String shortName,
        String longName,
        String description,
        boolean optional) {

        super(
            name,
            description);

        Conditions.validate(
            !Strings.isNullOrEmpty(shortName) || !Strings.isNullOrEmpty(longName),
            "Either the short name or the long name of a metadata of a named parameter has to be defined.");

        this.shortName = shortName;
        this.longName = longName;
        this.optional = optional;

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
        return ICommandConstants.shortNamedParameterPrefix + this.shortName;
    }

    /**
     * Gets a long name key of the parameter.
     */
    @Override
    public String getLongNameKey() {
        return ICommandConstants.longNamedParameterPrefix + this.longName;
    }

    /**
     * Returns whether a parameter is optional.
     */
    @Override
    public boolean optional() {
        return this.optional;
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
            writer.writeStringProperty(propertyShortName, this.shortName);
        }

        if (this.longName != null) {
            writer.writeStringProperty(propertyLongName, this.longName);
        }

        writer.writeBooleanProperty(propertyOptional, this.optional);
    }

    /**
     * Reads a json.
     */
    public static INamedParameterMetadata readJson(IJsonObjectReader reader) {
        String name = reader.readStringProperty(propertyName);

        String shortName = reader.hasProperty(propertyShortName) ?
            reader.readStringProperty(propertyShortName) :
            null;

        String longName = reader.hasProperty(propertyLongName) ?
            reader.readStringProperty(propertyLongName) :
            null;

        String description = reader.readStringProperty(propertyDescription);

        boolean optional = reader.hasProperty(propertyOptional) ?
            reader.readBooleanProperty(propertyOptional) : defaultOptionalValue;

        return new NamedParameterMetadata(
            name,
            shortName,
            longName,
            description,
            optional);
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
            return new HashCodeBuilder(3, 5)
                .withString(obj.getName())
                .withString(obj.getShortName())
                .withString(obj.getLongName())
                .withString(obj.getDescription())
                .withBoolean(obj.optional())
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
                .build();
        }
    }
}

