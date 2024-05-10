package cmakebuildsystem.core;

/**
 * The AddExecutableCommand class implements an add-executable command of a CMake build.
 *
 * add_executable(<name> [WIN32] [MAC_BUNDLE]
 *                [EXCLUDE_FROM_ALL]
 *                [source1] [source2 ...])
 */
public final class AddExecutableCommand extends AddBinaryCommand {
    /**
     * The AddExecutableCommand constructor.
     */
    public AddExecutableCommand(String moduleName) {
        super(
            CMakeListsConstants.ADD_EXECUTABLE_COMMAND,
            moduleName,
            null,
            false);
    }
}

