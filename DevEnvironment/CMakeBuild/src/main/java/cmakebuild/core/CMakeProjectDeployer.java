package cmakebuild.core;

import base.core.Conditions;
import base.core.DestructorHandler;
import base.core.Streams;
import base.core.Writers;
import base.interfaces.IWriter;
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
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

/**
 * The CMakeProjectDeployer class implements a deployer of a CMake project.
 */
public final class CMakeProjectDeployer implements IMakeProjectDeployer {
    private final ICMakeProjectManifest manifest;
    private final ICMakeProject project;

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
    }

    /**
     * Deploys a CMake project.
     */
    @Override
    public ICMakeProjectDeploymentResult deploy() {
        ICMakeProjectDeploymentData deploymentData = this.createDeploymentData();

        //
        // Deploy each module...
        //
        for (ICMakeModule module : this.project.getModules()) {
            try (DestructorHandler destructorHandler = new DestructorHandler()) {
                OutputStream stream = Streams.createOutputStream(module.getCMakeListsFilePath());
                destructorHandler.register(stream);

                Writer writer = Writers.createOutputStreamWriter(stream);
                destructorHandler.register(writer);

                this.deployModule(
                    module,
                    deploymentData,
                    writer);

                String cmakeListsPath = module.getCMakeListsFilePath().toString();
                String cmakeListsData = null;

                Streams.closeQuietly(stream);

                deploymentData.setModuleData(cmakeListsPath, cmakeListsData);
            }
        }

        return new CMakeProjectDeploymentResult(
            this.project,
            deploymentData.getData());
    }

    /**
     * Simulates a deployment of a CMake Build.
     */
    @Override
    public ICMakeProjectDeploymentResult simulate() {
        ICMakeProjectDeploymentData deploymentData = this.createDeploymentData();

        //
        // Deploy each module...
        //
        for (ICMakeModule module : this.project.getModules()) {
            try (DestructorHandler destructorHandler = new DestructorHandler()) {
                ByteArrayOutputStream stream = Streams.createByteArrayOutputStream();
                destructorHandler.register(stream);

                Writer writer = Writers.createOutputStreamWriter(stream);
                destructorHandler.register(writer);

                this.deployModule(
                    module,
                    deploymentData,
                    writer);

                String cmakeListsPath = module.getCMakeListsFilePath().toString();
                String cmakeListsData = new String(stream.toByteArray());

                deploymentData.setModuleData(cmakeListsPath, cmakeListsData);
            }
        }

        return new CMakeProjectDeploymentResult(
            this.project,
            deploymentData.getData());
    }

    /**
     * Deploys a module.
     */
    private void deployModule(
        ICMakeModule module,
        ICMakeProjectDeploymentData deploymentData,
        Writer writer) {

        if (!deploymentData.moduleEffective(module.getName())) {
            return;
        }

        ICMakeModuleManifest manifest = deploymentData.getModuleManifest(module.getName());

        IWriter moduleWriter = new CMakeModuleWriter(
            manifest,
            this.manifest.getEditorSettings(),
            this.manifest.getIgnoreRules(),
            module);

        moduleWriter.write(writer);

        Writers.flush(writer);
    }

    /**
     * Creates the deployment data.
     */
    private ICMakeProjectDeploymentData createDeploymentData() {
        Map<String, ICMakeModule> modules = this.createModulesMap();
        Map<String, ICMakeModuleManifest> modulesManifests = this.createModulesManifestsMap();
        Map<String, List<ICMakeModule>> modulesDependencies = this.createModulesDependenciesMap(modules);
        Set<String> effectiveModules = this.createEffectiveModulesSet(modules, this.manifest.getEffectiveModules());

        ICMakeProjectDeploymentData deploymentData = new CMakeProjectDeploymentData(
            modules,
            modulesManifests,
            modulesDependencies,
            effectiveModules);

        return deploymentData;
    }

    /**
     * Creates the modules map.
     */
    private Map<String, ICMakeModule> createModulesMap() {
        Map<String, ICMakeModule> modules = new HashMap<>();

        for (ICMakeModule module : this.project.getModules()) {
            modules.put(module.getName(), module);
        }

        return modules;
    }

    /**
     * Creates the modules-manifests map.
     */
    private Map<String, ICMakeModuleManifest> createModulesManifestsMap() {
        Map<String, ICMakeModuleManifest> modulesManifests = new HashMap<>();

        for (ICMakeModuleManifest manifest : this.manifest.getModulesManifests()) {
            modulesManifests.put(manifest.getName(), manifest);
        }

        return modulesManifests;
    }

    /**
     * Creates the modules-dependencies map.
     */
    private Map<String, List<ICMakeModule>> createModulesDependenciesMap(Map<String, ICMakeModule> modules) {
        ICMakeModuleDependencyManager dependencyManager = new CMakeModuleDependencyManager(modules);
        return dependencyManager.resolveModulesDependencies();
    }

    /**
     * Creates the effective-modules set.
     */
    private Set<String> createEffectiveModulesSet(
        Map<String, ICMakeModule> modules,
        List<String> effectiveModules) {

        Set<String> result = new HashSet<>();

        if (effectiveModules.isEmpty()) {
            result.addAll(modules.keySet());
        }
        else {
            for (String effectiveModule : effectiveModules) {
                result.add(effectiveModule);
            }
        }

        return result;
    }
}
