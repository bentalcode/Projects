package cmakebuild.core;

import base.core.Conditions;
import base.core.PathBuilder;
import base.interfaces.IScanner;
import cmakebuild.CMakeBuildException;
import cmakebuild.interfaces.ICMakeModule;
import cmakebuild.interfaces.ICMakeModuleManifest;
import java.io.File;
import java.io.IOException;
import java.nio.file.DirectoryIteratorException;
import java.nio.file.DirectoryStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
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

        List<Path> headerFilesPaths = new ArrayList<>();
        List<Path> sourceFilesPaths = new ArrayList<>();
        List<Path> cmakeListsFilesPaths = new ArrayList<>();

        this.processDirectory(
            this.path,
            this.manifest.getProperties().getHeaderFileExtensions(),
            this.manifest.getProperties().getSourceFileExtensions(),
            this.manifest.getProperties().getCMakeListsFileExtensions(),
            headerFilesPaths,
            sourceFilesPaths,
            cmakeListsFilesPaths);

        ICMakeModule module = new CMakeModule(
            this.manifest.getName(),
            this.path,
            headerFilesPaths,
            sourceFilesPaths,
            cmakeListsTargetPath,
            this.manifest.getDependentModules());

        return module;
    }

    /**
     * Processes a directory.
     */
    private void processDirectory(
        Path path,
        List<String> headerFileExtensions,
        List<String> sourceFileExtensions,
        List<String> cmakeListsExtensions,
        List<Path> headerFilesPaths,
        List<Path> sourceFilesPaths,
        List<Path> cmakeListsPaths) {

        try (DirectoryStream<Path> stream = Files.newDirectoryStream(path)) {
            for (Path currPath : stream) {
                File currFile = currPath.toFile();

                if (currFile.isDirectory()) {
                    this.processDirectory(
                        currPath,
                        headerFileExtensions,
                        sourceFileExtensions,
                        cmakeListsExtensions,
                        headerFilesPaths,
                        sourceFilesPaths,
                        cmakeListsPaths);
                }
                else if (currFile.isFile()) {
                    String currFileName = currFile.getName();

                    if (this.hasExtension(currFileName, headerFileExtensions)) {
                        headerFilesPaths.add(currPath);
                    } else if (this.hasExtension(currFileName, sourceFileExtensions)) {
                        sourceFilesPaths.add(currPath);
                    } else if (this.hasExtension(currFileName, cmakeListsExtensions)) {
                        cmakeListsPaths.add(currPath);
                    }
                }
            }
        }
        catch (IOException | DirectoryIteratorException e) {
            String errorMessage =
                "The CMakeProjectScanner failed processing the directory: " +
                path + ", due to the following error: " + e.getMessage();

            throw new CMakeBuildException(errorMessage);
        }
    }

    /**
     * Calculates target path of the CMakeListsFile.
     */
    private Path calculateCMakeListsTargetPath(
        Path modulePath,
        String cmakeListsFilePath) {

        String path = new PathBuilder()
            .addComponent(modulePath.toString())
            .addComponent(cmakeListsFilePath)
            .build();

        return Path.of(path);
    }

    /**
     * Checks whether this file has the specified extensions.
     */
    private boolean hasExtension(String fileName, List<String> extensions) {
        for (String extension : extensions) {
            if (fileName.endsWith(extension)) {
                return true;
            }
        }

        return false;
    }
}
