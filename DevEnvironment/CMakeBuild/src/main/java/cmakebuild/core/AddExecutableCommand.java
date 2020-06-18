package cmakebuild.core;

/**
 * The AddExecutableCommand class implements an add-executable command of a CMake build.
 *
 * add_executable(<name> [WIN32] [MACOSX_BUNDLE]
 *                [EXCLUDE_FROM_ALL]
 *                [source1] [source2 ...])
 */
public final class AddExecutableCommand extends AddBinaryCommand {
    /**
     * The AddExecutableCommand constructor.
     */
    public AddExecutableCommand(String moduleName) {
        super(
            ICMakeListsConstants.addExecutableCommand,
            moduleName,
            null);
    }
}
