package clionbuild.core;

import base.core.Conditions;
import base.core.PathBuilder;
import base.core.Paths;
import base.interfaces.IScanner;
import clionbuild.CLionBuildException;
import clionbuild.interfaces.ICLionModule;
import clionbuild.interfaces.ICLionModuleManifest;
import clionbuild.interfaces.ICLionProject;
import clionbuild.interfaces.ICLionProjectManifest;
import java.io.File;
import java.io.IOException;
import java.nio.file.DirectoryIteratorException;
import java.nio.file.DirectoryStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

/**
 * The CLionProjectScanner class implements a scanner of a CLion project.
 */
public final class CLionProjectScanner implements IScanner<ICLionProject> {
    private final ICLionProjectManifest manifest;

    /**
     * The CLionProjectScanner constructor.
     */
    public CLionProjectScanner(ICLionProjectManifest manifest) {
        Conditions.validateNotNull(
            manifest,
            "The manifest of a project.");

        this.manifest = manifest;
    }

    /**
     * Scans a project.
     */
    @Override
    public ICLionProject scan() {
        String name = this.manifest.getName();
        Path rootPath = Paths.create(this.manifest.getRootPath());
        List<ICLionModule> modules = this.scanModules();

        ICLionProject project = new CLionProject(
            name,
            rootPath,
            modules);

        return project;
    }

    /**
     * Scans modules.
     */
    private List<ICLionModule> scanModules() {
        List<ICLionModule> modules = new ArrayList<>(this.manifest.getModulesManifests().size());

        for (ICLionModuleManifest moduleManifest : this.manifest.getModulesManifests()) {
            ICLionModule module = this.scanModule(moduleManifest);
            modules.add(module);
        }

        return modules;
    }

    /**
     * Scans a module.
     */
    private ICLionModule scanModule(ICLionModuleManifest moduleManifest) {
        Path modulePath = this.calculateModulePath(moduleManifest);
        Path cmakeListsTargetPath = this.calculateCMakeListsTargetPath(modulePath, moduleManifest.getCMakeListsTargetPath());

        List<Path> headerFilesPaths = new ArrayList<>();
        List<Path> sourceFilesPaths = new ArrayList<>();
        List<Path> cmakeListsFilesPaths = new ArrayList<>();

        this.processDirectory(
            modulePath,
            moduleManifest.getHeaderFileExtensions(),
            moduleManifest.getSourceFileExtensions(),
            moduleManifest.getCMakeListsFileExtensions(),
            headerFilesPaths,
            sourceFilesPaths,
            cmakeListsFilesPaths);

        ICLionModule module = new CLionModule(
            moduleManifest.getName(),
            modulePath,
            headerFilesPaths,
            sourceFilesPaths,
            cmakeListsTargetPath);

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
                "The CLionProjectScanner failed processing the directory: " +
                path + ", due to the following error: " + e.getMessage();

            throw new CLionBuildException(errorMessage);
        }
    }

    /**
     * Calculates path of the module.
     */
    private Path calculateModulePath(ICLionModuleManifest moduleManifest) {
        String modulePath = moduleManifest.getPath();

        if (modulePath == null) {
            modulePath = moduleManifest.getName();
        }

        String path = new PathBuilder()
            .addComponent(this.manifest.getRootPath())
            .addComponent(modulePath)
            .build();

        return Path.of(path);
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
