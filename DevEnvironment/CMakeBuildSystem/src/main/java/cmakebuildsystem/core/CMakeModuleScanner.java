package cmakebuildsystem.core;

import base.core.ArrayLists;
import base.core.Conditions;
import base.core.Environment;
import base.core.Paths;
import base.interfaces.IScanner;
import basicio.core.FilePathScanner;
import basicio.interfaces.IFilePathScanner;
import cmakebuildsystem.interfaces.ICMakeModule;
import cmakebuildsystem.interfaces.ICMakeModuleManifest;
import java.nio.file.Path;
import java.util.List;

/**
 * The CMakeModuleScanner class implements a scanner of a CMake module.
 */
public final class CMakeModuleScanner implements IScanner<ICMakeModule> {
    private final Path path;
    private final ICMakeModuleManifest manifest;

    /**
     * The CMakeModuleScanner constructor.
     */
    public CMakeModuleScanner(
        Path path,
        ICMakeModuleManifest manifest) {

        Conditions.validatePathNotNullOrEmpty(
            path,
            "The path of a module.");

        Conditions.validateNotNull(
            manifest,
            "The manifest of a module.");

        this.path = path;
        this.manifest = manifest;
    }

    /**
     * Scans a module.
     */
    @Override
    public ICMakeModule scan() {
        Path cmakeListsTargetPath = this.calculateCMakeListsTargetPath(
            this.path,
            this.manifest.getProperties().getCMakeListsTargetPath());

        List<List<String>> extensions = ArrayLists.make(
            this.manifest.getProperties().getHeaderFileExtensions(),
            this.manifest.getProperties().getSourceFileExtensions(),
            this.manifest.getProperties().getBuildFileExtensions(),
            this.manifest.getProperties().getCMakeListsFileExtensions());

        IFilePathScanner scanner = new FilePathScanner();
        List<List<Path>> pathsResult = scanner.scanByCategory(this.path, extensions);
        List<Path> headerFilesPaths = pathsResult.get(0);
        List<Path> sourceFilesPaths = pathsResult.get(1);
        List<Path> buildFilesPaths = pathsResult.get(2);
        List<Path> cmakeListsFilesPaths = pathsResult.get(3);

        return new CMakeModule(
            this.manifest.getName(),
            this.path,
            headerFilesPaths,
            sourceFilesPaths,
            buildFilesPaths,
            cmakeListsTargetPath,
            this.manifest.getDependentModules());
    }

    /**
     * Calculates target path of the CMakeListsFile.
     */
    private Path calculateCMakeListsTargetPath(
        Path modulePath,
        String cmakeListsFilePath) {

        String path = Environment.getOperatingSystemControlSettings().pathSettings().createPathBuilder()
            .addComponent(modulePath.toString())
            .addComponent(cmakeListsFilePath)
            .build();

        return Paths.create(path);
    }
}
