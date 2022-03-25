package cmakebuildsystem.core;

import base.core.Conditions;
import base.core.Environment;
import base.interfaces.IPath;
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

        String modulePath = moduleManifest.getProperties().getPath();

        if (modulePath == null) {
            modulePath = moduleManifest.getName();
        }

        String path = Environment.getOperatingSystemControlSettings().pathSettings().createPathBuilder()
            .addComponent(projectPath.toString())
            .addComponent(modulePath)
            .build();

        return Path.of(path);
    }
}
