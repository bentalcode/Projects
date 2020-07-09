package cmakebuildsystem.core;

import base.core.Conditions;
import base.core.Paths;
import base.core.UnixPath;
import base.interfaces.IPathMatcher;
import cmakebuildsystem.interfaces.ICMakeBuildElement;
import cmakebuildsystem.interfaces.ICMakeBuildCommand;
import cmakebuildsystem.interfaces.ICMakeListsManifest;
import cmakebuildsystem.interfaces.ICMakeModule;
import cmakebuildsystem.interfaces.ICMakeVariable;
import cmakebuildsystem.interfaces.ICMakeWriter;
import cmakebuildsystem.interfaces.IIgnoreRules;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * The ModuleSection class implements a section of a module.
 */
public final class ModuleSection implements ICMakeBuildElement {
    private final ICMakeModule rootModule;
    private final ICMakeModule module;
    private final IIgnoreRules ignoreRules;

    /**
     * The ModuleLibrarySection constructor.
     */
    public ModuleSection(
        ICMakeModule rootModule,
        ICMakeModule module,
        IIgnoreRules ignoreRules) {

        Conditions.validateNotNull(
            module,
            "The CMake module.");

        Conditions.validateNotNull(
            ignoreRules,
            "The ignore rules.");

        this.rootModule = rootModule;
        this.module = module;
        this.ignoreRules = ignoreRules;
    }

    /**
     * Compiles a CMake build.
     */
    @Override
    public void compile(
        ICMakeWriter writer,
        ICMakeBuildContextData contextData) {

        Conditions.validateNotNull(
            writer,
            "The CMake writer.");

        Conditions.validateNotNull(
            contextData,
            "The context data.");

        ICMakeModuleContextData moduleContextData = contextData.getModuleContextData(this.module.getName());

        //
        // Writes includes files section...
        //
        List<String> includesDirectories = new ArrayList<>();
        ICMakeVariable includesFilesVariable = this.writeModuleIncludesFilesSection(
            writer,
            moduleContextData.getManifest().getCMakeListsManifest(),
            includesDirectories,
            contextData);

        writer.newLine();

        //
        // Writes sources files section...
        //
        ICMakeVariable sourcesFilesVariable = this.writeModuleSourcesFilesSection(
            writer,
            moduleContextData.getManifest().getCMakeListsManifest(),
            contextData);

        writer.newLine();

        //
        // Writes sources section...
        //
        ICMakeVariable sourcesVariable = this.writeModuleSourcesSection(
            writer,
            includesFilesVariable,
            sourcesFilesVariable,
            contextData);

        writer.newLine();

        //
        // Writes includes section...
        //
        ICMakeVariable includesVariable = this.writeModuleIncludesSection(
            writer,
            moduleContextData.getManifest().getCMakeListsManifest(),
            contextData,
            includesDirectories);

        moduleContextData.setVariable(includesVariable);
        moduleContextData.setVariable(sourcesVariable);
    }

    /**
     * Writes an includes files section of a module.
     */
    private ICMakeVariable writeModuleIncludesFilesSection(
        ICMakeWriter writer,
        ICMakeListsManifest manifest,
        List<String> includeDirectories,
        ICMakeBuildContextData contextData) {

        ICMakeVariable variable = CMakeVariable.createVariable(
            this.module.getName(),
            manifest.getIncludesFilesProperty());

        List<String> files = this.normalizeFilePaths(this.module.getHeaderFilesPaths());

        List<String> directories = this.getDirectories(files);
        includeDirectories.addAll(directories);

        ICMakeBuildCommand setCommand = new SetCommand(
            variable.getName(),
            files);

        setCommand.compile(
            writer,
            contextData);

        return variable;
    }

    /**
     * Writes a sources files section of a module.
     */
    private ICMakeVariable writeModuleSourcesFilesSection(
        ICMakeWriter writer,
        ICMakeListsManifest manifest,
        ICMakeBuildContextData contextData) {

        ICMakeVariable variable = CMakeVariable.createVariable(
            this.module.getName(),
            manifest.getSourcesFilesProperty());

        List<String> files = this.normalizeFilePaths(this.module.getSourceFilesPaths());

        ICMakeBuildCommand setCommand = new SetCommand(
            variable.getName(),
            files);

        setCommand.compile(
            writer,
            contextData);

        return variable;
    }

    /**
     * Writes a sources section of a module.
     */
    private ICMakeVariable writeModuleSourcesSection(
        ICMakeWriter writer,
        ICMakeVariable includesFilesVariable,
        ICMakeVariable sourcesFilesVariable,
        ICMakeBuildContextData contextData) {

        ICMakeModuleContextData moduleContextData = contextData.getModuleContextData(this.module.getName());
        ICMakeVariable sourcesVariable = CMakeModule.createSourcesVariable(moduleContextData);

        List<String> variables = new ArrayList<>();
        variables.add(includesFilesVariable.getVariable());
        variables.add(sourcesFilesVariable.getVariable());

        ICMakeBuildCommand setCommand = new SetCommand(
            sourcesVariable.getName(),
            variables);

        setCommand.compile(
            writer,
            contextData);

        return sourcesVariable;
    }

    /**
     * Writes an includes section of a module.
     */
    private ICMakeVariable writeModuleIncludesSection(
        ICMakeWriter writer,
        ICMakeListsManifest manifest,
        ICMakeBuildContextData contextData,
        List<String> directories) {

        ICMakeVariable includesVariable = CMakeVariable.createVariable(
            this.module.getName(),
            manifest.getIncludesProperty());

        ICMakeBuildCommand setCommand = new SetCommand(
            includesVariable.getName(),
            directories);

        setCommand.compile(
            writer,
            contextData);

        return includesVariable;
    }

    /**
     * Normalizes the file paths.
     */
    private List<String> normalizeFilePaths(List<Path> paths) {
        List<String> result = new ArrayList<>();

        IPathMatcher ignoreMatcher = new CMakePathMatcher(this.ignoreRules.getPathPatterns());

        Path currentPath = this.getRootPath();

        for (Path path : paths) {
            if (ignoreMatcher.match(path.toString())) {
                continue;
            }

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
    private List<String> getDirectories(List<String> filePaths) {
        Set<String> directories = new HashSet<>();

        for (String filePath : filePaths) {
            String directory = UnixPath.getDirectory(filePath);
            directories.add(directory);
        }

        List<String> result = new ArrayList<>(directories);
        Collections.sort(result);

        return result;
    }

    /**
     * Gets the root path.
     */
    private Path getRootPath() {
        if (this.rootModule != null) {
            return this.rootModule.getRootPath();
        }
        else {
            return this.module.getRootPath();
        }
    }
}
