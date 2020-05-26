package cmakebuild.core;

import base.core.Conditions;
import base.interfaces.IWriter;
import cmakebuild.interfaces.ICMakeBuildElement;
import cmakebuild.interfaces.ICMakeListsFile;
import cmakebuild.interfaces.ICMakeListsManifest;
import cmakebuild.interfaces.ICMakeModule;
import cmakebuild.interfaces.ICMakeWriter;
import cmakebuild.interfaces.IEditorSettings;
import cmakebuild.interfaces.IIgnoreRules;
import java.io.Writer;
import java.util.ArrayList;
import java.util.List;

/**
 * The CMakeListsWriter class implements a writer of a CMakeLists file.
 */
public final class CMakeListsWriter implements IWriter {
    private final ICMakeListsManifest manifest;
    private final ICMakeModule module;
    private final IEditorSettings editorSettings;
    private final IIgnoreRules ignoreRules;

    /**
     * The CMakeListsWriter constructor.
     */
    public CMakeListsWriter(
        ICMakeListsManifest manifest,
        ICMakeModule module,
        IEditorSettings editorSettings,
        IIgnoreRules ignoreRules) {

        Conditions.validateNotNull(
            manifest,
            "The manifest of a CMakeLists file.");

        Conditions.validateNotNull(
            module,
            "The CMake module.");

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
     * Writes a the CMake module.
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
        cmakeListsFile.compile(cmakeWriter);
    }

    /**
     * Creates a CMake lists file.
     */
    private ICMakeListsFile createCMakeListsFile() {
        List<ICMakeBuildElement> elements = new ArrayList<>();

        ICMakeBuildElement cmakeVersion = new CMakeVersion(this.manifest.getCMakeVersion());
        elements.add(cmakeVersion);

        ICMakeBuildElement projectVersion = new ProjectVersion(
            this.module.getName(),
            this.manifest.getProjectVersion());

        elements.add(projectVersion);

        ICMakeBuildElement presetSection = new CMakeResource(this.manifest.getPresetPath());
        elements.add(presetSection);

        ICMakeBuildElement moduleLibrarySection = new ModuleLibrarySection(
            this.manifest,
            this.module,
            this.ignoreRules);

        elements.add(moduleLibrarySection);

        ICMakeBuildElement postsetSection = new CMakeResource(this.manifest.getPostsetPath());
        elements.add(postsetSection);

        ICMakeListsFile file = new CMakeListsFile(elements);

        return file;
    }
}
