package base.core;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
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
     * Tests the logic of a get relative path.
     */
    @Test
    public void getRelativePathTest() {
        String path1 = "\\";
        String rootPath1 = "\\";
        String result1 = null;

        String path2 = "\\";
        String rootPath2 = "\\a";
        String result2 = null;

        String path3 = "\\a";
        String rootPath3 = "\\";
        String result3 = null;

        String path4 = "\\Base";
        String rootPath4 = "\\Base";
        String result4 = ".\\";

        String path5 = "\\Base\\";
        String rootPath5 = "\\Base";
        String result5 = ".\\";

        String path6 = "\\Base";
        String rootPath6 = "\\Base\\";
        String result6 = ".\\";

        String path7 = "\\Base\\";
        String rootPath7 = "\\Base\\";
        String result7 = ".\\";

        String path8 = "\\Base\\a";
        String rootPath8 = "\\Base";
        String result8 = ".\\a";

        String path9 = "\\Base\\a";
        String rootPath9 = "\\Base\\";
        String result9 = ".\\a";

        String path10 = "\\Base";
        String rootPath10 = "\\BaseTest";
        String result10 = null;

        String path11 = "\\a\\Base";
        String rootPath11 = "\\a\\BaseTest";
        String result11 = "..\\Base";

        String path12 = "c:\\repositories\\Projects\\DevEnvironmentCLion\\Base\\core\\PreCompiled.h";
        String rootPath12 = "c:\\repositories\\Projects\\DevEnvironmentCLion\\Base";
        String result12 = ".\\core\\PreCompiled.h";

        String path13 = "c:\\repositories\\Projects\\DevEnvironmentCLion\\Base\\BaseException.h";
        String rootPath13 = "c:\\repositories\\Projects\\DevEnvironmentCLion\\BaseTest";
        String result13 = "..\\Base\\BaseException.h";

        this.testGetRelativePath(path1, rootPath1, result1);
        this.testGetRelativePath(path2, rootPath2, result2);
        this.testGetRelativePath(path3, rootPath3, result3);
        this.testGetRelativePath(path4, rootPath4, result4);
        this.testGetRelativePath(path5, rootPath5, result5);
        this.testGetRelativePath(path6, rootPath6, result6);
        this.testGetRelativePath(path7, rootPath7, result7);
        this.testGetRelativePath(path8, rootPath8, result8);
        this.testGetRelativePath(path9, rootPath9, result9);
        this.testGetRelativePath(path10, rootPath10, result10);
        this.testGetRelativePath(path11, rootPath11, result11);
        this.testGetRelativePath(path12, rootPath12, result12);
        this.testGetRelativePath(path13, rootPath13, result13);
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

        this.testFindCommonRootPathEndIndex(pathA1, pathB1, result1);
        this.testFindCommonRootPathEndIndex(pathA2, pathB2, result2);
        this.testFindCommonRootPathEndIndex(pathA3, pathB3, result3);
        this.testFindCommonRootPathEndIndex(pathA4, pathB4, result4);
        this.testFindCommonRootPathEndIndex(pathA5, pathB5, result5);
        this.testFindCommonRootPathEndIndex(pathA6, pathB6, result6);
        this.testFindCommonRootPathEndIndex(pathA7, pathB7, result7);
        this.testFindCommonRootPathEndIndex(pathA8, pathB8, result8);
        this.testFindCommonRootPathEndIndex(pathA9, pathB9, result9);
        this.testFindCommonRootPathEndIndex(pathA10, pathB10, result10);
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
        String pattern1 = "glob:**\\\\*build*\\\\**";
        boolean status1 = true;

        String path2 = "..\\Base\\build\\CMakeFiles\\3.15.3\\CompilerIdCXX\\CMakeCXXCompilerId.cpp";
        String pattern2 = "glob:**\\\\*build*\\\\**";
        boolean status2 = true;

        String path3 = "..\\UnitTesting\\build\\CMakeFiles\\3.15.3\\CompilerIdCXX\\CMakeCXXCompilerId.cpp";
        String pattern3 = "glob:**\\\\*build*\\\\**";
        boolean status3 = true;

        String path4 = "c:\\repositories\\Projects\\DevEnvironmentCLion\\Base\\build\\CMakeFiles\\3.15.3\\CompilerIdCXX\\CMakeCXXCompilerId.cpp";
        String pattern4 = "glob:**\\\\*build*\\\\**";
        boolean status4 = true;

        String path5 = "c:\\repositories\\Projects\\DevEnvironmentCLion\\MemoryManagement\\cmake-build-debug\\CMakeFiles\\3.15.3\\CompilerIdCXX\\CMakeCXXCompilerId.cpp";
        String pattern5 = "glob:**\\\\*build*\\\\**";
        boolean status5 = true;

        this.testPathMatcher(path1, pattern1, status1);
        this.testPathMatcher(path2, pattern2, status2);
        this.testPathMatcher(path3, pattern3, status3);
        this.testPathMatcher(path4, pattern4, status4);
        this.testPathMatcher(path5, pattern5, status5);
    }

    /**
     * Tests the logic of get relative path.
     */
    private void testGetRelativePath(
        String path,
        String rootPath,
        String expectedResult) {

        String result = Paths.getRelativePath(path, rootPath);

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
        int expectedResult) {

        int result = Paths.findCommonRootPathEndIndex(path1, path2);

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
