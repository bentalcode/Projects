package command.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.core.ResourceReader;
import base.interfaces.IBinaryComparator;
import command.interfaces.ICommandHelpMetadata;
import command.interfaces.ICommandManifest;
import command.interfaces.IParameterSetMetadata;
import java.nio.file.Path;
import java.util.List;
import json.core.JsonObjectStream;
import json.interfaces.IJsonObjectReader;
import json.interfaces.IJsonObjectWriter;

/**
 * The CommandManifest class implements a manifest of a command.
 */
public final class CommandManifest implements ICommandManifest {
    private static final String PROPERTY_NAME = "name";
    private static final String PROPERTY_DESCRIPTION = "description";
    private static final String PROPERTY_HELP = "help";
    private static final String PROPERTY_PARAMETER_SETS = "parameterSets";

    private final String name;
    private final String description;
    private final ICommandHelpMetadata helpMetadata;
    private final List<IParameterSetMetadata> parameterSetMetadata;

    private final IBinaryComparator<ICommandManifest> comparator = defaultComparator();
    private final int hashCode;

    /**
     * Creates a new command manifest.
     */
    public static ICommandManifest make(
        String name,
        String description,
        ICommandHelpMetadata helpMetadata,
        List<IParameterSetMetadata> parameterSetMetadata) {

        return new CommandManifest(
            name,
            description,
            helpMetadata,
            parameterSetMetadata);
    }

    /**
     * The CommandManifest constructor.
     */
    private CommandManifest(
        String name,
        String description,
        ICommandHelpMetadata helpMetadata,
        List<IParameterSetMetadata> parameterSetMetadata) {

        Conditions.validateStringNotNullOrEmpty(
            name,
            "The name of a command.");

        Conditions.validateStringNotNullOrEmpty(
            description,
            "The description of a command.");

        Conditions.validateNotNull(
            helpMetadata,
            "The help metadata of a command.");

        Conditions.validateNotNull(
            parameterSetMetadata,
            "The parameters-set of a command.");

        this.name = name;
        this.description = description;
        this.helpMetadata = helpMetadata;
        this.parameterSetMetadata = parameterSetMetadata;

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
     * Gets help metadata of a command.
     */
    @Override
    public ICommandHelpMetadata getHelpMetadata() {
        return this.helpMetadata;
    }

    /**
     * Gets parameter-sets metadata of a command.
     */
    public List<IParameterSetMetadata> getParameterSetMetadata() {
        return this.parameterSetMetadata;
    }

    /**
     * Gets the string representation of this instance.
     */
    @Override
    public String toString() {
        return JsonObjectStream.serialize(this);
    }

    /**
     * Loads a manifest from a resource file.
     */
    public static ICommandManifest load(Path path) {
        String json = ResourceReader.loadString(path);
        return fromJson(json);
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
        writer.writeStringProperty(PROPERTY_NAME, this.name);
        writer.writeStringProperty(PROPERTY_DESCRIPTION, this.description);
        writer.writeObjectProperty(PROPERTY_HELP, this.helpMetadata);
        writer.writeCollectionProperty(PROPERTY_PARAMETER_SETS, this.parameterSetMetadata);
    }

    /**
     * Reads a json.
     */
    public static ICommandManifest readJson(IJsonObjectReader reader) {
        String name = reader.readStringProperty(PROPERTY_NAME);
        String description = reader.readStringProperty(PROPERTY_DESCRIPTION);
        ICommandHelpMetadata help = reader.readObjectProperty(PROPERTY_HELP, CommandHelpMetadata.class);

        List<IParameterSetMetadata> parameterSets = reader.readListProperty(
                PROPERTY_PARAMETER_SETS,
            ParameterSetMetadata.class);

        return new CommandManifest(
            name,
            description,
            help,
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
            return new HashCodeBuilder(199, 211)
                .withString(obj.getName())
                .withString(obj.getDescription())
                .withObject(obj.getHelpMetadata())
                .withCollection(obj.getParameterSetMetadata())
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
                .withObject(lhs.getHelpMetadata(), rhs.getHelpMetadata())
                .withCollection(lhs.getParameterSetMetadata(), rhs.getParameterSetMetadata())
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
                .withObject(lhs.getHelpMetadata(), rhs.getHelpMetadata())
                .withCollection(lhs.getParameterSetMetadata(), rhs.getParameterSetMetadata())
                .build();
        }
    }
}
