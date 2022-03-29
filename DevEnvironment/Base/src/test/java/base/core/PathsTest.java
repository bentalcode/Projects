package base.core;


import java.nio.file.FileSystems;
import java.nio.file.Path;
import java.nio.file.PathMatcher;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import org.junit.Test;

/**
 * The PathsTest class implements tests for paths.
 */
public final class PathsTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The PathsTest constructor.
     */
    public PathsTest() {
    }

    /**
     * Tests the logic of a get relative path.
     */
    @Test
    public void getRelativePathTest() {
        String separator = String.valueOf(WindowsPath.SEPARATOR);

        this.testGetRelativePath(
            "\\",
            "\\",
            separator,
            null);

        this.testGetRelativePath(
            "\\",
            "\\a",
            separator,
            null);

        this.testGetRelativePath(
            "\\a",
            "\\",
            separator,
            null);

        this.testGetRelativePath(
            "\\Base",
            "\\Base",
            separator,
            ".\\");

        this.testGetRelativePath(
            "\\Base\\",
            "\\Base",
            separator,
            ".\\");

        this.testGetRelativePath(
            "\\Base",
            "\\Base\\",
            separator,
            ".\\");

        this.testGetRelativePath(
            "\\Base\\",
            "\\Base\\",
            separator,
            ".\\");

        this.testGetRelativePath(
            "\\Base\\a",
            "\\Base",
            separator,
            ".\\a");

        this.testGetRelativePath(
            "\\Base\\a",
            "\\Base\\",
            separator,
            ".\\a");

        this.testGetRelativePath(
            "\\Base",
            "\\BaseTest",
            separator,
            null);

        this.testGetRelativePath(
            "\\a\\Base",
            "\\a\\BaseTest",
            separator,
            "..\\Base");

        this.testGetRelativePath(
            "c:\\repositories\\Projects\\DevEnvironmentCLion\\Base\\core\\PreCompiled.h",
            "c:\\repositories\\Projects\\DevEnvironmentCLion\\Base",
            separator,
            ".\\core\\PreCompiled.h");

        this.testGetRelativePath(
            "c:\\repositories\\Projects\\DevEnvironmentCLion\\Base\\BaseException.h",
            "c:\\repositories\\Projects\\DevEnvironmentCLion\\BaseTest",
            separator,
            "..\\Base\\BaseException.h");
    }

    /**
     * Tests the logic of finding the common root path end index.
     */
    @Test
    public void findCommonRootPathEndIndexTest() {
        String pathA1 = "\\";
        String pathB1 = "\\";
        int result1 = -1;

        String pathA2 = "\\";
        String pathB2 = "\\a";
        int result2 = -1;

        String pathA3 = "\\a";
        String pathB3 = "\\";
        int result3 = -1;

        String pathA4 = "\\Base";
        String pathB4 = "\\Base";
        int result4 = 4;

        String pathA5 = "\\Base\\";
        String pathB5 = "\\Base";
        int result5 = 4;

        String pathA6 = "\\Base";
        String pathB6 = "\\Base\\";
        int result6 = 4;

        String pathA7 = "\\Base\\";
        String pathB7 = "\\Base\\";
        int result7 = 4;

        String pathA8 = "\\Base\\a";
        String pathB8 = "\\Base";
        int result8 = 4;

        String pathA9 = "\\Base\\a";
        String pathB9 = "\\Base\\";
        int result9 = 4;

        String pathA10 = "\\Base";
        String pathB10 = "\\BaseTest";
        int result10 = -1;

        String separator = String.valueOf(WindowsPath.SEPARATOR);

        this.testFindCommonRootPathEndIndex(pathA1, pathB1, separator, result1);
        this.testFindCommonRootPathEndIndex(pathA2, pathB2, separator, result2);
        this.testFindCommonRootPathEndIndex(pathA3, pathB3, separator, result3);
        this.testFindCommonRootPathEndIndex(pathA4, pathB4, separator, result4);
        this.testFindCommonRootPathEndIndex(pathA5, pathB5, separator, result5);
        this.testFindCommonRootPathEndIndex(pathA6, pathB6, separator, result6);
        this.testFindCommonRootPathEndIndex(pathA7, pathB7, separator, result7);
        this.testFindCommonRootPathEndIndex(pathA8, pathB8, separator, result8);
        this.testFindCommonRootPathEndIndex(pathA9, pathB9, separator, result9);
        this.testFindCommonRootPathEndIndex(pathA10, pathB10, separator, result10);
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
        this.testPathMatcher(
            ".\\build\\CMakeFiles\\3.15.3\\CompilerIdCXX\\CMakeCXXCompilerId.cpp",
            "glob:**\\\\*build*\\\\**",
            true);

        this.testPathMatcher(
            "..\\Base\\build\\CMakeFiles\\3.15.3\\CompilerIdCXX\\CMakeCXXCompilerId.cpp",
            "glob:**\\\\*build*\\\\**",
            true);

        this.testPathMatcher(
            "..\\UnitTesting\\build\\CMakeFiles\\3.15.3\\CompilerIdCXX\\CMakeCXXCompilerId.cpp",
            "glob:**\\\\*build*\\\\**",
            true);

        this.testPathMatcher(
            "c:\\repositories\\Projects\\DevEnvironmentCLion\\Base\\build\\CMakeFiles\\3.15.3\\CompilerIdCXX\\CMakeCXXCompilerId.cpp",
            "glob:**\\\\*build*\\\\**",
            true);

        this.testPathMatcher(
            "c:\\repositories\\Projects\\DevEnvironmentCLion\\MemoryManagement\\cmake-build-debug\\CMakeFiles\\3.15.3\\CompilerIdCXX\\CMakeCXXCompilerId.cpp",
            "glob:**\\\\*build*\\\\**",
            true);

        this.testPathMatcher(
            "/home/bental-linux/repositories/Projects/DevEnvironmentCLion/Base/build/CMakeFiles/3.16.0-rc1/CompilerIdCXX/CMakeCXXCompilerId.cpp",
            "glob:**/*build*/**",
            true);
    }

    /**
     * Tests the logic of get relative path.
     */
    private void testGetRelativePath(
        String path,
        String rootPath,
        String separator,
        String expectedResult) {

        String result = Paths.getRelativePath(path, rootPath, separator);

        this.assertion.assertEquals(
            result,
            expectedResult,
            "The logic of getting a relative path is incorrect.");
    }

    /**
     * Tests the logic of finding the common root path end index.
     */
    private void testFindCommonRootPathEndIndex(
        String path1,
        String path2,
        String separator,
        int expectedResult) {

        int result = Paths.findCommonRootPathEndIndex(path1, path2, separator);

        this.assertion.assertEquals(
            result,
            expectedResult,
            "The logic of finding the common root path end index is incorrect.");
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
