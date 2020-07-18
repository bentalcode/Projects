package base.core;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;

/**
 * The UnixPathTest class implements tests for unix paths.
 */
public final class UnixPathTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The UnixPathTest constructor.
     */
    public UnixPathTest() {
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
     * Tests the logic for getting an absolute unix path.
     */
    @Test
    public void getAbsoluteUnixPathTest() {
        String homeDirectory = System.getProperty("user.home");

        this.testGetAbsoluteUnixPath("~/a/./b/../../c/", homeDirectory + "/c");
        this.testGetAbsoluteUnixPath("~/a/../../b/../c//.//", homeDirectory + "/c");
    }

    /**
     * Tests the logic for getting a canonical unix path.
     */
    @Test
    public void getCanonicalUnixPathTest() {
        this.testGetCanonicalUnixPath("/home/", "/home");
        this.testGetCanonicalUnixPath("/../", "/");
        this.testGetCanonicalUnixPath("/home//foo/", "/home/foo");
        this.testGetCanonicalUnixPath("/a/./b/../../c/", "/c");
        this.testGetCanonicalUnixPath("/a/../../b/../c//.//", "/c");
        this.testGetCanonicalUnixPath("/a//b////c/d//././/..", "/a/b/c");
    }

    /**
     * Tests the logic for getting an absolute unix path.
     */
    private void testGetAbsoluteUnixPath(String path, String expectedResult) {
        UnixPath unixPath = new UnixPath(path);
        String result = unixPath.getAbsolutePath();

        this.assertion.assertEquals(
            result,
            expectedResult,
            "Invalid logic for getting an absolute unix path.");
    }

    /**
     * Tests the logic for getting a canonical unix path.
     */
    private void testGetCanonicalUnixPath(String path, String expectedResult) {
        UnixPath unixPath = new UnixPath(path);
        String result = unixPath.getCanonicalPath();

        this.assertion.assertEquals(
            result,
            expectedResult,
            "Invalid logic for getting a canonical unix path.");
    }
}
