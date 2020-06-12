package cmakebuild.core;

import base.core.Conditions;
import base.core.DestructorHandler;
import base.core.Streams;
import base.core.Writers;
import base.interfaces.IWriter;
import cmakebuild.CMakeBuildException;
import cmakebuild.interfaces.ICMakeModule;
import cmakebuild.interfaces.ICMakeModuleManifest;
import cmakebuild.interfaces.ICMakeProject;
import cmakebuild.interfaces.IMakeProjectDeployer;
import cmakebuild.interfaces.ICMakeProjectDeploymentResult;
import cmakebuild.interfaces.ICMakeProjectManifest;
import java.io.ByteArrayOutputStream;
import java.io.OutputStream;
import java.io.Writer;
import java.util.HashMap;
import java.util.Map;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The CMakeProjectDeployer class implements a deployer of a CMake project.
 */
public final class CMakeProjectDeployer implements IMakeProjectDeployer {
    private final ICMakeProjectManifest manifest;
    private final ICMakeProject project;
    private final Map<String, ICMakeModuleManifest> modulesManifests = new HashMap<>();

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The CMakeProjectDeployer constructor.
     */
    public CMakeProjectDeployer(
        ICMakeProjectManifest manifest,
        ICMakeProject project) {

        Conditions.validateNotNull(
            manifest,
            "The manifest of a CMake project.");

        Conditions.validateNotNull(
            project,
            "The CMake project.");

        this.manifest = manifest;
        this.project = project;

        //
        // Create the mapping between modules and it's manifests...
        //
        this.createModulesManifestsMap();
    }

    /**
     * Deploys a CMake project.
     */
    @Override
    public ICMakeProjectDeploymentResult deploy() {
        Map<String, String> deploymentData = new HashMap<>();

        //
        // Deploy each module...
        //
        for (ICMakeModule module : this.project.getModules()) {
            ICMakeModuleManifest moduleManifest = this.getModuleManifest(module.getName());

            try (DestructorHandler destructorHandler = new DestructorHandler()) {
                OutputStream stream = Streams.createOutputStream(module.getCMakeListsFilePath());
                destructorHandler.register(stream);

                Writer writer = Writers.createOutputStreamWriter(stream);
                destructorHandler.register(writer);

                this.deployModule(
                    module,
                    moduleManifest,
                    writer);

                Writers.flush(writer);
                Streams.closeQuietly(stream);

                String cmakeListsPath = module.getCMakeListsFilePath().toString();
                String cmakeListsData = null;

                deploymentData.put(cmakeListsPath, cmakeListsData);
            }
        }

        return new CMakeProjectDeploymentResult(
            this.project,
            deploymentData);
    }

    /**
     * Simulates a deployment of a CMake Build.
     */
    @Override
    public ICMakeProjectDeploymentResult simulate() {
        Map<String, String> deploymentData = new HashMap<>();

        //
        // Deploy each module...
        //
        for (ICMakeModule module : this.project.getModules()) {
            ICMakeModuleManifest moduleManifest = this.getModuleManifest(module.getName());

            try (DestructorHandler destructorHandler = new DestructorHandler()) {
                ByteArrayOutputStream stream = Streams.createByteArrayOutputStream();
                destructorHandler.register(stream);

                Writer writer = Writers.createOutputStreamWriter(stream);
                destructorHandler.register(writer);

                this.deployModule(
                    module,
                    moduleManifest,
                    writer);

                Writers.flush(writer);

                String cmakeListsPath = module.getCMakeListsFilePath().toString();
                String cmakeListsData = new String(stream.toByteArray());

                deploymentData.put(cmakeListsPath, cmakeListsData);
            }
        }

        return new CMakeProjectDeploymentResult(
            this.project,
            deploymentData);
    }

    /**
     * Deploys a module.
     */
    private void deployModule(
        ICMakeModule module,
        ICMakeModuleManifest moduleManifest,
        Writer writer) {

        IWriter moduleWriter = new CMakeModuleWriter(
            moduleManifest,
            this.manifest.getEditorSettings(),
            this.manifest.getIgnoreRules(),
            module);

        moduleWriter.write(writer);
    }

    /**
     * Gets a module manifest by name.
     */
    private ICMakeModuleManifest getModuleManifest(String name) {
        if (!this.modulesManifests.containsKey(name)) {
            String errorMessage = "The module: " + name + " is not defined in this project.";

            this.log.error(errorMessage);
            throw new CMakeBuildException(errorMessage);
        }

        return this.modulesManifests.get(name);
    }

    /**
     * Creates a modules-manifests map.
     */
    private void createModulesManifestsMap() {
        for (ICMakeModuleManifest manifest : this.manifest.getModulesManifests()) {
            String name = manifest.getName();

            if (this.modulesManifests.containsKey(name)) {
                String errorMessage = "The module: " + name + " is already defined in this project.";

                this.log.error(errorMessage);
                throw new CMakeBuildException(errorMessage);
            }

            this.modulesManifests.put(manifest.getName(), manifest);
        }
    }
}
