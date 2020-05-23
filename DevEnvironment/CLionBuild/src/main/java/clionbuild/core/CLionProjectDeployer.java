package clionbuild.core;

import base.core.Conditions;
import base.core.DestructorHandler;
import base.core.Streams;
import base.core.Writers;
import base.interfaces.IWriter;
import clionbuild.CLionBuildException;
import clionbuild.interfaces.ICLionModule;
import clionbuild.interfaces.ICLionModuleManifest;
import clionbuild.interfaces.ICLionProject;
import clionbuild.interfaces.ICLionProjectDeployer;
import clionbuild.interfaces.ICLionProjectDeploymentResult;
import clionbuild.interfaces.ICLionProjectManifest;
import java.io.ByteArrayOutputStream;
import java.io.OutputStream;
import java.io.Writer;
import java.util.HashMap;
import java.util.Map;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The CLionProjectDeployer class implements a deployer of a CLion project.
 */
public final class CLionProjectDeployer implements ICLionProjectDeployer {
    private final ICLionProjectManifest manifest;
    private final ICLionProject project;
    private final Map<String, ICLionModuleManifest> modulesManifests = new HashMap<>();

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The CLionProjectDeployer constructor.
     */
    public CLionProjectDeployer(
        ICLionProjectManifest manifest,
        ICLionProject project) {

        Conditions.validateNotNull(
            manifest,
            "The manifest of a CLion project.");

        Conditions.validateNotNull(
            project,
            "The CLion project.");

        this.manifest = manifest;
        this.project = project;

        //
        // Create the mapping between modules and it's manifests...
        //
        this.createModulesManifestsMap();
    }

    /**
     * Deploys a CLion project.
     */
    @Override
    public ICLionProjectDeploymentResult deploy() {
        Map<String, String> deploymentData = new HashMap<>();

        //
        // Deploy each module...
        //
        for (ICLionModule module : this.project.getModules()) {
            ICLionModuleManifest moduleManifest = this.getModuleManifest(module.getName());

            try (DestructorHandler destructorHandler = new DestructorHandler()) {
                OutputStream stream = Streams.createOutputStream(module.getCMakeListsFilePath());
                destructorHandler.register(stream);

                Writer writer = Writers.createOutputStreamWriter(stream);
                destructorHandler.register(writer);

                this.deployModule(
                    module,
                    moduleManifest,
                    writer);

                String cmakeListsPath = module.getCMakeListsFilePath().toString();
                String cmakeListsData = null;

                deploymentData.put(cmakeListsPath, cmakeListsData);
            }
        }

        return new CLionProjectDeploymentResult(
            this.project,
            deploymentData);
    }

    /**
     * Simulates a deployment of a CLion Build.
     */
    @Override
    public ICLionProjectDeploymentResult simulate() {
        Map<String, String> deploymentData = new HashMap<>();

        //
        // Deploy each module...
        //
        for (ICLionModule module : this.project.getModules()) {
            ICLionModuleManifest moduleManifest = this.getModuleManifest(module.getName());

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

        return new CLionProjectDeploymentResult(
            this.project,
            deploymentData);
    }

    /**
     * Deploys a module.
     */
    private void deployModule(
        ICLionModule module,
        ICLionModuleManifest moduleManifest,
        Writer writer) {

        IWriter moduleWriter = new CLionModuleWriter(
            moduleManifest,
            this.manifest.getEditorSettings(),
            this.manifest.getIgnoreRules(),
            module);

        moduleWriter.write(writer);
    }

    /**
     * Gets a module manifest by name.
     */
    private ICLionModuleManifest getModuleManifest(String name) {
        if (!this.modulesManifests.containsKey(name)) {
            String errorMessage = "The module: " + name + " is not defined in this project.";

            this.log.error(errorMessage);
            throw new CLionBuildException(errorMessage);
        }

        return this.modulesManifests.get(name);
    }

    /**
     * Creates a modules-manifests map.
     */
    private void createModulesManifestsMap() {
        for (ICLionModuleManifest manifest : this.manifest.getModulesManifests()) {
            String name = manifest.getName();

            if (this.modulesManifests.containsKey(name)) {
                String errorMessage = "The module: " + name + " is already defined in this project.";

                this.log.error(errorMessage);
                throw new CLionBuildException(errorMessage);
            }

            this.modulesManifests.put(manifest.getName(), manifest);
        }
    }
}
