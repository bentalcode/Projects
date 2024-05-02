package cmakebuildsystem.core;

import base.core.Conditions;
import base.core.Environment;
import base.interfaces.IPath;
import base.interfaces.IPathBuilder;
import base.interfaces.IScanner;
import cmakebuildsystem.interfaces.ICMakeModule;
import cmakebuildsystem.interfaces.ICMakeModuleManifest;
import cmakebuildsystem.interfaces.ICMakeProject;
import cmakebuildsystem.interfaces.ICMakeProjectManifest;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

/**
 * The CMakeProjectScanner class implements a scanner of a CMake project.
 */
public final class CMakeProjectScanner implements IScanner<ICMakeProject> {
    private final ICMakeProjectManifest manifest;

    /**
     * The CMakeProjectScanner constructor.
     */
    public CMakeProjectScanner(ICMakeProjectManifest manifest) {
        Conditions.validateNotNull(
            manifest,
            "The manifest of a project.");

        this.manifest = manifest;
    }

    /**
     * Scans a project.
     */
    @Override
    public ICMakeProject scan() {
        String name = this.manifest.getName();
        Path projectPath = this.calculateProjectPath(this.manifest);
        List<ICMakeModule> modules = this.scanModules(projectPath);

        return new CMakeProject(
            name,
            projectPath,
            modules);
    }

    /**
     * Scans modules.
     */
    private List<ICMakeModule> scanModules(Path projectPath) {
        List<ICMakeModule> modules = new ArrayList<>(this.manifest.getModulesManifests().size());

        for (ICMakeModuleManifest moduleManifest : this.manifest.getModulesManifests()) {
            ICMakeModule module = this.scanModule(projectPath, moduleManifest);
            modules.add(module);
        }

        return modules;
    }

    /**
     * Scans a module.
     */
    private ICMakeModule scanModule(Path projectPath, ICMakeModuleManifest moduleManifest) {
        Path modulePath = this.calculateModulePath(projectPath, moduleManifest);

        IScanner<ICMakeModule> scanner = new CMakeModuleScanner(
            modulePath,
            moduleManifest);

        return scanner.scan();
    }

    /**
     * Calculates a path of the project.
     */
    private Path calculateProjectPath(ICMakeProjectManifest manifest) {
        IPath path = Environment.getOperatingSystemControlSettings().pathSettings().createPath(manifest.getRootPath());
        String absolutePath = path.getAbsolutePath();

        return Path.of(absolutePath);
    }

    /**
     * Calculates a path of the module.
     */
    private Path calculateModulePath(
        Path projectPath,
        ICMakeModuleManifest moduleManifest) {

        //
        // Calculate the root path...
        //
        String rootPath = moduleManifest.getRootPath();

        if (rootPath == null) {
            rootPath = projectPath.toString();
        }

        //
        // Calculate the sub path...
        //
        String subPath = moduleManifest.getProperties().getPath();

        //
        // Calculate the directory name...
        //
        String directoryName = moduleManifest.getProperties().getDirectoryName();

        if (directoryName == null) {
            directoryName = moduleManifest.getName();
        }

        //
        // Create the path...
        //
        IPathBuilder pathBuilder = Environment.getOperatingSystemControlSettings().pathSettings().createPathBuilder();
        pathBuilder.addComponent(rootPath);

        if (subPath != null) {
            pathBuilder.addComponent(subPath);
        }

        pathBuilder.addComponent(directoryName);

        String path = pathBuilder.build();

        return Path.of(path);
    }
}
