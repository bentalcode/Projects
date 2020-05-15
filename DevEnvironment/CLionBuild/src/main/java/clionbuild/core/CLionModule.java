package clionbuild.core;

import clionbuild.interfaces.ICLionModule;

import java.nio.file.Path;
import java.util.List;

/**
 * The CLionModule class implements a CLion module.
 */
public final class CLionModule implements ICLionModule {
    private final String name;
    private final Path rootPath;
    private final List<Path> headerFilesPaths;
    private final List<Path> sourceFilesPaths;
    private final Path cmakeListsFilePath;

    /**
     * The CLionModule constructor.
     */
    public CLionModule(
        String name,
        Path rootPath,
        List<Path> headerFilesPaths,
        List<Path> sourceFilesPaths,
        Path cmakeListsFilePath) {

        this.name = name;
        this.rootPath = rootPath;
        this.headerFilesPaths = headerFilesPaths;
        this.sourceFilesPaths = sourceFilesPaths;
        this.cmakeListsFilePath = cmakeListsFilePath;
    }

    /**
     * Gets the name of the module.
     */
    @Override
    public String getName() {
        return this.name;
    }

    /**
     * Gets the root path of the module.
     */
    @Override
    public Path getRootPath() {
        return this.rootPath;
    }

    /**
     * Gets the paths of the header files.
     */
    @Override
    public List<Path> getHeaderFilesPaths() {
        return this.headerFilesPaths;
    }

    /**
     * Gets the paths of the source files.
     */
    @Override
    public List<Path> getSourceFilesPaths() {
        return this.sourceFilesPaths;
    }

    /**
     * Gets the path of the CMakeLists file.
     */
    @Override
    public Path getCMakeListsFilePath() {
        return this.cmakeListsFilePath;
    }
}
