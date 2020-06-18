package cmakebuild.core;

import base.core.Conditions;
import base.core.DestructorHandler;
import base.core.Writers;
import base.interfaces.IWriter;
import cmakebuild.interfaces.ICMakeModule;
import cmakebuild.interfaces.ICMakeModuleManifest;
import cmakebuild.interfaces.ICMakeProject;
import cmakebuild.interfaces.IMakeProjectDeployer;
import cmakebuild.interfaces.ICMakeProjectDeploymentResult;
import cmakebuild.interfaces.ICMakeProjectManifest;
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
        return this.deploy(DeploymentType.Deployment);
    }

    /**
     * Simulates a deployment of a CMake Build.
     */
    @Override
    public ICMakeProjectDeploymentResult simulate() {
        return this.deploy(DeploymentType.Simulation);
    }

    /**
     * Deploys a project.
     */
    private ICMakeProjectDeploymentResult deploy(DeploymentType deploymentType) {
        //
        // Create the context data...
        //
        ICMakeBuildContextData contextData = this.createContextData();

        //
        // Deploy each module...
        //
        for (ICMakeModule module : this.project.getModules()) {
            ICMakeModuleContextData moduleContextData = contextData.getModuleContextData(module.getName());

            if (moduleContextData.effective()) {
                this.deployModule(
                    deploymentType,
                    module,
                    contextData);
            }
        }

        return new CMakeProjectDeploymentResult(
            this.project,
            contextData.getData());
    }

    /**
     * Deploys a module.
     */
    private void deployModule(
        DeploymentType deploymentType,
        ICMakeModule module,
        ICMakeBuildContextData contextData) {

        try (DestructorHandler destructorHandler = new DestructorHandler()) {
            IModuleDeploymentLogic moduleDeploymentLogic = deploymentType.createModuleDeploymentLogic(module);
            destructorHandler.register(moduleDeploymentLogic);

            OutputStream stream = moduleDeploymentLogic.getOutputStream();

            Writer writer = Writers.createOutputStreamWriter(stream);
            destructorHandler.register(writer);

            this.deployModule(
                module,
                contextData,
                writer);

            moduleDeploymentLogic.setDeploymentData(contextData);
        }
    }

    /**
     * Deploys a module.
     */
    private void deployModule(
        ICMakeModule module,
        ICMakeBuildContextData contextData,
        Writer writer) {

        ICMakeModuleContextData moduleContextData = contextData.getModuleContextData(module.getName());
        ICMakeModuleManifest moduleManifest = moduleContextData.getManifest();

        IWriter moduleWriter = new CMakeModuleWriter(
            this.manifest,
            moduleManifest,
            module,
            contextData);

        moduleWriter.write(writer);

        Writers.flush(writer);
    }

    /**
     * Creates the context data.
     */
    private ICMakeBuildContextData createContextData() {
        Map<String, ICMakeModule> modules = this.createModulesMap();
        Map<String, ICMakeModuleManifest> modulesManifests = this.createModulesManifestsMap();
        Map<String, List<ICMakeModule>> modulesDependencies = this.createModulesDependenciesMap(modules);
        Set<String> effectiveModules = this.createEffectiveModulesSet(modules, this.manifest.getEffectiveModules());

        ICMakeBuildContextData contextData = new CMakeBuildContextData(
            modules,
            modulesManifests,
            modulesDependencies,
            effectiveModules);

        return contextData;
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
