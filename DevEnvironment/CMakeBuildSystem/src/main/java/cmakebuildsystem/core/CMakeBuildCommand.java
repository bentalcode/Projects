package cmakebuildsystem.core;

import base.core.Collections;
import base.core.Conditions;
import cmakebuildsystem.interfaces.ICMakeBuildCommand;
import cmakebuildsystem.interfaces.ICMakeWriter;
import java.util.List;

/**
 * The CMakeBuildCommand class implements a cmake command of a CMake build.
 */
abstract class CMakeBuildCommand implements ICMakeBuildCommand {
    private final String name;
    private final String subjectName;
    private final List<String> properties;

    /**
     * The CMakeBuildCommand constructor.
     */
    protected CMakeBuildCommand(
        String name,
        String subjectName) {

        this(
            name,
            subjectName,
            null);
    }

    /**
     * The CMakeBuildCommand constructor.
     */
    protected CMakeBuildCommand(
        String name,
        String subjectName,
        List<String> properties) {

        Conditions.validateStringNotNullOrEmpty(
            name,
            "The name of a command.");

        Conditions.validateStringNotNullOrEmpty(
            subjectName,
            "The subject name of a command.");

        this.name = name;
        this.subjectName = subjectName;
        this.properties = properties;
    }

    /**
     * Gets a name of a command.
     */
    @Override
    public String getName() {
        return this.name;
    }

    /**
     * Gets a subject name of a command.
     */
    @Override
    public String getSubjectName() {
        return this.subjectName;
    }

    /**
     * Gets properties of a command.
     */
    @Override
    public List<String> getProperties() {
        return this.properties;
    }

    /**
     * Begins a command.
     */
    protected void begin(ICMakeWriter writer) {
        StringBuilder header = new StringBuilder();

        header.append(this.name);
        header.append("(");

        if (this.subjectName != null) {
            header.append(this.subjectName);
        }

        if (this.properties != null) {
            String propertiesString = " " + Collections.toString(this.properties, " ");
            header.append(propertiesString);
        }

        writer.write(header.toString());
    }

    /**
     * Ends a command.
     */
    protected void end(ICMakeWriter writer) {
        writer.write(")");
    }

    /**
     * Adds a parameter.
     */
    protected void addParameter(
        ICMakeWriter writer,
        String parameter) {

        writer.rightIndent();
        writer.write(parameter);
        writer.leftIndent();
    }

    /**
     * Adds parameters.
     */
    protected void addParameters(
        ICMakeWriter writer,
        List<String> parameters) {

        writer.rightIndent();

        for (String parameter : parameters) {
            writer.write(parameter);
        }

        writer.leftIndent();
    }
}
