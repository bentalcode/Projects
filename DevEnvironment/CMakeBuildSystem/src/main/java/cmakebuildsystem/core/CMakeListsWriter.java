package cmakebuildsystem.core;

import base.core.Conditions;
import base.core.Environment;
import base.core.Paths;
import base.interfaces.IWriter;
import cmakebuildsystem.interfaces.ICMakeBuildElement;
import cmakebuildsystem.interfaces.ICMakeBuildElementList;
import cmakebuildsystem.interfaces.ICMakeBuildCommand;
import cmakebuildsystem.interfaces.ICMakeListsFile;
import cmakebuildsystem.interfaces.ICMakeModule;
import cmakebuildsystem.interfaces.ICMakeModuleManifest;
import cmakebuildsystem.interfaces.ICMakeWriter;
import cmakebuildsystem.interfaces.IEditorSettings;
import cmakebuildsystem.interfaces.IIgnoreRules;
import java.io.Writer;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

/**
 * The CMakeListsWriter class implements a writer of a CMakeLists file.
 */
public final class CMakeListsWriter implements IWriter {
    private final IEditorSettings editorSettings;
    private final IIgnoreRules ignoreRules;
    private final ICMakeModuleManifest moduleManifest;
    private final ICMakeModule module;
    private final ICMakeBuildContextData contextData;

    /**
     * The CMakeListsWriter constructor.
     */
    public CMakeListsWriter(
        IEditorSettings editorSettings,
        IIgnoreRules ignoreRules,
        ICMakeModuleManifest moduleManifest,
        ICMakeModule module,
        ICMakeBuildContextData contextData) {

        Conditions.validateNotNull(
            editorSettings,
            "The editor settings.");

        Conditions.validateNotNull(
            ignoreRules,
            "The ignore rules.");

        Conditions.validateNotNull(
            moduleManifest,
            "The manifest of a CMake module.");

        Conditions.validateNotNull(
            module,
            "The CMake module.");

        Conditions.validateNotNull(
            contextData,
            "The context data.");

        this.editorSettings = editorSettings;
        this.ignoreRules = ignoreRules;
        this.moduleManifest = moduleManifest;
        this.module = module;
        this.contextData = contextData;
    }

    /**
     * Writes a CMake module.
     */
    @Override
    public void write(Writer writer) {
        Conditions.validateNotNull(
            writer,
            "The CMake writer.");

        ICMakeWriter cmakeWriter = new CMakeWriter(
            writer,
            this.editorSettings);

        ICMakeListsFile cmakeListsFile = this.createCMakeListsFile();

        cmakeListsFile.compile(
            cmakeWriter,
            this.contextData);
    }

    /**
     * Creates a CMake lists file.
     */
    private ICMakeListsFile createCMakeListsFile() {
        ICMakeBuildElementList elements = new CMakeBuildElementList();

        //
        // Add the cmake version section...
        //
        ICMakeBuildElement cmakeVersion = new CMakeVersion(this.moduleManifest.getCMakeListsManifest().getCMakeVersion());
        elements.add(cmakeVersion);

        //
        // Add the cmake version section...
        //
        ICMakeBuildElement projectVersion = new ProjectVersion(
            this.module.getName(),
            this.moduleManifest.getCMakeListsManifest().getProjectVersion());

        elements.add(projectVersion);

        //
        // Add the build properties section...
        //
        Path buildPropertiesPath = resolveResourcePath(this.moduleManifest.getCMakeListsManifest().getBuildPropertiesPath());
        ICMakeBuildElement buildPropertiesSection = this.moduleManifest.getType().createBuildProperties(buildPropertiesPath);
        elements.add(buildPropertiesSection);

        //
        // Add the preset section...
        //
        List<Path> presetPaths = resolveResourcePaths(this.moduleManifest.getCMakeListsManifest().getPresetPaths());
        ICMakeBuildElement presetSection = new CMakeResource(presetPaths);
        elements.add(presetSection);

        //
        // Add section for the module...
        //
        ICMakeBuildElement moduleSection = new ModuleSection(
            null,
            this.module,
            this.ignoreRules);

        elements.add(moduleSection);

        //
        // Add section for each dependent module...
        //
        ICMakeModuleContextData moduleContextData = this.contextData.getModuleContextData(this.module.getName());

        for (ICMakeModule dependentModule : moduleContextData.getDependencies()) {
            ICMakeBuildElement dependentModuleLibrary = new ModuleLibrarySection(
                this.module,
                dependentModule,
                this.ignoreRules);

            elements.add(dependentModuleLibrary);
        }

        //
        // Add section for to include directories command...
        //
        ICMakeBuildElement includesDirectoriesCommand = new IncludesDirectoriesCommand(this.module.getName());
        elements.add(includesDirectoriesCommand);

        //
        // Add the section for the module type command...
        //
        List<ICMakeBuildCommand> moduleTypeCommands =
            this.moduleManifest.getType().createCommands(this.module.getName());

        for (ICMakeBuildCommand command : moduleTypeCommands) {
            elements.add(command);
        }

        //
        // Add section for the postset section...
        //
        List<Path> postsetPaths = resolveResourcePaths(this.moduleManifest.getCMakeListsManifest().getPostsetPaths());
        ICMakeBuildElement postsetSection = new CMakeResource(postsetPaths);
        elements.add(postsetSection);

        return new CMakeListsFile(elements);
    }

    /**
     * Resolves resource paths.
     */
    private static List<Path> resolveResourcePaths(List<String> paths) {
        List<Path> resolvedPaths = new ArrayList<>(paths.size());

        for (String path : paths) {
            Path resolvedPath = resolveResourcePath(path);
            resolvedPaths.add(resolvedPath);
        }

        return resolvedPaths;
    }

    /**
     * Resolves resource path.
     */
    private static Path resolveResourcePath(String path) {
        String resolvedPath = Environment.expandSystemProperties(path, Environment.operatingSystemTransformer());
        return Paths.create(resolvedPath);
    }
}
