package clionbuild.core;

import base.core.Conditions;
import base.core.Paths;
import base.core.Strings;
import base.interfaces.IPathMatcher;
import java.nio.file.FileSystems;
import java.nio.file.Path;
import java.nio.file.PathMatcher;
import java.util.List;

/**
 * The CMakePathMatcher class implements a path matcher for CMake.
 */
public final class CMakePathMatcher implements IPathMatcher {
    private final List<String> patterns;

    /**
     * The PathMatcher constructor.
     */
    public CMakePathMatcher(List<String> patterns) {
        Conditions.validateNotNull(
            patterns,
            "The patterns of paths");

        this.patterns = patterns;
    }

    /**
     * Checks whether there is a match.
     */
    public boolean match(String path) {
        if (this.patterns.isEmpty() || Strings.isNullOrEmpty(path)) {
            return false;
        }

        for (String pattern : this.patterns) {
            if (this.patternMatching(pattern, path)) {
                return true;
            }
        }

        return false;
    }

    /**
     * Checks whether the pattern is matching.
     */
    private boolean patternMatching(String pattern, String path) {
        PathMatcher matcher = FileSystems.getDefault().getPathMatcher(pattern);

        Path currPath = Paths.create(path);
        return matcher.matches(currPath);
    }
}
