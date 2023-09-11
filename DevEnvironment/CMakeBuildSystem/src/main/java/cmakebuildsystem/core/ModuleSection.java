package cmakebuildsystem.core;

import base.core.Conditions;
import base.core.Pair;
import base.core.Paths;
import base.core.StringEquality;
import base.core.UnixPath;
import base.core.UnixPathBuilder;
import base.interfaces.IPair;
import base.interfaces.IPathMatcher;
import cmakebuildsystem.interfaces.ICMakeBuildElement;
import cmakebuildsystem.interfaces.ICMakeBuildCommand;
import cmakebuildsystem.interfaces.ICMakeListsManifest;
import cmakebuildsystem.interfaces.ICMakeModule;
import cmakebuildsystem.interfaces.ICMakeModuleManifest;
import cmakebuildsystem.interfaces.ICMakeVariable;
import cmakebuildsystem.interfaces.ICMakeWriter;
import cmakebuildsystem.interfaces.IIgnoreRules;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
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
        Map<String, String> buildFilePaths = new HashMap<>();
        ICMakeVariable includesFilesVariable = this.writeModuleIncludesFilesSection(
            writer,
            moduleContextData.getManifest(),
            contextData,
            includesDirectories,
            buildFilePaths);

        writer.newLine();

        //
        // Writes sources files section...
        //
        ICMakeVariable sourcesFilesVariable = this.writeModuleSourcesFilesSection(
            writer,
            moduleContextData.getManifest(),
            contextData,
            buildFilePaths);

        writer.newLine();

        //
        // Write includes section...
        //
        ICMakeVariable includesVariable = this.writeModuleIncludesSection(
            writer,
            moduleContextData.getManifest().getCMakeListsManifest(),
            contextData,
            includesDirectories);

        writer.newLine();

        //
        // Writes sources section...
        //
        ICMakeVariable sourcesVariable = this.writeModuleSourcesSection(
            writer,
            includesFilesVariable,
            sourcesFilesVariable,
            contextData);

        //
        // Configure the build files...
        //
        if (!buildFilePaths.isEmpty()) {
            this.writeBuildFilesConfigurationSection(
                writer,
                buildFilePaths,
                contextData);
        }

        moduleContextData.setVariable(includesVariable);
        moduleContextData.setVariable(sourcesVariable);
    }

    /**
     * Writes an includes files section of a module.
     */
    private ICMakeVariable writeModuleIncludesFilesSection(
        ICMakeWriter writer,
        ICMakeModuleManifest manifest,
        ICMakeBuildContextData contextData,
        List<String> includeDirectories,
        Map<String, String> buildFilePaths) {

        ICMakeVariable variable = CMakeVariable.createVariable(
            this.module.getName(),
            manifest.getCMakeListsManifest().getIncludesFilesProperty());

        List<String> filePaths = this.normalizeFilePaths(this.module.getHeaderFilesPaths());

        transformBuildFilePaths(
            this.module.getRootPath(),
            this.module.getBuildFilesPaths(),
            manifest.getProperties().getBuildFileExtensions(),
            manifest.getProperties().getHeaderFileExtensions(),
            buildFilePaths);

        filePaths.addAll(buildFilePaths.values());

        List<String> directories = this.getDirectories(filePaths);
        includeDirectories.addAll(directories);

        ICMakeBuildCommand setCommand = SetCommand.make(
            variable.getName(),
            filePaths);

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
        ICMakeModuleManifest manifest,
        ICMakeBuildContextData contextData,
        Map<String, String> buildFilePaths) {

        ICMakeVariable variable = CMakeVariable.createVariable(
            this.module.getName(),
            manifest.getCMakeListsManifest().getSourcesFilesProperty());

        List<String> files = this.normalizeFilePaths(this.module.getSourceFilesPaths());

        transformBuildFilePaths(
            this.module.getRootPath(),
            this.module.getBuildFilesPaths(),
            manifest.getProperties().getBuildFileExtensions(),
            manifest.getProperties().getSourceFileExtensions(),
            buildFilePaths);

        ICMakeBuildCommand setCommand = SetCommand.make(
            variable.getName(),
            files);

        setCommand.compile(
            writer,
            contextData);

        return variable;
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

        ICMakeBuildCommand setCommand = SetCommand.make(
            includesVariable.getName(),
            directories);

        setCommand.compile(
            writer,
            contextData);

        return includesVariable;
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

        ICMakeBuildCommand setCommand = SetCommand.make(
            sourcesVariable.getName(),
            variables);

        setCommand.compile(
            writer,
            contextData);

        return sourcesVariable;
    }

    /**
     * Writes the build files configuration section.
     */
    private void writeBuildFilesConfigurationSection(
        ICMakeWriter writer,
        Map<String, String> paths,
        ICMakeBuildContextData contextData) {

        for (Map.Entry<String, String> entry : paths.entrySet()) {
            ICMakeBuildElement buildCommand = ConfigureFileCommand.make(
                entry.getKey(),
                entry.getValue());

            buildCommand.compile(
                writer,
                contextData);
        }
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
     * Transforms the build file paths.
     */
    private static void transformBuildFilePaths(
        Path rootPath,
        List<Path> paths,
        List<String> buildFileExtensions,
        List<String> expectedExtensions,
        Map<String, String> result) {

        for (Path path : paths) {
            String sourcePath = path.toString();

            for (String buildFileExtension : buildFileExtensions) {
                if (sourcePath.endsWith(buildFileExtension)) {

                    for (String expectedExtension : expectedExtensions) {
                        int expectedExtensionStartIndex =
                            sourcePath.length() - buildFileExtension.length() - expectedExtension.length();

                        int expectedExtensionEndIndex =
                            expectedExtensionStartIndex + expectedExtension.length() - 1;

                        if (StringEquality.equals(
                                sourcePath, expectedExtensionStartIndex, expectedExtensionEndIndex,
                                expectedExtension, 0, expectedExtension.length() - 1)) {

                            IPair<String, String> transformedBuildPath = transformBuildFilePath(
                                rootPath,
                                sourcePath,
                                buildFileExtension);

                            result.put(
                                transformedBuildPath.first(),
                                transformedBuildPath.second());
                        }
                    }
                }
            }
        }
    }

    /**
     * Transforms the build file path.
     */
    private static IPair<String, String> transformBuildFilePath(
        Path rootPath,
        String path,
        String buildFileExtension) {

        String relativePath = Paths.getRelativePath(path, rootPath.toString());
        String sourcePath = Paths.separatorToUnix(relativePath);
        String transformedSourcePath = sourcePath.substring(
            0,
            sourcePath.length() - buildFileExtension.length());

        transformedSourcePath = Paths.normalizePath(
            transformedSourcePath,
            UnixPath.DIRECTORY_SEPARATOR);

        String targetPath = new UnixPathBuilder(Paths.CURRENT_DIRECTORY)
            .addComponent(CMakeListsConstants.BUILD_DIRECTORY_NAME)
            .addComponent(transformedSourcePath)
            .build();

        return Pair.make(sourcePath, targetPath);
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
