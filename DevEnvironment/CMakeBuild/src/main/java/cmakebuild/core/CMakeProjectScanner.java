package cmakebuild.core;

import base.core.Conditions;
import base.core.PathBuilder;
import base.core.Paths;
import base.interfaces.IScanner;
import cmakebuild.interfaces.ICMakeModule;
import cmakebuild.interfaces.ICMakeModuleManifest;
import cmakebuild.interfaces.ICMakeProject;
import cmakebuild.interfaces.ICMakeProjectManifest;
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
        Path rootPath = Paths.create(this.manifest.getRootPath());
        List<ICMakeModule> modules = this.scanModules();

        ICMakeProject project = new CMakeProject(
            name,
            rootPath,
            modules);

        return project;
    }

    /**
     * Scans modules.
     */
    private List<ICMakeModule> scanModules() {
        List<ICMakeModule> modules = new ArrayList<>(this.manifest.getModulesManifests().size());

        for (ICMakeModuleManifest moduleManifest : this.manifest.getModulesManifests()) {
            ICMakeModule module = this.scanModule(moduleManifest);
            modules.add(module);
        }

        return modules;
    }

    /**
     * Scans a module.
     */
    private ICMakeModule scanModule(ICMakeModuleManifest moduleManifest) {
        Path modulePath = this.calculateModulePath(moduleManifest);

        IScanner<ICMakeModule> scanner = new CMakeModuleScanner(
            modulePath,
            moduleManifest);

        ICMakeModule module = scanner.scan();

        return module;
    }

    /**
     * Calculates a path of the module.
     */
    private Path calculateModulePath(ICMakeModuleManifest moduleManifest) {
        String modulePath = moduleManifest.getProperties().getPath();

        if (modulePath == null) {
            modulePath = moduleManifest.getName();
        }

        String path = new PathBuilder()
            .addComponent(this.manifest.getRootPath())
            .addComponent(modulePath)
            .build();

        return Path.of(path);
    }
}
