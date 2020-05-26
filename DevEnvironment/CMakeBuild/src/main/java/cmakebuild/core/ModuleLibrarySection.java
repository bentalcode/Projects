package cmakebuild.core;

import base.core.Conditions;
import base.core.Pair;
import base.core.Paths;
import base.core.UnixPath;
import base.interfaces.IPair;
import base.interfaces.IPathMatcher;
import cmakebuild.interfaces.ICMakeBuildElement;
import cmakebuild.interfaces.ICMakeBuildInstruction;
import cmakebuild.interfaces.ICMakeListsManifest;
import cmakebuild.interfaces.ICMakeModule;
import cmakebuild.interfaces.ICMakeVariable;
import cmakebuild.interfaces.ICMakeWriter;
import cmakebuild.interfaces.IIgnoreRules;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * The ModuleLibrarySection class implements a section of a module library.
 */
public final class ModuleLibrarySection implements ICMakeBuildElement {
    private final ICMakeListsManifest manifest;
    private final ICMakeModule module;
    private final IIgnoreRules ignoreRules;

    /**
     * The ModuleLibrarySection constructor.
     */
    public ModuleLibrarySection(
        ICMakeListsManifest manifest,
        ICMakeModule module,
        IIgnoreRules ignoreRules) {

        Conditions.validateNotNull(
            manifest,
            "The manifest of a CMakeLists file.");

        Conditions.validateNotNull(
            module,
            "The CMake module.");

        Conditions.validateNotNull(
            ignoreRules,
            "The ignore rules.");

        this.manifest = manifest;
        this.module = module;
        this.ignoreRules = ignoreRules;
    }

    /**
     * Compiles a CMake build.
     */
    @Override
    public void compile(ICMakeWriter writer) {
        Conditions.validateNotNull(
            writer,
            "The CMake writer.");

        //
        // Writes includes files section...
        //
        List<String> includesDirectories = new ArrayList<>();
        ICMakeVariable includesFilesVariable = this.writeModuleIncludesFilesSection(
            writer,
            includesDirectories);

        writer.newLine();

        //
        // Writes sources files section...
        //
        ICMakeVariable sourcesFilesVariable = this.writeModuleSourcesFilesSection(writer);

        writer.newLine();

        //
        // Writes sources section...
        //
        ICMakeVariable sourcesVariable = this.writeModuleSourcesSection(
            writer,
            includesFilesVariable,
            sourcesFilesVariable);

        writer.newLine();

        //
        // Writes includes section...
        //
        ICMakeVariable includesVariable = this.writeModuleIncludesSection(
            writer,
            includesDirectories);

        writer.newLine();

        //
        // Writes includes directory section...
        //
        this.writeModuleIncludesDirectorySection(
            writer,
            includesVariable);

        writer.newLine();

        //
        // Writes an add library section...
        //
        List<IPair<String, ICMakeVariable>> modules = new ArrayList<>();
        modules.add(Pair.of(this.module.getName(), sourcesVariable));

        this.writeAddLibrarySection(
            writer,
            modules);
    }

    /**
     * Writes an includes files section of a module.
     */
    private ICMakeVariable writeModuleIncludesFilesSection(
        ICMakeWriter writer,
        List<String> includeDirectories) {

        ICMakeVariable variable = CMakeVariable.createVariable(
            this.module.getName(),
            this.manifest.getIncludesFilesProperty());

        List<String> files = this.normalizeFilePaths(this.module.getHeaderFilesPaths());

        Set<String> directories = this.getDirectories(files);
        includeDirectories.addAll(directories);

        ICMakeBuildInstruction setInstruction = new SetInstruction(
            variable,
            files);

        setInstruction.compile(writer);

        return variable;
    }

    /**
     * Writes a sources files section of a module.
     */
    private ICMakeVariable writeModuleSourcesFilesSection(ICMakeWriter writer) {
        ICMakeVariable variable = CMakeVariable.createVariable(
            this.module.getName(),
            this.manifest.getSourcesFilesProperty());

        List<String> files = this.normalizeFilePaths(this.module.getSourceFilesPaths());

        ICMakeBuildInstruction setInstruction = new SetInstruction(
            variable,
            files);

        setInstruction.compile(writer);

        return variable;
    }

    /**
     * Writes a sources section of a module.
     */
    private ICMakeVariable writeModuleSourcesSection(
        ICMakeWriter writer,
        ICMakeVariable includesFilesVariable,
        ICMakeVariable sourcesFilesVariable) {

        ICMakeVariable sourcesVariable = CMakeVariable.createVariable(
            this.module.getName(),
            this.manifest.getSourcesProperty());

        List<String> variables = new ArrayList<>();
        variables.add(includesFilesVariable.getVariable());
        variables.add(sourcesFilesVariable.getVariable());

        ICMakeBuildInstruction setInstruction = new SetInstruction(
            sourcesVariable,
            variables);

        setInstruction.compile(writer);

        return sourcesVariable;
    }

    /**
     * Writes an includes section of a module.
     */
    private ICMakeVariable writeModuleIncludesSection(
        ICMakeWriter writer,
        List<String> directories) {

        ICMakeVariable includesVariable = CMakeVariable.createVariable(
            this.module.getName(),
            this.manifest.getIncludesProperty());

        ICMakeBuildInstruction setInstruction = new SetInstruction(
            includesVariable,
            directories);

        setInstruction.compile(writer);

        return includesVariable;
    }

    /**
     * Writes an includes directory section of a module.
     */
    private void writeModuleIncludesDirectorySection(
        ICMakeWriter writer,
        ICMakeVariable includesVariable) {

        List<ICMakeVariable> includesVariables = new ArrayList<>();
        includesVariables.add(includesVariable);

        ICMakeBuildInstruction includesDirectoryInstruction = new IncludesDirectoryInstruction(includesVariables);

        includesDirectoryInstruction.compile(writer);
    }

    /**
     * Writes an add library section of a module.
     */
    private void writeAddLibrarySection(
        ICMakeWriter writer,
        List<IPair<String, ICMakeVariable>> modules) {

        ICMakeBuildInstruction addLibraryInstruction = new AddLibraryInstruction(modules);
        addLibraryInstruction.compile(writer);
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
}
