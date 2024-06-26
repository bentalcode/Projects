package cmakebuildsystem.core;

import base.core.ArrayLists;

/**
 * The AddLibraryCommand class implements an add-library command of a CMake build.
 *
 * add_library(<name> [STATIC | SHARED | MODULE]
 *             [EXCLUDE_FROM_ALL]
 *             source1 [source2 ...])
 */
public final class AddLibraryCommand extends AddBinaryCommand {
    /**
     * The AddLibraryCommand constructor.
     */
    public AddLibraryCommand(String moduleName) {
        super(
            CMakeListsConstants.ADD_LIBRARY_COMMAND,
            moduleName,
            ArrayLists.make(CMakeListsConstants.STATIC_LIBRARY),
            false);
    }
}
