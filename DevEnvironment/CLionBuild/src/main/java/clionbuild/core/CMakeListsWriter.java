package clionbuild.core;

import base.core.Conditions;
import base.core.Paths;
import base.core.ResourceReader;
import base.core.UnixPath;
import base.core.Writers;
import base.interfaces.IPathMatcher;
import base.interfaces.IWriter;
import clionbuild.interfaces.ICLionModule;
import clionbuild.interfaces.ICMakeListsManifest;
import clionbuild.interfaces.IEditorSettings;
import clionbuild.interfaces.IIgnoreRules;
import java.io.Writer;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * The CMakeListsWriter class implements a writer of a CLionLists file.
 */
public final class CMakeListsWriter implements IWriter {
    private final ICMakeListsManifest manifest;
    private final ICLionModule module;
    private final IEditorSettings editorSettings;
    private final IIgnoreRules ignoreRules;
    private int indentationSize;

    /**
     * The CMakeListsWriter constructor.
     */
    public CMakeListsWriter(
        ICMakeListsManifest manifest,
        ICLionModule module,
        IEditorSettings editorSettings,
        IIgnoreRules ignoreRules) {

        Conditions.validateNotNull(
            manifest,
            "The manifest of a CMakeLists file.");

        Conditions.validateNotNull(
            module,
            "The CLion module.");

        Conditions.validateNotNull(
            editorSettings,
            "The settings of an editor.");

        Conditions.validateNotNull(
            ignoreRules,
            "The ignore rules.");

        this.manifest = manifest;
        this.module = module;
        this.editorSettings = editorSettings;
        this.ignoreRules = ignoreRules;
    }

    /**
     * Writes a the CLion module.
     */
    @Override
    public void write(Writer writer) {
        this.writeCMakeVersion(writer);
        this.writeNewLine(writer);

        this.writeProjectVersion(writer);
        this.writeNewLine(writer);

        this.writePresetSection(writer);
        this.writeNewLine(writer);

        this.writeModuleLibrarySection(writer);
        this.writeNewLine(writer);

        this.writePostsetSection(writer);
        this.writeNewLine(writer);
    }

    /**
     * Gets a name of a module.
     */
    private String getModuleName() {
        String name = this.manifest.getName();
        return name;
    }

    /**
     * Writes a CMake version.
     */
    private void writeCMakeVersion(Writer writer) {
        String line =
            ICMakeListsConstants.cmakeMinimumRequired +
            "(" + ICMakeListsConstants.version + " " + this.manifest.getCMakeVersion() + ")";

        this.writeLine(writer, line);
    }

    /**
     * Writes a project version.
     */
    private void writeProjectVersion(Writer writer) {
        String line =
            ICMakeListsConstants.project +
            "(" + this.getModuleName() + " " + ICMakeListsConstants.version + " " + this.manifest.getProjectVersion() + ")";

        this.writeLine(writer, line);
    }

    /**
     * Writes a preset section.
     */
    private void writePresetSection(Writer writer) {
        this.writeSectionFromResource(writer, this.manifest.getPresetPath());
    }

    /**
     * Writes a postset section.
     */
    private void writePostsetSection(Writer writer) {
        this.writeSectionFromResource(writer, this.manifest.getPostsetPath());
    }

    /**
     * Writes a library section of the module.
     */
    private void writeModuleLibrarySection(Writer writer) {
        List<String> includesDirectories = new ArrayList<>();
        String includesFilesVariableName = this.writeModuleIncludesFilesSection(writer, includesDirectories);

        this.writeNewLine(writer);

        String sourcesFilesVariableName = this.writeModuleSourcesFilesSection(writer);

        this.writeNewLine(writer);

        String sourcesVariableName = this.writeModuleSourcesSection(
            writer,
            includesFilesVariableName,
            sourcesFilesVariableName);

        this.writeNewLine(writer);

        String includesVariableName = this.writeModuleIncludesSection(
            writer,
            includesDirectories);

        this.writeNewLine(writer);

        List<String> includesVariables = new ArrayList<>();
        includesVariables.add(includesVariableName);

        this.writeIncludesDirectoryInstruction(
            writer,
            includesVariables);

        this.writeNewLine(writer);

        this.writeAddLibraryInstruction(
            writer,
            this.getModuleName(),
            sourcesVariableName);
    }

    /**
     * Writes an includes files section of a module.
     */
    private String writeModuleIncludesFilesSection(Writer writer, List<String> includeDirectories) {
        String variableName = this.createIncludesFilesVariableName(this.module.getName());

        List<String> files = this.normalizeFilePaths(this.module.getHeaderFilesPaths());

        Set<String> directories = this.getDirectories(files);
        includeDirectories.addAll(directories);

        this.writeSetInstruction(writer, variableName, files);

        return variableName;
    }

    /**
     * Writes a sources files section of a module.
     */
    private String writeModuleSourcesFilesSection(Writer writer) {
        String variableName = this.createSourcesFilesVariableName(this.module.getName());

        List<String> files = this.normalizeFilePaths(this.module.getSourceFilesPaths());
        this.writeSetInstruction(writer, variableName, files);

        return variableName;
    }

    /**
     * Writes a sources section of a module.
     */
    private String writeModuleSourcesSection(
        Writer writer,
        String includesFilesVariableName,
        String sourcesFilesVariableName) {

        String sourcesVariableName = this.createSourcesVariableName(this.module.getName());

        String includeFilesVariable = this.createVariable(includesFilesVariableName);
        String sourcesFilesVariable = this.createVariable(sourcesFilesVariableName);

        List<String> variables = new ArrayList<>();
        variables.add(includeFilesVariable);
        variables.add(sourcesFilesVariable);

        this.writeSetInstruction(writer, sourcesVariableName, variables);

        return sourcesVariableName;
    }

    /**
     * Writes an includes section of a module.
     */
    private String writeModuleIncludesSection(
        Writer writer,
        List<String> directories) {

        String variableName = this.createIncludesVariableName(this.module.getName());
        this.writeSetInstruction(writer, variableName, directories);
        return variableName;
    }

    /**
     * Writes a set instruction.
     */
    private void writeSetInstruction(
        Writer writer,
        String setVariable,
        List<String> items) {

        String setInstruction = ICMakeListsConstants.setInstruction + "(" + setVariable;
        this.writeLine(writer, setInstruction);

        this.indentationSize += this.editorSettings.getTabSize();

        for (String item : items) {
            this.writeLine(writer, item);
        }

        this.indentationSize -= this.editorSettings.getTabSize();

        this.writeLine(writer, ")");
    }

    /**
     * Writes an includes directory instruction.
     */
    private void writeIncludesDirectoryInstruction(
        Writer writer,
        List<String> variableNames) {

        String includeDirectoriesInstruction = ICMakeListsConstants.includeDirectoriesInstruction + "(" ;
        this.writeLine(writer, includeDirectoriesInstruction);

        this.indentationSize += this.editorSettings.getTabSize();

        for (String variableName : variableNames) {
            String variable = this.createVariable(variableName);
            this.writeLine(writer, variable);
        }

        this.indentationSize -= this.editorSettings.getTabSize();

        this.writeLine(writer, ")");
    }

    /**
     * Writes an add library instruction.
     */
    private void writeAddLibraryInstruction(
        Writer writer,
        String moduleName,
        String sourcesVariableName) {

        String sourcesVariable = this.createVariable(sourcesVariableName);

        String addLibraryInstruction =
            ICMakeListsConstants.addLibraryInstruction + "(" + moduleName + " " + sourcesVariable + ")";

        this.writeLine(writer, addLibraryInstruction);
    }

    /**
     * Creates a variable.
     */
    private String createVariable(String variableName) {
        String variable = "${" + variableName + "}";
        return variable;
    }

    /**
     * Writes a section from a resource.
     */
    private void writeSectionFromResource(Writer writer, String path) {
        if (path == null) {
            return;
        }

        String content = ResourceReader.loadString(path);
        this.writeLine(writer, content);
    }

    /**
     * Creates a variable name for the includes.
     */
    private String createIncludesVariableName(String moduleName) {
        String variableName = moduleName + "_" + this.manifest.getIncludesProperty();
        variableName = variableName.toUpperCase();
        return variableName;
    }

    /**
     * Creates a variable name for the sources.
     */
    private String createSourcesVariableName(String moduleName) {
        String variableName = moduleName + "_" + this.manifest.getSourcesProperty();
        variableName = variableName.toUpperCase();
        return variableName;
    }

    /**
     * Creates a variable name for the includes files.
     */
    private String createIncludesFilesVariableName(String moduleName) {
        String variableName = moduleName + "_" + this.manifest.getIncludesFilesProperty();
        variableName = variableName.toUpperCase();
        return variableName;
    }

    /**
     * Creates a variable name for the sources files.
     */
    private String createSourcesFilesVariableName(String moduleName) {
        String variableName = moduleName + "_" + this.manifest.getSourcesFilesProperty();
        variableName = variableName.toUpperCase();
        return variableName;
    }

    /**
     * Normalizes the file paths.
     */
    private List<String> normalizeFilePaths(List<Path> paths) {
        List<String> result = new ArrayList<>();

        IPathMatcher ignoreMatcher = new CMakePathMatcher(this.ignoreRules.getPathPatterns());

        Path currentPath = this.module.getRootPath();

        for (Path path : paths) {
            String relativePath = Paths.getRelativePath(path.toString(), currentPath.toString());

            if (relativePath != null && !ignoreMatcher.match(relativePath)) {
                relativePath = Paths.separatorToUnix(relativePath);
                result.add(relativePath);
            }
        }

        Collections.sort(result);

        return result;
    }

    /**
     * Gets the directories of the paths.
     */
    private Set<String> getDirectories(List<String> filePaths) {
        Set<String> result = new HashSet<>();

        for (String filePath : filePaths) {
            String directory = UnixPath.getDirectory(filePath);
            result.add(directory);
        }

        return result;
    }

    /**
     * Writes a line.
     */
    private void writeLine(Writer writer, String content) {
        String indentation = this.createIndentation();
        String line = indentation + content;

        Writers.write(writer, line);
        Writers.write(writer, "\n");
    }

    /**
     * Writes a new line.
     */
    private void writeNewLine(Writer writer) {
        Writers.write(writer, "\n");
    }

    /**
     * Creates an indentation string.
     */
    private String createIndentation() {
        if (this.indentationSize == 0) {
            return "";
        }

        char[] buffer = new char[this.indentationSize];
        for (int i = 0; i < this.indentationSize; ++i) {
            buffer[i] = ' ';
        }

        return new String(buffer);
    }
}
