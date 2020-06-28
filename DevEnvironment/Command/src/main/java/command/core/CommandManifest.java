package command.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import command.interfaces.ICommandManifest;
import command.interfaces.IParameterSetMetadata;
import json.core.JsonObjectStream;
import json.interfaces.IJsonObjectReader;
import json.interfaces.IJsonObjectWriter;
import java.util.List;

/**
 * The CommandManifest class implements manifest of a command.
 */
public final class CommandManifest implements ICommandManifest {
    private static final String propertyName = "name";
    private static final String propertyDescription = "description";
    private static final String propertyHelpMessage = "helpMessage";
    private static final String propertyParameterSets = "parameterSets";

    private final String name;
    private final String description;
    private final String helpMessage;
    private final List<IParameterSetMetadata> parameterSets;

    private final IBinaryComparator<ICommandManifest> comparator = defaultComparator();
    private final int hashCode;

    /**
     * The CommandMetadata constructor.
     */
    public CommandManifest(
        String name,
        String description,
        String helpMessage,
        List<IParameterSetMetadata> parameterSets) {

        Conditions.validateStringNotNullOrEmpty(
            name,
            "The name of a command.");

        Conditions.validateStringNotNullOrEmpty(
            description,
            "The description of a command.");

        Conditions.validateStringNotNullOrEmpty(
            helpMessage,
            "The help message of a command.");

        Conditions.validateNotNull(
            parameterSets,
            "The parameters-set of a command.");

        this.name = name;
        this.description = description;
        this.helpMessage = helpMessage;
        this.parameterSets = parameterSets;

        this.hashCode = this.comparator.hashCode();
    }

    /**
     * Gets name of a command.
     */
    @Override
    public String getName() {
        return this.name;
    }

    /**
     * Gets description of a command.
     */
    @Override
    public String getDescription() {
        return this.description;
    }

    /**
     * Gets help message of a command.
     */
    @Override
    public String getHelpMessage() {
        return this.helpMessage;
    }

    /**
     * Gets parameter-sets of a command.
     */
    public List<IParameterSetMetadata> getParameterSets() {
        return this.parameterSets;
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
    public static ICommandManifest fromJson(String json) {
        return JsonObjectStream.deserialize(json, CommandManifest.class);
    }

    /**
     * Writes an object to a json writer.
     */
    @Override
    public void writeJson(IJsonObjectWriter writer) {
        writer.writeStringProperty(propertyName, this.name);
        writer.writeStringProperty(propertyDescription, this.description);
        writer.writeStringProperty(propertyHelpMessage, this.helpMessage);
        writer.writeCollectionProperty(propertyParameterSets, this.parameterSets);
    }

    /**
     * Reads a json.
     */
    public static ICommandManifest readJson(IJsonObjectReader reader) {
        String name = reader.readStringProperty(propertyName);
        String description = reader.readStringProperty(propertyDescription);
        String helpMessage = reader.readStringProperty(propertyHelpMessage);

        List<IParameterSetMetadata> parameterSets = reader.readListProperty(
            propertyParameterSets,
            ParameterSetMetadata.class);

        return new CommandManifest(
            name,
            description,
            helpMessage,
            parameterSets);
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
    public boolean isEqual(ICommandManifest other) {
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
    public int compareTo(ICommandManifest other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<ICommandManifest> defaultComparator() {
        return new Comparator();
    }

    /**
     * The Comparator class implements a comparator of a meta-data of a command.
     */
    public static final class Comparator extends AbstractBinaryComparator<ICommandManifest> {
        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(ICommandManifest obj) {
            return new HashCodeBuilder(3, 5)
                .withString(obj.getName())
                .withString(obj.getDescription())
                .withString(obj.getHelpMessage())
                .withCollection(obj.getParameterSets())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(ICommandManifest lhs, ICommandManifest rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withString(lhs.getName(), rhs.getName())
                .withString(lhs.getDescription(), rhs.getDescription())
                .withString(lhs.getHelpMessage(), rhs.getHelpMessage())
                .withCollection(lhs.getParameterSets(), rhs.getParameterSets())
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
        public int compareTo(ICommandManifest lhs, ICommandManifest rhs) {
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
                .withString(lhs.getDescription(), rhs.getDescription())
                .withString(lhs.getHelpMessage(), rhs.getHelpMessage())
                .withCollection(lhs.getParameterSets(), rhs.getParameterSets())
                .build();
        }
    }
}
