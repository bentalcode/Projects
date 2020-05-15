package clionbuild.core;

import clionbuild.interfaces.ICLionModule;
import clionbuild.interfaces.ICLionProject;
import java.nio.file.Path;
import java.util.List;

/**
 * The CLionProject implements a CLion project.
 */
public final class CLionProject implements ICLionProject {
    private final String name;
    private final Path rootPath;
    private final List<ICLionModule> modules;

    /**
     * The CLionProject constructor.
     */
    public CLionProject(
        String name,
        Path rootPath,
        List<ICLionModule> modules) {

        this.name = name;
        this.rootPath = rootPath;
        this.modules = modules;
    }

    /**
     * Gets the name of the project.
     */
    @Override
    public String getName() {
        return this.name;
    }

    /**
     * Gets the path of the root of the project.
     */
    @Override
    public Path getRootPath() {
        return this.rootPath;
    }

    /**
     * Gets the list of the modules.
     */
    @Override
    public List<ICLionModule> getModules() {
        return this.modules;
    }
}
