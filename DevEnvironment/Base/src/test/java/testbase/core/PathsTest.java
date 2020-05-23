package testbase.core;

import base.core.Paths;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.interfaces.IAssertion;
import java.nio.file.FileSystems;
import java.nio.file.Path;
import java.nio.file.PathMatcher;

/**
 * The PathsTest class implements tests for paths.
 */
public final class PathsTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The PrimesTest constructor.
     */
    public PathsTest() {
    }

    /**
     * Initialize the tests.
     */
    @Before
    public void setUp() {
    }

    /**
     * Un-Initializes the tests.
     */
    @After
    public void tearDown() {
    }

    /**
     * Tests the logic of a path conversion to windows.
     */
    @Test
    public void pathSeparatorToWindowsTest() {
        String path1 = "/a/b/c/d/e/";
        String result1 = "\\a\\b\\c\\d\\e\\";
        this.testPathSeparatorToWindows(path1, result1);
    }

    /**
     * Tests the logic of a path conversion to unix.
     */
    @Test
    public void pathSeparatorToUnixTest() {
        String path1 = "\\a\\b\\c\\d\\e\\";
        String result1 = "/a/b/c/d/e/";
        this.testPathSeparatorToUnix(path1, result1);
    }

    /**
     * Tests the logic of a path matcher.
     */
    @Test
    public void pathMatcherTest() {
        String path1 = ".\\build\\CMakeFiles\\3.15.3\\CompilerIdCXX\\CMakeCXXCompilerId.cpp";
        String pattern1 = "glob:.\\\\build\\\\**";
        boolean status1 = true;

        this.testPathMatcher(
            path1,
            pattern1,
            status1);
    }

    /**
     * Tests the logic of a path matcher.
     */
    private void testPathMatcher(
        String path,
        String pattern,
        boolean expectedStatus) {

        PathMatcher matcher = FileSystems.getDefault().getPathMatcher(pattern);
        Path currPath = Paths.create(path);
        boolean status = matcher.matches(currPath);

        this.assertion.assertEquals(
            status,
            expectedStatus,
            "Pattern is not matching as expected.");
    }

    /**
     * Tests the logic of a path conversion to windows.
     */
    private void testPathSeparatorToWindows(
        String path,
        String expectedResult) {

        String result = Paths.separatorToWindows(path);

        this.assertion.assertEquals(
            result,
            expectedResult,
            "Incorrect logic of converting a path to windows.");
    }

    /**
     * Tests the logic of a path conversion to unix.
     */
    private void testPathSeparatorToUnix(
        String path,
        String expectedResult) {

        String result = Paths.separatorToUnix(path);

        this.assertion.assertEquals(
            result,
            expectedResult,
            "Incorrect logic of converting a path to unix.");
    }
}
